#include<iostream>
#include <windows.h> // for sleep()

using namespace std;

int main()
{
    
/**    std::cout << '-' << std::flush;
    std::cout << "\b\\rost" << std::flush;
    Sleep(1000);
    std::cout << "\b|" << std::flush;
    Sleep(1000);
    std::cout << "\b/" << std::flush;
    Sleep(1000);
    std::cout << "\b-" << std::flush;
*/

    printf("hello");
    Sleep(2000);
    printf("\033[2K\r");
    string text = "I am here";
    int i;
    for(i=0; i < text.length(); i++){
        cout << text[i];
        Sleep(100);
    }
    printf("\033[2K\r");
    Sleep(2000);
    text = "and now I am gone";
    for(i=0; i < text.length(); i++){
        cout << text[i];
        Sleep(100);
    }
    Sleep(2000);
    printf("\033[A\033[2K\r");
    printf("bye");

    return 0;

}