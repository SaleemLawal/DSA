/*****************************************
** File:    Proj2.cpp
** Project: CMSC 202 Project 2, Spring 2023 (potionCraft)
** Author:  Saleem Lawal
** Date:    3/9/2023
** Section: 41
** E-mail:  slawal1@umbc.edu
**
** This file contains the driver file that calls the files made
***********************************************/

#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

int main () {
	srand(time(NULL));
	Game newGame;
	newGame.StartGame();
	return 0;
}
