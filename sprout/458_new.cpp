#include <iostream>
#include <string>

struct Player {
	int id;
	struct Player *nxt;
};

using namespace std;

void createChickenList(int n);		// 建立所有的玩家資料
void rotateChickenList();		// 換一位母雞
void attack(int id);			// 老鷹試圖攻擊編號id的雞
void print();				// 印出當前狀態

Player *hen = nullptr;
Player *eagle = nullptr;
Player *tail = nullptr;
int len;

int main()
{
	int m, n;
	std::cin >> n;
	createChickenList(n);
	len = n - 1;

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
    hen = new Player;
    eagle = new Player;
    tail = new Player;

    len = n-1;
    eagle -> id = 1;
    eagle -> nxt = nullptr;
    hen -> id = 2;
    hen -> nxt = nullptr;

    Player* current = hen;
    int i = 3;
    while(i < len+1){
        Player *new_player;
        new_player = new Player;

        new_player -> id = i;
        current -> nxt = new_player;
        current = new_player;
        i++;
    }
    tail -> id = i;
    tail -> nxt = nullptr;
    if(len >= 2){
        current -> nxt = tail;
    } else {
        tail = hen;
    }

}

void rotateChickenList(){
    if(len >= 2){
        Player *new_tail;
        new_tail = new Player;

        new_tail -> id = hen -> id;
        new_tail -> nxt = nullptr;
        tail -> nxt = new_tail;

        hen = hen -> nxt;
        tail = new_tail;

    }
}

void attack(int id){
    if(hen -> id != id){
        Player *current = hen;
        int i = 2;
        while(current -> nxt ->id != id){
            current = current -> nxt;
            i++;
        }
        if(3*i > len){
            int eagle_id = eagle -> id;
            if(i == len){ //tail
                eagle -> id = tail -> id;
                tail -> id = eagle_id;
            } else {
                eagle -> id = current -> nxt -> id;
                current -> nxt -> id = eagle_id;
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
