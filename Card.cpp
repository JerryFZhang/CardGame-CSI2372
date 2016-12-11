//
//  Card.cpp
//  CardGame
//
//  Created by Jerry Zhang on 2016-11-07.
//  Copyright © 2016 FZhang_HYANG. All rights reserved.
//

#include "Card.hpp"

//We will be practising inheritance with the different cards. Card will be an abstract base class and the eight different gemstone cards will be derived from it. All containers will hold cards through the base type. However, standard containers do not work well with polymorphic types because they hold copies, i.e., slicing will occur.

//All cards are going to be generated through a ****CardFactory**** //Doc - FactoryPattern http://stackoverflow.com/questions/5120768/how-to-implement-the-factory-method-pattern-in-c-correctly#5121500 .While here not strictly necessary, it will give us a chance to explore the factory pattern. A factory ensures that there is only a single unit in the program that is responsible to create and delete cards. Other parts of the program will only use pointers to access the cards. Note that means, we will delete the copy constructor and assignment operator in Card.

/*Create the gemstone card hierarchy. A gemstone card can be printed to console with its first character of its name. The base class Card should be abstract, derived classes Quartz, Hematite, Obsidian, Malachite, Turquoise, Ruby, Amethyst, and Emerald will have to be concrete classes.
 
 Card will have the following pure virtual functions:
 
 virtual int getCardsPerCoin( int coins ) will implement in the derived classes the above table for how many cards are necessary to receive the corresponding number of coins.
 
 virtual string getName() returns the full name of the card (e.g., Ruby).
 
 virtual void print(std::ostream& out) inserts the first character for the card into the output stream supplied as argument. You will also need to create a global stream insertion operator for printing any objects of such a class which implements the “Virtual Friend Function Idiom” with the class hierarchy.
 */

std::string Card::getName(){
    return "G";
}
int Card::getCardsPerCoin(int coins){
    return 0;
}
void Card::print(std::ostream & out){
    
}
Card:: Card(){
    
};
int Quartz::getCardsPerCoin( int coins ){
    switch (coins) {
        case 1:
            return 4;
            break;
            
        case 2:
            return 6;
            break;
            
        case 3:
            return 8;
            break;
            
        case 4:
            return 10;
            break;
            
            
        default:
            return 0;
            break;
    };
}
std::string Quartz::getName(){
    return "Quartz";
}
Quartz::Quartz(){
    
}
void Quartz::print(std::ostream& out){
    out<<'Q';
}
// use << to insert
// see  http://en.cppreference.com/w/cpp/io/basic_ostream/operator_ltlt2

Hematite::Hematite(){
    
};

int Hematite::getCardsPerCoin( int coins ){
    switch (coins) {
        case 1:
            return 3;
            break;
            
        case 2:
            return 6;
            break;
            
        case 3:
            return 8;
            break;
            
        case 4:
            return 9;
            break;
            
            
        default:
            return 0;
            break;
    };
}
std::string Hematite::getName(){
    return "Hematite";
}
void Hematite::print(std::ostream& out){
    out<<'H';
}
// use << to insert
// see  http://en.cppreference.com/w/cpp/io/basic_ostream/operator_ltlt2

Obsidian::Obsidian(){
    
};

int Obsidian::getCardsPerCoin( int coins ){
    switch (coins) {
        case 1:
            return 3;
            break;
            
        case 2:
            return 5;
            break;
            
        case 3:
            return 7;
            break;
            
        case 4:
            return 8;
            break;
            
            
        default:
            return 0;
            break;
    };
}
std::string Obsidian::getName(){
    return "Obsidian";
}
void Obsidian::print(std::ostream& out){
    out<<'O';
}
// use << to insert
// see  http://en.cppreference.com/w/cpp/io/basic_ostream/operator_ltlt2

Malachite::Malachite(){
    
}
int Malachite::getCardsPerCoin( int coins ){
    switch (coins) {
        case 1:
            return 3;
            break;
            
        case 2:
            return 5;
            break;
            
        case 3:
            return 6;
            break;
            
        case 4:
            return 7;
            break;
            
            
        default:
            return 0;
            break;
    };
}
std::string Malachite::getName(){
    return "Malachite";
}
void Malachite::print(std::ostream& out){
    out<<'M';
    // use << to insert
    // see  http://en.cppreference.com/w/cpp/io/basic_ostream/operator_ltlt2
}

int Turquoise::getCardsPerCoin( int coins ){
    switch (coins) {
        case 1:
            return 2;
            break;
            
        case 2:
            return 4;
            break;
            
        case 3:
            return 6;
            break;
            
        case 4:
            return 7;
            break;
            
            
        default:
            return 0;
            break;
    };
}
Turquoise::Turquoise(){
    
}
std::string Turquoise::getName(){
    return "Turquoise";
}
void Turquoise::print(std::ostream& out){
    out<<'T';
    // use << to insert
    // see  http://en.cppreference.com/w/cpp/io/basic_ostream/operator_ltlt2
}

int Ruby::getCardsPerCoin( int coins ){
    switch (coins) {
        case 1:
            return 2;
            break;
            
        case 2:
            return 4;
            break;
            
        case 3:
            return 5;
            break;
            
        case 4:
            return 6;
            break;
            
            
        default:
            return 0;
            break;
    };
}
std::string Ruby::getName(){
    return "Ruby";
}
Ruby::Ruby(){
    
}
void Ruby::print(std::ostream& out){
    out<<'R';
    // use << to insert
    // see  http://en.cppreference.com/w/cpp/io/basic_ostream/operator_ltlt2
}

int Amethyst::getCardsPerCoin( int coins ){
    switch (coins) {
        case 1:
            return 2;
            break;
            
        case 2:
            return 3;
            break;
            
        case 3:
            return 4;
            break;
            
        case 4:
            return 5;
            break;
            
            
        default:
            return 0;
            break;
    };
}
std::string Amethyst::getName(){
    return "Amethyst";
}
void Amethyst::print(std::ostream& out){
    out<<'A';
    // use << to insert
    // see  http://en.cppreference.com/w/cpp/io/basic_ostream/operator_ltlt2
}
Amethyst::Amethyst(){
    
}

int Emerald::getCardsPerCoin( int coins ){
    switch (coins) {
        case 2:
            return 2;
            break;
            
        case 3:
            return 3;
            break;
            
        default:
            return 0;
            break;
    };
}
std::string Emerald::getName(){
    return "Emerald";
}
void Emerald::print(std::ostream& out){
    out<<'E';
    // use << to insert
    // see  http://en.cppreference.com/w/cpp/io/basic_ostream/operator_ltlt2
}
Emerald::Emerald(){
    
}

