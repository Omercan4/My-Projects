#include "Bullet.h"
#include "olcSimpleEngine.h"
using namespace std;

Bullet::Bullet(double speed_In, double xIn, double yIn, SpaceShipGame* game) 
	: FlyingObject(speed_In, xIn, yIn, 5, 4, true, game){

	sprite = new olc::Sprite("Sprites/rbullet.png");
	name = "Bullet";
}

void Bullet::FO_move(float time) {

	FO_x += time * FO_speed;

	if (FO_x >= game->ScreenWidth() || FO_x<0) 
		FO_Alive = false;
}

bool Bullet::Check_collision(double xMin, double xMax, double yMin, double yMax, string object) {
	if (FO_x >= xMin && FO_x <= xMax && FO_y >= yMin && FO_y <= yMax && (object == "Asteroid" || object == "EnemyShip" || object == "ShootingEnemy" || object == "StrongAsteroid")) {
		FO_Alive = false;
		return true;
	}

	return false;
}

void Bullet::FO_collision(FlyingObject* object) {
	if (object->Check_collision(FO_x, FO_x + FODim_x, FO_y - 5, FO_y + FODim_y, name)) {
		FO_Alive = false;
	}
}

void Bullet::FO_draw(float time) {
	game->DrawSprite(FO_x, FO_y, sprite, 2);
	if (!FO_Alive) 
		DeleteSprite();
}