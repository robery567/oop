#ifndef TEMA2_SEGMENT_H
#define TEMA2_SEGMENT_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Segment {
    private:
        double xA, xB, yA, yB;
        string color;

    public:
        Segment(double xA, double yA, double xB, double yB, string color) {
            this->xA = xA;
            this->yA = yA;
            this->xB = xB;
            this->yB = yB;
            this->color = move(color);
        }

        double getSegmentLength() {
            return sqrt((this->xB - this->xA) * (this->xB - this->xA) + (this->yB - this->yA) * (this->yB - this->yA));
        }

        friend ostream& operator << (ostream& os, Segment &obj) {
            os << "A(" << obj.xA << "," << obj.yA << ")" << endl;
            os << "B(" << obj.xB << "," << obj.yB << ")" << endl;
            os << "Color: " << obj.color << endl;
            os << "Length: " << obj.getSegmentLength() << endl;
        }
};

#endif //TEMA2_SEGMENT_H
