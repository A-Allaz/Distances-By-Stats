#include "./vectors.h"
#include "./utils.h"

using namespace std;


PointsToCompare initializeVectors(int nbRows){
    vector<float> firstVector;
    vector<float> secondVector; 

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 100);

    for(int i = 0; i < nbRows; i++){
        firstVector.push_back(dis(gen)); 
        secondVector.push_back(dis(gen));
    }

    PointsToCompare vectors;
    vectors.first = firstVector;
    vectors.second = secondVector;

    return(vectors);
};

const float calculateDistance(int nbRows, PointsToCompare vectors){
    float distance = 0;

    for(int i = 0; i < nbRows; i++){
        distance += pow(vectors.first[i] - vectors.second[i], 2);
    }

    distance = sqrt(distance);
    return(distance);
};