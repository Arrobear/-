#pragma once
#define MAX 1000

//��ϵ�˽ṹ��
struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};
//ͨѶ¼�ṹ��
struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size;
};

void showMenu();  //��ʾ�˵�

void addPerson(Addressbooks* abs);  //�����ϵ��

void showPerson(Addressbooks* abs);  //��ʾͨѶ¼�е�������ϵ��

int Check(Addressbooks* abs,string name);  //���ͨѶ¼���Ƿ�����ϵ�˲����ؾ���λ��

void deletePerson(Addressbooks* abs);  //ɾ����ϵ��

void checkPerson(Addressbooks* abs);  //������ϵ��

void changePerson(Addressbooks* abs);  //�޸���ϵ��

void freeAddressbooks(Addressbooks* abs);  //���ͨѶ¼
  //�˳�����