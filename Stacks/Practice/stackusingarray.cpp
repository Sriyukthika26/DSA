//Implementation of Stack Using Array
#include<bits/stdc++.h>
using namespace std;

class Stack{
    int capacity;
    int * arr;
    int top;
    public:
    Stack(int c){
        this->capacity =c;
        arr = new int[c];
        this->top = -1;
    }

    void push(int data){
        if(this->top == this-> capacity-1){
            cout<<"Stack Overflow";
            return;
        }
        this->top++;
        this->arr[this->top]= data;
    }

    int pop(){
        if(this->top == -1){
            cout<<"stack Underflow";
            return INT_MIN;
        }
        this->top--;
        return this->arr[top+1];
    }

    int gettop(){
        if(this->top == -1){
            cout<<"Stack underflow";
            return INT_MIN;
        }
        return this->arr[this->top];
    }

    bool isempty(){
        return this->top == -1;
    }
    bool isfull(){
        return this->top == this->capacity-1;
    }
    int size(){
        return this->top+1;
    }

};
int main(){
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(5);
    cout<<st.gettop()<<"\n";
    st.push(8);
    st.push(9);
    st.pop();
    st.pop();
    st.pop();
    cout<<st.gettop()<<"\n";

}