#ifndef PACJENT_HPP
#define PACJENT_HPP

class Osoba{
public:

  //Konstruktory
  
  Osoba(): pesel{0}, wiek{0}, wzrost{0}, waga{0} {};
  Osoba(string Pesel, string Imie, string Nazwisko, int Wiek, string Plec, int Wzrost, int Waga): pesel{Pesel}, imie{Imie}, nazwisko{Nazwisko}, wiek{Wiek}, plec{Plec}, wzrost{Wzrost}, waga{Waga} {};

  //Setery
  
  void set_pesel(string Pesel){pesel=Pesel;}
  void set_imie(string Imie){imie=Imie;}
  void set_nazwisko(string Nazwisko){nazwisko=Nazwisko;}
  void set_plec(string Plec){plec=Plec;}
  
  void set_wiek(int Wiek){wiek=Wiek;}
  void set_wzrost(int Wzrost){wzrost=Wzrost;}
  void set_waga(int Waga){waga=Waga;}

  //Getery
  
  string get_pesel(){return pesel;}
  string get_imie(){return imie;}
  string get_nazwisko(){return nazwisko;}
  string get_plec(){return plec;}

  int get_wiek(){return wiek;}
  int get_wzrost(){return wzrost;}
  int get_waga(){return waga;}

  //Destruktor
  
  ~Osoba() {};

protected:
  string pesel, imie, nazwisko, plec, dolegliwosc;
  int wiek, wzrost, waga;
};

class Pomiary{
public:

  //Konstruktor
  
  Pomiary(): cisnienie_skurczowe{0}, cisnienie_rozkurczowe{0}, tetno{0}, utlenienie{0}, poziom_cukru{0}, temperatura_ciala{0}, stan{0} {};
  Pomiary(int cS, int cR, int Tetno, int Utlenienie, int Cukier, int temp, int Stan, string Dolegliwosc): cisnienie_skurczowe{cS}, cisnienie_rozkurczowe{cR}, tetno{Tetno}, utlenienie{Utlenienie}, poziom_cukru{Cukier}, temperatura_ciala{temp}, stan{Stan}, dolegliwosc{Dolegliwosc} {};
	  
  //Setery

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

    void set_temp(int wartosc)
    {
        temperatura_ciala = wartosc;
    }

  void set_dolegliwosc(string wartosc){
    dolegliwosc = wartosc;
  }
  
  //Getery

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

    int get_temp()
    {
        return temperatura_ciala;
    }

  string get_dolegliwosc(){return dolegliwosc;}
  
  
  //Destruktor
  
  ~Pomiary() {};

protected:
  int cisnienie_skurczowe, cisnienie_rozkurczowe, tetno, poziom_cukru, utlenienie, temperatura_ciala, stan;
  string dolegliwosc;

};


class Pacjent: public Osoba, public Pomiary{
public:

  //Konstruktory

  Pacjent(): Osoba(), Pomiary() {};
  Pacjent(string Pesel, string Imie, string Nazwisko, int Wiek, string Plec, int Wzrost, int Waga, int cS, int cR, int Tetno, int Utlenienie, int Cukier, int temp, int Stan, string Dolegliwosc ): Osoba(Pesel, Imie, Nazwisko, Wiek, Plec, Wzrost, Waga), Pomiary(cS, cR, Tetno, Utlenienie, Cukier, temp, Stan, Dolegliwosc) {};
  
  //Destruktor

  ~Pacjent() {};
  
protected:
  Pomiary pomiary;

};



#endif
