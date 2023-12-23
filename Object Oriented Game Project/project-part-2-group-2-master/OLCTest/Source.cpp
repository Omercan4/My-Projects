#include"olcSimpleEngine.h"
#include<stdio.h>
#include<stdlib.h>
#include "SpaceShipGame.h"

/*
	INSTRUCTIONS:
	Controls: W,A,S,D
	Shoot: SPACE
	Game ends if the player collides with an enemy or an asteroid
*/

int main()
{
	SpaceShipGame game;
	if (game.Construct(400, 400, 1, 1))
		game.Start();

	return 0;
}