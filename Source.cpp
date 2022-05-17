#include <iostream>

int main()
{
	int k{0}, arr[8][8];
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			arr[i][j] = k;
			k++;
			std::cout << arr[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			std::cout << (float) arr[i][j] / 8 << "\t";
		}
		std::cout << std::endl;
	}
	srand(time(NULL));
	int value = (rand() % 2) == 0 ? 7 : 9;
	std::cout << (10 - ((rand() % 2) == 0 ? 7 : 9)) << std::endl;
}