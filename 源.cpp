#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
class AbstractCalculator
{
public:
	virtual double getResult()
	{
		return 0;
	}
	double m_Num1 = 0.0;
	double m_Num2 = 0.0;
};
//加法计算器
class AddCalculator :public AbstractCalculator
{
public:
	double getResult()
	{
		return m_Num1 + m_Num2;
	}
};
//减法计算器
class SubCalculator :public AbstractCalculator
{
public:
	double getResult()
	{
		return m_Num1 - m_Num2;
	}
};
//乘法计算器
class MulCalculator :public AbstractCalculator
{
public:
	double getResult()
	{
		return m_Num1 * m_Num2;
	}
};
//除法计算器
class DivCalculator :public AbstractCalculator
{
public:
	double getResult()
	{
		return m_Num1 / m_Num2;
	}
};
//乘方计算器
class SquCalculator :public AbstractCalculator
{
public:
	double getResult()
	{
		int i;
		double t = 1;
		for (i = 1; i <= m_Num2; i++)
		{
			t = t * m_Num1;
		}
		return t;
	}
};
//开方计算器
class PreCalculator :public AbstractCalculator
{
public:
	double getResult()
	{
		return sqrt(m_Num1);
	}
};
//三角函数计算器
class SinCalculator :public AbstractCalculator
{
public:
	double getResult()
	{
		//return sin(m_Num1*3.1415926/180);

		cout << "正弦值为:" << sin(m_Num1 * 3.1415926 / 180) << endl;
		cout << "余弦值为:" << cos(m_Num1 * 3.1415926 / 180) << endl;
		if (m_Num1)
			cout << "正切值为:";
		return tan(m_Num1 * 3.1415926 / 180);
	}

};
//任意进制转换为十进制计算器
class BaseCalculator :public AbstractCalculator
{
public:
	double getResult()
	{
		int t = m_Num1;
		double y = 0, product = 1;
		while (t != 0)
		{
			y = y + (t % 10) * product;
			t = t / 10;
			product = product * m_Num2;
		}
		return y;
	}
};
//十进制转换为任意进制计算器
class ANTIBaseCalculator :public AbstractCalculator
{
public:
	double getResult()
	{
		//x为十进制数，p为目标进制大小 
		int a[100]; //存放余数 
		int count = 0;
		int t = m_Num1;
		int m = m_Num2;
		do {
			a[count++] = t % m;
			t = t / m;
		} while (t != 0);//当商不为0时进行循环 
		for (int i = count - 1; i >= 0; i--)
		{
			printf("%d", a[i]);
		}
		printf("\n");
		return 0;
	}

};
//科学计算器界面
void fund()
{
	cout << endl <<"* *********欢迎来到科学计算器界面，按下数字键实现对应的操作 * *********" << endl;
	cout << endl << "——按下1来进行加法运算——" << endl;
	cout << "——按下2来进行减法运算——" << endl;
	cout << "——按下3来进行乘法运算——" << endl;
	cout << "——按下4来进行除法运算——" << endl;
	cout << "——按下5来进行乘方运算——" << endl;
	cout << "——按下6来进行开方运算——" << endl;
	cout << "——按下7来进行三角函数运算——" << endl;
	cout << "——按下8来进行任意进制转换十进制运算——" << endl;
	cout << "——按下9来进行十进制转换任意进制运算——" << endl;
}
//主函数
int main()
{
	fund();
	int m;
	AbstractCalculator* abc = new AddCalculator;
	while (1)
	{
		cout << "请输入数字实现操作:";
		cin >> m;
		switch (m)
		{
		case 1://创建加法计算器
		{
			abc = new AddCalculator;
			cout << "*执行加法运算;" << endl;
			cout<<"请输入两个需要相加的数字" << endl;
			cin >> abc->m_Num1 >> abc->m_Num2;
			cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
			cout << "按对应数字键来执行下一步操作，若按0则退出计算器" << endl;
		}break;
		case 2://创建减法计算器
		{
			abc = new SubCalculator;
			cout << "*执行减法运算" << endl;
			cout << "请输入两个需要相减的数字" << endl;
			cin >> abc->m_Num1 >> abc->m_Num2;
			cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
			cout << "按对应数字键来执行下一步操作，若按0则退出计算器" << endl;
		}break;
		case 3://创建乘法计算器
		{
			abc = new MulCalculator;
			cout << "*执行乘法运算" << endl;
			cout << "请输入两个需要相乘的数字" << endl;
			cin >> abc->m_Num1 >> abc->m_Num2;
			cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
			cout << "按对应数字键来执行下一步操作，若按0则退出计算器" << endl;
		}break;
		case 4://创建除法计算器
		{
			abc = new DivCalculator;
			cout << "*执行除法运算" << endl;
			cout << "请输入两个需要相除的数字(第二个数不能为0)" << endl;
			cin >> abc->m_Num1 >> abc->m_Num2;
			if (abc->m_Num2 == 0)
			{
				cout << "第二个数为0，运算错误！" << endl;
			}
			else
				cout << abc->m_Num1 << " / " << abc->m_Num2 << " = " << abc->getResult() << endl;
			cout << "按对应数字键来执行下一步操作，若按0则退出计算器" << endl;
		}break;
		case 5://创建乘方计算器
		{
			abc = new SquCalculator;
			cout << "*执行乘方运算" << endl;
			cout << "请输入需要乘方的数字和乘方数" << endl;
			cin >> abc->m_Num1 >> abc->m_Num2;
			cout << abc->m_Num1 << "的" << abc->m_Num2 << "次方 = ";
			cout<<abc->getResult() << endl;
			cout << "按对应数字键来执行下一步操作，若按0则退出计算器" << endl;
		}break;
		case 6://创建开方计算器
		{
			abc = new PreCalculator;
			cout << "*执行开方运算" << endl;
			cout << "请输入需要开方的数字（不能为负数）" << endl;
			cin >> abc->m_Num1;
			if (abc->m_Num1 > 0 || abc->m_Num1 == 0)
			{
				cout << abc->m_Num1 << "开方 = ";
				cout << abc->getResult() << endl;
			}
			else
				cout << "负数不能被开方！" << endl;
			cout << "按对应数字键来执行下一步操作，若按0则退出计算器" << endl;
		}break;
		case 7://创建三角函数计算器
		{
			abc = new SinCalculator;
			cout << "*执行三角函数运算" << endl;
			cout << "请输入角度" << endl;
			cin >> abc->m_Num1;
			cout << abc->getResult() << endl;
			cout << "按对应数字键来执行下一步操作，若按0则退出计算器" << endl;
		}break;
		case 8://创建任意进制转换为十进制计算器
		{
			abc = new BaseCalculator;
			cout << "*执行任意进制转换十进制运算" << endl;
			cout << "请输入一个数和它的进制" << endl;
			cin >> abc->m_Num1 >> abc->m_Num2;
			cout << "这个数转换为十进制为: " << abc->getResult() << endl;
			cout << "按对应数字键来执行下一步操作，若按0则退出计算器" << endl;
		}break;
		case 9://创建任意进制转换为十进制计算器
		{
			abc = new ANTIBaseCalculator;
			cout << "*执行十进制转换任意进制运算" << endl;
			cout << "请输入一个十进制数和需要转换的进制" << endl;
			cin >> abc->m_Num1 >> abc->m_Num2;
			cout << "该十进制数转换为对应进制为:";
			cout << abc->getResult() << endl;
			cout << "按对应数字键来执行下一步操作，若按0则退出计算器" << endl;
		}break;
		case 0:cout << "已退出计算器！！！" << endl; return 0;
		}
	}
	system("pause");
	return 0;
}