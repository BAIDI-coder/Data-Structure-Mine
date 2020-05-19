#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<queue>
#include<stdbool.h>
#include<algorithm>
#include<string.h>
using namespace std;
int p_list[20];
char* codes[20];
bool compare(char *str1, char *str2)
{
    return strlen(str1) < strlen(str2);
}
bool isPreffix(char * str[], int n)   //判断一种编码方案是否为前缀码
{
    char * copy[n + 5];
    for(int i = 0;i < n;i++)
    {
        copy[i] = str[i];
    }
    sort(copy, copy + n, compare); 
    for(int i = 0;i < n - 1;i++)
    {
        for(int j = i + 1;j < n;j++){
            if(strstr(copy[j], copy[i]) == copy[j]) return true;
        }
    }
    return false;
}
int Length(char * codes[], int power[], int n)
{
    int len = 0;
    for(int i = 0;i < n;i++)
    {
        len += strlen(codes[i]) * power[i];
    }
    return len;
}
int getWPL(int n)   //得到WPL
{
    char ch;
    int power, WPL = 0;
    priority_queue<int,vector<int>,greater<int> > q;//小顶堆优先队列
    for(int i = 0;i < n;i++)
    {
        cin >> ch >> power;
        q.push(power);
        p_list[i] = power;
    }
    while (q.size() > 1)
    {
        int tmp = q.top();
        q.pop();
        tmp += q.top();
        q.pop();
        q.push(tmp);
        WPL += tmp;
    }
    return WPL;
}
int main()
{
    int num;
    cin >> num;
    int WPL = getWPL(num);
    int casenum;
    cin >> casenum;
    char ch;
    for(int j = 0;j < 20;j++)
    codes[j] = (char*)malloc(sizeof(char) * 20);
    for(int i = 0;i < casenum;i++)
    {
        for(int j = 0;j < num;j++)
        {
            cin >> ch >> codes[j];
        }
        if(isPreffix(codes, num)){
            cout << "NO" << endl;
            continue;
        }
        else{
            if(Length(codes, p_list, num) == WPL) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}