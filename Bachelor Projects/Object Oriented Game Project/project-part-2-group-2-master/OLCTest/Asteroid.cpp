#include "Asteroid.h"
#include "GeneralExplosion.h"
#include "time.h"

Asteroid::Asteroid(SpaceShipGame* game)
	: GeneralEnemy(game)
{
	sprite = new olc::Sprite("Sprites/asteroid.png");
	name = "Asteroid";


	
}

