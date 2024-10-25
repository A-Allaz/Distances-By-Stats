#include <random>
#include <threads.h>
#include "../core/vectors.h"
#include "../core/utils.h"
#include "../sciplot/sciplot.hpp"

using namespace std;

const int POINTS_SIZE = 100;
const int NB_ITERATIONS = 25;

int main(int argc, char *argv[]){
	int points_size = argc > 1 ? atoi(argv[1]) : POINTS_SIZE; 
	srand(time(0));
	PointsToCompare points = initializeVectors(points_size);
	float distance = calculateDistance(points.first.size(), points);

	cout << "distance : " << distance << endl;

	// Generate random sub-points
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(MIN_INT, MAX_INT);

	float** storage = (float**) malloc(points_size * sizeof(NB_ITERATIONS * sizeof(float)));
	for(int i = 0; i < points_size; i++){
		storage[i] = (float*) malloc(NB_ITERATIONS * sizeof(float));
	}

	for(int iter = 0; iter < NB_ITERATIONS; iter++){
		for(int i = 0; i < points_size; i++){
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

	sciplot::Vec y = sciplot::linspace(0, 1, points_size);
	sciplot::Vec yDelta = sciplot::linspace(0, 1, points_size);

	for(int i = 0; i < points_size; i++){
		float iterationMean = calculateMean(storage[i], NB_ITERATIONS);
		float deviation = calculateDeviation(storage[i], iterationMean, NB_ITERATIONS) ;
		y[i] = iterationMean;
		yDelta[i] = calculateConfidence(iterationMean, 1.96, deviation, NB_ITERATIONS);
		std::cout << "sub-dimension used :" << i + 1 << "\t mean diff : " << iterationMean << "%" << "\t deviation : " << deviation << endl;
	}

	sciplot::Vec x = sciplot::linspace(0, points_size, points_size);

	sciplot::Plot2D plot;
	plot.palette("paired");
	plot.drawCurveWithPoints(x, y);
	plot.yrange(0.0, 100);
	plot.xrange(0.0, points_size);

	sciplot::Figure figure = {{ plot }};

	sciplot::Canvas canvas = {{ figure }};

	canvas.show();
	canvas.save("test.pdf");
}