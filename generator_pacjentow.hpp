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
    int get_stan() const;
    int get_temp() const;

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
    virtual ~Pomiary();     
};

class Pacjent 
{
protected: // zmienne chronione przed dostepem publicznym
    int id, wiek, wzrost, waga;
    std::string imie, nazwisko, plec, pesel, dolegliwosc;
    Pomiary pomiary;

public:
    // metody
    void wylosujWzrost_Wage();
    void wylosujPomiary();
    void zapisz(std::ofstream &plik);

    // konstruktor
    Pacjent(int ID, std::string Pesel, std::string Imie, std::string Nazwisko, int Wiek, std::string Dolegliwosc);

    // wirtualny destruktor
    virtual ~Pacjent();
};


#endif // GENERATOR_PACJENTOW_HPP
