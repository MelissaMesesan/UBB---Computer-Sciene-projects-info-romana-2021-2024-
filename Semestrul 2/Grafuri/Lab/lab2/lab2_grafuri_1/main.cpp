/*
        1. Implementați algoritmul lui Moore pentru un graf orientat neponderat
        (algoritm bazat pe Breath-first search, vezi cursul 2).
        Datele sunt citete din fisierul graf.txt.
        Primul rând din graf.txt conține numărul vârfurilor,
        iar următoarele rânduri conțin muchiile grafului.
        Programul trebuie să afiseze lanțul cel mai scurt dintr-un vârf
        (vârful sursa poate fi citit de la tastatura).
*/


#include <iostream>
#include<fstream>
using namespace std;

ifstream in("date.in");

int i[20], p[20], v[20], q[20], d[20];

int moore(int a[20][20], int n, int u)
{
    int x;
    i[u]=0;
    for(int z=1;z<=n;z++)
        if(z!=u) i[z]=10000;

    q[20]={0}; //coada
    int j=0,nr=0;
    j=1;
    q[++nr]=u; //introducem nodul sursa in coada
    while(j<=nr) //cat timp coada nu e vida
    {
        x=q[j]; //scoatem un element din coada
        for(int z=1;z<=n;z++)
        {
            if(a[x][z]==1) //vecinii
                if(i[z]==10000)
                {
                    p[z]=x;
                    i[z]=i[x]+1;
                    q[++nr]=z; //introducem vecinul in coada
                }
        }
        j++; //scoatem elementul din coada
    }
    for(int z=1;z<=n;z++){
        if(z!=u && i[z]!=10000){
            return 1;
        }
    }
    return 2;
}

void moore_drum(int i[20], int p[20], int dest)
{
    int x, c;
    x=i[dest];
    c=x;
    d[x]=dest;
    while(x)
    {
        d[x-1]=p[d[x]];
        x--;
    }
    cout<<"drumul minim este: ";
    for(int l=0;l<=c;l++)
        cout<<d[l]<<" ";
}


int main(){
    int l,j,k,t[20][20], x,y, n, a[20][20], sursa, destinatie;
    in>>n;
    for(l=1;l<=n;l++)
        for(j=1;j<=n;j++)
            t[l][j]=0;

    //matrica de adiacenta
    for(l=1;l<=n;l++)
        for(j=1;j<=n;j++)
            a[l][j]=0;

    while(in>>x>>y)
    {
        a[x][y]=1;
        a[y][x]=1;
    }

    //cel mai scurt drum
    cout<<"Alege varful de pornire: ";
    cin>>sursa;
    cout<<"Alege varful destinatie: ";
    cin>>destinatie;
    if(sursa<1 || sursa>n || destinatie<1 || destinatie>n){
        cout<<"nu este drum";
    }
    else{
        int varr=moore(a, n, sursa);
        if(varr==1){
            moore_drum(i,p,destinatie);
        }
        else{
            cout<<"Nu exista drum :) ";
        }
    }




    cout<<endl<<endl<<"Matricea de adiacenta: "<<endl<<endl;
    for(l=1;l<=n;l++)
    {
        for(j=1;j<=n;j++)
            cout<<a[l][j]<<" ";
        cout<<endl;
    }

}
