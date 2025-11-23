#include "EnergyCard.h"
#include <iostream>
#include <string>
using namespace std;

// EnergyCard.cpp - Simple implementation for energy-card behavior and display.

EnergyCard::EnergyCard(const std::string& energyType) : Card("Energy"), energyType(energyType) {}

void EnergyCard::displayInfo() {
    cout << "Energy Card - Name: " << getCardName()
         << ", Type: " << energyType << endl;
}

string EnergyCard::getEnergyType() const {
    return energyType;
}
