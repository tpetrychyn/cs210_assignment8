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


using namespace std;

int main(int argc, const char * argv[]) {
    ifstream inData;
    inData.open("instructions.txt");
    if (!inData) {
        return 0;
    }
    
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
              || tempData.member == "end")) {
            string operand;
            getline(inData , operand);
            operand.erase(0,1);
            tempData.operand = new char[operand.length() + 1];
            strcpy(tempData.operand, operand.c_str());
        } else tempData.operand = "\0";
        instructions.InsertUnsorted(tempData);
    }
    
    instructions.ResetP();
    instructions.Iterate();
    for (int i=0;i<instructions.Length();i++) {
        cout << instructions.Read().member << " " << instructions.Read().operand << endl;
        instructions.Iterate();
    }
    
    return 0;
}
