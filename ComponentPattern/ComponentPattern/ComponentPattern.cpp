// ComponentPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

#define DELETE_PTR(p) {if(p!=nullptr){delete (p); (p)=nullptr;}}

using namespace std;

// 抽象构件类
class ComponentCompany
{
public:
	ComponentCompany(string strName)
	{
		m_strName = strName;
	}
	virtual ~ComponentCompany(){}
	virtual void add(ComponentCompany *pComponentCompany) = 0;
	virtual void remove(ComponentCompany *pComponentCompanyp) = 0;
	virtual ComponentCompany *getChild(int index) = 0;
	virtual void showChild() = 0;

protected:
	string m_strName;
};

// 容器构件类
class CompositeCompany : public ComponentCompany
{
public:
	CompositeCompany(string strName) : ComponentCompany(strName){}

	virtual ~CompositeCompany() 
	{
		while (!m_comElemsVector.empty())
		{
			vector<ComponentCompany *>::iterator it = m_comElemsVector.begin();
			DELETE_PTR(*it);
			m_comElemsVector.erase(it);
		}
	}

	void add(ComponentCompany *pComponentCompany)
	{
		m_comElemsVector.push_back(pComponentCompany);
	}

	void remove(ComponentCompany *pComponentCompany)
	{
		for (auto *iter : m_comElemsVector)
		{
			if (iter == pComponentCompany)
			{
				DELETE_PTR(pComponentCompany);
				break;
			}
		}
	}

	ComponentCompany *getChild(int index)
	{
		if (index >= m_comElemsVector.size())
		{
			return nullptr;
		}
		return m_comElemsVector.at(index);
	}

	void showChild()
	{
		cout << m_strName << endl;
		for (auto *iter : m_comElemsVector)
		{
			iter->showChild();
		}
	}

private:
	vector<ComponentCompany *> m_comElemsVector;
};

// 叶子构件类
class LeafDepart : public ComponentCompany
{
public:
	LeafDepart(string strName) : ComponentCompany(strName) {}

	virtual ~LeafDepart(){}

	void add(ComponentCompany *pComponentCompany)
	{
		cout << "LeafDepart Node Can't add a leaf!" << endl;
	}

	void remove(ComponentCompany *pComponentCompany)
	{
		cout << "Can't remove a leaf from LeafDepart Node!" << endl;
	}

	ComponentCompany *getChild(int index)
	{
		cout << "Can't getChild a leaf from LeafDepart Node!" << endl;;
		return nullptr;
		
	}

	void showChild()
	{
		cout << m_strName << endl;;
	}
};

int main()
{
	cout << "-------------组合模式--------------" << endl;
	// 总公司
	ComponentCompany *pHeadCompany = new CompositeCompany("-总公司");
	// 子公司
	ComponentCompany *pBranchCompany = new CompositeCompany("-------子公司");
	pBranchCompany->add(new LeafDepart("-------------子公司研发部"));
	pBranchCompany->add(new LeafDepart("-------------子公司产品部"));
	pBranchCompany->add(new LeafDepart("-------------子公司测试部"));
	pBranchCompany->add(new LeafDepart("-------------子公司网络部"));

	pHeadCompany->add(pBranchCompany);
	pHeadCompany->add(new LeafDepart("-------总公司研发部"));
	pHeadCompany->add(new LeafDepart("-------总公司产品部"));
	pHeadCompany->add(new LeafDepart("-------总公司测试部"));
	pHeadCompany->add(new LeafDepart("-------总公司网络部"));

	pHeadCompany->showChild();

	//DELETE_PTR(pBranchCompany);调用下面的删除时，会自动在析构函数中删除该指针
	DELETE_PTR(pHeadCompany);

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
