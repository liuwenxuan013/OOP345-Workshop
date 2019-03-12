//
//  MessagePack.cpp
//  pro1
//
//  Created by Liu Wenxuan on 2019-02-08.
//  Copyright © 2019 Liu Wenxuan. All rights reserved.
//
#include <utility>
#include "MessagePack.h"
namespace sict {
    MessagePack::MessagePack(Message** m,size_t n){
        if(n>0&&m!=nullptr){
            msg = new Message* [n];
            for(size_t i=0u;i<n;i++){
                if(!m[i]->empty()){
                    msg[count]=new Message(*m[i]);
                    count++;}
            }
        }
        else *this=MessagePack();
    }
    MessagePack:: ~MessagePack(){
        for(size_t i=0; i<count;i++)
        delete msg[i];
        delete [] msg;
    }
    MessagePack::MessagePack(const MessagePack& mpk){
        *this=mpk;
    }
    MessagePack::MessagePack(MessagePack&& mpk){
        *this=std::move(mpk);
    }
    MessagePack& MessagePack::operator=(const MessagePack& mpk){
        if(this!=&mpk){
           for(size_t i=0;i<count;i++)   delete msg[i];
            delete [] msg;
            count=mpk.count;
            msg=new Message* [count];
            for(size_t i=0;i<count;i++)
                msg[i]=new Message(*(mpk.msg[i]));
        }
        return *this;
    }
    MessagePack& MessagePack::operator=(MessagePack&& mpk){
        if(this!=&mpk){
            delete [] msg;
            count=mpk.count; mpk.count=0;
            msg=mpk.msg;     mpk.msg=nullptr;
        }
        return *this;
    }  
    void MessagePack::display(std::ostream& os) const{
        for(size_t i=0u;i<count;i++)
        msg[i]->display(os);
    }
    size_t MessagePack::size() const{
        return count;
    }
    std::ostream&operator<<(std::ostream& os,const MessagePack& mpk){
        mpk.display(os);
        return os;
    }
}
