// VisitorPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <list>

#define DELETE_PTR(p) {if(p!=nullptr){delete (p); (p)=nullptr;}}
using namespace std;

// 前置声明
class StaffElement;

// 访问者抽象类-客户
class CustomerVisit
{
public:
	virtual void customVisit(StaffElement *pStaffElement) = 0;
};

// 抽象节点类-营业厅员工
class StaffElement
{
public:
	virtual void accepCustomer(CustomerVisit *CustomerVisit) = 0;
	virtual string getName() = 0;
};

// 具体节点类-营业厅员工A
class StaffAElem : public StaffElement
{
public:
	StaffAElem(string nameStr)
	{
		m_nameStr = nameStr;
	}

	virtual void accepCustomer(CustomerVisit *pCustomerVisit)
	{
		pCustomerVisit->customVisit(this);
	}

	virtual string getName()
	{
		return m_nameStr;
	}

private:
	string m_nameStr;
};

// 具体节点类-营业厅员工B
class StaffBElem : public StaffElement
{
public:
	StaffBElem(string nameStr)
	{
		m_nameStr = nameStr;
	}

	virtual void accepCustomer(CustomerVisit *pCustomerVisit)
	{
		pCustomerVisit->customVisit(this);
	}

	virtual string getName()
	{
		return m_nameStr;
	}

private:
	string m_nameStr;
};

// 具体访问者类-客户A
class CustomerAVisit : public CustomerVisit
{
public:
	virtual void customVisit(StaffElement *pStaffElement)
	{
		cout << "客户A在营业厅里通过->" << pStaffElement->getName() << "办理业务" << endl;
	}
};

// 具体访问者类-客户B
class CustomerBVisit : public CustomerVisit
{
public:
	virtual void customVisit(StaffElement *pStaffElement)
	{
		cout << "客户B在营业厅里通过->" << pStaffElement->getName() << "办理业务" << endl;
	}
};

// 结构对象类-员工管理类
class StaffStructure : public StaffElement
{
public:
	StaffStructure()
	{
		m_staffElemList.clear();
	}

	~StaffStructure()
	{
		for (auto iter : m_staffElemList)
		{
			DELETE_PTR(iter);
		}
		m_staffElemList.clear();
	}

	virtual void accepCustomer(CustomerVisit *pCustomerVisit)
	{
		for (auto iter : m_staffElemList)
		{
			iter->accepCustomer(pCustomerVisit);
		}
	}

	string getName()
	{
		return m_nameStr;
	}

	void addStaffElem(StaffElement *pStaffElement)
	{
		m_staffElemList.push_back(pStaffElement);
	}

	void removeStaffElem(StaffElement *pStaffElement)
	{
		m_staffElemList.remove(pStaffElement);
	}

private:
	list<StaffElement*> m_staffElemList;
	string m_nameStr;
};


int main()
{
	cout << "----------------------访问者模式-------------------------" << endl;
	StaffAElem *pStaffAElem = new StaffAElem("营业厅员工A");
	StaffBElem *pStaffBElem = new StaffBElem("营业厅员工B");

	StaffStructure *pStaffStructure = new StaffStructure;
	pStaffStructure->addStaffElem(pStaffAElem);
	pStaffStructure->addStaffElem(pStaffBElem);

	CustomerAVisit *pCustomerAVisit = new CustomerAVisit;
	CustomerBVisit *pCustomerBVisit = new CustomerBVisit;

	cout << "------------客户A办理业务--------------" << endl;
	pStaffStructure->accepCustomer(pCustomerAVisit);
	cout << "------------客户B办理业务--------------" << endl;
	pStaffStructure->accepCustomer(pCustomerBVisit);

	//DELETE_PTR(pStaffAElem); //已经在StaffStructure析构函数析构
	//DELETE_PTR(pStaffBElem);
	DELETE_PTR(pCustomerAVisit);
	DELETE_PTR(pCustomerBVisit);
	DELETE_PTR(pStaffStructure);

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
