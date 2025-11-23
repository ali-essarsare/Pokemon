#ifndef ENERGYCARD_H
#define ENERGYCARD_H

#include "Card.h"
#include <string>

class EnergyCard : public Card {
private:
    std::string energyType;

public:
    EnergyCard(const std::string& energyType);

    void displayInfo() override;
    std::string getEnergyType() const;
};

#endif
