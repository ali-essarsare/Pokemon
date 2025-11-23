#include "Card.h"

// Card.cpp - Implements the base `Card` methods (constructor, destructor, getters).

Card::Card(const std::string& name) : cardName(name) {}

Card::~Card() = default;

const std::string& Card::getCardName() const {
    return cardName;
}
