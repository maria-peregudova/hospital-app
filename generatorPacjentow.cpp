#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

struct Zakres {
    double min;
    double max;
};

class Pomiary 
{
    public:

    int cisnienie_skurczowe, cisnienie_rozkurczowe, tetno, utlenienie, poziom_cukru, stan;
    double temperatura_ciala;

    int ocenaStanu(double roznica) {
        if (roznica < 10) return 1;
        else if (roznica <= 20) return 2;
        else if (roznica <= 30) return 3;
        else if (roznica <= 40) return 4;
        else return 5;          
    }
    
    void sprawdzStan(int wiek)
    {
        Zakres z_cS, z_cR, z_tetno, z_utl, z_cukier, z_temp;
        double rozn_cS = 0, rozn_cR = 0, rozn_tetno = 0, rozn_utl = 0, rozn_cukier = 0, rozn_temp = 0;

        if (wiek < 1) { // niemowlę
            z_cS = {60, 90}; z_cR = {30, 60}; z_tetno = {100, 160};
            z_utl = {90, 100}; z_temp = {36.0, 37.5}; z_cukier = {60, 100};
        } else if (wiek < 12) { // dziecko
            z_cS = {90, 110}; z_cR = {55, 75}; z_tetno = {75, 120};
            z_utl = {92, 100}; z_temp = {36.0, 38.0}; z_cukier = {70, 110};
        } else if (wiek < 18) { // nastolatek
            z_cS = {100, 120}; z_cR = {65, 80}; z_tetno = {60, 100};
            z_utl = {94, 100}; z_temp = {36.0, 38.0}; z_cukier = {70, 110};
        } else if (wiek < 65) { // dorosły
            z_cS = {110, 130}; z_cR = {70, 85}; z_tetno = {60, 100};
            z_utl = {95, 100}; z_temp = {35.5, 38.5}; z_cukier = {70, 125};
        } else { // senior
            z_cS = {110, 140}; z_cR = {70, 90}; z_tetno = {60, 100};
            z_utl = {93, 100}; z_temp = {35.5, 38.0}; z_cukier = {70, 140};
        }

        // Różnica ciśnienia skurczowego
        if (cisnienie_skurczowe < z_cS.min)
        {
            rozn_cS = z_cS.min - cisnienie_skurczowe;
        } else if (cisnienie_skurczowe > z_cS.max)
        {
            rozn_cS = cisnienie_skurczowe - z_cS.max;
        }

        // Różnica ciśnienia rozkurczowego
        if (cisnienie_rozkurczowe < z_cR.min)
        {
            rozn_cR = z_cR.min - cisnienie_rozkurczowe;
        } else if (cisnienie_rozkurczowe > z_cR.max)
        {
            rozn_cR = cisnienie_rozkurczowe - z_cR.max;
        }
        
        // Różnica tętna
        if (tetno < z_tetno.min)
        {
            rozn_tetno = z_tetno.min - tetno;
        } else if (tetno > z_tetno.max)
        {
            rozn_tetno = tetno - z_tetno.max;
        }

        // Różnica utlenienia
        if (utlenienie < z_utl.min)
        {
            rozn_utl = z_utl.min - utlenienie;
        } else if (utlenienie > z_utl.max)
        {
            rozn_utl = utlenienie - z_utl.max;
        }

        // Różnica poziom cukru
        if (poziom_cukru < z_cukier.min)
        {
            rozn_utl = z_cukier.min - poziom_cukru;
        } else if (poziom_cukru > z_cukier.max)
        {
            rozn_utl = poziom_cukru - z_cukier.max;
        }

        // Różnica temperatury
        if (temperatura_ciala < z_temp.min)
        {
            rozn_temp = z_temp.min - temperatura_ciala;
        } else if (temperatura_ciala > z_temp.max)
        {
            rozn_temp = temperatura_ciala - z_temp.max;
        }

        int stan_cS = ocenaStanu(rozn_cS);
        int stan_cR = ocenaStanu(rozn_cR);
        int stan_tetno = ocenaStanu(rozn_tetno);
        int stan_utl = ocenaStanu(rozn_utl);
        int stan_cukier = ocenaStanu(rozn_cukier);
        int stan_temp = ocenaStanu(rozn_temp);

        stan = 1;
        if (stan_cS > stan) stan = stan_cS;
        if (stan_cR > stan) stan = stan_cR;
        if (stan_tetno > stan) stan = stan_tetno;
        if (stan_utl > stan) stan = stan_utl;
        if (stan_cukier > stan) stan = stan_cukier;
        if (stan_temp > stan) stan = stan_temp;
    }

    Pomiary() 
    {
        cisnienie_skurczowe = 0;
        cisnienie_rozkurczowe = 0;
        tetno = 0;
        utlenienie = 0;
        poziom_cukru = 0;
        temperatura_ciala = 0.0;
        stan = 1;
    };
    
    ~Pomiary() {}

};

class Pacjent 
{
    public:
    int id, wiek, wzrost, waga;
    string imie, nazwisko, plec, pesel, dolegliwosc;
    Pomiary pomiary;

    void wylosujWzrost_Wage()
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
        pomiary.cisnienie_skurczowe = rand() % 61 + 80;
        pomiary.cisnienie_rozkurczowe = rand() % 31 + 50;
        pomiary.tetno = rand() % 61 + 50;
        pomiary.utlenienie = rand() % 11 + 90;
        pomiary.poziom_cukru = rand() % 160 + 40;
        pomiary.temperatura_ciala =  (rand() % 80 / 10) + 35.5;
        pomiary.sprawdzStan(wiek);
    }

    void zapisz(ofstream &plik) {
        // plik << "ID PESEL Imię Nazwisko Wiek Płeć Wzrost Waga"
        //     << "Ciśnienie_skurczowe Ciśnienie_rozkurczowe Tętno "
        //     << "Utlenienie Temperatura Poziom_Cukru Stan Doległość\n";
        plik << id << " " << pesel << " " << imie << " " << nazwisko << " "
            << wiek << " " << plec << " " << wzrost << " " << waga << " "
            << pomiary.cisnienie_skurczowe << " " << pomiary.cisnienie_rozkurczowe << " "
            << pomiary.tetno << " " << pomiary.utlenienie << " " << pomiary.temperatura_ciala << " "
            << pomiary.poziom_cukru << " " << pomiary.stan << " " << dolegliwosc << "\n";
    }

    Pacjent (int ID, string Pesel, string Imie, string Nazwisko, int Wiek, string dolegliwosc)
    : id(ID), pesel(Pesel), imie(Imie), nazwisko(Nazwisko), wiek(Wiek), dolegliwosc(dolegliwosc)
    {
        plec = (imie.back() == 'a') ? "Kobieta" : "Mężczyzna";
        wylosujWzrost_Wage();
        wylosujPomiary();
    }

    ~Pacjent() {}
};


string wygenerujPesel()
{
    string pesel = "";
    int cyfra;
    for (int i=0; i < 11; i++)
    {
        cyfra = rand() % 10;
        pesel += to_string(cyfra);
    }
    return pesel;
}

int main()
{
    srand(time(0));

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