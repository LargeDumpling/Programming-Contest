#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int UNKNOWN = INT_MAX;
const double W = 1E7;
const double EPS = 1E-9;

int n, m;

vector<int> a, b, d;
vector<int> o;

struct edge {
    int a, b, e;
    double w;
};

vector<edge> g;
vector<double> r;

int main() {
    while (cin >> n >> m) { 
        o = vector<int>(n);
        g = vector<edge>();

        forn(i, n) {
            string x;
            cin >> x;
            if (x == "?")
                o[i] = UNKNOWN;
            else {
                stringstream ss;
                ss << x;
                ss >> o[i];
            }

            edge fo = {0, i + 1, -1, 0.0};
            g.push_back(fo);
            edge ba = {i + 1, 0, -1, 0.0};
            g.push_back(ba);
        }

        a = b = d = vector<int>(m);
        forn(j, m) {
            cin >> a[j] >> b[j] >> d[j];
            edge e = {b[j], a[j], j, 0.0};
            g.push_back(e);
        }

        r = vector<double>(n + 1);
        double L = 0;
        double R = 1E10;

        forn(tt, 100) {
            double mid = (L + R) / 2;

            forn(i, g.size()) {
                if (g[i].e == -1) {
                    int idx = g[i].a + g[i].b - 1;
                    if (o[idx] == UNKNOWN)
                        g[i].w = (g[i].a == 0 ? +W : +W);
                    else
                        g[i].w = (g[i].a == 0 ? o[idx] : -o[idx]);
                } else
                    g[i].w = mid - d[g[i].e];
            }

            r[0] = 0;
            forn(i, n)
                r[i + 1] = 1E100;
            
            forn(i, n)
                forn(j, g.size())
                    if (r[g[j].a] < 1E20 && r[g[j].b] > r[g[j].a] + g[j].w)
                        r[g[j].b] = r[g[j].a] + g[j].w;

            bool negative_cycle = false;
            forn(j, g.size())
                if (r[g[j].b] > r[g[j].a] + g[j].w + EPS)
                    negative_cycle = true;

            if (negative_cycle) 
                L = mid;
            else
                R = mid;
        }

        printf("%.10f\n", (L + R) / 2);
        forn(i, n)
            printf("%.10f ", r[i + 1]);
        printf("\n");    
    }
}
