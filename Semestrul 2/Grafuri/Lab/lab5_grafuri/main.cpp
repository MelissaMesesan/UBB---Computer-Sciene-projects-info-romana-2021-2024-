#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");

int n, m, i, r[200001], cost, p[200001], x, y, c;

struct muchie{
    int x, y, c;
};

int root(int x){
    while (x != r[x])
        x = r[x];
    return x;
}

void merger(int a, int b){
    if (p[a] < p[b])
        r[a] = b;
    if (p[a] > p[b])
        r[b] = a;
    if (p[a] == p[b])
    {
        r[b] = a;
        p[a]++;
    }
}

bool comp(muchie a, muchie b){
    return a.c < b.c;
}

vector <muchie> v, out;

int main()
{
    fin >> n >> m;
    for (i = 1; i <= m; i++)
    {
        fin >> x >> y >> c;
        v.push_back({ x, y, c });
    }
    for (i = 1; i <= n; i++)
        r[i] = i;
    int k = 0;
    i = 0;
    sort(v.begin(), v.end(), comp);
    while (k < n - 1)
    {
        x = v[i].x;
        y = v[i].y;
        c = v[i].c;
        int rx = root(x), ry = root(y);
        if (rx != ry)
        {
            out.push_back(v[i]);
            k++;
            cost += c;
            merger(rx, ry);
        }
        i++;
    }
    fout << cost << '\n' << n - 1 << '\n';
    pair<int, int>array[10000];
    for (int i = 0; i < k; i++) {
        array[i].first = out[i].x;
        array[i].second = out[i].y;
    }
    sort(array, array + k);
    for (i = 0; i < k; i++)
    {
        fout << array[i].first << ' ' << array[i].second << '\n';
    }
    return 0;
}
