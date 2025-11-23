#include "TrainerCard.h"
#include <iostream>
using namespace std;

// TrainerCard.cpp - Implements trainer card actions such as healing player Pokemon.

TrainerCard::TrainerCard(const string& cardName, const string& trainerEffect)
    : Card(cardName), trainerEffect(trainerEffect) {}

void TrainerCard::displayInfo() {
    cout << "Trainer Card - Name: " << getCardName()
         << ", Effect: " << trainerEffect << endl;
}

void TrainerCard::HealAllYourActionPokemon(vector<PokemonCard*>& actionCards) {
    cout << "Healing all your action Pokémon." << endl;
    for (auto pokemon : actionCards) {
        pokemon->heal();
    }
}
