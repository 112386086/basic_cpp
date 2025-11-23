#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

int main() {
    int PCB_Width, PCB_Length, PCB_Area, IC_Num;
    int IC_Area = 0;
    std::string SPEC1_pass = "FAIL", SPEC2_pass = "FAIL";
    double IC_Power = 0.0, avg_IC_Power = 0.0; // need to initialize, otherwise may contain garbage value

    std::string line;
    std::ifstream inFile("ex_11_1.csv", std::ios::in);
    if (!inFile.is_open()){
        std::cout << "Error: cannot open" << std::endl;
        return -1;
    }
    // first line of ex_11_1.csv format: PCB_Width,PCB_Length,IC_Num
    std::getline(inFile, line);
    std::stringstream ss(line);
    std::string value;
    std::getline(ss, value, ',');
    // process value here
    PCB_Width = std::stoi(value);
    std::getline(ss, value, ',');
    PCB_Length = std::stoi(value);
    std::getline(ss, value, ',');
    IC_Num = std::stoi(value);
    if (IC_Num > 100){
        std::cout << "Error: IC_Num exceeds 100" << std::endl;
        return -1;
    }
    
    while (std::getline(inFile, line)){
        std::stringstream ss(line);
        std::string value;
        std::getline(ss, value, ',');
        IC_Power += std::stod(value);
        std::getline(ss, value, ',');
        IC_Area += std::stoi(value);

    }

    avg_IC_Power = IC_Power / IC_Num;
    if (avg_IC_Power <= 3.0){
        SPEC1_pass = "PASS";
    }
    PCB_Area = PCB_Width * PCB_Length;
    if (IC_Area <= PCB_Area){
        SPEC2_pass = "PASS";
    }
    std::cout << std::fixed << std::setprecision(2) << "Average IC Power = " << avg_IC_Power << ", SPEC1 " << SPEC1_pass << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "Total IC Area = " << IC_Area << ", SPEC2 " << SPEC2_pass << std::endl;

    inFile.close();
}