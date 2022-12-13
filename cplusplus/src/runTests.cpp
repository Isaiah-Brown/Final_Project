
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
    //runs test of seq length 100, 200, 300, 400, 500, 1000, 5000, and 10,000 (file are named by increments of 100 for for loop to work correctly)
    for (int i =0; i < 9; i++){
        if (i==0) threads = 1;
        else threads = i * 2;
        num+=100;
        
        string threadTest = "./threaded proteinseq4.txt p1000b.txt "+to_string(threads);
        const char *command1 = threadTest.c_str();

        string tempString = "./threaded p"+to_string(num)+"a.txt" +" p"+to_string(num)+"b.txt"+" "+ to_string(12);
        string tempString2 = "./serial2 p"+to_string(num)+"a.txt" +" p"+to_string(num)+"b.txt";

        const char *command2 = tempString.c_str();
        const char *command3 = tempString2.c_str();
        system(command2);
        system(command3);


    }
    system("./serial2 p2000a.txt p2000b.txt");
    system("./threaded p2000a.txt p2000b.txt 12");
    system("./serial2 p3000a.txt p3000b.txt");
    system("./threaded p3000a.txt p3000b.txt 12");
    system("./serial2 p4000a.txt p4000b.txt");
    system("./threaded p4000a.txt p4000b.txt 12");
    system("./serial2 p6000a.txt p6000b.txt");
    system("./threaded p6000a.txt p6000b.txt 12");
    system("./serial2 p7000a.txt p7000b.txt");
    system("./threaded p7000a.txt p7000b.txt 12");
    system("./serial2 p8000a.txt p8000b.txt");
    system("./threaded p8000a.txt p8000b.txt 12");
    system("./serial2 p9000a.txt p9000b.txt");
    system("./threaded p9000a.txt p9000b.txt 12");
    

}