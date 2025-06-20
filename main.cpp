#include <iostream>
#include <cstdlib>
#include "generator_pacjentow.hpp"

using namespace std;
const int ile = 20;
Pacjent tab[ile];

int main()
{
    int wybor;
    bool dziala = true;
    string nazwa_pliku;

    while (dziala)
    {
        cout << "\nMENU" << endl;
        cout << "1. Generuj Pacjentów" << endl;
        cout << "2. Aktualizuj Pacjentów" << endl;
        cout << "3. Sprawdź poprawność parametrów Pacjentów" << endl;
        cout << "4. Uruchom funkcję Search - wyszukaj pacjentów o zadanych cechach" << endl;
        cout << "0. Koniec programu" << endl;
        cout << "Wybierz operację: " << endl;
        cin >> wybor;

        switch (wybor)
        {
        case 1:
            generujPacjentow();
            break;
        case 2:
            aktualizujPacjentow();
            break;
        case 3:
            sprawdzeniePoprawnosci();
            break;
        case 4:
            std::cout<<msg_0;
            std::cin>>end;
            // TU potrzebne odczytanie z pliku, które znajduje się w .hpp
            search(tab);
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 0:
            cout << "Koniec programu!" << endl;
            dziala = false;
            break;
        default:
            cout << "Nie ma takiej opcji!" << endl;
            break;
        }
    }
    return 0;
}
