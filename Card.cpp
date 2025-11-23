#include "Card.h"

Card::Card(const std::string& name) : cardName(name) {}

Card::~Card() = default;

const std::string& Card::getCardName() const {
    return cardName;
}
