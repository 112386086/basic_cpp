#include <iostream>
#include <string>
#include <sstream>

int* findPtr(int*arr, int n, int target){
    int* p = arr;
    for(int i = 0; i < n; i++){
        if (target == *(p + i)){
            return (p + i);
        }
    }
    return nullptr;
}

int main(){
    int num_int = 0, num = 0, search_num;
    std::string line;
    std::cin >> num_int;
    int* arr = new int[num_int];
    std::cin.ignore();
    std::getline(std::cin, line);
    std::stringstream ss(line);
    while(num < num_int && ss >> arr[num]){
        num++;
    }
    std::cin >> search_num;
    int* result = findPtr(arr, num_int, search_num);
    if (!result){
        std::cout << "Not found" << std::endl;
    } else {
        std::cout << "Found at index " << (result - arr) << std::endl;
    }

    delete[] arr;
    return 0;
}