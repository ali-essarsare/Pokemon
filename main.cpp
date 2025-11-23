#include "PokemonCard.h"
#include "" // main.cpp - demo runner: creates players and exercises cards
#include "TrainerCard.h"
#include "EnergyCard.h"
#include "Player.h"
#include <iostream>
using namespace std;

int main() {
    Player player1("Hadi");


    player1.addCardToBench(new EnergyCard("Electric"));
    player1.addCardToBench(new EnergyCard("Electric"));
    player1.addCardToBench(new TrainerCard("Ash", "heal all your action pokemon"));
    player1.addCardToBench(new PokemonCard ("Pikachu", "Electric", "Pikachu", 2, 100, 2, "thunder bolt ", 20 , 3, "thunder storm ", 30));

    player1.activatePokemonCard(3);
    player1.attachEnergyCard(0,0);
    player1.attachEnergyCard(0,0);

    Player player2("Germani");


    player2.addCardToBench(new EnergyCard("Grass"));
    player2.addCardToBench(new TrainerCard("Brock", "heal all your action pokemon"));
    player2.addCardToBench(new PokemonCard("Bulbasaur", "Grass", "Bulbasaur", 1, 100, 2, "leech seed ", 15 , 3, "thunder storm", 25));

    player2.activatePokemonCard(2);
    player2.attachEnergyCard(0,0);

    cout << endl; 
    player2.displayBench();
    cout << endl; 
    player2.displayAction();


    player1.attack(0, 0 , player2, 0);
    cout << endl;
    player2.displayAction();
    player2.useTrainer();
    cout << endl;
    player2.displayAction();
}
