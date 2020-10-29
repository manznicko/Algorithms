#include <bits/stdc++.h> 
#include <vector>
using namespace std;

void insertionsort(vector<float> arr, int n ){
    int k, j;
    for (int i = 1; i< n; i++){
        k = arr[i];
        j = i-1;
        while (j>=0 && arr[j]>k){
            arr[j+1] = arr[j];
            j=j-1;
            arr[j+1] = k; 
        }
    }
}
void bucketsort(float* A, int n){
    vector<float> b[n];
    int count = 0;

   for(int i = 0; i<n; i++)  {          
      b[int(n*A[i])].push_back(A[i]); //Int cast works as floor function from textbook pseudocode 
   }
    /*insertionsort(b, n);
    for(int j = 0; j<n ; j++){
        cout << b[j] << "\n";
    }*/
     for(int i = 0; i<n; i++) {
      sort(b[i].begin(), b[i].end()); //from std library works same as insertion sort  
   }

   for (int i = 0; i<n; i++){ // loops through array A so each element is re-input
       for (int j = 0; j<b[i].size(); j++){ //takes each sorted element from a bucket that holds an element
           A[count] = b[i][j];
           count++;
       }
   }
}

int main(){
    int x;
    cin >> x;

    float* arr = new float[x];
    for (int i = 0; i<x ; i++){
        cin>>arr[i];
    }

    bucketsort(arr, x);

    for(int j = 0; j<x ; j++){
        cout << arr[j] << "\n";
    }
    //cout << endl;
    return 0;
}
