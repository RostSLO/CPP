#include <iostream>
#include <cmath>
#include <string>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <ctime>




using namespace std;




int diceRoll() {
   
    srand((unsigned) time(NULL));
    string input;
    string numSides;
    string numDice;
    string numRolls;
    bool done = false;
    bool dones = false;
    bool don = false;
    int num;
    int nums;
    int numS;
    int numbered;
    int numbereds;
    int numberedS;
   
   
    ofstream myfile;
    myfile.open ("example.txt");
   
    while(don == false){
        printf("Enter a number of sides for your dice (4-20), Enter a number of dice (0-5), Enter a number of rolls (0-1000): \n");
        getline(cin, input);
       
        istringstream iss(input);
        iss >> numSides;
        iss >> numDice;
        iss >> numRolls;
        printf("\n");
       
        don = true;
        for(int i = 0; i<numSides.length(); i++){
            num = numSides[i];
            if(isdigit(num) != true){
                printf("-1 \n");
                don = false;
                break;
            }
       
        }
        if(don == true){
            numbered = stoi(numSides);
            if(numbered > 20 || numbered < 4){
                printf("-1 \n");
                don = false;
            }
        }
        for(int i = 0; i<numDice.length(); i++){
            nums = numDice[i];
            if(isdigit(nums) != true){
                printf("-1 \n");
                don = false;
                break;
            }
       
        }
        if(don == true){
            numbereds = stoi(numDice);
            if(numbereds > 5 || numbereds < 0){
                printf("-1 \n");
                done = false;
            }
        }








        for(int i = 0; i<numRolls.length(); i++){
            numS = numRolls[i];
            if(isdigit(numS) != true){
                printf("-1 \n");
                don = false;
                break;
            }
       
        }
        if(dones == true){
            numberedS = stoi(numRolls);
            if(numberedS > 1000 || numberedS < 0){
                printf("-1 \n");
                don = false;
            }
        }
    }
    if(stoi(numDice) == 0 || stoi(numRolls) == 0){
        printf("0");
        myfile.close();
        return 0;
    }
    else{
        myfile<<numSides<<" "<<numDice<<" "<<numRolls<<"\n";
    
        int diceSum[5];
        int diceSumFinal[stoi(numRolls)];
       
        int diceFinal;
        //add 2 because the both number of sides will start from 0
        string diceHolder[(stoi(numSides)) * (stoi(numDice))][2];
       
        //set array to 0
        for(int i = 0; i < 5; i++){
            diceSum[i] = 0;
        }
       
        //find the numbers rolled(all the numbers we are summing)
        for(int i = 0; i < stoi(numRolls); i++){
            printf("Roll %d: " , i + 1);
            for(int j = 0; j < stoi(numDice); j++){
                diceFinal = rand() % (stoi(numSides)) + 1;
                printf("%d " , diceFinal);
                diceSum[j] = diceFinal;
            }
            printf("\t");
            diceSumFinal[i] = diceSum[0] + diceSum[1] + diceSum[2] + diceSum[3] + diceSum[4];
            printf("Total Sum: %d \n" , diceSumFinal[i]);
        }
       
        //initialize
        for(int i = 0; i < ((stoi(numSides)) * (stoi(numDice))); i++){
            diceHolder[i][0] = to_string(i + 1);
            diceHolder[i][1] = "";
        }
       
        for(int i = 0; i < stoi(numRolls); i++){
            diceHolder[diceSumFinal[i] - 1][1] += '*';
        }
        for(int i = 0; i < ((stoi(numSides)) * (stoi(numDice))); i++){
             myfile<<diceHolder[i][0]<<" "<<diceHolder[i][1]<<"\n";
        }
       
        myfile.close();
        printf("\n write complete \n");
       
       
        for(int i = 0; i < (stoi(numSides)) * (stoi(numDice)); i++){
            diceHolder[i][0] = to_string(-3);
            diceHolder[i][1] = "-3";
        }
        numSides = "-3";
        numDice = "-3";
        numRolls = "-3";
    }
    return 1;
}




void createPictograph(){




    ifstream myfile ("example.txt");
    if (myfile.is_open())
    {
        string numSides,numDice,numRolls;
        int counter = 0;
        string line;
        getline(myfile, line);
        istringstream iss(line);
        iss>>numSides>>numDice>>numRolls;  
       
        string diceHolder[(stoi(numSides)) * (stoi(numDice))][2];
       
        while(getline(myfile, line)){
            istringstream iss(line);
            iss>>diceHolder[counter][0]>>diceHolder[counter][1];
            counter++;
        }
















        int diceReference = stoi(numSides) * stoi(numDice) - stoi(numDice) + 1;
        bool even = true;
        string res = "";
        if(diceReference <= 20){
            //display array of possible rolls
            for(int i = 0; i < ((stoi(numSides)) * (stoi(numDice)) - stoi(numDice) + 1); i++){
                if(stoi(diceHolder[i + stoi(numDice) - 1][0]) < 10){
                    if(diceHolder[i + stoi(numDice) - 1][1].length() <= 20){
                        printf("\n %s  | %s" , diceHolder[i + stoi(numDice) - 1][0].c_str() , diceHolder[i + stoi(numDice) - 1][1].c_str());
                    }
                    else{
                        printf("\n %s | %s" , diceHolder[i + stoi(numDice) - 1][0].c_str() , diceHolder[i + stoi(numDice) - 1][1].substr(0, 20).c_str());
                    }
                }
                else{
                    if(diceHolder[i + stoi(numDice) - 1][1].length() <= 20){
                        printf("\n %s | %s" , diceHolder[i + stoi(numDice) - 1][0].c_str() , diceHolder[i + stoi(numDice) - 1][1].c_str());
                    }
                    else{
                        printf("\n %s | %s" , diceHolder[i + stoi(numDice) - 1][0].c_str() , diceHolder[i + stoi(numDice) - 1][1].substr(0, 20).c_str());
                    }
                }
            }
        }
        else{
            int numPerRow = floor((diceReference / 20) + 1);
            int start = stoi(numDice) - 1;
           
            for(int i = 0; i < floor(diceReference / numPerRow); i++){
                if(i != floor(diceReference / numPerRow) - 1){
                    for(int j = start + (i * numPerRow); j <= start + (i * numPerRow) + numPerRow - 1; j++){
                        if(diceHolder[j][1] != ""){
                            res += diceHolder[j][1];
                        }
                    }
                    if(res.length() > 20){
                        res = res.substr(0, 20);
                    }
                    if(stoi(diceHolder[start + (i * numPerRow)][0]) < 10){
                        printf("\n %s - %s\t\t| %s" , diceHolder[start + (i * numPerRow)][0].c_str() , diceHolder[start + (i * numPerRow) + numPerRow - 1][0].c_str() , res.c_str());
                        res = "";
                    }
                    else{
                        printf("\n %s - %s\t| %s" , diceHolder[start + (i * numPerRow)][0].c_str() , diceHolder[start + (i * numPerRow) + numPerRow - 1][0].c_str() , res.c_str());
                        res = "";
                    }
                }
                else{
                    for(int j = start + (i * numPerRow); j <= (stoi(numSides)) * (stoi(numDice)) - 1; j++){
                        if(diceHolder[j][1] != ""){
                            res += diceHolder[j][1];
                        }
                    }
                    if(res.length() > 20){
                        res = res.substr(0, 20);
                    }
                    printf("\n %s - %s\t| %s" , diceHolder[start + (i * numPerRow)][0].c_str() , diceHolder[(stoi(numSides)) * (stoi(numDice)) - 1][0].c_str() , res.c_str());
                    res = "";
                }
            }
        }
    }
    else{
        printf("file lost, please try again!");
    }
    myfile.close();
}
   


int main() {
   
    if(diceRoll() == 1){
        createPictograph();
    }
   
    return 0;
}

















