#include "ShootingEnemy.h"
#include "Bullet.h"

ShootingEnemy::ShootingEnemy(SpaceShipGame* game)
	: EnemyShip(game) {

	name = "ShootingEnemy";
	sprite = new olc::Sprite("Sprites/enemy2.png");
}

FlyingObject* ShootingEnemy::fire() {
	return new Bullet(-200, FO_x - 1, FO_y + 9, game);
}

void ShootingEnemy::CoordinatesForShootingEnemy(double y_In) { //takes coordinates from Our Ship in order to follow it
		FO_y = y_In;
}

bool ShootingEnemy::Fired() { //shooting enemy fires regularly with intervals of 1.5 seconds
	if (bulletTime < 0) {
		bulletTime = 1.5;
		return true;
	}
	return false;
}

void ShootingEnemy::timeUpdate(float time) {
	bulletTime -= time;
}

void ShootingEnemy::FO_move(float time) {
	FO_x -= FO_speed * time;

	if (FO_y <= 0)
		FO_y = 0;

	if (FO_y + 25 >= game->ScreenHeight())
		FO_y = game->ScreenHeight() - 25;

	if (FO_x <= -25 || !(FO_Alive)) { //if one shooting enemy dies or goes out of range, a new ship comes
		FO_x = game->ScreenWidth();
		if (!(FO_Alive)) {
			FO_Alive = true;
			game->increaseEnemy_hit();
		}
	}
}

