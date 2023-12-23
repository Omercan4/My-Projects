#pragma once
#include "olcSimpleEngine.h"
#include "SpaceShipGame.h"
class FlyingObject : public olc::PixelGameEngine
{
protected:
	double FO_speed; //moving speed of the object
	double FO_x; //x coordinate
	double FO_y; //y coordinate
	int FODim_x; //width dimension of the object
	int FODim_y; //height dimension of the object
	bool FO_Alive; //living status of the object
	SpaceShipGame* game; //pointer pointing to spaceship game
	olc::Sprite* sprite; //sprite of the object

	string name;

public:
	FlyingObject(double, double, double, int, int, bool, SpaceShipGame*); //parametric constructor
	virtual void FO_move(float); //move function. overridden in child classes.
	virtual void FO_draw(float); //draws the object on the screen. overridden in child classes.
	virtual void NucBlast(FlyingObject* object);
	virtual FlyingObject* fire(); //creates bullet when executed in OurShip class (it is overridden there). we created this function here for future improvements. for example in future enemy ships may fire back to us.
	virtual FlyingObject* superfire(); //creates strong bullet when we hit 5 asteroids
	virtual bool Fired(); //this is to check if "space" is pressed to fire in OurShip class (it is overridden there). we created this function here for future improvements.
	virtual FlyingObject* explode(); //creates explosion. overridden in Asteroid and EnemyShip classes.
	bool death(); //checks if the object is dead
	virtual bool specialDeath(); //to create explosion after Asteroid or Enemyship dies
	virtual void timeUpdate(float); //used for the occurrence time of the explosion. it is overridden in Explosion class. the function is defined here for future improvements (maybe we need other time related processes).
	virtual void FO_collision(FlyingObject*); //compares coordinates and detects collisions
	virtual bool Check_collision(double, double, double, double, string); //checks if there is a collision on the given coordinates
	virtual bool Box_collection(double, double, double, double, string); //checks if OurShip can collect a box
	virtual void DeleteSprite(); //deletes the sprite of the object to avoid memory leak
	virtual void CoordinatesForShootingEnemy(double);
	virtual void CoordinatesForShootingEnemy(double, double);
	virtual bool gameOverCheck();
	virtual void CoordinatesForShootingEnemy(FlyingObject*);
	virtual bool isStrong();
	virtual ~FlyingObject();
};