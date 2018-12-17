#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <SDL2/SDL.h>
#include <cmath>
#include "Player.h"
#include "Obstacle.h"

#undef main

//#define WINDOW_WIDTH 600
using namespace std;


int main(void) {
	int WINDOW_WIDTH;
	int speed;
	cout << fixed << setprecision(2);
	cout << "Gamesize?";
	cin >> WINDOW_WIDTH;
	cout << "\n Gamespeed?";
	cin >> speed;
	SDL_Renderer *renderer;
	SDL_Window *window;
	double playerx = WINDOW_WIDTH / 2;
	double playery = WINDOW_WIDTH / 2;
	double direction = 0;



	Player player1(255, 0, 0, 255, playerx, playery, direction);
	Player player2(0, 255, 0, 255, WINDOW_WIDTH * 3 / 4, playery, direction);
	//SDL_PixelFormat *fmt;
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_WIDTH, 0, &window, &renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	//fmt = renderer->format;
	//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);


    //Map of obstacles
    auto mapWidth = WINDOW_WIDTH / 20;
    vector<vector<Obstacle>> mapMatrix; //Creating the 2-D vector/array that houses the obstacles
    mapMatrix.resize(mapWidth, vector<Obstacle>(mapWidth, Obstacle(0, 0, 0, 1))); //Resizing so it fits to the board
    for (int j = 0; j < mapWidth ; j++){
        for (int i = 0; i < mapWidth; i++){
            int type = (int)round(rand()%3); //Object type is randomly generated
            mapMatrix[j][i].setX(j*mapWidth); //Setting x coordinates for the object
            mapMatrix[j][i].setY(i*mapWidth); // Setting y coordinates for the object
            mapMatrix[j][i].setType(type); //Object type is randomly generated
            mapMatrix[j][i].setObstacleWidth(10);
            mapMatrix[j][i].loadObstacle(renderer); //Rendering the obstacles

        }
    }


    bool quit = false;

	while (!quit) {
		// set timeout to limit frame rate
		Uint32 timeout = SDL_GetTicks() + speed;
		// Handle the input
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
			// All keydown events
			if (e.type == SDL_KEYDOWN) {
				switch (e.key.keysym.sym) {
				case SDLK_LEFT:
					player1.setDir(player1.getDir()- 0.01*M_PI);
					break;
				case SDLK_RIGHT:
					player1.setDir(player1.getDir() + 0.01*M_PI);
					break;
				case SDLK_a:
					player2.setDir(player2.getDir() - 0.01*M_PI);
					break;
				case SDLK_d:
					player2.setDir(player2.getDir() + 0.01*M_PI);
					break;
				case SDLK_q:
					quit = true;
					break;
				}
			}
		}

		//Uint8 r, g, b, a;
		SDL_Rect srcrect;
		srcrect.x = (int)playerx;
		srcrect.y = (int)playery;
		/*Uint32 *target_pixel = (Uint8 *)surface->pixels + y * surface->pitch +
			x * sizeof *target_pixel;*/
		srcrect.h = 1;
		srcrect.w = 1;
		int* pixels[4];
		int pitch = 0;
		SDL_RenderReadPixels(renderer, &srcrect, 0, &pixels, pitch);
		/*SDL_GetRGBA({ playerx, playery}, 0, &r, &g, &b, &a);*/
		/*cout << pixels[0] << "  " << pixels[1] << "  " << pixels[2] << "  " << pixels[3]<< "\n";*/
		player1.posUpdate();
		player2.posUpdate();
		SDL_SetRenderDrawColor(renderer, player1.getR(), player1.getG(), player1.getB(), player1.getA());
		SDL_RenderDrawPoint(renderer, (int)player1.getX(), (int)player1.getY());
		SDL_SetRenderDrawColor(renderer, player2.getR(), player2.getG(), player2.getB(), player2.getA());
		SDL_RenderDrawPoint(renderer, (int)player2.getX(), (int)player2.getY());
		SDL_RenderPresent(renderer);

        int obstacleTypeAtPlayerPos = mapMatrix[ceil(player1.getX()/mapWidth)][ceil(player1.getY()/mapWidth)].getType();
        if (obstacleTypeAtPlayerPos == 1) {
            cout << "Player at: " << player1.getX() << ":" << player1.getY() << endl;
            cout << "Obstacle at: " << mapMatrix[ceil(player1.getX()/mapWidth)][ceil(player1.getY()/mapWidth)].getX()
            << ":" << mapMatrix[ceil(player1.getX()/mapWidth)][ceil(player1.getY()/mapWidth)].gety() << endl;
        }


		while (!SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) {
			// ... do work until timeout has elapsed
		}
	}
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return EXIT_SUCCESS;
}