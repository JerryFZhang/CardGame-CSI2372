//
//  Hand.cpp
//  CardGame
//
//  Created by Jerry Zhang on 2016-11-07.
//  Copyright © 2016 FZhang_HYANG. All rights reserved.
//

#include "Hand.hpp"
//Hand is well mapped by a queue since players have to keep their hand in order and the first card drawn is the first card played. The only derivation from this pattern is if players discard a card from the middle in Step 4 in the above description of a player's turn. Therefore, we can use a std::vector to remove at an arbitrary location with a std::queue adapter. This will make removal somewhat inefficient, i.e., O(n) but it is rare and we can accept it
/*
 Hand& operator+=(Card*) adds the card to the rear of the hand
 Card* play() returns and removes the top card from the player's hand.
 Card* top() returns but does not remove the top card from the player's hand.
 Card* operator[](int) returns and removes the Card at a given index.
 Also add the insertion operator to print Hand on an std::ostream. The hand should print all the cards in order.
 Hand needs a constructor which accepts an std::istream and reconstruct the Hand from file. Hand( std::istream&, CardFactory* )
 */
Hand& Hand::operator+=(Card* c){
    onHand.push(c);
    return *this;
}
Card* Hand::play(){
    Card* topMostOnHand =onHand.front();
    onHand.pop();
    return topMostOnHand;
}
Card* Hand::top(){
    return onHand.front();
}
bool Hand::isEmpty(){
    if (onHand.size()==0){
        return true;
    }
    else{
        return false;
    }
}

Card* Hand::index(int j){
    std::queue<Card*> newHand;
    int i=0;
    Card* theOne = nullptr;
    int a =onHand.size();
    while (i!= a){
        if(i==j){
            theOne = onHand.front();
            newHand.push(theOne);
            onHand.pop();
        }
        else{
            newHand.push(onHand.front());
            onHand.pop();
        }
        i++;
    }
    
    for(int j=0;j<a;j++){
        onHand.push(newHand.front());
        newHand.pop();
    }
    
    return theOne;

}
//Card* operator[](int) returns and removes the Card at a given index.
Card* Hand::operator[](int j){
    std::queue<Card*> newHand;
    int i=0;
    Card* theOne = nullptr;
    int a =(int)onHand.size();
    while (i!= a){
        if(i==j){
            theOne = onHand.front();
            onHand.pop();
        }
        else{
            newHand.push(onHand.front());
            onHand.pop();
        }
        i++;
    }
    
    for(int j=0;j<a;j++){
        onHand.push(newHand.front());
        newHand.pop();
    }
    
    return theOne;
}
