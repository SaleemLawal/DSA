/*****************************************
** This file contains the main driver program for Project 1.
** A balloon is hidden somewhere on the map, the user has to guess
** the coordinates of the balloon. The program will inform the user
** what direction it is if they are unsuccessful with the guess.
**
**
***********************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

const char NOT_SEARCHED = '$', GUESSED = 'G', BALLOON = 'B', YES = 'y', NO = 'n';
const int WIDTH = 20,  HEIGHT= 20;

void checkDirection(int GuessX, int GuessY, int balloonX, int balloonY);
void startBalloon(int x, int y, int posArr[]);
void resetMap(char arr[][HEIGHT], int xAxis, int yAxis);
bool guessLocation(int xCord, int yCord, int arr[], char map[][HEIGHT], int balloonX, int balloonY);
void printMap(char arr[][HEIGHT], int xAxis, int yAxis);
bool checkBalloon(int x, int y, char arr[][HEIGHT], int balloonX, int balloonY);

int main() {
    /*
     * Data Declaration
     */
    bool continueGame = true, game, notBalloon, choiceCheck = true;
    int choice = 0;
    int guessXCord = 0, guessYCord = 0, balloonX = 0, balloonY = 0;
    char mapArray[WIDTH][HEIGHT];
    int coordinateArr[2];
    int posArr[2];

    cout << "Welcome to the Surveillance Balloon Tracker \n" << "You are searching for the surveillance balloon \n";
    while (continueGame) {
        // need to run this section only when the game is started/ replayed.
        notBalloon = true;

        resetMap(mapArray, WIDTH, HEIGHT);
        startBalloon(balloonX, balloonY, posArr);
        balloonX = posArr[0], balloonY = posArr[1];

        while(notBalloon){
            cout << "What would you like to do?: " << endl;
            cout << "1. Display Map \n" << "2. Guess Location of Balloon \n" << "3. Exit \n";
            // checks for the menu range
            while (choiceCheck) {
                cin >> choice;
                if ((choice != 1) and (choice != 2) and (choice != 3)) {
                    cout << "Please choose again \n" << "What would you like to do?:" << endl;
                    cout << "1. Display Map \n" << "2. Guess Location of Balloon \n" << "3. Exit \n";
                } else {
                    choiceCheck = false;
                }
            }
            choiceCheck = true;
            switch (choice) {

                case 1:
                    printMap(mapArray, WIDTH, HEIGHT);
                    break;
                case 2:
                    game = guessLocation(guessXCord, guessYCord, coordinateArr, mapArray, balloonX, balloonY);
                    if (!game) {
                        // if user chooses not to continue game after winning
                        cout << "Thank you for Using the Surveillance Balloon Tracker";
                        continueGame = false;
                        notBalloon = false;
                    } else if ((coordinateArr[0] == balloonX) and (coordinateArr[1] == balloonY)){
                        notBalloon = false;
                    } else if ((coordinateArr[0] != balloonX) || (coordinateArr[1] != balloonY)){
                        // continue but do not reset map or change balloon location
                        checkDirection(coordinateArr[0], coordinateArr[1], balloonX, balloonY);
                        notBalloon = true;
                    }
                    break;
                case 3:
                    cout << "Thank you for Using the Surveillance Balloon Tracker";
                    notBalloon = false;
                    continueGame = false;
                    break;
                default:
                    // Not needed due to data validation done ahead
                    ;
            }
        }
    }
    return 0;
}

// Function name: printMap
// Pre-condition: A valid map has to be created
// Post-condition: prints the map everytime the user chooses to display option
void printMap(char arr[][HEIGHT], int xAxis, int yAxis){
    // Prints the map which will show ®you $ if that spot has not been guessed yet or a G if that spot has been guessed.
    for (int x = 0; x < xAxis; x++){
        cout << "\t" << x ;
    }
    cout << endl;
    for (int y = 0; y < yAxis; y++){
        cout  << y ;
        for (int i = 0; i < xAxis; i++) {
            cout << "\t" << arr[i][y];
        }
        cout << endl;
    }
}

// Function name: startBalloon
// Pre-condition: Needs a valid size of the map
// Post-condition: places balloon in a random position when the function is called
void startBalloon(int x, int y, int posArr[]){
    // Randomly places the balloon in a random location on the map (not visible)
    srand(time(NULL));
    x = 0 + (rand() % WIDTH);
    y = 0 +(rand() % HEIGHT);
    posArr[0] = x , posArr[1] = y;
}

// Function name: resetMap
// Pre-condition: Array of the map is passed, xAxis and yAxis are each location
// Post-condition: Creates a map and place "$" in all location that hasn't been searched,
//                 reset everytime user chooses to replay
void resetMap(char arr[][HEIGHT], int xAxis, int yAxis){
    // Resets the map to all $.
    // populates the array ( needs to run everytime the game is reset)
    for (int i = 0; i < xAxis; i++){
        for (int j = 0; j < yAxis; j++){
            arr[i][j] = NOT_SEARCHED;
        }
    }
}

// Function name: guessLocation
// Pre-condition: User guess X and Y coordinates
// Post-condition: Returns a boolean after calling "checkBalloon" function
bool guessLocation(int xCord, int yCord, int arr[], char map[][HEIGHT], int balloonX, int balloonY){
    // Allows the user to enter an x and a y location to see if the balloon exists there. Makes sure that they guess a
    // range changes based on the size of the map
    do{
        cout << "Where would you like to look for the balloon? \n";
        cout << "Enter the X coordinate (0 - " << WIDTH - 1 <<  "): \n";
        cin >> xCord;
        cout << "Enter the Y coordinate (0 - " << HEIGHT - 1 << "): \n";
        cin >> yCord;
    } while( ((xCord < 0) || (xCord > WIDTH - 1)) || ((yCord < 0) || ( yCord> HEIGHT -1)));
    arr[0] = xCord, arr[1] = yCord;
    bool game = checkBalloon(arr[0], arr[1], map, balloonX, balloonY);
    return game;

}

// Function name: checkBalloon
// Pre-condition: Valid guess coordinate, compares the balloon location to the guess
// Post-condition: returns a boolean if user found the balloon and either chooses to continue playing or ends the game
bool checkBalloon(int x, int y, char arr[][HEIGHT], int balloonX, int balloonY){
    // Checks if balloon is in specified position and inform user whether they found the balloon or didn't
    char continue_game;
    bool game = true;
    if ((x == balloonX) and (y == balloonY)){
        cout << "You found the balloon!" << endl;
        do{
            cout <<  "Would you like to play again?" << endl;
            cin >> continue_game;
        }while ((continue_game != YES) and (continue_game != NO));

        if (continue_game == YES){
            game = true;
        }else{
            game = false;
        }
    }else {
        cout << "You didn't find the balloon" << endl;
        arr[x][y] = GUESSED;
    }
    return game;
}

// Function name: checkDirection
// Pre-condition: Valid X and Y User guess
// Post-condition: informs what direction the balloon is
void checkDirection(int GuessX, int GuessY, int balloonX, int balloonY){
    /*
     Based on the location guessed, indicates which direction the balloon is. Importantly, if the guess is not on the
     correct north/south, it will always indicate if the balloon is north or south of the current guess.
     Once the north/south value is correct, then this function will return the east/west direction.
     */
    if (GuessY > balloonY){
        cout << "The balloon is north of your guess" << endl;
    } else if ( GuessY < balloonY){
        cout << "The balloon is south of your guess" << endl;
    } else{
        if (GuessX > balloonX){
            cout << "The balloon is west of your guess" << endl;
        } else if (GuessX < balloonX){
            cout << "The balloon is east of your guess" << endl;
        }
    }
}
