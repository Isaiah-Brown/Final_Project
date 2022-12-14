//#include "serial.h"
#include <fstream>
#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <unordered_map>
#include <time.h>

using namespace std;
using namespace std::chrono;

string seq1;
string seq2;
string finalSeq1 = "";
string finalSeq2 = "";
int bestI = 0;
int bestJ = 0;


unordered_map<char, unordered_map<char, int>> GenMatrix() {
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
    unordered_map<char, unordered_map<char, int>>table2;

    table2 = {
        {'A', 
            {
                {'A', 5}, 
                {'R', -2},
                {'N', -1},
                {'D', -2},
                {'C', -1},
                {'Q', -1},
                {'E', -1},
                {'G', 0},
                {'H', -2},
                {'I', -1},
                {'L', -1},
                {'K', -1},
                {'M', -1},
                {'F', -2},
                {'P', -1},
                {'S', 1},
                {'T', 0},
                {'W', -2},
                {'Y', -2},
                {'V', 0},
                {'B', -1},
                {'J', -1},
                {'Z', -1},
                {'X', -1},
            }
        },
        {'R', 
            {
                {'A', -2},
                {'R', 7},
                {'N', 0},
                {'D', -1},
                {'C', -3},
                {'Q', 1},
                {'E', 0},
                {'G', -2},
                {'H', 0},
                {'I', -3},
                {'L', -2},
                {'K', 3},
                {'M', -1},
                {'F', -2},
                {'P', -2},
                {'S', -1},
                {'T', -1},
                {'W', -2},
                {'Y', -1},
                {'V', -2},
                {'B', -1},
                {'J', -3},
                {'Z', 1},
                {'X', -1},
            }
        },
        {'N', 
            {
                {'A', -1},
                {'R', 0},
                {'N', 6},
                {'D', 2},
                {'C', -2},
                {'Q', 0},
                {'E', 0},
                {'G', 0},
                {'H', 1},
                {'I', -2},
                {'L', -3},
                {'K', -0},
                {'M', -2},
                {'F', -2},
                {'P', -2},
                {'S', 1},
                {'T', 0},
                {'W', -4},
                {'Y', -2},
                {'V', -3},
                {'B', -5},
                {'J', -3},
                {'Z', 0},
                {'X', -1},
            }
        },
        {'D', 
            {
                {'A', -2},
                {'R', -1},
                {'N', -2},
                {'D', 7},
                {'C', -3},
                {'Q', 0},
                {'E', 2},
                {'G', -1},
                {'H', 0},
                {'I', -4},
                {'L', -3},
                {'K', 0},
                {'M', -3},
                {'F', -4},
                {'P', -1},
                {'S', 0},
                {'T', -1},
                {'W', -4},
                {'Y', -2},
                {'V', -3},
                {'B', 6},
                {'J', -3},
                {'Z', 1},
                {'X', -1},
            }
        },
        {'C', 
            {
                {'A', -1},
                {'R', -3},
                {'N', -2},
                {'D', -3},
                {'C', 12},
                {'Q', -3},
                {'E', -3},
                {'G', -3},
                {'H', -3},
                {'I', -3},
                {'L', -2},
                {'K', -3},
                {'M', -2},
                {'F', -2},
                {'P', -4},
                {'S', -1},
                {'T', -1},
                {'W', -5},
                {'Y', -3},
                {'V', -1},
                {'B', -2},
                {'J', -2},
                {'Z', -3},
                {'X', -1},
            }
        },
        {'Q', 
            {
                {'A', -1},
                {'R', 1},
                {'N', 0},
                {'D', 0},
                {'C', -3},
                {'Q', 6},
                {'E', 2},
                {'G', -2},
                {'H', 1},
                {'I', -2},
                {'L', -2},
                {'K', 1},
                {'M', 0},
                {'F', -1},
                {'P', -1},
                {'S', 0},
                {'T', -1},
                {'W', -2},
                {'Y', -1},
                {'V', -3},
                {'B', 0},
                {'J', -2},
                {'Z', 4},
                {'X', -1},
            }
        },
        {'E', 
            {
                {'A', -1},
                {'R', 0},
                {'N', 0},
                {'D', 2},
                {'C', -3},
                {'Q', 2},
                {'E', 6},
                {'G', -2},
                {'H', 0},
                {'I', -3},
                {'L', -2},
                {'K', 1},
                {'M', -2},
                {'F', -3},
                {'P', 0},
                {'S', 0},
                {'T', -1},
                {'W', -3},
                {'Y', -2},
                {'V', -3},
                {'B', 1},
                {'J', -3},
                {'Z', 5},
                {'X', -1},
            }
        },
        {'G', 
            {
                {'A', 0},
                {'R', -2},
                {'N', 0},
                {'D', -1},
                {'C', -3},
                {'Q', -2},
                {'E', -2},
                {'G', 7},
                {'H', -2},
                {'I', -4},
                {'L', -3},
                {'K', -2},
                {'M', -2},
                {'F', -3},
                {'P', -2},
                {'S', 0},
                {'T', -2},
                {'W', -2},
                {'Y', -3},
                {'V', -3},
                {'B', -1},
                {'J', -4},
                {'Z', -2},
                {'X', -1},
            }
        },
        {'G', 
            {
                {'A', 0},
                {'R', -2},
                {'N', 0},
                {'D', -1},
                {'C', -3},
                {'Q', -2},
                {'E', -2},
                {'G', 7},
                {'H', -2},
                {'I', -4},
                {'L', -3},
                {'K', -2},
                {'M', -2},
                {'F', -3},
                {'P', -2},
                {'S', 0},
                {'T', -2},
                {'W', -2},
                {'Y', -3},
                {'V', -3},
                {'B', -1},
                {'J', -4},
                {'Z', -2},
                {'X', -1},
            }
        },
        {'H', 
            {
                {'A', -2},
                {'R', 0},
                {'N', 1},
                {'D', 0},
                {'C', -3},
                {'Q', 1},
                {'E', 0},
                {'G', -2},
                {'H', 10},
                {'I', -3},
                {'L', -2},
                {'K', -1},
                {'M', 0},
                {'F', -2},
                {'P', -2},
                {'S', -1},
                {'T', -2},
                {'W', -3},
                {'Y', 2},
                {'V', -3},
                {'B', 0},
                {'J', -2},
                {'Z', 0},
                {'X', -1},
            }
        },
        {'I', 
            {
                {'A', -1},
                {'R', -3},
                {'N', -2},
                {'D', -4},
                {'C', -3},
                {'Q', -2},
                {'E', -3},
                {'G', 4},
                {'H', -3},
                {'I', -5},
                {'L', 2},
                {'K', -3},
                {'M', 2},
                {'F', 0},
                {'P', -2},
                {'S', -2},
                {'T', -1},
                {'W', -2},
                {'Y', 0},
                {'V', 3},
                {'B', -3},
                {'J', 4},
                {'Z', -3},
                {'X', -1},
            }
        },
        {'L', 
            {
                {'A', -1},
                {'R', -2},
                {'N', -3},
                {'D', -3},
                {'C', -2},
                {'Q', -2},
                {'E', -2},
                {'G', -3},
                {'H', -2},
                {'I', 2},
                {'L', 5},
                {'K', -3},
                {'M', 2},
                {'F', 1},
                {'P', -3},
                {'S', -3},
                {'T', -1},
                {'W', -2},
                {'Y', -0},
                {'V', 1},
                {'B', -3},
                {'J', 4},
                {'Z', -2},
                {'X', -1},
            }
        },
        {'K', 
            {
                {'A', -1},
                {'R', 3},
                {'N', 0},
                {'D', 0},
                {'C', -3},
                {'Q', 1},
                {'E', 1},
                {'G', -2},
                {'H', -1},
                {'I', -3},
                {'L', -3},
                {'K', 5},
                {'M', -1},
                {'F', -3},
                {'P', -1},
                {'S', -1},
                {'T', -1},
                {'W', -2},
                {'Y', -1},
                {'V', -2},
                {'B', 0},
                {'J', -3},
                {'Z', 1},
                {'X', -1},
            }
        },
        {'M', 
            {
                {'A', -1},
                {'R', -1},
                {'N', -2},
                {'D', -3},
                {'C', -2},
                {'Q', 0},
                {'E', -2},
                {'G', -2},
                {'H', 0},
                {'I', 2},
                {'L', 2},
                {'K', -1},
                {'M', -6},
                {'F', 0},
                {'P', -2},
                {'S', -2},
                {'T', -1},
                {'W', -2},
                {'Y', 0},
                {'V', 1},
                {'B', -2},
                {'J', 2},
                {'Z', -1},
                {'X', -1},
            }
        },
        {'F', 
            {
                {'A', -2},
                {'R', -2},
                {'N', -2},
                {'D', -4},
                {'C', -2},
                {'Q', -4},
                {'E', -3},
                {'G', -3},
                {'H', -2},
                {'I', 0},
                {'L', 1},
                {'K', -3},
                {'M', 0},
                {'F', 8},
                {'P', -3},
                {'S', -2},
                {'T', -1},
                {'W', 1},
                {'Y', 3},
                {'V', 0},
                {'B', -3},
                {'J', 1},
                {'Z', -3},
                {'X', -1},
            }
        },
        {'P', 
            {
                {'A', -1},
                {'R', -2},
                {'N', -2},
                {'D', -1},
                {'C', -4},
                {'Q', -1},
                {'E', 0},
                {'G', -2},
                {'H', -2},
                {'I', -2},
                {'L', -3},
                {'K', -1},
                {'M', -2},
                {'F', -3},
                {'P', 9},
                {'S', -1},
                {'T', -1},
                {'W', -3},
                {'Y', -3},
                {'V', -3},
                {'B', -2},
                {'J', -3},
                {'Z', -1},
                {'X', -1},
            }
        },
        {'S', 
            {
                {'A', 1},
                {'R', -1},
                {'N', 1},
                {'D', 0},
                {'C', -1},
                {'Q', 0},
                {'E', 0},
                {'G', 0},
                {'H', -1},
                {'I', -2},
                {'L', -3},
                {'K', -1},
                {'M', -2},
                {'F', -2},
                {'P', -1},
                {'S', 4},
                {'T', 2},
                {'W', -4},
                {'Y', -2},
                {'V', -1},
                {'B', 0},
                {'J', -2},
                {'Z', 0},
                {'X', -1},
            }
        },
        {'T', 
            {
                {'A', 0},
                {'R', -1},
                {'N', 0},
                {'D', -1},
                {'C', -1},
                {'Q', -1},
                {'E', -1},
                {'G', -2},
                {'H', -2},
                {'I', -1},
                {'L', -1},
                {'K', -1},
                {'M', -1},
                {'F', -1},
                {'P', -1},
                {'S', 2},
                {'T', 5},
                {'W', -3},
                {'Y', -1},
                {'V', 0},
                {'B', 0},
                {'J', -1},
                {'Z', -1},
                {'X', -1},
            }
        },
        {'W', 
            {
                {'A', -2},
                {'R', -2},
                {'N', -4},
                {'D', -4},
                {'C', -5},
                {'Q', -2},
                {'E', -3},
                {'G', -2},
                {'H', -3},
                {'I', -2},
                {'L', -2},
                {'K', -2},
                {'M', -2},
                {'F', -1},
                {'P', -3},
                {'S', -4},
                {'T', -3},
                {'W', 15},
                {'Y', 3},
                {'V', -3},
                {'B', -4},
                {'J', -2},
                {'Z', -2},
                {'X', -1},
            }
        },
        {'Y', 
            {
                {'A', -2},
                {'R', -1},
                {'N', -2},
                {'D', -2},
                {'C', -3},
                {'Q', -1},
                {'E', -2},
                {'G', -3},
                {'H', 2},
                {'I', 0},
                {'L', 0},
                {'K', -1},
                {'M', 0},
                {'F', 3},
                {'P', -3},
                {'S', -2},
                {'T', -1},
                {'W', 3},
                {'Y', 8},
                {'V', -1},
                {'B', -2},
                {'J', 0},
                {'Z', -2},
                {'X', -1},
            }
        },
        {'V', 
            {
                {'A', 0},
                {'R', -2},
                {'N', -3},
                {'D', -3},
                {'C', -1},
                {'Q', -3},
                {'E', -3},
                {'G', -3},
                {'H', -3},
                {'I', 3},
                {'L', 1},
                {'K', -2},
                {'M', 1},
                {'F', 0},
                {'P', -3},
                {'S', -1},
                {'T', 0},
                {'W', -3},
                {'Y', -1},
                {'V', 5},
                {'B', -3},
                {'J', 2},
                {'Z', -3},
                {'X', -1},
            }
        },
        {'B', 
            {
                {'A', -1},
                {'R', -1},
                {'N', 5},
                {'D', 6},
                {'C', -2},
                {'Q', 0},
                {'E', 1},
                {'G', -1},
                {'H', 0},
                {'I', -3},
                {'L', -3},
                {'K', 0},
                {'M', -2},
                {'F', -3},
                {'P', -2},
                {'S', 0},
                {'T', 0},
                {'W', -4},
                {'Y', -2},
                {'V', -3},
                {'B', 5},
                {'J', -3},
                {'Z', 1},
                {'X', -1},
            }
        },
        {'J', 
            {
                {'A', -1},
                {'R', -3},
                {'N', -3},
                {'D', -3},
                {'C', -2},
                {'Q', -2},
                {'E', -3},
                {'G', -4},
                {'H', -2},
                {'I', 4},
                {'L', 4},
                {'K', -3},
                {'M', 2},
                {'F', 1},
                {'P', -3},
                {'S', -2},
                {'T', -1},
                {'W', -2},
                {'Y', 0},
                {'V', 2},
                {'B', -3},
                {'J', 4},
                {'Z', -2},
                {'X', -1},
            }
        },
        {'Z', 
            {
                {'A', -1},
                {'R', 1},
                {'N', 0},
                {'D', 1},
                {'C', -3},
                {'Q', 4},
                {'E', 5},
                {'G', -2},
                {'H', 0},
                {'I', -3},
                {'L', -2},
                {'K', 1},
                {'M', -1},
                {'F', -3},
                {'P', -1},
                {'S', 0},
                {'T', -1},
                {'W', -2},
                {'Y', -2},
                {'V', -3},
                {'B', 1},
                {'J', -2},
                {'Z', 5},
                {'X', -1},
            }
        },
        {'X', 
            {
                {'A', -1},
                {'R', -1},
                {'N', -1},
                {'D', -1},
                {'C', -1},
                {'Q', -1},
                {'E', -1},
                {'G', -1},
                {'H', -1},
                {'I', -1},
                {'L', -1},
                {'K', -1},
                {'M', -1},
                {'F', -1},
                {'P', -1},
                {'S', -1},
                {'T', -1},
                {'W', -1},
                {'Y', -1},
                {'V', -1},
                {'B', -1},
                {'J', -1},
                {'Z', -1},
                {'X', -1},
            }
        },
        {'_', 
            {
                {'_', -5},
                
            }
        },     
    };
        

    return table2;
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




vector<vector<int>> buildBoard(string seq1, string seq2, unordered_map<char, unordered_map<char, int>> table){

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
  int gap = table.at('_').at('_');

  //cout << seq1.length() << endl;
  //cout << seq2.length() << endl;
  
  for (int i = 0; i < seq2.length(); i++){
    for (int j=0; j < seq1.length(); j++){
      //cout << i << " " << j << endl;
      int diagonal = board[i][j];
      int top = board[i][j+1];
      int left = board[i+1][j];
      //cout << "here" << endl;

      char seq1C = seq1[j];
      char seq2C = seq2[i];
      int matchScore = table.at(seq1C).at(seq2C);
     
      int diagonalScore = diagonal + matchScore;
      int topScore = top + gap;
      int leftScore = left + gap;


      int bestScore = getMax(diagonalScore, topScore, leftScore);

      if (bestScore < 0) {
        board[i+1][j+1] = 0;
      } else {
        board[i+1][j+1] = bestScore;
        if (bestScore > veryBestScore) {
            //cout << i << " " << j << endl;
            veryBestScore = bestScore;
            bestI = i + 1;
            bestJ = j + 1;
        }
      }
    }
  }
  return board;
}


       
void traceBack(vector<vector<int>> board, unordered_map<char, unordered_map<char, int>> table){

   
    //int identities = 0
    int i = bestI;
    int j = bestJ;

    int gap = table.at('_').at('_');

    //cout << bestI << " " << bestJ << endl;


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
            int matchScore = table.at(seq1[j-1]).at(seq2[i-1]);

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



int main(int argc, char* argv[]) {
    
    if (argc != 3){
        cout << "ERROR invalid number of files.\nCORRECT USE: ./threaded.cpp <filename.txt> <filename.txt>"<< endl;
    }
    string file1 = argv[1];
    string file2 = argv[2];
    file2 = "../input/" + file2;
    file1 = "../input/" + file1;
    auto start = high_resolution_clock::now();
    seq1 = loadfile(file1);
    seq2 = loadfile(file2);
    unordered_map<char, unordered_map<char, int>>table = GenMatrix();

    auto start2 = high_resolution_clock::now();
    vector<vector<int>> board = buildBoard(seq1, seq2, table);
    auto end2 = high_resolution_clock::now();
    auto board_time = duration_cast<microseconds>(end2-start2);
    unsigned int seconds = board_time.count();
    float CUPS = (seq1.length() * seq2.length()+2)/ seconds;

    string s = "";
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[0].size(); j++){
            s += to_string(board[i][j]) + " ";
        }
        //cout <<to_string(i)+ " "<< s << endl;
        s = "";
    }

    //cout << bestI << " " << bestJ << endl;
    //cout << board.size() << endl;
    traceBack(board, table);
    
     int longestFile = 0;
    
    if (seq1.length() > seq2.length()) longestFile = seq1.length();
    else longestFile = seq2.length();
    cout << finalSeq1 << endl;
    cout << finalSeq2 << endl;
  
    
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "time taken (milliseconds) for serial2: " << duration.count() << endl;
    ofstream myfile;
    myfile.open("../output/serial_results.txt", ios_base::app);
    myfile << "\nSERIAL RESULTS: " << endl;
    myfile << "Sequence 1: "+finalSeq1+"\nSequence 2: "+ finalSeq2+ "\nExecution time (milliseconds): " + to_string(duration.count())+"\nCUPMS: "<<CUPS<<"\nSequence length: " <<longestFile <<endl;;
    myfile.close();

}