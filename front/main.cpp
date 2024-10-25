#include <random>
#include "../core/vectors.h"
#include "../core/utils.h"
#include "../sciplot/sciplot.hpp"

using namespace std;

const int POINTS_SIZE = 100;
const int NB_ITERATIONS = 25;

int main(){
	srand(time(0));
	PointsToCompare points = initializeVectors(POINTS_SIZE);
	float distance = calculateDistance(points.first.size(), points);

	std::cout << "distance : " << distance << endl;

	// Generate random sub-points
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(MIN_INT, MAX_INT);

	float** storage = (float**) malloc(POINTS_SIZE * sizeof(NB_ITERATIONS * sizeof(float)));
	for(int i = 0; i < POINTS_SIZE; i++){
		storage[i] = (float*) malloc(NB_ITERATIONS * sizeof(float));
	}

	for(int iter = 0; iter < NB_ITERATIONS; iter++){
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

			storage[i][iter] = difference;
		}
	}

	sciplot::Vec y = sciplot::linspace(0, 1, NB_ITERATIONS);
	sciplot::Vec yDelta = sciplot::linspace(0, 1, NB_ITERATIONS);

	for(int i = 0; i < POINTS_SIZE; i++){
		float iterationMean = calculateMean(storage[i], NB_ITERATIONS);
		float deviation = calculateDeviation(storage[i], iterationMean, NB_ITERATIONS) ;
		y[i] = iterationMean;
		yDelta[i] = calculateConfidence(iterationMean, 1.96, deviation, NB_ITERATIONS);
		std::cout << "number of parameters per point :" << i << "\t mean : " << iterationMean << "\t deviation : " << deviation << endl;
	}

	sciplot::Vec x = sciplot::linspace(0, POINTS_SIZE, POINTS_SIZE);

	sciplot::Plot2D plot;
	plot.palette("paired");
	plot.drawCurveWithPoints(x, y);

	sciplot::Figure figure = {{ plot }};

	sciplot::Canvas canvas = {{ figure }};

	canvas.show();
	canvas.save("test.pdf");
}