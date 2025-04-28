#include <iostream> // cin i cout
#include <cstdlib> // rand() i srand()
#include <fstream> // działania na plikach
#include <string> // stringi i ich metody np. back()
#include <ctime> // time()

using namespace std;
 
struct Zakres // struktura zakresu stworzona by uprościć działanie na pomiarach
{
    double min;
    double max;
};

class Pomiary 
{
    protected:

    int cisnienie_skurczowe, cisnienie_rozkurczowe, tetno, utlenienie, poziom_cukru, stan; // zmienne chronione przed dostepem publicznym
    double temperatura_ciala;

    public:
    // gettery do pozyskiwania wartości zmiennych
    int get_cS()
    {
        return cisnienie_skurczowe;
    }

    int get_cR()
    {
        return cisnienie_rozkurczowe;
    }

    int get_tetno()
    {
        return tetno;
    }

    int get_utl()
    {
        return utlenienie;
    }

    int get_cukier() 
    {
        return poziom_cukru;
    }

    int get_stan()
    {
        return stan;
    }

    double get_temp()
    {
        return temperatura_ciala;
    }

    // settery do ustalania wartości zmiennych
    void set_cS(int wartosc)
    {
        cisnienie_skurczowe = wartosc;
    }

    void set_cR(int wartosc)
    {
        cisnienie_rozkurczowe = wartosc;
    }

    void set_tetno(int wartosc)
    {
        tetno = wartosc;
    }

    void set_utl(int wartosc)
    {
        utlenienie = wartosc;
    }

    void set_cukier(int wartosc) 
    {
        poziom_cukru = wartosc;
    }

    void set_temp(double wartosc)
    {
        temperatura_ciala = wartosc;
    }


    int ocenaStanu(double roznica) { // ocenia stan na podstawie wielkości różnicy
        if (roznica < 10) return 1;
        else if (roznica <= 20) return 2;
        else if (roznica <= 30) return 3;
        else if (roznica <= 40) return 4;
        else return 5;          
    }
    
    void sprawdzStan(int wiek)
    {
        Zakres zakres_cS, zakres_cR, zakres_tetno, zakres_utl, zakres_cukier, zakres_temp; // zakresy zmiennych
        double roznica_cS = 0, roznica_cR = 0, roznica_tetno = 0, roznica_utl = 0, roznica_cukier = 0, roznica_temp = 0; // roznice zmiennych

        if (wiek < 1) { // niemowlę
            zakres_cS = {60, 90}; zakres_cR = {30, 60}; zakres_tetno = {100, 160};
            zakres_utl = {90, 100}; zakres_temp = {36.0, 37.5}; zakres_cukier = {60, 100};
        } else if (wiek < 12) { // dziecko
            zakres_cS = {90, 110}; zakres_cR = {55, 75}; zakres_tetno = {75, 120};
            zakres_utl = {92, 100}; zakres_temp = {36.0, 38.0}; zakres_cukier = {70, 110};
        } else if (wiek < 18) { // nastolatek
            zakres_cS = {100, 120}; zakres_cR = {65, 80}; zakres_tetno = {60, 100};
            zakres_utl = {94, 100}; zakres_temp = {36.0, 38.0}; zakres_cukier = {70, 110};
        } else if (wiek < 65) { // dorosły
            zakres_cS = {110, 130}; zakres_cR = {70, 85}; zakres_tetno = {60, 100};
            zakres_utl = {95, 100}; zakres_temp = {35.5, 38.5}; zakres_cukier = {70, 125};
        } else { // senior
            zakres_cS = {110, 140}; zakres_cR = {70, 90}; zakres_tetno = {60, 100};
            zakres_utl = {93, 100}; zakres_temp = {35.5, 38.0}; zakres_cukier = {70, 140};
        }

        // Różnica ciśnienia skurczowego
        if (cisnienie_skurczowe < zakres_cS.min)
        {
            roznica_cS = zakres_cS.min - cisnienie_skurczowe;
        } else if (cisnienie_skurczowe > zakres_cS.max)
        {
            roznica_cS = cisnienie_skurczowe - zakres_cS.max;
        }

        // Różnica ciśnienia rozkurczowego
        if (cisnienie_rozkurczowe < zakres_cR.min)
        {
            roznica_cR = zakres_cR.min - cisnienie_rozkurczowe;
        } else if (cisnienie_rozkurczowe > zakres_cR.max)
        {
            roznica_cR = cisnienie_rozkurczowe - zakres_cR.max;
        }
        
        // Różnica tętna
        if (tetno < zakres_tetno.min)
        {
            roznica_tetno = zakres_tetno.min - tetno;
        } else if (tetno > zakres_tetno.max)
        {
            roznica_tetno = tetno - zakres_tetno.max;
        }

        // Różnica utlenienia
        if (utlenienie < zakres_utl.min)
        {
            roznica_utl = zakres_utl.min - utlenienie;
        } else if (utlenienie > zakres_utl.max)
        {
            roznica_utl = utlenienie - zakres_utl.max;
        }

        // Różnica poziom cukru
        if (poziom_cukru < zakres_cukier.min)
        {
            roznica_cukier = zakres_cukier.min - poziom_cukru;
        } else if (poziom_cukru > zakres_cukier.max)
        {
            roznica_cukier = poziom_cukru - zakres_cukier.max;
        }

        // Różnica temperatury
        if (temperatura_ciala < zakres_temp.min)
        {
            roznica_temp = zakres_temp.min - temperatura_ciala;
        } else if (temperatura_ciala > zakres_temp.max)
        {
            roznica_temp = temperatura_ciala - zakres_temp.max;
        }

        // ustala ocene stanu dla każdej zmiennej
        int stan_cS = ocenaStanu(roznica_cS);
        int stan_cR = ocenaStanu(roznica_cR);
        int stan_tetno = ocenaStanu(roznica_tetno);
        int stan_utl = ocenaStanu(roznica_utl);
        int stan_cukier = ocenaStanu(roznica_cukier);
        int stan_temp = ocenaStanu(roznica_temp);

        stan = 1;
        if (stan_cS > stan) stan = stan_cS;
        if (stan_cR > stan) stan = stan_cR;
        if (stan_tetno > stan) stan = stan_tetno;
        if (stan_utl > stan) stan = stan_utl;
        if (stan_cukier > stan) stan = stan_cukier;
        if (stan_temp > stan) stan = stan_temp;
    }

    Pomiary() // konstruktor pomiarow
    {
        cisnienie_skurczowe = 0;
        cisnienie_rozkurczowe = 0;
        tetno = 0;
        utlenienie = 0;
        poziom_cukru = 0;
        temperatura_ciala = 0.0;
        stan = 1;
    };
    
    ~Pomiary() {} // destuktor pomiarow

};

class Pacjent 
{
    protected: // zmienne chronione przed dostepem publicznym
    int id, wiek, wzrost, waga;
    string imie, nazwisko, plec, pesel, dolegliwosc;
    Pomiary pomiary;

    public:

    void wylosujWzrost_Wage() // losuje wagę i wzrost dla pacjenta w jednej funkcji;
    {
        if (wiek < 1)
        {
            wzrost = rand() % 30 + 50;
            waga = rand() % 7 + 3;
        } else if (wiek < 5)
        {
            wzrost = rand() % 30 + 70;
            waga = rand() % 10 + 12;
        } else if (wiek < 12)
        {
            wzrost = rand() % 60 + 80;

            waga = rand() % 21 + 20;
        } else if (wiek < 18)
        {
            wzrost = rand() % 50 + 130;
            waga = rand() % 32 + 40;
        } else if (wiek < 65)
        {
            wzrost = rand() % 50 + 155;
            waga = rand() % 42 + 60;
        } else 
        {
            wzrost = rand() % 30 + 150;
            waga = rand() % 32 + 55;
        }
    }

    void wylosujPomiary() 
    {
        pomiary.set_cS(rand() % 61 + 80); // ustala losowe wartości pomiarów i przypisuje je do zmiennych
        pomiary.set_cR(rand() % 31 + 50);
        pomiary.set_tetno(rand() % 61 + 50);
        pomiary.set_utl(rand() % 11 + 90);
        pomiary.set_cukier(rand() % 160 + 40);
        pomiary.set_temp((rand() % 80 / 10) + 35.5);
        pomiary.sprawdzStan(wiek); // sprawdza stan na podstawie wieku pacjenta
    }

    void zapisz(ofstream &plik) {
        // plik << "ID PESEL Imię Nazwisko Wiek Płeć Wzrost Waga"
        //     << "Ciśnienie_skurczowe Ciśnienie_rozkurczowe Tętno "
        //     << "Utlenienie Poziom_Cukru Temperatura Stan Dolegliwość\n";
        plik << id << " " << pesel << " " << imie << " " << nazwisko << " "
            << wiek << " " << plec << " " << wzrost << " " << waga << " "
            << pomiary.get_cS() << " " << pomiary.get_cR() << " "
            << pomiary.get_tetno() << " " << pomiary.get_utl() << " " << pomiary.get_cukier() << " "
            << pomiary.get_temp() << " " << pomiary.get_stan() << " " << dolegliwosc << "\n";
    }

    Pacjent (int ID, string Pesel, string Imie, string Nazwisko, int Wiek, string dolegliwosc) // konstruktor do pacjenta
    : id(ID), pesel(Pesel), imie(Imie), nazwisko(Nazwisko), wiek(Wiek), dolegliwosc(dolegliwosc) // lista inicjalizacyjna
    { // instukcje wykonywane przez konstruktor
        plec = (imie.back() == 'a') ? "Kobieta" : "Mężczyzna"; // sprawdza plec po ostatniej cyfrze imienia
        wylosujWzrost_Wage(); // losuje wzrost i wagę
        wylosujPomiary(); // losuje wyniki pomiarów
    }

    ~Pacjent() {} // destruktor pacjenta
};


string wygenerujPesel() // funkcja do generowania numeru pesel
{
    string pesel = "";
    int cyfra;
    for (int i=0; i < 11; i++)
    {
        cyfra = rand() % 10;
        pesel += to_string(cyfra); // to_string zamienia cyfrę na stringa
    }
    return pesel;
}

int main()
{
    srand(time(0)); // zapewnia całkowita losowość wyników

    int liczba_pacjentow = rand() % 5 + 2;

    string imiona[100] =
    {
        "Anna", "Maria", "Katarzyna", "Magdalena", "Agnieszka",
        "Joanna", "Barbara", "Ewa", "Krystyna", "Elżbieta",
        "Zofia", "Teresa", "Halina", "Irena", "Jadwiga",
        "Danuta", "Grażyna", "Beata", "Urszula", "Małgorzata",
        "Natalia", "Patrycja", "Karolina", "Sylwia", "Paulina",
        "Dorota", "Martyna", "Alicja", "Justyna", "Weronika",
        "Milena", "Izabela", "Renata", "Gabriela", "Julia",
        "Emilia", "Olga", "Lucyna", "Aneta", "Wioletta",
        "Jan", "Andrzej", "Piotr", "Krzysztof", "Stanisław",
        "Tomasz", "Paweł", "Józef", "Marcin", "Marek",
        "Michał", "Grzegorz", "Jerzy", "Tadeusz", "Adam",
        "Zbigniew", "Ryszard", "Dariusz", "Wojciech", "Henryk",
        "Roman", "Kazimierz", "Edward", "Robert", "Sebastian",
        "Mateusz", "Antoni", "Julian", "Ignacy", "Oskar",
        "Bartosz", "Łukasz", "Hubert", "Karol", "Kamil",
        "Przemysław", "Daniel", "Konrad", "Szymon", "Damian",
        "Cezary", "Filip", "Maciej", "Mariusz", "Arkadiusz",
        "Patryk", "Rafał", "Norbert", "Tymoteusz", "Waldemar",
        "Lech", "Bogdan", "Borys", "Witold", "Albert"
    };

    string nazwiska[100] =
    {
        "Kowalski", "Nowak", "Wiśniewski", "Wójcik", "Kowalczyk",
        "Kamiński", "Lewandowski", "Zieliński", "Szymański", "Woźniak",
        "Dąbrowski", "Kozłowski", "Jankowski", "Mazur", "Wojciechowski",
        "Kwiatkowski", "Kaczmarek", "Piotrowski", "Grabowski", "Zając",
        "Król", "Wieczorek", "Jabłoński", "Wróbel", "Pawłowski",
        "Michalski", "Nowicki", "Adamczyk", "Dudek", "Sikora",
        "Walczak", "Baran", "Rutkowski", "Szewczyk", "Olszewski",
        "Bąk", "Szymańska", "Lis", "Makowski", "Chmielewski",
        "Szulc", "Brzeziński", "Czarnecki", "Sawicki", "Sokołowski",
        "Urbański", "Kubiak", "Kucharski", "Tomczak", "Jaworski",
        "Malinowski", "Piekarski", "Głowacki", "Czerwiński", "Sikorski",
        "Włodarczyk", "Marciniak", "Jastrzębski", "Zarzycki", "Rogowski",
        "Maj", "Sobczak", "Tomaszewski", "Cieślak", "Kubicki",
        "Kołodziej", "Milewski", "Szczepański", "Leszczyński", "Borowski",
        "Borkowski", "Majewski", "Urban", "Pawlak", "Kopeć",
        "Mróz", "Orłowski", "Musiał", "Wrona", "Brodziński",
        "Zawadzki", "Stefański", "Andrzejewski", "Błaszczyk", "Strzelczyk",
        "Marcinkowski", "Chojnacki", "Słowik", "Drozd", "Wilk",
        "Bednarek", "Białek", "Michalik", "Gajda", "Jóźwiak"
    };

    string dolegliwosci[50] =
    {
        "Grypa", "Angina", "Zapalenie płuc", "COVID-19", "Astma",
        "Cukrzyca", "Choroba wieńcowa", "Zawał serca", "Nadciśnienie", "Nowotwór",
        "Złamanie ręki", "Złamanie nogi", "Złamanie biodra", "Rana cięta", "Rana szarpana",
        "Oparzenie", "Odleżyny", "Reumatoidalne zapalenie stawów", "Osteoporoza", "Skolioza",
        "Zapalenie ucha", "Zatrucie pokarmowe", "Kamica nerkowa", "Wrzody żołądka", "Alzheimer",
        "Parkinson", "Migrena", "Depresja", "Nerwica", "Bezsenność",
        "Padaczka", "Choroba Crohna", "Hemoroidy", "Reumatyzm", "Stwardnienie rozsiane",
        "Zespół Downa", "Autyzm", "Biegunka", "Zaparcia", "Zapalenie gardła",
        "Angina ropna", "Ospa", "Różyczka", "Świnka", "Zapalenie spojówek",
        "Zawał mózgu", "Gruźlica", "Zapalenie oskrzeli", "Zatrucie chemiczne", "Wstrząśnienie mózgu"
    };


    ofstream plik("pacjenci.txt");
    if(!plik)
    {
        cerr << "Nie ma takiego pliku!\n";
        return 1;
    }

    for (int i = 1; i <= liczba_pacjentow; i++)
    {
        string pesel = wygenerujPesel();
        int wiek = rand() % 121;
        string imie = imiona[rand() % 100];
        string nazwisko = nazwiska[rand() % 100];
        string dolegliwosc = dolegliwosci[rand() % 50];

        Pacjent pacjent(i, pesel, imie, nazwisko, wiek, dolegliwosc);

        pacjent.zapisz(plik);
    }
    
    plik.close();
    cout << "Zapisano dane pacjentów do pliku pacjenci.txt\n";
    return 0;
}