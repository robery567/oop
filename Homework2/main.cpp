#include <iostream>
#include <map>
#include <algorithm>
#include "segment.h"

using namespace std;

int main() {
    Segment segments[4] = {
            {2, 3, 4, 5, "red"},
            {1, 1, 7, 7, "blue"},
            {10, 1, 3, 4, "grey"},
            {13, 5, 1, 1, "yellow"}
    };

    map<pair<double, double>, int> point;

    for (auto& object : segments) {
        if (point.find(object.getFirstPointCoordinates()) != point.end()) {
            ++point[object.getFirstPointCoordinates()];
        } else {
            point.insert(make_pair(object.getFirstPointCoordinates(), 1));
        }

        if (point.find(object.getSecondPointCoordinates()) != point.end()) {
            ++point[object.getSecondPointCoordinates()];
        } else {
            point.insert(make_pair(object.getSecondPointCoordinates(), 1));
        }

        cout << object << endl;
    }

    map<int, pair<double, double>> sortedPoints;

    for (auto el : point) {
        sortedPoints.insert(make_pair(el.second, el.first));
    }

    cout << "The most used 2 points are: " << endl;
    int count = 0;

    map<int, pair<double, double>>::reverse_iterator it;

    for (it = sortedPoints.rbegin(); it != sortedPoints.rend(); ++it) {
        if (count == 2) {
            break;
        }

        cout << "*(" << it->second.first << "," << it->second.second << ") (" << it->first << " usages)" << endl;
        ++count;
    }

    return 0;
}