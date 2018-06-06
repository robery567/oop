#include <iostream>
#include <map>
#include <vector>
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
    map<string, vector<int>> usedColors;
    vector<double> segmentLengths;

    int objIndex = 0;

    for (auto& object : segments) {
        usedColors[object.getSegmentColor()].emplace_back(objIndex);
        segmentLengths.emplace_back(object.getSegmentLength());

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

        ++objIndex;
    }

    sort(segmentLengths.rbegin(), segmentLengths.rend());

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

    cout << endl << "Used Colors: " << endl;
    for (auto color : usedColors) {
        cout << color.first << ":";

        for (auto objId : color.second) {
            cout << objId << ",";
        }

        cout << endl;
    }


    cout << endl << "Sorted segments:" << endl;
    for (auto length : segmentLengths) {
        for (auto segment : segments) {
            if (segment.getSegmentLength() == length) {
                cout << segment;
                cout << "Segment length: " << length << endl << endl;
                break;
            }
        }
    }

    return 0;
}