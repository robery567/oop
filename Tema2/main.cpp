#include <iostream>
#include "segment.h"

using namespace std;

int main() {
    Segment segments[4] = {
            {2, 3, 4, 5, "red"},
            {1, 1, 7, 7, "blue"},
            {10, 1, 3, 4, "grey"},
            {13, 5, 12, 10, "yellow"}
    };

    for (auto& obiect : segments) {
        cout << obiect << endl;
    }

    return 0;
}