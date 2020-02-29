//Автор - Калюжний Денис, К-13
#include "Functions.h"
using namespace std;

std::string trim(const std::string& str)
{
	auto pos1 = str.find_first_not_of(" \0\n");
	if (pos1 == string::npos)
		return str;
	auto pos2 = str.find_last_not_of(" \0\n");
	return str.substr(pos1, pos2 - pos1 + 1);
}