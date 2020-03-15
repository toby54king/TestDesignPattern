// MementoPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <list>

#define DELETE_PTR(p) {if(p!=nullptr){delete (p); (p)=nullptr;}}

using namespace std;

// 备忘录模式-备份类
class MementoInfo
{
public:
	MementoInfo(string messageStr)
	{
		m_messageStr = messageStr;
	}

	string getMessage()
	{
		return m_messageStr;
	}

private:
	string m_messageStr;
};

// 备忘录模式-原生者类
class OriginInfo
{
public:
	void sendMessage(string messageStr)
	{
		m_messageStr = messageStr;
		cout << "发送信息：" << messageStr << endl;
	}
	
	// 保存原生者的数据到备份中
	MementoInfo *saveInfo()
	{
		cout << "备份数据：" << m_messageStr << endl;
		return new MementoInfo(m_messageStr);
	}

	// 恢复备份数据
	void restoreInfo(MementoInfo *pMementoInfo)
	{
		if (pMementoInfo != nullptr)
		{
			m_messageStr = pMementoInfo->getMessage();
			cout << "恢复数据：" << m_messageStr << endl;
		}
	}
private:
	string m_messageStr;
};



// 备忘录模式-管理类
class CaretakerInfo
{
public:
	CaretakerInfo()
	{
		m_mementoList.clear();
	}

	~CaretakerInfo()
	{
		for (auto iter : m_mementoList)
		{
			DELETE_PTR(iter);
		}
		m_mementoList.clear();
	}

	// 返回备份数据
	MementoInfo *getMementoInfo()
	{
		return m_mementoList.back();
	}

	// 添加备份数据
	void addMementoInfo(MementoInfo *pMementoInfo)
	{
		if (pMementoInfo != nullptr)
		{
			m_mementoList.push_back(pMementoInfo);
		}
	}

private:
	list<MementoInfo*> m_mementoList;// 存储备份数据列表
};


int main()
{
	cout << "-------------------------备忘录模式--------------------------" << endl;
	CaretakerInfo *pCaretakerInfo = new CaretakerInfo();
	OriginInfo *pOriginInfo = new OriginInfo();

	pOriginInfo->sendMessage("你好啊！我是一个：爱人生，爱微笑，爱分享的程序猿！欢迎关注哦！");

	pCaretakerInfo->addMementoInfo(pOriginInfo->saveInfo());

	pOriginInfo->restoreInfo(pCaretakerInfo->getMementoInfo());

	DELETE_PTR(pCaretakerInfo);
	DELETE_PTR(pOriginInfo);

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
