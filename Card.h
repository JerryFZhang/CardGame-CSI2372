//
//  Card.hpp
//  CardGame
//
//  Created by Jerry Zhang on 2016-11-07.
//  Copyright © 2016 FZhang_HYANG. All rights reserved.
//

#ifndef Card_hpp
#define Card_hpp
#include <stdio.h>
#include <iostream>



//We will be practising inheritance with the different cards. Card will be an abstract base class and the eight different gemstone cards will be derived from it. All containers will hold cards through the base type. However, standard containers do not work well with polymorphic types because they hold copies, i.e., slicing will occur.
//All cards are going to be generated through a ****CardFactory**** (Doc - FactoryPattern http://stackoverflow.com/questions/5120768/how-to-implement-the-factory-method-pattern-in-c-correctly#5121500 ) While here not strictly necessary, it will give us a chance to explore the factory pattern. A factory ensures that there is only a single unit in the program that is responsible to create and delete cards. Other parts of the program will only use pointers to access the cards. Note that means, we will delete the copy constructor and assignment operator in Card.
/*Create the gemstone card hierarchy. A gemstone card can be printed to console with its first character of its name. The base class Card should be abstract, derived classes Quartz, Hematite, Obsidian, Malachite, Turquoise, Ruby, Amethyst, and Emerald will have to be concrete classes.
 Card will have the following pure virtual functions:
 virtual int getCardsPerCoin( int coins ) will implement in the derived classes the above table for how many cards are necessary to receive the corresponding number of coins.
 virtual string getName() returns the full name of the card (e.g., Ruby).
 virtual void print(std::ostream& out) inserts the first character for the card into the output stream supplied as argument. You will also need to create a global stream insertion operator for printing any objects of such a class which implements the “Virtual Friend Function Idiom” with the class hierarchy.
 */

class Card {
public:
    int cardId = 0;
    int virtual getID(){
        return cardId;
    }
    virtual std::string getName();
    virtual int getCardsPerCoin( int coins );
    virtual void print(std::ostream& out);
    Card();
    
};
class Quartz :public Card{
public:
    int cardId = 1;
    int virtual getID(){
        return cardId;
    }
    virtual int getCardsPerCoin( int coins );
    virtual std::string getName();
    virtual void print(std::ostream& out);
    Quartz();
    //Doc - ostream http://en.cppreference.com/w/cpp/io/basic_ostream
};
class Hematite :public  Card{
public:
    int cardId = 2;
    int virtual getID(){
        return cardId;
    }
    virtual int getCardsPerCoin( int coins );
    virtual std::string getName();
    virtual void print(std::ostream& out);
    Hematite ();
};
class Obsidian :public  Card{
public:
    int cardId = 3;
    int virtual getID(){
        return cardId;
    }
    virtual int getCardsPerCoin( int coins );
    virtual std::string getName();
    virtual void print(std::ostream& out);
    Obsidian();
};
class Malachite :public  Card{
public:
    int cardId = 4;
    int virtual getID(){
        return cardId;
    }
    virtual int getCardsPerCoin( int coins );
    virtual std::string getName();
    virtual void print(std::ostream& out);
    Malachite();
    
};
class Turquoise :public  Card{
public:
    int cardId = 5;
    int virtual getID(){
        return cardId;
    }
    virtual int getCardsPerCoin( int coins );
    virtual std::string getName();
    virtual void print(std::ostream& out);
    Turquoise();
    
};
class Ruby :public  Card{
public:
    int cardId = 6;
    int virtual getID(){
        return cardId;
    }
    virtual int getCardsPerCoin( int coins );
    virtual std::string getName();
    virtual void print(std::ostream& out);
    Ruby();
};
class Amethyst :public  Card{
public:
    int cardId = 7;
    int virtual getID(){
        return cardId;
    }
    virtual int getCardsPerCoin( int coins );
    virtual std::string getName();
    virtual void print(std::ostream& out);
    Amethyst();
};
class Emerald :public  Card{
public:
    int cardId = 8;
    int virtual getID(){
        return cardId;
    }
    virtual int getCardsPerCoin( int coins );
    virtual std::string getName();
    virtual void print(std::ostream& out);
    Emerald();
};

#endif /* Card_hpp */
