#include "SpaceShipGame.h"
#include "OurShip.h"
#include "EnemyShip.h"
#include "Asteroid.h"
#include "Box.h"
#include "GeneralExplosion.h"
#include "EnemyExplosion.h"
#include "AsteroidExplosion.h"
#include "FlyingObject.h"
#include "ShootingEnemy.h"
#include "StrongAsteroid.h"
using namespace std;

bool SpaceShipGame::OnUserCreate() {
	gameStarted = false;
	gameOver = false;
	createStartObjects();
	return true;
}

bool SpaceShipGame::OnUserUpdate(float Time) {

	Clear(olc::DARK_GREEN);
	SetPixelMode(olc::Pixel::ALPHA);

	if (!(gameStarted))
		GameStartScreen();

	else {
		if (gameOver) {
			
			GameEnded();
			
			printGameOverScreen();
			
			return ExitGame();
		}

		else {
			if (gamePaused) {
				GameIsPaused();
			}
					
			else {
				GameIsOn(Time);
			}
		}
	}
	return true;
}


void SpaceShipGame::setNuke(bool nuke) {
	OS_Nuke = nuke;
}

void SpaceShipGame::increaseAst_hit() {
	ast_hit++;
}

void SpaceShipGame::increaseEnemy_hit() {
	enemy_hit++;
	if (!(OS_Nuke) && !(collectability))  //checks if we have a nuke
		count++;
}

void SpaceShipGame::increaseBoxes_col() {
	boxes_col++;
	setNuke(true); //if we collect a box, then we will have a nuclear bomb
}

void SpaceShipGame::increaseNucblast() {
	nucblast++;
}

bool SpaceShipGame::checkNuke() {
	return OS_Nuke;
}

void SpaceShipGame::setCollectability(bool collect) {
	collectability = collect;
}

void SpaceShipGame::deleteFO(FlyingObject* object) {
	if(object){
		delete object;
		object = nullptr;
	}
	
}
SpaceShipGame::~SpaceShipGame() {

}

void SpaceShipGame::printPauseScreen(){
	DrawString(50, 50, "GAME PAUSED");
	DrawString(50, 75, "PRESS ENTER TO CONTINUE");
	DrawString(50, 100, "ASTEROIDS HIT: " + to_string(ast_hit));
	DrawString(50, 125, "ENEMIES HIT: " + to_string(enemy_hit));
	DrawString(50, 150, "BOXES COLLECTED: " + to_string(boxes_col));
	DrawString(50, 175, "NUCLEAR BLASTS PERFORMED: " + to_string(nucblast));
	DrawString(50, 200, "TOTAL SCORE: " + to_string(ast_hit * 3 + enemy_hit * 5 + boxes_col * 3 + nucblast * 4 + (int)surv_time));
}

void SpaceShipGame::printGameOverScreen() {
	DrawString(50, 50, "GAME OVER");
	DrawString(50, 75, "ASTEROIDS HIT: " + to_string(ast_hit));
	DrawString(50, 100, "ENEMIES HIT: " + to_string(enemy_hit));
	DrawString(50, 125, "BOXES COLLECTED: " + to_string(boxes_col));
	DrawString(50, 150, "NUCLEAR BLASTS PERFORMED: " + to_string(nucblast));
	DrawString(50, 175, "YOU HAVE SURVIVED " + to_string(surv_time) + " SECONDS");
	DrawString(50, 200, "TOTAL SCORE: " + to_string(ast_hit * 3 + enemy_hit * 5 + boxes_col * 3 + nucblast * 4 + (int)surv_time));
	DrawString(50, 250, "PRESS E TO EXIT");
}

void SpaceShipGame::printStartScreen() {
	DrawString(150, 100, "SPACESHIP GAME");
	DrawString(125, 125, "PRESS ENTER TO START");
	DrawString(100, 225, "GAMEPLAY");
	DrawString(100, 250, "-USE W-A-S-D TO CONTROL THE SHIP");
	DrawString(100, 275, "-PRESS SPACE TO SHOOT");
	DrawString(100, 300, "-AVOID COLLISIONS");
}

void SpaceShipGame::printNukePossession() {
	DrawString(80, 10, "Nuclear weapon is activated");
	DrawString(75, 30, "Press 'shift' to kill'em all");
}

void SpaceShipGame::createStartObjects() {
	FlyingObjects.push_back(new OurShip(this)); //our ship in the beginning
	FlyingObjects.push_back(new EnemyShip(this)); //enemy ship in the beginning
	FlyingObjects.push_back(new ShootingEnemy(this));
	FlyingObjects.push_back(new Asteroid(this));
	FlyingObjects.push_back(new StrongAsteroid(this)); //asteroid in the beginning
}

void SpaceShipGame::startGame() {
	gameStarted = true;
}

bool SpaceShipGame::ExitGame() {
	if (GetKey(olc::E).bPressed)
		return false;
	else
		return true;
}

void SpaceShipGame::EndGame() {
	gameOver = true;
}

void SpaceShipGame::GameEnded() {
	while (number < 1) {
		//this loop will execute only once. so, every remaining item will be deleted when the game is over. 
		//the program won't try to re-delete them after they were already deleted.
		for (int l = 0; l < FlyingObjects.size(); l++) {
			//FlyingObjects[l]->DeleteSprite(); //deleting the sprites of the remaining objects and sets the pointers to nullptr
			deleteFO(FlyingObjects[l]); //deleting the remaining objects and set the pointers to nullptr
			FlyingObjects.erase(FlyingObjects.begin() + l);
			l--; //if we don't do this, we get a "vector subscription out of range" error.
			//the reason is that one object is erased in each iteration of this for loop
		}

		number++; //we increase "number" so that this loop will not execute again
	}
}
void SpaceShipGame::GameIsOn(float Time) {
	surv_time += Time;

	if (GetKey(olc::P).bPressed)
		gamePaused = true;

	if (OS_Nuke)
		printNukePossession();

	for (int i = 0; i < FlyingObjects.size(); i++) {
		FlyingObjects[i]->FO_move(Time); //calls moving function of the objects in cooperation with time
		if (FlyingObjects[i]->Fired()) {
			if (superfireCheck()) { //checks if we can fire a strong bullet
				if (superFireCount == 0) {
					FlyingObjects.push_back(FlyingObjects[0]->superfire()); //creates strong bullet when 5 asteroids are hit
					superFireCount++;
				}
				else {
					FlyingObjects.push_back(FlyingObjects[i]->fire()); //creates normal bullet if a strong bullet is already on the screen
				}
			}
			else {
				FlyingObjects.push_back(FlyingObjects[i]->fire()); //creates bullet when the player wants to fire
				superFireCount = 0;
			}

		}
		FlyingObjects[i]->FO_draw(Time); //calls drawing function of the objects
		FlyingObjects[i]->timeUpdate(Time); //calls time update function, used especially for the occurrence time of explosion
		if (FlyingObjects[i]->death()) {
			FlyingObjects[i]->DeleteSprite(); //deleting sprites of objects that died
			deleteFO(FlyingObjects[i]); //deletes objects and turns pointers to nullptr
			FlyingObjects.erase(FlyingObjects.begin() + i);
			i--; //an object is erased in the vector, so i must decrease
		}

		if (count == 5) { //boxes appear when we hit five enemy ships
			FlyingObjects.push_back(new Box(this));
			count = 0;
		}

		for (int j = 0; j < FlyingObjects.size(); j++) {
			if (i != j) {
				FlyingObjects[i]->CoordinatesForShootingEnemy(FlyingObjects[j]); //sending coordinates to follow an object
				FlyingObjects[i]->FO_collision(FlyingObjects[j]); //checking if objects collide or not
				FlyingObjects[i]->NucBlast(FlyingObjects[j]); //for nuclear blasts
			}
		}
		if (FlyingObjects[0]->death()) {
			//if our ship dies, game is over
			EndGame();
		}
		if (FlyingObjects[i]->specialDeath())  //checks if an enemy is dead, so that there will be an explosion
			FlyingObjects.push_back(FlyingObjects[i]->explode()); //creates an explosion
		if (FlyingObjects[i]->gameOverCheck()) //checks whether strong asteroid reached to the left end of the screen
			EndGame();
		
	}
}




void SpaceShipGame::GameIsPaused() {
	printPauseScreen();
	GameResume();
}


void SpaceShipGame::GameResume() {
	if (GetKey(olc::ENTER).bPressed)
		gamePaused = false;
}


void SpaceShipGame::GameStartScreen(){
	printStartScreen();
	if (GetKey(olc::ENTER).bPressed)
		startGame();

}

bool SpaceShipGame::superfireCheck() {
	if (ast_hit != 0 && ast_hit % 5 == 0) //if we hit 5 asteroids, we can fire a strong bullet
		return true;
	else
		return false;
}