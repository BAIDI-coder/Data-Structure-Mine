#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<algorithm>
using namespace std;

typedef struct Node * Tree;
struct Node{
    Tree left;
    Tree right;
    int data;
    int height;
};

Tree create()
{
    Tree t = (Tree)malloc(sizeof(struct Node));
    t->height = 0;
    t->left = NULL;
    t->right = NULL;
}
int getHeight(Tree t)
{
    if(t == NULL) return -1;
    else return t->height;
}
Tree RRrotation(Tree A)
{
    Tree B = A->right;
    A->right = B->left;
    B->left = A;
    A->height = max(getHeight(A->left), getHeight(A->right)) + 1;
    B->height = max(getHeight(A), getHeight(B->right)) + 1;
    return B;
}
Tree LLrotation(Tree A)
{
    Tree B = A->left;
    A->left = B->right;
    B->right = A;
    A->height = max(getHeight(A->left), getHeight(A->right)) + 1;
    B->height = max(getHeight(B->left), getHeight(A)) + 1;
    return B;
}
Tree RLrotation(Tree A)
{
    A->right = LLrotation(A->right);
    return RRrotation(A);
}
Tree LRrotation(Tree A)
{
    A->left = RRrotation(A->left);
    return LLrotation(A);
}
Tree Insert(int value, Tree root)   //将value值插入BTS root中,返回插入后新BTS的地址
{
    if(!root){
        Tree leaf = create();
        leaf->data = value;
        return leaf;
    }
    if(value < root->data){
        root->left = Insert(value, root->left);
        if(getHeight(root->left) - getHeight(root->right) > 1){
            if(root->left->left) root = LLrotation(root);
            else root = LRrotation(root);
        } 
    }
    else{
        root->right = Insert(value, root->right);
        if(getHeight(root->right) - getHeight(root->left) > 1){
            if(root->right->right) root = RRrotation(root);
            else root = RLrotation(root);
        }
    }
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    //更新root树的高度
    return root;
}

int main()
{
    int n, value;
    Tree AVL = NULL;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        cin >> value;
        AVL = Insert(value, AVL);
    }
    cout << AVL->data;
    return 0;
}