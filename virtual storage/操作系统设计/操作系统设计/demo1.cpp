#include<iostream>
#include"hat.h"
using namespace std;

float arr = 0;//缺页数
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
		cout << "请输入逻辑地址：" ;
		cin >> k;
		int page_id_data = k / 1024;//得到页号
		int page_add = k % 1024;//逻辑地址偏移量
		if (page_id_data >= 17)
		{
			cout << "越界中断" << endl;
			cout << "此时页表状态：" << endl;
			print_form(YB,sizeof(YB)/sizeof(YB[0]));//输出页表
			cout << "此时快表状态：" << endl;
			print_form(KB,sizeof(KB)/sizeof(KB[0]));//输出快表
			system("pause");
			continue;
		}
		int KH = KB_search(KB, page_id_data, sizeof(KB) / sizeof(KB[0]));
		if (KH>= 0)//快表命中
		{
			cout << "物理地址为：" << KH * 1024 + page_add << endl;
			cout << "此时页表状态：" << endl;
			print_form(YB, sizeof(YB) / sizeof(YB[0]));//输出页表
			cout << "此时快表状态：" << endl;
			print_form(KB, sizeof(KB) / sizeof(KB[0]));//输出快表
			system("pause");
			//Yx_new(page_id_data,KB,Yx, sizeof(KB) / sizeof(KB[0]));//最少使用（LRU）置换算法时调用
			continue;
		}
		cout << "快表未命中,查找页表" << endl;
		if (YB[page_id_data].status)//页表命中
		{
			

			cout << "在页表中找到" << endl;
			cout << "物理地址为：" << YB[page_id_data].physical_id * 1024 + page_add << endl;
			cout << "此时页表状态：" << endl;
			print_form(YB, sizeof(YB) / sizeof(YB[0]));//输出页表
			cout << "此时快表状态：" << endl;
			print_form(KB, sizeof(KB) / sizeof(KB[0]));//输出快表
			//Yx_new(page_id_data, YB, Yx_y, sizeof(YB) / sizeof(YB[0]));//最少使用（LRU）置换算法时调用
			system("pause");
			continue;
		}
		else//页表未命中
		{
			cout << "页表未命中，缺页中断，进行页面置换" << endl;
			arr++;
			YB_new(YB,page_id_data,Yx_y);//更新页表
			if (YB[page_id_data].status)//页表命中
			{
				
				cout << "在页表中找到" << endl;
				cout << "(物理块号为："<< YB[page_id_data].physical_id <<") X (页面大小1024) + " << "(偏移量：" << page_add <<")" << endl;
				cout << "物理地址为：" << YB[page_id_data].physical_id * 1024 + page_add << endl;
				cout << "此时页表状态：" << endl;
				print_form(YB, sizeof(YB) / sizeof(YB[0]));//输出页表
				cout << "此时快表状态：" << endl;
				print_form(KB, sizeof(KB) / sizeof(KB[0]));//输出快表
				system("pause");
				continue;
			}
			else
			{
				cout << "缺页调度失败" << endl;
			}
		}
		system("pause");
	}
	cout << "缺页率：" << arr / 10*100 <<"%" << endl;
	return 0;
}