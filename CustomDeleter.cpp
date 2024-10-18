#include<iostream>
#include<vector>

void main()
{
	std::vector<std::unique_ptr<int>> UniqueVector;
	UniqueVector.push_back(std::make_unique<int>(1));
	UniqueVector.push_back(std::make_unique<int>(2));
	UniqueVector.push_back(std::make_unique<int>(3));
	std::for_each(UniqueVector.begin(), UniqueVector.end(), [](std::unique_ptr<int>* ptr) 
		{
			std::cout << *ptr << std::endl;
		})
}