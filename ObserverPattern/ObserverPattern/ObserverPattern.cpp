// ObserverPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>

#define DELETE_PTR(p) {if(p!=nullptr){delete (p); (p)=nullptr;}}

using namespace std;

class Staff;

// 被观察者抽象类
class Leader
{
public:
	virtual void addObserver(Staff *pStaff) {}
	virtual void notifyAll() {}
	virtual void setLeaderStatus(int status) {}
	virtual int getLeaderStatus() { return 0; }
};

// 观察者抽象类-员工
class Staff
{
public:
	virtual void updateStatus() {}
};

// 被观察者具体实现类-部门经理
class DepartManager : public Leader
{
public:
	void addObserver(Staff *pStaff)
	{
		m_staffVector.push_back(pStaff);
	}

	void notifyAll()
	{
		if (m_leaderStatus == 1)
		{
			cout << "------------部门经理回来了--------------" << endl;
		}
		else
		{
			cout << "------------部门经理出去了--------------" << endl;
		}
		
		for (auto iter : m_staffVector)
		{
			iter->updateStatus();
		}
	}

	// 设置领导的状态，1-在，0-不在
	void setLeaderStatus(int status)
	{
		m_leaderStatus = status;
	}

	int getLeaderStatus()
	{
		return m_leaderStatus;
	}

private:
	vector<Staff*> m_staffVector;
	int m_leaderStatus;
};

// 被观察者具体实现类-技术总监
class CTOManager : public Leader
{
public:
	void addObserver(Staff *pStaff)
	{
		m_staffVector.push_back(pStaff);
	}

	void notifyAll()
	{
		if (m_leaderStatus == 1)
		{
			cout << "------------技术总监回来了--------------" << endl;
		}
		else
		{
			cout << "------------技术总监出去了--------------" << endl;
		}
		for (auto iter : m_staffVector)
		{
			Staff *pStaff = iter;
			pStaff->updateStatus();
		}
	}

	// 设置领导的状态，1-在，0-不在
	void setLeaderStatus(int status)
	{
		m_leaderStatus = status;
	}

	int getLeaderStatus()
	{
		return m_leaderStatus;
	}

private:
	vector<Staff*> m_staffVector;
	int m_leaderStatus;
};



// 观察者具体类-玩游戏的员工
class PlayGameStaff : public Staff
{
public:
	PlayGameStaff(Leader *pLeader, string name)
	{
		m_pLeader = pLeader;
		m_nameStr = name;
	}

	void updateStatus()
	{
		if (m_pLeader->getLeaderStatus() == 1) // 领导来了
		{
			cout << m_nameStr << "停止玩游戏，开始工作。" << endl;
		}
		else
		{
			cout << m_nameStr << "停止工作，开始玩游戏。" << endl;
		}
	}

private:
	Leader *m_pLeader;
	string m_nameStr;
};

// 观察者具体类-看电影员工
class WatchMovieStaff : public Staff
{
public:
	WatchMovieStaff(Leader *pLeader, string name)
	{
		m_pLeader = pLeader;
		m_nameStr = name;
	}

	void updateStatus()
	{
		if (m_pLeader->getLeaderStatus() == 1) // 领导来了
		{
			cout << m_nameStr << "停止看电影，开始工作。" << endl;
		}
		else
		{
			cout << m_nameStr << "停止工作，开始看电影。" << endl;
		}
	}

private:
	Leader *m_pLeader;
	string m_nameStr;
};



int main()
{
	cout << "---------------------观察者模式------------------" << endl;
	Leader *pDepartManager = dynamic_cast<Leader*>(new DepartManager);
	pDepartManager->setLeaderStatus(1);

	Staff *pPlayGameStaff = dynamic_cast<Staff*>(new PlayGameStaff(pDepartManager,"ISmileLI"));
	Staff *pWatchMovieStaff = dynamic_cast<Staff*>(new WatchMovieStaff(pDepartManager, "Toby"));

	pDepartManager->addObserver(pPlayGameStaff);
	pDepartManager->addObserver(pWatchMovieStaff);

	pDepartManager->notifyAll();
	pDepartManager->setLeaderStatus(0);
	pDepartManager->notifyAll();

	DELETE_PTR(pPlayGameStaff);
	DELETE_PTR(pWatchMovieStaff);

	cout << "--------------部门经理走了，技术总监又过来了--------------" << endl;
	Leader *pCTOManager = dynamic_cast<Leader*>(new CTOManager);
	pCTOManager->setLeaderStatus(1);
	

	pPlayGameStaff = dynamic_cast<Staff*>(new PlayGameStaff(pCTOManager, "ISmileLI"));
	pWatchMovieStaff = dynamic_cast<Staff*>(new WatchMovieStaff(pCTOManager, "Toby"));

	pCTOManager->addObserver(pPlayGameStaff);
	pCTOManager->addObserver(pWatchMovieStaff);

	pCTOManager->notifyAll();

	DELETE_PTR(pPlayGameStaff);
	DELETE_PTR(pWatchMovieStaff);
	DELETE_PTR(pDepartManager);
	DELETE_PTR(pCTOManager);

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
