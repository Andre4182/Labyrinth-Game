#ifndef MAP_UTILS_H
#define MAP_UTILS_H

#include "LED_UTILS.h"

//sets a hardcoded map, sets the person position by setting column and row parameters and sets the starting and end positions
void LoadMap1(int *start,int *endPosition, int * column, int *row) {
  strip.clear();
  //set the initial position of the person
  *column = 1; //column e x
  *row = 0; // row e y

  fillFullColumn(0,wallColor);
fillFullColumn(15,wallColor);
fillFullRow(15,wallColor);
fillRow(wallColor,14,6,-1);
fillRow(wallColor,13,1,2,3,4,8,9,10,11,12,13,-1);
fillRow(wallColor,12,4,5,7,8,12,-1);
fillRow(wallColor,11,2,3,4,10,-1);
fillRow(wallColor,10,6,8,10,11,12,13,-1);
fillRow(wallColor,9,1,2,3,4,5,6,8,10,-1);
fillRow(wallColor,8,8,10,12,13,14,-1);
fillRow(wallColor,7,2,3,4,5,6,8,10,-1);
fillRow(wallColor,6,2,6,8,10,11,12,13,-1);
fillRow(wallColor,5,2,4,6,8,10,-1);
fillRow(wallColor,4,2,4,6,8,10,11,13,-1);
fillRow(wallColor,3,4,6,8,10,13,-1);
fillRow(wallColor,2,1,2,4,6,7,8,10,11,12,13,-1);
fillRow(wallColor,1,4,10,-1);
fillRow(wallColor,0,2,3,4,5,6,7,8,9,10,11,12,14,-1);


  //personaj + finish
  *start = 16;
  *endPosition =208 ;
  strip.setPixelColor(*start, personColor);
  strip.setPixelColor(*endPosition, endColor);
  strip.show();
}

void LoadMap2(int *start,int *endPosition, int * column, int *row) {
  strip.clear();
  //set the initial position of the person
  //y=15, x=0
  *column = 1; //column e x
  *row = 15; // row e y

     fillFullColumn(0,wallColor);
    fillFullRow(0,wallColor);
fillRow(wallColor,15,2,3,4,5,6,7,8,9,10,11,12,13,14,15,-1);
fillRow(wallColor,14,8,15,-1);
fillRow(wallColor,13,2,3,4,5,6,8,10,11,12,15,-1);
fillRow(wallColor,12,2,4,6,8,10,12,15,-1);
fillRow(wallColor,11,2,4,6,8,10,12,15,-1);
fillRow(wallColor,10,4,10,15,-1);
fillRow(wallColor,9,2,3,4,6,7,8,9,10,12,13,14,15,-1);
fillRow(wallColor,8,4,6,9,12,15,-1);
fillRow(wallColor,7,1,2,4,6,7,9,10,11,12,15,-1);
fillRow(wallColor,6,4,6,11,14,15,-1);
fillRow(wallColor,5,2,6,8,9,11,15,-1);
fillRow(wallColor,4,2,3,4,5,6,9,11,13,14,15,-1);
fillRow(wallColor,3,2,6,8,9,11,-1);
fillRow(wallColor,2,2,4,6,8,13,14,15,-1);
fillRow(wallColor,1,4,8,10,15,-1);



  //personaj + finish
  *start = 31;
  *endPosition = 243;
  strip.setPixelColor(*start, personColor);
  strip.setPixelColor(*endPosition, endColor);
  strip.show();

}
void LoadMap3(int *start,int *endPosition, int * column, int *row) {
  strip.clear();
  //set the initial position of the person

  *column = 1; //column e x
  *row = 15; // row e y

  fillFullColumn(0,wallColor);
fillRow(wallColor,15,2,3,4,5,6,7,8,9,10,11,12,13,14,15,-1);
fillRow(wallColor,14,5,13,15,-1);
fillRow(wallColor,13,2,3,5,7,8,9,11,12,13,15,-1);
fillRow(wallColor,12,3,4,5,8,15,-1);
fillRow(wallColor,11,2,3,7,8,9,11,12,13,14,15,-1);
fillRow(wallColor,10,3,5,9,11,-1);
fillRow(wallColor,9,2,3,4,5,7,8,9,11,13,14,15,-1);
fillRow(wallColor,8,2,9,11,15,-1);
fillRow(wallColor,7,4,6,8,9,11,12,15,-1); 
fillRow(wallColor,6,1,2,3,4,6,7,8,9,15,-1);
fillRow(wallColor,5,9,10,11,12,13,15,-1);
fillRow(wallColor,4,2,3,4,5,6,10,13,15,-1);
fillRow(wallColor,3,3,5,10,13,15,-1);
fillRow(wallColor,2,1,5,6,8,10,13,15,-1); 
fillRow(wallColor,1,1,3,8,15,-1);
fillFullRow(0,wallColor);     

  //personaj + finish
  *start = 31;
  *endPosition = 250;
  strip.setPixelColor(*start, personColor);
  strip.setPixelColor(*endPosition, endColor);

  strip.show();
}

void LoadMap4(int *start,int *endPosition, int * column, int *row) {
  strip.clear();
  //set the initial position of the person
  //y=15, x=0
  *column = 4; //column e x
  *row = 15; // row e y

  fillFullColumn(15,wallColor);
fillFullColumn(0,wallColor);
fillFullRow(0,wallColor);  
fillRow(wallColor,15,1,2,3,5,6,7,8,9,10,11,12,13,14,-1);
fillRow(wallColor,14,5,-1);
fillRow(wallColor,13,2,3,5,6,7,8,10,11,12,13,-1);
fillRow(wallColor,12,2,10,-1);
fillRow(wallColor,11,2,8,10,13,-1);
fillRow(wallColor,10,2,6,7,8,10,13,-1);
fillRow(wallColor,9,2,4,8,10,13,-1);
fillRow(wallColor,8,2,4,5,6,8,10,12,13,-1);
fillRow(wallColor,7,2,6,10,-1);
fillRow(wallColor,6,2,3,4,6,10,11,13,14,-1);
fillRow(wallColor,5,4,6,8,11,-1);
fillRow(wallColor,4,2,4,6,8,9,13,-1);
fillRow(wallColor,3,2,4,6,9,10,13,-1);
fillRow(wallColor,2,2,3,4,6,7,9,10,11,12,13,-1);
fillRow(wallColor,1,7,-1);
fillRow(wallColor,0,1,2,3,4,5,6,7,8,9,11,12,13,14,-1);


  //personaj + finish
  *start = 64;
  *endPosition = 175;
  strip.setPixelColor(*start, personColor);
  strip.setPixelColor(*endPosition, endColor);
  strip.show();
}

//loads the current wanted map by "mapNumber" parameter, and passes the rest of the needed paramters to the LoadMap type functions
void loadMaps(int mapNumber,int *start,int *end, int * column, int *row) { 
  if (mapNumber == 1) {
    LoadMap1(start,end,column,row);
  } else if (mapNumber == 2) {
    LoadMap2(start,end,column,row);
  } else if (mapNumber == 3) {
    LoadMap3(start,end,column,row);
  } else if (mapNumber == 4) {
    LoadMap4(start,end,column,row);
  }
}

//a hardcoded image of an "OK" on the matrix
void OK(){
strip.clear();
fillRow(okColor,15,3,4,5,10,14,-1);
fillRow(okColor,14,2,6,10,13,-1);
fillRow(okColor,13,1,7,10,12,-1);
fillRow(okColor,12,1,7,10,11,-1);
fillRow(okColor,11,1,7,10,11,-1);
fillRow(okColor,10,1,7,10,11,-1);
fillRow(okColor,9,1,7,10,11,-1);
fillRow(okColor,8,1,7,10,12,-1);
fillRow(okColor,7,2,6,10,13,-1);
fillRow(okColor,6,3,4,5,10,14,-1);

strip.show();
}

//harcoded image of "1" number on the led matrix
void Load1(){
	fillRow(personColor,4,5,-1);
	fillRow(personColor,3,4,5,-1);
	fillRow(personColor,2,3,5,-1);
	fillRow(personColor,1,5,-1);
	fillRow(personColor,0,5,-1);
}
//harcoded image of "2" number on the led matrix
void Load2(){
	fillRow(personColor,4,3,4,5,-1);
	fillRow(personColor,3,5,-1);
	fillRow(personColor,2,3,4,5,-1);
	fillRow(personColor,1,3,-1);
	fillRow(personColor,0,3,4,5,-1);
}
//harcoded image of "3" number on the led matrix
void Load3(){
	fillRow(personColor,4,3,4,5,-1);
	fillRow(personColor,3,5,-1);
	fillRow(personColor,2,3,4,5,-1);
	fillRow(personColor,1,5,-1);
	fillRow(personColor,0,3,4,5,-1);
}
//harcoded image of "4" number on the led matrix
void Load4(){
	fillRow(personColor,4,3,-1);
	fillRow(personColor,3,3,-1);
	fillRow(personColor,2,3,4,5,-1);
	fillRow(personColor,1,5,-1);
	fillRow(personColor,0,5,-1);
}

//function to load a score of "x/4", where x is the number of maps finished, on the matrix
void LoadScore(int mapNumber){

  if(mapNumber==1)
    Load1();
  else if(mapNumber==2)
    Load2();
  else if(mapNumber==3)
    Load3();
  else if (mapNumber==4)
    Load4();

  fillRow(personColor,4,10,-1);
  fillRow(personColor,3,10,-1);
  fillRow(personColor,2,10,11,12,-1);
  fillRow(personColor,1,12,-1);
  fillRow(personColor,0,12,-1);
  
  fillRow(DashColor,3,9,-1);
  fillRow(DashColor,2,8,-1);
  fillRow(DashColor,1,7,-1);
  fillRow(DashColor,0,6,-1);

strip.show();
}

//makes the person and obstacle blink for a few times before loadind the map again and making the person restart the current map
void BlinkAndRestart(int *columnP,int *rowP,int obstacle,int *start,int *endPosition,int mapNumber){
  int person=getLEDpos(*columnP,*rowP);

  strip.setPixelColor(person, off); 
  strip.setPixelColor(obstacle, off);
  strip.show();
  delay(1000);
  
  strip.setPixelColor(person, personColor);
  strip.setPixelColor(obstacle, obstacleColor);
  strip.show();
  delay(1000);
  
  strip.setPixelColor(person, off);
  strip.setPixelColor(obstacle, off);
  strip.show();
  delay(1000);
  
  strip.setPixelColor(person, personColor);
  strip.setPixelColor(obstacle, obstacleColor);
  strip.show();
  delay(1000);
  
  strip.setPixelColor(person, off);
  strip.setPixelColor(obstacle, off);
  strip.show();
  delay(1000);
  
  strip.setPixelColor(person, personColor);
  strip.setPixelColor(obstacle, obstacleColor);
  strip.show();

  loadMaps(mapNumber,start,endPosition,columnP, rowP);
}

#endif
