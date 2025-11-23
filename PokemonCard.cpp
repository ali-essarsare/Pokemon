#include "PokemonCard.h"
#include <iostream>
using namespace std;

// PokemonCard.cpp - Implements Pokemon card behavior: damage, heal, energy management and display.

PokemonCard::PokemonCard(
    const string& pokemonName,
    const string& pokemonType,
    const string& familyName,
    int evolutionLevel,
    int maxHP,
    int hp,
    const string& attackDescription1,
    int coutEnergie,
    int coutEnergieActuel,
    const string& attackDescription2,
    int attackDegats
) :
    Card(pokemonName),
    pokemonType(pokemonType),
    familyName(familyName),
    evolutionLevel(evolutionLevel),
    maxHP(maxHP),
    hp(hp),
    coutEnergie(coutEnergie),
    coutEnergieActuel(coutEnergieActuel),
    attackDescription1(attackDescription1),
    attackDescription2(attackDescription2),
    attackDegats(attackDegats)
{ }

void PokemonCard::displayInfo() {
    cout << "Pokemon Card - " << familyName
         << " | Type: " << pokemonType
         << " | HP: " << hp << "/" << maxHP
         << " | Energy: " << coutEnergieActuel << "/" << coutEnergie
         << " | Attack: " << attackDescription1 << " (" << attackDegats << " dmg)"
         << endl;
}

void PokemonCard::subirDegats(int degats) {
    hp -= degats;
    if (hp < 0) hp = 0;
}

void PokemonCard::heal() {
    hp = maxHP;
}

int PokemonCard::getDegat() const {
    return attackDegats;
}

int PokemonCard::getEnergieActuelle() const {
    return coutEnergieActuel;
}

void PokemonCard::addEnergy(int amount) {
    coutEnergieActuel += amount;
}
