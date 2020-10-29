#include <bits/stdc++.h> 
using namespace std;

int findMaxCrossingSubArray(int* arr, int low, int mid, int high){
    int leftsum, rightsum, sum; // maxright, maxleft;
    leftsum = INT_MIN;rightsum = INT_MIN;sum = 0; //maxright=0; maxleft=0; 

    for (int i=mid; i>=low;i--){
        sum = sum + arr[i];
        if (sum>leftsum){
            leftsum = sum;
            //maxleft =i when want idices
        }
    }
    sum = 0;
    for(int i=mid+1; i <= high; i++){
        sum = sum + arr[i];
        if (sum>rightsum){
            rightsum = sum;
            //maxright =i when want indices
        }
    }

    return leftsum+rightsum;
}
int findMaxSubArray(int* arr, int low, int high){
    if (low == high)
        return arr[low];
    else{
    
        int mid = (low+high)/2 ;
        int leftsum, rightsum, crosssum;
        
        leftsum = findMaxSubArray(arr, low, mid);
        rightsum = findMaxSubArray(arr, mid+1, high);
        crosssum = findMaxCrossingSubArray(arr, low, mid, high);

        if (leftsum>=rightsum && leftsum>=crosssum)
            return leftsum;
        else if (rightsum>=leftsum && rightsum>=crosssum)
            return rightsum;
        else
            return crosssum;

    }
    return 0;
}
int main(){
    int n, x;   
    cin >> n;
    int* ar = new int[n];
    for (int i = 0; i<n; i++){
        cin >> ar[i];
    }
    x = findMaxSubArray(ar, 0, n-1);
    cout << x;
    cout << endl;
    return 1;
}