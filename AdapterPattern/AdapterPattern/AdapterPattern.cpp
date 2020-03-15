// AdapterPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

// 目标接口类
class Voltage11V
{
public:
	void use11vPower()
	{
		cout << "use 11V power" << endl;
	}

private:

};

// 适配者类
class Voltage220V
{
public:
	void use220vPower()
	{
		cout << "use 220V power" << endl;
	}

private:

};

// 适配器类
class AdapterVol : public Voltage11V
{
public:
	AdapterVol(Voltage220V *pVol220V)
	{
		m_pVol220v = pVol220V;
	}

	void use11vPower()
	{
		cout << "适配器将220V电压转换成需要的11V电压" << endl;
		m_pVol220v->use220vPower();
	}
	

private:
	Voltage220V *m_pVol220v;
};

#define DELETE_PTR(p) {if(p!=nullptr){delete (p); (p)=nullptr;}}
int main()
{
	cout << "--------适配器模式----------" << endl;

	Voltage220V *pVol220V = new Voltage220V;
	AdapterVol *pAdapterVol = new AdapterVol(pVol220V);
	pAdapterVol->use11vPower();

	DELETE_PTR(pVol220V);
	DELETE_PTR(pAdapterVol);
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
