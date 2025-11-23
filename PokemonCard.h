#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include "Card.h"
#include <string>

class PokemonCard : public Card {
private:
    std::string pokemonType;
    std::string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;
    int coutEnergie;
    int coutEnergieActuel;
    std::string attackDescription1;
    std::string attackDescription2;
    int attackDegats;

public:
    PokemonCard(
        const std::string& pokemonName,
        const std::string& pokemonType,
        const std::string& familyName,
        int evolutionLevel,
        int maxHP,
        int hp,
        const std::string& attackDescription1,
        int coutEnergie,
        int coutEnergieActuel,
        const std::string& attackDescription2,
        int attackDegats
    );

    virtual ~PokemonCard() = default;

    void displayInfo() override;

    // Gestion des PV / dégâts
    void subirDegats(int degats);
    void heal();

    // Infos pour les attaques
    int getDegat() const;
    int getEnergieActuelle() const;
    void addEnergy(int amount = 1);
};

#endif
