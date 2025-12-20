#include <iostream>
#include <iomanip>
#include <sstream>

int main()
{
    // 找到arr中兩個數和近似n
    int target, arr[10], cnt = 0, max = 10;
    int diff, abs_diff = 1000000;
    std::string line;
    std::getline(std::cin, line);
    std::stringstream ss(line);
    while (cnt < max && ss >> arr[cnt])
    {
        cnt++;
    }
    std::cin >> target;
    int idx1 = 0, idx2 = 0;
    for (int i = 0; i < max; i++)
    {
        for (int j = i + 1; j < max; j++)
        {
            int sum = arr[i] + arr[j];
            diff = sum - target;
            if (abs(diff) < abs_diff)
            {
                idx1 = i;
                idx2 = j;
                abs_diff = abs(diff);
            }
        }
    }
    std::cout << idx1 << " " << idx2 << std::endl;
    return 0;
}