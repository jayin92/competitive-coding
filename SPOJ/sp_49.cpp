#include <bits/stdc++.h>

using namespace std;


int f;

struct box{
	vector <box*> child;
	
};
void traversal(box* boxes){
	for(int i=0;i<boxes->child.size();i++){
		f++;
		traversal(boxes->child[i]);
	}
}
int main(){
	int t, n, m, q, x, y, z;
	
	cin >> t;
	
	for(int k=0;k<t;k++){
		cin >> n >> m;
		box boxes[n+1];
		
		for(int i=0;i<m;i++){
			cin >> x >> y;
			
			boxes[x].child.push_back(boxes + y);
		}
		cin >> q;
		
		for(int i=0;i<q;i++){
			cin >> z;
			box *current = boxes + z;
			f = 1;
			traversal(current);
			cout << f << endl;
		}
	}
}
