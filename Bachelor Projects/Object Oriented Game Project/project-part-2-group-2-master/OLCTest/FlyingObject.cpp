#include "FlyingObject.h"
#include "olcSimpleEngine.h"

// parametric constructor
FlyingObject::FlyingObject(double speed_In, double x_coord_In, double y_coord_In, int dim_x_In, int dim_y_In, bool alive_In, SpaceShipGame* game_In)
	: FO_speed(speed_In), FO_x(x_coord_In), FO_y(y_coord_In), FODim_x(dim_x_In), FODim_y(dim_y_In), FO_Alive(alive_In), game(game_In)
{
}

void FlyingObject::FO_move(float time) {}

void FlyingObject::FO_draw(float time) {
		game->DrawSprite(FO_x, FO_y, sprite);
}

void FlyingObject::NucBlast(FlyingObject* object) {}

FlyingObject* FlyingObject::fire() {
	return nullptr; 
}

FlyingObject* FlyingObject::superfire() {
	return nullptr;
}

FlyingObject* FlyingObject::explode() {
	return nullptr;
}

bool FlyingObject::Fired() { 
	return false;
}

bool FlyingObject::death() {
	if (FO_Alive == false)
		return true;
	return false;
}

bool FlyingObject::specialDeath() {
	return false;
}

void FlyingObject::timeUpdate(float time) {}

void FlyingObject::FO_collision(FlyingObject* object) {}

bool FlyingObject::Check_collision(double xMin, double xMax, double yMin, double yMax, string object) {
	return false;
}

bool FlyingObject::Box_collection(double xMin, double xMax, double yMin, double yMax, string object) {
	return false;
}

void FlyingObject::DeleteSprite() {
	delete sprite;
	sprite = nullptr; 
}


void FlyingObject::CoordinatesForShootingEnemy(double y) {

}

void FlyingObject::CoordinatesForShootingEnemy(double x, double y) {

}

bool FlyingObject::gameOverCheck() {
	return false;
}

void FlyingObject::CoordinatesForShootingEnemy(FlyingObject* object) {

}

bool FlyingObject::isStrong() {
	return false;
}

FlyingObject::~FlyingObject() {
	delete sprite;
	sprite = nullptr;
}