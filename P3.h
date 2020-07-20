//
// PREGUNTA #3
//

#ifndef P3_H
#define P3_H

#include <string>
#include <vector>
#include <limits>

using namespace std;

template <typename ...Args>
string remove_characters(const string& text, Args ...args)
{
	string substring;
	(substring.append(args), ...);
	
	vector<size_t> hash(numeric_limits<char>::max());
	for (const auto& c : substring)
		++hash[c];

	string result;
	for (const auto& c : text)
		if (hash[c] == 0)
			result += c;
	return result;
}

void p3();




#endif //P3_H
