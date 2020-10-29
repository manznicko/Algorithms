#include <bits/stdc++.h> 
using namespace std;


int maxHeapify(int* arr, int n, int x){
    int largest, l, r;
    largest = x;
    l = 2*x;   //the left child of the node at index x's child is equal to 2*x
    r = 2*x+1; //^^ but 2*x +1
    if(l < n && arr[l] > arr[x] ){
        largest = l;
    } else
        largest = x;
    
    if(r < n && arr[r] > arr[largest]){
        largest = r;
    }
    if(largest != x){
        swap(arr[x], arr[largest]);
        maxHeapify(arr, n, largest);
    }
    
    return 0;
}

int buildMaxHeap(int* arr, int n ){
    int half;
    half = n/2 -1;
    for (int i = half; i>=0; i--){
        maxHeapify(arr, n, i);
    }
    return 0;
}


int heapsort(int* arr, int n){
    //int temp;
    buildMaxHeap(arr, n);
    for (int i = (n-1); i>=0; i--  ){
        //temp = arr[0];
        //arr[0] = arr[i];
        //arr[i] = temp; 
        swap(arr[0],arr[i]);
        n--;
        maxHeapify(arr, n, 0);
    }
    return 0;
}

int main(){
    int n;
    cin>>n;
    int* arr = new int[n];
    for (int i = 0; i<n; i++){
        cin >> arr[i];
    }
    
    heapsort(arr, n);

    for(int i=0; i<n; i++){
        cout << arr[i] << ";";
    }
    cout << endl ;
    return 0;
}