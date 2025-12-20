
#include <iostream>
#include <string>
#include <fstream> // for file input and output
#include <sstream> // for stringstream
#include <cctype>  // for isalpha, toupper

void calAmount()
{
    std::string item;
    int val, total_val = 0;
    std::string text;
    std::ifstream infile("10_1.csv");
    if (!infile.is_open())
    {
        std::cout << "failed to open file" << std::endl;
        return;
    }
    while (std::getline(infile, text)) // read line by line, only accept string
    {
        std::stringstream ss(text);
        while (std::getline(ss, item, ',')) // access first token separated by ',' get item as string
        {
            ss >> val;
            total_val += val;
        }
    }
    std::cout << "Final Balance: " << total_val << std::endl;
    infile.close();
}

int main()
{
    calAmount();
    return 0;
}