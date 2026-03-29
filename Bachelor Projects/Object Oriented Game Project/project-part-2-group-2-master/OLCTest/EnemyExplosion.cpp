#include "EnemyExplosion.h"

EnemyExplosion::EnemyExplosion(double xIn, double yIn, SpaceShipGame* game)
	: GeneralExplosion(xIn, yIn, game)
{
	scale = 2;
	sprite = new olc::Sprite("Sprites/explosion.png");
}