//分治法
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define MAX 1000
using namespace std;
//int divide(int* arr,int size);//分治法复杂度O（nlogn）
int greed(int *arr,int n)
{
    int maxamt=0;
    for(int i=0,amt=0;i<n;i++)
    {
        amt+=arr[i];
        if(amt<0) amt=0;
        else if(amt>maxamt) maxamt=amt; 
    }
    return maxamt;
}//在线处理（贪心算法）复杂度O（n）
int main()
{
    int n,maxamt;
    int arr[MAX];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    //maxamt=divide(arr,n);
    maxamt=greed(arr,n);
    cout<<maxamt;
    return 0;
}
/*int divide(int* arr, int size)
{
    if(size==1)
    {
        if(*arr<0) return 0;
        else return *arr;
    }
    else if(size==0) return 0;
    else if(size==2) return max(max(arr[0],arr[1]),arr[0]+arr[1]); 
    else
    {
        int mid=size/2;
        int maxright=divide(&arr[mid],size-mid);
        int maxleft=divide(arr,mid);
        int max_midleft=0,max_midright=0,maxmid=0;
        for(int i=mid+1,amt=0;i<size;i++)
        {
            amt+=arr[i];
            if(max_midright<amt) max_midright=amt;
        }
        for(int i=mid-1,amt=0;i>=0;i--)
        {
            amt+=arr[i];
            if(max_midleft<amt) max_midleft=amt;
        }
        maxmid=max_midleft+max_midright+arr[mid];
        return max(max(maxright,maxleft),maxmid);
    }
    
}*/