#ifndef TILESET_H
#define TILESET_H

#include <QString>
#include <qmath.h>
#include <QDebug>
#include <QImage>
#include <QDir>

class tileset
{
public:
    tileset(int imageWidth, int imageHeight, int firstGid, int tilewidth, int tileheight, QString source, QString name);
	
	int imageWidth;
	int imageHeight;
	int firstGid;
	int lastGid;
	int tilewidth;
	int tileheight;
	int tileAmountWidth;
	QString source;
	QString name;
	QImage image;
};

#endif // TILESET_H
