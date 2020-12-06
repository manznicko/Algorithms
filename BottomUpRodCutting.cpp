#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void PrintCutRodSolution(int* r, int* s, int n){
    int e = -1;
    cout<<r[n]<<endl; //Max revenue is r[n]
    while (n>0){
        cout<<s[n]<<" ";
        n= n-s[n];
    } 
    cout<<e<<endl;
}

void ExtendedBottomUpCutRod(int* p, int n){
    int* r = new int[n+1];
    int* s = new int[n+1];
    r[0]=0;
    int q = INT_MIN; 

    for(int j=1;j<n;j++){
        q = INT_MIN;
        for(int i=1;i<=j;i++){
            if(q < p[i]+r[j-i]){
                q = p[i]+r[j-i];
                s[j]=i;
            }
        }
        r[j] = q;
    }
    PrintCutRodSolution(r,s,n-1); //Prints values of r and s after being calculated in the algorithm above
}

int main(){
    int n;
    cin>>n;
    int* p = new int[n+1];
    p[0] = 0;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    ExtendedBottomUpCutRod(p,n+1);
    return 0;
}