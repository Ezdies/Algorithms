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

#define CRABS_MAX 100
#define TRAPS_MAX 10

void solve(int *crabs, int *traps, std::string *names, std::string possibilitiesTotalNames[][TRAPS_MAX], int n)
{

    for (int i = 0; i < n; i++)
    {
        if (possibilitiesTotalNames[crabs[i]][traps[i]] != std::string())
        {
            possibilitiesTotalNames[crabs[i]][traps[i]].append(" " + names[i]);
        }
        else
        {
            possibilitiesTotalNames[crabs[i]][traps[i]] = names[i];
        }
    }
}

void printResult(std::string possibilitiesTotal[][TRAPS_MAX])
{
    for (int i = CRABS_MAX - 1; i >= 0; i--)
    {
        for (int j = 0; j < TRAPS_MAX; j++)
        {
            if (possibilitiesTotal[i][j] != std::string())
            {
                std::cout << possibilitiesTotal[i][j] << ' ';
            }
        }
    }
    std::cout << '\n';
}

void getInput(std::string *names, int *crabs, int *traps, int n)
{

    for (int i = 0; i < n; i++)
    {
        std::cin >> names[i] >> crabs[i] >> traps[i];
        names[i].shrink_to_fit();
    }
}

void freeMemory(std::string *names, int *crabs, int *traps)
{
    delete[] names;
    delete[] crabs;
    delete[] traps;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::string *names = new std::string[n];
    int *crabs = new int[n];
    int *traps = new int[n];

    const int totalCrabsNumber = 100;
    const int totalTrapsNumber = 10;

    std::string possibilitiesTotalNames[totalCrabsNumber][totalTrapsNumber]{};

    getInput(names, crabs, traps, n);
    solve(crabs, traps, names, possibilitiesTotalNames, n);
    printResult(possibilitiesTotalNames);
    freeMemory(names, crabs, traps);
}