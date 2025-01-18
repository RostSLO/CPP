#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

int readFile(string fileName, bool (&pArr)[3], int (&arr)[3]){

    int lineCount = 0;
    int wordCount = 0;
    int charsCount = 0;
    int extra = 0;
    char c;
    string word;
    string str;

    ifstream file;
    file.open(fileName);
    if (!file.is_open()) return 0;

    //read from file to a string, eliminating extra spaces and tabs
    while (file.get(c))
    {
        if (c != '\t'){
            if (c == ' '){
                if (extra == 0){
                    str += c;
                    charsCount++;
                    extra = 1;
                }
            } else {
                if (c == '\n' && extra == 1){
                    str.pop_back();
                    charsCount--;
                    extra = 0;
                }
                str += c;
                charsCount++;
                extra = 0;
                if (c == '\n'){
                    lineCount++;
                    charsCount--;
                    extra = -1;
                }
            }
        }
    }
    if (extra == 1){
        str.pop_back();
        charsCount--;
    }

    file.close();

    // writing text without extra spaces and tabs back to the file
    ofstream oFile(fileName);
    if (!oFile.is_open()) return 2;
    oFile << str;
    oFile.close();

    //count words if requested
    if (pArr[1]){
    
        istringstream iStr(str);

        while (iStr >> word){
            wordCount++;
        }
        
        arr[1] = wordCount;
    }

    //return number of lines if requested
    if (pArr[0]){
        arr[0] = lineCount + 1;
    }
    //return number of chars if requested
    if (pArr[2]){
        arr[2] = charsCount;
    }

    return 1;

}

void printResult(string filename, bool (&pArr)[3], int (&arr)[3]){

    //print lines
    if (pArr[0]){
        cout << arr[0] << " ";
    }
    
    //print words
    if (pArr[1]){
        cout << arr[1] << " ";
    }

    //print caharcters
    if (pArr[2]){
        cout << arr[2] << " ";
    }

    //print filename
    cout << filename << endl;
}

int main(int argc, char* argv[]){
    
    bool paramArr[3] = {false, false, false};
    int resArr[3] = {0, 0, 0};
    int fileRead = 0;
    string args = ".args";
    string txt = "";
    

    // Using a while loop to iterate through arguments
    int i = 1;
    while (i < argc) {

        //alternative way to read argv. i.e. argument "-l" translets into argv[i] = {'-', 'l'}
        // string s(argv[i])
        // if (s == "-l")

        if (argv[i][1] == 'l'){
            paramArr[0] = true;
        } else if (argv[i][1] == 'w'){
            paramArr[1] = true;
        } else if (argv[i][1] == 'c'){
            paramArr[2] = true;
        } else {
            //check if any of arguments was provided, if not all argumens set to true
            if (!paramArr[0] && !paramArr[1] && !paramArr[2]){
                paramArr[0] = true;
                paramArr[1] = true;
                paramArr[2] = true;
            }

            //read the file if it is .args
            string s(argv[i]);
            
            if (s.compare(s.size() - args.size(), args.size(), args) == 0){

                ifstream file(s);
                if (!file.is_open()){
                    cout << "Can't open file to read " << s << endl;
                } else{
                    while(file >> txt){
                        fileRead = readFile(txt + ".txt", paramArr, resArr);

                        if  (fileRead == 1){
                            //print Result for the current file
                            printResult(argv[i], paramArr, resArr);
                            //if we need to return input files instead of .args file
                            //printResult(txt + ".txt", paramArr, resArr);
                        } else if (fileRead == 2){
                            cout << "Can't open file to write" << argv[i] << endl;
                        } else {
                            cout << "Can't open file to read" << argv[i] << endl;
                        }
                    }
                }
            } else {

                //read file and fill the result based on the arguments (-l, -w, -c)
                // if returns 0 - file can't be open
                fileRead = readFile(argv[i], paramArr, resArr);

                if  (fileRead == 1){
                    //print Result for the current file
                    printResult(argv[i], paramArr, resArr);
                } else if (fileRead == 2){
                    cout << "Can't open file to write" << argv[i] << endl;
                } else {
                    cout << "Can't open file to read" << argv[i] << endl;
                }
            }

        }

        i++;
    }

    return 0;
}