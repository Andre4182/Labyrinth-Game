#ifndef GENERATING_UTILS_H
#define GENERATING_UTILS_H

#include "LED_UTILS.h"

//generates a position in the given interval and checks if the position on the matrix is turned off
int generatePosition(int minVal, int maxVal) {
  int randomPosition;
  uint32_t randomPositionColor = 0;
  do {
    randomPosition = random(minVal, maxVal + 1); // Generate a random number
    randomPositionColor = strip.getPixelColor(randomPosition);

  } while (randomPositionColor != off); // Check if the number is a position that is turned off
  return randomPosition;
}

//generates an obstacle on a random turned off position if enought times has passed by
void generateObstacleOnTime(unsigned long generatingTime,unsigned long* lastTimeGenerate,int *obstaclePosition,int* generatedFirstTime) {
  unsigned long currentTime = millis();

  if (currentTime - *lastTimeGenerate >= generatingTime) {
    *lastTimeGenerate = currentTime;
    if (*generatedFirstTime) {//safeguard to only turn off the last obstacle after the first generation occured, so obstaclePosition initialization is not turned off
      strip.setPixelColor(*obstaclePosition, off);
    } else {
      *generatedFirstTime = 1;// flag to signal that a first time generation happened
    }

    *obstaclePosition = generatePosition(0, LED_COUNT - 1);
    strip.setPixelColor(*obstaclePosition, obstacleColor);
    strip.show();
  }
}

unsigned long lastTimeGenerate1 = 0;
int animationPosition=0;
int wasAnimationPosition=0;

int generatePositionAnimation(int minVal, int maxVal) {
    int randomPosition1;
    uint32_t randomPositionColor1 = 0;
    do {
        randomPosition1 = random(minVal, maxVal + 1); // Generate a random number
        randomPositionColor1 = strip.getPixelColor(randomPosition1);
        
    } while (randomPositionColor1 != off); // Check if the number is a position that is turned off
    return randomPosition1;
}


void generateAnimationOnTimeAnimation(int mapNumber,unsigned long generatingTime) {
  int times=0;
  int maxTimes=0;
  if(mapNumber==1)
    maxTimes=196;
  else if(mapNumber==2)
   maxTimes=192;
  else if(mapNumber==3)
    maxTimes=192;
  else
    maxTimes=194;
  while(times<maxTimes){
    unsigned long currentTime1 = millis();
    
    if (currentTime1 - lastTimeGenerate1 >= generatingTime) {
        lastTimeGenerate1 = currentTime1;
        times=times+1;
       animationPosition= generatePositionAnimation(0, LED_COUNT - 1);
       strip.setPixelColor(animationPosition, okColor);
      strip.show();
    }
  }
}



#endif
