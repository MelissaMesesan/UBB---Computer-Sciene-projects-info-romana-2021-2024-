#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("date.in");

int main()
{
	int n,  m[10][10], i, j;
	fin >> n;
  for(int i = 1; i < n; i++)
  {
    for(int j = 1; j <= n; j++)
    {
      fin >> m[i][j];
      //m[j][i] = m[i][j];
    }
  }

	for(int i = 1; i <=n; i++)
        for(int j = 1; j <= n; j++)
            if(m[i][j] == 1)
                cout << i << " " << j << "\n";



    return 0;
}
