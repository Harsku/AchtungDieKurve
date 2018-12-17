#include "Player.h"
#include "math.h"

// constructor
Player::Player(int r, int g, int b, int a, double x, double y, double dir)
	: colorR(r),colorG(g),colorB(b),colorA(a),posX(x),posY(y),posDir(dir){}

// set r
void Player::setR(int r) { colorR = r; }

// set g
void Player::setG(int g) { colorG = g; }

// set b
void Player::setB(int b) { colorB = b; }

// set a
void Player::setA(int a) { colorA = a; }

// get r
int Player::getR() { return colorR; }

// get g
int Player::getG() { return colorG; }

// get b
int Player::getB() { return colorB; }

// get a
int Player::getA() { return colorA; }

//set x coordinate
void Player::setX(double x) { posX = x; }

//set y coordinate
void Player::setY(double y) { posY = y; }

//set dir
void Player::setDir(double dir) { posDir = dir; }

//get x coordinate
double Player::getX() { return posX; }

//get y coordinate
double Player::getY() { return posY; }

//get dir
double Player::getDir() { return posDir; }

//position update
void Player::posUpdate() {
	posX = posX + sin(posDir);
	posY = posY - cos(posDir);
}
