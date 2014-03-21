#include "testLib.h"
#include <iostream>

using namespace std;

void testLib::print()
{
	//printf ( "x: %d, y: %d, z: %d ", _x, _y, _z );
	cout << _x << _y << _z << endl;
	cout << xyz << endl;
}

void testLib::setValue(int x, int y, int z)
{
	_x = x;
	_y = y;
	_z = z;
}