#include <random>
#include "../core/vectors.h"
#include "../core/utils.h"
#include <sciplot/sciplot.hpp>

using namespace std;

const int POINTS_SIZE = 100;

int main(){
	srand(time(0));
	PointsToCompare points = initializeVectors(POINTS_SIZE);
	float distance = calculateDistance(points.first.size(), points);

	cout << points;
	cout << "distance : " << distance << endl;

	// Generate random sub-points
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(MIN_INT, MAX_INT);

	for(int i = 0; i < POINTS_SIZE; i++){
		int j = 0;
		int* list = (int*) malloc((i + 1) * sizeof(int));

		while(j < i){
			int newIndex = dis(gen);
			if(!isIn(list, j, newIndex)){
				list[j] = newIndex;
				j++;
			}
		}

		PointsToCompare newPoints = createNewPoints(points, list, i + 1);
		float newDistance = calculateDistance(i + 1, newPoints);
		float difference = calculateDifferencePercentage(newDistance, distance);

		cout << "size sub-points : " << i + 1 << "\t difference(%) : " << difference << endl;

	}

}