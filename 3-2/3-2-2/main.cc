#include <iostream>
#include <string>

int main(void){
	std::string s1, s2, temp;
	std::cin >> s1 >> s2;
	temp = s1 + s2;
	std::cout << temp << std::endl << s1[0] << std::endl << s2[s2.length() - 1] << std::endl;
	return 0;
}
