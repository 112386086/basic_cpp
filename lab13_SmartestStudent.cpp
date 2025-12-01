#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

struct Student{
    char name[20];
    int score;
};

Student* findTopStudent(Student* list, int n){
    Student* topStu = nullptr;
    for (int i = 0; i < n; i++){
        if (topStu == nullptr || list[i].score > topStu->score){
            topStu = &list[i];
        }
    }
    return topStu;
}

int main(){
    int num_stu;
    std::cin >> num_stu;
    std::cin.ignore();  // use ignore between cin and getline
    Student* list = new Student[num_stu];
    char* buf = new char[20];
    for (int i = 0; i < num_stu; i++){
        std::cin.getline(buf, 20, ' '); // read until space
        std::strcpy(list[i].name, buf);
        std::cin >> list[i].score;
        std::cin.ignore();
    }
    Student* topStu = findTopStudent(list, num_stu);
    std::cout << "Top student: " << topStu->name << std::endl;
    delete[] buf;
    delete[] list;
    return 0;
}