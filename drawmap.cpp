#include "drawmap.h"

drawMap::drawMap(QString xmlFilePath){
		this -> xmlFilePath = xmlFilePath;
}

// not use
void drawMap::draw(){
    QImage mapImage = this -> convertXmlToImage();

    nav * mapShow = new nav();
    mapShow -> showImage(mapImage);
}

void drawMap::importXmlFile(){
    QDomDocument xmlBOM;
    QFile f(this -> xmlFilePath);
    if (!f.open(QIODevice::ReadOnly )) {
       qDebug() << "Error while loading file";
       return;
    }

    xmlBOM.setContent(&f);
    f.close();

    QDomElement root = xmlBOM.documentElement();
    QDomNodeList objectList = root.elementsByTagName("objectgroup").at(0).toElement().childNodes();
    for (int o = 0; o < objectList.count(); o++) {
        QDomNode objectNode = objectList.at(o);
        QString x = objectNode.toElement().attribute("x");
        QString y = objectNode.toElement().attribute("y");
        QString width = objectNode.toElement().attribute("width");
        QString height = objectNode.toElement().attribute("height");
        QString type = objectNode.toElement().attribute("name");

        QSqlQuery qry_config;
        QString sql_config = "INSERT INTO `config` (`key`, `value`) VALUES ('maploaded','true')";
        qry_config.prepare(sql_config);

        if( !qry_config.exec() ){
            qDebug() << qry_config.lastError();
            return;
        }

        // save in mysql
        QSqlQuery qry;
        QString sql = "INSERT INTO `car_pos` (`x`, `y`, `width`, `height`, `status`, `type`, `pos_num`) VALUES ('" + x + "','" + y + "','" + width + "','" + height + "','free','" + type + "','" + QString::number(o+1) + "')";
        qry.prepare(sql);
        if( !qry.exec() ){
            qDebug() << qry.lastError();
            return;
        }
    }
}

QImage drawMap::markParkingPos(QImage mapImage){
    QSqlQuery qry;
    QString sql = "SELECT * FROM `car_pos` WHERE `type` = 'position'";
    int x, y,width,heigth;
    QString pos, status;
    qry.prepare(sql);
    if( !qry.exec() ){
        qDebug() << qry.lastError();
        exit(0);
    }
    while( qry.next() ){
        x = qry.value(1).toInt();
        y = qry.value(2).toInt();
        width = qry.value(3).toInt();
        heigth = qry.value(4).toInt();
        status = qry.value(5).toString();
        pos = qry.value(7).toString();
        QPainter mapPrinter(&mapImage);
        if(status == "full"){
            mapPrinter.setPen(QPen(Qt::red, 6));
            pos += "/有车";
        } else {
            mapPrinter.setPen(QPen(Qt::yellow, 6));
            pos += "/空闲";
        }

        QPointF point = QPointF(x+10,y+heigth/2);
        mapPrinter.drawText(point,pos);
    }
    return mapImage;
}

QImage drawMap::convertXmlToImage(){
    // open the xml fileMainWindow
    QDomDocument xmlBOM;
    QFile f(this -> xmlFilePath);
    if (!f.open(QIODevice::ReadOnly )) {
       qDebug() << "Error while loading file";
       exit(0);
    }

    xmlBOM.setContent(&f);
    f.close();

    //Get the root element
    QDomElement root = xmlBOM.documentElement();

    //Get map info
    int mapWidth = root.attribute("width").toInt();
    int mapHeight = root.attribute("height").toInt();
    int tileWidth = root.attribute("tilewidth").toInt();
    int tileHeight =  root.attribute("tileheight").toInt();

    map * map_created = new map(mapWidth, mapHeight, tileWidth, tileHeight);

    // Get tileset info!
    QDomNodeList tilesetList = root.elementsByTagName("tileset");

    for(int i = 0; i < tilesetList.count(); i++) {
        QDomNode node = tilesetList.at(i);
        if(node.isElement()){
            int imageWidth = node.toElement().firstChildElement().attribute("width").toInt();
            int imageHeight = node.toElement().firstChildElement().attribute("height").toInt();
            int firstGid = node.toElement().attribute("firstgid").toInt();
            int tilewidth = node.toElement().attribute("tilewidth").toInt();
            int tileheight = node.toElement().attribute("tileheight").toInt();
            QString source = node.toElement().firstChildElement().attribute("source");
            QString name = node.toElement().firstChildElement().attribute("name");
            map_created -> tilesetVector.append(new tileset(imageWidth, imageHeight, firstGid, tilewidth, tileheight, source, name));
        }
    }

    QSize mapSize( mapWidth * tileWidth, mapHeight * tileHeight );
    QImage mapImage(mapSize,QImage::Format_RGB888);
    QPainter mapPainter(&mapImage);

    QDomNodeList layerList = root.elementsByTagName("layer");

    for(int i = 0; i < layerList.count(); i++) {
        QDomNodeList tileList = layerList.at(i).childNodes().at(0).toElement().childNodes();
        int tileLength = 0;
        int tileCount = tileList.count();
        QVector<int> tiles(tileCount);

        for(int j = 0; j < tileCount; j++){
            int gid = tileList.at(j).toElement().attribute("gid").toInt();
            if(gid > 0) {
                tiles[tileLength] = gid;
            }
            tileLength ++;
        }

        // Store the gid into a 2d array
        for(int spriteForX = 0; spriteForX < mapWidth; spriteForX++) {
            for(int spriteForY = 0; spriteForY < mapHeight; spriteForY++) {
                int tileGid = tiles[(spriteForX + (spriteForY * mapWidth))];
                tileset * currentTileset;
                foreach(tileset *item, map_created -> tilesetVector) {
                    if(tileGid >= item -> firstGid -1 && tileGid <= item -> lastGid){
                        currentTileset = item;
                        break;
                    }
                }

                int destY = spriteForY * tileWidth;
                int destX = spriteForX * tileWidth;

                tileGid -= currentTileset -> firstGid -1;
                int sourceY = qFloor( tileGid / currentTileset->tileAmountWidth );
                int sourceX = tileGid - (currentTileset->tileAmountWidth * sourceY) - 1;

                QRect tagmapRect(sourceX * currentTileset->tilewidth, sourceY * currentTileset->tilewidth, currentTileset->tilewidth, currentTileset->tileheight);
                QRect sorcmapRect(destX,destY,currentTileset->tilewidth, currentTileset->tileheight);
                mapPainter.drawImage(sorcmapRect, currentTileset->image, tagmapRect);
            }
        }
    }

    return this ->markParkingPos(mapImage);
}

QImage drawMap::draw_widh_nav(QString to_pos_num){
    QImage mapImage = this -> convertXmlToImage();
//    mapImage = this ->markParkingPos(mapImage);
    QPainter mapPainter(&mapImage);
    mapPainter.setPen(QPen(Qt::red, 4));

    int x, y, width, height, door_x, door_y, door_width;

    QSqlQuery qry, qry_door;
    QString sql = "SELECT * FROM `car_pos` WHERE `pos_num`='" + to_pos_num +"' LIMIT 1";
    qry.prepare(sql);
    if( !qry.exec() ){
        qDebug() << qry.lastError();
        exit(0);
    }
    if( qry.next() ){
        x = qry.value(1).toInt();
        y = qry.value(2).toInt();
        width = qry.value(3).toInt();
        height = qry.value(4).toInt();

        QString door_pos_sql = "SELECT * FROM `car_pos` WHERE `type`='door' LIMIT 1";
        qry_door.prepare(door_pos_sql);
        if( !qry_door.exec() ){
            qDebug() << qry_door.lastError();
            exit(0);
        }
        if(qry_door.next()) {
            door_x = qry_door.value(1).toInt();
            door_y = qry_door.value(2).toInt();
            door_width = qry_door.value(3).toInt();
        }
    }

    QPoint *doorPoint = new QPoint(door_x + door_width/2,door_y);
    QPoint *centerPoint = new QPoint(door_x + door_width/2, y + height + width/2);
    QPoint *targetPoint = new QPoint(x + width/2, y + height + width/2);
    QPoint *lastPoint = new QPoint(x + width/2, y + height);


    mapPainter.drawLine(*doorPoint, *centerPoint);
    mapPainter.drawLine(*centerPoint, *targetPoint);
    mapPainter.drawLine(*targetPoint, *lastPoint);

    return mapImage;
}















