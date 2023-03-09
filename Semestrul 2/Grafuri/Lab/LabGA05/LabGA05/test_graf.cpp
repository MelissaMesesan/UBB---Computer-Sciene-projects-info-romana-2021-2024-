#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using std::queue;
using std::vector;
using std::pair;
using std::ifstream;
using std::make_pair;
int v, e;
ifstream fin("input.txt");

#define INF 99999999;

queue<int> Q;
vector<pair<int, int>> G[100000];
int Graph[1000][1000];
int d[100000];
int viz[100000];
int p[100000];

void citire() {
    fin >> v >> e;
    int i, j,k;
    while (fin >> i >> j >> k) {
        G[i].push_back(make_pair(j, k));
        Graph[i][j] = k;
    }

}

bool bfs() {
    int i;
    for (i = 0; i < v; i++) {
        p[i] = 0;
        viz[i] = 0;
    }
    viz[0] = 1;
    p[0] = -1;
    Q.push(0);
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        for (i = 0; i < v; i++) {
            if (viz[i] == 0 && Graph[x][i] > 0) {
                viz[i] = 1;
                p[i] = x;
                Q.push(i);
            }
        }
    }
    if (viz[v - 1] == 0) {
        return false;
    }
    return true;
    
}

int flow() {

    int maxfl = 0;
    while (bfs()) {
        int fl = INF;
        int y = v - 1;
        while (y != 0) {
            int x = p[y];
            if (Graph[x][y] < fl) {
                fl = Graph[x][y]; //cel mai mic cost
            }
            y = p[y];
        }
        y = v - 1;

        while (y != 0) {
            int x = p[y];
            Graph[x][y] -= fl;//actualizare x->y
            Graph[y][x] += fl;//actualizare y->x
            y = p[y];
        }
        maxfl += fl; //actualizare flux 

    }
    return maxfl;
}




int main()
{
    citire();
    std::cout << flow();
}


