// InterpreterPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

#define DELETE_PTR(p) {if(p!=nullptr){delete (p); (p)=nullptr;}}

using namespace std;

// 抽象表达式类
class AbstarctExpression
{
public:
	virtual int interpreter() = 0;
};

// 非终结符表达式类
class SymbolExpression : public AbstarctExpression
{
public:
	SymbolExpression(string numStr)
	{
		m_numStr = numStr;
	}

	int interpreter()
	{
		if (m_numStr.empty())
		{
			return -1;
		}
		return atoi(m_numStr.c_str());
	}

private:
	string m_numStr;
};

// 终结符表达式类-加法运算
class PlusExpression : public AbstarctExpression
{
public:
	PlusExpression(int firstNum, int secondNum)
	{
		m_firstNum = firstNum;
		m_secondNum = secondNum;
	}

	int interpreter()
	{
		return (m_firstNum + m_secondNum);
	}

private:
	int m_firstNum;
	int m_secondNum;
};

// 终结符表达式类-减法运算
class MinusExpression : public AbstarctExpression
{
public:
	MinusExpression(int firstNum, int secondNum)
	{
		m_firstNum = firstNum;
		m_secondNum = secondNum;
	}

	int interpreter()
	{
		return (m_firstNum - m_secondNum);
	}

private:
	int m_firstNum;
	int m_secondNum;
};

// 终结符表达式类-乘法运算
class MultiExpression : public AbstarctExpression
{
public:
	MultiExpression(int firstNum, int secondNum)
	{
		m_firstNum = firstNum;
		m_secondNum = secondNum;
	}

	int interpreter()
	{
		return (m_firstNum * m_secondNum);
	}

private:
	int m_firstNum;
	int m_secondNum;
};

// 终结符表达式类-除法运算
class DivisionExpression : public AbstarctExpression
{
public:
	DivisionExpression(int firstNum, int secondNum)
	{
		m_firstNum = firstNum;
		m_secondNum = secondNum;
	}

	int interpreter()
	{
		return (m_firstNum / m_secondNum);
	}

private:
	int m_firstNum;
	int m_secondNum;
};

// 环境类
class Context
{
public:
	void setSymbolType(int symbolType)
	{
		m_symbolType = symbolType;
	}

	void setNum(string firstNumStr, string secondNumStr)
	{
		m_firstNumStr = firstNumStr;
		m_secondNumStr = secondNumStr;
	}

	int getResult()
	{
		int result = -999; // 不支持的运算符默认返回-999
		SymbolExpression *pFirstSymbolExpression = new SymbolExpression(m_firstNumStr);
		int firstNum = pFirstSymbolExpression->interpreter();

		SymbolExpression *pSecondSymbolExpression = new SymbolExpression(m_secondNumStr);
		int secondNum = pSecondSymbolExpression->interpreter();
		AbstarctExpression *pAbstarctExpression = nullptr;
		switch (m_symbolType)
		{
		case 1: // 加法运算
			pAbstarctExpression = dynamic_cast<PlusExpression*>(new PlusExpression(firstNum, secondNum));
			break;
		case 2: // 减法运算
			pAbstarctExpression = dynamic_cast<MinusExpression*>(new MinusExpression(firstNum, secondNum));
			break;
		case 3: // 乘法运算
			pAbstarctExpression = dynamic_cast<MultiExpression*>(new MultiExpression(firstNum, secondNum));
			break;
		case 4: // 除法运算
			pAbstarctExpression = dynamic_cast<DivisionExpression*>(new DivisionExpression(firstNum, secondNum));
			break;
		default:
			cout << "无法解释的运算符，只支持加减乘除运算，请找产品经理提需求增加！" << endl;
			break;
		}

		if (pAbstarctExpression != nullptr)
		{
			result = pAbstarctExpression->interpreter();
		}
		
		return result;
	}

private:
	string m_firstNumStr;
	string m_secondNumStr;
	int m_symbolType;
	AbstarctExpression *m_pAbstarctExpression;
};


int main()
{
	cout << "----------------------解释器模式----------------------" << endl;
	string firstNumStr = "10";
	string secondNumStr = "2";
	Context *pContext = new Context();

	cout << "----------------------进行加法运算----------------------" << endl;
	pContext->setSymbolType(1);
	pContext->setNum(firstNumStr, secondNumStr);
	cout << "运算结果：" << pContext->getResult() << endl;;

	cout << "----------------------进行减法运算----------------------" << endl;
	pContext->setSymbolType(2);
	pContext->setNum(firstNumStr, secondNumStr);
	cout << "运算结果：" << pContext->getResult() << endl;;

	cout << "----------------------进行乘法运算----------------------" << endl;
	pContext->setSymbolType(3);
	pContext->setNum(firstNumStr, secondNumStr);
	cout << "运算结果：" << pContext->getResult() << endl;;

	cout << "----------------------进行除法运算----------------------" << endl;
	pContext->setSymbolType(4);
	pContext->setNum(firstNumStr, secondNumStr);
	cout << "运算结果：" << pContext->getResult() << endl;;

	pContext->setSymbolType(5);
	pContext->setNum(firstNumStr, secondNumStr);
	cout << "运算结果：" << pContext->getResult() << endl;

	DELETE_PTR(pContext);
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
