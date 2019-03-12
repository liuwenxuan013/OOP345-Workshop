//Workshop 6
//Name:          Wenxuan Liu
//Student ID:    160678173


#ifndef SICT_SALE_H
#define SICT_SALE_H
#include <vector>
#include "iProduct.h"

namespace sict {

	class Sale {
		std::vector<iProduct*> proList;
	public:
		Sale();
        Sale(const char* file);
		void display(std::ostream& os)const;
        ~Sale() = default;
	};
}

#endif // !SICT_SALE_H
