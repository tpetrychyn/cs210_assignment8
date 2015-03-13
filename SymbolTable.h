//
//  InstructionsArray.h
//  Assignment8
//
//  Created by Taylor Petrychyn on 2015-03-06.
//  Copyright (c) 2015 Taylor Petrychyn. All rights reserved.
//

#ifndef __Assignment8__InstructionsArray__
#define __Assignment8__InstructionsArray__

//Before interpreting a HAL program, the instructions in the file should be read into a program array implemented as an unsorted array-based list type defined as a C++ class, where each element consists of a struct containing two members: (1) a string operation member and (2) a char* operand member. For example, the following program array contains the example HAL program shown above. Here, each line of the program is associated with a unique, sequential integer (i.e., the array index which doubles as the line number, so the line number from the input file does not need to be stored in the program array). A special variable of type int named pc (i.e., program counter) should be used to indicate the next instruction to execute.


#include <stdio.h>
#include <string>

using namespace std;

const int MAX_LENGTH = 100;

struct Data {
    string symbol;
    int value;
    
    friend class InstructionsArray;
};

class SymbolTable {
private:
    int p;
    int length;
    Data data[MAX_LENGTH];
    
public:
    
    // this is the constructor
    // initializes the list
    SymbolTable();
    
    void ResetP();
    
    void Iterate();
    
    bool IsPSet();
    
    int GetP();
    
    void SetP(const int& newP);
    
    Data Read();
    
    void Write(const Data& d);
    
    bool IsFull();
    bool IsEmpty();
    
    int Length() { return length; }
    
    void InsertSorted(const Data& d);
    
    bool FindSorted(const string& x);
};

#endif /* defined(__Assignment8__InstructionsArray__) */
