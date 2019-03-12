//
//  Text.h
//  ws02
//
//  Created by Liu Wenxuan on 2019-01-22.
//  Copyright © 2019 Liu Wenxuan. All rights reserved.
//
#ifndef SICT_TEXT_H
#define SICT_TEXT_H
namespace sict {
	class Text {
		std::string* str;
		size_t recNum;
	public:
		Text();
		Text(char* t);
		~Text();
		Text(Text& t);
		Text& operator=(const Text& t);
		size_t size() const;
	};
}
#endif /* Text_h */

