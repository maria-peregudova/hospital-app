#include <iostream>
#include <string>
#include "sqlite3.h"

int main(int aggc, char* qrgv[]){
  bool exit=1;
  sqlite3 *db;
  const char* star = "%";
  const char* msg_0 = "Aby uruchomiś funkcję wyszukiwania wybierz 1\nAby zakończyć działanie programu wybierz 0\n";
  const char* msg_exit = " Chcę wyjść z funkcji poszukującej - -1\n";
  const char* msg_01 = "Wybierz po jakim parametrze chcesz wyszukać:\n imie - 1 \n nazwisko - 2 \n stan - 3 \n pokój - 4 \n opiekujący się pacjentem Lekarz(nazwisko) - 5 \n";
  const char* msg_001 = "Wybierz metodę poprzez którą chcesz wyszukać:\n znam pełne - 1 \n znam koniec - 2 \n znam początek - 3\n";
  const char* msg_002 = "Wprowadź stan pacjentów, którzych chcesz znaleźć. Uwaga! Stan -  1-5\n";
  const char* msg_003 = "Wprowadź numer pokoju, w którym chcesz znaleźć pacjentów. Uwaga! Pokoje -  1-2\n";
  std::cout<<msg_0;
  std::cin>>exit;

  
  while(exit){
    int choice = 0;
    int choice2 = 0;
    std::string name;
    std::cout<<msg_01<<msg_exit;
    std::cin>>choice; //Po czym chcemy szukać

    if(choice == -1) {exit = 0; break;}
    else if(choice == 1) { //imie
      std::cout<<msg_001<<msg_exit;
      std::cin>>choice2; //pełne, czy fragment z prawej lub lewej
      if(choice2 == -1) {exit = 0; break;}
      else if(choice2 == 1) {
	std::cout<<"Wprowadź pełne imie:\n";
	std::cin>>name;
      }
      else if(choice2 == 2) {
	std::cout<<"Wprowadź końcówkę imienia:\n";
	std::cin>>name;
	name = star + name;
      }
      else if(choice2 == 3) {
	std::cout<<"Wprowadż początek imienia:\n";
	std::cin>>name;
	name = name + star;
      }
      else {std::cout<<"Wybrałeś opcję, która nie istnieje. Wyszukiwanie będzie powtórzone;";}

      //Tu stworzyć 3 stringi, początek i koniec zapytania SQLite i zsumować je z name po środku
      
      choice2 = 0; //wyzerowanie wyboru
    }
    else if(choice == 2) { //nazwisko
      std::cout<<msg_001<<msg_exit;
      std::cin>>choice2; //pełne, czy fragment z prawej lub lewej
      if(choice2 == -1) {exit = 0; break;}
      else if(choice2 == 1) {
	std::cout<<"Wprowadź pełne nazwisko:\n";
        std::cin>>name;
      }
      else if(choice2 == 2) {
	std::cout<<"Wprowadź końcówkę nazwiska:\n";
        std::cin>>name;
	name = star + name;
      }
      else if(choice2 == 3) {
	std::cout<<"Wprowadż początek imienia:\n";
	std::cin>>name;
	name = name + star;
      }
      else {std::cout<<"Wybrałeś opcję, która nie istnieje. Wyszukiwanie będzie powtórzone;";}


      
      choice2 =	0; //wyzerowanie wyboru
    }
    else if(choice == 3) { //stan
      std::cout<<msg_002;
      std::cin>>name; //To wartość stanu, którą chcemy wyszukać

    }
    else if(choice == 4) { //pokój
      std::cout<<msg_003;
      std::cin>>name; //To numer pokoju, który chcemy wyszukać
      if(name != "2" && name != "1") {std::cout<<"Wybrałeś opcję, która nie istnieje. Wyszukiwanie będzie powtórzone;";}
      choice2 = choice2-1; //pokoje o numerach (1,2) -> (0,1), aby łatwiej dalej decydować

      choice2 = 0; //wyzerowanie wyboru
    }
    else if(choice == 5) {
      std::cout<<msg_001<<msg_exit;
      std::cin>>choice2; //pełne, czy fragment z prawej lub lewej
      if(choice2 == -1) {exit = 0; break;}
      else if(choice2 == 1) {
        std::cout<<"Wprowadź pełne nazwisko:\n";
        std::cin>>name;
      }
      else if(choice2 == 2) {
        std::cout<<"Wprowadź końcówkę nazwiska:\n";
        std::cin>>name;
        name = star + name;
      }
      else if(choice2 == 3) {
        std::cout<<"Wprowadż początek imienia:\n";
        std::cin>>name;
        name = name + star;
      }
      else {std::cout<<"Wybrałeś opcję, która nie istnieje. Wyszukiwanie będzie powtórzone;";}

    }

  }
  return 0;
}
