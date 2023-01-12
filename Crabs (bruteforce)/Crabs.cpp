#include <bits/stdc++.h>

using namespace std;
using vec1d = vector<int>;
using vec2d = vector<vector<int>>;

struct Vec1d
{
    vec1d occupyX;
    vec1d occupyY;
    vec1d occupyDiagM;
    vec1d occupyDiagP;
    vec1d res;

    Vec1d(int n) : occupyX(n, 0), occupyY(n, 0), occupyDiagM(n * 2 + 1, 0), occupyDiagP(n * 2 + 1, 0), res(n, 0) {}
};

void het(int row, int n, int _cost, Vec1d &vecs1d, vec2d &cost, int &costRes)
{
    if (row == n)
    {
        if (_cost < costRes)
        {
            costRes = _cost;
            vecs1d.res = vecs1d.occupyY;
        }
        return;
    }
    if (_cost >= costRes)
        return;

    for (int i = 0; i < n; ++i)
    {
        const int diagM = row - i + (n - 1);
        const int diagP = row + i;

        if (vecs1d.occupyX[i] || vecs1d.occupyDiagM[diagM] || vecs1d.occupyDiagP[diagP])
            continue;
        vecs1d.occupyX[i] = vecs1d.occupyDiagM[diagM] = vecs1d.occupyDiagP[diagP] = true;
        vecs1d.occupyY[row] = i;
        _cost += cost[row][i];

        het(row + 1, n, _cost, vecs1d, cost, costRes);

        vecs1d.occupyX[i] = vecs1d.occupyDiagM[diagM] = vecs1d.occupyDiagP[diagP] = false;
        _cost -= cost[row][i];
    }
}

int main()
{
    int n;
    cin >> n;

    Vec1d vecs1d(n);
    auto cost = vec2d(n, vector<int>(n));
    int costRes = numeric_limits<int>::max();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> cost[i][j];
        }
    }
    het(0, n, 0, vecs1d, cost, costRes);
    for (int i = 0; i < (int)vecs1d.res.size(); ++i)
    {
        cout << vecs1d.res[i] << " ";
    }
    cout << endl;
}