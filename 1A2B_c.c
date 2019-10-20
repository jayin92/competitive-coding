#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

//�@�ӱN����ন�}�C����� 
void intToArr(int x, int* arr){
	for(int i=0;i<4;i++){
		arr[i] = x / pow(10, 3-i); //�q�d��}�l�s 
		x %= (int)pow(10, 3-i);
	}
}

int main(){
	srand(time(0)); //�H���ؤl 
	int ans[4], guess[4];
	int Ans, Guess;
	int max = 9999; // 
	int min = 0;
	int a, b;
	bool flag;
	int x;
	while(1){
		flag = 0;
		Ans = rand() % 10000; //�ͦ� 0 ~ 9999���H���ü� 
		intToArr(Ans, ans); //�N���G�s��@���׬�4���}�C�� 
		// �ˬd�䤤�Ʀr�O�_�����ơA�Y���h�A���s�ͦ��@���H���� 
		for(int i=0;i<4;i++){
			for(int j=i+1;j<4;j++){
				if(ans[i] == ans[j]){
					flag = 1;
					break;
				}
			}
			if(flag) break;
		}
		if(!flag) break;
	}
	printf("The answer is "); //�N���צL�X
	for(int i=0;i<4;i++){
		printf("%d", ans[i]);	
	}
	printf("\n");
	while(1){
		a = b = 0; //���w��l�� 
		printf("Your guess:");
		scanf("%d", &Guess); // �������a�ҿ�J���Ʀr 
		if(Guess == Ans) break; //�p�G��J�Ʀr�P���׬ۦP�h�C���������X�L�a�j�� 
		intToArr(Guess, guess); // �N���a��J���Ʀr�୼ 
		for(int i=0;i<4;i++){
			if(ans[i] == guess[i]){ //�Y���a�Ҳq�����Ʀr�Φ�m�һP���׬ۦP�h a++ 
				a++;
				continue; //�~��~�hfor�j��A���g�L���h��for�j�� 
			} 
			for(int j=0;j<4;j++){ 
				if(guess[i] == ans[j]) b++; //�Y�Ʀr�ۦP����m���P�h b++ 
			}
		}
		printf("%dA%dB\n", a, b); //��X���G 
	}
	// ���Xwhile�j��Y�N���a�H�q��A��X�q�諸�T���õ����C�� 
	printf("You guess right!!!\n");
	
	return 0;
}
