#include <iostream>
#include <string>
#include "Parser.h"
#include "Team.h"
#include "Player.h"

using namespace std;

int main() {

   string line;  
   string command;  
   
   int fagent_size=1;
   Player* free_agent=new Player[fagent_size];
   int forteamsize= 1;
   Team* allteams=new Team[forteamsize];
   Team team;
   

   while (1) {
      cout << endl << "Enter a command:" << endl;
      cout<<"Choose from"<<endl;
      cout << "  [\"Team <location> <team-nickname>\"" << std::endl <<
	      "    \"Player <firstname> <lastname> <number> [<team-nickname>]\"" << std::endl << 
	      "    \"League\"" << std::endl << 
	      "    \"Roster [<team-nickname>]\"" << std::endl << 
          "    \"Release <lastname> <team-nickname>\"" <<std::endl<<
          "    \"Sign <lastname> <team-nickname>\"" <<std::endl<<
          "    \"Career <lastname>\"" <<std::endl<<
	      "    \"Quit\"]" << endl;
      cout << ": "; 

      getline(cin, line);
      Parser command(line);
      if (command.getOperation().empty()){
          if (std::cin.fail())
              break;
          continue;
       }

      if (command.getOperation() == "Quit") {
         if (command.numArgs() > 0){
             cout << std::endl << "Ignoring " << UNEXPECTED_ARGS << endl;
         }
         break;
      }

      if (command.getOperation() == "League") {
         if (command.numArgs() > 0) cout << std::endl << "Ignoring " << UNEXPECTED_ARGS << endl; 
            cout<<"Teams: "<< (int)forteamsize-1 <<endl;
            for(int i=0; i<(int)forteamsize-1;i++){
                cout<<allteams[i].location<<" ";
                cout<<allteams[i].get_nickname()<<" ";
                cout<<"("<<allteams[i].counter<<" players)"<<endl;
            }
	 
      }

      else if (command.getOperation() == "Player") {
        
        if (command.numArgs() < 3) {
            cout << std::endl << MISSING_ARGS << endl;
        }
        if(command.numArgs() >4){
            cout<<std::endl<<"Ignoring " << UNEXPECTED_ARGS << endl;
        }
        unsigned int preferred_number1;
        unsigned int preferred_number2;
        unsigned int possiblenum=0;
        Player p;
        unsigned int temp;
        bool issame=false;
        if(command.numArgs() ==3){
            preferred_number1=stoi(command.getArg3());
            p= Player(command.getArg1(), command.getArg2(), preferred_number1, preferred_number1);
            free_agent[fagent_size-1]=p;
            free_agent=p.resizeAry2(free_agent,fagent_size);
            cout<<"Player "<<command.getArg1()<<" "<<command.getArg2()<<" added to free agents."<<endl;
        }
	    else if(command.numArgs()==4){
            preferred_number1=stoi(command.getArg3());
            preferred_number2=stoi(command.getArg3());
            for(int i=0; i<forteamsize;i++){
                if(command.getArg4()==allteams[i].get_nickname()){
                        for(int o=0; o<allteams[i].counter;o++){
                            if(preferred_number2==allteams[i].plyrs[o].getjersey()){
                                cout << "Here\t";
                                issame= true;      
                            }
                            else{
                                issame=false;
                            }
                            if(issame==true){
                                preferred_number2=possiblenum;
                                possiblenum+=1;
                                o=0;
                            }
                            
                        }
                        p= Player(command.getArg1(),command.getArg2(),preferred_number2,preferred_number1);
                        allteams[i].addPlayer(p);
                    
                }
            }
            
        }
         
    }

      else if (command.getOperation() == "Team") {
          if(command.numArgs()< 2){
              cout<< std::endl<<MISSING_ARGS<<endl;
              continue;
          }
          if(command.numArgs()>2){
              cout<<std::endl<< "Ignoring "<< UNEXPECTED_ARGS<<endl;
          }
          if(command.numArgs()==2){
              bool dup = true;

              for(int i=0;i<forteamsize;i++){
                  if(command.getArg2()==allteams[i].get_nickname()){
                      dup=false;
                      cout<< "Duplicate team nickname "<<command.getArg2()<< " not added"<<endl;
                      break;
                    }
                }
                if(dup==true){
                    cout<<endl;
                    team = Team(command.getArg1(),command.getArg2());
                    allteams[forteamsize-1]=team;
                    allteams=team.resizeAry(allteams,forteamsize);
                }

            
            }

        }
      else if(command.getOperation() == "Roster"){
          if(command.numArgs()<1){
              if(fagent_size-1==0){
                  cout<<"There is no free agent"<<endl;
              }
              //cout<<"Free Agents"<<endl;
              //cout<<"   Players: "<<endl;
              else if(fagent_size-1!=0){
                  cout<<"Free Agents"<<endl;
                  cout<<"   Players: "<<endl;
                  for(int i=0; i<(int)fagent_size-1;i++){
                      free_agent[i].print_player();
                    }
                }
            }
            if(command.numArgs()>1){
                cout<<std::endl<<"Ignoring " << UNEXPECTED_ARGS << endl;
            }
            if(command.numArgs()==1){
                for(int i=0;i<(int)forteamsize;i++){
                    if(command.getArg1()==allteams[i].get_nickname()){
                        cout <<allteams[i].location << " "<<allteams[i].get_nickname()<< endl;
                        cout << "Players:"<<endl;
                        for(int o=0; o<allteams[i].counter;o++){
                            allteams[i].plyrs[o].print_player();
                        }
                        break;
                    }
                }
            }
        }
        else if(command.getOperation()=="Release"){
            if(command.numArgs() < 2){cout<<std::endl<< MISSING_ARGS <<endl; continue;}
            if(command.numArgs() >2){cout<<std::endl<< "Ignoring"<< UNEXPECTED_ARGS<<endl;}
            Player removed;
            bool teamexist=false;
            Team t;
            for(int i=0;i<(int)forteamsize;i++){
                if(command.getArg2()==allteams[i].get_nickname()){
                    t=allteams[i];
                    teamexist= true;
                    allteams[i].InTeamorNot(command.getArg2(),command.getArg1());
                    if(teamexist==false ||allteams[i].InTeamorNot(command.getArg2(),command.getArg1())==false){
                        cout<<"ERROR: Player is not in that team."<<endl;
                    }
                    else if(allteams[i].InTeamorNot(command.getArg2(),command.getArg1())==true){
                        removed=allteams[i].Remove_player(command.getArg1());
                        free_agent[fagent_size-1]=removed;
                        free_agent=removed.resizeAry2(free_agent,fagent_size);
                    }
                    break;
                }
            }
            if(teamexist==false){
                cout<<"ERROR: Team not exist."<<endl;
            }


        }
        else if(command.getOperation()=="Sign"){
            if(command.numArgs() < 2){cout<<std::endl<< MISSING_ARGS <<endl; continue;}
            if(command.numArgs() >2){cout<<std::endl<< "Ignoring "<< UNEXPECTED_ARGS<<endl;}
            int chc=0;
            Player dltPlayer;
            int zz=0;
            for(int i=0;i<forteamsize;i++){
                if(command.getArg2()==allteams[i].get_nickname()){
                    //Specified team is found
                    chc=1;
                }
                break;
            }
            if(chc==0){
                cout<<"ERROR: Team not exist"<<endl;
            }
            else if(chc==1){
                for(int i=0; i<fagent_size-1;i++){
                    if(command.getArg1()==free_agent[i].getlastname()){
                        dltPlayer=free_agent[i];
                        chc=2;
                        for(int j=i;j<fagent_size-2;j++){
                            free_agent[j]=free_agent[j+1];
                        }
                        for(int k=0;k<forteamsize;k++){
                            if(command.getArg2()==allteams[k].get_nickname()){
                                for(int p=0; p<allteams[k].counter;p++){
                                    if(dltPlayer.getjersey()==allteams[k].plyrs[p].getjersey()){
                                        dltPlayer.jerseynumber=zz;
                                        zz+=1;
                                        p=0;
                      //it means that the player's preferred number is taken by somebody else
                                     }
                                 }
                  
                                allteams[k].addPlayer(dltPlayer);
                            }
                        }
                    }
                }
                if(chc==2){
                    fagent_size=fagent_size-1;
                }
                else{
                    cout<<"ERROR: Player is not a free agent"<<endl;
                }
            }

        }
        else if(command.getOperation()=="Career"){
            if(command.numArgs() < 1){cout<<std::endl<< MISSING_ARGS <<endl; continue;}
            if(command.numArgs() >1){cout<<std::endl<< "Ignoring "<< UNEXPECTED_ARGS<<endl;}
            for(int i=0;i<(int)forteamsize-1;i++){
                for(int o=0; o<allteams[i].counter;o++){
                    if(command.getArg1()==allteams[i].plyrs[o].getlastname()){
                    //player allteams[i] takiminda oynadi demektir.
                    cout<< allteams[i].get_nickname()<<" #"<<allteams[i].plyrs[o].getjersey()<<endl;
                    }
                }
            }
            if(fagent_size-1>0){
                for(int i=0; i<fagent_size-1;i++){
                    if(command.getArg1()==free_agent[i].getlastname()){
                        cout<<"free agents "<<"#"<<free_agent[i].getjersey()<<endl;
                    }
                }
            }
            


        }

      else {
         cout << std::endl << 
		 "Command not recognized. Please try again." << endl; 
      }
   }
   return 0;
}
