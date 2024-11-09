#include<iostream>
#include<queue>
#include<conio.h>


struct Object
{
	static int s_iData;
	int m_iData;
	Object() : m_iData(++s_iData) {}
	~Object() { std::cout << "Release Object(" << m_iData << ")" << std::endl; }
	void Print() { std::cout << "Object(" << m_iData << ")" << std::endl; }
};
int Object::s_iData = 0;
std::queue<std::shared_ptr<Object>> ObjectQueue;
bool DeleteFlag = false;

void Push(Object* object)
{
	if (DeleteFlag)
		delete object;
	else
	{
		ObjectQueue.push(std::shared_ptr<Object>(object, Push));
		std::cout << "Pool In Object(" << object->m_iData << ")" << std::endl;
	}
}

void main()
{
	for (int i = 0; i < 5; i++)
	{
		ObjectQueue.push(std::shared_ptr<Object>(new Object, Push));
	}

	int oldclock = clock();
	while (true)
	{
		if (_kbhit())
		{
			char ch = _getch();
			if (ch == 27)
			{
				DeleteFlag = true;
				break;
			}
		}
		if (clock() - oldclock >= 1000)
		{
			std::shared_ptr<Object> object = ObjectQueue.front();
			ObjectQueue.pop();
			object->Print();
			object = nullptr;
			oldclock = clock();
		}
	}
}