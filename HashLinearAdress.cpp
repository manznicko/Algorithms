//Program is fixed at table of size 13
#include <bits/stdc++.h> 
#include <list>
#include <vector>
using namespace std;

int F1(int key){
    return (key%13);
}
int F2(int key){
    return (1 + (key%11));
}
int hashFunc(int key, int index){
    int value;
    value = (F1(key) + index*F2(key)) % 13;
    return value; 

}

vector<int> insertkey(vector<int> list, int key, int index){
    //list[ F1(key)] = key;
    if(list[F1(key)]<0){
        list[F1(key)] = key; 
    }else{
        //list[hashFunc(key, index)] = key;
        for(int i=1; i<13; i++){
            if (list[hashFunc(key, i)] < 0){
                list[hashFunc(key, i)] = key;
                break;
            }
        }
    }
    return list;
}
vector<int> deletekey(vector<int> list, int key){
    int i=0;
    while(i<13){
        if(key == list[i]){
            list[i]=-1;
        }
        i++;
    }

    return list;
}

void output(vector<int> list){
    for(int i = 0; i<list.size(); i++){
        if(list[i]<0){
            cout<<" "<<endl;
        }else
            cout<<list[i]<<endl;
    }

}

void searchkey(vector<int> list, int key){
    int found, i;
    i = 0;
    found = 0;
    while(i<13){
        if(key == list[i]){
            found = 1;
            cout<<i<<endl;
        }
        i++;
    }
    if(found == 0){
        cout<<"NOT_FOUND"<<endl;
    }
    

}

int main(){
    int val, counter, check;
    check = -4;
    vector<int> table(13,-1);
    

    counter = 0; 
    while(check <= -1){
        cin >> val;
        if(val < 0){
            check = val;
            counter = 0;
        }
        if (check == -4){
            table = insertkey(table, val, counter);
            counter++;
        }

        if (check == -1 && val!=-1){
            if(counter == 0 ){
                cout<<"++++table printout++++"<<endl;
                output(table);
                cout<<"++++searching++++"<<endl;
            }
            searchkey(table, val);
            counter++;
        }
        if (check == -2){
            if(counter == 0){
                cout<<"++++deleting++++"<<endl;
            }
            table = deletekey(table, val);
            counter++;
        }
        if (check == -3){
            cout<<"++++table printout++++"<<endl;
            output(table);
            break;
        }
    
    }


    return 0;
}