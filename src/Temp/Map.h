//
// Created by harald on 07.12.18.
//

#ifndef AP_PROJECT_MAP_H
#define AP_PROJECT_MAP_H


#include "Obstacle.h"
#include "list"

class Map {
public:
    Map(int w, int h);
    Obstacle* mapMatrix() const;
    int getWidth() const ;
    int getHeight() const;

private:
    int mapWidth;
    int mapHeight;
};


#endif //AP_PROJECT_MAP_H
