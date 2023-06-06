/*****************************************
** File:    proj4.cpp
** Project: CMSC 202 Project 4, Spring 2023 (UMBC Bloons)
** Author:  Saleem Lawal
** Date:    4/15/2023
** Section: 41
** E-mail:  slawal1@umbc.edu
**
** This file contains the functions that call the start game functions
***********************************************/
#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
  srand (time(NULL));
  Game g;
  g.StartGame();
  return 0;
}
