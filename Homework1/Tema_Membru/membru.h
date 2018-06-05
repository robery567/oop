#ifndef TEMA_MEMBRU_MEMBRU_H
#define TEMA_MEMBRU_MEMBRU_H

#include <iostream>

using namespace std;

class Membru {
    /**
     * @var string nume Numele membrului
     */
    string nume;

    /**
     * @var string tip Tipul membrului (Premium, Gold, Silver, Standard)
     */
    string tip;

    /**
     * @var int cotizatie Cotizatie adusa de catre membru
     */
    int cotizatie;

    public :
        /**
         * Membru constructor
         * @param string nume
         * @param string tip
         * @param int cotizatie
         */
        Membru(string nume, string tip, int cotizatie) {
            this->nume = nume;
            this->tip = tip;
            this->cotizatie = cotizatie;
        }

        /**
         * Getter cotizatie
         * @return int
         */
        int getCotizatie() {
            return this->cotizatie;
        }

        /**
         * Getter tip
         * @return string
         */
        string getTip() {
            return this->tip;
        }

        Membru() = default;

        /**
         * Getter nume
         * @return string
         */
        string getNume() {
            return this->nume;
        }
};

#endif //TEMA_MEMBRU_MEMBRU_H
