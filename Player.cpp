#include <iostream>
#include "Player.h"
using namespace std;


Player::Player(string firstname,string lastname, unsigned int jerseynumber, unsigned int preferred_number) {

     this->firstname = firstname;
     this->lastname= lastname;
	 this->jerseynumber = jerseynumber;
     this->preferred_number = preferred_number;
     //this->active = active;
    
	 
}
Player::Player() {
    this->firstname = "";
    this->lastname=" ";
    //this->active=false;//ne yazcagimi bilemedim
    this->jerseynumber = 0;
   
}
/*string Player::activeornot(){
    string isactive=" ";
    if(active==true){
        isactive="[active]";
    }
    else if(active==false){
        isactive="[not active]";
    }
    return isactive;

}
*/

//void Player::show_career(){
    //buraya biseyler gelcek

//}
unsigned int Player::getPreferred(){
    return this->preferred_number;
}
unsigned int Player::getjersey(){
    return this->jerseynumber;
}

void Player::print_player(){
    cout <<lastname<<", "<<firstname<< " (#" << jerseynumber << ")"<<endl;

}

string Player::getlastname(){
    return this->lastname;
}

Player * Player::resizeAry2(Player*& ary,int&SIZE){
    Player *temporiginal = new Player[SIZE + 1];
    for(int i=0; i<SIZE;i++){
        temporiginal[i]=ary[i];
    }
    delete[] ary;
    ary=temporiginal;
    SIZE=SIZE+1;
    return ary;
}
