#include <iostream> // cin i cout
#include <cstdlib> // rand() i srand()
#include <fstream> // działania na plikach
#include <string> // stringi i ich metody np. back()
#include <ctime> // time()
#include "generator_pacjentow.hpp"

using namespace std;

// gettery
int Pomiary::get_cS() const {
    return cisnienie_skurczowe;
}

int Pomiary::get_cR() const {
    return cisnienie_rozkurczowe;
}

int Pomiary::get_tetno() const {
    return tetno;
}

int Pomiary::get_utl() const {
    return utlenienie;
}

int Pomiary::get_cukier() const {
    return poziom_cukru;
}

int Pomiary::get_temp() const {
    return temperatura_ciala;
}

int Pomiary::get_stan() const {
    return stan;
}



// settery
void Pomiary::set_cS(int wartosc) {
    cisnienie_skurczowe = wartosc;
}

void Pomiary::set_cR(int wartosc) {
    cisnienie_rozkurczowe = wartosc;
}

void Pomiary::set_tetno(int wartosc) {
    tetno = wartosc;
}

void Pomiary::set_utl(int wartosc) {
    utlenienie = wartosc;
}

void Pomiary::set_cukier(int wartosc) {
    poziom_cukru = wartosc;
}

void Pomiary::set_temp(int wartosc) {
    temperatura_ciala = wartosc;
}

// metoda oceniająca stan na podstawie różnicy
int Pomiary::ocenaStanu(double roznica) {
    if (roznica < 10) return 1;
    else if (roznica <= 20) return 2;
    else if (roznica <= 30) return 3;
    else if (roznica <= 40) return 4;
    else return 5;          
}

// metoda sprawdzająca stan pacjenta w zależności od wieku
void Pomiary::sprawdzStan(int wiek) {
    Zakres zakres_cS, zakres_cR, zakres_tetno, zakres_utl, zakres_cukier, zakres_temp;
    double roznica_cS = 0, roznica_cR = 0, roznica_tetno = 0, roznica_utl = 0, roznica_cukier = 0, roznica_temp = 0;

    // ustalenie zakresów dla różnych grup wiekowych
    if (wiek < 1) { // niemowlę
        zakres_cS = {60, 90}; zakres_cR = {30, 60}; zakres_tetno = {100, 160};
        zakres_utl = {90, 100}; zakres_temp = {360, 375}; zakres_cukier = {60, 100};
    } else if (wiek < 12) { // dziecko
        zakres_cS = {90, 110}; zakres_cR = {55, 75}; zakres_tetno = {75, 120};
        zakres_utl = {92, 100}; zakres_temp = {360, 380}; zakres_cukier = {70, 110};
    } else if (wiek < 18) { // nastolatek
        zakres_cS = {100, 120}; zakres_cR = {65, 80}; zakres_tetno = {60, 100};
        zakres_utl = {94, 100}; zakres_temp = {360, 380}; zakres_cukier = {70, 110};
    } else if (wiek < 65) { // dorosły
        zakres_cS = {110, 130}; zakres_cR = {70, 85}; zakres_tetno = {60, 100};
        zakres_utl = {95, 100}; zakres_temp = {355, 385}; zakres_cukier = {70, 125};
    } else { // senior
        zakres_cS = {110, 140}; zakres_cR = {70, 90}; zakres_tetno = {60, 100};
        zakres_utl = {93, 100}; zakres_temp = {355, 380}; zakres_cukier = {70, 140};
    }

    // obliczanie odchyleń od normy dla każdego parametru
    if (cisnienie_skurczowe < zakres_cS.min) roznica_cS = zakres_cS.min - cisnienie_skurczowe;
    else if (cisnienie_skurczowe > zakres_cS.max) roznica_cS = cisnienie_skurczowe - zakres_cS.max;

    if (cisnienie_rozkurczowe < zakres_cR.min) roznica_cR = zakres_cR.min - cisnienie_rozkurczowe;
    else if (cisnienie_rozkurczowe > zakres_cR.max) roznica_cR = cisnienie_rozkurczowe - zakres_cR.max;

    if (tetno < zakres_tetno.min) roznica_tetno = zakres_tetno.min - tetno;
    else if (tetno > zakres_tetno.max) roznica_tetno = tetno - zakres_tetno.max;

    if (utlenienie < zakres_utl.min) roznica_utl = zakres_utl.min - utlenienie;
    else if (utlenienie > zakres_utl.max) roznica_utl = utlenienie - zakres_utl.max;

    if (poziom_cukru < zakres_cukier.min) roznica_cukier = zakres_cukier.min - poziom_cukru;
    else if (poziom_cukru > zakres_cukier.max) roznica_cukier = poziom_cukru - zakres_cukier.max;

    if (temperatura_ciala < zakres_temp.min) roznica_temp = zakres_temp.min - temperatura_ciala;
    else if (temperatura_ciala > zakres_temp.max) roznica_temp = temperatura_ciala - zakres_temp.max;

    // ocena stanu
    stan = 1;
    if (ocenaStanu(roznica_cS) > stan) stan = ocenaStanu(roznica_cS);
    if (ocenaStanu(roznica_cR) > stan) stan = ocenaStanu(roznica_cR);
    if (ocenaStanu(roznica_tetno) > stan) stan = ocenaStanu(roznica_tetno);
    if (ocenaStanu(roznica_utl) > stan) stan = ocenaStanu(roznica_utl);
    if (ocenaStanu(roznica_cukier) > stan) stan = ocenaStanu(roznica_cukier);
    if (ocenaStanu(roznica_temp) > stan) stan = ocenaStanu(roznica_temp);
}

// konstruktor pomiary
Pomiary::Pomiary() 
{
    cisnienie_skurczowe = 0;
    cisnienie_rozkurczowe = 0;
    tetno = 0;
    utlenienie = 0;
    poziom_cukru = 0;
    temperatura_ciala = 0;
    stan = 1;
};

//Gettery Pacjent
string Pacjent::get_imie() const {
    return imie;
}
string Pacjent::get_nazwisko() const {
    return nazwisko;
}
int Pacjent::get_stan() const {
    return pomiary.get_stan();
}
int Pacjent::get_pokoj() const {
    return pokoj;
}
string Pacjent::get_lekarz() const {
    return lekarz;
}

// Setter Pacjent
void Pacjent::set_pacjent(int Id, std::string Pesel, std::string Imie, std::string Nazwisko, int Wiek,
std::string Plec, int Wzrost, int Waga, int Cisk, int Ciroz, int Tetno, int Utlenienie, int Cukier, int Temperatura, int Stan, std::string Dolegliwosc, int Pokoj, std::string Lekarz_nazwisko)
{
    id = Id;
    pesel = Pesel;
    imie = Imie;
    nazwisko = Nazwisko;
    wiek = Wiek;
    plec = Plec;
    wzrost = Wzrost;
    waga = Waga;
    dolegliwosc = Dolegliwosc;

    pomiary.set_cS(Cisk);
    pomiary.set_cR(Ciroz);
    pomiary.set_tetno(Tetno);
    pomiary.set_utl(Utlenienie);
    pomiary.set_cukier(Cukier);
    pomiary.set_temp(Temperatura);
    pomiary.sprawdzStan(Wiek);

    if(id%2 == 0){pokoj = 1;}
    else{pokoj = 2;}
    if(id%3 == 0){lekarz = "Kowalski";}
    else if(id%3 == 1){lekarz = "Lewandowski";}
    else{lekarz = "Wodecki";}
};

// metoda losująca wzrost i wagę pacjenta
void Pacjent::wylosujWzrost_Wage() {
    if (wiek < 1) {
        wzrost = rand() % 30 + 50;   // 50-80 cm
        waga = rand() % 7 + 3;      // 3-10 kg
    } else if (wiek < 5) {
        wzrost = rand() % 30 + 70;  // 70-100 cm
        waga = rand() % 10 + 12;    // 12-22 kg
    } else if (wiek < 12) {
        wzrost = rand() % 60 + 80;  // 80-140 cm
        waga = rand() % 21 + 20;    // 20-41 kg
    } else if (wiek < 18) {
        wzrost = rand() % 50 + 130; // 130-180 cm
        waga = rand() % 32 + 40;    // 40-72 kg
    } else if (wiek < 65) {
        wzrost = rand() % 50 + 155; // 155-205 cm
        waga = rand() % 42 + 60;    // 60-102 kg
    } else {
        wzrost = rand() % 30 + 150; // 150-180 cm
        waga = rand() % 32 + 55;    // 55-87 kg
    }
}

// metoda losująca pomiary
void Pacjent::wylosujPomiary() 
{
    pomiary.set_cS(rand() % 61 + 80);      // 80-140 mmHg
    pomiary.set_cR(rand() % 31 + 50);      // 50-80 mmHg
    pomiary.set_tetno(rand() % 61 + 50);   // 50-110 uderzeń/min
    pomiary.set_utl(rand() % 11 + 90);     // 90-100% procent utlenienia
    pomiary.set_cukier(rand() % 160 + 40); // 40-200 mg/dL
    pomiary.set_temp(rand() % 90 + 345);   // 34.5-43.5°C (pomnożone razy 10)
    pomiary.sprawdzStan(wiek);
}

void Pacjent::zapisz(ofstream &plik) 
{
    // plik << "ID PESEL Imię Nazwisko Wiek Płeć Wzrost Waga"
    //     << "Ciśnienie_skurczowe Ciśnienie_rozkurczowe Tętno "
    //     << "Utlenienie Poziom_Cukru Temperatura Stan Dolegliwość\n";
    plik << id << " " << pesel << " " << imie << " " << nazwisko << " "
        << wiek << " " << plec << " " << wzrost << " " << waga << " "
        << pomiary.get_cS() << " " << pomiary.get_cR() << " "
        << pomiary.get_tetno() << " " << pomiary.get_utl() << " " << pomiary.get_cukier() << " "
        << pomiary.get_temp() << " " << pomiary.get_stan() << " " << dolegliwosc << "\n";
}


// konstruktor klasy Pacjent
Pacjent::Pacjent(int ID, std::string Pesel, std::string Imie, std::string Nazwisko, int Wiek, std::string Dolegliwosc): id(ID), pesel(Pesel), imie(Imie), nazwisko(Nazwisko), wiek(Wiek), dolegliwosc(Dolegliwosc) 
{
    plec = (imie.back() == 'a') ? "Kobieta" : "Mężczyzna"; // określa płeć na podstawie imienia
    wylosujWzrost_Wage();
    wylosujPomiary();
}

// funkcja generująca Pesel
string wygenerujPesel() 
{
    string pesel = "";
    for (int i = 0; i < 11; i++) {
        int cyfra = rand() % 10;
        pesel += to_string(cyfra);
    }
    return pesel;
}

// int main()
// {
//     srand(time(0)); // zapewnia całkowita losowość wyników

//     int liczba_pacjentow = rand() % 5 + 2; // losowanie ilości pacjentów

//     string imiona[100] =
//     {
//         //Imiona kobiet kończą się literą 'a'
//         "Anna", "Maria", "Katarzyna", "Magdalena", "Agnieszka",
//         "Joanna", "Barbara", "Ewa", "Krystyna", "Elżbieta",
//         "Zofia", "Teresa", "Halina", "Irena", "Jadwiga",
//         "Danuta", "Grażyna", "Beata", "Urszula", "Małgorzata",
//         "Natalia", "Patrycja", "Karolina", "Sylwia", "Paulina",
//         "Dorota", "Martyna", "Alicja", "Justyna", "Weronika",
//         "Milena", "Izabela", "Renata", "Gabriela", "Julia",
//         "Emilia", "Olga", "Lucyna", "Aneta", "Wioletta",
//         "Jan", "Andrzej", "Piotr", "Krzysztof", "Stanisław",
//         "Tomasz", "Paweł", "Józef", "Marcin", "Marek",
//         "Michał", "Grzegorz", "Jerzy", "Tadeusz", "Adam",
//         "Zbigniew", "Ryszard", "Dariusz", "Wojciech", "Henryk",
//         "Roman", "Kazimierz", "Edward", "Robert", "Sebastian",
//         "Mateusz", "Antoni", "Julian", "Ignacy", "Oskar",
//         "Bartosz", "Łukasz", "Hubert", "Karol", "Kamil",
//         "Przemysław", "Daniel", "Konrad", "Szymon", "Damian",
//         "Cezary", "Filip", "Maciej", "Mariusz", "Arkadiusz",
//         "Patryk", "Rafał", "Norbert", "Tymoteusz", "Waldemar",
//         "Lech", "Bogdan", "Borys", "Witold", "Albert"
//     };

//     string nazwiska[100] =
//     {
//         "Kowalski", "Nowak", "Wiśniewski", "Wójcik", "Kowalczyk",
//         "Kamiński", "Lewandowski", "Zieliński", "Szymański", "Woźniak",
//         "Dąbrowski", "Kozłowski", "Jankowski", "Mazur", "Wojciechowski",
//         "Kwiatkowski", "Kaczmarek", "Piotrowski", "Grabowski", "Zając",
//         "Król", "Wieczorek", "Jabłoński", "Wróbel", "Pawłowski",
//         "Michalski", "Nowicki", "Adamczyk", "Dudek", "Sikora",
//         "Walczak", "Baran", "Rutkowski", "Szewczyk", "Olszewski",
//         "Bąk", "Szymańska", "Lis", "Makowski", "Chmielewski",
//         "Szulc", "Brzeziński", "Czarnecki", "Sawicki", "Sokołowski",
//         "Urbański", "Kubiak", "Kucharski", "Tomczak", "Jaworski",
//         "Malinowski", "Piekarski", "Głowacki", "Czerwiński", "Sikorski",
//         "Włodarczyk", "Marciniak", "Jastrzębski", "Zarzycki", "Rogowski",
//         "Maj", "Sobczak", "Tomaszewski", "Cieślak", "Kubicki",
//         "Kołodziej", "Milewski", "Szczepański", "Leszczyński", "Borowski",
//         "Borkowski", "Majewski", "Urban", "Pawlak", "Kopeć",
//         "Mróz", "Orłowski", "Musiał", "Wrona", "Brodziński",
//         "Zawadzki", "Stefański", "Andrzejewski", "Błaszczyk", "Strzelczyk",
//         "Marcinkowski", "Chojnacki", "Słowik", "Drozd", "Wilk",
//         "Bednarek", "Białek", "Michalik", "Gajda", "Jóźwiak"
//     };

//     string dolegliwosci[50] =
//     {
//         "Grypa", "Angina", "Zapalenie płuc", "COVID-19", "Astma",
//         "Cukrzyca", "Choroba wieńcowa", "Zawał serca", "Nadciśnienie", "Nowotwór",
//         "Złamanie ręki", "Złamanie nogi", "Złamanie biodra", "Rana cięta", "Rana szarpana",
//         "Oparzenie", "Odleżyny", "Reumatoidalne zapalenie stawów", "Osteoporoza", "Skolioza",
//         "Zapalenie ucha", "Zatrucie pokarmowe", "Kamica nerkowa", "Wrzody żołądka", "Alzheimer",
//         "Parkinson", "Migrena", "Depresja", "Nerwica", "Bezsenność",
//         "Padaczka", "Choroba Crohna", "Hemoroidy", "Reumatyzm", "Stwardnienie rozsiane",
//         "Zespół Downa", "Autyzm", "Biegunka", "Zaparcia", "Zapalenie gardła",
//         "Angina ropna", "Ospa", "Różyczka", "Świnka", "Zapalenie spojówek",
//         "Zawał mózgu", "Gruźlica", "Zapalenie oskrzeli", "Zatrucie chemiczne", "Wstrząśnienie mózgu"
//     };


//     ofstream plik("pacjenci.txt");
//     if(!plik)
//     {
//         cerr << "Nie ma takiego pliku!\n";
//         return 1;
//     }

//     for (int i = 1; i <= liczba_pacjentow; i++)
//     {
//         string pesel = wygenerujPesel();
//         int wiek = rand() % 121;
//         string imie = imiona[rand() % 100];
//         string nazwisko = nazwiska[rand() % 100];
//         string dolegliwosc = dolegliwosci[rand() % 50];

//         Pacjent pacjent(i, pesel, imie, nazwisko, wiek, dolegliwosc);

//         pacjent.zapisz(plik);
//     }
    
//     plik.close();
//     cout << "Zapisano dane pacjentów do pliku pacjenci.txt\n";
//     return 0;
// }