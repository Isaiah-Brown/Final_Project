
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

int main(){
    int num = 0;
    int threads = 0;
    for (int i =0; i < 12; i++){
        if (i==0) threads = 1;
        else threads = i * 2;
        num+=100;
        
        string threadTest = "./threaded p600a.txt p600b.txt "+to_string(threads);
        const char *command1 = threadTest.c_str();

        string tempString = "./threaded p"+to_string(num)+"a.txt" +" p"+to_string(num)+"b.txt"+" "+ to_string(10);
        const char *command2 = tempString.c_str();
        system(command1);

    }
    

}