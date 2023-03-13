// trzeba znaleźć ścieżkę Eulera
// dzielimy każdą trójkę na parę i to jest krawędź
// musimy stwierdzić jakie są stopnie poszeczególnych wierzchołków - zważyć je
// wartość powyżej 0 - więcej wierzchołków wychodzących niż wchodzących
// wszystkie wierzchołki mają stopień 0 - zaczynamy leksograficznie
// inaczej zaczynamy od wierzchołka o wartości 1
// patrzymy ile razy przejdziemy przez krawędź daną

#include <iostream>
#include <vector>
#include <algorithm>

struct Triplet
{
    int x;
    int y;
    int z;
};

struct Pair
{
    int left;
    int right;
};


void printInput(const std::vector<Triplet> &triplets)
{
    for (const auto &triplet : triplets)
    {
        std::cout << triplet.x << " " << triplet.y << " " << triplet.z << '\n';
    }
}

void solve()
{
}

int main(int argc, char const *argv[])
{
    int t;
    int n;
    int x, y, z;

    std::cin >> t;

    std::vector<Triplet> triplets;
    

    for (int i = 0; i < t; i++)
    {
        std::cin >> n;
        for (int j = 0; j < n - 2; j++)
        {
            Triplet triplet;
            std::cin >> triplet.x >> triplet.y >> triplet.z;
            triplets.push_back(triplet);
        }
    }

    printInput(triplets);

    return 0;
}
