#ifndef TEMA2_SEGMENT_H
#define TEMA2_SEGMENT_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Segment {
    private:
        /**
         * @var double xA x coordinate of the point A
         */
        double xA;

        /**
        * @var double xB x coordinate of the point B
        */
        double xB;

        /**
        * @var double yA y coordinate of the point A
        */
        double yA;

        /**
        * @var double yB y coordinate of the point B
        */
        double yB;

        /**
         * @var string color Segment color
         */
        string color;

    public:
        /**
         * Segment class constructor
         * @param double xA
         * @param double yA
         * @param double xB
         * @param double yB
         * @param string color
         */
        Segment(double xA, double yA, double xB, double yB, string color) {
            this->xA = xA;
            this->yA = yA;
            this->xB = xB;
            this->yB = yB;
            this->color = move(color);
        }

        /**
         * Gets the length of the segment
         * @return double
         */
        double getSegmentLength() {
            return sqrt((this->xB - this->xA) * (this->xB - this->xA) + (this->yB - this->yA) * (this->yB - this->yA));
        }

        /**
         * Gets the coordinates of the point A
         * @return pair<double, double>
         */
        pair <double, double> getFirstPointCoordinates() {
            return make_pair(this->xA, this->yA);
        }

        /**
        * Gets the coordinates of the point B
        * @return pair<double, double>
        */
        pair <double, double> getSecondPointCoordinates() {
            return make_pair(this->xB, this->yB);
        }

        /**
         * Gets the segment color
         * @return
         */
        string getSegmentColor() {
            return this->color;
        }

        /**
         * The << operator overloading
         * @param &ostream os
         * @param &obj obj
         * @return
         */
        friend ostream& operator << (ostream& os, Segment &obj) {
            os << "A(" << obj.xA << "," << obj.yA << ")" << endl;
            os << "B(" << obj.xB << "," << obj.yB << ")" << endl;
            os << "Color: " << obj.color << endl;
            os << "Length: " << obj.getSegmentLength() << endl;
        }
};

#endif //TEMA2_SEGMENT_H
