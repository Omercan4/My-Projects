#pragma once
#include "Asteroid.h"
#include "FlyingObject.h"
class Bullet :
    public FlyingObject
{

public:
    Bullet(double, double, double, SpaceShipGame*); //constructor
    void FO_move(float); //move function of bullet
    void FO_draw(float); //draws bullet on the screen
    bool Check_collision(double, double, double, double, string); //checks if bullet collides with asteroid or enemyship
    void FO_collision(FlyingObject*);
};


