#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

//一個將整數轉成陣列的函數 
void intToArr(int x, int* arr){
	for(int i=0;i<4;i++){
		arr[i] = x / pow(10, 3-i); //從千位開始存 
		x %= (int)pow(10, 3-i);
	}
}

int main(){
	srand(time(0)); //隨機種子 
	int ans[4], guess[4];
	int Ans, Guess;
	int max = 9999; // 
	int min = 0;
	int a, b;
	bool flag;
	int x;
	while(1){
		flag = 0;
		Ans = rand() % 10000; //生成 0 ~ 9999的隨機亂數 
		intToArr(Ans, ans); //將結果存於一長度為4的陣列中 
		// 檢查其中數字是否有重複，若有則再重新生成一次隨機數 
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
	printf("The answer is "); //將答案印出
	for(int i=0;i<4;i++){
		printf("%d", ans[i]);	
	}
	printf("\n");
	while(1){
		a = b = 0; //指定初始值 
		printf("Your guess:");
		scanf("%d", &Guess); // 接收玩家所輸入的數字 
		if(Guess == Ans) break; //如果輸入數字與答案相同則遊戲結束跳出無窮迴圈 
		intToArr(Guess, guess); // 將玩家輸入的數字轉乘 
		for(int i=0;i<4;i++){
			if(ans[i] == guess[i]){ //若玩家所猜測的數字及位置皆與答案相同則 a++ 
				a++;
				continue; //繼續外層for迴圈，不經過內層的for迴圈 
			} 
			for(int j=0;j<4;j++){ 
				if(guess[i] == ans[j]) b++; //若數字相同但位置不同則 b++ 
			}
		}
		printf("%dA%dB\n", a, b); //輸出結果 
	}
	// 跳出while迴圈即代表玩家以猜對，輸出猜對的訊息並結束遊戲 
	printf("You guess right!!!\n");
	
	return 0;
}
