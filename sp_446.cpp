#include<iostream>
#include <string>

using namespace std;

template<typename T>  
struct Stack{
    T arr[1024];
    int top=0;
};

template<typename T> 
Stack<T> push(Stack<T> x, T data){
	x.arr[x.top] = data;
	x.top ++;
	
	return x;
} 

template<typename T>
Stack<T> pop(Stack<T> x){
	x.top--;
	return x;
}

template<typename T>
bool isEmpty(Stack<T> x){
	if(x.top == 0){
		return true;
	} else {
		return false;
	}
}

int main(){
	int event;
	std::cin>>event;
	Stack<string> s;//這裡T指的是int
	for(int i=0;i<event;i++){
		std::string command;
		std::cin>>command;
		if(command=="push"){
			string data;//這裡T指的是int
			std::cin>>data;
			s=push(s,data);
		}
		else{
			if(isEmpty(s)!=true){
				std::cout<<s.arr[s.top-1]<<"\n";
				s=pop(s);	
			}
		}
	}
	std::cout<<"\n";
}
