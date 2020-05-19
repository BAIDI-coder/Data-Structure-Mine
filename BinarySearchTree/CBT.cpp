/*利用完全二叉树编号的性质--用顺序存储，那么父节点序号*2 = 左儿子序号，
左儿子序号+1 = 右儿子序号。首先用个顺序表（数组）存储目标完全二叉树，
先不管数据域。然后中序遍历该二叉树，便利的过程将排好序的数据填充数据域，
这么做的原理是因为对于任何一颗树其中序遍历输出的结果均为排序序列。*/
#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<algorithm>
#define MAX 20
using namespace std;

typedef int Tree;
int Index = -1;  //中序遍历“迭代器”
int inorder_data[MAX], CBT[MAX];    //中序遍历数据序列，CBT顺序表

void inorder_fill(Tree root, int maxnum)   //中序遍历填充完全二叉树root
{
    if(root > maxnum) return;
    inorder_fill(root * 2, maxnum); //递归遍历左子树
    CBT[root] = inorder_data[++Index];  //数据域填充
    inorder_fill(root * 2 + 1, maxnum); //递归遍历右子树
}

int main()
{    
    int nodes_num = 0;  //结点数
    cin >> nodes_num;
    for(int i = 0;i < nodes_num;i++)
    {
        cin >> inorder_data[i];
    }
    sort(inorder_data, inorder_data + nodes_num);   //左闭右开

    inorder_fill(1, nodes_num);

    for(int i = 1;i < nodes_num + 1;i++)
    {
        cout << CBT[i] << ' ';
    }
    return 0;
}