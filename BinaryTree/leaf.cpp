/*注意iostream的用法！*/
#include<iostream>
#include<cstdio>
#include<queue>
#define MAX 20
#define Null -1
using namespace std;

struct Node{
    int left;
    int right;
}Index[MAX];

int create(void){
    int num = 0, findroot = 0;
    char left, right;
    cin >> num;
    if(!num) return Null;
    for(int i = 0;i < num;i++)
    {
        cin >> left >> right;
        if(left == '-') Index[i].left = Null;
        else{
            Index[i].left = left - '0';
            findroot -= Index[i].left;
        }
        if(right == '-') Index[i].right = Null;
        else{
            Index[i].right = right - '0';
            findroot -= Index[i].right;
        }
        findroot += i;
    }

    return findroot;
}

void findleaves(int root)
{
    if(root == Null){
        cout << "No leaves";
        return;
    }

    queue<int> q;
    q.push(root);
    int cur;

    while(!q.empty()){
        cur = q.front();
        if(Index[cur].left == Null && Index[cur].right == Null){
            cout << cur;
        }
        else{
            if(Index[cur].left != Null) q.push(Index[cur].left);
            if(Index[cur].right != Null) q.push(Index[cur].right);
        }
        q.pop();
    }
}

int main()
{
    int root_of_tree;
    root_of_tree = create();
    findleaves(root_of_tree);
    return 0;
}