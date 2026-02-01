#include <iostream>
#include <fstream>

std::string SearchAndReplace(std::string content, std::string s1, std::string s2)
{
	if (content.empty())
		return "\n";
	int pos = 0;
	std::string res;
	while (1)
	{
		size_t found = content.find(s1, pos);
		if (found == std::string::npos)
		{
			res += content.substr(pos);
			break;
		}
		res += content.substr(pos, found - pos);
        res += s2;
        pos = found + s1.length();
	}
	return res;
}

int main(int ac, char **av)
{
    if (ac != 4)
        return (std::cout<<"error", 1);
		std::string out = av[1];
		std::string s1 = av[2];
		std::string s2 = av[3];
		if (s1.empty())
			return (std::cout<<"empty s1\n", 1);
		out += ".replace";

		std::ifstream inFile(av[1]);
		if (!inFile.is_open())
    	    return (std::cout<<"error opening file\n", 1);
		
		std::ofstream outFile(out.c_str());
		if (!outFile.is_open())
			return (std::cout<<"error opening file\n", 1);
		std::string content;
    	getline(inFile, content, '\0');
		std::string s;
		s = SearchAndReplace(content, s1, s2);
		outFile << s;
	return 0;
}
