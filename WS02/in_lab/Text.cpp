//
//  Text.cpp
//  ws02
//
//  Created by Liu Wenxuan on 2019-01-22.
//  Copyright © 2019 Liu Wenxuan. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <string>
#include "Text.h"
namespace sict {
	Text::Text() {
		str = nullptr;
		recNum = 0;
	}
	Text::Text(char* t) {
		std::ifstream f(t);
		if (f.is_open()) {
			std::string p;
			while (getline(f, p)) {
				recNum++;
			}
			str = new std::string[recNum];
			for (size_t i = 0; i < recNum; i++) {
				getline(f, str[i]);
			}
			f.close();
		}
		else {
			*this = Text();
		}
	}
	Text::~Text() {
		delete[] str;
		str = nullptr;
	}
	Text::Text(Text& t) {
		*this = t;
	}
	Text& Text::operator=(const Text& t) {
		if (this != &t) {
			recNum = t.recNum;
			delete[] str;
			str = new std::string[recNum];
			for (size_t i = 0; i < recNum; i++) {
				str[i] = t.str[i];
			}
		}
		return *this;
	}
	size_t Text::size() const {
		return recNum;
	}
}


