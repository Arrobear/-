#include<iostream>
using namespace std;
#include<string>
#include"api.h"

void showMenu()//显示菜单
{
	cout << "***************************" << endl;
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}

void addPerson(Addressbooks* abs)
{
	//判断通讯录是否已满
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加！" << endl;
		return;
	}
	else
	{
		//添加具体联系人
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name=name; 

		cout << "请输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "请重新输入（1或2）" << endl;
		}

		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		abs->m_Size++;
		cout << "添加成功！" << endl;

		system("pause");
		system("cls");
	}
}

void showPerson(Addressbooks* abs)  //显示通讯录中的所有联系人
{
	//判断联系人是否为空
	if (abs->m_Size == 0)
	{
		cout << "当前联系人为空。" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Addr<< endl;
		}
	}
	system("pause");
	system("cls");
}

int Check(Addressbooks* abs, string name)  //检查通讯录中是否有联系人并返回具体位置
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

void deletePerson(Addressbooks* abs)  //删除联系人
{
	cout << "请输入您要删除的联系人：" << endl;
	string name;
	cin >> name;

	int ret = Check(abs, name);
	if (ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		for (ret; ret < abs->m_Size; ret++)
		{
			abs->personArray[ret] = abs->personArray[ret + 1];
		}
		abs->m_Size = abs->m_Size - 1;
	}
	system("pause");
	system("cls");
}

void checkPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人：" << endl;
	string name;
	cin >> name;
	int ret = Check(abs, name);

	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}

void changePerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人：" << endl;
	string name;
	cin >> name;
	int ret = Check(abs, name);
	if (ret!=- 1)
	{
		cout << "请重新输入姓名：" << endl;
		string who;
		cin >> who;
		abs->personArray[ret].m_Name = who;

		cout << "请重新输入性别：" << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "请重新输入（1或2）" << endl;
		}

		cout << "请重新输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		cout << "请重新输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		cout << "请重新输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;


		system("pause");
		system("cls");
	}
	else
	{
		cout << "查无此人" << endl;
	}
}

void freeAddressbooks(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}