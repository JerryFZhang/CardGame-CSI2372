//
//  Table.hpp
//  CardGame
//
//  Created by Jerry Zhang on 2016-11-07.
//  Copyright © 2016 FZhang_HYANG. All rights reserved.
//

#ifndef Table_hpp
#define Table_hpp
#include <stdio.h>
#include <iostream>
#include <string>
#include <istream>
#include "Player.hpp"
#include "TradeArea.hpp"
#include "Deck.hpp"
#include "DiscardPile.hpp"
using namespace std;
/*
 Table will manage all the game components. It will hold two objects of type Player, the Deck and the DiscardPile, as well as the TradeArea.
 
 */
class Table{
    Player* A;
    Player* B;
    Deck* myD;
    DiscardPile* myDP;
    TradeArea* myTA;
public:
    Table(Player* p1, Player* p2, Deck* d, DiscardPile* dp, TradeArea* ta);
    bool win( std::string& );
    void print(std::ostream&);
};
#endif /* Table_hpp */
