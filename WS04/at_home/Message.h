//  Message.h
//  ws04
//  Name:  Wenxuan Liu
//  Student ID:160678173
//  Created by Liu Wenxuan on 2019-02-06.
//  Copyright © 2019 Liu Wenxuan. All rights reserved.
//

#ifndef SICT_MESSAGE_H
#define SICT_MESSAGE_H
#include <iostream>
#include <string>

namespace sict {
    class Message{
        std::string usr;
        std::string re;
        std::string twt;
    public:
        Message():usr(),re(),twt(){};
        Message(const std::string& str);
        bool empty() const;
        void display(std::ostream& os) const;
    };
}
#endif // !SICT_MESSAGE_H

