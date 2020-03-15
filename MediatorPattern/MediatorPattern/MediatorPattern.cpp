// MediatorPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

#define DELETE_PTR(p) {if(p!=nullptr){delete (p); (p)=nullptr;}}


class User;
// 中介者抽象类-基站
class BaseStation
{
public:
	virtual void callPhone(User *pUser) = 0;
	virtual void setUserOne(User *pUserOne) = 0;
	virtual void setUserTwo(User *pUserTwo) = 0;
};

// 中介者具体实现类-通讯基站
class CommunicationStation : public BaseStation
{
public:
	void setUserOne(User *pUserOne)
	{
		m_pUserOne = pUserOne;
	}

	void setUserTwo(User *pUserTwo)
	{
		m_pUserTwo = pUserTwo;
	}

	void callPhone(User *pUser)
	{
		if (pUser == m_pUserOne)
		{
			cout << "UserOne call phone UserTwo." << endl; // 用户1给用户2打电话
		}
		else
		{
			cout << "UserTwo call phone UserOne." << endl; // 用户2给用户1打电话
		}
	}

private:
	User *m_pUserOne;
	User *m_pUserTwo;
};

// 关联（同事）类的抽象类-用户
class User
{
public:
	User(BaseStation* pBaseStation)
	{
		m_pBaseStation = pBaseStation;
	}
	virtual void callPhone() = 0;

protected:
	BaseStation *m_pBaseStation;
};

// 关联类的具体类-用户1
class UserOne : public User
{
public:
	UserOne(BaseStation* pComStation) : User(pComStation) {}

	void callPhone()
	{
		m_pBaseStation->callPhone(this);
	}
};

// 关联类的具体类-用户2
class UserTwo : public User
{
public:
	UserTwo(BaseStation* pComStation) : User(pComStation) {}

	void callPhone()
	{
		m_pBaseStation->callPhone(this);
	}
};

int main()
{
	cout << "--------------中介者模式---------------" << endl;

	BaseStation *pBaseStation = new CommunicationStation();
	User *pUserOne = new UserOne(pBaseStation);
	User *pUserTwo = new UserTwo(pBaseStation);
	
	pBaseStation->setUserOne(pUserOne);
	pBaseStation->setUserTwo(pUserTwo);
	pUserOne->callPhone();
	pUserTwo->callPhone();

	DELETE_PTR(pUserOne);
	DELETE_PTR(pUserTwo);
	DELETE_PTR(pBaseStation);

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
