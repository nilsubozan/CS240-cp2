#ifndef TEAM_H
#define TEAM_H
#include <string.h>
#include <iostream>
#include "Player.h"
using namespace std;

class Team{
    public:
        string location;
        string nickname;
        Team(string loc, string nick);
        Team();
        string get_nickname();
        //Player plyrs[12];
        Player* plyrs;
        int counter;
        int capacity;
        //Team *resizeAry3(Player*& ary,int&SIZE);
        Team * resizeAry(Team*& ary,int&SIZE);
        bool InTeamorNot( string teamname,string lastname);
        void addPlayer(Player p);
        Player Remove_player(string lastname);
        
        
        
        
        


};







#endif