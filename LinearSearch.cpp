#include <bits/stdc++.h> 
using namespace std;

int linear(int n, int x, int* arr){
   for(int i = 0;i<n; i++){
        if (x == arr[i]){
            return i;
        }
    } 
    return -1;
}
int main(){
    
    int i, n ,x, ans;
    cin >> n;
    cin >> x;


    int* arr = new int[n];
    for (i = 0; i<n; i++){
        cin >> arr[i];
    }

    ans = linear(n,x,arr);
    cout << ans << endl;

    return 0;
}