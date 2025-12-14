#include <iostream>
#include <string>

void sumArray(int arr[], int n, int* head, int* tail){
    int maximal = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++){
            sum = arr[i] + arr[j];
            if (sum > maximal){
                maximal = sum;
                *head = i;
                *tail = j;
            }
        }
    }
}

int FindMaxSumPair(){
    int arr[10];
    int head, tail;
    for (int i = 0; i < 10; i++) {
        std::cin >> arr[i];
    }
    sumArray(arr, 10, &head, &tail);
    std::cout << head << " " << tail << std::endl;
    return 0;
}

void MatrixExample(){
    int size, res = 0, row_sum = 0, col_sum = 0, diag_sum = 0, sec_diag_sum = 0;
    std::cin >> size;
    int matrix[size][size];
    for (int i = 0; i < size; i++){
        int row_num = 0, col_num = 0;
        for (int j = 0; j < size; j++){
            std::cin >> matrix[i][j];
            row_num += matrix[i][j];
            if (i == j){
                diag_sum += matrix[i][j];
            }
            if (i + j == size - 1){
                sec_diag_sum += matrix[i][j];
            }
        }
        if (row_num > row_sum){
            row_sum = row_num;
        }
    }
    if (diag_sum > res) res = diag_sum;
    if (row_sum > res) res = row_sum;
    if (sec_diag_sum > res) res = sec_diag_sum;
    
    for (int i = 0; i < size; i++){
        int col_num = 0;
        for (int j = 0; j < size; j++){
            // matrix needs to be completed first, otherwise garbage value
            col_num += matrix[j][i];    
        }
        if (col_num > col_sum)  col_sum = col_num;
        
    }
    if (col_sum > res)  res = col_sum;
    
    std::cout << res << std::endl;
}

int main(){
    MatrixExample();
    return 0;
}