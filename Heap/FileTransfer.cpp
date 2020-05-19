#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<stdbool.h>
#define SET_CAPACITY 100
using namespace std;
typedef int ElementType;
struct SetType{
    ElementType data;
    int parent;
};
typedef struct SetType* Set;
Set create(int n)  //生成总容量为n的集合的集合
{
    Set SetSet = (Set)malloc(sizeof(struct SetType) * (n + 5));
    for(int i = 1;i <= n;i++)
    {
        SetSet[i].parent = -1;
    }
    return SetSet;
}
void merge(Set s, int a, int b)
{
    for(;s[a].parent >= 0;a = s[a].parent);
    for(;s[b].parent >= 0;b = s[b].parent); //找祖先
    if(s[a].parent < s[b].parent){  //按轶合并
        s[a].parent += s[b].parent; //规模合并
        s[b].parent = a;    //合成一棵树
    }
    else{
        s[b].parent += s[a].parent;
        s[a].parent = b;
    }
}   //非路径压缩做法，会使树高增大，效率变低
bool isSameSet(Set s, int a, int b)
{
    for(;s[a].parent >= 0;a = s[a].parent);
    for(;s[b].parent >= 0;b = s[b].parent);
    if(a == b) return true;
    else return false;
}   //非路径压缩做法，会使树高增大，效率变低
//路径压缩
int Find(Set s, int x)  //集合s中寻找x节点的祖先节点，并且沿路压缩路径
{
    if(s[x].parent < 0) return x;
    else return s[x].parent = Find(s, s[x].parent);
}
void Union(Set s, int a, int b)
{
    int a_parent = Find(s, a);
    int b_parent = Find(s, b);
    if()
}
bool isSameSet_plus(Set s, int a, int b)
{
    if(s[a].parent == s[b].parent) return true;
    else return false;
}
int main()
{
    int amt;
    cin >> amt;
    Set allset = create(amt);
    char cmd[5];
    int value1, value2;
    while (1)
    {
        cin >> cmd;
        if(cmd[0] == 'I'){
            cin >> value1 >> value2;
            merge(allset, value1, value2);
        }
        else if(cmd[0] == 'C'){
            cin >> value1 >> value2;
            if(isSameSet(allset, value1, value2)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else{
            break;
        }
    }
    int num = 0;    //Set中集合的数目
    for(int i = 1;i <= 5;i++)
    {
        if(allset[i].parent < 0) num++;
    }
    if(num == 1) cout << "the network is connected.";
    else cout << "there are " << num << " components."; 
    return 0;
}