// StatePattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

#define DELETE_PTR(p) {if(p!=nullptr){delete (p); (p)=nullptr;}}

using namespace std;

// 根据时间点不同模仿一个人吃早饭、午饭、晚饭的状态，其他时间状态都设置在工作
class EatMeal;
//class MorningTimeState;
//class NoonTimeState;
//class NightTimeState;

// 抽象状态类（State）
class TimeState
{
public:
	virtual void changeTimeState(int timeState) = 0;
	virtual void toEatMeal(EatMeal *pEatMeal) = 0;
};

// 用户对象（上下文环境）类（Context）-去吃饭
class EatMeal
{
public:
	EatMeal()
	{
		m_curTimeState = nullptr;
	}

	~EatMeal()
	{
		DELETE_PTR(m_curTimeState);
	}

	void changeTimeState(int timeState)
	{
		m_timeState = timeState;
	}

	int getCurTime()
	{
		return m_timeState;
	}

	void setTimeState(TimeState *pCurTimeState)
	{
		m_curTimeState = pCurTimeState;
	}

	TimeState *getTimeState()
	{
		return m_curTimeState;
	}

	void toEatMeal()
	{
		m_curTimeState->toEatMeal(this);
	}

private:
	int m_timeState;
	TimeState *m_curTimeState;
};

// 具体状态类（ConcreteState）-吃早饭
class MorningTimeState : public TimeState
{
public:
	void changeTimeState(int timeState)
	{
		m_timeState = timeState;
	}

	virtual void toEatMeal(EatMeal *pEatMeal);
private:
	int m_timeState;
};

// 具体状态类（ConcreteState）-吃午饭
class NoonTimeState : public TimeState
{
public:
	void changeTimeState(int timeState)
	{
		m_timeState = timeState;
	}

	 virtual void toEatMeal(EatMeal *pEatMeal);
	
private:
	int m_timeState;
};

// 具体状态类（ConcreteState）- 吃晚饭
class NightTimeState : public TimeState
{
public:
	void changeTimeState(int timeState)
	{
		m_timeState = timeState;
	}

	virtual void toEatMeal(EatMeal *pEatMeal);
private:
	int m_timeState;
};

/*因为MorningTimeState、NoonTimeState、NightTimeState三个类中互相调用了类中的方法，
即使前置声明这三个类也不行，类的声明和实现必须分离才行,不分离的话会提示“使用了未定义的类型错误”*/

void MorningTimeState::toEatMeal(EatMeal *pEatMeal)
{
	if (pEatMeal->getCurTime() >= 7 && pEatMeal->getCurTime() <= 8) // 早饭
	{
		cout << "ISMILELI------------>洗刷完了，我要去吃早饭啦!" << endl;
	}
	else if(pEatMeal->getCurTime() >= 12 && pEatMeal->getCurTime() <= 13) // 下一个吃饭节点午饭
	{
		MorningTimeState *pMorningTimeState = dynamic_cast<MorningTimeState*>(pEatMeal->getTimeState());
		DELETE_PTR(pMorningTimeState);
		TimeState *pNoonTimeState = dynamic_cast<TimeState*>(new NoonTimeState);
		pEatMeal->setTimeState(pNoonTimeState);
		pEatMeal->getTimeState()->toEatMeal(pEatMeal);
	}
	else // 其他时间都在工作
	{
		cout << "ISMILELI------------>我是工作狂，我不爱睡觉，除了吃饭就是工作!" << endl;
	}
}

void NoonTimeState::toEatMeal(EatMeal *pEatMeal)
{
	if (pEatMeal->getCurTime() >= 12 && pEatMeal->getCurTime() <= 13) // 午饭
	{
		cout << "ISMILELI------------>中午到了，我要去吃午饭啦！" << endl;
	}
	else if(pEatMeal->getCurTime() >= 18 && pEatMeal->getCurTime() <= 20)// 下一个吃饭节点晚饭
	{
		NoonTimeState *pNoonTimeState = dynamic_cast<NoonTimeState*>(pEatMeal->getTimeState());
		DELETE_PTR(pNoonTimeState);
		TimeState *pNightTimeState = dynamic_cast<TimeState*>(new NightTimeState);
		pEatMeal->setTimeState(pNightTimeState);
		pEatMeal->getTimeState()->toEatMeal(pEatMeal);
	}
	else // 其他时间都在工作
	{
		cout << "ISMILELI------------>我是工作狂，我不爱睡觉，除了吃饭就是工作!" << endl;
	}
}

void NightTimeState::toEatMeal(EatMeal *pEatMeal)
{
	if (pEatMeal->getCurTime() >= 18 && pEatMeal->getCurTime() <= 20) // 晚饭
	{
		cout << "ISMILELI------------>下班时间到了，我要去吃晚饭啦！" << endl;
	}
	else if(pEatMeal->getCurTime() >= 7 && pEatMeal->getCurTime() <= 8)// 下一个吃饭节点早饭
	{
		NightTimeState *pNightTimeState = dynamic_cast<NightTimeState*>(pEatMeal->getTimeState());
		DELETE_PTR(pNightTimeState);
		TimeState *pMorningTimeState = dynamic_cast<TimeState*>(new MorningTimeState);
		pEatMeal->setTimeState(pMorningTimeState);
		pEatMeal->getTimeState()->toEatMeal(pEatMeal);
	}
	else // 其他时间都在工作
	{
		cout << "ISMILELI------------>我是工作狂，我不爱睡觉，除了吃饭就是工作!" << endl;
	}
}

int main()
{
	cout << "----------------------状态模式----------------------" << endl;
	EatMeal *pEatMeal = new EatMeal;
	TimeState *pCurTimeState = dynamic_cast<TimeState*>(new MorningTimeState);
	pEatMeal->setTimeState(pCurTimeState);
	
	pEatMeal->changeTimeState(7);
	pEatMeal->toEatMeal();

	pEatMeal->changeTimeState(13);
	pEatMeal->toEatMeal();

	
	pEatMeal->changeTimeState(18);
	pEatMeal->toEatMeal();

	pEatMeal->changeTimeState(21);
	pEatMeal->toEatMeal();

	// 指针pCurTimeState内存释放在pEatMeal析构函数中
	DELETE_PTR(pEatMeal);

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
