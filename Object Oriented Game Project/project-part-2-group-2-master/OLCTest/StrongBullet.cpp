#include "StrongBullet.h"

StrongBullet::StrongBullet(double speed, double x, double y, SpaceShipGame* game)
	: Bullet(speed, x, y, game) {

	name = "StrongBullet";
	sprite = new olc::Sprite("Sprites/strongbullet.png");

}

void StrongBullet::FO_move(float time) {
	if (FO_x <= StrongAsteroid_X)
		FO_x += FO_speed * time;
	if (FO_x > StrongAsteroid_X)
		FO_x -= FO_speed * time;
	if (FO_y <= StrongAsteroid_Y)
		FO_y += FO_speed * time;
	if (FO_y > StrongAsteroid_Y)
		FO_y -= FO_speed * time;
}

void StrongBullet::CoordinatesForShootingEnemy(double x, double y) { //takes coordinates of strong asteroid
	StrongAsteroid_X = x;
	StrongAsteroid_Y = y;
}

bool StrongBullet::isStrong() {
	return true;
}


