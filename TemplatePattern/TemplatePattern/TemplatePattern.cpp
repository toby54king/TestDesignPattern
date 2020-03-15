// TemplatePattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

// 模板父类-制造手机
class ProductPhone
{
public:
	virtual void makeScreen() = 0;
	virtual void makeChip() = 0;
	virtual void makeBattery() = 0;
	
	void makePhone()
	{
		makeScreen();
		makeChip();
		makeBattery();
	}
};

// 模板子类-手机厂商们使用的各种零件开启“私人订制”模式
class ProductHuaWeiPhone : public ProductPhone
{
public:
	void makeScreen()
	{
		cout << "make a screen for HuaWei phone." << endl;
	}

	void makeChip()
	{
		cout << "make a chip for HuaWei phone." << endl;
	}

	void makeBattery()
	{
		cout << "make a Batttery for HuaWei phone." << endl;
	}
};

class ProductXiaoMiPhone : public ProductPhone
{
public:
	void makeScreen()
	{
		cout << "make a screen for XiaoMi phone." << endl;
	}

	void makeChip()
	{
		cout << "make a chip for XiaoMi phone." << endl;
	}

	void makeBattery()
	{
		cout << "make a Batttery for XiaoMi phone." << endl;
	}
};

class ProductOPPOPhone : public ProductPhone
{
public:
	void makeScreen()
	{
		cout << "make a screen for OPPO phone." << endl;
	}

	void makeChip()
	{
		cout << "make a chip for OPPO phone." << endl;
	}

	void makeBattery()
	{
		cout << "make a Batttery for OPPO phone." << endl;
	}
};

#define DELETE_PTR(p) {if(p!=nullptr){delete (p); (p)=nullptr;}}

int main()
{
	cout << "-----------------模板模式--------------------" << endl;
	cout << "---------制造华为手机-----------" << endl;
	ProductPhone *pHuaWeiPhone = new ProductHuaWeiPhone;
	pHuaWeiPhone->makePhone();

	cout << "---------制造小米手机-----------" << endl;
	ProductPhone *pXiaoMiPhone = new ProductXiaoMiPhone;
	pXiaoMiPhone->makePhone();

	cout << "---------制造OPPO手机-----------" << endl;
	ProductPhone *pOPPOPhone = new ProductOPPOPhone;
	pOPPOPhone->makePhone();

	DELETE_PTR(pHuaWeiPhone);
	DELETE_PTR(pXiaoMiPhone);
	DELETE_PTR(pOPPOPhone);

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
