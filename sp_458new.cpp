#include <iostream>
#include <string>

struct Player {
	int id;
	struct Player *nxt;
};

void createChickenList(int n);		// �إߩҦ������a���
void rotateChickenList();		// ���@�����
void attack(int id);			// ���N�չϧ����s��id����
void print();				// �L�X��e���A

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
    Player* current = hen;
    int i = 3;
    while(i < len+1){
        Player *new_player;
        new_player = new Player;

        new_player -> id = i;
        current -> nxt = new_player;
        i++;
    }
    if(len >= 2){
        tail -> id = i
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
        tail -> nxt = new_tail;

        hen = hen -> nxt;
        tail = new_tail;

    }
}

void attack(int id){
    std::cout << "test" << endl;
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
