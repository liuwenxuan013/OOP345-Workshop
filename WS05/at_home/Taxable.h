//
//  Taxable.h
//  pro1
//
//  Created by Liu Wenxuan on 2019-02-15.
//  Copyright © 2019 Liu Wenxuan. All rights reserved.
//

#ifndef SICT_Taxable_h
#define SICT_Taxable_h

namespace sict{
class Taxable{
    const float tax;
public:
    Taxable():tax{9}{};
    Taxable(float t):tax(t){};
    float operator()(float p){
        return p+p*tax;
    }
};
}


#endif /* SICT_Taxable_h */
