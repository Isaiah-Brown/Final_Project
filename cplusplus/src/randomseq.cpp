#include <random>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <cstring>

using namespace std;
int main(int charc, char* argv[]){
    vector<char> aminoacids = {'A','R','N','D','C','Q','E','G','H', 'I', 'L','K', 'M', 'F', 'P','S' , 'T' ,'W' ,'Y' ,'V' , 'B' ,'J' , 'Z' ,'X' };
    srand(time(nullptr));
    
    string aa_string = "";
    int aa_length= stoi(argv[1]);

    for (int i = 0; i< aa_length ; i++){
        int indx = rand() % aminoacids.size();
        aa_string+= aminoacids.at(indx);

    } 
    string file_name = argv[2];
    string destination = "../input/" + file_name;
    ofstream myfile(destination);
    //file_name = "../input/" + to_string(argv[2]);
    
    myfile << "random sequence of amino acids" << endl;
    myfile << aa_string+"\n";
    myfile.close();
    return 0;
    
    
    
}