#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<stdbool.h>
#define GUARD_MIN -1e5
using namespace std;

typedef int ElementType;
struct HeapStruct{
    ElementType *data;
    int size;
    int capacity;
};
typedef struct HeapStruct * Heap;

Heap create(int maxcap)
{
    Heap h = (Heap)malloc(sizeof(struct HeapStruct));
    h->capacity = maxcap;
    h->data = (ElementType*)malloc(sizeof(ElementType) * (h->capacity + 1)); //留出“哨兵”位置
    h->size = 0;
    h->data[0] = GUARD_MIN;
    return h;
}
bool isFull(Heap h)
{
    if(h->size == h->capacity) return true;
    else return false; 
}
bool isEmpty(Heap h)
{
    if(h->size == 0) return true;
    else return false;
}
void Insert(ElementType x, Heap h)
{
    if(isFull(h)){
        cout << "Heap is full!" << endl;
        return;
    }
    int tmp = ++h->size;
    for(;h->data[tmp / 2] > x;tmp /= 2) h->data[tmp] = h->data[tmp / 2];//比每次都swap效率高
    h->data[tmp] = x;
}
void HeapPath(int start, Heap h)
{
    for(int i = start;i > 0;i /= 2) cout << h->data[i] << ' ';
    cout << endl;
}
Heap Build(int n)   //构建节点数为n的堆
{
    Heap h = create(n + 10);
    int value;
    for(int i = 0;i < n;i++)
    {
        cin >> value;
        Insert(value, h);
    }
    return h;
}
void Justify(Heap h, int i) //调整堆h中顶为i的子堆（默认该子堆的子堆是小顶堆）
{
    ElementType parent_item = h->data[i];
    int child = i * 2;
    for(;child <= h->size;child *= 2){
        if(h->data[child] > h->data[child + 1]) child++;
        if(h->data[child] < parent_item)
        h->data[child / 2] = h->data[child];
        else break;
    }
    h->data[child / 2] = parent_item;
}//非swap类型比较注意比较对象不变性
Heap Build_plus(int n)  //调整法建立堆
{
    Heap h = create(n + 10);
    for(int i = 1;i <= n;i++)
    {
        cin >> h->data[i];
        h->size++;//不要忘记规模变大
    }
    for(int i = n / 2;i > 0;i--)
    {
        Justify(h, i);  //自下而上调整堆
    }
    return h;
}
void Delete(Heap h)
{
    if(!h->size){
        cout << "Heap is empty!" << endl;
        return;
    }
    h->data[1] = h->data[h->size--];
    Justify(h, 1);
}
int main()
{
    int node_num, path_num, pathstart;
    cin >> node_num >> path_num;
    Heap heap = Build_plus(node_num);
    for(int i = 1;i <= node_num;i++)
    {
        cout << heap->data[i] << ' ';
    }
    cout << endl; //Debug
    for(int i = 1;i <= path_num;i++)
    {
        cin >> pathstart;
        HeapPath(pathstart, heap);
    }
    return 0;
}