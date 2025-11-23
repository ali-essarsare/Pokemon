#include "EnergyCards.h"
#include <iostream>
#include <string>
using namespace std;

EnergyCard::EnergyCard(const std::string& energyType) : Card("Energy"), energyType(energyType) {}

void EnergyCard::displayInfo() {
    cout << "Energy Card - Name: " << getCardName()
         << ", Type: " << energyType << endl;
}

string EnergyCard::getEnergyType() const {
    return energyType;
}
