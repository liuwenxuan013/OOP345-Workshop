//
//  Notifications.cpp
//  pro1
//
//  Created by Liu Wenxuan on 2019-02-08.
//  Copyright © 2019 Liu Wenxuan. All rights reserved.
//

#include "Notifications.h"
namespace sict {
    Notifications::Notifications(int mx){
        if(mx>0){
               mp=new const Message*[mx];
               max=mx;
        }
        else *this=Notifications();
    }
    
    Notifications::~Notifications(){
        delete [] mp;
    }
    
    Notifications::Notifications(const Notifications& noti){*this=noti;
    }
    Notifications::Notifications(Notifications&& noti){
        *this=std::move(noti);
    }
    Notifications& Notifications::operator=(const Notifications& noti){
        if(this!=&noti){
            delete mp;
            max=noti.max;
            num=noti.num;
            mp=new const Message* [max];
            for(size_t i=0;i<max;i++){
                mp[i]=noti.mp[i];
            }
        }
        return *this;
    }
    Notifications& Notifications::operator=(Notifications&& noti){
        if(this!=&noti){
            delete [] mp;
            max=noti.max; noti.max=0;
            num=noti.num; noti.num=0;
            mp=noti.mp;   noti.mp=nullptr;
        }
        return *this;
    }
    
    Notifications& Notifications::operator+=(const Message& msg){
        if(num < max&&!msg.empty())
            mp[num++] = &msg;
        return *this;
    }
    Notifications& Notifications::operator-=(const Message& msg){
        bool found=false;
        size_t i;
        for (i=0;i<num&&!found; i++){
            if(mp[i]== &msg)
                found=true;
        }
        if(found){
            for(;i<num;i++)
                mp[i-1]=mp[i];
            if(num){
                    mp[num-1]=nullptr;
                    num--;
            }
        }
        return *this;
    }
    void Notifications::display(std::ostream& os)const{
        for(size_t i=0;i<num;i++)
            mp[i]->display(os);
    }
    size_t Notifications::size() const{
        return num;
    }
    std::ostream& operator<<( std::ostream& os, const Notifications& noti){
        noti.display(os);
        return os;
    }
}


