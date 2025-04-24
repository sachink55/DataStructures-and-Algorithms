#include<iostream>
using namespace std;

class NStack {
    int *arr, *top, *next;
    int n; //no. of stacks
    int size; //size of array  
    int freeSpot; //to keep track of the next free spot in the array

public:
    NStack(int N, int S): n(N), size(S) {
        freeSpot = 0; 
        arr = new int[size]; //array to store the elements of stacks
        top = new int[n]; //array to store the top index of each stack
        next = new int[size]; //array to store the next index of each element in the array

        for (int i = 0; i < n; i++) {
            top[i] = -1; //initially all stacks are empty
        }

        for (int i = 0; i < size; i++) {
            next[i] = i + 1; //next[i] points to the next free spot in the array
        }
        next[size - 1] = -1; //last element points to -1 as there is no next free spot
    }

    //push X into stack m
    bool push(int X, int m){
        if(freeSpot == -1) {
           return false; //stack overflow
        }
        int index = freeSpot; //get the index of the free spot

        freeSpot = next[index]; //update the free spot to the next free spot

        arr[index] = X; //store the element in the array
        
        next[index] = top[m - 1]; //update next

        top[m - 1] = index; //update the top of the stack to the new element
        return true; //push successful
    }

    //pop element from mth stack - reverse of push
    int pop(int m){
        if(top[m - 1] == -1) {
            return -1; //stack underflow
        }
        int index = top[m - 1]; //get the index of the top element

        top[m - 1] = next[index]; //update the top of the stack to the next element

        next[index] = freeSpot; //update next to point to the free spot

        freeSpot = index; //update free spot to the popped element

        return arr[index]; //return the popped element
    }

    ~NStack() {
        delete[] arr; 
        delete[] top; 
        delete[] next; 
    }
};

int main(){
    NStack ns(3, 9); //3 stacks and size of array is 9
    cout << ns.push(10, 1) << endl; 
    cout << ns.push(20, 2) << endl;
    cout << ns.push(30, 3) << endl;
    cout << ns.push(40, 1) << endl;
    cout << ns.push(50, 2) << endl;
    cout << ns.push(60, 3) << endl;
    cout << ns.pop(1) << endl; //40
    cout << ns.pop(2) << endl; //50
    cout << ns.pop(3) << endl; //60
   
    return 0;
}