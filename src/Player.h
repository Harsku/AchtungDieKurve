#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
	Player(int r,int g, int b, int a, double x, double y, double dir);
	void setR(int);
	void setG(int);
	void setB(int);
	void setA(int);
	void setX(double);
	void setY(double);
	void setDir(double);
	int getR();
	int getG();
	int getB();
	int getA();
	double getX();
	double getY();
	double getDir();
	void posUpdate();
private:
	int colorR;
	int colorG;
	int colorB;
	int colorA;
	double posX;
	double posY;
	double posDir;
};


#endif