#include <iostream>
#include <map>
#include <string>
#include "oala.h"

using namespace std;

int main() {
    Oala oala1("tefal", "tigaie", 200);
    Oala oala2("dry cooker", "tigaie", 300);
    Oala oala3("tefal", "oala", 1000);

    cout << oala1 << endl;
    cout << oala2 << endl;
    cout << oala3 << endl;

    Oala oale[4] = {
            {"tefal", "tigaie", 100},
            {"magic cooker", "oala", 800},
            {"magic cooker", "oala", 900},
            {"tefal", "oala", 1000}
    };

    for (auto& oala : oale) {
        cout << oala << endl;
    }

    int minVolum;

    cout << "Afisam oale cu volum mai mare de: ";
    cin >> minVolum;

    for (auto& oala : oale) {
        if (oala.volum > minVolum) {
            cout << oala;
        }
    }

    map<string, int> tipOala;

    for (auto& oala: oale) {
        if (tipOala.find(oala.tip) == tipOala.end()) {
            tipOala[oala.tip] = 1;
        } else {
            ++tipOala[oala.tip];
        }
    }

    cout << endl << "Tipuri oale intalnite: " << endl;

    for(auto it : tipOala) {
        cout << it.first << endl;
    }

    string searchedOala;
    cout << "Tip oala dorita: ";
    cin >> searchedOala;

    map<string, map<string, int>> tip;

    for (auto& oala: oale) {
        if (oala.tip == searchedOala && (tip.find(oala.numeFirma) == tip.end() || tip[oala.numeFirma].find(oala.tip) == tip[oala.numeFirma].end())) {
            tip[oala.numeFirma][oala.tip] = 1;
        } else {
            ++tip[oala.numeFirma][oala.tip];
        }
    }

    string firmaMax;

    for(auto & it : tip) {
        if (firmaMax.length() == 0) {
            firmaMax = it.first;
        }

        for(auto & it2 : it.second) {
            if (it2.second > tip[firmaMax][searchedOala]) {
                firmaMax = it.first;
            }
        }
    }

    cout << "Firma cu cele mai multe " << searchedOala << " este: " << firmaMax;

    return 0;
}