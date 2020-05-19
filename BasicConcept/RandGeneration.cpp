#include<iostream>
#include<cstdio>
#include<random>
#include<time.h>
#include<math.h>
using namespace std;
int main()
{
    int n;
    srand((int)time(0));
    cout<<(n=rand()%1000)<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<(int)pow(-1,rand()%100)*rand()<<' ';
    }
    return 0;
}