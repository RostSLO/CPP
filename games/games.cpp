#include<iostream>
#include <stdlib.h>     /* srand, rand */
#include<array> 
#include <ctime>
#include <string> 

using namespace std;

string game1 = "Game 1";
string game2 = "Game 2";
string game3 = "Game 3";
string game4 = "Game 4";


string players[8] = {"1", "2", "3", "4", "5", "6", "7", "8"};
string resArray[16] = {};
string randArray[8];

void uniquePair(int round, int game){
    string player1, player2;
    string strGame = to_string(game);
    string strRound = to_string(round);
    bool unique = true;


    while (unique){
        srand((unsigned int)time(NULL));
        int s = sizeof(randArray[])/sizeof(randArray[0]);
        player1 = players[rand() % s];

        do{
            player2 = players[rand() % s];
        }
        while(player1 == player2);

        int count = 0;
        bool duplicate = true;
        while(count < 16 && resArray[count] != "" && duplicate){
            
            if(resArray[count].substr(1, 3) == strGame + player1 + player2 || resArray[count].substr(1, 3) == strGame + player2 + player1    //check the game and players              
                || resArray[count].substr(2, 3) == player1 + player2 || resArray[count].substr(2, 3) == player2 + player1                    //check pairs
                || (resArray[count].substr(0, 1) == strRound && (resArray[count].substr(2, 1) == player2 || resArray[count].substr(2, 1) == player1)) 
                || (resArray[count].substr(0, 1) == strRound && (resArray[count].substr(3, 1) == player2 || resArray[count].substr(3, 1) == player1)) ){
                duplicate = false;
            }
            else{
                count++;
            }

        }
        if(count == 16){
            unique = false;
        }else if (duplicate && count < 16){
            resArray[count] = strRound + strGame + player1 + player2;
            unique = false;
            
            cout<<"TESTING!!!   "<<resArray[count]<<"\t"<<resArray[count].substr(2, 3)<<endl;
            //cout<<player1<<"\t"<<"Game "<<strGame<<"\t"<<player2<<endl;
        }
    }
}

int main(){

    int i, j;
    string upair[2];
    for(i  = 0; i < 4; i++){
        cout<<"Round "<<to_string(i+1)<<endl;
        copy(begin(players), end(players), begin(randArray));
        for(j = 0; j < 4; j++){

            uniquePair(i, j);
        
        }
    }

    return 0;

}
