#include "GeneralExplosion.h"
#include "time.h"

GeneralExplosion::GeneralExplosion(double x, double y, SpaceShipGame* game)
	: FlyingObject(0, x, y, 25, 25, true, game)
{
	explosionTime = 0.5;
}


void GeneralExplosion::timeUpdate(float time) {
	explosionTime -= time;
}

void GeneralExplosion::FO_draw(float time) {
	game->DrawSprite(FO_x, FO_y, sprite, scale);
	if (explosionTime < 0)
		FO_Alive = false;
}
