#include <string>
#include <iostream>
#include <fstream>

#include "../logger.hpp"

bool isLogIn( std::string msg, Logger & logger )
{
	std::ifstream file;
	file.open( logger.getOutputFile() );
	std::string log;
	std::getline( file, log );
	if (log.find(msg) != std::string::npos)
	{
		return true;
	}
	return false;
}
