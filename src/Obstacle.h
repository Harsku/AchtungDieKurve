//
// Created by harald on 07.12.18.
//

#ifndef AP_PROJECT_OBSTACLE_H
#define AP_PROJECT_OBSTACLE_H

class Obstacle {
public:
    Obstacle(double x, double y, int width, int type);
    void setX(double);
    void setY(double);
    void setObstacleWidth(int);
    void setType(int);
    void loadObstacle(SDL_Renderer* renderer);
    double getX();
    double gety();
    int getType();

private:
    double posX;
    double posY;
    int obstacleWidth;
    int obstacleType;




};


#endif //AP_PROJECT_OBSTACLE_H
