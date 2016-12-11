//
//  DiscardPile.cpp
//  CardGame
//
//  Created by Jerry Zhang on 2016-11-07.
//  Copyright © 2016 FZhang_HYANG. All rights reserved.
//

#include "DiscardPile.hpp"
//DiscardPile must support insertion and removal but not at random locations but all at the end. Again a std::vector will work fine but here we can use simple aggregation.

/*
 The DiscardPile holds cards in a std::vector and is similar to Deck.
 DiscardPile& operator+=( Card* ) discards the card to the pile.
 Card* pickUp() returns and removes the top card from the discard pile.
 Card* top() returns but does not remove the top card from the discard pile.
 void print( std::ostream& ) to insert all the cards in the DiscardPile to an std::ostream.
 Also add the insertion operator to insert only the top card of the discard pile to an std::ostream. The DiscardPile needs a constructor which accepts an std::istream and reconstructs the
 DiscardPile from file.
 DiscardPile( std::istream&, CardFactory* )
 
 */
DiscardPile& DiscardPile::operator+=( Card* c){
    this->push_back(c);
    return *this;
}
Card* DiscardPile::pickUp(){
    if(this->empty()){
        return nullptr;
    }
    else{
        Card* temp = topp;
        this->erase(this->end()-1);
        return temp;
    }
    
}
Card* DiscardPile::top(){
    topp = this->back();
    return topp;
}
bool DiscardPile::isEmpty(){
    if(this->size()==0){
        return true;
    }
    else{
        return false;
    }
}






