//Workshop 6
//Name:          Wenxuan Liu
//Student ID:    160678173


#include <iostream>
#include <fstream>
#include <iomanip>
#include <iterator>
#include "Sale.h"
#include "iProduct.h"
extern int FW;
namespace sict {
	
	Sale::Sale() :proList {nullptr} {}
	Sale::Sale(const char* file) {
		std::ifstream f(file);
		if (!f.is_open())
			throw "fail to open the file!";
		else
			  while (!f.eof()) {
				  proList.push_back(readRecord(f));}
	}


	void Sale::display(std::ostream& os)const {
        double total=0.0;
        
        os << std::setw(FW) <<std::right;
        os << "Product No" << std::setw(FW) << std::right << "Cost" << std::left << " Taxable" << std::endl;
        for_each(proList.begin(),proList.end(),[&](iProduct* p){
            if (p == nullptr) return;
            p->display(os);
            total += p->price();});
        std::cout << std::fixed << std::setprecision(2);
        os << std::setw(FW) <<std::right;
        os << "Total";
        os << std::setw(FW) <<std::right;
        os << total << std::endl;
    }
}
