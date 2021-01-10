#ifndef HW2_GAME_H
#define HW2_GAME_H
#endif //HW2_GAME_H

// Get Seed Number
int getSeed();
// Get Target Distance
double getDistance(int value);
// Get Angle Of Elevation
double getAngle();
// Get Amount of Powder
double getPowderAmount();
// Convert Vertical Component to Radians
double getVerticalAngleConvert(double angleDegree);
// Convert Horizontal Component to Radians
double getHorizontalAngleConvert(double angleDegree);
// Calculate Initial Velocity
double getInitialVel(double powderAmount, double radians);
// Calculate Time
double getTime(double initialVel);
// Calculate Horizontal Distance
double getHorizontalDistance(double initialVel, double timeTopArc);



