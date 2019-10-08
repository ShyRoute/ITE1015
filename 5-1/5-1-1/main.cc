#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv){
	string s = argv[1];
	int n = atoi(argv[2]);
	for(int i=0; i<n; i++){
		cout << s << endl;
	}
	return 0;
}
