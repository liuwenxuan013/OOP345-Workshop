//  WS01 - Linkage, Storage Duration, Namespaces, and OS Interface
//  Student ID:   160678173
//  Created by Liu Wenxuan on 2019-01-15.
//  Copyright © 2019 Liu Wenxuan. All rights reserved.
//  w1.cpp

#include "process.h"
#include "String.h"

using namespace sict;
extern const int INITIAL = 3;

int main(int argc, char* argv[]){
    int n;
    if(argc==0){
        std::cout<<"***Insufficient number of argument***";
        n= 1;}
    else{
        std::cout<<"Command Line :";
        for(int i=0;i<argc;i++)
            std::cout<<" "<<argv[i];
        std::cout<<" "<<std::endl;
        for(int i=1;i<argc;i++)
            process(argv[i]);
        n= 0;}
    return n;
    
}
    


