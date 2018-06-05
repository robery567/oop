#ifndef __OALA_H
#define __OALA_H

#include <iostream>
#include <string>

using namespace std;

class Oala {
    public:
        int volum;
        string tip, numeFirma;

        Oala(string numeFirma, string tip, int volum) {
            this->numeFirma = numeFirma;
            this->tip = tip;
            this->volum = volum;
        }

        friend ostream& operator << (ostream& os, const Oala &oalaObj) {
            os << "Nume firma: " << oalaObj.numeFirma << endl;
            os << "Tip oala: " << oalaObj.tip << endl;
            os << "Volum: " << oalaObj.volum << endl;

            return os;
        }
};


#endif