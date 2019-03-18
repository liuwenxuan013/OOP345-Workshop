//
//  DataTable.hpp
//  ws07
//
//  Created by Liu Wenxuan on 2019-03-14.
//  Copyright © 2019 Liu Wenxuan. All rights reserved.
//

#ifndef SICT_DataTable_hpp
#define SICT_DataTable_hpp
#include <numeric>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
extern int FW;
extern int ND;
namespace sict {
    template<typename T>
    class DataTable {
        std::vector<T> x_;
        std::vector<T> y_;
    public:
        DataTable(std::ifstream& f) {
            T x, y;
            if (f.is_open()) {
                while (!f.eof()) {
                    f >> x;
                    x_.push_back(x);
                    f >> y;
                    y_.push_back(y);}
            }
        }
        T mean() const {
            return accumulate(y_.begin(), y_.end(), (T)0)/ y_.size();}

        T sigma() const {
            T sum = 0;
            for (size_t i = 0; i < y_.size(); i++)
                sum = sum + (y_.at(i) - mean()) * (y_.at(i) - mean());
            return sqrt(sum / (y_.size() - 1));
        }
        T slope() const{
            T total_x = accumulate(x_.begin(), x_.end(), (T)0);
            T total_y = accumulate(y_.begin(), y_.end(), (T)0);
            T total_xx = inner_product(x_.begin(), x_.end(), x_.begin(), (T)0);
            T total_xy = inner_product(x_.begin(), x_.end(), y_.begin(), (T)0);
            T num = y_.size();
            return (num * total_xy - total_x * total_y) / (num * total_xx - total_x * total_x);
        }
        
        T median() const {
            std::vector<T> v = y_;
            sort(v.begin(), v.end());
            return v[y_.size() / 2];
        }
        T intercept() const{
            T total_x = accumulate(x_.begin(), x_.end(), (T)0);
            T total_y = accumulate(y_.begin(), y_.end(), (T)0);
            return  (total_y - slope()*total_x)/y_.size();
        }
        void displayData(std::ostream& os) const {
            os<<"Data Values"<<std::endl;
            os<<"------------"<<std::endl;
            os << std::fixed<< std::setfill(' ')<< std::setw(FW) << std::setprecision(ND) <<  'X';
            os << std::setw(FW) << 'Y' << std::endl;
           for (int i = 0; i < x_.size(); i++) {
                os  <<std::setprecision(ND)<<std::setw(FW) << x_[i] << std::setw(FW) << y_[i] <<std::endl;
          }
           
        }
       
        void displayStatistics(std::ostream& os)const{
            os<<"Statistics"<<std::endl;
            os<<"----------"<<std::endl;
            os << std::fixed<< std::setfill(' ');
            os << std::setw(FW+3) <<std::left<< "  y mean"<<std::setw(FW) <<"   ="<< std::right<<mean()<<std::endl;
            os << std::setw(FW+3) <<std::left<< "  y sigma"<<std::setw(FW) <<"   =" << std::right<<sigma()<<std::endl;
            os << std::setw(FW+3) <<std::left<< "  y median"<<std::setw(FW) <<"   =" << std::right<<median()<<std::endl;
           os << std::setw(FW+3) <<std::left<< "  slope"<<std::setw(FW) <<"   =" << std::right<<slope()<<std::endl;
            os << std::setw(FW+3) <<std::left<< "  intercept"<<std::setw(FW) <<"   =" << std::right<<intercept()<<std::endl;
   
        }
        friend std::ostream& operator<<(std::ostream& os, const DataTable& datatable) {
            datatable.display(os);
            return os;
        }
    };
}
#endif /* DataTable_hpp */
