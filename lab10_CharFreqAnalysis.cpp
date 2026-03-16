#include <iostream>
#include <string>
#include <fstream> // for file input and output
#include <sstream> // for stringstream
#include <cctype>  // for isalpha, toupper

void outfileIO()
{
    std::ofstream outfile("output.txt", std::ios::out); // create ofsteam object and specify write mode
    outfile << "today is monday, I need to meeting but still have cplusplus homework." << std::endl;
    outfile << "endl will flush the buffer, \\n is only a newline character." << std::endl;
    outfile.close(); // flush buffers and finalize writes
}

void infileIO()
{
    std::ifstream infile("output.txt"); // create ifstream object
    if (!infile.is_open())
    { // or if(stream), or infile.fail()
        std::cout << "failed to open file" << std::endl;
    }
    std::string text;
    // infile >> text; // token-by-token, stop at whitespace
    int lnNum = 1;
    char ch;
    while (std::getline(infile, text)) // read line by line
    {
        std::stringstream ss(text);
        std::string value;
        while (std::getline(ss, value, ','))
        {
        }
        std::cout << lnNum++ << ": " << text << std::endl;
    }
    while (infile.get(ch)) // read character by character
    {
        std::cout << ch;
    }
    infile.close();
}

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
    std::cout << total_val << std::endl;
    infile.close();
}

void countLetterFreq()
{
    // === TODO 1 : Read file ===
    int freq[26] = {0};
    char ch;
    std::ifstream infile("10_2.txt", std::ios::in);
    if (!infile.is_open())
    {
        std::cout << "failed to open file" << std::endl;
    }
    // === TODO 2 : count frequency of each letter ===
    while (infile.get(ch))
    {
        if (isalpha(ch))
        {
            ch = toupper(ch); // convert to uppercase
            // TODO: map ch to freq array
            freq[ch - 'A']++;
        }
    }
    char letters[26];
    for (int i = 0; i < 26; i++)
    {
        letters[i] = 'A' + i;
    }
    // === TODO 3 : sort by freq and letters ===
    for (int i = 0; i < 25; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            // TODO: if freq[j] > freq[i], or if frequencies are equal but letters[j] < letters[i]
            // then swap freq[i],freq[j] and letters[i],letters[j]
            if (freq[j] > freq[i] || (freq[j] == freq[i] && letters[j] < letters[i]))
            {
                std::swap(freq[i], freq[j]);
                std::swap(letters[i], letters[j]);
            }
        }
    }
    std::cout << "Top 5 letters:" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "Top " << i + 1 << ": " << letters[i]
                  << " (" << freq[i] << ")" << std::endl;
    }
}

int main()
{
    countLetterFreq();
    return 0;
}
