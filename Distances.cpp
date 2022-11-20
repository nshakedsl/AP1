
#include "Distances.h"
#define P 3
#include <cmath>

using namespace std;
// constructor
Distances ::Distances(vector<double> &v1, const vector<double> &v2)
{
    this->v1 = v1;
    this->v2 = v2;
}

// calculate minkowski distance
double Distances::minkowskiDistance()
{
    return minkowskiDistanceGeneric(P);
}

double Distances::minkowskiDistanceGeneric(int exp)
{
    if(v1.empty())
        return 0;
    double distance = 0;
    for (int i = 0; i < v1.size(); ++i)
    {
        distance += pow(abs(v1[i] - v2[i]), exp);
    }
    return pow(distance, 1.0 /exp);
}