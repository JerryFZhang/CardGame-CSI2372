//
//  DiscardPile.hpp
//  CardGame
//
//  Created by Jerry Zhang on 2016-11-07.
//  Copyright © 2016 FZhang_HYANG. All rights reserved.
//

#ifndef DiscardPile_hpp
#define DiscardPile_hpp

#include <stdio.h>
#include <vector>
#include "Card.hpp"
using namespace std;

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

class DiscardPile:public std::vector<Card*>{
    Card* topp;
public:
    DiscardPile& operator+=( Card* c);
    Card* pickUp();
    Card* top();
    bool isEmpty();
    
    friend ostream& operator<<(std::ostream& os, const DiscardPile* dp){
        
        // override insertion https://msdn.microsoft.com/en-us/library/1z2f6c2k.aspx
        if(dp->size() != 0){
            os <<"Discard pile has : " <<dp->topp<<" on top."<<endl;
        }
        else{
            os << "Discard pile has no card"<< endl;
        }
        return os;
    }
    //DiscardPile(std::istream& DPIStream, CardFactory* cf);
};

#endif /* DiscardPile_hpp */
