#include<iostream>
#include"hat.h"
using namespace std;

float arr = 0;//ȱҳ��
void Yx_new(int data,form KB[],int y[],int size)
{
	for (int i = 0; i < size; i++)
	{
		if (KB[i].page_id == data)
		{
			y[i] = -1;
			for (int j = 0; j < 4; j++)
			{
				y[j]++;
			}
			return;
		}
	}
}
int main()
{

	for (int i=0;i<10;i++)
	{
		int k = 0;
		cout << "�������߼���ַ��" ;
		cin >> k;
		int page_id_data = k / 1024;//�õ�ҳ��
		int page_add = k % 1024;//�߼���ַƫ����
		if (page_id_data >= 17)
		{
			cout << "Խ���ж�" << endl;
			cout << "��ʱҳ��״̬��" << endl;
			print_form(YB,sizeof(YB)/sizeof(YB[0]));//���ҳ��
			cout << "��ʱ���״̬��" << endl;
			print_form(KB,sizeof(KB)/sizeof(KB[0]));//������
			system("pause");
			continue;
		}
		int KH = KB_search(KB, page_id_data, sizeof(KB) / sizeof(KB[0]));
		if (KH>= 0)//�������
		{
			cout << "�����ַΪ��" << KH * 1024 + page_add << endl;
			cout << "��ʱҳ��״̬��" << endl;
			print_form(YB, sizeof(YB) / sizeof(YB[0]));//���ҳ��
			cout << "��ʱ���״̬��" << endl;
			print_form(KB, sizeof(KB) / sizeof(KB[0]));//������
			system("pause");
			//Yx_new(page_id_data,KB,Yx, sizeof(KB) / sizeof(KB[0]));//����ʹ�ã�LRU���û��㷨ʱ����
			continue;
		}
		cout << "���δ����,����ҳ��" << endl;
		if (YB[page_id_data].status)//ҳ������
		{
			

			cout << "��ҳ�����ҵ�" << endl;
			cout << "�����ַΪ��" << YB[page_id_data].physical_id * 1024 + page_add << endl;
			cout << "��ʱҳ��״̬��" << endl;
			print_form(YB, sizeof(YB) / sizeof(YB[0]));//���ҳ��
			cout << "��ʱ���״̬��" << endl;
			print_form(KB, sizeof(KB) / sizeof(KB[0]));//������
			//Yx_new(page_id_data, YB, Yx_y, sizeof(YB) / sizeof(YB[0]));//����ʹ�ã�LRU���û��㷨ʱ����
			system("pause");
			continue;
		}
		else//ҳ��δ����
		{
			cout << "ҳ��δ���У�ȱҳ�жϣ�����ҳ���û�" << endl;
			arr++;
			YB_new(YB,page_id_data,Yx_y);//����ҳ��
			if (YB[page_id_data].status)//ҳ������
			{
				
				cout << "��ҳ�����ҵ�" << endl;
				cout << "(������Ϊ��"<< YB[page_id_data].physical_id <<") X (ҳ���С1024) + " << "(ƫ������" << page_add <<")" << endl;
				cout << "�����ַΪ��" << YB[page_id_data].physical_id * 1024 + page_add << endl;
				cout << "��ʱҳ��״̬��" << endl;
				print_form(YB, sizeof(YB) / sizeof(YB[0]));//���ҳ��
				cout << "��ʱ���״̬��" << endl;
				print_form(KB, sizeof(KB) / sizeof(KB[0]));//������
				system("pause");
				continue;
			}
			else
			{
				cout << "ȱҳ����ʧ��" << endl;
			}
		}
		system("pause");
	}
	cout << "ȱҳ�ʣ�" << arr / 10*100 <<"%" << endl;
	return 0;
}