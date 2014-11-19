#ifndef DRAWMAP_H
#define DRAWMAP_H

#include <QString>
#include <QtXml>
#include <QFile>
#include <QPixmap>
#include <QVector>
#include <QLabel>
#include <QScrollArea>
#include <QPainter>
#include "map.h"
#include "tileset.h"
#include "nav.h"

class drawMap
{
public:
    drawMap(QString xmlFilePath);
    void draw();
private:
	QString xmlFilePath;
	void parserXmlFile();
};

#endif // DRAWMAP_H
