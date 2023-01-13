// counting sort
// musimy znać dziedzinę wartości tego co mamy sortować
// wiemy, że są z przedziału do 0-99 i 0-9
// jeśli sortowaliśmyby względem jedynie pierwszej kolumny
// chcemy zliczyć ile wartości będzie w naszych danych
// robimy tablicę o wielkości puapek (99)
// przechowujemy informację jaka osoba się kryje pod danym indeksem
// Przechodzimy od końca i je wypisujemy
// druga kolumna jest sortowana w odwrotnej kolejności
// do drugiej kolumny korzystamy z tablicy dwuwymiarowej
// adekwatnej do dziedziny wartości
// dwuwymiarowa puapki x kraby
// elementami są listy
// przechodzimy od prawej strony i od góry na dół
// trick jest taki żeby używać stringów zamiast list

// można zrobić to inaczej na jednowymiarowej tablicy
// jak są dwie wartości na tym samym indexie, to dodać do stringa np

#include <iostream>
#include <string>

void solve(int *crabs, int *crabsTotal, std::string *names, std::string *namesTotal, int n)
{
    const int size = 100;

    for (int i = 0; i < n; i++)
    {
        crabsTotal[crabs[i]] = crabs[i];

        //jeśli jest już zajęte, to dodaj do tego słowa
        if (namesTotal[crabs[i]] != std::string())
        {
            namesTotal[crabs[i]].append(" " + names[i]);
        }
        else
        {
            namesTotal[crabs[i]] = names[i];
        }
    }
}

void printCrabsTotal(int *crabsTotal, const int N = 100)
{
    for (int i = N - 1; i >= 0; i--)
    {
        if (crabsTotal[i] != 0)
        {
            std::cout << crabsTotal[i] << ' ';
        }
    }
    std::cout << '\n';
}

void printNamesTotal(std::string *namesTotal, const int N = 100)
{
    for (int i = N - 1; i >= 0; i--)
    {
        if (namesTotal[i] != std::string())
        {
            std::cout << namesTotal[i] << ' ';
        }
    }
    std::cout << '\n';
}

void getInput(std::string *names, int *crabs, int *traps, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cin >> names[i] >> crabs[i] >> traps[i];
    }
}

void freeMemory(std::string *names, int *crabs, int *traps)
{
    delete[] names;
    delete[] crabs;
    delete[] traps;
}

void printInput(std::string *names, int *crabs, int *traps, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << names[i] << " " << crabs[i] << " " << traps[i] << '\n';
    }
}

int main()
{
    int n;
    std::cin >> n;

    std::string *names = new std::string[n];

    const int totalCrabsNumber = 100;
    const int totalTrapsNumber = 9;

    int *crabs = new int[n];
    int *traps = new int[n];

    int crabsTotal[totalCrabsNumber]{};
    int trapsTotal[totalTrapsNumber]{};
    std::string namesTotal[totalCrabsNumber]{};
    int possibilitiesTotal[totalCrabsNumber * totalTrapsNumber];

    getInput(names, crabs, traps, n);
    solve(crabs, crabsTotal, names, namesTotal, n);
    printCrabsTotal(crabsTotal);
    printNamesTotal(namesTotal);
    //  printInput(names, crabs, traps, n);
    freeMemory(names, crabs, traps);
}