// FacadePattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

#define DELETE_PTR(p) {if(p!=nullptr){delete (p); (p)=nullptr;}}

using namespace std;

// 鸿蒙操作系统
class HarmonyOS
{
public:
	void printOS()
	{
		cout << "Hello,I'm HarmonyOS!" << endl;
	}
};

// windows操作系统
class WindowsOS
{
public:
	void printOS()
	{
		cout << "Hello,I'm WindowsOS!" << endl;
	}
};

// 苹果操作系统
class AppleIOS
{
public:
	void printOS()
	{
		cout << "Hello,I'm AppleIOS!" << endl;
	}
};

// 外观类
class Facade
{
public:
	Facade()
	{
		m_pHarmonyOS = new HarmonyOS;
		m_pWindowsOS = new WindowsOS;
		m_pAppleIOS = new AppleIOS;
	}

	~Facade()
	{
		DELETE_PTR(m_pHarmonyOS);
		DELETE_PTR(m_pWindowsOS);
		DELETE_PTR(m_pAppleIOS);
	}

	void printOS()
	{
		m_pHarmonyOS->printOS();
		m_pWindowsOS->printOS();
		m_pAppleIOS->printOS();
	}

private:
	HarmonyOS *m_pHarmonyOS;
	WindowsOS *m_pWindowsOS;
	AppleIOS *m_pAppleIOS;
};


int main()
{
	cout << "------------外观模式-------------" << endl;

	cout << "========通过外观类调用子系统=======" << endl;
	Facade *pFacade = new Facade;
	pFacade->printOS();
	DELETE_PTR(pFacade);

	cout << "========在客户端中直接调用子系统=======" << endl;
	HarmonyOS *pHarmonyOS = new HarmonyOS;
	WindowsOS *pWindowsOS = new WindowsOS;
	AppleIOS *pAppleIOS = new AppleIOS;

	pHarmonyOS->printOS();
	pWindowsOS->printOS();
	pAppleIOS->printOS();

	DELETE_PTR(pHarmonyOS);
	DELETE_PTR(pWindowsOS);
	DELETE_PTR(pAppleIOS);

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
