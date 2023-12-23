#include "Box.h"
#include "time.h"

Box::Box(SpaceShipGame* game)
	: FlyingObject(0, rand() % (game->ScreenWidth() - 30), rand() % (game->ScreenHeight() - 25), 30, 25, true, game)
{
	sprite = new olc::Sprite("Sprites/box.png");
}

bool Box::Box_collection(double xMin, double xMax, double yMin, double yMax, string object) {
	if (FO_x >= xMin && FO_x <= xMax && FO_y >= yMin && FO_y <= yMax && object == "OurShip") {
		FO_Alive = false;
		game->setCollectability(false);
		return true;
	}
	game->setCollectability(true); //if there is a box and we did not collect it, then this will prevent 2 boxes to appear on the screen
	return false;
}