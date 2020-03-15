// SingletonPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

using namespace std;

#if 0
//个人常用构建单例方法
class Singleton
{
public:

	// 提供一个全局的访问入口
	static Singleton *GetInstance()
	{
		// 定义一个本类的静态变量
		static Singleton instance;
		return &instance;
	}

	void printSelf()
	{
		std::cout << "Hello!I'm Singleton Pattern\n";
	}

private:
	// 构造函数私有化
	Singleton() {};
};
#endif // 0


#include <mutex>

// 懒/饿汉式单例公用部分
class Singleton
{
public:

	// 提供一个全局的访问入口
	static Singleton *GetInstance();

	void printSelf()
	{
		std::cout << "Hello!I'm Singleton Pattern\n";
	}

	// 释放内存
	static void DestoryInstance() 
	{ 
		if (m_pSingleton != nullptr)
		{ 
			delete m_pSingleton; 
			m_pSingleton = nullptr;
		} 
	}

	class ClearRubbish
	{
		public: ~ClearRubbish()
		{ 
			// 释放所有的资源 
			if (m_pSingleton != nullptr)
			{ 
				cout << "destory all source..." << endl; 
				delete m_pSingleton; 
				m_pSingleton = nullptr;
			} 
		}
	static ClearRubbish CR; // 用于释放单例 
	};


private:
	// 构造函数私有化
	Singleton() {};
	// 定义一个本类的静态变量
	static Singleton *m_pSingleton;
	static mutex m_mutex;
};

// 懒汉式单例
Singleton *Singleton::m_pSingleton = nullptr;
Singleton *Singleton::GetInstance()
{
	if (m_pSingleton == nullptr)
	{
		// 为保证单例在多线程中安全加锁
		lock_guard<mutex> tmpLock(m_mutex);
		if (m_pSingleton == nullptr)
		{
			m_pSingleton = new Singleton;
		}
	}
	return m_pSingleton;
}

//饿汉式单例
Singleton *Singleton::m_pSingleton = new Singleton();
Singleton *Singleton::GetInstance()
{
	return m_pSingleton; 
}

Singleton::ClearRubbish Singleton::ClearRubbish::CR; // 释放垃圾

int main()
{
	Singleton::GetInstance()->printSelf();
	Singleton::GetInstance()->DestoryInstance();
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
