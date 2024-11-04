#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    int heapsize;
    int maxsize;
public:
    int *arr;
    MaxHeap(int maxsize){
        maxsize = maxsize;
        heapsize=0;
        arr = new int [maxsize];
    }

    int parent(int i){
        return (i-1)/2;
    }
    int lchild(int i){
        return 2*i+1;
    }
    int rchild(int i){
        return 2*i+2;
    }
    int getsize(){
        return heapsize;
    }
    int getmax(){
        return arr[0];
    }

    void upheapify(int i){                //down to up-- up heap
        while(i!=0 && arr[parent(i)]<arr[i]){
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    void insert(int key){
        if(heapsize==maxsize){
            cout<<"Overflow\n";
            return;
        }
        heapsize++;
        int i=heapsize-1;
        arr[i] = key;
        upheapify(i);
    }

    void print(){
        for (int i = 0; i < heapsize; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }

    void maxheapify(int i){    // up to down-downheap
        int l = lchild(i);
        int r = rchild(i);
        int largest = i;
        if(l<heapsize && arr[l]>arr[i]) largest = l;
        if(r<heapsize && arr[r]>arr[largest]) largest = r;
        if(largest!=i){
            swap(arr[i], arr[largest]);
            maxheapify(largest);
        }
    }

    void increasekey(int i, int new_value){
        arr[i] = new_value;
        upheapify(i);
    }


    int extractmax(){
        if(heapsize<=0) return INT_MIN;
        if(heapsize==1){
            heapsize--;
            return arr[0];
        }
        int maxi = arr[0];
        swap(arr[0], arr[heapsize-1]);
        heapsize--;
        maxheapify(0);

        return maxi;
    }

    void deletekey(int i){
        increasekey(i,INT_MAX);
        extractmax();
    }
};
    void heapssort(MaxHeap mh){

        int n = mh.getsize();
        while(mh.getsize()>1){
            mh.extractmax();
        }

        for(int i=0;i<n;i++) cout<<mh.arr[i]<<" ";
    }

int main(){
    MaxHeap mh(15);
    mh.insert(3);
    mh.insert(2);
    mh.insert(5);
    mh.insert(7);
    mh.insert(6);
    mh.insert(1);

    mh.print();
    // cout<<mh.getmax()<<"\n";
    // cout<<mh.getsize()<<"\n";

    // cout<<mh.extractmax()<<"\n";
    // mh.print();

    // mh.increasekey(2,9);
    // mh.print();

    // mh.deletekey(2);
    // mh.print();

    heapssort(mh);

}