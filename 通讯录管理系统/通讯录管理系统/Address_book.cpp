#include<iostream>
using namespace std;
#include"api.h"
#include<string>

int main()
{
	int select = 0;  //用户选择输入的变量
	
	Addressbooks abs;  //创建通讯录
	abs.m_Size = 0;

	while (true)
	{
		showMenu();  //菜单调用
		cin >> select;

		switch (select)
		{
		case 1:  //添加联系人
			addPerson(&abs);
			break;
		case 2:  //显示联系人
			showPerson(&abs);
			break;
		case 3:  //删除联系人
			deletePerson(&abs);
			break;
		case 4:  //查找联系人
			checkPerson(&abs);
			break;
		case 5:  //修改联系人
			changePerson(&abs);
			break;
		case 6:  //清空联系人
			freeAddressbooks(&abs);
			break;
		case 0:  //退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}