#include "serial.h"
#include <fstream>
#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <map>

using namespace std;

string loadfile(){
  ifstream file1("../input/proteinseq1.txt");
   
  string out1;
  string seq;
  string last_char;
  getline(file1, out1);
  while(getline (file1, out1)){
    seq += out1;
    last_char = seq.back();
    seq.pop_back();
  }
  seq += last_char;
  cout << seq << endl; 
  return seq;
}

void buildMatrix(string seq1, string seq2 , map<char, vector<int>> table, string col){

  int boardColumns = seq1.length() +1;
  int boardRows = seq2.length() +1;
  
  vector<vector<int>> board;
  for(int i=0; i< boardColumns; i++){
    vector<int> tempV;
    for(int j = 0; j < boardRows; j++){
      tempV.push_back(0);

    }

  }
  int veryBestScore = 0;

  for (int i = 0; i < seq1.length(); i++){
    for (int j=0; j <seq2.length(); i++){
      int diagonal = board[i][j];
      int top = board[i][j+1];
      int left = board[i+1][j];
      char seq1C = seq1[j];
      char seq2C = seq2[i];
      int idx = col.find(seq2C);
      int matchScore = table[seq1C][idx];
      int diagonalScore = diagonal + matchScore;
      //int topScore = top + table["gap"];
      //int leftScore = left + table["gap"];

    }
  }

}



int main() {
  loadfile();
 
}
