#include "drawmap.h"

drawMap::drawMap(QString xmlFilePath){
		this -> xmlFilePath = xmlFilePath;
}

void drawMap::draw(){
    this -> parserXmlFile();
}

void drawMap::parserXmlFile(){
    // open the xml fileMainWindow
	QDomDocument xmlBOM;
    QFile f(this -> xmlFilePath);
    if (!f.open(QIODevice::ReadOnly )) {
       qDebug() << "Error while loading file";
       return;
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

    QSqlQuery qry_get_config;
    QString sql = "SELECT `value` FROM `config` WHERE `key`='maploaded' LIMIT 1";
    qry_get_config.prepare(sql);
    if( !qry_get_config.exec() ){
        qDebug() << qry_get_config.lastError();
        return;
    }
    if(! qry_get_config.next()){
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
            QString sql = "INSERT INTO `car_pos` (`x`, `y`, `width`, `height`, `status`, `type`, `pos_num`) VALUES ('";
            sql += x;
            sql += "','";
            sql += y;
            sql += "','";
            sql += width;
            sql += "','";
            sql += height;
            sql += "','free','";
            sql += type;
            sql += "','";
            sql += QString::number(o+1);
            sql += "')";
            qry.prepare(sql);
            if( !qry.exec() ){
                qDebug() << qry.lastError();
                return;
            }
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

    nav * mapShow = new nav();
    mapShow -> showImage(mapImage);
}

void drawMap::draw_widh_nav(){

}















