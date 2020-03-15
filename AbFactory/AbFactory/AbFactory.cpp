// AbFactory.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

// 具体水果-北京香蕉
class BeiJingBanana : public Fruit
{
public:
	BeiJingBanana() {};
	~BeiJingBanana() {};
	void printName()
	{
		cout << "My name is BeiJingBanana." << endl;
	}
};

// 具体水-北京苹果
class BeiJingApple : public Fruit
{
public:
	BeiJingApple() {};
	~BeiJingApple() {};
	void printName()
	{
		cout << "My name is BeiJingApple." << endl;
	}
};

// 具体水果-南京香蕉
class NanJingBanana : public Fruit
{
public:
	NanJingBanana() {};
	~NanJingBanana() {};
	void printName()
	{
		cout << "My name is NanJingBanana." << endl;
	}
};

// 具体水-南京苹果
class NanJingApple : public Fruit
{
public:
	NanJingApple() {};
	~NanJingApple() {};
	void printName()
	{
		cout << "My name is NanJingApple." << endl;
	}
};

// 抽象工厂类
class Factory
{
public:
	Factory() {};
	~Factory() {};


	virtual Fruit *CreatBananaFruit()
	{
		Fruit *pFruit = nullptr;
		pFruit = new Fruit();
		return pFruit;
	}

	virtual Fruit *CreatAppleFruit()
	{
		Fruit *pFruit = nullptr;
		pFruit = new Fruit();
		return pFruit;
	}
};

// 北京工厂类
class BeiJingFactory : public Factory
{
public:
	BeiJingFactory() {};
	~BeiJingFactory() {};


	virtual Fruit *CreatBananaFruit()
	{
		Fruit *pFruit = nullptr;
		pFruit = new BeiJingBanana();
		return pFruit;
	}

	virtual Fruit *CreatAppleFruit()
	{
		Fruit *pFruit = nullptr;
		pFruit = new BeiJingApple();
		return pFruit;
	}
};

// 南京工厂类
class NanJingFactory : public Factory
{
public:
	NanJingFactory() {};
	~NanJingFactory() {};


	virtual Fruit *CreatBananaFruit()
	{
		Fruit *pFruit = nullptr;
		pFruit = new NanJingBanana();
		return pFruit;
	}

	virtual Fruit *CreatAppleFruit()
	{
		Fruit *pFruit = nullptr;
		pFruit = new NanJingApple();
		return pFruit;
	}
};

#define DELETE_PTR(p) {if(p!=nullptr){delete (p); (p)=nullptr;}}
int main()
{
	cout << "------------AbstractFactory------------" << endl;
	Factory *pFactory = nullptr;
	Fruit *pFruit = nullptr;

	// 北京水果
	cout << "-------北京水果--------" << endl;
	pFactory = new BeiJingFactory();
	pFruit = pFactory->CreatBananaFruit();
	pFruit->printName();
	pFruit = pFactory->CreatAppleFruit();
	pFruit->printName();

	DELETE_PTR(pFruit);
	DELETE_PTR(pFactory);

	// 南京水果
	cout << "-------南京水果--------" << endl;
	pFactory = new NanJingFactory();
	pFruit = pFactory->CreatBananaFruit();
	pFruit->printName();
	pFruit = pFactory->CreatAppleFruit();
	pFruit->printName();

	DELETE_PTR(pFruit);
	DELETE_PTR(pFactory);

	std::cout << "Hello World!\n";

	getchar();
}
