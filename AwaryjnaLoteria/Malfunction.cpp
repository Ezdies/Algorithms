#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

struct Wniosek {
    unsigned int ID;
    std::string surname;
    std::string name;

    Wniosek() = default;
    bool operator<(const Wniosek &a) {
        if (ID != a.ID) return ID < a.ID;
        if (surname != a.surname) return surname < a.surname;
        return name < a.name;
    }
};

void printWniosek(const Wniosek &wniosek) {
    std::cout << wniosek.name << " " << wniosek.surname << " " << wniosek.ID
              << '\n';
}

Wniosek &medianaMedian(std::vector<Wniosek> &wnioski, int start, int end) {
    int size = end - start;

    if (size <= 10) {
        std::sort(wnioski.begin() + start, wnioski.begin() + end);
        Wniosek &res = wnioski[(start + end) / 2];
        return res;
    }

    const int elements = 5;
    int n = ceil((float)size / elements);

    for (int i = 0; i < n; i++) {
        int start2 = start + i * elements;
        int end2 = std::min(end, start2 + elements);
        auto &tmp = medianaMedian(wnioski, start2, end2);
        std::swap(wnioski[start + i], tmp);
    }
    return medianaMedian(wnioski, start, start + n);
}

void divideToSubArrays(std::vector<Wniosek> &wnioski, const Wniosek &pivot,
                       int &aCount, int &bCount, int &cCount, int start,
                       int end) {
    int a = 0;
    int c = 0;

    for (int i = start; i < end; i++) {
        if (wnioski[i] < pivot) {
            std::swap(wnioski[a + start], wnioski[i]);
            a++;
        }
    }

    for (int i = end - 1; i >= start; i--) {
        if ((Wniosek)pivot < wnioski[i]) {
            std::swap(wnioski[end - 1 - c], wnioski[i]);
            c++;
        }
    }
    aCount = a;
    cCount = c;
    bCount = end - start - aCount - cCount;
}

Wniosek kWniosek(std::vector<Wniosek> &wnioski, const int k, int start,
                 int end) {
    const Wniosek pivot = medianaMedian(wnioski, start, end);

    int aCount = 0;
    int bCount = 0;
    int cCount = 0;

    divideToSubArrays(wnioski, pivot, aCount, bCount, cCount, start, end);

    if (k < aCount) {
        return kWniosek(wnioski, k, start, start + aCount);
    }
    if (k < aCount + bCount) {
        return pivot;
    }
    return kWniosek(wnioski, k - aCount - bCount, end - cCount, end);
}

void getInput(std::vector<Wniosek> &wnioski, const int i) {
    Wniosek wniosek;
    std::cin >> wniosek.name >> wniosek.surname >> wniosek.ID;
    wnioski[i] = wniosek;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<Wniosek> wnioski(n);

    for (int i = 0; i < n; i++) {
        getInput(wnioski, i);
    }

    auto res = kWniosek(wnioski, k, 0, wnioski.size());
    printWniosek(res);
}