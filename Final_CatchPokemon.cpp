#include <iostream>
#include <string>
#include <sstream>
#include <cstring>

struct Pokemon
{
    std::string name;
    int rarity; // 1~5
    double catch_rate;
};

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
    int ballPower, num_pokemon;
    double catch_score, success = 0.0;
    std::cin >> num_pokemon;
    if (num_pokemon < 1 || num_pokemon > 100)
    {
        std::cout << "Invalid number of Pokemons" << std::endl;
        return 0;
    }
    Pokemon *pokemon = new Pokemon[num_pokemon];
    std::string target_Pokemon_Name;
    std::string value;
    for (int i = 0; i < num_pokemon; i++)
    {
        std::cin >> pokemon[i].name >> pokemon[i].rarity >> pokemon[i].catch_rate;
        while (pokemon[i].rarity < 1 || pokemon[i].rarity > 5 || pokemon[i].catch_rate < 0.0)
        {
            std::cout << "Invalid Pokemon data, try again" << std::endl;
            std::cin.clear();
            std::cin.ignore();
            std::cin >> pokemon[i].name >> pokemon[i].rarity >> pokemon[i].catch_rate;
        }
    }
    std::cin >> ballPower;
    std::cin.ignore();
    std::getline(std::cin, target_Pokemon_Name);

    int target = findPokemonIdx(pokemon, num_pokemon, target_Pokemon_Name);
    if (target != -1)
    {
        catch_score = ballPower * pokemon[target].catch_rate;
        // catchScore ≥ rarity ,and catchScore = ballPower * catchRate
        if (catch_score >= pokemon[target].rarity)
        {
            success = 1.0;
            std::cout << "Caught " << pokemon[target].name << std::endl;
        }
        else
        {
            success = 0.0;
            std::cout << pokemon[target].name << " escaped" << std::endl;
        }
    }

    delete[] pokemon;
    pokemon = nullptr;
    return 0;
}