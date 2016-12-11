//
//  Deck.cpp
//  CardGame
//
//  Created by Jerry Zhang on 2016-11-07.
//  Copyright © 2016 FZhang_HYANG. All rights reserved.
//

#include "Deck.hpp"
#include "Card.hpp"
//Deck will initially hold all the cards which will have to be shuffled to produce a randomized order, then players' hands are dealt and during game play players draw cards from the Deck. There is no insertion into the Deck. Deck can therefore usefully extend a std::vector.
/*
 Deck is a simple derived class from std::vector.
 Card* draw() returns and removes the top card from the deck.
 Also add the insertion operator to insert all the cards in the deck to an std::ostream.
 The Deck needs a constructor which accepts an std::istream and reconstructs the deck from file. Deck( std::istream&, CardFactory* )
 */


Card* Deck::draw(){
    if(this->empty()){
        return nullptr;
    }
    else{
        Card* last;
        last = this->back();
        this->erase(this->end()-1);
        return last;
    }
}
