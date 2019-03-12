//Workshop 6
//Name:          Wenxuan Liu
//Student ID:    160678173


#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H
#include <iostream>
#include "iProduct.h"
namespace sict {

    class Product:public iProduct{
        
    public:
        int proNum;
        double proPrice;
        Product();
        Product(int, double );
        double price() const;
        void display(std::ostream& os) const;
        //~Product();
    };
    class TaxableProduct: public Product {
        const double HST = 0.13, PST = 0.08;
        double taxPrice;
        enum tax {H, P} taxType;
        
    public:
        TaxableProduct(int, double, char);
        double price() const;
        void display(std::ostream& os) const;
    };
    
}
#endif // !SICT_PRODUCT_H
