//
// Created by harald on 07.12.18.
//

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include "Obstacle.h"

Obstacle::Obstacle(double x, double y, int width, int type) : posX(x), posY(y), obstacleWidth(width), obstacleType(type){}

void Obstacle::setX(double x) {posX = x;}
void Obstacle::setY(double y) {posY = y;}
void Obstacle::setObstacleWidth(int width) { obstacleWidth = width;}
void Obstacle::setType(int type) {obstacleType = type;}

void Obstacle::loadObstacle(SDL_Renderer* renderer) {
    int x = (int)posX;
    int y = (int)posY;
    int width = obstacleWidth;
    int height = obstacleWidth;
    SDL_Rect rect{x, y, width, height};
    if (obstacleType == 1){
        SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);

    } else if(obstacleType == 2){
        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);

    }else {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    }
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderPresent(renderer);

}
double Obstacle::getX() { return posX;}
double Obstacle::gety() { return posY;}
int Obstacle::getType() { return obstacleType;}




