//
//  main.cpp
//  CardGame
//
//  Created by YangHuairuo on 2016-11-01.
//  Copyright © 2016 FZhang_HYANG. All rights reserved.
//

#include <iostream>
#include "CardFactory.hpp"
#include "DiscardPile.hpp"
#include "Table.hpp"

#include "Player.hpp"
//#include "Card.cpp"
#include "TradeArea.hpp"
using namespace  std;

void initPlayer(string , string);
void populateDeck();
void turn (Player * t);
void setGame();
void askForBuyingChain(Player *t);
void addCardFromTradeArea(Player *p);
void discardOneArbitrary();
void playHandCard(Player *p);
void sell();
void castAndAdd(Chain_Base*, Card*);
void drawThree();
void seperator();
void drawThreeChainOrLeave(Player* p);
void ChainCard(Chain_Base* , Card*);

Player *A;
Player *B;
Table* gameTable;
Deck *gameDeck;
CardFactory *gameFactory;
DiscardPile *gameDiscard;
TradeArea* gameTrade;

int main() {
    
    gameFactory = new CardFactory();
    
    // Asking for player names.
    string player1Name;
    string player2Name;
    cout<<"Game started."<< "\n" <<"Enter Player 1's name:"<<endl;
    cin >>player1Name;
    seperator();
    cout<<"Enter player 2's name:"<<endl;
    cin >>player2Name;
    
    initPlayer(player1Name,player2Name);
    seperator();
    cout<<"Player 1: "<<(*A).name<< " has joined the game"<< endl;
    cout<<"Player 2: "<<(*B).name<< " has joined the game"<< endl;
    seperator();
    
    setGame();
    //clog<<"----setGame----"<<endl;
    //vector empty, http://en.cppreference.com/w/cpp/container/vector/empty
    //while(!(gameDeck->empty())){
    //clog<<"----while----"<< endl;
    turn (A);
//    turn (B);
    //}
}

void initPlayer(string player1Name, string player2Name){
    // Initiation and player creation.
    A = new Player();
    B = new Player();
    A->setName(player1Name);
    B->setName(player2Name);
    //End of initiating players
}

void setGame(){
    //set the deck
    populateDeck();
    //clog<<"----populateDeck----"<<endl;
    
    //player draw 5 initial cards
    A->setHand(*gameDeck);
    B->setHand(*gameDeck);
    //clog<<"----setHand----"<<endl;
    
    //innitialize dscard and trade
    gameDiscard = new DiscardPile();
    gameTrade = new TradeArea();
    //clog<<"----gameDiscard----"<<endl;
    
    //set the game table
    gameTable =new Table(A, B, gameDeck, gameDiscard, gameTrade);
    
    
    
}

void populateDeck(){
    //Populate Deck
    gameDeck = gameFactory->getDeck();
    //clog<<"----populateDeck----"<< endl;
}

void playerDraw(Player* p,Card *c) {
    //clog<<"----playerDraw----"<<endl;
    cout<<"Card drew: "<<c->getName()<<endl;
    *(p->getHand()) +=c;
}

void askForBuyingChain(Player *t){
    //clog<<"----askForBuyingChain----"<<endl;
    string userAnswer;
    cout<<"You are eligible for puchasing an extra chain with 3 coins.\n"<<"Type \"y\" to buy, type anything else to cancel."<<endl;
    cin >> userAnswer;
    if(userAnswer == "y"){
        t->buyThirdChain();
        seperator();
        cout<<"Now you have 3 chains!"<<endl;
        seperator();
    }
}
void addTradeCardToPlayer(Player* p, Card* c){
    //clog<<"----addTradeCardToPlayer----"<<endl;
    if ((*p).getMaxNumChains() == (*p).getNumChains()){
        for (int i =0;i<(p->getNumChains()-1);++i){
            if ((p->getChain(i)->getType() == (*c).getName())){
                cout<<"There is a card of { "<<c->getName()<<" } in trade area. Type \"y\" to add it to your curren chain: {"<<(p->getChain(i)->getType())<<"}, type anything else to disgard."<<endl;
                string ans;
                cin>>ans;
                if(ans == "y"){
                    castAndAdd(p->getChain(i),c);
                }
                else{
                    cout<<"This card is discard"<<endl;
                }
            }
        }
        cout<<"You have no empty chain, therefore you can not add card from trade area!"<<endl;
    }
    else{
        if(p->getNumChains()==0){
            cout<< "If you want to add a new chain of ["<< (*c).getName()<<"]. Type y to add."<<endl;
            string ans;
            cin>>ans;
            if (ans == "y"){
                p->addNewChain();
                Chain_Base* thisChain = p->getChain(p->getNumChains()-1);
                ChainCard(p->getChain(0), c);
                cout<<"Chain Type {"<<thisChain->getType()<<"}";
                
            }
            else{
                cout<<"This card is discard"<<endl;
            }
            
        }
        else{
            
            for (int i =0;i<p->getNumChains();++i){
                Chain_Base * thisChain = p->getChain(i);
                cout << thisChain->getType()<< endl;
                if ((thisChain->getType() == (*c).getName())){
                    cout<<"There is "<<c->getName()<<" in trade area. Type \"y\" to add it to your curren chain: {"<<(thisChain->getType())<<"} type anything else to disgard."<<endl;
                    string ans;                    cin>>ans;
                    if(ans == "y"){
                        ChainCard(p->getChain(i), c);
                        cout<<thisChain;

                        
                    }
                    else{
                        cout<< "If you want to add a new chain of { "<< (*c).getName()<<"}. Type \"y\" to add, type anything else to disgard."<<endl;
                        string ans;
                        cin>>ans;
                        if (ans == "y"){
                            p->addNewChain();
                            Chain_Base* thisChain = p->getChain(p->getNumChains());
                            ChainCard(p->getChain(i), c);
                            cout<<"Added to your {"<<thisChain->getType()<<"}";
                        }
                        else{
                            cout<<"This card is discard"<<endl;
                        }
                    }
                    
                    
                }
            }}
    }
}


void addCardFromTradeArea(Player *p){
    //clog<<"----addCardFromTradeArea----"<<endl;
    cout<<"Trade area has "<<gameTrade->numCards()<<" cards\n";
    cout<<gameTrade;
    seperator();
    cout<<"Do you want to chain up these card? Type \"y\" to confirm, type anything else to cancel."<<endl;
    
    string addORnot;
    cin>>addORnot;
    if (addORnot == "y"){
        for (auto cardInTA: *gameTrade->tradeList){
            addTradeCardToPlayer(p, cardInTA);
        }
        seperator();
    }
}

void discardOneArbitrary(Player *p){
    //	2.	Then, the player has the option of discarding one arbitrary card (not necessarily in order) from his/her hand on the discard pile face up.
    
    // User input
    string wishToDiscard;
    //clog<<"----discardOneArbitrary----"<<endl;
    cout<<"Do you want to dicard a card? Type \"y\" for yes, type anything else for no."<<endl;
    cin>>wishToDiscard;
    
    if (wishToDiscard == "y"){
        int id;
        cout<<p->getHand();
        seperator();
        cout<<"Which card do you want to discard? Type the id of the card:"<<endl;
        cin>>id;
        
        if (id >=0 && id< p->getHand()->onHand.size()){
            seperator();
            Card* temp =p->getHand()->index(id);
            cout <<"Card "<< temp->getName()<<" discarded."<<endl;
            gameDiscard->push_back(temp);
            seperator();
            cout<<p->getHand();
            cout<<"Add card is not yet implemented"<<endl;
            
            
        }
    }else{
        cout <<"Nothing discarded."<<endl;
        cout<<p->getHand();
    }
    
}
void playHandCard(Player* p){
    seperator();
    string an;
    //clog<<"----playHandCard----"<<endl;
    for (int i=0;i<(p->getHand()->onHand.size());++i){
          Card* cardToBePlayed =(*p->getHand()).index(i);
        cout<<"Do you wanna play card: [" << cardToBePlayed->getName()<<"]? y for yes"<<endl;
        cin>> an;
        if(an == "y"){
        
                ChainCard(p->getChain(i), cardToBePlayed);

        }
    }
}

void drawThree(Player * p){
    //	1.	The player draws three cards; from the draw deck and places them in the trade area.
    //clog<<"----drawThree----"<<endl;
    
    cout<<gameTrade;
    seperator();
    cout<<"Now drewing card from deck and put into trade area, press anykey to continue."<<endl;
    string s;
    cin>>s;
    for (int i = 0; i< 3; i ++){
        Card* c = gameDeck->draw();
        cout<<"Card drew: "<<c->getName()<<endl;
        gameTrade->tradeList->push_back(c);
    }
    
    cout<<gameTrade;
    seperator();
    
    //Next, the player draws cards from the discard pile as long as the card matches one of the stones in the trade area.
    //Once the top card does not match (or the pile is empty), the player can either chain the cards or leave them in the trade area for the next player.
    cout<<"Card drew: from disaded pile"<<endl;
    cout<<gameDiscard->top()->getName();
    seperator();
    cout<<"Looking in to Table Area"<<endl;
    cout<<gameTrade;
    seperator();
    bool matched = false;
    if (!gameDiscard->isEmpty()){
        for(auto& item: *gameTrade->tradeList){
            if (item->getName() == gameDiscard->top()->getName()){
                string answer;
                cout<<"A "<< item->getName() <<" card matches one of the stones in the trade area, do you want to draw?"<<endl;
                cout<<"Type \"y\" for yes, anything else for no."<<endl;
                cin>>answer;
                if (answer == "y"){
                    cout<<"Card drew: "<<item->getName()<<endl;
                    //add card hereererere
                    cout<<"Add card is not yet implemented"<<endl;
                }else{
                    cout<<"Skipped"<<endl;
                }
                matched = true;
            }else{
//                cout<<""<<" 1 "<<item->getName()<<endl;
                
            }
        }
    }else{
        drawThreeChainOrLeave(p);
    }
    
    if (matched){
        //Do nothin
    }else{
        drawThreeChainOrLeave(p);
    }
    
    //	As in Step 2, if the player has currently no such chain matching the stone of the card, an old chain on the table will have to be tied and sold, and then a new chain is started. 


}

void drawThreeChainOrLeave(Player * p){
    string answer;
    cout<<"No match found. You now have the choice to chain the cards ot leave it in the TradeArea."<<endl;
    cout<<"Type \"y\" to chain them, type anything else to leave it."<<endl;
    cin>> answer;
    if (answer =="y"){
        // call chaining - to be implemented
    }
    else{
        // do nothing
    }
}

void castAndAdd(Chain_Base* current, Card * car){

    // cast base class to specific chain
    switch(car->getID()){
        case 1:{
            Quartz* a= dynamic_cast<Quartz*>(car);
            Chain<Quartz> * A = new Chain<Quartz>(  a);
            A->setType("Quartz");
            
            (*A)+=a;
            current = A;
            break;
        }
        case 2:{
            Chain<Hematite>* B= dynamic_cast< Chain<Hematite>* >(current);
            B->setType("Hematitie");
            Hematite* b= dynamic_cast<Hematite*>(car);
            (*B)+=b;
            current = B;
            break;
        }
        case 3:{
            Chain<Obsidian>* C = dynamic_cast< Chain<Obsidian>* >(current);
            C->setType("Obsidian");
            Obsidian* c= dynamic_cast<Obsidian*>(car);
            (*C)+=c;
            current = C;
            break;
        }
        case 4:{
            Chain<Malachite>* D = dynamic_cast< Chain<Malachite>* >(current);
            D->setType("Malachite");
            Malachite* d= dynamic_cast<Malachite*>(car);
            (*D)+=d;
            current =D;
            break;
        }
        case 5:{
            Chain<Turquoise>* E= dynamic_cast< Chain<Turquoise>* >(current);
            E->setType("Turquoise");
            Turquoise* e= dynamic_cast<Turquoise*>(car);
            (*E)+=e;
            current = E;
            break;
        }
            
        case 6:{
            Chain<Ruby>* F= dynamic_cast< Chain<Ruby>* >(current);
            F->setType("Ruby");
            Ruby* f= dynamic_cast<Ruby*>(car);
            (*F)+=f;
            current =F;
            break;
        }
        case 7:{
            Chain<Amethyst>* Pu =
            dynamic_cast< Chain<Amethyst>* >(current);
            Pu->setType("Amethyst");
            Amethyst* g= dynamic_cast<Amethyst*>(car);
            (*Pu)+=g;
            current = Pu;
            break;
        }
        case 8:{
            Chain<Emerald>* H= dynamic_cast< Chain<Emerald>* >(current);
            H->setType("Emerald");
            Emerald* h= dynamic_cast<Emerald*>(car);
            (*H)+=h;
            current =H;
            break;
        }
        default:{
            seperator();
        }
    }
}

void ChainCard(Chain_Base* p, Card* c){
    // to be implemented
    //input : player-> chain, card
    //chain
    cout<<"Chain card to be implemented."<<endl;
}
// Too lazy to print
void seperator(){
    cout<<"--------------------------------"<<endl;
}

// Game logic
void turn(Player *t){

    cout<<"Player "<<(*t).name<<" is playing..."<<endl;
    //clog<<"----gameTable----"<<endl;
    seperator();
    gameTable->print(cout);
    seperator();
    if(t->getNumCoins()>=3){
        askForBuyingChain(t);
    }
    
    //Draw
    playerDraw(t, gameDeck->draw());
    cout<<t->getHand();
    seperator();
    gameTrade->tradeList->push_back(new Quartz);
    gameTrade->tradeList->push_back(new Quartz);
    gameTrade->tradeList->push_back(new Amethyst);
    if(!gameTrade->isEmpty()){
        addCardFromTradeArea(t);
    }
    
   
    
    playHandCard(t);
    
    discardOneArbitrary(t);
    
    drawThree(t);
    

    
}


