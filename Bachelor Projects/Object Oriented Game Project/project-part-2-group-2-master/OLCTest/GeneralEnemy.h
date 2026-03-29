#pragma once
#include "FlyingObject.h"
#include "AsteroidExplosion.h"
#include "EnemyExplosion.h"
class GeneralEnemy :
    public FlyingObject
{

public:
    GeneralEnemy(SpaceShipGame*); //constructor
    void FO_move(float); //move function
    void FO_collision(FlyingObject* object);
    void NucBlast(FlyingObject* object);
    bool IsShiftPressed();
    bool specialDeath(); //this will return true when asteroid dies and explosion will occur
    virtual FlyingObject* explode(); //this will create an explosion
};

