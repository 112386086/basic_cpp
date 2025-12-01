#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

int** CreateMatrix(int m, int n){
    int** row = new int* [m];
    int row_element = n, num = 0;
    std::string line;
    for (int i = 0; i < m; i++){
        std::getline(std::cin, line);
        std::stringstream ss(line);
        row[i] = new int[n];
        while (num < row_element && ss >> row[i][num]){
            num++;
        }
        num = 0;
    }
    return row;
}

void DeleteMatrix(int** arr, int m){ // free in reverse order
    for (int i = 0; i < m; i++){
        delete[] arr[i];    // first delete each row
    }
    delete[] arr;   // delete the memory stored pointer to rows
    arr = nullptr;
}

int** AddMatrix(int** A, int** B, int m, int n){
    int** row = new int*[m];
    for (int i = 0; i < m; i++){
        row[i] = new int[n];
        for (int j = 0; j < n; j++){
            row[i][j] = A[i][j] + B[i][j];
            std::cout << row[i][j];
            if (j != n - 1){
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    return row;
}

int main(){
    int m, n;
    std::cin >> m >> n;
    std::cin.ignore();
    int** matrixA = CreateMatrix(m, n);
    int** matrixB = CreateMatrix(m, n);
    int** matrixC = AddMatrix(matrixA, matrixB, m, n);

    DeleteMatrix(matrixA, m);
    DeleteMatrix(matrixB, m);
    DeleteMatrix(matrixC, m);
}