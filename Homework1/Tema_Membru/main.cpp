#include <iostream>
#include "club.h"

using namespace std;

int main() {
    Club club1("pensionari", "Galati");
    Club club2("Tinerii cercetasi", "Timisoara");

    club1.inserareMembru("Marcel Pop", "Standard", 100);
    club1.inserareMembru("Ionut Pavel", "Premium", 1000);
    club1.inserareMembru("Vasilescu Raul", "Gold", 500);

    club2.inserareMembru("Lupu Gheorghe", "Premium", 900);
    club2.inserareMembru("Dragomir Mircea", "Standard", 100);


    cout << club1 << endl;
    cout << club2 << endl;

    cout << endl << club1["Marcel Pop"].getNume() << endl << endl;

    Club clubArray[4] = {
            {"tinerii pelicani", "Constanta"},
            {"Soimii patriei", "Bucuresti"},
            {"CodersDojo", "Timisoara"},
            {"Club gimnastica", "Timisoara"}
    };

    clubArray[0].inserareMembru("Vlad Pop", "Premium", 800);
    clubArray[0].inserareMembru("Damian Marcel", "Standard", 150);
    clubArray[0].inserareMembru("Teodor Ionut", "Gold", 330);
    clubArray[2].inserareMembru("Vlad Pop", "Standard", 100);
    clubArray[2].inserareMembru("Mircea Ionescu", "Gold", 450);
    clubArray[1].inserareMembru("Vlad Pop", "Standard", 200);
    clubArray[1].inserareMembru("Tudor Ionescu", "Gold", 250);
    clubArray[3].inserareMembru("Vasile Ionescu", "Gold", 350);

    map <string, int> countClubs;

    for (auto& club : clubArray) {
        if (countClubs.find(club.getOras()) == countClubs.end()) {
            countClubs[club.getOras()] = 1;
        } else {
            ++countClubs[club.getOras()];
        }

        cout << club << endl;
    }

    string minOras, maxOras;

    for (auto club : countClubs) {
        if (minOras.length() == 0) {
            minOras = club.first;
        }

        if (minOras.length() == 0) {
            maxOras = club.first;
        }

        if (club.second < countClubs[minOras]) {
            minOras = club.first;
        }

        if (club.second > countClubs[maxOras]) {
            maxOras = club.first;
        }
    }

    cout << "Orasul cu cele mai multe cluburi: " << maxOras << "(" << countClubs[maxOras] << " cluburi)" << endl;
    cout << "Orasul cu cele mai putine cluburi: " << minOras << "(" << countClubs[minOras] << " cluburi)" << endl;


    for (auto& club : clubArray) {
        cout << club;
        cout  << "Medie Cotizatie: " << club.getAverageCotizatie() << endl << endl;
    }

    map <int, string> tipuriMembru = clubArray[0].getTipuri();
    map <string, int> countTipuri;

    for (auto tip : tipuriMembru) {
        countTipuri[tip.second] = 0;
    }

    for (auto& club : clubArray) {
        map<string, Membru> membriClub = club.getMembri();

        for (auto membru : membriClub) {
            ++countTipuri[membru.second.getTip()];
        }
    }

    cout << "Tipuri membri: " << endl;
    for (auto tip : countTipuri) {
        cout << tip.first << ": " << tip.second << endl;
    }

    return 0;
}