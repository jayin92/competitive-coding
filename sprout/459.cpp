#include <iostream>

const int MAXN = 128;

void InputMatrix(int N, int M, int A[MAXN][MAXN]);
void PrintMatrix(int N, int M, int A[MAXN][MAXN]);
void MatrixMultiplication(int N, int K, int M, int A[MAXN][MAXN], int B[MAXN][MAXN], int C[MAXN][MAXN]);
void DecryptImage(int N, int M, int A[MAXN][MAXN], int B[MAXN][MAXN], int C[MAXN][MAXN], int S[MAXN][MAXN]);

void InputMatrix(int N, int M, int A[MAXN][MAXN]){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> A[i][j];
		}
	}
}

void PrintMatrix(int N, int M, int A[MAXN][MAXN]){
	for(int i=0;i<N;i++){
		for(int j=0;j<M-1;j++){
			cout << A[i][j] << "\t";
		}
		cout << A[i][M-1] << endl;
	}	
}

void MatrixMultiplication(int N, int K, int M, int A[MAXN][MAXN], int B[MAXN][MAXN], int C[MAXN][MAXN]){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			C[i][j] = 0;
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			for(int k=0;k<K;k++){
				C[i][j] += (A[i][k] * B[k][j]);			
			}
		}		
	}
}
void DecryptImage(int N, int M, int A[MAXN][MAXN], int B[MAXN][MAXN], int C[MAXN][MAXN], int S[MAXN][MAXN]){
	int mid[MAXN][MAXN];
	MatrixMultiplication(N, M, N, A, B, mid);
	MatrixMultiplication(N, M, M, mid, C, S);
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			S[i][j] %= 251;
		}
	}
}

int main() {
    int N, M;
    int A[MAXN][MAXN], B[MAXN][MAXN], C[MAXN][MAXN], S[MAXN][MAXN];
    std::cin >> N >> M;
    InputMatrix(N, N, A);
    InputMatrix(M, M, B);
    InputMatrix(N, M, C);

    DecryptImage(N, M, A, B, C, S);
    PrintMatrix(N, M, S);
}

/* Your Code Will Be Placed Here */
