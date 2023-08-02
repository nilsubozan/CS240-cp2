#include <iostream>
#include "Team.h"

using namespace std;

Team::Team(string loc, string nick){
    this->location = loc;
    this->nickname = nick;
    
    counter=0;

    capacity=1;
    plyrs = new Player[capacity];
}
Team::Team(){
    this->location = "";
    this->nickname ="";
}

string Team::get_nickname(){
    return this->nickname;
}


/*Player * Team::resizeAry3(Player& ary,int&SIZE){
    Player *temporiginal = new Player[SIZE + 1];
    for(int i=0; i<SIZE;i++){
        temporiginal[i]=ary[i];
    }
    delete[] ary;
    ary=temporiginal;
    //SIZE=SIZE+1;
    return ary;
}
*/


Team * Team::resizeAry(Team*& ary,int&SIZE){
    Team *temporiginal = new Team[SIZE + 1];
    for(int i=0; i<SIZE;i++){
        temporiginal[i]=ary[i];
    }
    delete[] ary;
    ary=temporiginal;
    SIZE=SIZE+1;
    return ary;
}

bool Team::InTeamorNot(string teamname,string lastname){ 
    bool isInTeam= false;
    for(int i=0; i<counter;i++){
        if(plyrs[i].getlastname()==lastname){
            
            isInTeam=true;
        }
    }
    return isInTeam;
}



void Team::addPlayer(Player p){
    Player * temp= new Player[capacity*2];
    for(int i=0; i<capacity ;i++){
        temp[i]=plyrs[i];
    }
    temp[counter]=p;
    delete [] plyrs;
    plyrs=temp;
    capacity=capacity*2;
    counter+=1;
    

}

Player Team::Remove_player(string lastname){
    int i;
    Player removed_player1;
    for(i=0;i<counter;i++){
        if(plyrs[i].getlastname()==lastname){
            removed_player1=plyrs[i];
            break;
        }
    }
    //create temp player array with size -1

    if(i<counter){
        //cout<<"i is:"<<i<<endl;
        
        //counter=counter-1;
        for(int j=i;j<counter-1;j++){
            plyrs[j]=plyrs[j+1];
        }
    }
    counter=counter-1;
    return removed_player1;

   

    //Player removed_player;
    //int k=0;
    /*
    for(int x=0; x<counter;x++){
        if(lastname==plyrs[x].getlastname()){
            
            for(int y=x; y<counter-1;y++){
                plyrs[y]=plyrs[y+1];
                
            }
        }
    }
    counter=counter-1;
   
*/


    
} 
