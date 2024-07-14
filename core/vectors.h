#include <vector>
#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

struct PointsToCompare
{
    vector<float> first;
    vector<float> second;
};


PointsToCompare initializeVectors(int nbRows);

const float calculateDistance(int nbRows, PointsToCompare vectors);