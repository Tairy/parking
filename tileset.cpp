#include "tileset.h"

tileset::tileset(int imageWidth, int imageHeight, int firstGid, int tilewidth, int tileheight, QString source, QString name){
	this -> imageWidth = imageWidth;
	this -> imageHeight = imageHeight;
	this -> firstGid = firstGid;
	this -> tilewidth = tilewidth;
	this -> tileheight = tileheight;
	this -> source = source;
	this -> name = name;
    this -> tileAmountWidth = qFloor(imageWidth / tilewidth);
    this -> lastGid = tileAmountWidth * qFloor(imageHeight / tileheight) + firstGid - 1;
    QString imagePath = "/home/tairy/Documents/" + this -> source;
    this -> image = QImage(imagePath);
}
