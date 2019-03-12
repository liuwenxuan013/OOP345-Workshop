//  WS01 - Linkage, Storage Duration, Namespaces, and OS Interface
//  Student ID:   160678173
//  Created by Liu Wenxuan on 2019-01-15.
//  Copyright © 2019 Liu Wenxuan. All rights reserved.
//  String.cpp

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "String.h"

extern const  int  INITIAL;
static int num= INITIAL;
namespace sict{
//one argument constructor
    String::String(const char* s ){
        if(s!=nullptr&&strlen(s)!=0){
            strncpy(str,s,MAX);
            str[MAX]='\0';
        }
        else str[0]='\0';
    }
//display
    void String::display(std::ostream& os)const{
        os<<num++<<": "<<str;
    }
//ostream operator <<
    std::ostream& operator<<(std::ostream& os,String& s){
        s.display(os);
        return os;
    }
}
    



    
