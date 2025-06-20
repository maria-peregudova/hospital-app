#ifndef GENERATOR_PACJENTOW_HPP
#define GENERATOR_PACJENTOW_HPP

#include <iostream> // cin i cout
#include <cstdlib> // rand() i srand()
#include <fstream> // działania na plikach
#include <string> // stringi i ich metody np. back()
#include <ctime> // time()

struct Zakres // struktura zakresu do wykorzystywania w obliczaniu pomiarów 
{
    double min;
    double max;
};

class Pomiary 
{
protected: // zmienne chronione przed dostepem publicznym
    int cisnienie_skurczowe, cisnienie_rozkurczowe, tetno, utlenienie, poziom_cukru, stan, temperatura_ciala;

public:
    // Gettery - const bo są stałe
    int get_cS() const;
    int get_cR() const;
    int get_tetno() const;
    int get_utl() const;
    int get_cukier() const;
    int get_temp() const;
    int get_stan() const;

    // Settery
    void set_cS(int wartosc);
    void set_cR(int wartosc);
    void set_tetno(int wartosc);
    void set_utl(int wartosc);
    void set_cukier(int wartosc);
    void set_temp(int wartosc);

    // Metody sprawdzania stanu
    int ocenaStanu(double roznica);
    void sprawdzStan(int wiek);

    // konstruktor domyslny pomiarow  
    Pomiary();

    // wirtualny destruktor
    virtual ~Pomiary(){};     
};

class Pacjent 
{
protected: // zmienne chronione przed dostepem publicznym
    int id, wiek, wzrost, waga;
    std::string imie, nazwisko, plec, pesel, dolegliwosc, lekarz;
    Pomiary pomiary;

public:

//getery
int get_id(){return id;}
int get_wiek(){return wiek;}
int get_wzrost(){return wzrost;}
int get_waga(){return waga;}
string get_imie(){return imie;}
string get_nazwisko(){return nazwisko;}
string get_plec(){return plec;}
string get_pesel(){return pesel;}
string get_dolegliwosc(){return dolegliwosc;}
string get_lekarz(){return lekarz;}

//setery
void set_id(int wartosc){id = wartosc};
void set_wiek(int wartosc){wiek = wartosc};
void set_wzrost(int wartosc){wzrost = wartosc};
void set_waga(int wartosc){waga = wartosc};
void set_imie(int wartosc){imie = wartosc};
void set_nazwisko(int wartosc){nazwisko = wartosc};
void set_plec(int wartosc){plec = wartosc};
void set_pesel(int wartosc){pesel = wartosc};
void set_dolegliwosc(int wartosc){dolegliwosc = wartosc};
void set_lekarz(int wartosc){lekarz = wartosc};

    // metody
    void wylosujWzrost_Wage();
    void wylosujPomiary();
    void zapisz(std::ofstream &plik);
    // konstruktor
    Pacjent(int ID, std::string Pesel, std::string Imie, std::string Nazwisko, int Wiek, std::string Dolegliwosc. std::string Lekarz);

    // wirtualny destruktor
    virtual ~Pacjent(){};
};

struct PacjentDane // struktura danych pacjenta
{
    int id, wiek, wzrost, waga, cisnienie_skurczowe, cisnienie_rozkurczowe, tetno, utlenienie, poziom_cukru, temperatura, stan;
    std::string pesel, imie, nazwisko, plec, dolegliwosc;
};

std::string wygenerujPesel();

void wczytajPacjentow();

void zapiszPacjentow();

#endif // GENERATOR_PACJENTOW_HPP
