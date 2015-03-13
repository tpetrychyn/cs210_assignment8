//
//  StackArray.cpp
//  Assignment8
//
//  Created by Taylor Petrychyn on 2015-03-13.
//  Copyright (c) 2015 Taylor Petrychyn. All rights reserved.
//

#include "StackArray.h"

StackArray::StackArray() {
    top = -1;
}

int StackArray::Height() {
    return top + 1;
}

bool StackArray::IsEmpty() {
    return (top == -1);
}

bool StackArray::IsFull() {
    return (top == MAX_HEIGHT - 1);
}

void StackArray::Push(const int& x) {
    top++;
    data[top] = x;
    return;
}

int StackArray::Pop() {
    int x = data[top];
    top--;
    return x;
}

int StackArray::Top() {
    return data[top];
}

void StackArray::Clear() {
    top = -1;
    return;
}