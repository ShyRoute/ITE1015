#include <iostream>
#include <string>

typedef struct {
	std::string name;
	int age;
} Person;

int main(void){
	int n;
	std::cin >> n;
	Person *arr = new Person[n];
	for(int i=0; i<n; i++){
		std::cin >> arr[i].name >> arr[i].age;
	}
	for(int i=0; i<n; i++){
		std::cout << "Name: " << arr[i].name << ", Age: " << arr[i].age << std::endl;
	}
	delete[] arr;
}
