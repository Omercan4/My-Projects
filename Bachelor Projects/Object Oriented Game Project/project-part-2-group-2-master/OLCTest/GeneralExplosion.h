#pragma once
#include "FlyingObject.h"
class GeneralExplosion :
    public FlyingObject
{
protected:
    double explosionTime; //explosion will stay on the screen for 0.5 seconds. this will achieve that.
    int scale; //the scale of asteroid explosion is 1 whereas the scale of enemy explosion is 2. therefore we need scale as a parameter in constructor.

public:
    GeneralExplosion(double, double, SpaceShipGame*); //constructor
    void FO_draw(float); //draws the sprite of theexplosion on the screen
    void timeUpdate(float); //this function will deal with occurrence time of the explosion on the screen (0.5 seconds)
};

