//
//  CardFactory.hpp
//  CardGame
//
//  Created by YangHuairuo on 2016-11-08.
//  Copyright © 2016 FZhang_HYANG. All rights reserved.
//

#ifndef CardFactory_hpp
#define CardFactory_hpp

#include <stdio.h>
#include "Deck.hpp"
#include "Card.hpp"

class CardFactory {
public:
    Deck* myDeck;
    CardFactory* currentFact;
    CardFactory* getFactory();
    void add(Deck a, Card* cptr);
    CardFactory();
    Deck* getDeck();
private:
    const static int numOfQuartz=20;
    const static int numOfHematite=18;
    const static int numOfObsidian=16;
    const static int numOfMalachite=14;
    const static int numOfTurquoise=12;
    const static int numOfRuby=10;
    const static int numOfAmethyst=8;
    const static int numOfEmerald=6;
    const static int numOfTotal = 104;
};
#endif /* CardFactory_hpp */
