#include "EnemyShip.h"
#include "time.h"
#include "Bullet.h"


EnemyShip::EnemyShip(SpaceShipGame* game)
	: GeneralEnemy(game)
{
	FO_speed = 100;
	FODim_x = 27;
	sprite = new olc::Sprite("Sprites/enemy.png");
	name = "EnemyShip";
}