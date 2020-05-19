#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include"BST.h"
using namespace std;

BinTree create()
{
    BinTree t = (BinTree)malloc(sizeof(struct TNode));
    t->Left = NULL;
    t->Right = NULL;
    return t;
}
BinTree Insert( BinTree BST, ElementType X )
{
    if(BST == NULL){
        BinTree tmp = create();
        tmp->Data = X;
        return tmp;
    }
    if(X < BST->Data){
        BST->Left = Insert(BST->Left, X);
    }
    else BST->Right = Insert(BST->Right, X);
    return BST;
}
BinTree Delete( BinTree BST, ElementType X )
{
    if(BST == NULL) return NULL;
    if(BST->Data == X){
        if(!BST->Left && !BST->Right){
            free(BST);
            return NULL;
        }
        if(BST->Left && BST->Right){
            Position rightmin_node = FindMin(BST->Right);
            BST->Data = rightmin_node->Data;    //右子树最小值替换根节点数据域
            BST->Right = Delete(BST->Right, rightmin_node->Data);    //删除右子树最小值节点
        }
        else if(BST->Left){
            BinTree tmp = BST->Left;
            free(BST);
            BST = tmp;
        }
        else if(BST->Right){
            BinTree tmp = BST->Right;
            free(BST);
            BST = tmp;
        }
    }
    if(X < BST->Data) BST->Left = Delete(BST->Left, X);
    else BST->Right = Delete(BST->Right, X);
    return BST;
}
Position Find( BinTree BST, ElementType X )
{
    if(BST == NULL) return NULL;
    if(X == BST->Data) return BST;
    if(X < BST->Data) return Find(BST->Left, X);
    else return Find(BST->Right, X);
}
Position FindMin( BinTree BST )
{
    if(BST == NULL) return NULL;
    if(BST->Left == NULL) return BST;
    else return FindMin(BST->Left);
}
Position FindMax( BinTree BST )
{
    if(BST == NULL) return NULL;
    if(BST->Right == NULL) return BST;
    else return FindMax(BST->Right);
}