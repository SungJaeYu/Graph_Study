#include <iostream>

int func1(int x, int y, int z);
int func2(int x, int y, int z);
int func3(int x, int y, int z);
int func4(int x, int y, int z);

int main(void){
	int x, y, z ;
	std::cin >> x;
	std::cin >> y;
	std::cin >> z;
	std::cout << func1(x, y, z) << std::endl;
	std::cout << func2(x, y, z) << std::endl;
	std::cout << func3(x, y, z) << std::endl;
	std::cout << func4(x, y, z) << std::endl;
}

int func1(int x, int y, int z)
	return (x + y) % z;

int func2(int x, int y, int z)
	return ((x%z) + (y%z))%z;

int func3(int x, int y, int z)
	return (x * y) % z;

int func4(int x, int y, int z)
	return ((x%z) * (y%z))%z;
