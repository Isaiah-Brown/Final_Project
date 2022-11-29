

from load import *
from dna import *





def getScoreL(seq1, seq2, table, row):

    boardColumns = len(seq1) + 1
    boardRows = len(seq2) + 1
    board = [[0] * boardColumns for i in range(boardRows)]
    veryBestScore = 0

    for i in range(len(seq2)):
        for j in range(len(seq1)):
            diagonal = board[i][j]
            top = board[i][j+1]
            left = board[i+1][j]

            seq1C = seq1[j]
            seq2C = seq2[i]
            idx = row.index(seq2C)
            matchScore = table[seq1C][idx]

            diagonalScore = diagonal + matchScore
            topScore = top + table["gap"]
            leftScore = left + table["gap"]

            bestScore = max(diagonalScore, topScore, leftScore)
            if bestScore < 0:
                board[i+1][j+1] = 0
            else: 
                board[i+1][j+1] = bestScore
                if bestScore > veryBestScore:
                    veryBestScore = bestScore
                    bestI = i + 1
                    bestJ = j + 1

    return bestI, bestJ, board



def traceBackL(seq1, seq2, table, row, board, bestI, bestJ):

    finalSeq1 = ""
    finalSeq2 = ""
    identities = 0

    i = bestI
    j = bestJ

    while(board[i][j] != 0):
        if i == 0:
            finalSeq1 += seq1[j-1]
            finalSeq2 += "_"
            j -= 1
            startJ -= 1
        elif j == 0:
            finalSeq1 += "_"
            finalSeq2 += seq2[i-1]
            i -= 1
            startI -= 1
        else:
            diagonal = board[i-1][j-1]
            idx = row.index(seq2[i-1])
            matchScore = table[seq1[j-1]][idx]

            diagonalScore = diagonal + matchScore
            topScore = board[i-1][j] + table["gap"]
            leftScore = board[i][j-1] + table["gap"]

            if diagonalScore >= topScore and diagonalScore >= leftScore:
                if seq1[j-1] == seq2[i-1]:
                    identities += 1

                finalSeq1 += seq1[j-1]
                finalSeq2 += seq2[i-1]
                i = i -1
                j = j -1
            elif topScore > leftScore:
                finalSeq1 += "_"
                finalSeq2 += seq2[i-1]
                i = i-1
            else:
                finalSeq1 += seq1[j-1]
                finalSeq2 += "_"
                j = j-1
            
    finalSeq1 = finalSeq1[::-1]
    finalSeq2 = finalSeq2[::-1]

    indexes = [j + 1, bestJ, i + 1, bestI]
   
    return finalSeq1, finalSeq2, identities, indexes



if __name__ == "__main__":

    # example command line argument
    # python3 align.py -o out.txt -atype L -i proteinseq3.txt -j proteinseq4.txt -p T

    seq1, seq2, table, row, alignment, outFile = parseArguments()

    
    bestI, bestJ, board = getScoreL(seq1, seq2, table, row)
    score = board[bestI][bestJ]
    finalSeq1, finalSeq2, identities, indexes = traceBackL(seq1, seq2, table, row, board, bestI, bestJ)

    

    
    write(outFile, finalSeq1, finalSeq2, score, identities, indexes)
