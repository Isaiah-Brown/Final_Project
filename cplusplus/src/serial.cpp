#include "serial.h"
#include <fstream>
#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std::chrono;
using namespace std;

string seq1;
string seq2;
string finalSeq1 = "";
string finalSeq2 = "";
int bestI = 0;
int bestJ = 0;


unordered_map<char, vector<int>> GenMatrix() {
   unordered_map<char, vector<int>>table;

  
   table = {
    {'A' , {5, -2, -1, -2, -1, -1, -1,  0, -2, -1, -1, -1, -1, -2, -1,  1,  0, -2, -2,  0, -1, -1, -1, -1}},
    {'R' , {-2,  7,  0, -1, -3,  1,  0, -2,  0, -3, -2,  3, -1, -2, -2, -1, -1, -2, -1, -2, -1, -3,  1, -1}},
    {'N' , {-1,  0,  6,  2, -2,  0,  0,  0,  1, -2, -3,  0, -2, -2, -2,  1,  0, -4, -2, -3,  5, -3,  0, -1}},
    {'D' , {-2, -1,  2,  7, -3,  0,  2, -1,  0, -4, -3,  0, -3, -4, -1,  0, -1, -4, -2, -3,  6, -3,  1, -1}},
    {'C' , {-1, -3, -2, -3, 12, -3, -3, -3, -3, -3, -2, -3, -2, -2, -4, -1, -1, -5, -3, -1, -2, -2, -3, -1}},
    {'Q' , {-1,  1,  0,  0, -3,  6,  2, -2,  1, -2, -2, 1,  0, -4, -1,  0, -1, -2, -1, -3,  0, -2,  4, -1}},
    {'E' , {-1,  0,  0,  2, -3,  2,  6, -2,  0, -3, -2,  1, -2, -3,  0,  0, -1, -3, -2, -3,  1, -3,  5, -1}},
    {'G' , {0, -2,  0, -1, -3, -2, -2,  7, -2, -4, -3, -2, -2, -3, -2,  0, -2, -2, -3, -3, -1, -4, -2, -1}},
    {'H' , {-2,  0, 1,  0, -3,  1,  0, -2, 10, -3, -2, -1,  0, -2, -2, -1, -2, -3,  2, -3,  0, -2,  0, -1}},
    {'I' , {-1, -3, -2, -4, -3, -2, -3, -4, -3,  5,  2, -3, 2,  0, -2, -2, -1, -2,  0,  3, -3,  4, -3, -1}},
    {'L' , {-1, -2, -3, -3, -2, -2, -2, -3, -2,  2,  5, -3,  2,  1, -3, -3, -1, -2,  0,  1, -3,  4, -2, -1}},
    {'K' , {-1,  3,  0,  0, -3,  1,  1, -2, -1, -3, -3,  5, -1, -3, -1, -1, -1, -2, -1, -2,  0, -3,  1, -1}},
    {'M' , {-1, -1, -2, -3, -2,  0, -2, -2,  0,  2,  2, -1,  6,  0, -2, -2, -1, -2,  0,  1, -2,  2, -1, -1}},
    {'F' , {-2, -2, -2, -4, -2, -4, -3, -3, -2,  0,  1, -3,  0,  8, -3, -2, -1,  1,  3,  0, -3,  1, -3, -1}},
    {'P' , {-1, -2, -2, -1, -4, -1,  0, -2, -2, -2, -3, -1, -2, -3,  9, -1, -1, -3, -3, -3, -2, -3, -1, -1}},
    {'S' , {1, -1,  1,  0, -1,  0,  0,  0, -1, -2, -3, -1, -2, -2, -1,  4,  2, -4, -2, -1,  0, -2,  0, -1}},
    {'T' , {0, -1,  0, -1, -1, -1, -1, -2, -2, -1, -1, -1, -1, -1, -1,  2,  5, -3, -1,  0,  0, -1, -1, -1}},
    {'W' , {-2, -2, -4, -4, -5, -2, -3, -2, -3, -2, -2, -2, -2,  1, -3, -4, -3, 15,  3, -3, -4, -2, -2, -1}},
    {'Y' , {-2, -1, -2, -2, -3, -1, -2, -3,  2,  0,  0, -1,  0,  3, -3, -2, -1,  3,  8, -1, -2, 0, -2, -1}},
    {'V' , {0, -2, -3, -3, -1, -3, -3, -3, -3,  3, 1, -2,  1,  0, -3, -1,  0, -3, -1,  5, -3,  2, -3, -1}},
    {'B' , {-1, -1,  5,  6, -2,  0,  1, -1,  0, -3, -3,  0, -2, -3, -2,  0,  0, -4, -2, -3,  5, -3,  1, -1}},
    {'J' , {-1, -3, -3, -3, -2, -2, -3, -4, -2,  4,  4, -3,  2,  1, -3, -2, -1, -2,  0,  2, -3,  4, -2, -1}},
    {'Z' , {-1,  1,  0,  1, -3, 4,  5, -2,  0, -3, -2,  1, -1, -3, -1,  0, -1, -2, -2, -3,  1, -2,  5, -1}},
    {'X' , {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}},
    {'_' , {-5}}
    };

    return table;
}

string GenCol(){

    string col = "ARNDCQEGHILKMFPSTWYVBJZX"; 
    
    return col;
}

int getMax(int a, int b, int c) {
    if ((a > b) && (a > c)) {
        return a;
    } else if ((b > a) && (b > c)) {
        return b;
    } else {
        return c;
    }
}




string loadfile(string filepath){
  ifstream file1(filepath);
   
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
  //cout << seq << endl; 
  return seq;
}




vector<vector<int>> buildMatrix(string seq1, string seq2 , unordered_map<char, vector<int>> table, string col){

  int boardColumns = seq1.length() +1;
  int boardRows = seq2.length() +1;
  
  vector<vector<int>> board;
  for(int i=0; i < boardRows; i++){
    vector<int> tempV;
    for(int j = 0; j < boardColumns; j++){
      tempV.push_back(0);
    }
    board.push_back(tempV);
  }

  int veryBestScore = 0;
  vector<int> gapV = table.at('_');
  int gap = gapV[0];

  cout << seq1.length() << endl;
  cout << seq2.length() << endl;
  
  for (int i = 0; i < seq2.length(); i++){
    for (int j=0; j < seq1.length(); j++){
      //cout << i << " " << j << endl;
      int diagonal = board[i][j];
      int top = board[i][j+1];
      int left = board[i+1][j];
      //cout << "here" << endl;

      char seq1C = seq1[j];
      char seq2C = seq2[i];
      int idx = col.find(seq2C);

      vector<int>v = table.at(seq1C);
      int matchScore = v[idx];


      int diagonalScore = diagonal + matchScore;
      int topScore = top + gap;
      int leftScore = left + gap;


      int bestScore = getMax(diagonalScore, topScore, leftScore);

      if (bestScore < 0) {
        board[i+1][j+1] = 0;
      } else {
        board[i+1][j+1] = bestScore;
        if (bestScore > veryBestScore) {
            veryBestScore = bestScore;
            bestI = i + 1;
            bestJ = j + 1;
        }
      }
    }
  }
  return board;
}


       
void traceBack(vector<vector<int>> board, unordered_map<char, vector<int>> table, string col){

   
    //int identities = 0
    int i = bestI;
    int j = bestJ;

    vector<int> gapV = table.at('_');
    int gap = gapV[0];

    cout << bestI << " " << bestJ << endl;


    while(board[i][j] != 0){
        if (i == 0) {
            finalSeq1 += seq1[j-1];
            finalSeq2 += "_";
            j -= 1;
        } else if (j == 0) {
            finalSeq1 += "_";
            finalSeq2 += seq2[i-1];
            i -= 1;
        } else {
            int diagonal = board[i-1][j-1];
            int idx = col.find(seq2[i-1]);
            vector<int> v = table.at(seq1[j-1]);
            int matchScore = v[idx];

            int diagonalScore = diagonal + matchScore;
            int topScore = board[i-1][j] + gap;
            int leftScore = board[i][j-1] + gap;

            if ((diagonalScore >= topScore) && (diagonalScore >= leftScore)) {
                finalSeq1 += seq1[j-1];
                finalSeq2 += seq2[i-1];
                i -= 1;
                j -= 1;
            }else if (topScore > leftScore) {
                finalSeq1 += "_";
                finalSeq2 += seq2[i-1];
                i = i-1;
            }else{
                finalSeq1 += seq1[j-1];
                finalSeq2 += "_";
                j -= 1;
            }  
        }
    }


    int len = finalSeq1.length();

    for (int i = 0; i < len / 2; i++) {
        swap(finalSeq1[i], finalSeq1[len - i - 1]);
        swap(finalSeq2[i], finalSeq2[len - i - 1]);
    }
}



int main() {
  auto start = high_resolution_clock::now();
  
  seq1 = loadfile("../input/proteinseq1.txt");
  seq2 = loadfile("../input/proteinseq2.txt");
  unordered_map<char, vector<int>>table = GenMatrix();
  string col = GenCol();
  vector<vector<int>> board = buildMatrix(seq1, seq2, table, col);
  traceBack(board, table, col);
  cout << finalSeq1 << endl;
  cout << finalSeq2 << endl;
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<milliseconds>(stop - start);
  cout <<"serial time taken " << duration.count() << endl;

 
}