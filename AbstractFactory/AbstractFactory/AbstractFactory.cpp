// AbstractFactory.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

// 水果基类
class Fruit
{
public:
	Fruit() {};
	~Fruit() {};
	virtual void printName()
	{
		cout << "My name is Fruit." << endl;
	}
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

// 抽象工厂类
class Factory
{
public:
	Factory() {};
	~Factory() {};

	
	virtual Fruit *CreatFruit()
	{
		Fruit *pFruit = nullptr;
		pFruit = new Fruit();
		return pFruit;
	}
};

// 香蕉工厂类
class BananaFactory : public Factory
{
public:
	BananaFactory() {};
	~BananaFactory() {};


	virtual Banana *CreatFruit()
	{
		Banana *pFruit = nullptr;
		pFruit = new Banana();
		return pFruit;
	}
};

// 苹果工厂类
class AppleFactory : public Factory
{
public:
	AppleFactory() {};
	~AppleFactory() {};


	virtual Apple *CreatFruit()
	{
		Apple *pFruit = nullptr;
		pFruit = new Apple();
		return pFruit;
	}
};


#define DELETE_PTR(p) {if(p!=nullptr){delete (p); (p)=nullptr;}}
int main()
{
	Factory *pFactory = nullptr;
	Fruit *pFruit = nullptr;

	// 香蕉
	pFactory = new BananaFactory();
	pFruit = pFactory->CreatFruit();
	pFruit->printName();

	DELETE_PTR(pFruit);
	DELETE_PTR(pFactory);

	// 苹果
	pFactory = new AppleFactory();
	pFruit = pFactory->CreatFruit();
	pFruit->printName();

	DELETE_PTR(pFruit);
	DELETE_PTR(pFactory);

	std::cout << "Hello World!\n";

	getchar();
}