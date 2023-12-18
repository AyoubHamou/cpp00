#include <iostream>

int main (int argc, char *argv[]) {
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else{
		std::string str;
		for(int i = 1; i < argc; i++){
			str = argv[i];
			for(int j = 0; argv[i][j]; j++)
				str[j] = toupper(argv[i][j]);
			std::cout << str;
		}
	}
	std::cout << std::endl;
	return 0;
}
