//
//  TradeArea.hpp
//  CardGame
//
//  Created by Jerry Zhang on 2016-11-07.
//  Copyright © 2016 FZhang_HYANG. All rights reserved.
//

#ifndef TradeArea_hpp
#define TradeArea_hpp

#include <stdio.h>
#include <list>
#include <iostream>
#include "CardFactory.hpp"


//TradeArea needs random access as the cards are removed from the area depending on which cards the Player wants to chain. We will use std::list to support random access by gemstone type.
/*
 The class TradeArea will have to hold cards openly and support random access insertion and removal. The TradeArea holds cards in a std::list.
 TradeArea& operator+=( Card* ) adds the card to the trade area but it does not check if it is legal to place the card.
 bool legal( Card* ) returns true if the card can be legally added to the TradeArea, i.e., a card of the same gemstone is already in the TradeArea.
 Card* trade( string ) removes a card of the corresponding gemstone name from the trade area. int numCards() returns the number of cards currently in the trade area.
 Also add the insertion operator to insert all the cards of the trade area to an std::ostream.
 The TradeArea needs a constructor which accepts an std::istream and reconstruct the TradeArea from file.
 TradeArea( std::istream&, CardFactory* )
 
 */

class TradeArea{
    
    
    
public:
    // TradeArea& operator+=( Card* ) adds the card to the trade area but it does not check if it is legal to place the card.
    list<Card*>* tradeList;
    TradeArea(){
        tradeList = new list<Card*>;
    }
    TradeArea& operator+=( Card* c);
    
    // bool legal( Card* ) returns true if the card can be legally added to the TradeArea, i.e., a card of the same gemstone is already in the TradeArea.
    bool legal( Card* c);
    
    //Card* trade( string ) removes a card of the corresponding gemstone name from the trade area. int numCards() returns the number of cards currently in the trade area.
    Card* trade( std::string str);
    int numCards();
    bool isEmpty();
    
    friend ostream& operator<<(std::ostream& os,  TradeArea* myTA) {
        // override insertion https://msdn.microsoft.com/en-us/library/1z2f6c2k.aspx
        if (myTA->tradeList->size()>0){
            os<< "Trade area has: ";
            list<Card*>::iterator it = myTA->tradeList->begin();
            for(int i=0;i < myTA->tradeList->size();i++){
                os<< (*it)->getName()<<" ";
                ++it;
            }
            os<<endl;
        }
        
        // use << to insert
        // see  http://en.cppreference.com/w/cpp/io/basic_ostream/operator_ltlt2
        
        else{
            os << "Trade area" << " has no cards." << endl;
            
        }
        return os;
    }
    
    
    
    //TradeArea( std::istream& TAIStream, CardFactory* cf);
};
#endif /* TradeArea_hpp */
