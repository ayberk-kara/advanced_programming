//
// Created by ayber on 5.05.2023.
//
#include <string>
#include <iostream>
#ifndef HW55_BOARD_H
#define HW55_BOARD_H
using namespace std;
struct Node {
    string owner;
    Node* next;
    Node ();
    Node (string o, Node * p);
};



class Board {
public:

Board(int NumberOfSlots);
~Board();
void display();
string who_owns(Node* Location);
Node * returnFirst();
private:
Node * first;

};


#endif //HW55_BOARD_H
