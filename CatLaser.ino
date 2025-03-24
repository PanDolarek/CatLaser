#include "catMotion.h"

void setup() {
  posX = posY = 90;
  axisX.attach(PORTX);
  axisY.attach(PORTY);

  axisX.write(posX);
  axisY.write(posY);
}

void loop() {
  moveToPoint(random(-30, 30), random(-35, -15), dt);
}
