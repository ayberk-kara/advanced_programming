//
// Created by ayber on 5.05.2023.
//
#include <string>
#include <iostream>
#include "Board.h"
#include <iomanip>
/**
 * @brief Default constructor for struct node.
 */
Node::Node() {
    owner = "None";
    next = nullptr;
}
/**
 * @brief Parametric constructor for struct node.
 */
Node::Node(string o, Node* p) {
    owner = o;
    next = p;
}

/**
 * @brief Accessor for first data member of board.
 */
Node * Board:: returnFirst(){

    return first;
};


/**
 * @brief Parametric constructor board class. It takes integer (NumberOfSlots) and it constructs a circular linked list with the size of this integer by using Node struct.
 */
Board :: Board(int NumberOfSlots) {
    first = new Node ("None", nullptr);
    Node * ptr = first;

    for (int i = 0; i < NumberOfSlots-1; ++i) {
        Node * nextNode = new Node("None", NULL);
        ptr->next = nextNode;
        ptr = nextNode;

    }

ptr->next = first;


}
/**
 * @brief Destructor for board object.
 */
Board ::~Board(){
    // No need to check if first pointer is null or not because it can never be null.
    Node * prevNode= first->next;
    Node * ptr = prevNode->next->next;
    while(ptr!=first){
        delete prevNode;
        prevNode = ptr;
        ptr = ptr->next;


    }
    delete prevNode;
    delete first;
    first = NULL;

};


/**
 * Accessor function that takes node parameter and returns the (owner) info of the that node object.
 * @param Location
 * @return String data member 'owner' of the Node Struct object.
 */
string Board::who_owns(Node *Location) {

    return Location->owner;

}

/**
 * @brief Prints circular list board object accordingly to order of the slots and owners of slots. It separates each slot with arrows '->'
 * And it
 * Output of this function syncs with display function of the board class.
 */
void Board ::display() {

    int NumberOfSlots = 0;
    Node* current_node = first;
    do {
        NumberOfSlots++;                        //Counting number of slots
        current_node = current_node->next;
    } while (current_node != first);


    Node* head = first;

    for (int i = 0; i < NumberOfSlots; ++i) {
        cout << head->owner;
        if (head->owner != "None")
            cout <<" ";                             //Printing owners of slots with the given format
        head = head->next;
        if (i!=NumberOfSlots-1)
            cout<<"->";
    }
    cout << endl;
    int characterCountFirstRow = (NumberOfSlots*4) + ((NumberOfSlots-1) * 2);
    cout<< setw(1)<<"^";
    for (int i = 0; i < characterCountFirstRow-2; ++i) {
        cout << " ";                                            //Printing the second row to show that board is circular
    }
    cout<< "|";
    cout<<endl;
    cout<< "|" << "----<";
    for (int i = 0; i < NumberOfSlots-2; ++i) {
        cout<<"-----<";
    }
    cout<<"---";
    cout << "v" << endl;



}