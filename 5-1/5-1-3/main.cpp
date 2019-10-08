#include <iostream>
#include "minmax.h"

using namespace std;

int main(int argc, char **argv){
	int *arr = new int[argc-1];
	int min, max;
	for(int i=0; i<argc-1; i++){
		arr[i] = atoi(argv[i+1]);
	}
	getMinMax(arr, argc-1, min, max);
	cout << "Min: " << min << endl << "Max: " << max << endl;
	delete[] arr;
	return 0;
}
