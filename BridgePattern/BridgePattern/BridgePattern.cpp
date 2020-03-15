// BridgePattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

// 海思麒麟系列芯片
class KirinChip
{
public:
	virtual void useKirinChip() = 0;
};

// 麒麟960芯片
class Kirin960 : public KirinChip
{
public:
	virtual void useKirinChip()
	{
		cout << "use Kirin960 Chip." << endl;
	}
};

// 麒麟970芯片
class Kirin970 : public KirinChip
{
public:
	virtual void useKirinChip()
	{
		cout << "use Kirin970 Chip." << endl;
	}
};

// 麒麟980芯片
class Kirin980 : public KirinChip
{
public:
	virtual void useKirinChip()
	{
		cout << "use Kirin980 Chip." << endl;
	}
};

// 华为手机
class HuaWeiPhone
{
public:
	HuaWeiPhone(KirinChip *pKirinChip)
	{
		m_pKirinChip = pKirinChip;
	}
	virtual void useKirinChip() = 0;

protected:
	KirinChip *m_pKirinChip;
};

// 华为P8
class HuaWeiP8 : public HuaWeiPhone
{
public:
	HuaWeiP8(KirinChip *pKirinChip) : HuaWeiPhone(pKirinChip)
	{

	}
	virtual void useKirinChip()
	{
		cout << "HuaWeiP8 ";
		m_pKirinChip->useKirinChip();
	}

};

// 华为P9
class HuaWeiP9 : public HuaWeiPhone
{
public:
	HuaWeiP9(KirinChip *pKirinChip) : HuaWeiPhone(pKirinChip)
	{

	}
	virtual void useKirinChip()
	{
		cout << "HuaWeiP9 ";
		m_pKirinChip->useKirinChip();
	}
};

// 华为P10
class HuaWeiP10 : public HuaWeiPhone
{
public:
	HuaWeiP10(KirinChip *pKirinChip) : HuaWeiPhone(pKirinChip)
	{

	}
	virtual void useKirinChip()
	{
		cout << "HuaWeiP10 ";
		m_pKirinChip->useKirinChip();
	}
};

#define DELETE_PTR(p) {if(p!=nullptr){delete (p); (p)=nullptr;}}
int main()
{
	cout << "------------桥接模式-----------" << endl;
	cout << "以下手机和芯片的组合随意的，并不能真实反映华为手机和芯片配置情况,真实信息请在google上BaiDu一下！" << endl;
	Kirin960 *pKirin960 = new Kirin960;
	HuaWeiP8 *pHuaWeiP8 = new HuaWeiP8(pKirin960);
	pHuaWeiP8->useKirinChip();

	Kirin970 *pKirin970 = new Kirin970;
	HuaWeiP9 *pHuaWeiP9 = new HuaWeiP9(pKirin970);
	pHuaWeiP9->useKirinChip();

	Kirin980 *pKirin980 = new Kirin980;
	HuaWeiP10 *pHuaWeiP10 = new HuaWeiP10(pKirin980);
	pHuaWeiP10->useKirinChip();

	DELETE_PTR(pKirin960);
	DELETE_PTR(pHuaWeiP8);
	DELETE_PTR(pKirin970);
	DELETE_PTR(pHuaWeiP9);
	DELETE_PTR(pKirin980);
	DELETE_PTR(pHuaWeiP10);

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
