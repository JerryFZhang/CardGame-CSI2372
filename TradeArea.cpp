//
//  TradeArea.cpp
//  CardGame
//
//  Created by Jerry Zhang on 2016-11-07.
//  Copyright © 2016 FZhang_HYANG. All rights reserved.
//

#include "TradeArea.hpp"



// TradeArea& operator+=( Card* ) adds the card to the trade area but it does not check if it is legal to place the card.
TradeArea& TradeArea::operator+=( Card* c){
    tradeList->push_back(c);
    return *this;
}

// bool legal( Card* ) returns true if the card can be legally added to the TradeArea, i.e., a card of the same gemstone is already in the TradeArea.
bool TradeArea:: legal( Card* c){
    list<Card*>::iterator it = tradeList->begin();
    for(int i=0;i < tradeList->size();i++){
        if( c->getName()== (*it)->getName()){
            return true;
        }
        ++it;
    }
    return false;}

int TradeArea::numCards(){
    return  (int)tradeList->size();
}
bool TradeArea::isEmpty(){
    if(tradeList->size()==0){
        return true;
    }
    else{
        return false;
    }
}
//Card* trade( string ) removes a card of the corresponding gemstone name from the trade area.

Card* TradeArea:: trade( std::string str){
    list<Card*>::iterator it = tradeList->begin();
    Card* tradeCard = nullptr;
    
    for(int i=0;i < tradeList->size();i++){
        
        ++it;
        if( (*it)->getName()==str){
            tradeCard=*it;
            tradeList->erase(it);
        }
    }
    return tradeCard;
}

//int numCards() returns the number of cards currently in the trade area.



//TradeArea( std::istream& TAIStream, CardFactory* cf);
