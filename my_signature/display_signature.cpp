#include <iostream>
#include <fstream>

#define BHGREEN "\033[7;32m"
#define BHYELLOW "\033[1;33m"
#define BHWHITE "\033[1;37m"
#define BHBLUE "\033[1;34m"
#define BHCYAN "\033[7;36m"
#define BHPINK "\033[1;35m"
#define UNDERLINE "\033[4;1;37m"
#define RESET "\033[0m"

void display_signature() {
	bool toggle = false;
	std::ifstream file("ascii_signature");
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			for (char& c : line) {
				if (c == '$') {
					std::cout << BHCYAN << " " << RESET;
				} else if (c == '6') {
					toggle = true;
					std::cout << " " << UNDERLINE;
				} else if (c == '7') {
					toggle = true;
					std::cout << BHYELLOW << " ";
				} else if (c == '8') {
					toggle = true;
					std::cout << BHBLUE << " ";
				} else if (c == '9') {
					toggle = true;
					std::cout << BHPINK << " ";
				} else if (c == ':') {
					toggle = false;
					std::cout << ":" << RESET << BHWHITE;
				} else {
					if (!toggle) {
						std::cout << BHWHITE << c << RESET;
					} else {
						std::cout << c;
					}
				}
			}
			std::cout << std::endl;
		}
		file.close();
	}
}

int main() {
	display_signature();
	return 0;
}

