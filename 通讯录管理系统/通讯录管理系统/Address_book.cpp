#include<iostream>
using namespace std;
#include"api.h"
#include<string>

int main()
{
	int select = 0;  //�û�ѡ������ı���
	
	Addressbooks abs;  //����ͨѶ¼
	abs.m_Size = 0;

	while (true)
	{
		showMenu();  //�˵�����
		cin >> select;

		switch (select)
		{
		case 1:  //�����ϵ��
			addPerson(&abs);
			break;
		case 2:  //��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3:  //ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4:  //������ϵ��
			checkPerson(&abs);
			break;
		case 5:  //�޸���ϵ��
			changePerson(&abs);
			break;
		case 6:  //�����ϵ��
			freeAddressbooks(&abs);
			break;
		case 0:  //�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}