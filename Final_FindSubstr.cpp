#include <iostream>
#include <string>
#include <cstring>

int main()
{
    int row, col;
    char names[50][31];
    char keyword[31];
    std::cin >> row >> col;
    for (int i = 0; i < row; i++)
    {
        std::cin >> names[i];
    }
    std::cin >> keyword;

    char lowerName[31];
    char lowerKey[31];

    std::strcpy(lowerKey, keyword);
    for (int i = 0; lowerKey[i]; i++)
    {
        lowerKey[i] = tolower(lowerKey[i]);
    }

    for (int i = 0; i < row; i++)
    {
        std::strcpy(lowerName, names[i]);
        for (int j = 0; lowerName[j]; j++)
        {
            lowerName[j] = tolower(lowerName[j]);
        }
        char *c = std::strstr(lowerName, lowerKey);
        if (c != NULL)
        {
            std::cout << i << std::endl;
            return 0;
        }
    }
    std::cout << -1 << std::endl;
    return 0;
}