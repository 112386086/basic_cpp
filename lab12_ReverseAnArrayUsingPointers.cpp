#include <iostream>
#include <string>
#include <sstream>

void reverseArray(int* left, int* right){
    while (left < right){
        int t = *left;
        *left = *right;
        *right = t;
        left++;
        right--;
    }
}

int main(){
    int num_int = 0, num = 0;
    std::string line;
    std::cin >> num_int;
    int* arr = new int[num_int];
    std::cin.ignore();
    std::getline(std::cin, line);
    std::stringstream ss(line);
    while(num < num_int && ss >> arr[num]){
        num++;
    }
    reverseArray(arr, arr + num_int - 1);
    for(int i = 0; i < num_int; i++){
        std::cout << arr[i];
        if (i != num_int - 1){
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    delete[] arr;
    arr = nullptr; // avoid dangling pointer
    return 0;
}