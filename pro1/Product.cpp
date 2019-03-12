//Workshop 6
//Name:          Wenxuan Liu
//Student ID:    160678173


#include <iomanip>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "Product.h"

extern int FW;
namespace sict {
    Product::Product() :proNum(0),proPrice(0){}
	Product::Product(const int num, const double price) {
		if (num > 0 && price >= 0) { proNum= num; proPrice = price;}
		else *this = Product();
	}
    
    double Product::price() const {  return proPrice; }
    double TaxableProduct::price() const {
        return taxPrice==H?Product::price()*(1+HST):Product::price()*(1+PST);
    }
    void Product::display(std::ostream& os) const {
        os.setf(std::ios::fixed);os.precision(2);
        os<<std::setw(FW)<<std::right<<proNum;
        os<<std::setw(FW)<<proPrice<<std::endl;
        os.unsetf(std::ios::fixed);
        
    }
    void TaxableProduct::display(std::ostream& os) const {
        os.setf(std::ios::fixed);os.precision(2);
        os<<std::setw(FW)<<std::right<<proNum;
        os<<std::setw(FW)<<this->price();
        os.unsetf(std::ios::fixed);
        os << " " << (taxType == H ? "HST" : "PST")<<std::endl;
        
    }
    std::ostream& operator<<(std::ostream& os, const iProduct& p){
        p.display(os);
        return os;
    }
    iProduct* readRecord(std::ifstream& file){
        iProduct *p=nullptr;
        if(file.is_open()){
            int num;
            double price;
            char tax;
            std::string line;
            getline(file,line);
            if(!line.empty()){
                std::istringstream isn (line);
                isn>>num>>price>>tax;
                if (tax == 'H' || tax == 'P')
                    p= new TaxableProduct(num,price,tax);
                else
                    p= new Product(num,price);
            }
        }
            else throw "Loading data Failed";
        return p;
    }
    TaxableProduct:: TaxableProduct(int pNum,double pCost, char pType):Product(pNum,pCost){
        if (pType=='H') taxType=H;
        else taxType=P;
        
    };
    
    }


