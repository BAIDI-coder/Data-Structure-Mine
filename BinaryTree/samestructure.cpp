/*
除了根节点之外每个节点都只会出现一次，于是找根节点就可以依据这个特性：
累加或累减每次输入的数值，最后减去加上所有的节点编号，结果就是根节点编号！
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <stdbool.h>
using namespace std;

#define MAXCAP 100

typedef struct Node
{
    char data;
    int left;
    int right;
} node;
node tree1[MAXCAP], tree2[MAXCAP];

bool judgement(int r1, int r2);
void scanfind(int& root1, int& root2);

int main()
{
    int root1, root2;
    scanfind(root1, root2);
    judgement(root1, root2) ? cout << "YES" : cout << "NO";
    return 0;
}

void scanfind(int& root1, int& root2)
{
    int num;
    int findroot = 0;

    cin >> num;
    for(int i=0;i<num;i++)
    {
        cin >> tree1[i].data >> tree1[i].left >> tree1[i].right;
        if(tree1[i].left == '-') tree1[i].left = -1;
        else{
            findroot -= tree1[i].left;
        }
        if(tree1[i].right == '-') tree1[i].right = -1;
        else findroot -= tree1[i].right;
    }
    for(int i = 0;i<num;i++){
        findroot += i;
    }
    cout <<endl<< (root1 = findroot);

    findroot = 0;
    cin >> num;
    for(int i=0;i<num;i++)
    {
        cin >> tree2[i].data >> tree2[i].left >> tree2[i].right;
        if(tree2[i].left == '-') tree2[i].left = -1;
        else{
            findroot -= tree2[i].left;
        }
        if(tree2[i].right == '-') tree2[i].right = -1;
        else findroot -= tree2[i].right;
    }
    for(int i = 0;i<num;i++){
        findroot += i;
    }
    cout <<endl<< (root2 = findroot);
}

bool judgement(int r1, int r2)
{
    if(r1 == -1 && r2 == -1) return true;
    if(r1 == -1 && r2 != -1) return false;
    if(r1 != -1 && r2 == -1) return false;
    if(tree1[r1].data != tree2[r2].data) return false; 
    else
    {
        if(judgement(tree1[r1].left,tree2[r2].left) && judgement(tree1[r1].right,tree2[r2].right))
        return true;
        else if(judgement(tree1[r1].right,tree2[r2].left) && judgement(tree1[r1].left,tree2[r2].right))
        return true;
        else return false;
    }
}