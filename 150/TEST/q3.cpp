#include <iostream>
#include <cmath>
using namespace std;

struct triangle {
	double side1, side2, angle;
	
	triangle(double newSide1, double newSide2, double newAngle)
	{
		side1 = newSide1;
		side2 = newSide2;
		angle = newAngle;
	}
};

double area(triangle tri)
{
	return (.5) * tri.side1 * tri.side2 * (sin(tri.angle));
}

int main()
{
	triangle first(10, 24, 1.5708);
	triangle second = {7, 7, 1.0472};
	
	cout << "Triangle with side length " << first.side1 << " and " << first.side2 << " with angle " << first.angle
	     << " has a total area of " << area(first) << endl;
	     
	cout << "Triangle with side length " << second.side1 << " and " << second.side2 << " with angle " << second.angle
	     << " has a total area of " << area(second) << endl;

}
