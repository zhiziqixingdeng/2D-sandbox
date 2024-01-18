#ifndef CIRCLE_H
#define  CIRCLE_H
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string>
using namespace std;
struct bag{
	string article;
	int flag;//有什么用
	/*
	1.代表斧头
	2.代表稿子
	*/
}s[6];
int cnt;//背包里面有多少
struct people{
	string name;
	int x,y;//坐标
	int blood,hungry;
	int food;
	int wood,rock;
	void e(){
		cout<<"木头:"<<wood<<endl<<"石头:"<<rock<<endl<<"食物:"<<food<<endl;
		for(int i=1;i<=5;i++){
			cout<<s[i].article<<endl;
		}
		return;
	}
	void eat(){
		system("cls");
		if(hungry==7){
			cout<<"我不饿"<<endl;
		}
		else{
			cout<<"吃掉了"<<endl;
			hungry++;
			food--;
		}
	}
	void make(int x){
		if(x==1){
			if(wood>=3&&rock>=2&&cnt<=5){
				cout<<"合成成功!"<<endl;
				wood-=3;
				rock-=2;
				cnt++;
				cout<<"给物品取个名字:";
				getline(cin,s[cnt].article);
				s[cnt].flag=1;
			}
			else if(cnt==6){
				cout<<"背包满了"<<endl;
			}
			else{
				cout<<"材料不够"<<endl;
			}
			sleep(1);
			system("cls");
		}
		else{
			if(wood>=2&&rock>=3&&cnt<=5){
				cout<<"合成成功!"<<endl;
				wood-=2;
				rock-=3;
				cnt++;
				cout<<"给物品取个名字:";
				getline(cin,s[cnt].article);
				s[cnt].flag=2;
			}
			else if(cnt==6){
				cout<<"背包满了"<<endl;
			}
			else{
				cout<<"材料不够"<<endl;
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
		rock++;//因为拆了，所以不能原价退回(滑稽)
		return;
	}
};
#endif
