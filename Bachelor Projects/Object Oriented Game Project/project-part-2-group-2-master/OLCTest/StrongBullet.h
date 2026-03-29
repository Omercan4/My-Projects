#pragma once
#include "Bullet.h"
class StrongBullet :
    public Bullet
{
    double StrongAsteroid_X;
    double StrongAsteroid_Y;

public:
    StrongBullet(double, double, double, SpaceShipGame*);
    void FO_move(float);
    void CoordinatesForShootingEnemy(double x, double y);
    bool isStrong();
};

