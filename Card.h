#ifndef CARD_H
#define CARD_H

#include <string>

// Card.h - Declares the base `Card` type used by all card classes in the project.

class Card {
protected:
    std::string cardName;

public:
    Card(const std::string& name);
    virtual ~Card();

    const std::string& getCardName() const;

    
    virtual void displayInfo() = 0;
};

#endif
