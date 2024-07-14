#include <random>
#include "../core/vectors.h"

using namespace std;

int main(){
    srand(time(0));
    PointsToCompare vectors = initializeVectors(10);
    float distance = calculateDistance(vectors.first.size(), vectors);

    for(int i = 0; i < vectors.first.size(); i++){
        cout << vectors.first[i] << ' ' << vectors.second[i] << endl;
    }
    cout << "distance : " << distance << endl;
}