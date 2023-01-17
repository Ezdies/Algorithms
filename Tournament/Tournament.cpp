#include <bits/stdc++.h>

#include <cstdio>
#include <iterator>

using namespace std;

using DistanceType = long long;

struct Point {
    int x, y, w, index;
};

DistanceType distance(const Point &a, const Point &b) {
    return (DistanceType)(b.x - a.x) * (b.x - a.x) +
           (DistanceType)(b.y - a.y) * (b.y - a.y);
}

bool comparatorX(const Point &a, const Point &b) {
    if (a.x < b.x) {
        return true;
    } else {
        return false;
    }
}

bool comparatorY(const Point &a, const Point &b) {
    if (a.y < b.y) {
        return true;
    } else {
        return false;
    }
}

struct Result {
    Point a;
    Point b;
    DistanceType dist;
};

Result makeResult(const Point &p1, const Point &p2, const DistanceType &d) {
    Result res;
    if (p1.index < p2.index) {
        res.a = p1;
        res.b = p2;
    } else {
        res.a = p2;
        res.b = p1;
    }
    res.dist = d;
    return res;
}

const Result &minResult(const Result &r1, const Result &r2) {
    if (r1.dist < r2.dist) return r1;
    if (r1.dist == r2.dist) {
        if (r1.a.index < r2.a.index) {
            return r1;
        }
        if (r2.a.index < r1.a.index) {
            return r2;
        }
        // r1.a == r2.a
        if (r1.b.index < r2.b.index) {
            return r1;
        }
        return r2;
    }
    return r2;
}

Result minPNaPale(int a, int b, const vector<Point> &v) {
    Result res = makeResult(v[a], v[a + 1], distance(v[a], v[a + 1]));
    for (int i = a; i <= b; ++i) {
        for (int j = i + 1; j <= b; ++j) {
            const DistanceType d = distance(v[i], v[j]);
            if (d < res.dist) {
                res = makeResult(v[i], v[j], d);
            } else if (res.dist == d) {
                res = minResult(res, makeResult(v[i], v[j], d));
            }
        }
    }
    return res;
}

Result minPNaPale2(int a, int b, const vector<Point> &v) {
    Result res = makeResult(v[a], v[a + 1], distance(v[a], v[a + 1]));
    for (int i = a + 1; i <= b; ++i) {
        const DistanceType d = distance(v[a], v[i]);
        if (d < res.dist) {
            res = makeResult(v[a], v[i], d);
        } else if (res.dist == d) {
            res = minResult(res, makeResult(v[a], v[i], d));
        }
    }
    return res;
}

Result minP(int a, int b, const vector<Point> &t) {
    const int size = b - a + 1;
    if (size < 4) {
        // robimy na pale
        // printf("s = %d\n", size - 1 - 0 + 1);
        return minPNaPale(a, b, t);
    } else {
        // 4 <= size
        const int half = size / 2;
        Result leftResult = minP(a, a + half - 1, t);
        Result rightResult = minP(a + half, b, t);
        const DistanceType minDelta = min(leftResult.dist, rightResult.dist);
        float middle = (float)(t[a + half - 1].x + t[a + half].x) / 2.f;
        vector<Point> tmp;
        for (int i = a + half - 1; i >= a; --i) {
            if (t[i].x < middle - minDelta) break;
            tmp.push_back(t[i]);
        }
        for (int i = a + half; i <= b; ++i) {
            if (middle + minDelta < t[i].x) break;
            tmp.push_back(t[i]);
        }
        if (tmp.size() < 2) {
            return minResult(leftResult, rightResult);
        }
        sort(tmp.begin(), tmp.end(), comparatorY);
        // a b c d e
        int przedzial = 7;
        // printf("tmp.size= %d/%d\n", (int)tmp.size(), size);
        // a b c d e
        Result res = minPNaPale2(0, min(przedzial, (int)tmp.size() - 1), tmp);
        for (int i = 0; i <= (int)tmp.size() - 2; ++i) {
            // printf("tmp.size2=%d\n", (int)tmp.size());
            Result r =
                minPNaPale2(i, min(i + przedzial, (int)tmp.size() - 1), tmp);
            res = minResult(res, r);
        }
        return minResult(res, minResult(leftResult, rightResult));
    }
}
void deltePoint(Point u, vector<Point> &v) {
    for (int i = 0; i < (int)v.size(); ++i) {
        if (v[i].index == u.index) {
            v.erase(v.begin() + i);
            break;
        }
    }
}
int main() {
    int n, t;

    // cin >> n >> t;
    scanf("%d%d", &n, &t);

    vector<Point> point;
    for (int i = 0; i < n; i++) {
        Point p;
        // cin >> p.x >> p.y >> p.w;
        scanf("%d%d%d", &p.x, &p.y, &p.w);
        p.index = i;
        point.push_back(p);
    }

    sort(point.begin(), point.end(), comparatorX);
    // for (int i = 0; i < point.size(); ++i) {
    //     printf("%d ", point[i].x);
    // }
    // printf("\n");

    for (int i = 0; i < t; i++) {
        Result r = minP(0, n - 1, point);
        Point u;
        if (r.a.w < r.b.w)
            u = r.a;
        else
            u = r.b;

        // printf("%d %d    a=%d,%d b=%d,%d\n", u.x, u.y, r.a.x, r.a.y, r.b.x,
        //        r.b.y);

        // cout << u.x << " " << u.y << endl;
        printf("%d %d\n", u.x, u.y);
        deltePoint(u, point);
        --n;
    }

    return 0;
}
