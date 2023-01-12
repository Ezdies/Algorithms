#include <bits/stdc++.h>

using namespace std;
using vec1d = vector<int>;
using vec2d = vector<vector<int>>;

vec2d cost;
int costRes = numeric_limits<int>::max();
vec1d res;

void het(int row, int n, vec1d &occupyX, vec1d &occupyDiagM, vec1d &occupyDiagP,
         vec1d &occupyY, int _cost) {
    if (row == n) {
        if (_cost < costRes) {
            costRes = _cost;
            res = occupyY;
        }
        return;
    }
    if (_cost >= costRes) return;

    for (int i = 0; i < n; ++i) {
        const int diagM = row - i + (n - 1);
        const int diagP = row + i;
        if (occupyX[i] || occupyDiagM[diagM] || occupyDiagP[diagP]) continue;
        occupyX[i] = occupyDiagM[diagM] = occupyDiagP[diagP] = true;
        occupyY[row] = i;
        _cost += cost[row][i];

        het(row + 1, n, occupyX, occupyDiagM, occupyDiagP, occupyY, _cost);

        occupyX[i] = occupyDiagM[diagM] = occupyDiagP[diagP] = false;
        _cost -= cost[row][i];
    }
}

void het(int n) {
    vec1d occupyX(n, 0);
    vec1d occupyY(n, 0);
    vec1d occupyDiagM(n * 2 + 1, 0);
    vec1d occupyDiagP(n * 2 + 1, 0);
    het(0, n, occupyX, occupyDiagM, occupyDiagP, occupyY, 0);
}

int main() {
    int n = 20;
    cin >> n;
    cost = vec2d(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cost[i][j];
            // cost[i][j] = 5;
        }
    }
    het(n);
    for (int i = 0; i < (int)res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
}