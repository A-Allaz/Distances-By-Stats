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