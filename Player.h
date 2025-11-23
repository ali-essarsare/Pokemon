#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Card.h"
#include <string>
// Player.h - Declares a Player who manages bench and active Pokemon cards.
#include "PokemonCard.h"

class Player {
private:
    std::string playerName;
    std::vector<Card*> benchCards;        
    std::vector<PokemonCard*> actionCards; 

public:
    Player(const std::string& playerName);
    ~Player();

    void displayInfo();
    void displayBench();
    void displayAction();

    const std::string& getPlayerName() const;
    std::vector<Card*>& getBenchCards();
    std::vector<PokemonCard*>& getActionCards();

    void addCardToBench(Card* card);

    
    void activatePokemonCard(int index);
    void attachEnergyCard(int benchIndex, int activeIndex);
    void attack(int attackerIndex, int attackIndex, Player& opponent, int targetIndex);
    void useTrainer();
};

#endif
