#include <iostream>
#include <fstream>
#include <string>
 
static std::string	replaceAll(std::string content, const std::string& s1,
								const std::string& s2)
{
	std::string	result;
	size_t		pos = 0;
	size_t		found;
 
	if (s1.empty())
		return (content);
	while ((found = content.find(s1, pos)) != std::string::npos)
	{
		result += content.substr(pos, found - pos);
		result += s2;
		pos = found + s1.length();
	}
	result += content.substr(pos);
	return (result);
}
 
int	main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
		return (1);
	}
 
	std::string		filename = argv[1];
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
 
	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be empty" << std::endl;
		return (1);
	}
 
	std::ifstream	inFile(filename.c_str());
	if (!inFile.is_open())
	{
		std::cerr << "Error: cannot open file: " << filename << std::endl;
		return (1);
	}
 
	std::string		content;
	std::string		line;
	bool			firstLine = true;
 
	while (std::getline(inFile, line))
	{
		if (!firstLine)
			content += "\n";
		content += line;
		firstLine = false;
	}
	if (inFile.eof() && !firstLine)
		content += "\n";
	inFile.close();
 
	std::string		replaced = replaceAll(content, s1, s2);
 
	std::string		outFilename = filename + ".replace";
	std::ofstream	outFile(outFilename.c_str());
	if (!outFile.is_open())
	{
		std::cerr << "Error: cannot create file: " << outFilename << std::endl;
		return (1);
	}
 
	outFile << replaced;
	outFile.close();
 
	std::cout << "Replaced all occurrences of \"" << s1 << "\" with \"" << s2
		<< "\" in " << outFilename << std::endl;
 
	return (0);
}