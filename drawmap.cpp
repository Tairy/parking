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

//    QPixmap *screenBitmap = new QPixmap(mapWidth * tileWidth, mapHeight * tileHeight);
//    QBitmap *screenBitmapTopLayer = new QBitmap(mapWidth*tileWidth,mapHeight*tileHeight);

//    QSize mapSize( mapWidth * tileWidth, mapHeight * tileHeight );
//    QImage mapImage(mapSize,QImage::Format_RGB32);
//    QPainter mapPainter(&mapImage);

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
                    if(tileGid >= item -> firstGid && tileGid <= item -> lastGid){
                        currentTileset = item;
                        break;
                    }
                }

//                int destY = spriteForY * tileWidth;
//                int destX = spriteForX * tileWidth;
//                qDebug() << currentTileset->firstGid;
//                tileGid -= currentTileset->firstGid -1;
//                int sourceY = qCeil( tileGid / currentTileset->tileAmountWidth ) - 1;
//                int sourceX = tileGid - (currentTileset->tileAmountWidth * sourceY) - 1;
//                qDebug() << sourceX * currentTileset->tilewidth;
//                qDebug() << sourceY * currentTileset->tilewidth;
//                qDebug() << currentTileset->tilewidth;
//                qDebug() << currentTileset->tileheight;
//                QRect tagmapRect(sourceX * currentTileset->tilewidth, sourceY * currentTileset->tilewidth, currentTileset->tilewidth, currentTileset->tileheight);
//                QRect tagmapRect(20,20,50,50);
//                QRect sorcmapRect(destX,destY,currentTileset->tilewidth, currentTileset->tileheight);
//                mapPainter.drawImage(tagmapRect, currentTileset->image, sorcmapRect);
            }
        }
    }

//    QPixmap test_1 = QPixmap::fromImage(map_created -> tilesetVector.at(0)->image);
//    QPixmap test_2 = test_1.copy(30,20,50,50);
//    QSize testsize = QSize( mapWidth * tileWidth, mapHeight * tileHeight );
//    QImage testimage_1(testsize,QImage::Format_RGB32);

//    QPainter painter(&testimage_1);
//    QImage image_1;
//    QRect  test_rec(30,20,50,50);
//    painter.drawImage(test_rec,map_created -> tilesetVector.at(0)->image,test_rec);
//    painter.drawImage(20,20,map_created -> tilesetVector.at(0)->image,50,50);

    // show map
    QLabel *label = new QLabel;
    label -> setPixmap(QPixmap::fromImage(map_created -> tilesetVector.at(0)->image));
    QScrollArea *scrollArea = new QScrollArea;
    scrollArea->setWindowTitle("停车场平面图");
    scrollArea->setWidget(label);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
//    scrollArea->viewport()->setBackgroundRole(QPalette::Dark);

    scrollArea -> show();
}















