// SimpleFactory.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

// 水果基类
class Fruit
{
public:
	Fruit() {};
	~Fruit() {};
	virtual void printName() = 0;
};

// 具体水果-香蕉
class Banana : public Fruit
{
public:
	Banana() {};
	~Banana() {};
	void printName() 
	{
		cout << "My name is Banana." << endl;
	}
};

// 具体水-苹果
class Apple : public Fruit
{
public:
	Apple() {};
	~Apple() {};
	void printName()
	{
		cout << "My name is Apple." << endl;
	}
};

// 工厂类
class Factory
{
public:
	Factory() {};
	~Factory() {};
	
	enum FRUIT_TYPE
	{
		BANANA_TYPE,
		APPLE_TYPE
	};

	Fruit *CreatFruit(FRUIT_TYPE type)
	{
		Fruit *pFruit = nullptr;
		switch (type)
		{
		case FRUIT_TYPE::BANANA_TYPE:
			pFruit = new Banana();
			break;
		case FRUIT_TYPE::APPLE_TYPE:
			pFruit = new Apple();
			break;
		default:
			break;
		}
		return pFruit;
	}
};

#define DELETE_PTR(p) {if(p!=nullptr){delete (p); (p)=nullptr;}}
int main()
{
	Factory *pFactory = nullptr;
	Fruit *pFruit = nullptr;

	pFactory = new Factory();

	// 香蕉
	pFruit = pFactory->CreatFruit(Factory::BANANA_TYPE);
	pFruit->printName();

	DELETE_PTR(pFruit);

	// 苹果
	pFruit = pFactory->CreatFruit(Factory::APPLE_TYPE);
	pFruit->printName();

	DELETE_PTR(pFruit);
	DELETE_PTR(pFactory);

    std::cout << "Hello World!\n";
	
	getchar();
}
