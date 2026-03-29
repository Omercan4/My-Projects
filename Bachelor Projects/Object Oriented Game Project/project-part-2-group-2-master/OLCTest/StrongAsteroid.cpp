#include "StrongAsteroid.h"

StrongAsteroid::StrongAsteroid(SpaceShipGame* game)
	: Asteroid(game) 
{

	FO_speed = 40; //strong asteroid is slower
	name = "StrongAsteroid";
	sprite = new olc::Sprite("Sprites/Ast2.png");
}

bool StrongAsteroid::gameOverCheck() { //when strong asteroid reaches to left end, the game is over
	if (FO_x <= -24) {
		return true;
	}
	return false;
}

void StrongAsteroid::FO_collision(FlyingObject* object) {
	if (object->Check_collision(FO_x, FO_x + FODim_x, FO_y - 5, FO_y + FODim_y, name)) {
		if (object->isStrong()) //checks if it collides with strong bullet
			count = 2; //so strong bullet will directly destroy strong asteroid with one hit
		
		else
			count++;

		if(count %2 == 0) //strong asteroid must be hit twice to be destroyed
			FO_Alive = false;
	}
	if (game->checkNuke()) { //we can execute the part below if we have a nuke
 		if (game->GetKey(olc::SHIFT).bPressed) {
			game->increaseNucblast();
			FO_Alive = false;
			game->setNuke(false);
			game->setCollectability(false); //since we used nuke, we can now collect new boxes if we hit 5 enemyships
		}
	}
}

void StrongAsteroid::CoordinatesForShootingEnemy(FlyingObject* object) { //sends its coordinates to strong bullet
	object->CoordinatesForShootingEnemy(FO_x, FO_y);
}


