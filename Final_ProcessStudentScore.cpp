#include <iostream>
#include <iomanip>
#include <sstream>
#include <iomanip>
#include <string>

int main()
{

    std::string command, name, subject, token;
    double score, value, sum;
    int cnt = 0;
    double avg_score = 0;
    std::string line;
    // NAME <studentName>
    while (std::getline(std::cin, line))
    {
        std::stringstream ss(line);
        ss >> command;
        if (command == "NAME")
        {
            ss >> name;
        }
        else if (command == "SCORE")
        {
            ss >> subject;
            sum = 0;
            cnt = 0;
            while (ss >> token) // access input as string
            {
                std::stringstream tt(token);
                char extra;
                if (tt >> score && !(tt >> extra))
                {
                    cnt++;
                    sum += score;
                }
            }
            if (cnt > 0)
            {
                avg_score = sum / cnt;
                std::cout << std::fixed << std::setprecision(4) << name << " " << subject << " " << avg_score << std::endl;
            }
        }
    }
    return 0;
}