#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

int main(){
    // basic JSON structure, obj: { key: value }
    std::string name, gender;
    int age;
    std::getline(std::cin, name);
    std::cin >> age;
    std::cin.ignore();
    std::cin >> gender;
    std::cout << "{" << std::endl 
        << " \"name\": \"" << name << "\",\n"
        << " \"age\": " << std::showbase  << std::hex << age << ",\n" 
        << " \"gender\": \"" << gender << "\"\n"
        << "}" << std::endl;

}