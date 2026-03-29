#pragma once
#include "Asteroid.h"
using namespace std;

class StrongAsteroid
	: public Asteroid
{
	
	int count = 0;
	
public:
	StrongAsteroid(SpaceShipGame*); //constructor
	bool gameOverCheck();
	void FO_collision(FlyingObject* object);
	void CoordinatesForShootingEnemy(FlyingObject* object);

};

