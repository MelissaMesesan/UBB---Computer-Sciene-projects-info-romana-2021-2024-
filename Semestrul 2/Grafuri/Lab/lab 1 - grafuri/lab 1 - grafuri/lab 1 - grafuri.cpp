#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("C:\\Users\\Meli\\source\\repos\\TextFile1.txt");


int main()
{
	int n, a, b, m[20][20], m1[20][20], i, j, k = 1;
	fin>>n;

	// intializez matricile cu 0
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			m[i][j] = 0;
			m1[i][j] = 0;
		}
	}

	// citesc muchiile si le pun in matrice
	while (fin >> a >> b)
		m[a][b] = m[b][a] = 1;

	// k = pe ce coloana ma aflu
	k = k + 1;
	for (i = 1; i <= n; i++) {
		m1[a][k] = 1;
		m1[b][k] = 1;
	}
	
	
	

	// afisare matrice adiacenta
	cout << "matricea de adiacenta:"<<endl;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cout << m[i][j]<<" ";
		}
		cout<<endl;
	}
	k = 1;
	for (i = 1;i <= n;i++) {
		for (j =i+1;j <= n;j++)
			if (m[i][j] == 1)
			{
				m1[i][k] = 1;
				m1[j][k] = 1;
				k++;
			}
	}
	cout << endl;
	// afisare matrice inceidenta
	cout<<"matricea de incidenta:"<<endl;
	for (i = 1; i <= n; i++) {
		for (j =1; j <k; j++) {
			cout<<m1[i][j]<<" ";
		}
		cout<<endl;
	}
	cout << endl;
	// afisare lista de adiacenta
	cout << "lista de adiacenta:" << endl;
	for (i = 1;i <= n;i++) {
		cout <<endl<< i << ": ";
		for (j = 1;j <= n;j++)
			if (m[i][j] == 1)
				cout << ' ' << j;
	}

    return 0;
}
