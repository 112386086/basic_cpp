#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

struct Pokemon {
    std::string name;
    std::string type;
    int attack;
    int defense;
    double hp;
};



int main() {
    int num_pokemon;
    std::string battle_name1, battle_name2;
    std::cin >> num_pokemon;
    Pokemon* pokemon = new Pokemon[num_pokemon];
    std::cin.ignore();
    std::string line;
    std::stringstream ss(line);
    std::string value;
    for (int i = 0; i < num_pokemon; i++){
        std::getline(std::cin, line,' ');
        pokemon[i].name = line;
        std::getline(std::cin, line,' ');
        pokemon[i].type = line;
        std::getline(std::cin, line,' ');
        pokemon[i].attack = std::stoi(line);
        std::getline(std::cin, line,' ');
        pokemon[i].defense = std::stoi(line);
        std::getline(std::cin, line);
        pokemon[i].hp = std::stod(line);
    }
    std::getline(std::cin, line, ' ');
    battle_name1 = line;
    std::getline(std::cin, line);
    battle_name2 = line;
}