//
//  InstructionsArray.h
//  Assignment8
//
//  Created by Taylor Petrychyn on 2015-03-06.
//  Copyright (c) 2015 Taylor Petrychyn. All rights reserved.
//

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <stdio.h>
#include <string>

using namespace std;

const int MAX = 100;

struct SymData {
    string symbol;
    int value;
    
    SymData();
    
    friend class SymbolTable;
};

class SymbolTable {
private:
    int p;
    int length;
    SymData data[MAX];
    
public:
    
    // this is the constructor
    // initializes the list
    SymbolTable();
    
    void ResetP();
    
    void Iterate();
    
    bool IsPSet();
    
    int GetP();
    
    void SetP(const int& newP);
    
    SymData Read();
    
    void Write(const SymData& d);
    
    bool IsFull();
    bool IsEmpty();
    
    int Length() { return length; }
    
    void InsertSorted(const SymData& d);
    
    bool FindSorted(const string& x);
};

#endif
