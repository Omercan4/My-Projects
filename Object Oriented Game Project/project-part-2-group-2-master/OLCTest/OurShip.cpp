#include "OurShip.h"
#include "Bullet.h"
#include "StrongBullet.h"
#include "olcSimpleEngine.h"
using namespace std;

OurShip::OurShip(SpaceShipGame* game)
	: FlyingObject(125, 50, 50, 23, 25, true, game)
{


	sprite = new olc::Sprite("Sprites/spaceship.png");

	name = "OurShip";

}

void OurShip::FO_move(float time) {
	if (game->GetKey(olc::A).bHeld) 
		FO_x -= FO_speed * time;

	if (game->GetKey(olc::D).bHeld) 
		FO_x += FO_speed * time;

	if (FO_x <= 0)
		FO_x = 0;

	if (FO_x + 23 >= game->ScreenWidth()) 
		FO_x = game->ScreenWidth() - 23;

	if (game->GetKey(olc::W).bHeld)
		FO_y -= FO_speed * time;

	if (game->GetKey(olc::S).bHeld)
		FO_y += FO_speed * time;

	if (FO_y <= 0)
		FO_y = 0;

	if (FO_y + 25 >= game->ScreenHeight())
		FO_y = game->ScreenHeight() - 25;
}

FlyingObject* OurShip::fire() {
	return new Bullet(250, FO_x + 24, FO_y + 10, game);
}

bool OurShip::Fired() {
	if (game->GetKey(olc::SPACE).bPressed) {
		return true;
	}
	return false;
}

FlyingObject* OurShip::superfire() {
	return new StrongBullet(350, FO_x + 24, FO_y + 10, game);
}



bool OurShip::Check_collision(double xMin, double xMax, double yMin, double yMax, string object) {
	if (FO_x >= xMin - FODim_x && FO_x <= xMax && FO_y >= yMin - FODim_y && FO_y <= yMax && (object == "Asteroid" || object == "EnemyShip" || object == "ShootingEnemy" || object == "StrongAsteroid")) {
		FO_Alive = false;
		return true;
	}

	if (FO_x >= xMin - FODim_x && FO_x <= xMax && FO_y >= yMin - FODim_y && FO_y <= yMax && (object == "Bullet")) {
		count++;
		if (count == 2) { //our ship must be hit twice by bullets to be destroyed
			FO_Alive = false;
		}
		return true;
	}
	return false;
}

void OurShip::FO_collision(FlyingObject* object) { //collecting box with moving onto the coordinates
	if (object->Box_collection(FO_x - FODim_x, FO_x + FODim_x, FO_y - FODim_y, FO_y + FODim_y, name)) {
		game->increaseBoxes_col();
		game->setNuke(true);
	}
	if (object->Check_collision(FO_x, FO_x + FODim_x, FO_y - 5, FO_y + FODim_y, name)) 
			FO_Alive = false;

	if (MouseCoordinateCompare()) { //collecting box with mouse click
		if (object->Box_collection(game->GetMouseX() - 30, game->GetMouseX(),
			game->GetMouseY() - 25, game->GetMouseY(), name)) {
				game->increaseBoxes_col();
				game->setNuke(true);
		}
	}
}

void OurShip::CoordinatesForShootingEnemy(FlyingObject* object) { //sends y coordinates to shooting enemy
	object->CoordinatesForShootingEnemy(FO_y);
}

bool OurShip::MouseCoordinateCompare() {
	return (game->GetMouse(0).bPressed);
}



	
	