
#ifndef PROJECT_05
#define PROJECT_05

#include<string>
using std::string;
#include<vector>
using std::vector;
#include<random>
using std::mt19937_64;
using std::uniform_int_distribution;
#include <cctype>
#include<iostream>
using std::cout;  using std::endl; using std::cin;
#include<sstream>
using std::istringstream;
#include<fstream>
using std::ifstream; using std::ofstream;
#include<fstream>
using std::ifstream;

string filter_string(string);
void read_key(ifstream &, vector<long> &);
string encode(string , vector<long>&,
	      mt19937_64 &,
	      uniform_int_distribution<long> &);
string decode(string , vector<long>&);
#endif
