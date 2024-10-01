#include <cmath>
#include <random>

using namespace std;

float calculateDifferencePercentage(float a, float b);

float calculateMean(float* tab, int size);

float calculateDeviation(float* tab, float mean, int size);

float calculateConfidence(float mean, float z, float deviation, float size);

bool isIn(int* list, int size, int value);