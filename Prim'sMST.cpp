#include <iostream>
#include <vector>
#include <limits.h>
#include <climits>
using namespace std;

bool check_if_queue_empty(int* Q, int n){
    for(int i = 0; i < n; i++){
        if(Q[i] != -1) 
            return false;
  }
    return true;
}

int extract_min(int* Q, int n){
    int min = INT_MAX;
    int u;
    for(int i = 0; i < n; i++){
        if(Q[i] != -1 && Q[i] < min) {
        min = Q[i];
        u = i;
        }
    }
    Q[u] = -1;
    return u;
}

int main() {
    int n,m;
    cin>>n;
    cin>>m;

    vector<vector<pair<int,int>>> G;
    for(int i = 0; i < n; i++){
        vector<pair<int,int>> tmp;
        G.push_back(tmp);
    }

    for(int i = 0; i < m; i++){
        int u,v,w;
        cin>>u;
        cin>>v;
        cin>>w;
        pair<int,int> p1(v,w);
        pair<int,int> p2(u,w);
        G[u].push_back(p1);
        G[v].push_back(p2);
    }

    int* queue = new int[n];
    int* parents = new int[n];
    for(int i = 0; i < n; i++){
        queue[i] = INT_MAX;
    }

    queue[0] = 0;
    //cout<<Q[0]<< " isQ[0] "<<endl;
    int x, y, u;
    //cout<<check_empty(Q, n)<<" is initial queue check"<<endl;
    while(check_if_queue_empty(queue, n)==false){
        u = extract_min(queue, n);
        //cout<<u<< " is u"<<endl;
        for(pair<int,int> p : G[u]){
            x=p.first;
            //cout<<x<<" this is x"<<endl;
            y=p.second;
            //cout<<y<<" this is y"<<endl;
            if(queue[x] != -1 && y < queue[x]){
                parents[x] = u;
                queue[x] = y;
            }
        }
    }

  //prints parents
    for(int i=1; i<n; i++){
      cout<<parents[i]<<endl;
  }

  return 0;
}