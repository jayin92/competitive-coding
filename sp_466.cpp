#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

struct Traveler {
	string name;
	int gender; // 0 for man, 1 for women
};

template <typename T> 
void Start();

template <typename T> 
void Start(){
	int n;
	cin >> n;
	stack<T*> A;
	queue<T*> B; 
	for(int i=0;i<n;i++){
		char mode, village;
		string name;
		int gender;
		cin >> mode;
		if(mode == 'I'){
			cin >> village >> name >> gender;
			cout << "A " << (gender == 0 ? "man " : "woman ") << name << " enters village " << village << "!" << endl; 
			T *traveler;
			traveler = new T;
			traveler -> name = name;
			traveler -> gender = gender;
			if(village == 'A'){				
				A.push(traveler);
			} else {
				B.push(traveler);
			}
		} else {
			cin >> village;
			if(village == 'A'){
				if(!A.empty()){
					T *out = A.top();
					gender = out -> gender;
					name = out -> name;					
					cout << "A " << (gender == 0 ? "man " : "woman ") << name << " leaves village A!" << endl;
					A.pop();
				} else {
					cout << "No traveler is in village A now." << endl;
				}
			} else {
				if(!B.empty()){
					T *out = B.front();
					gender = out -> gender;
					name = out -> name;					
					cout << "A " << (gender == 0 ? "man " : "woman ") << name << " leaves village B!" << endl;
					B.pop();
				} else {
					cout << "No traveler is in village B now." << endl;
				}
			}
		}
	} 
}
/* 你的code會被放在這邊 */

int main()
{
	Start<Traveler>();
	return 0;
}
