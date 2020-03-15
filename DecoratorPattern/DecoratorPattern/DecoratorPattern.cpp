// DecoratorPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

// 抽象类
class AbstractDrink
{
public:
	virtual string drinkName() = 0;

private:

};

// 具体类
class MilkTea : public AbstractDrink
{
public:
	string drinkName()
	{
		return "MilkTea";
	}

private:

};

// 装饰者类
class TasteDecorator : public AbstractDrink
{
public:
	//TasteDecorator() {}
	TasteDecorator(AbstractDrink *pDrink)
	{
		m_pDrink = pDrink;
	}
	string drinkName()
	{
		return m_pDrink->drinkName();
	}
	AbstractDrink *m_pDrink;
};

// 具体装饰者类
// 麦香味
class WheatTaste : public TasteDecorator
{
public:
	WheatTaste(AbstractDrink *pDrink) : TasteDecorator(pDrink) {}
	string drinkName()
	{
		return m_pDrink->drinkName() + "WheatTaste";
	}
};
// 苹果味
class AppleTaste : public TasteDecorator
{
public:
	AppleTaste(AbstractDrink *pDrink) : TasteDecorator(pDrink) {}
	
	string drinkName()
	{
		return m_pDrink->drinkName() + "AppleTaste";
	}
};
// 糖味
class SugarTaste : public TasteDecorator
{
public:
	SugarTaste(AbstractDrink *pDrink) : TasteDecorator(pDrink) {}

	string drinkName()
	{
		return m_pDrink->drinkName() + "SugarTaste";
	}
};

#define DELETE_PTR(p) {if(p!=nullptr){delete (p); (p)=nullptr;}}
int main()
{
	cout << "------装饰者模式------" << endl;
	AbstractDrink *pAbDrink = new MilkTea;
	cout << pAbDrink->drinkName() << endl;

	TasteDecorator *pWheatTaste = new WheatTaste(pAbDrink);
	cout << pWheatTaste->drinkName() << endl;

	TasteDecorator *pAppleTaste = new AppleTaste(pAbDrink);
	cout << pAppleTaste->drinkName() << endl;

	TasteDecorator *pSugarTaste = new SugarTaste(pAbDrink);
	cout << pSugarTaste->drinkName() << endl;
	DELETE_PTR(pSugarTaste);
	DELETE_PTR(pAppleTaste);
	DELETE_PTR(pWheatTaste);
	DELETE_PTR(pAbDrink);
    std::cout << "Hello World!\n";
	getchar();
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
