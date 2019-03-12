// List.h
//  ws03
//  Name:  Wenxuan Liu
//  Student ID:160678173
//  Created by Liu Wenxuan on 2019-01-30.
//  Copyright © 2019 Liu Wenxuan. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#ifndef SICT_LIST_H
#define SICT_LIST_H
#include "LVPair.h"

namespace sict {
    template <typename T, size_t N>
    class List {
        T arr[N];
        size_t num{0u};
    public:
        size_t size()const {
            return num;
        }
        const T& operator[](size_t i)const {
            return arr[i];
            
        }
        void operator+=(const T& t) {
            if (num < N) {
                arr[num] = t;
                num++;
            }
        }
    };

    template<typename T, typename L, typename V, size_t N>
    class LVList : public List<T, N> {
        
    public:
        V accumulate(const L& label) const {
            V sValue = SummableLVPair<L, V>::getInitialValue();
            for(size_t i=0; i<((List<T, N>&)*this).size(); i++)
                sValue =(*this)[i].sum(label, sValue);
            return sValue;
        }
    };
}
#endif // !SICT_LIST_H
