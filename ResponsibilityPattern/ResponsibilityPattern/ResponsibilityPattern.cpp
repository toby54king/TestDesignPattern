// ResponsibilityPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

#define DELETE_PTR(p) {if(p!=nullptr){delete (p); (p)=nullptr;}}

// 员工请求类
class EmployeeRequest
{
public:

	void setRequestContent(string contentStr)
	{
		if (contentStr.empty())
		{
			return;
		}
		m_contentStr = contentStr;
	}

	string getRequestContent()
	{
		return m_contentStr;
	}

	void setRequestCount(int count)
	{
		if (count <= 0)
		{
			return;
		}
		m_count = count;
	}

	int getRequestCount()
	{
		return m_count;
	}

private:
	string m_contentStr;
	int m_count;
};

// 处理基类-管理者抽象类
class Manager
{
public:
	Manager *setNextManager(Manager *pManager)
	{
		if (pManager == nullptr)
		{
			return nullptr;
		}
		m_pManager = pManager;
		return pManager;
	}

	virtual void handleWork(EmployeeRequest *pEmployeeRequest) = 0;

protected:
	Manager *m_pManager;
};

// 处理具体类-管理者具体实现类
// 部门经理
class DepartManager : public Manager
{
public:
	virtual void handleWork(EmployeeRequest *pEmployeeRequest)
	{
		if ((pEmployeeRequest->getRequestContent()== "加薪") && pEmployeeRequest->getRequestCount() <=1000)
		{
			cout << "部门经理批准加薪：" << pEmployeeRequest->getRequestCount() << endl;
		}
		else
		{
			cout << "申请的数量太大，部门经理无权批准，传递给总监批准！" << endl;
			if (m_pManager != nullptr)
			{
				m_pManager->handleWork(pEmployeeRequest);
			}
		}
	}
};

// 总监
class MonitorManager : public Manager
{
public:
	virtual void handleWork(EmployeeRequest *pEmployeeRequest)
	{
		if ((pEmployeeRequest->getRequestContent() == "加薪") && pEmployeeRequest->getRequestCount() <= 5000)
		{
			cout << "总监批准加薪：" << pEmployeeRequest->getRequestCount() << endl;
		}
		else
		{
			cout << "申请的数量太大，总监无权批准，传递给总经理批准！" << endl;
			if (m_pManager != nullptr)
			{
				m_pManager->handleWork(pEmployeeRequest);
			}
		}
	}
};

// 总经理
class GeneralManager : public Manager
{
public:
	virtual void handleWork(EmployeeRequest *pEmployeeRequest)
	{
		if ((pEmployeeRequest->getRequestContent() == "加薪") && pEmployeeRequest->getRequestCount() <= 10000)
		{
			cout << "总经理批准加薪：" << pEmployeeRequest->getRequestCount() << endl;
		}
		else
		{
			cout << "申请的数量太大，总经理无权批准，传递给董事长批准！" << endl;
			if (m_pManager != nullptr)
			{
				m_pManager->handleWork(pEmployeeRequest);
			}
		}
	}
};



int main()
{
	cout << "------------------职责链模式-------------------" << endl;
	EmployeeRequest *pEmployeeRequest = new EmployeeRequest;
	pEmployeeRequest->setRequestContent("加薪");
	pEmployeeRequest->setRequestCount(3000);

	GeneralManager *pGeneralManager = new GeneralManager;
	MonitorManager *pMonitorManager = new MonitorManager;
	DepartManager *pDepartManager = new DepartManager;
	pDepartManager->setNextManager(pMonitorManager);
	pMonitorManager->setNextManager(pGeneralManager);
	
	pDepartManager->handleWork(pEmployeeRequest);

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
