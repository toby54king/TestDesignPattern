// StrategyPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

#define DELETE_PTR(p) {if(p!=nullptr){delete (p); (p)=nullptr;}}

// 策略算法基类
class AlgorithmBase
{
public:
	virtual void algorithmName() = 0;
};

// 冒泡排序算法
class BubbleSort : public AlgorithmBase
{
public:
	virtual void algorithmName()
	{
		cout << "调用冒泡排序算法" << endl;
	}
};

// 选择排序算法
class SelectSort : public AlgorithmBase
{
public:
	virtual void algorithmName()
	{
		cout << "调用选择排序算法" << endl;
	}
};

// 插入排序算法
class InsertSort : public AlgorithmBase
{
public:
	virtual void algorithmName()
	{
		cout << "调用插入排序算法" << endl;
	}
};

// 策略模式的容器类
class ContextAlgorithm
{
public:
	ContextAlgorithm(AlgorithmBase *pAlgorithmBase)
	{
		if (pAlgorithmBase != nullptr)
		{
			m_pAlgorithmBase = pAlgorithmBase;
		}
	}

	~ContextAlgorithm()
	{
		DELETE_PTR(m_pAlgorithmBase);
	}

	void choiceAlgorithm()
	{
		cout << "=====客户端通过策略模式的容器类调用算法====" << endl;
		m_pAlgorithmBase->algorithmName();
	}

private:
	AlgorithmBase *m_pAlgorithmBase;
};



int main()
{
	cout << "--------------------策略模式-----------------------" << endl;
	cout << "--------直接调用各个算法类------" << endl;
	AlgorithmBase *pAlgorithmBase = nullptr;
	pAlgorithmBase = new BubbleSort;
	pAlgorithmBase->algorithmName();
	DELETE_PTR(pAlgorithmBase);

	pAlgorithmBase = new SelectSort;
	pAlgorithmBase->algorithmName();
	DELETE_PTR(pAlgorithmBase);

	pAlgorithmBase = new SelectSort;
	pAlgorithmBase->algorithmName();
	DELETE_PTR(pAlgorithmBase);

	//cout << "--------调用策略模式的容器类------" << endl;
	pAlgorithmBase = new BubbleSort;
	ContextAlgorithm *pContextAlgorithm = new ContextAlgorithm(pAlgorithmBase); //以调用冒泡排序为例
	pContextAlgorithm->choiceAlgorithm();
	//DELETE_PTR(pAlgorithmBase); // 不需要释放了，已经在ContextAlgorithm中析构释放
	DELETE_PTR(pContextAlgorithm);

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
