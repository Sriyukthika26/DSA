#include<bits/stdc++.h>
using namespace std;

class deque_arr{
    int *arr;
    int front;
    int rear;
    int size;
public:
    deque_arr(int n){
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    void push_front(int x){
        if((rear+1)%size == front){
            cout<<"Overflow";
            return;
        }
        else if(front == -1){
            front = rear = 0;
        }
        else if(front == 0){
            front = size-1;
        }
        else front--;

        arr[front]= x;
    }

    void push_rear(int x){
        if((rear+1)%size==front){
            cout<<"Overflow";
            return;
        }
        else if(rear==-1){
            front = rear = 0;
        }
        else{
            rear = (rear+1)%size;
        }
        arr[rear]=x;
    }
};

int main(){

}