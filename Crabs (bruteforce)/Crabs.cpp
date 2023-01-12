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

vec2d cost;
int costRes = numeric_limits<int>::max();

void het(int row, int n, int _cost, Vec1d &v1d)
{
    if (row == n)
    {
        if (_cost < costRes)
        {
            costRes = _cost;
            v1d.res = v1d.occupyY;
        }
        return;
    }
    if (_cost >= costRes)
        return;

    for (int i = 0; i < n; ++i)
    {
        const int diagM = row - i + (n - 1);
        const int diagP = row + i;
        if (v1d.occupyX[i] || v1d.occupyDiagM[diagM] || v1d.occupyDiagP[diagP])
            continue;
        v1d.occupyX[i] = v1d.occupyDiagM[diagM] = v1d.occupyDiagP[diagP] = true;
        v1d.occupyY[row] = i;
        _cost += cost[row][i];

        het(row + 1, n, _cost, v1d);

        v1d.occupyX[i] = v1d.occupyDiagM[diagM] = v1d.occupyDiagP[diagP] = false;
        _cost -= cost[row][i];
    }
}

int main()
{
    int n;
    cin >> n;
    Vec1d v1d(n);
    cost = vec2d(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> cost[i][j];
        }
    }
    het(0, n, 0, v1d);
    for (int i = 0; i < (int)v1d.res.size(); ++i)
    {
        cout << v1d.res[i] << " ";
    }
    cout << endl;
}