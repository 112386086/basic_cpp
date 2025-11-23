#include <iostream>
#include <string>
#include <cctype> //use tolower() to ignore letter case
#include <cstring> //use strstr()

std::string toLower(std::string& str) {
    std::string dst = str;
    for (int i = 0; i < str.length(); i++) {
        dst[i] = tolower(str[i]);
    }
    return dst;
}
int main() {
    std::string keyword;
    std::string mainStr;
    std::string dstKey;
    std::string dstStr;
    std::string res;

    int idx = -1;
    std::cout << "Enter the main string: ";
    std::getline(std::cin, mainStr);
    std::cout << "Enter the keyword to search: ";
    std::cin >> keyword;
    dstStr = toLower(mainStr);
    dstKey = toLower(keyword);
    
    size_t i = dstStr.find(dstKey);  // if not found, return std::string::npos
    if (i != std::string::npos){
        idx = i;  // Calculate how many characters away 'pos' is from the start of 'dstStr'
        std::string remain = mainStr.substr(0, idx);
        std::string key = mainStr.substr(idx, keyword.length());
        std::string remainpart = mainStr.substr(idx + keyword.length());
        res = remain + "[" + key + "]" + remainpart;
        std::cout << idx << std::endl;
        std::cout << res << std::endl;

    }
    else{
        std::cout << idx << std::endl;
        std::cout << mainStr << std::endl;
    }

}


