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
            L pLabel;
			V pValue;
	public:
        LVPair(): pLabel(), pValue(){}
        LVPair(const L& label, const V& value) {
            pLabel = label;
            pValue = value;
        }
		
        virtual void display(std::ostream& os) const {
            os << pLabel << " : " << pValue << std::endl;
        }
        const L& getLabel() const{
            return pLabel;
        }
        const V& getValue() const { return  pValue; }
    };
	
	template <typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const LVPair<L, V>& pair) {
		pair.display(os);
		return os;
	}

	template<typename L, typename V>
	class SummableLVPair : public LVPair<L, V>{
		static V dValue;
		static size_t width;
	public:
        SummableLVPair(){}
		SummableLVPair(const L& label, const V& v):LVPair<L, V>(label, v) {
			if (width < label.size())
                width = label.size();
		}
        
		const static V& getInitialValue() {
			return dValue;
		}
        
		V sum(const L& label, const V& sum) const {
			return ( label ==this->getLabel())? LVPair<L, V>::getValue() + sum : sum;
		}

		virtual void display(std::ostream& os) const {
			os.setf(std::ios::left);
			os.width(width);
			LVPair<L, V>::display(os);
			os.unsetf(std::ios::left);
		}
	};
	template<typename L, typename V>
		size_t SummableLVPair<L, V>::width = 0u;

	template<>
	int SummableLVPair<std::string, int>::dValue = 0;

	template<>
	std::string SummableLVPair<std::string, std::string>::dValue = "\0";
    
	template<>
	std::string SummableLVPair<std::string,std::string>::sum(const std::string& l, const std::string& s) const {
		return (l == this->getLabel()) ? (s + " " + LVPair<std::string, std::string>::getValue()):s;
	}
}
#endif // !SICT_LIST_H
