// IteratorPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

#define DELETE_PTR(p) {if(p!=nullptr){delete (p); (p)=nullptr;}}

using namespace std;

class MyIterator
{
public:
	virtual void first() = 0;
	virtual void next() = 0;
	virtual int currentItem() = 0;
	virtual bool isEnd() = 0;
};

class Aggregate
{
public:
	virtual void addItem(int num) = 0;
	virtual int getItem(int index) = 0;
	virtual MyIterator *createIterator() = 0;
	virtual int getSize() = 0;
};

class ConcreteIterator : public MyIterator
{
public:
	ConcreteIterator(Aggregate *pAggregate)
	{
		m_pAggregate = pAggregate;
		m_index = 0;
	}

	~ConcreteIterator()
	{
		DELETE_PTR(m_pAggregate);
		m_index = 0;
	}

	void first()
	{
		m_index = 0;
	}

	void next()
	{
		if (m_index < m_pAggregate->getSize())
		{
			m_index++;
		}
	}

	int currentItem()
	{
		return m_pAggregate->getItem(m_index);
	}

	bool isEnd()
	{
		if (m_index == m_pAggregate->getSize())
		{
			return true;
		}
		return false;
	}

private:
	int m_index;
	Aggregate *m_pAggregate;
};

class ConcreteAggregate : public Aggregate
{
public:
	ConcreteAggregate()
	{
		m_elemVec.clear();
	}

	~ConcreteAggregate()
	{
		if (!m_elemVec.empty())
		{
			vector<int> tmpVec;
			m_elemVec.swap(tmpVec);// 释放内存
			m_elemVec.clear();
		}
	}

	void addItem(int num)
	{
		cout << "迭代器中添加元素： " << num << endl;
		m_elemVec.push_back(num);
	}

	int getItem(int index)
	{
		if (index < m_elemVec.size())
		{
			return m_elemVec.at(index);
		}
		return -1;
	}

	MyIterator *createIterator()
	{
		return new ConcreteIterator(this);
	}

	int getSize()
	{
		return m_elemVec.size();
	}


private:
	vector<int> m_elemVec;;
};



int main()
{
	cout << "--------------------迭代器模式--------------------" << endl;
	Aggregate *pAggregate = dynamic_cast<Aggregate*>(new ConcreteAggregate);
	pAggregate->addItem(1);
	pAggregate->addItem(2);
	pAggregate->addItem(3);
	pAggregate->addItem(4);
	pAggregate->addItem(5);
	pAggregate->addItem(6);
	pAggregate->addItem(7);
	pAggregate->addItem(8);
	pAggregate->addItem(9);
	pAggregate->addItem(10);

	MyIterator *myIter = pAggregate->createIterator();
	
	cout << "----------------打印出所有的元素------------------" << endl;
	while (!myIter->isEnd())
	{
		cout << myIter->currentItem() << "  ";
		myIter->next();
	}
	cout << endl;

	DELETE_PTR(pAggregate);
	DELETE_PTR(myIter);

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
