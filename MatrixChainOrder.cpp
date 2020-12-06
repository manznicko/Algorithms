#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

void printOptimal(vector<vector<int>> arr, int i, int j){
    if(i == j){
        cout<<"A"<<(--i);
    }else{
        cout<<"(";
        printOptimal(arr, i, arr[i][j]);
        printOptimal(arr, arr[i][j] +1, j);
        cout<<")";
    }
}

void Matrix_Chain_Order(int* p, int len){
    int i, j, l, k, q;
    vector<vector<int>> m;
    vector<vector<int>> s;
    m.resize(len+1, vector<int>(len+1,0));
    s.resize(len+1, vector<int>(len+1,0));

    for (i=1; i<=len; i++){
        m[i][i] = 0;
    }
    for(l=2; l<=len; l++){
        for(i=1; i<=len-l+1; i++){
            j = i+l-1;
            m[i][j] = INT_MAX; 
            for(k=i; k<=j-1; k++){
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout<<m[1][len]<<endl;
    printOptimal(s,1,len);
}

int main(){
    int n;
    cin>>n;
    int p[n+1];

    for(int i = 0; i<=n; i++ ){
        cin>>p[i];
    } 

    Matrix_Chain_Order(p,n);

    return 0;
}