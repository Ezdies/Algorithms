//graf nieskierowany
//sąsiad jest sąsiadem swojego i sąsiadem sąsiada
//numerujemy wioski
//macierz lub lista siąsiedztwa
//macierz gdy gęste grafy (dużo połączeń między wierzchołkami)
//lepiej skorzystać z listy sąsiedztwa
//dla każdego wierzchołka tworzymy listę sąsiadów
//lista sąsiedztwa to mapa
//Algorytm BFS
//odwiedzamy graf warstwowo
//przekazujemy informację jak daleko jesteśmy od wierzchołka początkowego
//wykorzystujemy kolejkę
//robimy dwie tablice
//jedna tablica przechowuje informacje czy dany wierzchołek odwiedziliśmy czy nie
//druga przechowuje informacje jaka jest minimalna odległość od wierzchołka początkowego
//czyli na początku inicjalizujemy ją wartościami maksymalnymi
//Kolejka:
//wrzucamy wierzchołek startowy do kolejki
//informacja, że odległość wynosi 0
//i oznaczamy, że wierzchołek został odwiedzony
//ściągamy element z kolejki
//wrzucamy wszystkich sąsiadów do kolejki
//aktualizujemy informację o sąsiednich wierzchołków w tablicach
//odwiedzamy tylko nieodwiedzone wierzchołki, jak zostały odwiedzone to zwiększamy ich odległość
//względem wierzchołka wyciągniętego z kolejki
//jak kolejka będzie pusta, to przeglądamy tablicę i wyświetlamy wierzchołki z największą odległością
//kluczem nazwa wioski, a wartością numer (0,1,2,..)


#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int numberOfVillages;
    int numberOfTargetVillages;
    std::map<std::string, int> namesToIntMap;
    std::vector<int> villages;
    std::vector<int> villagesNeighbours;
    std::map<int, std::vector<int>> villageAndNeighboursMap;
    std::string startingVillage;

    std::cin >> numberOfVillages >> numberOfTargetVillages;

    std::string villageName;

    for (int i = 0; i < numberOfVillages; i++) {
        std::cin >> villageName;
        namesToIntMap[villageName] = i;
        villages.push_back(namesToIntMap[villageName]);
    }

    for (int i = 0; i < numberOfVillages;) {
        std::cin >> villageName;
        if (villageName != "X") {
            villagesNeighbours.push_back(namesToIntMap[villageName]);
        } else {
            villageAndNeighboursMap[villages[i]] = villagesNeighbours;
            //ewentualna optymalizacja tutaj
            villagesNeighbours.clear();
            i++;
        }
    }

    std::cin >> startingVillage;

    std::vector<int> targetVillages;

    for (int i = 0; i < numberOfTargetVillages; i++) {
        std::cin >> villageName;
        targetVillages.push_back(namesToIntMap[villageName]);
    }

    //wyswietlanie wierzcholkow i sasiadow

//    for (const auto &[village, neighbours]: villageAndNeighboursMap) {
//        std::cout << "Wioska - " << village << ", Sasiedzi: ";
//        for (const auto neighbour: neighbours) {
//            std::cout  << neighbour << " ";
//        }
//        std::cout << std::endl;
//    }

    //bfs

    const int MAX_NUMBER_OF_VILLAGES = 0;
    std::vector<bool> visitedVillages(numberOfVillages, false);
    std::vector<int> minimalDistanceFromStartingVillage(numberOfVillages, MAX_NUMBER_OF_VILLAGES);

    std::queue<int> q;
    q.push(namesToIntMap[startingVillage]);
    visitedVillages[namesToIntMap[startingVillage]] = true;
    minimalDistanceFromStartingVillage[namesToIntMap[startingVillage]] = 0;

    int maxi = 0;

    while (!q.empty()) {
        for (int v: villageAndNeighboursMap[q.front()]) {
            if (!visitedVillages[v]) {
                minimalDistanceFromStartingVillage[v] = minimalDistanceFromStartingVillage[q.front()] + 1;
                for(int targetVillage : targetVillages) {
                    if(targetVillage == v) {
                        maxi = std::max(maxi, minimalDistanceFromStartingVillage[v]);
                    }
                }
                q.push(v);
                visitedVillages[v] = true;
            }
        }
        q.pop();
    }

//    for (int i = 0; i < numberOfVillages; i++) {
//        std::cout << minimalDistanceFromStartingVillage[i] << std::endl;
//    }

    std::cout << maxi;

    return 0;
}
