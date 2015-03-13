//
//  SymbolTable.cpp
//  Assignment8
//
//  Created by Taylor Petrychyn on 2015-03-06.
//  Copyright (c) 2015 Taylor Petrychyn. All rights reserved.
//

#include "SymbolTable.h"

SymbolTable::SymbolTable() {
    length = 0;
    p = -1;
}

void SymbolTable::ResetP() {
    p = -1;
}

void SymbolTable::Iterate() {
    p++;
}

bool SymbolTable::IsPSet() {
    if (p < 0 || p > length-1)
        return false;
    return true;
}

int SymbolTable::GetP() {
    return p;
}

void SymbolTable::SetP(const int& newP) {
    p = newP;
}

Data SymbolTable::Read() {
    return data[p];
}

void SymbolTable::Write(const Data& d) {
    data[p] = d;
}

bool SymbolTable::IsFull() {
    if (length == MAX_LENGTH)
        return true;
    return false;
}

bool SymbolTable::IsEmpty() {
    if (length == 0)
        return true;
    return false;
}

void SymbolTable::InsertSorted(const Data& d) {
    p = 0;
    while (p < length && d.symbol > data[p].symbol)
        p ++;
    int q = length;
    while (q > p) {
        data[q] = data[q-1];
        q --;
    }
    data[p] = d;
    length ++;
    return;
}

bool SymbolTable::FindSorted(const string& x) {
    int q = 0;
    int r = length - 1;
    while (q <= r) {
        p = (q + r) / 2;
        if (x < data[p].symbol)
            r = p - 1;
        else if (x > data[p].symbol)
            q = p + 1;
        else
            return true;
    }
    return false;
}