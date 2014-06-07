#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>

int main(int argc, char* argv) {
	// make string
	std::string str;

	// read contents of file and put them in string
	std::ifstream istr("cfg.txt");
	if (istr) {
		std::streambuf * pbuf = istr.rdbuf();
		while (pbuf->sgetc() != EOF)
		{
			str.push_back(pbuf->sbumpc());
		}
		istr.close();
	}

	// get positions of data in string
	size_t aa_start		= str.find_first_of('=') + 1;
	size_t aa_end		= str.find_first_of(';');

	size_t fps_start	= str.find_first_of('=', aa_end) + 1;
	size_t fps_end		= str.find_first_of(';', aa_end);

	size_t res_start	= str.find_first_of('=', fps_end) + 1;
	size_t res_end		= str.find_first_of(';', fps_end);
	
	// compose smaller strings of the values of attributes
	std::string aa_val;
	for (size_t i = aa_start; i != aa_end; i++) {
		aa_val.push_back(str.at(i));
	}

	std::string fps_val;
	for (size_t i = fps_start; i != fps_end; i++) {
		fps_val.push_back(str.at(i));
	}

	std::string res_val;
	for (size_t i = res_start; i != res_end; i++) {
		res_val.push_back(str.at(i));
	}

	// end results
	int antialiasing_level = atoi(aa_val.c_str());
	int fps_max = atoi(fps_val.c_str());
	int resolution = atoi(res_val.c_str());

	// simulating use of results
	std::cout << antialiasing_level;
	std::cout << fps_max;
	std::cout << resolution;

	// my way to keep the window open ??? haha
	int x;
	std::cin >> x;

	return 0;
}