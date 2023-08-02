//#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
using namespace std;


class Player{
    public:
        Player(string firstname,string lastname, unsigned int jerseynumber,unsigned int preferred_number);
        Player();
        void print_player();
        //bool active;
        unsigned int jerseynumber;
        string firstname;
        string lastname;
        unsigned int preferred_number;
        Player * resizeAry2(Player*& ary,int&SIZE);
        unsigned int getjersey();
        string getlastname();
        unsigned int getPreferred();
        int CarCap;
        int CarNum;
        
        
};



#endif