//
// Created by ayber on 5.05.2023.
//
#include <iomanip>
#include "Player.h"
/**
 * @brief Parametric constructor for player class. It takes name, initial capital values and assigns them to name, balance data members respectively. And it also takes a reference object of the board class and this object shared with other player objects.
 * @param sharedBoard
 * @param Name
 * @param initialCapital
 */
Player::Player(Board & sharedBoard, string Name, int initialCapital): board(sharedBoard){
    name = Name;
    balance = initialCapital;
    currentPos = sharedBoard.returnFirst();

                         //node first position
                         //board first node its useful to keep this in player's data too
                                            //current position on the table as integer (start point is 1) its useful for display operations
};
/**
 * @brief Moves player(node pointer) object on the shared board object returns 1 if player passes start, 0 otherwise.
 * @param steps
 * @return 0 or 1
 */
int Player::move(int steps) {

    int DidPassStart = 0;

    Node * start = board.returnFirst();
    for (int i = 0; i < steps; ++i) {
        currentPos = currentPos->next;
        if (currentPos == start){
            DidPassStart = 1;
        }

    }

    return DidPassStart;

};


/**
 * @brief Accessor for current position of the player on the board.
 * @return currentPos (Node pointer)
 */
Node * Player:: where_am_I(){

    return currentPos;

};



/**
 * @brief Object (this) that this function called on, pays (money) amount to (otherPlayer) parameter object.
 * @param otherPlayer
 * @param money
 */
void Player ::pay_to_player(Player & otherPlayer, int money){

    this->balance -= money;
    otherPlayer.balance+=money;

};

/**
 * @brief Accessor of balance data.
 * @return int balance
 */
int Player ::get_balance()const{

    return balance;

};
/**
 * @brief that adds (depositAmount) of player objects's balance that this function called on.
 * @param depositAmount
 */
void Player ::deposit_money(int depositAmount){

    this->balance+=depositAmount;

};

/**
 * @brief that assigns player object's name that this function called on, and decrements the player's balance by the
 * parameter (priceOfSlot) amount.
 * @param priceOfSlot
 */
void Player ::buy_slot(int priceOfSlot){

    this->balance-=priceOfSlot;
    currentPos->owner = this->name;

};
/**
 * @brief Function that checks if there is a bankrupt by checking balance of the player object that this function called on smaller than or equal to zero
 * @return true or false
 */
bool Player ::is_bankrupt()const{

    if (balance<=0)
        return true;

    return false;
};


/**
 * @brief Prints player object's name and balance and it leaves spaces at the beginning according to player's location on the board. Output of this function syncs with display function of the board class.
 */
void Player :: display()const{
    int slotNumber = 1;

    int NumberOfSlots = 0;
    Node* current_node = board.returnFirst();
    do {
        NumberOfSlots++;
        current_node = current_node->next;               //Counting number of slots
    } while (current_node != board.returnFirst());


    Node* currentNode = board.returnFirst();
    while (currentNode != currentPos) {
        slotNumber++;                                      //Determining player's current position as a int (its needed for spaces at the beginning)
        currentNode = currentNode->next;
    }
    if (slotNumber%NumberOfSlots != 0)
        slotNumber = slotNumber%NumberOfSlots;


    for (int i = 0; i < (6*((slotNumber)-1)); ++i) {    //Formating
        cout << " ";
    }

    cout << this->name << " " << this->balance << endl;

}




