//
//  GameTemplate.h
//  LLD_PARKING_LOT
//
//  Created by Paras Kaushik on 01/08/23.
//

#ifndef GameTemplate_h
#define GameTemplate_h
/*
 - allows us to define a 'skeleton' with concrete implemetaions in the base class
 - after details are defined this skeleton function is used
 - this has the same function as stratergy but while that used (inheritance+composoition) ie TextProcessor "has a" strategy ,
    this uses inheritace, chess game "is a" game
 **/

class Game {// skeleton "Template" of a game
public:
    explicit Game(int number_of_players): number_of_players(number_of_players){}

    void run(){ // template method whose specicis inheritors provide
        start();
        while (!have_winner())
            take_turn();
        cout << "Player " << get_winner() << " wins.\n";
    }

protected:
    virtual void start() = 0;
    virtual bool have_winner() = 0;
    virtual void take_turn() = 0;
    virtual int get_winner() = 0;

    int current_player{ 0 };
    int number_of_players;
};

class Chess : public Game {
public:
    explicit Chess() : Game{ 2 } {}

protected:
    void start() override{
        cout << "Starting a game of chess with " << number_of_players << " players\n";
    }

    bool have_winner() override{
        return turns == max_turns;
    }

    void take_turn() override{
        cout << "Turn " << turns << " taken by player " << current_player << "\n";
        turns++;
        current_player = (current_player + 1) % number_of_players;
    }

    int get_winner() override{
        return current_player;
    }

private:
    int turns{ 0 }, max_turns{ 10 };
};


#endif /* GameTemplate_h */
