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
//�ӷ�������
class AddCalculator :public AbstractCalculator
{
public:
	double getResult()
	{
		return m_Num1 + m_Num2;
	}
};
//����������
class SubCalculator :public AbstractCalculator
{
public:
	double getResult()
	{
		return m_Num1 - m_Num2;
	}
};
//�˷�������
class MulCalculator :public AbstractCalculator
{
public:
	double getResult()
	{
		return m_Num1 * m_Num2;
	}
};
//����������
class DivCalculator :public AbstractCalculator
{
public:
	double getResult()
	{
		return m_Num1 / m_Num2;
	}
};
//�˷�������
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
//����������
class PreCalculator :public AbstractCalculator
{
public:
	double getResult()
	{
		return sqrt(m_Num1);
	}
};
//���Ǻ���������
class SinCalculator :public AbstractCalculator
{
public:
	double getResult()
	{
		//return sin(m_Num1*3.1415926/180);

		cout << "����ֵΪ:" << sin(m_Num1 * 3.1415926 / 180) << endl;
		cout << "����ֵΪ:" << cos(m_Num1 * 3.1415926 / 180) << endl;
		if (m_Num1)
			cout << "����ֵΪ:";
		return tan(m_Num1 * 3.1415926 / 180);
	}

};
//�������ת��Ϊʮ���Ƽ�����
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
//ʮ����ת��Ϊ������Ƽ�����
class ANTIBaseCalculator :public AbstractCalculator
{
public:
	double getResult()
	{
		//xΪʮ��������pΪĿ����ƴ�С 
		int a[100]; //������� 
		int count = 0;
		int t = m_Num1;
		int m = m_Num2;
		do {
			a[count++] = t % m;
			t = t / m;
		} while (t != 0);//���̲�Ϊ0ʱ����ѭ�� 
		for (int i = count - 1; i >= 0; i--)
		{
			printf("%d", a[i]);
		}
		printf("\n");
		return 0;
	}

};
//��ѧ����������
void fund()
{
	cout << endl <<"* *********��ӭ������ѧ���������棬�������ּ�ʵ�ֶ�Ӧ�Ĳ��� * *********" << endl;
	cout << endl << "��������1�����мӷ����㡪��" << endl;
	cout << "��������2�����м������㡪��" << endl;
	cout << "��������3�����г˷����㡪��" << endl;
	cout << "��������4�����г������㡪��" << endl;
	cout << "��������5�����г˷����㡪��" << endl;
	cout << "��������6�����п������㡪��" << endl;
	cout << "��������7���������Ǻ������㡪��" << endl;
	cout << "��������8�������������ת��ʮ�������㡪��" << endl;
	cout << "��������9������ʮ����ת������������㡪��" << endl;
}
//������
int main()
{
	fund();
	int m;
	AbstractCalculator* abc = new AddCalculator;
	while (1)
	{
		cout << "����������ʵ�ֲ���:";
		cin >> m;
		switch (m)
		{
		case 1://�����ӷ�������
		{
			abc = new AddCalculator;
			cout << "*ִ�мӷ�����;" << endl;
			cout<<"������������Ҫ��ӵ�����" << endl;
			cin >> abc->m_Num1 >> abc->m_Num2;
			cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
			cout << "����Ӧ���ּ���ִ����һ������������0���˳�������" << endl;
		}break;
		case 2://��������������
		{
			abc = new SubCalculator;
			cout << "*ִ�м�������" << endl;
			cout << "������������Ҫ���������" << endl;
			cin >> abc->m_Num1 >> abc->m_Num2;
			cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
			cout << "����Ӧ���ּ���ִ����һ������������0���˳�������" << endl;
		}break;
		case 3://�����˷�������
		{
			abc = new MulCalculator;
			cout << "*ִ�г˷�����" << endl;
			cout << "������������Ҫ��˵�����" << endl;
			cin >> abc->m_Num1 >> abc->m_Num2;
			cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
			cout << "����Ӧ���ּ���ִ����һ������������0���˳�������" << endl;
		}break;
		case 4://��������������
		{
			abc = new DivCalculator;
			cout << "*ִ�г�������" << endl;
			cout << "������������Ҫ���������(�ڶ���������Ϊ0)" << endl;
			cin >> abc->m_Num1 >> abc->m_Num2;
			if (abc->m_Num2 == 0)
			{
				cout << "�ڶ�����Ϊ0���������" << endl;
			}
			else
				cout << abc->m_Num1 << " / " << abc->m_Num2 << " = " << abc->getResult() << endl;
			cout << "����Ӧ���ּ���ִ����һ������������0���˳�������" << endl;
		}break;
		case 5://�����˷�������
		{
			abc = new SquCalculator;
			cout << "*ִ�г˷�����" << endl;
			cout << "��������Ҫ�˷������ֺͳ˷���" << endl;
			cin >> abc->m_Num1 >> abc->m_Num2;
			cout << abc->m_Num1 << "��" << abc->m_Num2 << "�η� = ";
			cout<<abc->getResult() << endl;
			cout << "����Ӧ���ּ���ִ����һ������������0���˳�������" << endl;
		}break;
		case 6://��������������
		{
			abc = new PreCalculator;
			cout << "*ִ�п�������" << endl;
			cout << "��������Ҫ���������֣�����Ϊ������" << endl;
			cin >> abc->m_Num1;
			if (abc->m_Num1 > 0 || abc->m_Num1 == 0)
			{
				cout << abc->m_Num1 << "���� = ";
				cout << abc->getResult() << endl;
			}
			else
				cout << "�������ܱ�������" << endl;
			cout << "����Ӧ���ּ���ִ����һ������������0���˳�������" << endl;
		}break;
		case 7://�������Ǻ���������
		{
			abc = new SinCalculator;
			cout << "*ִ�����Ǻ�������" << endl;
			cout << "������Ƕ�" << endl;
			cin >> abc->m_Num1;
			cout << abc->getResult() << endl;
			cout << "����Ӧ���ּ���ִ����һ������������0���˳�������" << endl;
		}break;
		case 8://�����������ת��Ϊʮ���Ƽ�����
		{
			abc = new BaseCalculator;
			cout << "*ִ���������ת��ʮ��������" << endl;
			cout << "������һ���������Ľ���" << endl;
			cin >> abc->m_Num1 >> abc->m_Num2;
			cout << "�����ת��Ϊʮ����Ϊ: " << abc->getResult() << endl;
			cout << "����Ӧ���ּ���ִ����һ������������0���˳�������" << endl;
		}break;
		case 9://�����������ת��Ϊʮ���Ƽ�����
		{
			abc = new ANTIBaseCalculator;
			cout << "*ִ��ʮ����ת�������������" << endl;
			cout << "������һ��ʮ����������Ҫת���Ľ���" << endl;
			cin >> abc->m_Num1 >> abc->m_Num2;
			cout << "��ʮ������ת��Ϊ��Ӧ����Ϊ:";
			cout << abc->getResult() << endl;
			cout << "����Ӧ���ּ���ִ����һ������������0���˳�������" << endl;
		}break;
		case 0:cout << "���˳�������������" << endl; return 0;
		}
	}
	system("pause");
	return 0;
}