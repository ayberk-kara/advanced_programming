using namespace std;
#include <string>
#include<iostream>

struct point{
    int x;
    int y;

    point (int xx , int yy): x(xx), y(yy){}
};

struct student{
    int id;
    string name;

    student * next;

    student(){
        id = 0;
        name = "";
    }
    student(int idnumber, string name1){
        id = idnumber;
        name = name1;
    }
};
int main(){

    student * ptr = new student();
    ptr->name = "Ayberk";
    ptr->id = 28;

    ptr->next = new student();
    student *ptr2 = new student(29, "abiliki");


    int **twoDarray;

    *twoDarray = new int[30];

    for (int i = 0; i < 30; ++i) {
        twoDarray[i] = new int [10];
    }

    point(int x, int y) : x(0), y(0)
    return 0;
}