//  Message.cpp
//  ws04
//  Name:  Wenxuan Liu
//  Student ID:160678173
//  Created by Liu Wenxuan on 2019-02-06.
//  Copyright © 2019 Liu Wenxuan. All rights reserved.
//

#include <string>
#include "Message.h"

namespace sict {
    
    Message::Message(const std::string& str){
               size_t  pos1=str.find(' ',0);//pos1->' '
                if(pos1!=std::string::npos){
                    usr = str.substr(0, pos1);
                    size_t  pos2=str.find('@',pos1+1);//pos2->'@'
                    if(pos2==pos1+1){
                        size_t  pos3=str.find(' ',pos2+1);//pos3->‘ ’twt
                           re = str.substr(pos2+1,pos3-pos2-1);
                            pos1=pos3;
                    }
                        twt = str.substr(pos1+1);
		}
        	else *this = Message();
    }
    
    bool Message:: empty()const{
        return ( usr.empty() || twt.empty()) ? true:false;
    }
    
    void Message::display(std::ostream& os) const{
        if(!empty()){
            os << ">User  : "<< usr << std::endl;
            if(!re.empty())
                os << " Reply : "<< re << std::endl;
            os << " Tweet : "<< twt << std::endl;
          
        }
    }
}

