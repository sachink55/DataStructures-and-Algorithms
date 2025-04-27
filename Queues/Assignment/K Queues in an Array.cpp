#include<iostream>
using namespace std;

class KQueue
{
    int *front, *rear, *arr, *next;
    int n, k, freeSpot;
public:
    KQueue(int n, int k)
    {
        this->n = n;
        this->k = k;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];

        for (int i = 0; i < k; i++)
            front[i] = -1;

        for (int i = 0; i < n; i++)
            next[i] = i + 1;

        next[n - 1] = -1;
        freeSpot = 0;
    }
    
    //push x into queue number qn
    bool push(int x, int qn)
    {
       //check overflow
        if (freeSpot == -1)
        {
            cout << "Queue Overflow" << endl;
            return false;
        }

        //find first free index
        int index = freeSpot;

        //update freeSpot to next free index
        freeSpot = next[index];
        
        //if this is the first element in the queue
        if (front[qn] == -1)
        {
            front[qn] = index;
        }
        else
        {
            //link the new element to the end of the queue
            next[rear[qn]] = index;
        }
        
        //update next of the new element to -1
        next[index] = -1;

        //update rear of the queue
        rear[qn] = index;

        //push the element into the array
        arr[index] = x;

        return true;
    }

    int pop(int qn)
    {
        //check underflow
        if (front[qn] == -1)
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }

        //get the index of the front element
        int index = front[qn];

        //update front to the next element in the queue
        front[qn] = next[index];

        //update next of the popped element to freeSpot
        next[index] = freeSpot;

        //update freeSpot to the popped element's index
        freeSpot = index;

        return arr[index];  //return the popped element
    }

    ~KQueue()
    {
        delete[] arr;
        delete[] front;
        delete[] rear;
        delete[] next;
    }
};

int main()
{
    int n = 10, k = 3;
    KQueue q(n, k);

    q.push(10, 0);
    q.push(20, 0);
    q.push(30, 1);
    q.push(40, 1);
    q.push(50, 2);
    q.push(60, 2);

    cout << "Popped from queue 0: " << q.pop(0) << endl; 
    cout << "Popped from queue 1: " << q.pop(1) << endl; 
    cout << "Popped from queue 2: " << q.pop(2) << endl;

    return 0;
}
// Output:  
// Popped from queue 0: 10
// Popped from queue 1: 30
// Popped from queue 2: 50

