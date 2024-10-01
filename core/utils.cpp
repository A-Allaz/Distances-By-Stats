#include "./utils.h"
#include "vectors.h"

using namespace std;

float calculateDifferencePercentage(float a, float b){
	return(100 - ((a / b) * 100));
};

const ostream& operator<<(ostream& os, PointsToCompare& points){
	for(int i = 0; i < points.first.size(); i++){
		os << " | " <<  points.first[i] << "\t|\t" <<  points.second[i] << "\t|\n";
	}
	return os;
};

float calculateMean(float* tab, int size){
	float sum = 0;
	for(int i = 0; i < size; i++){
		sum += tab[i];
	}
	return sum / (float) size;
};

float calculateDeviation(float* tab, float mean, int size){
	float sum = 0;
	for(int i = 0; i < size; i++){
		sum += pow(mean - tab[i], 2);
	}
	return sqrt(sum / ((float) size));
};

bool isIn(int* list, int size, int value){
	if(size == 0){
		return false;
	}

	for(int i = 0; i < size - 1; i++){
		if(list[i] == value){
			return true;
		}
	}
	
	return false;
};

float calculateConfidence(float mean, float z, float deviation, float size){
	return mean + abs(z * (deviation / sqrt(size)));
};