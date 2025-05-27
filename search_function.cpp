#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "sqlite3.h"
#include "generator_pacjentow.hpp"

  int end=1;
  const char* msg_0 = "Aby uruchomiś funkcję wyszukiwania wybierz 1\nAby zakończyć działanie programu wybierz 0\n";
  const char* msg_exit = " Chcę wyjść z funkcji poszukującej - -1\n";
  const char* msg_01 = "Wybierz po jakim parametrze chcesz wyszukać:\n imie - 1 \n nazwisko - 2 \n stan - 3 \n pokój - 4 \n opiekujący się pacjentem Lekarz(nazwisko) - 5 \n";
  const char* msg_001 = "Wprowadź imię albo jego fragment:\n";
  const char* msg_0001 = "Wprowadź nazwisko albo jego fragment:\n";
  const char* msg_002 = "Wprowadź stan pacjentów, którzych chcesz znaleźć. Uwaga! Stan -  1-5\n";
  const char* msg_003 = "Wprowadź numer pokoju, w którym chcesz znaleźć pacjentów. Uwaga! Pokoje -  1-2\n";
const int ile = 10;

Pacjent tab[ile];

std::vector <std::string> split_text(const std::string &text, char delimiter){ //funkcja zwracająca wektor stringów, podzielonych delimiterem                                           
    std::vector<std::string> tokens;
    std::stringstream ss(text);
    std::string token;

    while(std::getline(ss, token, delimiter)){
	tokens.push_back(token);
    }
    return tokens;
}

int wczytaj(Pacjent *tab){
    int count = 0;
    std::string filename, line;
    std::vector<std::string> tokens;
    std::ifstream file;
    filename = "dane.txt";
    file.open(filename.c_str());
    while(std::getline(file, line)){
        tokens = split_text(line, ' ');
        tab[count].set_id(std::stoi(tokens[0]));
	tab[count].set_imie(tokens[1]);
        tab[count].set_nazwisko(tokens[2]);
	tab[count].set_stan(std::stoi(tokens[3]));
        tab[count].set_lekarz(tokens[4]);
        count++;
    }
    file.close();
    return count;
}


void search(int choice, Pacjent *tab){
    std::string name;
    int number = 0;
    int count = 0;
    int found = 0;
    if(choice == -1) {end = 0;}
    else if(choice == 1) { //imie                                                                                                                                                       
      std::cout<<msg_001<<msg_exit;
      std::cin>>name;
      if(name == "-1") {end = 0;}
      else{
	count = wczytaj(tab);
	for(int i=0;i<count;i++){
	  std::string data = tab[i].get_imie();
	  found = data.find(name);
	  if(found != std::string::npos){
	    std::cout<<tab[i].get_id()<<" "<<tab[i].get_imie()<<" "<<tab[i].get_nazwisko()<<" "<<tab[i].get_stan()<<" "<<tab[i].get_lekarz()<<"\n";
	  }
	  found = 0;
	}
      }count = 0;

    }
    else if(choice == 2) { //nazwisko                                                                                                                                                   
      std::cout<<msg_0001<<msg_exit;
      std::cin>>name;
      if(name == "-1") {end = 0;}
      else{
	count = wczytaj(tab);
        for(int i=0;i<count;i++){
          std::string data = tab[i].get_nazwisko();
          found = data.find(name);
          if(found != std::string::npos){
            std::cout<<tab[i].get_id()<<" "<<tab[i].get_imie()<<" "<<tab[i].get_nazwisko()<<" "<<tab[i].get_stan()<<" "<<tab[i].get_lekarz()<<"\n";
          }
          found = 0;
        }
      }count = 0;

    }
    else if(choice == 3) { //stan                                                                                                                                                       
      std::cout<<msg_002<<msg_exit;
      std::cin>>number; //To wartość stanu, którą chcemy wyszukać
      if(number == -1){ end = 0;}
      else{
	count = wczytaj(tab);
	for(int i=0;i<count;i++){
	  int data = tab[i].get_stan();
	  if(data == number){
	    std::cout<<tab[i].get_id()<<" "<<tab[i].get_imie()<<" "<<tab[i].get_nazwisko()<<" "<<tab[i].get_stan()<<" "<<tab[i].get_lekarz()<<"\n";
	  }
	  data = 0;
	}
      }
      count = 0;
      number = 0;
    }
    else if(choice == 4) { //pokój                                                                                                                                                      
      std::cout<<msg_003;
      std::cin>>number; //To numer pokoju, który chcemy wyszukać
      if(number == -1){ end = 0;}
      else{
	count = wczytaj(tab);
	for(int i=0;i<count;i++){
          int data = tab[i].get_id();
          if(data%2 == number%2){
            std::cout<<tab[i].get_id()<<" "<<tab[i].get_imie()<<" "<<tab[i].get_nazwisko()<<" "<<tab[i].get_stan()<<" "<<tab[i].get_lekarz()<<"\n";
          }
          data = 0;
	}
      }
      count = 0;
      number = 0;

    }
    else if(choice == 5) {
      std::cout<<msg_0001<<msg_exit;
      std::cin>>name; //pełne, czy fragment z prawej lub lewej                                                                                                                       
      if(name == "-1") {end = 0;}
      else{
        count = wczytaj(tab);
        for(int i=0;i<count;i++){
          std::string data = tab[i].get_lekarz();
          found = data.find(name);
          if(found != std::string::npos){
            std::cout<<tab[i].get_id()<<" "<<tab[i].get_imie()<<" "<<tab[i].get_nazwisko()<<" "<<tab[i].get_stan()<<" "<<tab[i].get_lekarz()<<"\n";
          }
          found = 0;
        }
	
      }
      count = 0;

    }

}

int choice = 0;

int main(int argc, char* argv[]){
  std::cout<<msg_0;
  std::cin>>end;

  while(end){
    std::cout<<msg_01<<msg_exit;                                                                                                                                                       
    std::cin>>choice; //Po czym chcemy szukać
    search(choice, tab);
    std::cout<<msg_0;
    std::cin>>end;
  }
  return 0;
}
