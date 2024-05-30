#include "LED_UTILS.h"
#include "MAP_UTILS.h"
#include "GENERATING_UTILS.h"
#include "KEYBOARD_UTILS.h"
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

//POSITION VARIABLES
int mapNumber = 1;
int row = 0, column = 0;
int start = 0, endPosition = 0;
//GAME VARIABLES
int isGameFinished = 0;
int loadedMap = 0;
//OBSTACLE VARIABLES 
unsigned long lastTimeGenerate = 0;
int obstaclePosition = 0;
int generatedFirstTime = 0;

/****************************************************
4x4 keyboard matrix
(reduced to 3x2)
Connect:

Row 1 to Arduino pin 2
Row 2 to Arduino pin 3
Row 3 to Arduino pin 4

Column A to Arduino pin 8
Column B to Arduino pin 9

Key identification:
(with connector at the top)
0 1 2 
4 5 6
****************************************************/

//SET UP VARIABLES FOR KEYBOARD MATRIX
int rowCounter = 0; // row counter
int columnCounter = 0; // column counter
int foundColumn = 0;
boolean foundCol = false;
int keyValue = 0;
int noKey = 0;
boolean readKey = false;
int debounce = 300; // set this to the lowest value that gives the best result
const int row1 = 2;
const int row2 = 3;
const int row3 = 4;

const int colA = 8;
const int colB = 9;



void setup() {
  pinMode(row1, OUTPUT);
  pinMode(row2, OUTPUT);
  pinMode(row3, OUTPUT);

  pinMode(colA, INPUT_PULLUP);
  pinMode(colB, INPUT_PULLUP);
  strip.begin();
  strip.clear();
  strip.show(); // Initialize all pixels to 'off'
}

// moves the character based on the key that was pressed
int MoveCharacter(int keyValue,int mapNumber) {
  if (keyValue == 4) //right
  {
//checks if the move is not out of bounds and if the position wanted is not a wall/obstacle, or if the position is the end position
    if ((column + 1) <= 15 && (strip.getPixelColor(getLEDpos(column + 1, row)) == off || strip.getPixelColor(getLEDpos(column + 1, row)) == endColor))
    { 
      strip.setPixelColor(getLEDpos(column, row), off);
      column = column + 1;
      strip.setPixelColor(getLEDpos(column, row), personColor);
    }
//checks if in bounds and if its the obstacle position that the character wants to be moved into, if so the two positions will blink and then the map will restart
    else if((column + 1) <= 15 && getLEDpos(column+1,row) == obstaclePosition){
      BlinkAndRestart(&column,&row,obstaclePosition,&start,&endPosition,mapNumber);
    }
  }
  else if (keyValue == 6) //left
  {
    if ((column - 1) >= 0 && (strip.getPixelColor(getLEDpos(column - 1, row)) == off || strip.getPixelColor(getLEDpos(column - 1, row)) == endColor))
    {
      strip.setPixelColor(getLEDpos(column, row), off);
      column = column - 1;
      strip.setPixelColor(getLEDpos(column, row), personColor);
    }
    else if( (column - 1) >= 0 && getLEDpos(column-1,row) == obstaclePosition){  
      BlinkAndRestart(&column,&row,obstaclePosition,&start,&endPosition,mapNumber);
    }
  } 
  else if (keyValue == 5) //down
  {
    if ((row - 1) >= 0 && (strip.getPixelColor(getLEDpos(column, row - 1)) == off || strip.getPixelColor(getLEDpos(column, row - 1)) == endColor))
    {
      strip.setPixelColor(getLEDpos(column, row), off);
      row = row - 1;
      strip.setPixelColor(getLEDpos(column, row), personColor);
    }
    else if( (row - 1) >= 0 && getLEDpos(column,row-1) == obstaclePosition){  
     BlinkAndRestart(&column,&row,obstaclePosition,&start,&endPosition,mapNumber);
    }
  } 
  else if (keyValue == 1) //up
  {
    if ((row + 1) <= 15 && (strip.getPixelColor(getLEDpos(column, row + 1)) == off || strip.getPixelColor(getLEDpos(column, row + 1)) == endColor))
    {
      strip.setPixelColor(getLEDpos(column, row), off);
      row = row + 1;
      strip.setPixelColor(getLEDpos(column, row), personColor);
    }
    else if( (row + 1) <= 15 && getLEDpos(column,row+1) == obstaclePosition){
      BlinkAndRestart(&column,&row,obstaclePosition,&start,&endPosition,mapNumber);
    }
  }
  strip.show();
  if (getLEDpos(column, row) == endPosition)// function only returns 1 if the end position has been reached
    return 1;
  else return 0;
}

int playGame(int mapNumber) {
  if (noKey == 6) { // no keys were pressed
    readKey = true; // keyboard is ready to accept a new keypress
  }
  noKey = 0;
  //rescans all the rows and columns for new key pressed
  for (rowCounter = row1; rowCounter < (row3 + 1); rowCounter++) {
    scanRow(row1,row3,rowCounter); // switch on one row at a time

    for (columnCounter = colA; columnCounter < (colB + 1); columnCounter++) {
      readColumn(&foundColumn,&columnCounter,&foundCol,& noKey); // read the switch pressed
      if (foundCol == true) {
        keyValue = (rowCounter - row1) + 4 * (columnCounter - colA);
      }
    }
  }
  if (readKey == true && noKey == 5) { // if a key has been pressed 
    isGameFinished = MoveCharacter(keyValue,mapNumber); // try to move character, and see if the game is finished
    readKey = false; // rest the flag
    delay(debounce); // debounce
    if (isGameFinished)
      return 1;
    else return 0;
  }
  return 0;
}

void loop() {
  if (loadedMap == 0) {//safeguard so the maps are not loaded on each loop, only when game is finished
    loadMaps(mapNumber,&start,&endPosition,&column,&row);
    loadedMap = 1;
  }
  generateObstacleOnTime(4000,&lastTimeGenerate,&obstaclePosition,&generatedFirstTime);

  if (playGame(mapNumber)) {
        OK();
       LoadScore(mapNumber);
      delay(3000);
      generateAnimationOnTimeAnimation(mapNumber,40);
      delay(500);
      loadedMap = 0;
      isGameFinished = 0;
      
    if (mapNumber == 4) { //if the current map is map 4 the next one should be map 1
      mapNumber = 1;      
    } else { 
      mapNumber++;
    }
  }
}
