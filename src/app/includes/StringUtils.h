#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>

class StringUtils {
public:
	// trim from start (in place)
	static void ltrim(std::string &s);

	// trim from end (in place)
	static void rtrim(std::string &s);

	// trim from both ends (in place)
	static void trim(std::string &s);
};

#endif
