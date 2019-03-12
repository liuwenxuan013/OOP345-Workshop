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

namespace sict {
    template <typename T, size_t N>
    class List {
        size_t num{0u};
        T arr[N];
    public:
        size_t size()const{
            return num;
        }
        
        const T& operator[](size_t i)const {
                return arr[i];
        }
        
        void operator+=(const T& t) {
            if (num < N){
                arr[num] = t;
                num++;}
        }
    };
}

#endif // !SICT_LIST_H
