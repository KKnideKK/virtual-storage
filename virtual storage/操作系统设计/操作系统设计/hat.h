#include<iostream>
using namespace std;
int Yx_y[8] = { 0,1,3,2,0,1,2,3 };//页表优先度
int Yx[4] = { 0,1,3,2 };//快表优先度

struct form
{
	int page_id;//页号
	int physical_id;//物理块号
	int status;//状态位
	int Accessing;//访问字段
	int modify;//修改位
	int ESaddress;//外存地址
};
form YB[17] =
{ {0, 6,1,0,0,67 }, {1, 7,1,0,0,34},{2,19,1,0,0,24 }, {3,42,1,0,0,12 },
	{4,-1,0,0,0,56 }, {5,-1,0,0,0,67},{6,-1,0,0,0,45 }, {7,-1,0,0,0,66 },
	{8,-1,0,0,0,90 }, {9,-1,0,0,0,12},{10,-1,0,0,0,24 }, {11,-1,0,0,0,19 },
	{12,-1,0,0,0,32 }, {13,-1,0,0,0,43},{14,-1,0,0,0,56 }, {15,-1,0,0,0,54 },
	{16,-1,0,0,0,43 }
};//初始化页表
form KB[4] =
{
	{0,6,1,5,1,67},{1,7,1,6,0,34},{2,19,1,7,1,24},{3,42,1,2,1,12}
};//初始化快表
void print_form(form k[],int size)//输出表
{
	cout << "|页号   |物理块号|状态位P|访问字段A|修改位M|外存地址|" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "-----------------------------------------------------" << endl;
		cout << "|" << k[i].page_id << "\t|" << k[i].physical_id << "\t |" << k[i].status << "\t |" << k[i].Accessing << "\t   |" << k[i].modify << "\t   |" << k[i].ESaddress<<"\t    |" << endl;
	}
	cout << "-----------------------------------------------------" << endl;
}
int KB_search(form k[],int id,int size)//进入快表
{
	for (int i=0;i<size;i++)
	{
		if (k[i].page_id == id)
		{
			cout << "在快表中找到" << endl;
			return k[i].physical_id;
		}
	}
	return -1;
}
void KB_new(form kb[],form yb,int yx[])//更新快表
{
	for (int i =0;i<4;i++)
	{
		if (yx[i] == 3)
		{
			kb[i].Accessing = yb.Accessing;
			kb[i].ESaddress = yb.ESaddress;
			kb[i].modify = yb.modify;
			kb[i].page_id = yb.page_id;
			kb[i].physical_id = yb.physical_id;
			kb[i].status = 1;
			yx[i] = -1;
			for (int j = 0; j < 4; j++)
			{
				yx[j]++;
			}
			return;
		}
		
	}
}
void YB_new(form yb[],int data,int y[])//页表更新
{
	for (int i = 0; i < 4; i++)
	{
		if (y[i] == 3)
		{
			yb[data].physical_id = yb[y[i+4]].physical_id;
			yb[data].status = 1;
			yb[data].Accessing = yb[y[i + 4]].Accessing;
			yb[data].modify = yb[y[i + 4]].modify;
			cout << yb[data].page_id<<"号页面置换" << y[i + 4]<<"号页面" << endl;
			yb[y[i + 4]].status = 0;
			y[i + 4] = yb[data].page_id;
			y[i] = -1;
			KB_new(KB,yb[data],Yx);
				for (int j = 0; j < 4; j++)
				{
					y[j]++;
				}
				return;
		}
	}
}
