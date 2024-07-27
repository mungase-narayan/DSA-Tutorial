#include <iostream>
using namespace std;
class Heap
{
public:
    int *arr;
    int size;
    int capacity;

    Heap(int capacity)
    {
        this->arr = new int[capacity];
        this->capacity = capacity;
        this->size = 0;
    }
    void insert(int val)
    {
        if (size == capacity)
        {
            cout << "Heap Overflow :" << endl;
            return;
        }
        size++;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int ParentIndex = index / 2;
            if (arr[index] > arr[ParentIndex])
            {
                swap(arr[index], arr[ParentIndex]);
                index = ParentIndex;
            }
            else
            {
                break;
            }
        }
    }
    void PrintHeap()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Heap h(20);
    h.insert(10);
    h.insert(20);
    h.insert(5);
    h.insert(11);
    h.insert(6);

    cout << "Printing the content of heap :" << endl;
    h.PrintHeap();
    return 0;
}