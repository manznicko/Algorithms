#include <bits/stdc++.h> 
using namespace std;

void merge(int* arr, int left, int mid, int right){ //where left is the leftmost element of array and right is rightmost    
    int i, j, k, n, m;
    n = mid - left + 1;
    m = right - mid;
    
    int* Ls = new int[n+1];
    int* Rs = new int[n+1];
    
    for(i = 0; i<n; i++){                         //Fill left sub array
        Ls[i] = arr[left+i];
    }
    for(j = 0; j<m; j++){                         //Fill right sub array
        Rs[j] = arr[mid+j+1];
    }
    
    Ls[n] = INT_MAX;                                //Sentinel implemenation TXT pg 31. max int
    Rs[m] = INT_MAX;
    
    i = 0;j = 0;                                    //Zero both sub ararys iterative variable        
    
    for(k = left; k<=right; k++) {                //Sort + merging loop
        if(Ls[i] <= Rs[j]){
            arr[k] = Ls[i];
            i++;
        }
        else{
            arr[k] = Rs[j];
            j++;
        }
    }
    delete[] Ls;
    delete[] Rs;
    
}


void mergesort(int* arr, int left, int right){ // Left leftmost index, Right rightmost index
    if (left < right){
        int mid;
        mid = (left+right)/2;
        mergesort(arr, left, mid);
        mergesort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }

}
int main(){
    int n;
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i<n; i++){
        cin>>arr[i];
    }
    mergesort(arr, 0, n-1);

    for (int i = 0; i<n; i++){      
        cout << arr[i] << ";";
    }
    
    cout << endl;
    
    return 0;
}