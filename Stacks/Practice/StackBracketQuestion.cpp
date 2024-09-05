//Question- Find whether the Brackets are Unbalanced or Balanced
#include<bits/stdc++.h>
using namespace std;

class node{
public:
    char c;
    node* next;
    node(char s){
        c = s;
        next = NULL;
    }
};

class stack_2{
node*head;
int size;
public:
    stack_2(){
        head=NULL;
        size = 0;
    }

    char pop(){
        if(head==NULL){
            cout<<"Stack_Underflow";
            return '*';
        }
        char x = head->c;
        node*temp = head;
        head = head->next;
        free(temp);
        size--;
        return x;
    }

    void push(char t){
        node * new_node = new node(t);
        new_node ->next = head;
        head = new_node;
        size++;
    }

    bool isempty(){
        return head==NULL;
    }

    int stck_size(){
        return size;
    }

    char get_top(){
        return head->c;
    }

};

int main(){

    string s;
    cin>>s;
    stack_2 st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            st.push(s[i]);
        }
        else{
            if(s[i]==')' && st.get_top()=='('){
                char o = st.pop();
            }
            else if(s[i]=='}' && st.get_top()=='{'){
                char o = st.pop();

            }
            else if(s[i]==']' && st.get_top()=='['){
                char o = st.pop();
            }
        }
    }

    if(st.isempty()){
        cout<<"balanced";
    }
    else cout<<"unbalanced";

}