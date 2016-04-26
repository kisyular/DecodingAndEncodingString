/*
2016-02-18
functions-05.cpp
*/
#include <cctype>
#include<iostream>
using std::cout;  using std::endl; using std::cin;
#include<random>
using std::mt19937_64; using std::uniform_int_distribution;
#include<sstream>
using std::istringstream;
#include<string>
using std::getline; using std::string; using std::stringstream;
using std::to_string;
#include<fstream>
using std::ifstream; using std::ofstream;
#include<fstream>
using std::ifstream;
#include<vector>
using std::vector;
#include "functions-05.h"

string filter_string(string s){
string filtered; //initiate a variable and size_t 
size_t i = 0;
size_t leng = s.size(); //get the size of the string s
while(i < leng){
    if (isalpha(s[i]) ){ //see if the character is alpha and convert it to lowercase
         filtered+=tolower(s[i]) ;
	}
	i++;
}
return filtered; //return the filtered string
}
void read_key ( ifstream &in_file, vector<long> &shift_key){
	string line; //initialize the variable ss, and line, ss with type string stream
	stringstream ss;
	getline(in_file, line);
			int number;
			ss <<line; //write line to ss (string stream) and read from it
			while (ss >>number){
					shift_key.push_back(number);  //write the number to a vector
}
}
string encode (string to_encode, vector<long>& shifts, 
mt19937_64 &reng, uniform_int_distribution<long>& dist){

//initialize variable encoded, letter_index	
string encoded;
int letter_index;
int i = 0;
string filtered_str=filter_string(to_encode); //fpass string through filter function
for (auto ch : filtered_str){
	int random_num=dist(reng);
	letter_index=(ch -'a');
	
	int lenOfShiftKey = shifts.size();
	//encoded = 26 * random_num + letter_index + shift[index]
	int num = 26 * random_num + letter_index + shifts[i%lenOfShiftKey];
	encoded = encoded + to_string(num) + " ";
	i++;
	}
return encoded;
}

string decode(string to_decode, vector<long>& shifts){
//(final_encoded –shift_key[index]) % 26) 
int i=0;
string character;
int letter;
long lenOfShiftKey = shifts.size();
long letter_index;
	stringstream ss(to_decode); //write string to the string stream
	int item;
    while (ss>>item){ //get the numbers and save them in item
		//(final_encoded =(shift_key[index]) % 26) 
		letter_index = (item -shifts[i%lenOfShiftKey]);
		letter = letter_index % 26;
		character += (letter + 'a') ;
		i++;
	}
	return ( character);
}


