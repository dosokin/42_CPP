#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <ctime>
#include <cstdlib>

void parseDataFile(std::map<unsigned int, double>& data);
void treatInputFile(const std::map<unsigned int, double>& data, const std::string& filename);

#endif