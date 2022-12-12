//#include "threaded.h"

#include <iostream>
#include <thread>
#include <vector>
#include <fstream>
#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <unordered_map>
#include <time.h>
#include <stack>
#include <mutex>

using namespace std;
using namespace std::chrono;

string seq1;
string seq2;
string finalSeq1 = "";
string finalSeq2 = "";


unordered_map<char, unordered_map<char, int>> GenMatrix() {
   
    unordered_map<char, unordered_map<char, int>>table;

    table = {
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
  return seq;
}




void buildMatrix(string seq1, string seq2, unordered_map<char, unordered_map<char, int>> table, vector<vector<int>> &board, int id, mutex &m, int numThreads, std::stack<vector<int>> &stack){

  //cout << "here" << endl;
  int verybestscore = 0;
 
  int gap = table.at('_').at('_');

  int i = id;
  int j = 0;
  int rows = board.size();
  int cols = board[0].size();

  int bestI = i;
  int bestJ = j;
  //cout << id << " here " <<  endl;
  //cout << rows << " " << cols << endl;
  while(i < rows - 1) {
    while(j < cols - 1) {
        if (board[i][j+1] != -1 and board[i+1][j] != -1 and board[i][j] != -1) {
        //this_thread::sleep_for(chrono::nanoseconds(1));
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
            if(bestScore > verybestscore) {
                verybestscore = bestScore;
                bestI = i + 1;
                bestJ = j + 1;
            }
        }
        j += 1;
        }
    }
    j = 0;
    i += numThreads;
  }
  m.lock();
  stack.push({bestI, bestJ});
  m.unlock();
}


       
void traceBack(vector<vector<int>> board, unordered_map<char, unordered_map<char, int>> table, int i, int j){

   
    //int identities = 0
   

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

    int boardColumns = seq1.length() +1;
    int boardRows = seq2.length() +1;

    vector<vector<int>> board;
    for(int i=0; i < boardRows; i++){
    vector<int> tempV;
    for(int j = 0; j < boardColumns; j++){
        if(i == 0 or j == 0){
        tempV.push_back(0);
        }
        else{
        tempV.push_back(-1);
        }
    }
    board.push_back(tempV);
    }



    std::vector<std::thread> threads;
    mutex m;
    int b_size = board.size()-1;

    int numThreads = 10;
    std::stack<vector<int>> stack;
    for (int i = 0; i < numThreads; i++) {
    int id = i;
    std::thread t(buildMatrix, seq1, seq2, table, ref(board), id, ref(m), numThreads, ref(stack));
    threads.push_back(std::move(t));
    }

    for (auto &t : threads) {
    t.join();
    }
    string s = "";
    for(int i = 0; i < boardRows; i++){
    for(int j = 0; j < boardColumns; j++){
        s += to_string(board[i][j]) + " ";
    }
    //cout <<to_string(i)+ " "<<  s << endl;
    s = "";
    }


    int max = 0;
    int i = 0;
    int j = 0;
    while(!stack.empty()) {
    vector<int> v = stack.top();
    //cout << v[0] << " " << v[1]<< endl;
    stack.pop();
    int curr = board[v[0]][v[1]];
    if (curr > max) {
            max = curr;
            i = v[0];
            j = v[1];
    
    } else if (curr == max)    {
            if (i > v[0]) {
                max = curr;
                i = v[0];
                j = v[1];
            }
        }
    }
    
    //cout << i << " " << j << endl;
    //cout << board.size() << endl;


    traceBack(board, table, i, j);
    auto stop = high_resolution_clock::now();

    cout << finalSeq1 << endl;
    cout << finalSeq2 << endl;
    
    auto duration = duration_cast<milliseconds>(stop - start);
    ofstream myfile;
    //file_name = "../input/" + to_string(argv[2]);
    myfile.open("../output/threaded_results.txt");
    myfile << "THREADED RESULTS: " << endl;
    myfile << finalSeq1 + "\n" + finalSeq2+ "\n" + "Execution time (milliseconds): " + to_string(duration.count());
    myfile.close();

    



    return 0;
}
