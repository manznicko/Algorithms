#include <bits/stdc++.h> 
using namespace std;

int main() {
    int n, k,j;
    cin >> n;

    //new keyword
    // how to read
    int* arr = new int[n];
    for (int i = 0; i<n; i++){
        cin >>arr[i];
    }

    //Implementation 
    for (int i = 1; i < n; i++){
        k = arr[i];             //saves key
        j = i-1;                //2nd itterative var  

        while (j>=0 && arr[j]>k){
            arr[j+1] = arr[j];
            j = j-1;
            arr[j+1] = k;

        }
    }

    // how to output
    for (int i = (n-1) ; i>=0; i--)
        cout << arr[i] << ";";
return 0;
}