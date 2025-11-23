#include <iostream>
#include <iomanip>


int main() {
    int size = 0;
    std::cout << "enter the size of spiral matrix (1-100): ";
    std::cin >> size;
    while (size < 1 || size > 100){
        std::cout << "invalid size, enter again: ";
        std::cin >> size;
    }
    int top = 0;
    int right = size - 1;
    int left = 0;
    int bottom = size - 1;

    int matrix[size][size];
    int element = 1;

    while (left <= right && top <= bottom){
        for (int i = left; i <= right; i++){
            matrix[top][i] = element;
            element++;
        }
        top++;
        for (int i = top; i <= bottom; i++){
            matrix[i][right] = element;
            element++;
        }
        right--;
        for (int i = right; i >= left; i--){
            matrix[bottom][i] = element;
            element++;
        }
        bottom--;
        for (int i = bottom; i >= top; i--){
            matrix[i][left] = element;
            element++;
        }
        left++;
    }

    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            std::cout << std::setw(3) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
}