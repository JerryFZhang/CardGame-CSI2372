//
//  CardFactory.cpp
//  CardGame
//
//  Created by YangHuairuo on 2016-11-08.
//  Copyright © 2016 FZhang_HYANG. All rights reserved.
//

#include "CardFactory.hpp"
#include <algorithm>
#include <random>
using namespace std;

/*The card factory serves as a factory for all the gemstone cards.
 In the constructor for CardFactory all the cards need to be created in the numbers needed for the game
 (see the above table). Ensure that no copies can be made of CardFactory and that there is at most one
 CardFactory object in your program.
*/

//--Factory pattern: http://stackoverflow.com/questions/5120768/how-to-implement-the-factory-method-pattern-in-c-correctly#5121500

CardFactory::CardFactory(){
    currentFact=this;
    myDeck= new Deck();
}

//static CardFactory* getFactory() returns a pointer to the only instance of CardFactory.
CardFactory* CardFactory::getFactory(){
    return currentFact;
}


//Deck getDeck() returns a deck with all 104 gemstonecards. Note that the 104 gemstonecardsare always the same but their order in the deck needs to be different every time.
//--Use std::shuffle to achieve this.
//--std::shuffle: http://stackoverflow.com/questions/6926433/how-to-shuffle-a-stdvector
Deck* CardFactory::getDeck(){
    
    for(int i =0;i<numOfQuartz;++i){
        Card* b =  ( new Quartz());
        myDeck->push_back(b);
    }
    for(int i=0;i<numOfHematite;++i){
        Card* h = new Hematite();
        myDeck->push_back(h);
    }
    for(int i=0;i<numOfObsidian;++i){
        Card* o = new Obsidian();
        myDeck->push_back(o);
    }
    for(int i=0;i<numOfMalachite;++i){
        Card* m = new Malachite();
        myDeck->push_back(m);
    }
    for(int i=0;i<numOfTurquoise;++i){
        Card* t = new Turquoise();
        myDeck->push_back(t);
    }
    for(int i=0;i<numOfRuby;++i){
        Card *r = new Ruby();
        myDeck->push_back(r);
    }
    for(int i=0;i<numOfAmethyst;++i){
        Card *a = new Amethyst();
        myDeck->push_back(a);
    }
    for(int i=0;i<numOfEmerald;++i){
        Card *a = new Emerald();
        myDeck->push_back(a);
    }
    auto engine = default_random_engine{};
    
    shuffle(begin(*myDeck), end(*myDeck), engine);
    return myDeck;
}
