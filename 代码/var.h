#ifndef CIRCLE_H
#define  CIRCLE_H
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string>
using namespace std;
struct bag{
	string article;
	int flag;//��ʲô��
	/*
	1.����ͷ
	2.�������
	*/
}s[6];
int cnt;//���������ж���
struct people{
	string name;
	int x,y;//����
	int blood,hungry;
	int food;
	int wood,rock;
	void e(){
		cout<<"ľͷ:"<<wood<<endl<<"ʯͷ:"<<rock<<endl<<"ʳ��:"<<food<<endl;
		for(int i=1;i<=5;i++){
			cout<<s[i].article<<endl;
		}
		return;
	}
	void eat(){
		system("cls");
		if(hungry==8){
			cout<<"�Ҳ���"<<endl;
		}
		else{
			cout<<"�Ե���"<<endl;
			hungry++;
			food--;
		}
	}
	void make(int x){
		if(x==1){
			if(wood>=3&&rock>=2&&cnt<=5){
				cout<<"�ϳɳɹ�!"<<endl;
				wood-=3;
				rock-=2;
				cnt++;
				cout<<"����Ʒȡ������:";
				getline(cin,s[cnt].article);
				s[cnt].flag=1;
			}
			else if(cnt==6){
				cout<<"��������"<<endl;
			}
			else{
				cout<<"���ϲ���"<<endl;
			}
			sleep(1);
			system("cls");
		}
		else{
			if(wood>=2&&rock>=3&&cnt<=5){
				cout<<"�ϳɳɹ�!"<<endl;
				wood-=2;
				rock-=3;
				cnt++;
				cout<<"����Ʒȡ������:";
				getline(cin,s[cnt].article);
				s[cnt].flag=2;
			}
			else if(cnt==6){
				cout<<"��������"<<endl;
			}
			else{
				cout<<"���ϲ���"<<endl;
			}
			sleep(1);
			system("cls");
		}
		return;
	}
	void del(){
		s[cnt].article="";
		s[cnt].flag=0;
		wood++;
		rock++;//��Ϊ���ˣ����Բ���ԭ���˻�(����)
		return;
	}
};
#endif
