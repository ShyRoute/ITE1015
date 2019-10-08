#include <iostream>

int check(int num, int n) {
	if(num < 0) return num + n;
	else if(num >= n) return num - n;
	else return num;
}

void magicSquare(int **num, int n){
	int x, y, temp = 0, count = 1;
	for(int i = 0; i < n; i++) {
		x = n / 2 + i;
		for(int j = 0; j < n; j++, x--) {
			y = temp - x;
			num[check(x, n)][check(y, n)] = count++;
		}
		temp += 2;
	}
}

int main(void) {
	int n;
	std::cin >> n;
	if((n % 2) == 0 || n < 3){
		return 0;
	}
	int **num = new int *[n];
	for(int i = 0; i < n; i++) num[i] = new int[n];
	magicSquare(num, n);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			std::cout << num[i][j] << " ";
		}
		std::cout << "\n";
	}
	for(int i = 0; i < n; i++) delete[] num[i];
	delete[] num;
	return 0;
}
