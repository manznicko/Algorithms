#include <bits/stdc++.h> 
#include <list>
#include <vector>
using namespace std;

int func(int k, int m){ // The hash function
    return (k%m);
}
vector<list<int>> insertKey(vector<list<int>> table, int key){
    table[ func( key, table.size() ) ].push_front(key);
    return table;
}
vector<list<int>> deleteKey(vector<list<int>> table, int key){ //Can use search code to delete once found
    int i = func( key, table.size());
    int found = 0;
    list<int>::iterator j = table[i].begin();
    while(j != table[i].end()){
        if(key == *j){
            found = 1;
            break;
        }
        j++;
    }
    if (found==1){
        table[i].erase(j);
        cout<<key<<" : DELETED"<<endl;
    }else{
        cout<<key<< " : DELETE FAILED"<<endl;
    }
    return table;
}
void searchKey(vector<list<int>> table, int key){
    int i = func(key, table.size());
    int j = 0;
    int found = 0;
    list<int>::iterator k = table[i].begin();    // Could have used vector find function to search but this works so it will stay 
    while (k != table[i].end()){                // Will iterate across the linked list until it is found
        if(key == *k){
            found = 1;
            cout<<key<<" : FOUND AT "<<i<<","<<j<<endl;
            break;                              // Once found it breaks from loop because search is done
        }
        j++;
        k++;
    }
    if (found == 0){                            // Only prints if key is never found
        cout<<key<<" : NOT FOUND"<<endl;
    }
}
void output(vector<list<int>> table){
    for(int i = 0; i<table.size(); i++){
        cout<<i;
        cout<<" : ";
        list<int>::iterator j = table[i].begin();
        while(j!=table[i].end()){
            if(table[i].begin() == j){                //Keeps proper format of output for first element of the bucket
                cout<<*j;
            }else{
                cout<<"->"<<*j;
            }
            j++;
        }
        cout<<endl;
    }
}

int main(){
    int m, n;
    char action;
    cin>>m;

    //initialize Hash table as vector of lists size m
    vector<list<int>> table(m); //Professor Kyrilov used queues in CSE 30

    cin>>action;                //Gets first action
    while (action != 'e'){      // As long as action is not e the other functions will run
        if (action == 'i'){
            cin>>n;
            table = insertKey(table, n);
        }
        else if (action == 'd'){
            cin>>n;
            table = deleteKey(table, n);
            cout<<"++++++++++++++++++++"<<endl;
        }
        else if (action == 's'){
            cin>>n;
            searchKey(table, n);
            cout<<"++++++++++++++++++++"<<endl;
        }
        else {
            output(table);
            cout<<"++++++++++++++++++++"<<endl;
        }
        cin>>action;          // Gets to here after completing the first function and receives the remaining subsequent functions  
    }

    return 1;
}

