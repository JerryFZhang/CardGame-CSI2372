//
//  Chain.hpp
//  CardGame
//
//  Created by Jerry Zhang on 2016-11-07.
//  Copyright © 2016 FZhang_HYANG. All rights reserved.
//

//#include "CardFactory.hpp"
#include "Card.hpp"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>
using namespace std;

class Chain_Base {
    
public:
    int chainID;
    string ChainType="";
    Chain_Base() = default;
    Chain_Base(string t):ChainType (t) {}
    virtual ~Chain_Base() = default;
    virtual int sell(){
        return 0;
    };
     virtual string getType() {
        return ChainType;
    }
    virtual void setType(string newType){
        ChainType = newType;
    }
    virtual void print(std::ostream&) const {
        
    };
    
};



template <class T>
class Chain:public Chain_Base{
public:
    int chainID;
    std::vector<T*> thisChain;
    

    Chain<T>(T*t): Chain_Base(t->getName()){
        thisChain.push_back(t);
    }
    Chain<T>()=default;
    virtual Chain<T>& operator+=( T * c){
        if (c->getName()==ChainType){
            thisChain.push_back(c);
            return *this;
        }
        else{
            cout<<"Illegal type"<<endl;
            return *this;
        }
        
    }
    virtual void setType(string newType){
        ChainType = newType;
    }
    virtual string getType() {
        return ChainType;
    }
    //int sell() counts the number cards in the current chain and returns the number coins according to the function Card::getCardsPerCoin.
    virtual int sell(){
        int numberOfCards = thisChain.size();
        
        if (numberOfCards >thisChain[0]->getCardsPerCoin(4)){
            return 4;
        }
        
        
        if(numberOfCards >thisChain[0]->getCardsPerCoin(3)){
            return 3;
        }
        
        if (numberOfCards >thisChain[0]->getCardsPerCoin(2)){
            return 2;
        }
        
        if(numberOfCards >thisChain[0]->getCardsPerCoin(1)){
            return 1;
        }
        
        else{
            return 0;
        }
    }
    virtual void print(std::ostream& os) const{
        os<<"Chain {"<< ChainType<<"} :";
        for (auto& c : thisChain) {
            os<< c<< " ";
        }
    }
    
    virtual ~Chain() {
        thisChain.erase(thisChain.begin(), thisChain.end());
    }
};











