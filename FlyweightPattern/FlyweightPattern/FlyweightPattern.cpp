// FlyweightPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <map>

#define DELETE_PTR(p) {if(p!=nullptr){delete (p); (p)=nullptr;}}

using namespace std;

// 享元抽象类
class Person
{
public:
	Person(string name, int age, string sex) 
	{
		m_name = name;
		m_age = age;
		m_sex = sex;
	}
	
	string getName() 
	{
		return m_name; 
	}

	int getAge()
	{
		return m_age;
	}

	string getSex()
	{
		return m_sex;
	}


protected:
	string m_name;
	int m_age;
	string m_sex;
};

// 享元具体类
class Employee : public Person
{
public:
	Employee(int id, string name, int age, string sex):Person(name,age,sex)
	{
		m_id = id;
	}
	
	int getId()
	{
		return m_id;
	}

	void printInfo()
	{
		cout << "id: " << m_id << "\t" << "name: " << m_name << "\t" << "age: " << m_age << "\t" << "sex: " << m_sex << "\t" << endl;
		cout << "---------------------------------------------------------------------------------" << endl;
	}

private:
	int m_id;
};

// 享元工厂类
class EmployeeFactory
{
public:
	EmployeeFactory()
	{
	}

	~EmployeeFactory()
	{
		while (!m_employeeMap.empty())
		{
			Employee *pEmployee = nullptr;
			map<int, Employee*>::iterator iter = m_employeeMap.begin();
			pEmployee = iter->second;
			m_employeeMap.erase(iter);
			DELETE_PTR(pEmployee);
		}
		m_employeeMap.clear();
	}

	Employee *getEmployee(int id)
	{
		string name = "";
		int age = 0;
		string sex = "男";
		
		Employee *pEmployee = nullptr;
		map<int, Employee*>::iterator iter = m_employeeMap.find(id);
		if (iter == m_employeeMap.end())
		{
			cout << "id为：" << id << "员工不存在，系统为你创建该员工，请输入信息。" << endl;
			cout << "员工名字：";
			cin >> name;
			cout << "员工年龄：";
			cin >> age;
			cout << "员工性别：";
			cin >> sex;
			pEmployee = new Employee(id, name, age, sex);
			m_employeeMap.insert(pair<int,Employee*>(id,pEmployee));
		}
		else
		{
			cout << "id为：" << id << "员工存在，信息如下。" << endl;
			pEmployee = (iter->second);
		}
		return pEmployee;
	}

private:
	map<int, Employee*> m_employeeMap;
};


int main()
{
	cout << "-------------------享元模式-------------------" << endl;
	EmployeeFactory *pEmployeeFactory = new EmployeeFactory;
	Employee *pEmployee1 = pEmployeeFactory->getEmployee(1);
	pEmployee1->printInfo();

	Employee *pEmployee2 = pEmployeeFactory->getEmployee(2);
	pEmployee2->printInfo();

	Employee *pEmployee = pEmployeeFactory->getEmployee(1);
	pEmployee->printInfo();

	DELETE_PTR(pEmployeeFactory);
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
