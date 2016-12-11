//
//  Players.hpp
//  CardGame
//
//  Created by Jerry Zhang on 2016-11-07.
//  Copyright © 2016 FZhang_HYANG. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "Chain.hpp"
#include "Hand.hpp"
using namespace std;
/*
 Also add the insertion operator to print a Player to an std::ostream. The player's name, the number of coins in the player's possession and each of the chains (2 or 3, some possibly empty) should be printed. Note that the Hand is printed with a separate function. The player printout may look as follows:
 Jane     3 coins
 Ruby     R R R R
 Quartz   Q
 Player needs a constructor which accepts an std::istream and reconstruct the Player from file. Player( std::istream&, CardFactory* )
 */
class Player{
    
    int currentNumChains;
    int maxNumChains;
    int numCoins=0;
    Hand* myHand;
    
public:
    string name;
    Chain_Base* myChain1; 
    Chain_Base* myChain2;
    Chain_Base* myChain3;
    // Player( std::string& ) constructor that creates a Player with a given name.
    
    Player();
    Player& operator+=( int coins);
    
    
    //Player( std::istream& o, CardFactory* factory);
    //std:string getName() get the name of the player.
    string getName();
    void setName(string name);
    
    //int getNumCoins() get the number of coins currently held by the player.
    int getNumCoins();
    void setCoins(int a);
    
    //int getMaxNumChains() returns either 2 or 3.
    int getMaxNumChains() ;
    void setMaxChains(int a);
    
    //Chain_Base& operator[](int i) returns the chain at position i.
    //Chain_Base& operator[](int i);
    int getNumChains();
    void setNumChains(int i);
    
    Hand* getHand();
    void setHand(Deck& deck);
    
    Chain_Base* getChain(int i);
    
    
    //int getNumChains() returns the number of non-zero chains
    

    void addNewChain();
    
    
    // void buyThirdChain() adds an empty third chain to the player for two coins. The functions reduces the coin cousnt for the player by two. If the player does not have enough coins then an exception NotEnoughCoins is thrown.
    
    void buyThirdChain();
    
    // void printHand(std::ostream&, bool) prints the top card of the player's hand (with argument false) or all of the player's hand (with argument true) to the supplied std::ostream.
    //void printHand(std::ostream&, bool);
    
    friend ostream& operator<<(ostream& os, const Player* a) {
        if ( a->numCoins>1){
            os <<"Player "<< a->name << " has " << a->numCoins << " coins " << endl;
            // override insertion https://msdn.microsoft.com/en-us/library/1z2f6c2k.aspx
        }
        else{
            os <<"Player "<< a->name << " has " << a->numCoins << " coins " << endl;
            
        }
        return os;
    }
};

#endif  //Players_hpp
