#ifndef LED_UTILS_H
#define LED_UTILS_H
#include <Adafruit_NeoPixel.h>
#include <stdarg.h>
#define LED_COUNT 256
#define LED_PIN 7
extern Adafruit_NeoPixel strip;
#define yMax 16 //MAX NUMEBRS OF ROWS

//COLORS
#define wallColor strip.Color(0, 0, 255) //albastru
#define okColor strip.Color(0, 100, 0) //verde
#define endColor  strip.Color(0, 50, 0) //verde
#define personColor  strip.Color(255, 0, 255) //roz
#define obstacleColor  strip.Color(255, 0, 0) //rosu
#define off  strip.Color(0, 0, 0) //stins
#define DashColor  strip.Color(255, 255, 255) //white
//method that gets the position of the serpentine led matrix, based on the column and row
//x represents the column number
//y represents the row number
int getLEDpos(int x, int y) { 
  int position;
  if (x & 0x1) { // odd column
    position = x * yMax + y;

  } else { // even column
    position = x * yMax + (yMax - 1 - y);
  }
  return position;
}

//fills the full row of lights placed on the given row number using the given color
void fillFullRow(int rowNr,int color){
  for(int i=0;i<16;i++){
    int pos=getLEDpos(i,rowNr); // gets the position of the light on the row at the current column
    strip.setPixelColor(pos, color); //sets the color of the light 
  }
}

//fills the full column of lights placed on the given column number using the given color
void fillFullColumn(int colNr,int color){
  int firstPos; //stores the first position on the column for strip.fill to use

  if (colNr & 0x1)// an odd column's number order starts from the buttom of the led matrix
    { 
      firstPos=getLEDpos(colNr,0);
       
    }
    else// an even column's number order starts from the top of the led matrix
   {
     firstPos=getLEDpos(colNr,yMax-1);
   }

    strip.fill(color,firstPos, yMax);// filss the full column from start to end, filling yMax positions
}

//fills the row of lights placed on the given row number and at the specific positions given as a variant list of parameters after "rowNr", using the given color
void fillRow(int color,int rowNr, ...) {

 va_list args;//declares a list of arguments
 va_start(args, rowNr); // initialises the list strating from the argument "rowNr"

 while (true)
 {
    int light = va_arg(args, int);// the light number is the current argument
    if (light == -1) // we use "-1" as a flag parameter that the list has ended, so we don't ask for a number of lights as parameter
    {
      break; // if the list has ended the while loop needs to end
    } 
    int pos=getLEDpos(light,rowNr); // the list is not fisished so we need the position of the current light on the wanted row
    strip.setPixelColor(pos, color); // sets the light on the retrieved position with the color parameter

 } 
 va_end(args);//empties the parameter list
 }

#endif
