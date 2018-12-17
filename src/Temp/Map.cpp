//
// Created by harald on 07.12.18.
//

#include "Map.h"
using namespace std;


Map::Map(int w, int h) : mapWidth(w), mapHeight(h) {}

Obstacle* Map::mapMatrix() const {
    int height = mapHeight;
    int width = mapWidth;
    Obstacle* mapArray[width][height];
}

int Map::getWidth() const {
    return mapWidth;
}

int Map::getHeight() const {
    return mapHeight;
}

