#include <iostream>

void EzSort(int N, int const **ptr_array);

using namespace std;


int main() {
    int N, arr[1000], *ptr[1000];
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
        ptr[i] = &(arr[i]);
    }
    EzSort(N, (int const **)ptr); //  int const ** mean that a pointer to a pointer to const int
    							  //  so in the EzSort Function, I can change the value of ptr_array because the data inside them are not a const
    for (int i = 0; i < N; i++) {
        std::cout << *(ptr[i]) << (i == N - 1 ? '\n' : ' ');
    }
}

void EzSort(int N, int const **ptr_array){
	for(int i=0;i<N-1;i++){
		for(int j=0;j<N-1-i;j++){
			if(*(ptr_array[j])> *(ptr_array[j+1])){
				const int *temp = ptr_array[j];
				ptr_array[j] = ptr_array[j+1];
				ptr_array[j+1] = temp;
			}
		}
	}
}
