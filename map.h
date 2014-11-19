#ifndef MAP_H
#define MAP_H

#include <QString>
#include <QVector>

#include "tileset.h"

class map
{
public:
	int mapWidth;
	int mapHeight;
	int tileWidth;
	int tileHeight;
    QVector<tileset*> tilesetVector;

	map(int mapWidth, int mapHeight, int tileWidth, int tileHeight);
};

#endif // MAP_H
