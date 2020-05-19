#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main()
{
    int n,first=0,last;
    int *arr;
    cin>>n;
    int maxamt=-1;
    if(!(arr=(int*)malloc(sizeof(int)*n))) fprintf(stderr,"error");
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0,amt=0,temp=0;i<n;i++)
    {
        amt+=arr[i];
        if(amt>maxamt)
        {
            maxamt=amt;
            last=i;
            first=temp;
        }
        else if(amt<0)
        {
            amt=0;
            temp=i+1;
        }
    }
    cout<<maxamt<<endl<<"first num: "<<first+1<<endl<<"last num: "<<last+1;
    return 0;
}