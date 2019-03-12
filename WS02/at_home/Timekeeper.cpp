//
//  Timekeeper.cpp
//  ws02
//
//  Created by Liu Wenxuan on 2019-01-22.
//  Copyright © 2019 Liu Wenxuan. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Timekeeper.h"



namespace sict {

	Timekeeper::Timekeeper() {
		num = 0;
		for (int i = 0; i < MAX; i++) {
			record[i].message = nullptr;
			record[i].unit = nullptr;
		}
	}
	Timekeeper::~Timekeeper() {
		for (int i = 0; i < MAX; i++) {
			delete[] record[i].message;
		}
	}
	void Timekeeper::start() {
        tStart = std::chrono::steady_clock::now();
	}
	void Timekeeper::stop() {
		tEnd = std::chrono::steady_clock::now();
	}
	void Timekeeper::recordEvent(const char* desc){
		if (desc!=nullptr) {
			record[num].message = new char[strlen(desc) + 1];
			std::strcpy(record[num].message, desc);
			record[num].tDuration = (tEnd - tStart);
			record[num].unit = "milliseconds";
            num++;
		}
	}
    std::ostream& Timekeeper::report(std::ostream& os) {
		os <<std::endl;
		os << "Execution Times:" << std::endl;
		for (int i = 0; i < num; i++) {
			os << record[i].message << " " << std::chrono::duration_cast<std::chrono::milliseconds>(record[i].tDuration).count() << " "
            << record[i].unit << std::endl;
		}
		return os;
	}
}


