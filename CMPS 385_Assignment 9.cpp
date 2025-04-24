// CMPS 385_Assignment 9.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
const int maxn=3;
struct Node {
	bool isLeaf;
	vector<int> keys;
	vector<Node*>children;
	Node* next;
	
	Node(bool leaf) : isLeaf( leaf), next(nullptr) {}

};

class Btree {

public:
	Btree() 
	{
		root = new Node(true);
	}
	void insert( int key) {

		if (root->keys.size() == maxn)
		{
			Node* newRoot = new Node( false);
			newRoot->children.push_back(root) ;
			
        splitChild( newRoot, 0);
			root = newRoot;


		}move(root, key) ;

	}
	void print() {
		Node* curr = root;
while ( !curr->isLeaf) curr = curr->children[0];

		while (curr) {
			for (int k : curr->keys) cout << k << " ";
			curr = curr->next;
		}
		
        
        cout  << endl;
	}

    Node* root;

    void move(Node* node, int key) {
        if ( node->isLeaf) {
            auto pos = upper_bound(node->keys.begin(), node->keys.end(), key) ;
          
            node->keys.insert(pos, key);
        }
        else {
            int i = 0;
            while (i < node->keys.size() && key > node->keys[i]) i++;
            if (node->children[i]->keys.size() == maxn )  {
      splitChild(node, i);
                if (key > node->keys[i]) i++;
            }
            move(node->children[i], key);
        }
    }

    void splitChild( Node* parent, int i) {
        Node* full = parent->children[i];
        Node* newLeaf = new Node(full->isLeaf);
       
        int mid = maxn / 2;

        newLeaf->keys.assign(full->keys.begin() + mid, full->keys.end()) ;
       
        
        full->keys.resize(mid);

        if (!full->isLeaf) {
                newLeaf->children.assign(full->children.begin() + mid + 1, full->children.end());
            full->children.resize(mid + 1);
        }
        else {
            newLeaf->next = full->next;
                 full->next = newLeaf;
        }

  parent->keys.insert(parent->keys.begin() + i, newLeaf->keys[0]);
       
  
  parent->children.insert(parent->children.begin() + i + 1, newLeaf);
    
    }
};

int main() {
    Btree tree;
    for (int key : {11 , 27, 21, 20, 9 , 39, 16,50 })  {
       
        tree.insert(key);
    }

    cout << "Leafs :  ";
    tree.print();

    return 0;
}