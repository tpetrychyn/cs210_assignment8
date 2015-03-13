//
//  InstructionsArray.cpp
//  Assignment8
//
//  Created by Taylor Petrychyn on 2015-03-06.
//  Copyright (c) 2015 Taylor Petrychyn. All rights reserved.
//

#include "InstructionsArray.h"

InstructionsArray::InstructionsArray() {
    length = 0;
    p = -1;
}

void InstructionsArray::ResetP() {
    p = -1;
}

void InstructionsArray::Iterate() {
    p++;
}

bool InstructionsArray::IsPSet() {
    if (p < 0 || p > length-1)
        return false;
    return true;
}

int InstructionsArray::GetP() {
    return p;
}

void InstructionsArray::SetP(const int& newP) {
    p = newP;
}

Data InstructionsArray::Read() {
    return data[p];
}

void InstructionsArray::Write(const Data& d) {
    data[p] = d;
}

bool InstructionsArray::IsFull() {
    if (length == MAX_LENGTH)
        return true;
        return false;
}

bool InstructionsArray::IsEmpty() {
    if (length == 0)
        return true;
    return false;
}

void InstructionsArray::InsertUnsorted(const Data& d) {
    p = length;
    data[p] = d;
    length++;
}