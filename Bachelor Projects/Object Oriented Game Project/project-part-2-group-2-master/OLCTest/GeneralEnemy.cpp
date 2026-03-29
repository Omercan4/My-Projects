#include "GeneralEnemy.h"
#include "GeneralExplosion.h"
#include "EnemyExplosion.h"
#include "AsteroidExplosion.h"	
#include "time.h"

GeneralEnemy::GeneralEnemy(SpaceShipGame* game)
	: FlyingObject(75, game->ScreenWidth(), rand() % (game->ScreenHeight() - 25), 30, 25, true, game)
{

}

void GeneralEnemy::FO_move(float time) {
	FO_x -= time * FO_speed;
	if (FO_x <= -25 || !(FO_Alive)) { //if one ship dies or goes out of range, another ship comes from the right end
		FO_x = game->ScreenWidth();
		FO_y = rand() % (game->ScreenHeight() - 25);
		if (!(FO_Alive)) {
			FO_Alive = true;
			if (name == "Asteroid" || name == "StrongAsteroid")
				game->increaseAst_hit();
			if (name == "EnemyShip" || name == "ShootingEnemy")
				game->increaseEnemy_hit();
		}
	}

}


void GeneralEnemy::FO_collision(FlyingObject* object) {
	if (object->Check_collision(FO_x, FO_x + FODim_x, FO_y - 5, FO_y + FODim_y, name)) {
		FO_Alive = false;
	}
}

void GeneralEnemy::NucBlast(FlyingObject* object) {
	if (game->checkNuke()) { //we can execute the part below if we have a nuke
		if (IsShiftPressed()) {
			FO_Alive = false;
			game->setCollectability(false); //since we used nuke, we can now collect new boxes if we hit 5 enemyships
		}
	}
}

bool GeneralEnemy::IsShiftPressed() {
	return (game->GetKey(olc::SHIFT).bPressed);
}

bool GeneralEnemy::specialDeath() { //this helps to create explosion
	if (!(FO_Alive))
		return true;
	return false;
}

FlyingObject* GeneralEnemy::explode() {
	if (name == "EnemyShip" || name == "ShootingEnemy")
		return new EnemyExplosion(FO_x, FO_y, game); //creates explosion when enemy ship dies
	else
		return new AsteroidExplosion(FO_x, FO_y, game); //creates explosion when asteroid dies
}


