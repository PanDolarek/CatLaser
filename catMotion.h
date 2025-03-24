#ifndef CATMOTION_H
#define CATMOTION_H

#include <Servo.h>

#define PORTX 5
#define PORTY 6

typedef struct point_t
{
  int x;
  int y;
} point_t;

const struct point_t points[] = {
    {25, -25},
    {-25, -25},
    {30, -45},
    {35, -45},
};

Servo axisX, axisY;
int posX, posY;
float dt = 0.0002;

void moveBy(int deltaX, int deltaY, float deltaT)
{
  float currentX = (float)posX, currentY = (float)posY;
  float targetX = currentX + (float)deltaX, targetY = currentY + (float)deltaY;
  float dx = (float)deltaX * deltaT, dy = (float)deltaY / deltaX * dx;
  
  if (deltaX == 0)
  {
    dy = deltaY * deltaT;
    if (deltaY > 0)
    {
      while (currentY < targetY)
      {
        currentY += dy;
        posY = (int)currentY;
        axisY.write(posY);
      }
    }
    else
    {
      while (currentY > targetY)
      {
        currentY += dy;
        posY = (int)currentY;
        axisY.write(posY);
      }
    }
  }
  else if (deltaX > 0)
  {
    while (currentX < targetX)
    {
      currentX += dx;
      currentY += dy;
      posX = (int)currentX;
      posY = (int)currentY;
      axisX.write(posX);
      axisY.write(posY);
    }
  }
  else
  {
    while (currentX > targetX)
    {
      currentX += dx;
      currentY += dy;
      posX = (int)currentX;
      posY = (int)currentY;
      axisX.write(posX);
      axisY.write(posY);
    }
  }
}

void moveToPoint(int X, int Y, float deltaT)
{
  moveBy(X - posX + 90, Y - posY + 90, deltaT);
}

void moveToPoint(point_t p, float deltaT)
{
  moveBy(p.x - posX + 90, p.y - posY + 90, deltaT);
}

#endif
