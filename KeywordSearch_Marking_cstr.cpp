#include <iostream>
#include <string>
#include <cctype> //use tolower() to ignore letter case
#include <cstring> //use strstr()


/*
strstr(): find the first occurrence of a substring in a string
char * strstr(char * str1, const char * str2);
*/

void toLower(char str[], char dst[]) {
    for (int i = 0; str[i]; i++) {
        dst[i] = tolower(str[i]);
    }
    dst[strlen(str)] = '\0'; // null-terminate the destination string
}
int main() {
    char keyword[256];
    char dstKey[256];
    char mainStr[256];
    char dstStr[256];
    char res[260];
    int idx = -1;
    std::cout << "Enter the main string: ";
    std::cin.getline(mainStr, 256); // up to 255 chars + '\0', only for char
    std::cout << "Enter the keyword to search: ";
    std::cin >> keyword;
    toLower(mainStr, dstStr);
    toLower(keyword, dstKey);
    
    char* i = strstr(dstStr, dstKey);
    if (i != NULL){
        idx = i - dstStr;  // Calculate how many characters away 'pos' is from the start of 'dstStr'
        strncpy(res, mainStr, idx); // copy idx chars from mainStr to res
        res[idx] = '\0';
        strcat(res, "[");
        strncat(res, mainStr + idx, strlen(keyword)); 
        strcat(res, "]");
        strcat(res, mainStr + idx + strlen(keyword));
        std::cout << idx << std::endl;
        std::cout << res << std::endl;

    }
    else{
        std::cout << idx << std::endl;
        std::cout << mainStr << std::endl;
    }

}


