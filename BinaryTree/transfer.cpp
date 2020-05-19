/*二叉树的中序后序递归非递归遍历掌握
push时代表加入新节点（当上一个操作为pop时代表该节点为当前节点的右节点，否则说明为左节点）pop代表回到栈顶节点
*/
#include<iostream>
#include<cstdio>
#include<stack>
#include<malloc.h>
#include<string.h>
#include<stack>
#define MAX 10
using namespace std;

typedef struct Node *tree;
struct Node{
    char data;
    tree left;
    tree right;
};

tree create(void)
{
    tree ptr = (tree)malloc(sizeof(struct Node));
    ptr->left = NULL;
    ptr->right = NULL;
    return ptr;
}
void postorder(tree root)
{
    if(root == NULL) return;
    if(root->left != NULL) postorder(root->left);
    if(root->right != NULL) postorder(root->right);
    cout << root->data << ' ';
}
tree restore(void)
{
    int num;
    cin >> num;
    char str[MAX];
    gets(str);
    char value = str[5];
    tree cur = create();
    cur->data = value;
    tree root = cur;
    stack<tree> s;
    s.push(cur);//根节点创建&入栈
    int flag = 0;//0代表push前一个操作为push,1表示前一个操作为pop
    for(int i = 1;i < 2*num ;i++)
    {
        gets(str);
        if(strcmp(str,"Pop") == 0){
            cur = s.top();
            s.pop();
            flag = 1;
        }
        else{
            value = str[5];
            tree tmp = create();
            tmp->data = value;
            if(flag == 0) cur->left = tmp,cur = cur->left;
            else cur->right = tmp,cur = cur->right;
            s.push(cur);
            flag = 0;
        }
    }
    return root;    
}

int main()
{
    tree root;
    root = restore();
    postorder(root);
    return 0;
}