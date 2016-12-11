//
//  Table.cpp
//  CardGame
//
//  Created by Jerry Zhang on 2016-11-07.
//  Copyright © 2016 FZhang_HYANG. All rights reserved.
//

#include "Table.hpp"
/*Also add the insertion operator to print a Table to an std::ostream. The two players, the discard pile, the trading area should be printed. This is the top level print out. Note that a complete output with all cards for the pause functionality is printed with the separate function print above.
 */

//Table will manage all the game components. It will hold two objects of type Player, the Deck and the DiscardPile, as well as the TradeArea.
Table::Table(Player* p1, Player* p2, Deck* d, DiscardPile* dp, TradeArea* ta){
    A=p1;
    B=p2;
    myD=d;
    myDP=dp;
    myTA=ta;
    
}

//Table needs a constructor which accepts an std::istream and reconstruct the Table from file. Player( std::istream&, CardFactory* )
//Will be implement later........

//bool win( std::string& ) returns true when a player has won. The name of the player is returned by reference (in the argument). The winning condition is that all cards from the deck must have been picked up and then the player with the most coins wins.
bool Table::win (string & whoWin){
    if(myD->size()==0){
        if (A->getNumCoins()>B->getNumCoins()){
            whoWin = (*A).name;
            return true;
        }
        if (B->getNumCoins()>B->getNumCoins()){
            whoWin = (*B).name;
            return true;
        }
        else{
            whoWin = "EVEN!";
            return true;
        }
    }
    else {return false;}
}

//void print(std::ostream&) prints the complete table with all content. Intended for serialization to file.
void Table::print(std::ostream& os) {
    os << "Now:\n"<<"\t"<< A <<"\t"<< B<<"\t"<< myDP<<"\t"<< myTA;
}


