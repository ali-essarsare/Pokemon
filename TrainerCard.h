#ifndef TRAINERCARD_H
#define TRAINERCARD_H

#include "Card.h"
#include "PokemonCard.h"
#include <string>
#include <vector>

class TrainerCard : public Card {
private:
    std::string trainerEffect;

public:
    TrainerCard(const std::string& cardName, const std::string& trainerEffect);

    void displayInfo() override;

    const std::string& getEffect() const { return trainerEffect; }

    void HealAllYourActionPokemon(std::vector<PokemonCard*>& actionCards);
};

#endif
