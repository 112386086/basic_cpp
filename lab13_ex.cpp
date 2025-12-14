#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>

int main(){
    // enum replace magic numbers with readable names
    enum Color { RED, GREEN, BLUE, YELLOW, ORANGE }; 
    Color c = GREEN;
    std::cout << c << std::endl;

    typedef int* IntPtr; // define IntPtr as an alias for int*
    using IntPtr = int*; // equal to IntPtr p = new int(42);
    IntPtr p = new int(42);
    std::cout << *p << std::endl;
    delete p;

    // using vector instead of raw arrays to manage dynamic arrays
    const int MAX_SIZE = 15;
    int n = 0, value;
    std::vector<int> num; // declaration
    while (n < MAX_SIZE){
        std::cin >> value;
        if (value < 0) break;
        num.push_back(value); // add element
        n++;
    }
    std::cout << num.size() << std::endl; // get size
    for (int i = 0; i < num.size(); i++){
        std::cout << num[i] << " "; // access element
    }
    std::cout << std::endl;

    struct book{
        char title[30];
        int price;
    };
    int sale_book = 3;
    book* bookptr = new book[sale_book];
    char* booktitle = new char[20];
    for (int i = 0; i < sale_book; i++){
        std::cin.ignore();
        std::cin.getline(booktitle, 30, ',');
        std::strcpy(bookptr[i].title, booktitle);
        std::cin >> bookptr[i].price;
    }
    for (int i = 0; i < sale_book; i++){
        std::cout << bookptr[i].title << "($" << bookptr[i].price << ")" << std::endl;
    }
    delete[] bookptr;
    delete[] booktitle;
}

