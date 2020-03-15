// BuilderPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

class Phone
{
public:
	void setChip(string chip)
	{
		m_chipStr = chip;
	}

	void setScreen(string screen)
	{
		m_screenStr = screen;
	}

	void setShell(string shell)
	{
		m_shellStr = shell;
	}

	string getChip()
	{
		return m_chipStr;
	}

	string getScreen()
	{
		return m_screenStr;
	}

	string getShell()
	{
		return m_shellStr;
	}

private:
	string m_chipStr;
	string m_screenStr;
	string m_shellStr;
};

class Builder
{
public:
	virtual void makeChip() = 0; // 手机芯片
	virtual void makeScreen() = 0; // 手机屏幕
	virtual void makeShell() = 0; // 手机壳
	virtual Phone* getPhone() = 0; // 手机
};

class HuaWeiPhoneBuild : public Builder
{
public:
	HuaWeiPhoneBuild()
	{
		m_pPhone = new Phone;
	}

	virtual void makeChip()
	{
		m_pPhone->setChip("HuaWei Chip");
	}

	virtual void makeScreen()
	{
		m_pPhone->setScreen("HuaWei Screen");
	}

	virtual void makeShell()
	{
		m_pPhone->setShell("HuaWei Shell");
	}

	virtual Phone *getPhone()
	{
		return m_pPhone;
	}

private:
	Phone *m_pPhone;
};

class XiaoMiPhoneBuild : public Builder
{
public:
	XiaoMiPhoneBuild()
	{
		m_pPhone = new Phone;
	}

	virtual void makeChip()
	{
		m_pPhone->setChip("XiaoMi Chip");
	}

	virtual void makeScreen()
	{
		m_pPhone->setScreen("XiaoMi Screen");
	}

	virtual void makeShell()
	{
		m_pPhone->setShell("XiaoMi Shell");
	}

	virtual Phone *getPhone()
	{
		return m_pPhone;
	}

private:
	Phone *m_pPhone;
};

class Director
{
public:
	void creatPhone(Builder *pBuilder)
	{
		pBuilder->makeChip();
		pBuilder->makeScreen();
		pBuilder->makeShell();
	}
};

#define DELETE_PTR(p) {if(p!=nullptr){delete (p); (p)=nullptr;}}
int main()
{
	Director *pDirector = new Director;
	// 指挥者指挥建造产品
	HuaWeiPhoneBuild *pHuaWeiBuilder = new HuaWeiPhoneBuild;
	pDirector->creatPhone(pHuaWeiBuilder);
	Phone *pHuaWeiPhone = pHuaWeiBuilder->getPhone();

	XiaoMiPhoneBuild *pXiaoMiBuilder = new XiaoMiPhoneBuild;
	pDirector->creatPhone(pXiaoMiBuilder);
	Phone *pXiaoMiPhone = pXiaoMiBuilder->getPhone();

	// 输出测试
	cout << "------HuaWei--------" << endl;
	cout << "Chip: " << pHuaWeiPhone->getChip() << endl;
	cout << "Screen: " << pHuaWeiPhone->getScreen() << endl;
	cout << "Shell: " << pHuaWeiPhone->getShell() << endl;
	cout << "------XiaoMi--------" << endl;
	cout << "Chip: " << pXiaoMiPhone->getChip() << endl;
	cout << "Screen: " << pXiaoMiPhone->getScreen() << endl;
	cout << "Shell: " << pXiaoMiPhone->getShell() << endl;
   
	DELETE_PTR(pDirector);
	DELETE_PTR(pHuaWeiBuilder);
	DELETE_PTR(pXiaoMiBuilder);
	DELETE_PTR(pHuaWeiPhone);
	DELETE_PTR(pXiaoMiPhone);

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
