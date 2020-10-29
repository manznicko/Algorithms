#include <bits/stdc++.h> 
using namespace std;
#include <vector>

vector<vector<int>> countingsort(vector<vector<int>> A, int radix, int k){ // radix is the column
    vector<int> C(k,0);                                     // mimics first for loop where C arr is set to 0 from pseudocode
    vector<vector<int>> B (A.size(), vector<int> (k));      //2d Vector B to be returned
    vector<int> column(A.size(), 0);                        //column of A to be sorted

    for(int i = 0; i<A.size(); i++)
        column[i] = A[i][radix];
    for(int j = 0; j<column.size(); j++)
        C[column[j]] = C[column[j]]+1;
    for( int i = 1; i<k; i++)
        C[i] = C[i] + C[i-1];
    for(int j = A.size()-1; j>=0; j--) {
        B[C[column[j]]-1]=A[j];                             //Sets B to the elements in A in sorted order
        C[column[j]] = C[column[j]]-1;                      //Decrement count C
    }
    return B;
}


vector<vector<int>> radixsort(vector<vector<int>> vec, int x){
    for(int i = (x-1); i>=0; i--){  //Have to work outer digits and move inward 
        vec = countingsort(vec, i, x);
    }
    return vec;
}

int main(){ 
    int x, y, input;
    x=10;
    cin >> y;
    vector<vector<int>> vec(y, vector<int> (x));

    for(int i = 0; i<y; i++) {
        for(int j = 0; j<x; j++) {
            cin >> input;
            vec[i][j] = input;
        }
    }

    vec = radixsort(vec, x);

    for(int i = 0; i < y; i++){
        for (int j = 0; j < x; j++){
            cout << vec[i][j] << ";";
        }
        cout << endl;
    }


    return 1;
}