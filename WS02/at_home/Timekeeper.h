//
//  Timekeeper.h
//  ws02
//
//  Created by Liu Wenxuan on 2019-01-22.
//  Copyright © 2019 Liu Wenxuan. All rights reserved.
//

#ifndef SICT_TIMEKEEPER_H
#define SICT_TIMEKEEPER_H
#include <iostream>
#include <chrono>


namespace sict {
    const int MAX = 10;
	class Timekeeper {
		int num;
        std::chrono::steady_clock::time_point tStart;
        std::chrono::steady_clock::time_point tEnd;
		struct {
			char* message;
			const char* unit;
			 std::chrono::steady_clock::duration tDuration;
		} record[MAX];
	public:
		Timekeeper();
		~Timekeeper();
		void start();
		void stop();
		void recordEvent(const char* desc);
        std::ostream& report(std::ostream& os);
	};
}
#endif /* Timekeeper_h */

