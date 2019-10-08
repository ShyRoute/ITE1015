#include <iostream>

int bubble_sort(int arr[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

int main(void){
	int n;
	std::cin >> n;
	if(n <= 0){
		return 0;
	}
	int *num = new int[n];
	for(int i=0; i<n; i++){
		std::cin >> num[i];
	}
	bubble_sort(num, n);
	for(int i=0; i<n; i++){
		std::cout << num[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}
