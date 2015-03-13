//
//  StackArray.h
//  Assignment8
//
//  Created by Taylor Petrychyn on 2015-03-13.
//  Copyright (c) 2015 Taylor Petrychyn. All rights reserved.
//

#ifndef __Assignment8__StackArray__
#define __Assignment8__StackArray__

#include <stdio.h>

const int MAX_HEIGHT = 100;;

class StackArray {
private:
    int top;
    int data[MAX_HEIGHT];
public:
    StackArray();
    
    int Height();
    
    bool IsEmpty();
    
    // checks whether the stack is full
    bool IsFull();
    
    // inserts a new item on the top of the stack
    // always call IsFull prior to calling Push
    // sets top
    void Push(const int& x);
    
    //removes the item on the top of the stack and returns the value it contained
    // always call IsEmpty prior to calling Pop
    // sets top
    int Pop();
    
    // returns the value of the item on the top of the stack
    // always call IsEmppty prior to calling Top
    int Top();
    
    // reinitializes the stack
    // sets top
    void Clear();
};

#endif /* defined(__Assignment8__StackArray__) */
