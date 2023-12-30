#include<iostream>
#include <stdlib.h>     /* srand, rand */
#include <ctime>
#include <string>

using namespace std;

string players[8] = {"Sasha", "Rost", "Anna", "Anasta", "Daryna", "Yura", "Raisa", "Volo"};
int arrayPart1[4], arrayPart2[4];
int arrLeft[4][4], arrRight[4][4];

void uniqueArrays(){

    srand((unsigned int)time(NULL));
    int r = (rand() % (8-1+1)+1);
    int i, j;
    // Generating 4 players for left and right arrays
    for(i = 0; i < 4; i++){
        if (r > 8){
            arrayPart1[i] = r - 8;
        } else {
            arrayPart1[i] = r;
        }
        r++;
    }
    for(i = 0; i < 4; i++){
        if (r > 8){
            arrayPart2[i] = r - 8;
        } else {
            arrayPart2[i] = r;
        }
        r++;
    }

    // Building left array
    int shift = 0;
    int test;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            test = j + shift;
            if ((j + shift) >= 4){
                arrLeft[i][j] = arrayPart1[j+shift-4];
            } 
            else {
                arrLeft[i][j] = arrayPart1[j+shift];
            }
        }
        shift++;
    }
    // Building right array
    shift = 0;
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++){
            if ((j + shift) >= 4){
                arrRight[i][j] = arrayPart2[j+shift-4];
            } else{
                arrRight[i][j] = arrayPart2[j+shift];
            }
        }
        shift++;
    }

}

void printResult(){

    int i, j, player1, player2;

    for(i = 0; i < 4; i++){
        cout<<"Round "<<to_string(i+1)<<endl;
        for(j = 0; j < 4; j++){  
            cout<<"\t"<<players[arrLeft[i][j] - 1]<<"\t"<<"Game "<<to_string(j+1)<<"\t"<<players[arrRight[i][j] - 1]<<endl;
        }
    }

}

int main(){

    uniqueArrays();

    printResult();

    return 0;

}

