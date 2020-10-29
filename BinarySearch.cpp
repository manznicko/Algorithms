#include <bits/stdc++.h> 
using namespace std;

int bsearch(int* arr, int x, int b, int t){
    int mid = (t+b)/2;
    if (t >= b){
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            return bsearch(arr, x, b, mid-1);
        else
            return bsearch(arr, x, mid+1, t );
    }
    return -1;
}

int main(){
    int n, x, ans;
    cin >> n;
    cin >> x;
   
   
    int* arr = new int[n];
    for ( int i =0; i<n ; i++){
        cin >> arr[i];
    }
    ans = bsearch(arr, x, 0, n);

    cout << ans << endl;


    return 0; 
}