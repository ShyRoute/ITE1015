#include <iostream>
#include <string>

int add(int a, int b){
	return a + b;
}

std::string add(std::string a, std::string b){
	std::string temp;
	temp = a + '-' + b;
	return temp;
}

int main(void){
	int a, b;
	std::string s1, s2;
	std::cin >> a >> b >> s1 >> s2;
	std::cout << add(a, b) << std::endl << add(s1, s2) << std::endl;
	return 0;
}
