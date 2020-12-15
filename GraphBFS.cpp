#include <map>
#include <list>
#include <iostream>
#include <string>
#include <queue>
#include <limits>
#include <climits>
#include <limits.h>

using namespace std;

struct Graph {
    list<string> vertices;
    map<pair<string,string>,int> edges;
    void PrintOut(void);
    void AddEdge(string,string,int);
    bool FindVertex(string);
    int FindEdgeCost(string vert1, string vert2);
    int IsReachable(string vert1, string vert2);
};

void Graph::PrintOut(void) {
    list<string>::iterator it;
    map<pair<string,string>,int>::iterator eit;
    
    for(it=vertices.begin(); it!=vertices.end(); it++) {
        cout << *it << endl;
    }
    
    for(eit = edges.begin(); eit != edges.end(); eit++) {
        cout << (*eit).first.first << " " << (*eit).first.second << " " << (*eit).second << endl;
    }
}

void Graph::AddEdge(string vert1,string vert2,int weight) {
    if(FindVertex(vert1)==true && FindVertex(vert2)==true){
        edges.insert({make_pair(vert1,vert2), weight});
    }
}

bool Graph::FindVertex(string vert1) {
    list<string>::iterator it;
    for(it=vertices.begin(); it!=vertices.end(); it++){
        if(*it == vert1){
            return true;
        }
    }
    return false;
}

int Graph::FindEdgeCost(string vert1, string vert2) {
    map<pair<string,string>,int>::iterator eit;
 
    for(eit = edges.begin(); eit!=edges.end(); eit++){
        if( (*eit).first.first == vert1){
            if((*eit).first.second == vert2){
                return (*eit).second;
            }
        }
    }
    return -1;
}

int Graph::IsReachable(string vert1, string vert2) {//BFS pg 595
    queue<string> queue;
    map<string,string> color; //setup all 3 for each vertex
    map<string,int> distance;
    map<string,string> pi;

    list<string>::iterator vi;
    for(vi=vertices.begin(); vi!=vertices.end(); vi++){
        color[*vi]="white";
        distance[*vi]= INT_MAX; 
        pi[*vi]="NULL";
    }
    color[vert1]="gray";
    distance[vert1]=0;
    queue.push(vert1);
    string u, v;
    map<pair<string,string>,int>::iterator eit;
    while(queue.size()!=0){
        u=queue.front();
        queue.pop();
        for(eit=edges.begin(); eit!=edges.end(); eit++){
            if(u == (*eit).first.first){
                v=(*eit).first.second;
                if(color[v] == "white"){
                    color[v]="gray";
                    distance[v]=distance[u]+1;
                    pi[v]=u;
                    if(distance[vert2]!=INT_MAX){ 
                        return distance[vert2]; 
                    }
                    queue.push(v);
                }
            }
        }
        color[u]="black";
    }

    return -1;
}

int main() {
    Graph G;
    string check;
    cin>>check;
    while(check != "END"){
        G.vertices.push_back(check);
        cin>>check;
        
    }
    string check2;
    int weight;
    cin>>check;
    while(check!="END"){
        cin>>check2;
        cin>>weight;
        G.AddEdge(check, check2, weight);
        cin>>check;
    }
    G.PrintOut();
    int operation;
    cin>>operation;
    while(operation!=0){
        if(operation==1){
            cin>>check;
            if(G.FindVertex(check) == true){
                cout<<1<<endl;
            }else{
                cout<<0<<endl;
            } 
        }
        if(operation == 2){
            cin>>check;
            cin>>check2;
            cout<<G.FindEdgeCost(check,check2)<<endl;
        }
        if(operation == 3){
            cin>>check;
            cin>>check2;
            cout<<G.IsReachable(check,check2)<<endl;
        }
        cin>>operation;
    }


    return 1;
}
