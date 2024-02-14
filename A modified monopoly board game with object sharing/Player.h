//
// Created by ayber on 5.05.2023.
//
#include "Board.h"
#include <string>
#include <iostream>

#ifndef HW55_PLAYER_H
#define HW55_PLAYER_H

/**
 * @brief Player class of the game monopoly in the main.cpp. Shares object of the board,
 * keeps object's name as string, balance as int and position on the board as node pointer.
 */
class Player {
public:
    Player(Board & sharedBoard, string name, int initialCapital);
    int move(int steps);
    Node * where_am_I();
    void pay_to_player(Player & otherPlayer, int money);
    int get_balance()const;
    void deposit_money(int depositAmount);
    void buy_slot(int priceOfSlot);
    bool is_bankrupt()const;
    void display()const;




private:
    Board& board;
    string name;
    int balance;
    Node* currentPos;
};








#endif //HW55_PLAYER_H
