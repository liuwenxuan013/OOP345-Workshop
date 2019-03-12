// LVPair.h
//  ws03
//  Name:  Wenxuan Liu
//  Student ID:160678173
//  Created by Liu Wenxuan on 2019-01-30.
//  Copyright © 2019 Liu Wenxuan. All rights reserved.
//

#ifndef SICT_LVPAIR_H
#define SICT_LVPAIR_H
#include <iostream>

namespace sict {
    template<typename L, typename V >
    class LVPair {
        L sLable;
        V sValue;
    public:
        LVPair(): sLable(), sValue(){  }
        LVPair(const L& label, const V& value) {
            sLable = label;
            sValue = value;
        }
        
        void display(std::ostream& os) const {
            os << sLable << " : " << sValue << std::endl;
        }
     
    };
    
    template <typename L, typename V>
    std::ostream& operator<<(std::ostream& os, const LVPair<L,V>& pair) {
       pair.display(os);
        return os;
    }
}
#endif // !SICT_LIST_H

