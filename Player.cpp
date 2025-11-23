#include "Player.h"
#include "EnergyCard.h"
#include "TrainerCard.h"
#include <iostream>
using namespace std;

// Player.cpp - Implements player actions: add/activate cards, attach energy, attack, use trainer.

Player::Player(const string& playerName) : playerName(playerName) {
}

Player::~Player() {
    
    for (Card* card : benchCards) {
        delete card;
    }
    for (PokemonCard* card : actionCards) {
        delete card;
    }
}

void Player::displayInfo() {
    cout << "Player Name: " << playerName << endl;
    cout << "Bench Cards: " << benchCards.size() << endl;
    cout << "Action Cards: " << actionCards.size() << endl;
}

void Player::displayBench() {
    cout << "Bench cards for Player " << playerName << ":" << endl;
    for (size_t i = 0; i < benchCards.size(); i++) {
        cout << "Card " << i << ": ";
        benchCards[i]->displayInfo();
    }
}

void Player::displayAction() {
    cout << "Action cards for Player " << playerName << ":" << endl;
    for (size_t i = 0; i < actionCards.size(); i++) {
        cout << "Card " << i << ": ";
        actionCards[i]->displayInfo();
    }
}

const string& Player::getPlayerName() const {
    return playerName;
}

vector<Card*>& Player::getBenchCards() {
    return benchCards;
}

vector<PokemonCard*>& Player::getActionCards() {
    return actionCards;
}

void Player::addCardToBench(Card* card) {
    benchCards.push_back(card);
}


void Player::activatePokemonCard(int index) {
    if (index < 0 || index >= (int)benchCards.size()) {
        cout << "Invalid bench index for activation." << endl;
        return;
    }

    PokemonCard* pokemon = dynamic_cast<PokemonCard*>(benchCards[index]);
    if (!pokemon) {
        cout << "Selected card is not a Pokemon." << endl;
        return;
    }

    actionCards.push_back(pokemon);
    benchCards.erase(benchCards.begin() + index);

    cout << playerName << " activated a Pokemon: ";
    pokemon->displayInfo();
}


void Player::attachEnergyCard(int benchIndex, int activeIndex) {
    if (benchIndex < 0 || benchIndex >= (int)benchCards.size()) {
        cout << "Invalid bench index for energy card." << endl;
        return;
    }
    if (activeIndex < 0 || activeIndex >= (int)actionCards.size()) {
        cout << "Invalid active Pokemon index." << endl;
        return;
    }

    EnergyCard* energy = dynamic_cast<EnergyCard*>(benchCards[benchIndex]);
    if (!energy) {
        cout << "Selected card is not an Energy card." << endl;
        return;
    }

    actionCards[activeIndex]->addEnergy();
    cout << playerName << " attaches an " << energy->getEnergyType()
         << " energy to its active Pokemon." << endl;

    delete energy;
    benchCards.erase(benchCards.begin() + benchIndex);
}


void Player::attack(int attackerIndex, int /*attackIndex*/, Player& opponent, int targetIndex) {
    if (attackerIndex < 0 || attackerIndex >= (int)actionCards.size()) {
        cout << "Invalid attacker index." << endl;
        return;
    }
    if (targetIndex < 0 || targetIndex >= (int)opponent.actionCards.size()) {
        cout << "Invalid target index." << endl;
        return;
    }

    PokemonCard* attacker = actionCards[attackerIndex];
    PokemonCard* target = opponent.actionCards[targetIndex];

    int degats = attacker->getDegat();
    cout << playerName << " attacks " << opponent.playerName
         << " for " << degats << " damage!" << endl;

    target->subirDegats(degats);
}


void Player::useTrainer() {
    for (size_t i = 0; i < benchCards.size(); ++i) {
        TrainerCard* trainer = dynamic_cast<TrainerCard*>(benchCards[i]);
        if (trainer) {
            cout << playerName << " uses trainer card: "
                 << trainer->getCardName() << endl;
            trainer->HealAllYourActionPokemon(actionCards);

            delete trainer;
            benchCards.erase(benchCards.begin() + i);
            return;
        }
    }

    cout << playerName << " has no Trainer card on the bench." << endl;
}
