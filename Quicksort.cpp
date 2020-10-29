#include <bits/stdc++.h>
using namespace std;

int partition(int* arr, int p, int r){
    int n, i;
    n = arr[r];
    i = p-1; 

    for(int j = p; j<r; j++){
        if(arr[j] <= n){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}

int randomPartition (int* arr, int p, int r){
    int i;
    i = p+rand() % (r-p);   // add p so that the number from computation is in at least minumum array range 
    swap(arr[r], arr[i]);   // rand()%(r-p) gives a random pivot within an acceptable range
    return partition(arr, p, r); 
}

void quicksort(int* arr, int p, int r){
    if (p < r){
        int q;
        q = randomPartition(arr, p, r);
        quicksort(arr, p, q-1);
        quicksort(arr, q+1, r);
    }

}
int main(){
    int n;
    cin >> n; 
    int* arr = new int[n];

    for (int j = 0; j<n; j++){
        cin>>arr[j];
    }
    quicksort(arr, 0, n-1);

     for(int i=0; i<n; i++){        
        cout << arr[i] << ";";    
    }
    cout<<endl;
    return 0; 
}