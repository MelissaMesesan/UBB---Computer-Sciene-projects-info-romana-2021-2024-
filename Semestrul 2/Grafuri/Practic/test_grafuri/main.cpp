#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <Queue>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

const int NMAX = 1e3 + 5;
const int inf = 1e9;
vector < int > v[NMAX];
int n, m, F[NMAX][NMAX], c[NMAX][NMAX], parent[NMAX], viz[NMAX];
deque < int > q;

bool BFS() {
    int node;
    memset(viz, 0, sizeof(viz));
    q.push_back(1);
    viz[1] = 1;
    while (!q.empty()) {
        node = q.front();
        q.pop_front();

        if (node == n) continue;

        for (auto nxt : v[node])
            if (!viz[nxt] && c[node][nxt] != F[node][nxt]) {
                viz[nxt] = 1;
                q.push_back(nxt);
                parent[nxt] = node;
            }
    }
    return viz[n];
}

int main() {
    int i, j, x, y, cost;
    fin >> n >> m;
    for (i = 1; i <= m; i++) {
        fin >> x >> y >> cost;
        v[x].push_back(y);
        v[y].push_back(x);
        c[x][y] += cost;
    }

    int flow = 0, mflow, node;
    do {
        for (const auto& nxt : v[n]) {
            if (F[nxt][n] == c[nxt][n] || !viz[nxt])
                continue;
            mflow = inf;
            parent[n] = nxt;
            for (node = n; node != 1; node = parent[node]){
                mflow = min(mflow, c[parent[node]][node] - F[parent[node]][node]);
            }
            if (mflow == 0)
                continue;
            for (node = n; node != 1; node = parent[node]) {
                F[parent[node]][node] += mflow;
                F[node][parent[node]] -= mflow;
            }
            flow += mflow;
        }
    } while (BFS()); // cat timp citim in latime

    fout << flow;

    return 0;
}
