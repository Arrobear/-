#pragma once
#define MAX 1000

//联系人结构体
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};
//通讯录结构体
struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size;
};

void showMenu();  //显示菜单

void addPerson(Addressbooks* abs);  //添加联系人

void showPerson(Addressbooks* abs);  //显示通讯录中的所有联系人

int Check(Addressbooks* abs,string name);  //检查通讯录中是否有联系人并返回具体位置

void deletePerson(Addressbooks* abs);  //删除联系人

void checkPerson(Addressbooks* abs);  //查找联系人

void changePerson(Addressbooks* abs);  //修改联系人

void freeAddressbooks(Addressbooks* abs);  //清空通讯录
  //退出程序