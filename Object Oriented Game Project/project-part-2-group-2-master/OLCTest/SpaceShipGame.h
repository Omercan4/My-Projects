#pragma once
#include "olcSimpleEngine.h"
using namespace std;
class FlyingObject; //forward declaration

class SpaceShipGame : public olc::PixelGameEngine
{
	bool gamePaused; //returns true if game is paused
	bool gameStarted; //returns true if game has started
	bool gameOver; //returns true if game is over
	vector<FlyingObject*> FlyingObjects; //vector that contains every flying object in the game

	bool collectability = false; //checks if there is a box that can be collected
	bool OS_Nuke = false; //checks whether OurShip has a nuke or not
	bool superfire = true; //this controls our ability to fire a strong bullet
	int ast_hit = 0; //counts number of asteroids hit
	int enemy_hit = 0; //counts number of enemy ships hit
	int count = 0; //this will be used for the appearance of boxes
	int boxes_col = 0; //counts boxes collected
	int nucblast = 0; //counts nukes blasted
	double surv_time = 0; //total survival time
	

	int number = 0; //this will prevent us from trying to delete an already deleted object
	int superFireCount = 0; //this will prevent us to fire a strong bullet consecutively

	void deleteFO(FlyingObject*); //deletes the object and turns pointer into nullptr to avoid memory leak

	//below are the methods that print some specific situation on the screen
	void printStartScreen(); //prints the necessary information before game start
	void printPauseScreen(); //prints the necessary information when game is paused
	void printGameOverScreen(); //prints the necessary information when game is over
	void printNukePossession(); //prints the necessary information when the player has a nuke
	void createStartObjects();

public:
	bool OnUserCreate(); 
	bool OnUserUpdate(float); 
	void setNuke(bool); //determines if we have a nuclear bomb
	bool checkNuke(); //checks if we have nuke
	void increaseAst_hit(); //increases ast_hit by 1 each time it is called
	void increaseEnemy_hit(); //increases enemy_hit by 1 each time it is called
	void increaseBoxes_col(); //increases boxes_col by 1 each time it is called
	void increaseNucblast(); //increases nucblast by 1 each time it is called
	void setCollectability(bool); //to determine if there is a box to be collected
	void startGame();
	void EndGame();
	bool ExitGame();
	void GameEnded(); // just a function to gather messy codes
	void GameIsOn(float); // just a function to gather messy codes
	void GameIsPaused(); // just a function to gather messy codes
	void GameResume();
	void GameStartScreen();

	bool superfireCheck();
	
	~SpaceShipGame(); //destructor
};
