// CommandPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

#define DELETE_PTR(p) {if(p!=nullptr){delete (p); (p)=nullptr;}}

namespace TYPES
{
	enum COMMANDTYPE
	{
		EXPRESS, // 取快递
		WASH, // 洗碗
		COOK // 做饭
	};
}

// 丈夫是接收者-TOBY
class Husband
{
public:
	void setCommand(TYPES::COMMANDTYPE commandType) // 丈夫形同“虚”设，还要看媳妇脸色
	{
		switch (commandType)
		{
		case TYPES::EXPRESS:
			cout << "Toby去取快递。。。" << endl;
			break;
		case TYPES::WASH:
			cout << "Toby去洗碗。。。" << endl;
			break;
		case TYPES::COOK:
			cout << "Toby去做饭。。。" << endl;
			break;
		default:
			cout << "任性一回，不想做。" << endl;
			break;
		}
	}
};

// 命令抽象类
class Command
{
public:
	virtual void executeCommand() = 0;

private:

};

// 命令具体类-取快递
class ExpressCommand : public Command
{
public:
	ExpressCommand(Husband *pHusband)
	{
		m_pHusband = pHusband;
	}

	virtual void executeCommand()
	{
		m_pHusband->setCommand(TYPES::COMMANDTYPE::EXPRESS);
	}

private:
	Husband *m_pHusband;
};

// 命令具体类-洗碗
class WashCommand : public Command
{
public:
	WashCommand(Husband *pHusband)
	{
		m_pHusband = pHusband;
	}

	virtual void executeCommand()
	{
		m_pHusband->setCommand(TYPES::COMMANDTYPE::WASH);
	}

private:
	Husband *m_pHusband;
};

// 命令具体类-做饭
class CookCommand : public Command
{
public:
	CookCommand(Husband *pHusband)
	{
		m_pHusband = pHusband;
	}

	virtual void executeCommand()
	{
		m_pHusband->setCommand(TYPES::COMMANDTYPE::COOK);
	}

private:
	Husband *m_pHusband;
};

// 媳妇是命令发送者
class Wife
{
public:
	void setCommand(Command *pCommand)
	{
		m_pCommand = pCommand;
		if (pCommand != nullptr)
		{
			m_pCommand->executeCommand();
		}
		return;
	}

private:
	Command *m_pCommand;
};


int main()
{
	cout << "----------命令行模式----------" << endl;
	
	Husband *pHusband = new Husband;

	ExpressCommand *pExpressCommand = new ExpressCommand(pHusband);
	WashCommand *pWashCommand = new WashCommand(pHusband);
	CookCommand *pCookCommand = new CookCommand(pHusband);

	Wife *pWife = new Wife;
	pWife->setCommand(pExpressCommand);
	pWife->setCommand(pWashCommand);
	pWife->setCommand(pCookCommand);

	DELETE_PTR(pWife);
	DELETE_PTR(pExpressCommand);
	DELETE_PTR(pWashCommand);
	DELETE_PTR(pCookCommand);
	DELETE_PTR(pHusband);
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
