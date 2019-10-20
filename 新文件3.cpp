#include <iostream>
#include <string>

struct node{
	int id;
	node *nxt;
};
using namespace std;




int main(){
	Player *eagle;
	eagle = new Player;
	eagle -> id = 1;
	
	cout << eagle -> id << endl;
}
