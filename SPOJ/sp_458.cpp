#include <iostream>
#include <string>

struct Player {
	int id;
	Player *nxt;
};

void createChickenList(int n);		// 建立所有的玩家資料
void rotateChickenList();		// 換一位母雞
void attack(int id);			// 老鷹試圖攻擊編號id的雞
void print();				// 印出當前狀態

Player *hen = nullptr;
Player *eagle = nullptr;
Player *tail = nullptr;
int len;
using namespace std;
int main()
{
	int m, n;
	std::cin >> n;
	createChickenList(n);
	std::cin >> m;
	while(m--){
		std::string inst;
		int id;

		std::cin >> inst;
		if(inst == "attack"){
			std::cin >> id;
			attack(id);
		}else if(inst == "rotate"){
			rotateChickenList();
		}
		print();
	}

	// delete list
	Player *nxt;
	while(hen){
		nxt = hen->nxt;
		delete hen;
		hen = nxt;
	}
	delete eagle;

	return 0;
}

void createChickenList(int n){
	len = n-2;
	eagle = new Player;
	hen = new Player;
	tail = new Player;
	eagle -> id = 1;
	eagle -> nxt = nullptr;

	hen -> id = 2;
	hen -> nxt = nullptr;

	Player *current = hen;
	for(int i=3;i<n;i++){
		Player *temp;
		temp = new Player;
		temp -> id = i;
		current -> nxt = temp;
		current = temp;
	}
	tail -> id = n;
	tail -> nxt = nullptr;
	if(n != 2) current -> nxt = tail;
}
void rotateChickenList(){
	if(hen -> nxt != nullptr){
		int temp = hen -> id;
		Player *new_tail;
		new_tail = new Player;
		hen -> id = hen -> nxt -> id;
		hen -> nxt = hen -> nxt -> nxt;
		tail -> nxt = new_tail;
		new_tail -> id = temp;
		new_tail -> nxt = nullptr;
		tail = new_tail;
	}
}
void attack(int id){
	if(hen -> nxt != nullptr && hen -> id != id){
		int i = 1;
		Player* current = hen -> nxt;
		if(len >= 2){
	        while(current -> nxt -> id != id){
	            current = current -> nxt;
	            i++;
	        }
		}
		if(3*(i+1) > len){
	        if((i+1) == len){
	            int temp = tail -> id;
	            tail -> id = eagle -> id;
	            eagle -> id = temp;
	        } else { // the attacked chicken is in the middle
	            int temp = current -> nxt -> id;
	            current -> nxt -> id = eagle -> id;
	            eagle -> id = temp;
	
	        }
		}
	}
}
void print(){
	std::cout << (eagle -> id) << std::endl;
	Player* current = hen;
	while(current -> nxt != nullptr){
		std::cout << current -> id << " ";
		current = current -> nxt;
	}
	std::cout << current  -> id << std::endl;
}
