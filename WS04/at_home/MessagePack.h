//
//  MessagePack.h
//  pro1
//
//  Created by Liu Wenxuan on 2019-02-08.
//  Copyright © 2019 Liu Wenxuan. All rights reserved.
//

#ifndef SICT_MESSAGEPACK_H
#define SICT_MESSAGEPACK_H
#include "Message.h"
namespace sict {
    class MessagePack{
        Message **msg{nullptr};
        size_t count{0};
    public:
        MessagePack():msg{nullptr},count{0}{};
        MessagePack(Message** m,size_t n);
         ~MessagePack();
        MessagePack(const MessagePack&);
        MessagePack(MessagePack&&);
        MessagePack& operator=(const MessagePack&);
        MessagePack& operator=(MessagePack&&);
        void display(std::ostream& os) const;
        size_t size() const;
    };
    std::ostream&operator<<(std::ostream& os,const MessagePack& mpk);
}
#endif // !SICT_MESSAGEPACK_H

