   
#include <iostream>
#include <cstdio>

#define MaxVolume 1000
using namespace std;

class MinHeap
{
public:
    MinHeap(int sz = MaxVolume);
    MinHeap(int* arr, int n);//通过一个数组建堆
    ~MinHeap()
    {
        delete []heap;
    }
    bool Insert(const int& x);
    bool Remove(int& x);
    bool IsEmpty()const
    {
        return (currentSize == 0) ? true : false;
    }
    void makeEmpty()
    {
        currentSize = 0;
    }
    void PrintHeap();
private:
    int* heap;//存放最小堆元素的数组
    int currentSize;//最小堆中当前元素个数
    int maxHeapSize;//最小堆最多允许元素个数
    void siftDown(int start, int m);//从start到m号结点向下调整成为最小堆
    void siftUp(int start);
    //两个调整函数中j总是指向较小的,i总是指向较大的
};
MinHeap::MinHeap(int sz):heap(0), currentSize(0), maxHeapSize(sz)
{
    maxHeapSize = (MaxVolume > sz) ? sz : MaxVolume;
    heap = new int[maxHeapSize];
    if(heap == NULL)
    {
        cerr << "堆存储分配失败！" << endl;
        exit(1);
    }
    currentSize = 0;
}
MinHeap::MinHeap(int* arr, int n):heap(0), currentSize(0), maxHeapSize(n)
{
    maxHeapSize = (MaxVolume < n) ? n : MaxVolume;//如果容量大于1000，就申请
    //一个更大的
    heap = new int[maxHeapSize];
    if(heap == NULL)
    {
        cerr << "堆存储分配失败！" << endl;
        exit(1);
    }
    for(int i = 0; i < n; i++)
    {
        heap[i] = arr[i];
    }
    currentSize = n;
    int currentPos = (currentSize - 2) / 2;
    while(currentPos >= 0)
    {
        siftDown(currentPos, currentSize - 1);
        currentPos--;
    }
}
bool MinHeap::Insert(const int& x)
{
    if(currentSize == maxHeapSize)//堆满
        return false;
    heap[currentSize] = x;
    siftUp(currentSize);
    currentSize++;
    return true;
}
bool MinHeap::Remove(int& x)
{
    if(currentSize <= 0)
        return false;
    x = heap[0];
    heap[0] = heap[currentSize - 1];
    currentSize--;
    siftDown(0, currentSize - 1);
    return true;
}
void MinHeap::PrintHeap()
{
    if(currentSize > 0)
    {
        int i;
        for(i = 0; i < currentSize - 1; i++)
        {
            printf("%d ", heap[i]);
        }
        printf("%d\n", heap[i]);
    }
}
void MinHeap::siftDown(int start, int m)
{
    int i = start, j = 2 * i + 1;//j为i的左孩子
    int temp = heap[i];
    while(j <= m)
    {
        if(j < m && heap[j] > heap[j + 1])//让j指向i的左右孩子中较小的那一个
            j++;
        if(temp < heap[j])//双亲结点小则不做调整
            break;
        else
        {
            heap[i] = heap[j];//孩子上移，i,j下降一层
            i = j;
            j = 2 * i + 1;
        }
    }
    heap[i] = temp;//回放temp中暂存的元素
}
void MinHeap::siftUp(int start)
{
    int j = start, i = (j - 1) / 2;
    int temp = heap[j];
    while(j > 0)
    {
        if(heap[i] <= temp)//双亲小则不做调整
            break;
        else
        {
            heap[j] = heap[i];
            j = i;
            i = (j - 1) / 2;
        }
        heap[j] = temp;
    }
}
int main()
{
    int n, k, m;
    scanf("%d%d", &n, &k);
    MinHeap firstHeap(n);
    int operate_number, insert_number, i, temp = 0;
    for(i = 0; i < k; i++)
    {
        scanf("%d", &operate_number);
        if(operate_number == 1)
        {
            scanf("%d", &insert_number);
            firstHeap.Insert(insert_number);
            firstHeap.PrintHeap();
        }
        else if(operate_number == -1)
        {
            firstHeap.Remove(temp);
            firstHeap.PrintHeap();
        }
    }
    scanf("%d", &m);
    int* arr = new int[m];
    for(int i = 0; i < m; i++)
    {
        scanf("%d", &arr[i]);
    }
    MinHeap secondHeap(arr, m);
    secondHeap.PrintHeap();
    free(arr);
    return 0;
}