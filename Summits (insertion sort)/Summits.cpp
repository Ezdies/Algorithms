#include <iostream>
#include <string>

bool isPowerOfTwo(unsigned int x) {
    return x != 0 && !(x & (x - 1));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int t;
    int n;
    int sizeOfPowerOf2Array;
    int sizeOfNotPowerOf2Array;
    int summitPower2Counter;
    int summitNotPower2Counter;

    std::cin >> t;
    for (int i = 0; i < t; i++) {

        std::cin >> n;

        auto *summitHeights = new long long int[n];
        auto *summitNames = new std::string[n];
        for (int j = 0; j < n; j++) {
            std::cin >> summitNames[j];
            std::cin >> summitHeights[j];
            if (isPowerOfTwo(summitHeights[j])) {
                sizeOfPowerOf2Array++;
            }
        }

        sizeOfNotPowerOf2Array = n - sizeOfPowerOf2Array;

        auto *summitHeightsPower2 = new long long[sizeOfPowerOf2Array];
        auto *summitNamesPower2 = new std::string[sizeOfPowerOf2Array];

        auto *summitHeightsNotPower2 = new long long[sizeOfNotPowerOf2Array];
        auto *summitNamesNotPower2 = new std::string[sizeOfNotPowerOf2Array];

        summitPower2Counter = 0;
        summitNotPower2Counter = 0;

        for (int j = 0; j < n; j++) {
            if (isPowerOfTwo(summitHeights[j])) {
                summitHeightsPower2[summitPower2Counter] = summitHeights[j];
                summitNamesPower2[summitPower2Counter] = summitNames[j];
                summitPower2Counter++;
            } else {
                summitHeightsNotPower2[summitNotPower2Counter] = summitHeights[j];
                summitNamesNotPower2[summitNotPower2Counter] = summitNames[j];
                summitNotPower2Counter++;
            }
        }

        long long tempHeight, k;
        std::string tempName;

        for (int j = 1; j < sizeOfPowerOf2Array; j++) {
            tempHeight = summitHeightsPower2[j];
            tempName = summitNamesPower2[j];
            for (k = j - 1; k >= 0 && summitHeightsPower2[k] > tempHeight; k--) {
                summitHeightsPower2[k + 1] = summitHeightsPower2[k];
                summitNamesPower2[k + 1] = summitNamesPower2[k];
            }
            summitHeightsPower2[k + 1] = tempHeight;
            summitNamesPower2[k + 1] = tempName;
        }

        for (int j = 1; j < sizeOfNotPowerOf2Array; j++) {
            tempHeight = summitHeightsNotPower2[j];
            tempName = summitNamesNotPower2[j];
            for (k = j - 1; k >= 0 && summitHeightsNotPower2[k] > tempHeight; k--) {
                summitHeightsNotPower2[k + 1] = summitHeightsNotPower2[k];
                summitNamesNotPower2[k + 1] = summitNamesNotPower2[k];
            }
            summitHeightsNotPower2[k + 1] = tempHeight;
            summitNamesNotPower2[k + 1] = tempName;
        }
        for (int j = 0; j < sizeOfPowerOf2Array; j++) {
            std::cout << summitNamesPower2[j] << "-" << summitHeightsPower2[j] << ' ';
        }
        for (int j = 0; j < sizeOfNotPowerOf2Array; j++) {
            std::cout << summitNamesNotPower2[j] << "-" << summitHeightsNotPower2[j] << ' ';
        }

        std::cout << '\n';
        sizeOfPowerOf2Array = 0;

        delete[] summitHeights;
        delete[] summitNames;
        delete[] summitHeightsPower2;
        delete[] summitHeightsNotPower2;
        delete[] summitNamesPower2;
        delete[] summitNamesNotPower2;
    }
    return 0;
}
