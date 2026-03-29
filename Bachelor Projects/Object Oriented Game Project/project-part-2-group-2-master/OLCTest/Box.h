#pragma once
#include "FlyingObject.h"
using namespace std;

class Box :
    public FlyingObject
{

public:
    Box(SpaceShipGame*); //constructor
    bool Box_collection(double, double, double, double, string); //returns true when the box can be collected
};


