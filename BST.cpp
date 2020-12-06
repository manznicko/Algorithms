#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int root){
        data = root;
        left = NULL;
        right = NULL;
    }
};

Node* insertKey(Node* root, int key){
    if(root == NULL){
        root = new Node(key);
        return root;
    }
    else{
        if(key < root->data){
            root->left = insertKey(root->left, key);
        }
        else{
            root->right = insertKey(root->right, key);
        }
    }
    return root;
}
Node* deleteKey(Node* root, int key){
    if (root == NULL){
		return root;
	}
	if (key < root->data )
		root->left = deleteKey(root->left, key); 

	else if (key > root->data)
		root->right = deleteKey(root->right, key);
	
	else{ // If else then node is equal to root.
		if (root->left == NULL){
			struct Node* alt = root->right; 
			return alt; 
		}
		else if (root->right == NULL){
			struct Node* alt = root->left;
			return alt;
		}
		struct Node* minChildNode = root->right;
		while(minChildNode && minChildNode->left != NULL){
			minChildNode = minChildNode->left; 
		}
		root->data = minChildNode->data;
		root->right = deleteKey(root->right, minChildNode->data);

	}
    return root;
}

void preorder(Node* root){
    if(root != NULL){
        cout<<root->data<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(Node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<endl;
    }
}
void inorder(Node* root){
    if (root != NULL){
		inorder(root->left);
		cout << root->data << endl;
		inorder(root->right);
	}
}



int main(){

	struct Node* tree = NULL;
    int key = 0;
    bool work = true;   //this will get the while to work
    
    char pointer[5]; // Collects the line of input where the longest string is of five "post/0"
    while(work == true){
        cin.getline(pointer,5); //collects the string in char array
        string action(pointer); //converts array of char to a full string
        if ( action.substr(0,1) == "e" ){
            break;
        }
        else if(action.substr(0,1) == "i" && action.substr(0,2) != "in"){ //Prevents Insertion running in lace of inorder traversal
            //cout<<"got to i"<<endl;
            key = stoi(action.substr(2,action.size()-1));
            tree = insertKey(tree,key);
        }
        else if(action.substr(0,1) == "d"){
            //cout<<"got to d"<<endl;
            key = stoi(action.substr(2,action.size()-1));
            tree = deleteKey(tree,key);
        }
        else if (action.substr(0,2)=="in") { //Traversals start here down in string length, 2, 3, 4
			inorder(tree);
			cout << "++++++++++++++++++++" << endl;
		}
        else if (action.substr(0,3)=="pre") {
            preorder(tree);
            cout << "++++++++++++++++++++" << endl;
        }
        else if (action.substr(0,4) == "post") {
			postorder(tree);
			cout << "++++++++++++++++++++" << endl;
		}
        
    }   

    return 0;
}