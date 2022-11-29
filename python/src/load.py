import argparse
from dna import *


def loadSeq(fileName):
    dnaSequence = ""
    file = open(fileName, "r")
    s = file.readline()[:3]
    if s == ">gi":
        file.readline()
    for line in file:
        for c in line:
            if c != "\n":
                dnaSequence += c

   
    return dnaSequence



def write(fileName, seq1, seq2, score, identities, indexes):
    percent = identities/ len(seq1)
    outputFile = open(fileName, "w")
    outputFile.write("seq1: " + str(indexes[0]) + " " + seq1 + " " + str(indexes[1]) + "\n")
    outputFile.write("seq2: " + str(indexes[2]) + " " + seq2 + " " + str(indexes[3]) + "\n")
    outputFile.write("\n")
    outputFile.write("Score: " + str(score) + "\n")
    outputFile.write("Identities: " + str(identities) + "/" + str(len(seq1)) +  " (" + '{:.0%}'.format(percent) + ")")



def printboard(board):
    s = ""
    for i in range(len(board)):
        s += str(board[i]) + "\n"
    print(s)



def parseArguments():

    errorMessage = "\n"
    error = False

    parser = argparse.ArgumentParser()
    parser.add_argument("-i", "--seq1")
    parser.add_argument("-j", "--seq2")
    parser.add_argument("-o", "--outFile")
    parser.add_argument("-p", "--protein")
    parser.add_argument("-atype", "--alignment")
    args = parser.parse_args()

    try:
        seq1 = loadSeq("../sequences/" + args.seq1)
    except:
        errorMessage += "Please add <-i> follow by the first sequence file\n"
        error = True
    try:
        seq2 = loadSeq("../sequences/" + args.seq2)
    except:
        errorMessage += "Please add <-j> follow by the second sequence file\n"
        error = True

    try:
        output = open(args.outFile, "w")
        outFile = args.outFile
    except:
        errorMessage += "Please add <-o> followed by output file name\n"
        error = True

    if args.protein == 'T':
        table = PROTEIN_MATRIX
        row = PROTEIN
    elif args.protein == 'F':
        table = DNA_MATRIX
        row = DNA
    else:
        errorMessage += "Please add <-p> followed by <T> or <F>\n"
        error = True

    if args.alignment == 'G':
        alignment = "Globall"
    elif args.alignment == 'S':
        alignment = "Semi-Global"
    elif args.alignment == 'L':
        alignment = "Local"
    else:
        errorMessage += "Please add <-atype> followed by <G> or <S>\n"
        error = True

    if error == True:
        print(errorMessage)
        exit()

    
    return seq1, seq2, table, row, alignment, outFile