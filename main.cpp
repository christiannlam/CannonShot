#include <iostream>
#include <iomanip>
#include "game.h"
using namespace std;
// CONSTANT VARIABLES
double WINNING_DISTANCE = 1.0;
int main(int argc, char* argv[])
{
    bool shotDistance = false;
    char replay = 'y';
    while (replay == 'y')
    {
        // Ask for seed input
        int seed = getSeed();
        // Randomly generate target distance
        double distance = getDistance(seed);
        cout << "Target is " << fixed << setprecision(2) << distance << "m away." << endl;
        // Ask for Angle of Elevation
        double angle = getAngle();
        // Ask for gunPowder used
        double gunPowder = getPowderAmount();
        // Convert Vertical Component into Radians
        double verticalAngleRadian = getVerticalAngleConvert(angle);
        // Calculate Initial Velocity of Vertical Component
        double initialVerticalVel = getInitialVel(gunPowder, verticalAngleRadian);
        // Convert Horizontal Component into Radians
        double horizontalAngleRadian = getHorizontalAngleConvert(angle);
        // Calculate Initial Velocity of Horizontal Component
        double initialHorizontalVel = getInitialVel(gunPowder, horizontalAngleRadian);
        // Calculate Time of the Top of the Arc
        double timeTopArc = getTime(initialVerticalVel);
        // Calculate Horizontal Distance
        double horizontalDistance = getHorizontalDistance(initialHorizontalVel,timeTopArc);
        while (!shotDistance)
        {
            // If Horizontal Distance less than Target Distance
            if (horizontalDistance < distance && (distance - horizontalDistance) > WINNING_DISTANCE)
            {
                // Retry to Hit Target
                cout << "Shot was " << distance - horizontalDistance << "m short." << endl;
                angle = getAngle();
                gunPowder = getPowderAmount();
                verticalAngleRadian = getVerticalAngleConvert(angle);
                initialVerticalVel = getInitialVel(gunPowder, verticalAngleRadian);
                horizontalAngleRadian = getHorizontalAngleConvert(angle);
                initialHorizontalVel = getInitialVel(gunPowder, horizontalAngleRadian);
                timeTopArc = getTime(initialVerticalVel);
                horizontalDistance = getHorizontalDistance(initialHorizontalVel, timeTopArc);
            }
                // If Horizontal Distance is greater than Target Distance
            else if (horizontalDistance > distance && ( horizontalDistance - distance) > WINNING_DISTANCE)
            {
                // Retry to Hit Target
                cout << "Shot was " << horizontalDistance - distance << "m long." << endl;
                angle = getAngle();
                gunPowder = getPowderAmount();
                verticalAngleRadian = getVerticalAngleConvert(angle);
                initialVerticalVel = getInitialVel(gunPowder, verticalAngleRadian);
                horizontalAngleRadian = getHorizontalAngleConvert(angle);
                initialHorizontalVel = getInitialVel(gunPowder, horizontalAngleRadian);
                timeTopArc = getTime(initialVerticalVel);
                horizontalDistance = getHorizontalDistance(initialHorizontalVel, timeTopArc);
            }
                // Near One Meter
            else if ( horizontalDistance - distance < WINNING_DISTANCE)
            {
                cout << "Target Hit." << endl;
                shotDistance = true;
            }
        }
        cout << "Play Again? (y or n)" << endl;
        cin >> replay;
    }
}



