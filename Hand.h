//
//  Hand.hpp
//  CardGame
//
//  Created by Jerry Zhang on 2016-11-07.
//  Copyright © 2016 FZhang_HYANG. All rights reserved.
//

#ifndef Hand_hpp
#define Hand_hpp

#include <stdio.h>
#include <iostream>
#include <queue>
#include "CardFactory.hpp"


//Hand is well mapped by a queue since players have to keep their hand in order and the first card drawn is the first card played. The only derivation from this pattern is if players discard a card from the middle in Step 4 in the above description of a player's turn. Therefore, we can use a std::vector to remove at an arbitrary location with a std::queue adapter. This will make removal somewhat inefficient, i.e., O(n) but it is rare and we can accept it
/*
 Hand& operator+=(Card*) adds the card to the rear of the hand
 Card* play() returns and removes the top card from the player's hand.
 Card* top() returns but does not remove the top card from the player's hand.
 Card* operator[](int) returns and removes the Card at a given index.
 Also add the insertion operator to print Hand on an std::ostream. The hand should print all the cards in order.
 Hand needs a constructor which accepts an std::istream and reconstruct the Hand from file. Hand( std::istream&, CardFactory* )
 */
class Hand{
    
public:
    std::queue<Card*> onHand;
    Hand& operator+=(Card* c);
    Card* play();
    Card* top();
    Card* index(int j);
    bool isEmpty();
     Card* operator[](int j);
    friend ostream& operator<<(std::ostream& os,  Hand* mhand){
        
        // override insertion https://msdn.microsoft.com/en-us/library/1z2f6c2k.aspx
        if(mhand->onHand.empty()){
            os << "You have no card on hand"<< endl;
        }
        else{
            os<<"Cards on hand: ";
            for (int i=0;i<mhand->onHand.size();i++){
                os<<"["<<i<<"]:"<<(*mhand).index(i)->getName() <<" ";
            }
            os<<endl;
        }
        return os;
    }
    //Hand( std::istream& HIStream, CardFactory* cf);
    
};

#endif /* Hand_hpp */
