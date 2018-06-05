#ifndef TEMA_MEMBRU_CLUB_H
#define TEMA_MEMBRU_CLUB_H

#include <iostream>
#include "membru.h"
#include <map>

using namespace std;

class Club {
    /**
     * @var map<string, Membri> membri Lista membri club
     */
    map<string, Membru> membri;

    /**
     * @var string nume Nume club
     */
    string nume;

    /**
     * @var string oras Numele orasului in care se afla clubul
     */
    string oras;

    map <int, string> tipMembri = {
            {1, "Standard"},
            {2, "Gold"},
            {3, "Premium"}

    };

    public:
        /**
         * Club constructor
         * @param string nume
         * @param string oras
         */
        Club(string nume, string oras) {
            this->nume = nume;
            this->oras = oras;
        }

        /**
         * Inserare membru in lista de membri
         * @param string numeMembru
         * @param string tipMembru
         * @param int cotizatie
         * @return bool
         */
        bool inserareMembru(string numeMembru, string tipMembru, int cotizatie) {
            if (this->membri.find(numeMembru) != this->membri.end()) {
                return false;
            }

            this->membri.insert(make_pair(numeMembru, Membru(numeMembru, tipMembru, cotizatie)));

            return true;
        }

        /**
         * Returneaza lista de membri ai clubului
         * @return map<string, Membru>
         */
        map<string, Membru> getMembri() {
            return this->membri;
        };

        /**
         * Getter nume oras
         * @return string
         */
        string getOras() {
            return this->oras;
        }

        /**
         * Obtine Media cotizatilor tuturor membrilor
         * @return
         */
        unsigned long getAverageCotizatie() {
            unsigned long numarMembri = this->membri.size();
            unsigned long totalCotizatie = 0;

            for (auto it : this->membri) {
                totalCotizatie += it.second.getCotizatie();
            }

            return totalCotizatie/numarMembri;
        }

        /**
         * Suprascriere operator scriere
         * @param ostream& os
         * @param Club clubObj
         * @return ostream&
         */
        friend ostream& operator << (ostream& os, const Club &clubObj) {
            os << "Nume club: " << clubObj.nume << endl;
            os << "Oras club: " << clubObj.oras << endl;
            os << "Membri club: " << endl;

            for (auto it : clubObj.membri) {
                os << it.second.getNume() << endl;
            }

            return os;
        }

        /**
         * Indexing operator overloader
         * @param string nume
         * @return Membru
         */
        Membru& operator[] (string nume) {
            return this->membri[nume];
        }

        /**
         * Getter tipuri membru
         * @return map<int,string>
         */
        map <int, string> getTipuri() {
            return this->tipMembri;
        }


};

#endif //TEMA_MEMBRU_CLUB_H
