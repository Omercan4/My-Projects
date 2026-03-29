#include "AsteroidExplosion.h"

AsteroidExplosion::AsteroidExplosion(double xIn, double yIn, SpaceShipGame* game)
	: GeneralExplosion(xIn, yIn, game)
{
	scale = 1;
	sprite = new olc::Sprite("Sprites/exp2.png");
}