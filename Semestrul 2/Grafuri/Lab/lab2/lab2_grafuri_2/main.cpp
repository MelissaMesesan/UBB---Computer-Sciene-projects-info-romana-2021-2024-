        /*2. Sa se determine închiderea transitivă a unui graf orientat.
        (Închiderea tranzitivă poate fi reprezentată ca matricea care descrie,
         pentru fiecare vârf în parte, care sunt vârfurile accesibile din acest vârf.
         Matricea inchiderii tranzitive arată unde se poate ajunge din fiecare vârf.)
         ex. figura inchidere_tranzitiva.png - pentru graful de sus se construieste
         matricea de jos care arata inchiderea tranzitiva.*/




#include <iostream>
#include<fstream>
using namespace std;

ifstream in("date.in2");


int main(){
    int l,j,k,t[20][20], x,y, n, a[20][20], sursa, destinatie;
    in>>n;
    for(l=1;l<=n;l++)
        for(j=1;j<=n;j++)
            {
                t[l][j]=0;
                //t[l][l]=1;
            }

    while(in>>x>>y)
    {
        t[x][y]=1;
    }

    for(k=1;k<=n;k++)
        for(l=1;l<=n;l++)
            for(j=1;j<=n;j++)
                if(t[l][j]==0)
                    t[l][j]=(t[l][k]&&t[k][j]);


    //afisare matrice inchidere tranzitiva
    cout<<"Matrice inchidere tranzitiva: "<<endl<<endl;
    for(l=1;l<=n;l++)
    {
        for(j=1;j<=n;j++)
            cout<<t[l][j]<<" ";
        cout<<endl;
    }


    int i;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (t[i][j] == 1)
				cout << "Exista drum de la " << i << " la " << j << " => d(ij) < " << n << " \n";
			else
				cout << "Nu xista drum de la " << i << " la " << j << " => d(ij) = infinit" << " \n";
		}
		cout << "\n";
	}


}
