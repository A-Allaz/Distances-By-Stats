#include "./vectors.h"
#include "./utils.h"

using namespace std;

PointsToCompare initializeVectors(int nbRows){
	vector<float> firstVector;
	vector<float> secondVector; 

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(MIN_INT, MAX_INT);

	for(int i = 0; i < nbRows; i++){
		firstVector.push_back(dis(gen)); 
		secondVector.push_back(dis(gen));
	}

	PointsToCompare points;
	points.first = firstVector;
	points.second = secondVector;

	return(points);
};

const float calculateDistance(int nbRows, PointsToCompare points){
	float distance = 0;

	for(int i = 0; i < nbRows; i++){
		distance += pow(points.first[i] - points.second[i], 2);
	}

	distance = sqrt(distance);
	return(distance);
};

PointsToCompare createNewPoints(PointsToCompare points, int* indexList, int size){
	PointsToCompare newPoints;

	for(int i = 0; i < size; i++){
		newPoints.first.push_back(points.first[i]);
		newPoints.second.push_back(points.second[i]);
	}

	return newPoints;
};