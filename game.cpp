#include <iostream>
#include <random>
#include <cmath>
#include "game.h"
using namespace std;
// CONSTANT VARIABLES
int TIME_COMPONENT = 2;
int POWDER_VELOCITY = 30;
double GRAVITY = 9.81;
double PI = 3.141592653589793238463;
int RADIANS = 180;
// Method to Validate User Input of Positive Seed
int getSeed()
{
    int seed;
    cout << "Enter Positive Integer Value." << endl;
    cin >> seed;
    while (seed < 1)
    {
        cout << "Enter Positive Integer Value." << endl;
        cin >> seed;
    }
    return seed;
}
// A Method Randomly Generate A Distance
double getDistance(int value)
{
    uniform_real_distribution<double> distance{ 1.0,1000.0 };
    mt19937 engine = mt19937(value);
    return distance(engine);
}
// Method Validate User Input of Angle
double getAngle()
{
    double angle;
    cout << "Enter Angle Between 0 and 90 Degrees." << endl;
    cin >> angle;
    while (angle > 90 || angle < 0)
    {
        cout << "Enter Angle Between 0 and 90 Degrees." << endl;
        cin >> angle;
    }
    return angle;
}
// Method to Validate User Input of GunPowder
double getPowderAmount()
{
    double gunPowder;
    cout << "Enter Amount Of Gunpowder In Kilograms." << endl;
    cin >> gunPowder;
    while (gunPowder < 0)
    {
        cout << "Enter Amount Of Gunpowder In Kilograms." << endl;
        cin >> gunPowder;
    }
    return gunPowder;
}
// Method to Convert Degree into Radians
double getVerticalAngleConvert( double angleDegree)
{
    return sin( angleDegree * (PI / RADIANS) );
}
// Method to Convert Degree into Radians
double getHorizontalAngleConvert(double angleDegree)
{
    return cos(angleDegree * (PI / RADIANS));
}
// Method to Calculate Initial Velocity
double getInitialVel( double powderAmount, double radians)
{
    double velocity = powderAmount * POWDER_VELOCITY;
    return velocity * radians;
}
// Method to Calculate time
double getTime(double initialVel)
{
    return initialVel / GRAVITY;
}
// Method to Calculate Horizontal Distance
double getHorizontalDistance(double initialVel, double timeTopArc)
{
    return  initialVel * (TIME_COMPONENT * timeTopArc);
}


