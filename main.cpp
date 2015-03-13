//
//  main.cpp
//  Assignment8
//
//  Created by Taylor Petrychyn on 2015-03-06.
//  Copyright (c) 2015 Taylor Petrychyn. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "InstructionsArray.h"
#include "SymbolTable.h"
#include "StackArray.h"


using namespace std;

int main(int argc, const char * argv[]) {
    ifstream inData;
    if (argc < 2) {
        cout << "Usage: ./main <filename>" << endl;
        return 0;
    }
    inData.open(argv[1]);
    if (!inData) {
        return 0;
    }
    
    int status = -1;
    
    //Populates the instructions array with the input
    InstructionsArray instructions;
    instructions.Iterate();
    string firstNum;
    while (!inData.eof()) {
        inData >> firstNum; //get the first num and do nothing with it
        Data tempData;
        inData >> tempData.member;
        if (!(tempData.member == "read"
            || tempData.member == "add"
            || tempData.member == "subtract"
            || tempData.member == "compare"
            || tempData.member == "write"
            || tempData.member == "writenl"
              || tempData.member == "end")) { //check if there is an operand
            string operand;
            getline(inData , operand);
            operand.erase(0,1);
            tempData.operand = new char[operand.length() + 1];
            strcpy(tempData.operand, operand.c_str());
        } else tempData.operand = "\0";
        instructions.InsertUnsorted(tempData);
    }
    
    //table and stack
    SymbolTable symTable;
    StackArray stack;
    //put our instructions to step 1
    instructions.ResetP();
    instructions.Iterate();
    while(1) {
        cout << instructions.GetP() << " ";
        
        //read our instruction, not necessary but makes for shorter if statements
        Data read = instructions.Read();
        
        //compare the read line to a string and perform the action associated
        if (read.member == "declare") {
            SymData temp;
            temp.symbol = read.operand;
            symTable.InsertSorted(temp);
        } else if (read.member == "read") {
            if (!stack.IsFull()) {
                int value;
                cin >> value;
                stack.Push(value);
            }
        } else if (read.member == "put") {
            if (!stack.IsFull())
                stack.Push(atoi(read.operand));
        } else if (read.member == "get") {
            if (!stack.IsFull()) {
                if (symTable.FindSorted(read.operand)) {
                    if (!symTable.IsEmpty())
                        stack.Push(symTable.Read().value);
                }
            }
        } else if (read.member == "add") {
            if (!stack.IsEmpty()) {
                int num = stack.Pop();
                if (!stack.IsEmpty()) {
                    num += stack.Pop();
                    stack.Push(num);
                }
            }
        } else if (read.member == "multiply") {
            if (!stack.IsEmpty()) {
                int num = stack.Pop();
                if (!stack.IsEmpty()) {
                    num *= stack.Pop();
                    stack.Push(num);
                }
            }
        } else if (read.member == "subtract") {
            if (!stack.IsEmpty()) {
                int num = stack.Pop();
                if (!stack.IsEmpty()) {
                    num -= stack.Pop();
                    stack.Push(num);
                }
            }
        } else if (read.member == "divide") {
            if (!stack.IsEmpty()) {
                int num = stack.Pop();
                if (!stack.IsEmpty()) {
                    num /= stack.Pop();
                    stack.Push(num);
                }
            }
        } else if (read.member == "set") {
            if (symTable.FindSorted(read.operand)) {
                if (!stack.IsEmpty()) {
                    SymData temp;
                    temp.symbol = read.operand;
                    temp.value = stack.Pop();
                    symTable.Write(temp);
                }
            }
        } else if (read.member == "write") {
            if (!stack.IsEmpty())
                cout << stack.Pop();
        } else if (read.member == "writestring") {
            cout << read.operand;
        } else if (read.member == "writenl") {
            cout << endl;
        } else if (read.member == "compare") {
            if (!stack.IsEmpty()) {
                int num = stack.Pop();
                if (!stack.IsEmpty()) {
                    if (num == stack.Pop())
                        status = 1;
                    else
                        status = 0;
                }
            }
        } else if (read.member == "jumpequal") {
            if (status == 1) {
                status = -1;
                instructions.ResetP();
                for (int i=0;i<atoi(read.operand);i++)
                    instructions.Iterate();
            }
        } else if (read.member == "jump") {
            instructions.ResetP();
            for (int i=0;i<atoi(read.operand);i++)
                instructions.Iterate();
        } else if (read.member == "end") {
            return 0;
        }
        
        instructions.Iterate();
    }
    
    return 0;
}
