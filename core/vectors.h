#include <vector>
#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;

const int MIN_INT = 0;
const int MAX_INT = 100;

struct PointsToCompare
{
	vector<float> first;
	vector<float> second;
};


PointsToCompare initializeVectors(int nbRows);

const float calculateDistance(int nbRows, PointsToCompare points);

PointsToCompare createNewPoints(PointsToCompare points, int* indexList, int size);

const ostream& operator<<(ostream& os, PointsToCompare& points);