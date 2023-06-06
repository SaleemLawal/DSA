/*****************************************
** File:    proj3.cpp
** Project: CMSC 202 Project 3, Spring 2023 (Transcription and Translation)
** Author:  Saleem Lawal
** Date:    3/29/2023
** Section: 41
** E-mail:  slawal1@umbc.edu
**
** This file contains the driver file that gets a file name and 
** passes it into Sequencer to start sequencing
**
***********************************************/

#include "Sequencer.h"
#include <iostream>
using namespace std;

//This allows data to be passed when calling the executable
//For example, ./proj3 proj3_data1.txt would pass proj3_data1.txt as argv[1] below
int main (int argc, char* argv[]) {
  if (argc < 2)
    {
      cout << "You are missing a data file." << endl;
      cout << "Expected usage ./proj3 proj3_data1.txt" << endl;
      cout << "File 1 should be a file with one or more DNA strands" << endl;
    }
  else
    {
      cout << endl << "***Transcription and Translation***" << endl << endl;
      Sequencer D = Sequencer(argv[1]); //Passes the file name into the Sequencer constructor
      D.StartSequencing();//Starts the sequencer
    }
  return 0;
}
