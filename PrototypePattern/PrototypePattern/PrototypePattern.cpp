// PrototypePattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;
class Monkey
{
public:
	Monkey() {}
	virtual ~Monkey() {}
	virtual Monkey* clone() = 0;
	virtual void printName() = 0;
private:

};

class SunWuKong : public Monkey
{
public:
	SunWuKong(string nameStr)
	{
		m_nameStr = nameStr;
	}
	~SunWuKong() {}

	SunWuKong(const SunWuKong &other)
	{
		m_nameStr = other.m_nameStr;
	}

	Monkey* clone()
	{
		return new SunWuKong(*this);
	}
	void printName()
	{
		cout << m_nameStr << endl;
	}
private:
	string m_nameStr;
};

#define DELETE_PTR(p) {if(p!=nullptr){delete (p); (p)=nullptr;}}
int main()
{
	Monkey *pMonkey = new SunWuKong("QiTianDaSheng SunWuKong!");

	Monkey *pMonkey1 = pMonkey->clone();
	Monkey *pMonkey2 = pMonkey1->clone();

	pMonkey->printName();
	pMonkey1->printName();
	pMonkey2->printName();

	DELETE_PTR(pMonkey);
	DELETE_PTR(pMonkey1);
	DELETE_PTR(pMonkey2);
	
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
