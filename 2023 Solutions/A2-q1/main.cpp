#include <iostream>

const int ROWS = 100, COLS = 100;

int findSteps (int A[ROWS][COLS], int N, int M, int K) {

    std::cout  << "Enter positions in matrix: ";
    int value;
    for(int row=0; row<N; row++) {
        for(int col=0; col<M; col++) {
            std::cin >> value;
            A[row][col] = value;
        }
    }
   
    int row=0, col=0;
    int top=0;
    int bottom=N-1;
    int left=1;
    int right=M-1;  
    int stepCount=0;
    while(top != bottom && left != right) {
        while(row<bottom) {
            if(A[row][col]!=K) {
                stepCount++; 
            } else return stepCount;
            row++;
        }
        while(col<right) {
            if(A[row][col]!=K) {
                stepCount++; 
            } else return stepCount;
            col++;
        } 
        while(row>top) {
            if(A[row][col]!=K) {
                stepCount++; 
            } else return stepCount;
            row--;
        }
        while(col>left) {
            if(A[row][col]!=K) {
                stepCount++; 
            } else return stepCount;
            col--;
        }
        left++;
        right--;
        top++;
        bottom--;  
    }
    return -1;
}

int main() {
    int A[ROWS][COLS];
    int n=0, m=0, k=0;
    std::cout << "Number of rows (N): ";
    std::cin >> n;
    std::cout << "Number of columns (M): ";
    std::cin >> m;
    std::cout << "Destination Position (K): ";
    std::cin >> k;

    int steps = findSteps(A, n, m, k);
    std::cout << "Output: " << steps << std::endl;

    return 0;
}