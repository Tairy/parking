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
    QImage markParkingPos(QImage mapImage);
    QImage draw_widh_nav(QString to_pos_num);
    QImage convertXmlToImage();

private:
	QString xmlFilePath;
};

#endif // DRAWMAP_H
