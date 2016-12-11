//
//  Players.cpp
//  CardGame
//
//  Created by Jerry Zhang on 2016-11-07.
//  Copyright © 2016 FZhang_HYANG. All rights reserved.
//

#include "Player.hpp"
/*
 Player( std::string& ) constructor that creates a Player with a given name. std:string getName() get the name of the player.
 int getNumCoins() get the number of coins currently held by the player. Player& operator+=( int ) add a number of coins
 int getMaxNumChains() returns either 2 or 3.
 int getNumChains() returns the number of non-zero chains Chain_Base& operator[](int i) returns the chain at position i.
 void buyThirdChain() adds an empty third chain to the player for two coins. The functions reduces the coin count for the player by two. If the player does not have enough coins then an exception NotEnoughCoins is thrown.
 void printHand(std::ostream&, bool) prints the top card of the player's hand (with argument false) or all of the player's hand (with argument true) to the supplied std::ostream.
 Also add the insertion operator to print a Player to an std::ostream. The player's name, the number of coins in the player's possession and each of the chains (2 or 3, some possibly empty) should be printed. Note that the Hand is printed with a separate function. The player printout may look as follows:
 Jane     3 coins
 Ruby     R R R R
 Quartz   Q
 Player needs a constructor which accepts an std::istream and reconstruct the Player from file. Player( std::istream&, CardFactory* )
 */


Player::Player(){
    setName("");
    setNumChains(0);
    setMaxChains(2);
    setCoins(0);
    myHand = new Hand();
    myChain1 = new Chain_Base();
    myChain2 = new Chain_Base();
    myChain3 = new Chain_Base();
    myChain1->chainID =0;
    myChain2->chainID=1;
    myChain3->chainID =2;
    
}

void Player::setName(string n){
    name = n;
}
int Player::getNumCoins(){
    return numCoins;
}
void Player::setCoins(int a){
    numCoins = a;
}



//int getMaxNumChains() returns either 2 or 3
void Player::setMaxChains(int a){
    maxNumChains =a;
}
int Player::getMaxNumChains(){
    return maxNumChains;
}

//Player::Player( std::istream&, CardFactory* ){
////Implement later
//}
int Player::getNumChains(){
    
    return currentNumChains;
}
void Player::setNumChains(int i){
    currentNumChains = i;
}

Hand* Player::getHand(){
    return myHand;
}
void Player::setHand(Deck& deck) {
    for (int i=0; i<5; ++i) {
        (*myHand) += deck.draw();
    }
}
Chain_Base* Player::getChain(int i){
    switch (i) {
        case 0:
            return myChain1;
            break;
        case 1:
            return myChain2;
        case 2:
            return myChain3;
        default:
            return nullptr;
            break;
    }
}



//Chain_Base& operator[](int i) returns the chain at position i.
//Chain_Base& operator[](int i);


//Player& operator+=( int );

//int getNumChains() returns the number of non-zero chains

// void buyThirdChain() adds an empty third chain to the player for two coins. The functions reduces the coin cousnt for the player by two. If the player does not have enough coins then an exception NotEnoughCoins is thrown.





void Player::addNewChain() {
    if (currentNumChains >= maxNumChains) {
        cout<<"No chain can be added"<<endl;
    }
    else{
       ++currentNumChains;
       
    }
}

void Player::buyThirdChain(){
    if (numCoins< 3){
        cout<<"Transaction cannot be completed, you have less that 2 coins!"<<endl;
    }
    else{
        if(currentNumChains == 3){
            cout<<"You cannot buy more chains!"<<endl;
        }
        else{
            if (currentNumChains == 2 && numCoins >= 2){
                numCoins = numCoins - 3;
                ++currentNumChains;
            }
        }
        
    }
}
//
//void Player::printHand(std::ostream& o, bool list) {
//    if (!list) {
//        o << (*myHand).top()->getName();
//    }
//    else {
//        o << &(*myHand);
//    }
//}


//// void printHand(std::ostream&, bool) prints the top card of the player's hand (with argument false) or all of the player's hand (with argument true) to the supplied std::ostream.
//void Player::printHand(std::ostream&, bool){

//}



