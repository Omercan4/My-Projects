#pragma once
#include "EnemyShip.h"
using namespace std;

class ShootingEnemy :
    public EnemyShip
{
    double bulletTime;

public:
    void timeUpdate(float);
    bool Fired();
    ShootingEnemy(SpaceShipGame*);
    FlyingObject* fire();
    void CoordinatesForShootingEnemy(double);
    void FO_move(float);
};

