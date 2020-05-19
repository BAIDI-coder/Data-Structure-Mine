#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<queue>
using namespace std;

typedef struct Node * Tree;
struct Node{
    int flag;
    int data;
    Tree left;
    Tree right;
};

void SequenceTravel(Tree root)
{
    if(root == NULL) return;
    queue<Tree> q;
    q.push(root);
    Tree cur;
    while(!q.empty()){
        cur = q.front();
        cout << ' ' << cur->data;
        if(cur->left) q.push(cur->left);
        if(cur->right) q.push(cur->right);
        q.pop();
    }
}

Tree create()
{
    Tree node = (Tree)malloc(sizeof(struct Node));
    node->flag = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}
int check(int item, Tree root) //如果item插入root的顺序不正确则返回0否则返回1
{
    if(root == NULL) return 0;
    if(item == root->data){
        if(root->flag != 0) return 0;
        else{
            root->flag = 1;
            return 1;
        }
    }
    else if(item < root->data){
        if(root->flag == 0) return 0;
        else{
            return check(item, root->left);
        }
    }
    else if(item > root->data){
        if(root->flag == 0) return 0;
        else{
            return check(item, root->right);
        }
    }
}
void reset(Tree root)   //将标准搜索树的flag清零
{
    if(root == NULL) return ;
    root->flag = 0;
    reset(root->left);
    reset(root->right);
    return ;
}
Tree build(int n)    //读入一棵节点数为n的标准搜索树
{
    if(n == 0) return NULL;
    int value;
    cin >> value;
    Tree cur = create();
    cur->data = value;
    Tree root = cur;
    for(int i = 0;i < n - 1;i++){
        cin >> value;
        while(1)
        {
        if(value < cur->data){
            if(cur->left == NULL){
                cur->left = create();
                cur->left->data = value;
                cur = root;
                break;
            }
            else cur = cur->left;
        }
        else{
            if(cur->right == NULL){
                cur->right = create();
                cur->right->data = value;
                cur = root;
                break;
            }
            else cur = cur->right;
        }
        }
    }
    return root;
}
void onegame(int m, int n)  //m = 比较的树的数目,n = 一棵树的结点数
{
    Tree stdTree = build(n);
    for(int i = 0;i < m;i++)
    {
        int value, flag = 1;
        reset(stdTree);
        for(int j = 0;j < n;j++){
            cin >> value;
            if(flag && check(value, stdTree)) continue;
            else{
                flag = 0;continue;
            }
        }
        if(flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }   
}
int main()
{
    int m, n;
    cin >> n;
    while (n)
    {
        cin >> m;
        onegame(m, n);
        cin >> n;
    }
    return 0;
}