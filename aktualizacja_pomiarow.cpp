#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include "generator_pacjentow.hpp"


using namespace std;


void wczytajPacjentow(const string& nazwaPliku, vector<PacjentDane>& pacjenci) 
{
    ifstream plik(nazwaPliku);
    string linia;

    if (!plik) 
    {
        cerr << "Nie można otworzyć pliku do odczytu.\n";
        return;
    }

    while (getline(plik, linia)) 
    {
        istringstream iss(linia);
        PacjentDane p;
        iss >> p.id >> p.pesel >> p.imie >> p.nazwisko >> p.wiek >> p.plec >> p.wzrost >> p.waga
        >> p.cisnienie_skurczowe >> p.cisnienie_rozkurczowe >> p.tetno >> p.utlenienie
        >> p.poziom_cukru >> p.temperatura >> p.stan;
        getline(iss >> ws, p.dolegliwosc); // odczyt do końca linii (pomijanie znaków białych (spacji) przy nazwie choroby)
        pacjenci.push_back(p);
    }
}


void zapiszPacjentow(const string& nazwaPliku, const vector<PacjentDane>& pacjenci) 
{
    ofstream plik(nazwaPliku);

    for (const auto& p : pacjenci) 
    {
        plik << p.id << " " << p.pesel << " " << p.imie << " " << p.nazwisko << " " << p.wiek << " " << p.plec << " "
        << p.wzrost << " " << p.waga << " " << p.cisnienie_skurczowe << " " << p.cisnienie_rozkurczowe << " "
        << p.tetno << " " << p.utlenienie << " " << p.poziom_cukru << " " << p.temperatura << " "
        << p.stan << " " << p.dolegliwosc << '\n';
    }
}

int main() 
{

    srand(time(0));

    vector<PacjentDane> pacjenci;
    const string nazwaPliku = "pacjenci.txt";

    wczytajPacjentow(nazwaPliku, pacjenci);

    for (auto& p : pacjenci) {
        Pomiary npomiary;

        npomiary.set_cS(rand() % 61 + 80);  // 80–140 mmHg
        p.cisnienie_skurczowe = npomiary.get_cS();

        npomiary.set_cR(rand() % 31 + 50);  // 50–80 mmHg
        p.cisnienie_rozkurczowe = npomiary.get_cR();

        npomiary.set_tetno(rand() % 61 + 50); // 50–110 bpm
        p.tetno = npomiary.get_tetno();

        npomiary.set_cukier(rand() % 160 + 40); // 40–200 mg/dL
        p.poziom_cukru = npomiary.get_cukier();

        npomiary.set_utl(p.utlenienie);

        npomiary.set_temp(rand() % 90 + 345); // 34.5–43.5 °C *10
        p.temperatura = npomiary.get_temp();

        npomiary.sprawdzStan(p.wiek);
        p.stan = npomiary.get_stan();
    }

    zapiszPacjentow(nazwaPliku, pacjenci);

    cout << "Zaktualizowano pomiary wszystkich pacjentów.\n";
    return 0;
}
