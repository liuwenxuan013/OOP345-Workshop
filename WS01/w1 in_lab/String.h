//  WS01 - Linkage, Storage Duration, Namespaces, and OS Interface
//  Student ID:   160678173
//  Created by Liu Wenxuan on 2019-01-15.
//  Copyright © 2019 Liu Wenxuan. All rights reserved.
//  String.h

#ifndef SICT_STR_H
#define SICT_STR_H

#include <iostream>
namespace sict{
    const int MAX=3;
    class String{
        char str[MAX+1];
    public:
        String(const char* );
        void display(std::ostream&)const;
    };
    std::ostream& operator<<(std::ostream& os, String& s);
}
#endif /* String_h */
