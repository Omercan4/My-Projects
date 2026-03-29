#pragma once
#include "FlyingObject.h"
class OurShip :
    public FlyingObject
{
    int count = 0; //our ship needs to get hit twice by bullets. therefore we need count.

public:
    OurShip(SpaceShipGame*); //constructor
    void FO_move(float time); //move function of our ship
    FlyingObject* fire(); //creates bullets 
    bool Fired(); //returns true when player presses "SPACE" to fire
    FlyingObject* superfire();
    void FO_collision(FlyingObject* object); //function that compares coordinates and detects if our ship can collect a box
    bool Check_collision(double, double, double, double, string); //checks if ourship collides with asteroids or enemyships. if this returns true, our ship dies and game is over.
    void CoordinatesForShootingEnemy(FlyingObject*);
    bool MouseCoordinateCompare();
};