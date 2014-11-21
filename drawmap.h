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
#include <QtSql>
#include "map.h"
#include "tileset.h"
#include "nav.h"

class drawMap
{
public:
    drawMap(QString xmlFilePath);
    void importXmlFile();
    void draw();
    void draw_widh_nav(QPoint& doorPoint, QPoint& centerPoint, QPoint& targetPoint, QPoint &lastPoint);
private:
	QString xmlFilePath;
    QImage convertXmlToImage();
};

#endif // DRAWMAP_H
