#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

struct Pokemon
{
    std::string name;
    std::string type;
    int attack;
    int defense;
    double hp;
};

double type_Effectiveness_table[4][4] = {
    {0.5, 0.5, 1.0, 1.5},
    {1.5, 0.5, 1.0, 0.5},
    {1.0, 1.5, 0.5, 0.5},
    {0.5, 1.5, 1.0, 0.5}};

int typeidx(std::string type)
{
    if (type == "Fire")
        return 0;
    if (type == "Water")
        return 1;
    if (type == "Electric")
        return 2;
    if (type == "Grass")
        return 3;
    return -1;
}

int findPokemonIdx(Pokemon Pokemon[], int num_pokemon, std::string name)
{
    for (int i = 0; i < num_pokemon; i++)
    {
        if (Pokemon[i].name == name)
            return i;
    }
    return -1;
}

int main()
{
    int num_pokemon;
    std::string battle_name1, battle_name2;
    std::cin >> num_pokemon;
    Pokemon *pokemon = new Pokemon[num_pokemon];
    std::string line;
    std::string value;
    for (int i = 0; i < num_pokemon; i++)
    {
        std::cin >> pokemon[i].name >> pokemon[i].type >> pokemon[i].attack >> pokemon[i].defense >> pokemon[i].hp;
    }
    std::cin.ignore();
    std::getline(std::cin, line, ' ');
    battle_name1 = line;
    std::getline(std::cin, line);
    battle_name2 = line;

    // special case for Jirachi
    if (battle_name1 == "Jirachi" || battle_name2 == "Jirachi")
    {
        std::cout << "Jirachi is the cutest pokemon !!!!" << std::endl;
        std::cout << "--> cute is justice" << std::endl;
        std::cout << "--> Winner: Jirachi" << std::endl;
        return 0;
    }

    std::cout << battle_name1 << " VS " << battle_name2 << std::endl;
    std::cout << "!!!!!!!!!!!!!\n";
    std::cout << "!!! FIGHT !!!\n";
    std::cout << "!!!!!!!!!!!!!\n\n";

    int idx1 = findPokemonIdx(pokemon, num_pokemon, battle_name1);
    int idx2 = findPokemonIdx(pokemon, num_pokemon, battle_name2);
    Pokemon atk = pokemon[idx1];
    Pokemon dfd = pokemon[idx2];
    int round = 1;
    while (atk.hp > 0 && dfd.hp > 0)
    {
        double damage = (atk.attack * type_Effectiveness_table[typeidx(atk.type)][typeidx(dfd.type)]) - (dfd.defense * 0.5);
        std::cout << "Round" << round << ":" << atk.name << "dealt" << damage << "damage to" << dfd.name << "(HP = " << dfd.hp << ")" << std::endl;
        dfd.hp -= damage;
        // swap roles
        Pokemon temp = atk;
        atk = dfd;
        dfd = temp;
        if (atk.hp <= 0 || dfd.hp <= 0)
            break;
        damage = (atk.attack * type_Effectiveness_table[typeidx(atk.type)][typeidx(dfd.type)]) - (dfd.defense * 0.5);
        std::cout << "Round" << round << ":" << atk.name << "dealt" << damage << "damage to" << dfd.name << "(HP = " << dfd.hp << ")" << std::endl;
        dfd.hp -= damage;
        // swap roles
        temp = atk;
        atk = dfd;
        dfd = temp;
        round++;
    }
    std::cout << "======RESULT======" << std::endl;
    if (atk.hp <= 0)
    {
        std::cout << "Winner: " << dfd.name << "(HP left:" << dfd.hp << ")" << std::endl;
    }
    else
    {
        std::cout << "Winner: " << atk.name << "(HP left:" << atk.hp << ")" << std::endl;
    }

    delete[] pokemon;
    pokemon = nullptr;
    return 0;
}