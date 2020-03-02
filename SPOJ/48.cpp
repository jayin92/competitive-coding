#include <bits/stdc++.h>

using namespace std;

struct node{
	node* parent=NULL;
	node* left=NULL;
	node* right=NULL;
		
	int data=0;
};

void traversal(node* root){
	if(root -> left != NULL){
		traversal(root->left);
	}
	if(root -> right != NULL){
		traversal(root->right);
	}	
	cout << root -> data << endl;
}

int main(){
	vector <int> input;
	while(!cin.eof()){
		int temp;
		cin >> temp;
		input.push_back(temp);
	}
	
	node root;
	root.parent = NULL;
	root.data = input[0];
	input.pop_back();
	node tree[2005];
	int j = 0;
	for(int i=1;i<input.size();i++){
		node* temp = &root;
		while(1){
			if(temp -> data < input[i]){
				if(temp -> right == NULL){
					tree[j].parent = temp;
					tree[j].data = input[i];
					temp -> right = &tree[j];
					j++;
					break;
				} 
				else temp = temp -> right;
			}			
			
			else if(temp -> data > input[i]){
				if(temp -> left == NULL){
					tree[j].parent = temp;
					tree[j].data = input[i];
					temp -> left = &tree[j];
					j++;
					break;
				}
				else temp = temp -> left;
			}

		}
	}

 	traversal(&root);
	
	
	
	
}
