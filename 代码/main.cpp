#include <iostream>
#include "var.h"
#include <iomanip>
#include<conio.h>
using namespace std;
char world[1000][1000];
int x=500;
int y=500;
char to;
int w;
void draw(){
	for(int i=x-5;i<=x+5;i+=1){
		for(int j=y-5;j<=y+5;j+=1){
			if(i==x&&j==y){
				cout<<'m';
			}
			cout<<world[i][j];
		}
	}
}
void init(){
	for(int i=1;i<=1000;i+=9){
		for(int j=5;j<=1000;j+=16){
			world[i][j]='t';//树
		}
	}
	for(int i=200;i<=400;i++){
		for(int j=100;j<=300;j++){
			world[i][j]='r';
			world[i+500][j+600]='r';
		}
	}
	for(int i=1;i<=100;i++){
		for(int j=1;j<=100;j++){
			world[i][j]='f';//吃的
		}
	}
	world[512][501]='f';
	char to;
	for(int i=1;i<=1000;i+=1){
		for(int j=1;j<=1000;j+=1){
			if(world[i][j]!='f'&&world[i][j]!='r'&&world[i][j]!='t'){
				world[i][j]='.';
			}
		}
	}
}
void f(){
	freopen("world.in","r",stdin);
	for(int i=1;i<=1000;i+=1){
		for(int j=1;j<=1000;j+=1){
			cin>>world[i][j];
		}
		cout<<endl;
	}
	freopen("CON","r",stdin);
	return;
}
int main(){
	cout<<"1.读取存档 2.新地图"<<endl;
	int w;
	cin>>w;
	if(w==1){
		f();
	}
	else{
		init();
	}
	people user;
	user.hungry=7;
	while(true){
		system("cls");
		draw();
		cin>>to;
		if(to=='w'){
			if(world[x-1][y]!='#'&&world[x-1][y]!='t'&&world[x-1][y]!='r'){
				user.x--;
			}
		}
		else if(to=='s'){
			if(world[x+1][y]!='#'&&world[x-1][y]!='t'&&world[x-1][y]!='r'){
				user.x++;
			}
		}
		else if(to=='a'){
			if(world[x][y-1]!='#'&&world[x][y-1]!='t'&&world[x][y-1]!='r'){
				user.y--;
			}
		}
		else if(to=='d'){
			if(world[x][y+1]!='#'&&world[x][y+1]!='t'&&world[x][y+1]!='r'){
				user.y++;
			}
		}
		else if(to=='l'){
			if(world[x-1][y]=='#'){
				user.rock++;
				user.wood++;
			}
			else if(world[x-1][y]=='r'){
				user.rock++;
				for(int i=1;i<=6;i++){
					if(s[i].flag==2){
						user.rock++;
					}
				}
			}
			else if(world[x-1][y]=='t'){
				user.wood++;
				for(int i=1;i<=6;i++){
					if(s[i].flag==1){
						user.wood++;
					}
				}
			}
			else if(world[x-1][y]=='f'){
				user.food+=2;
			}
		}
		else if(to=='f'){
			if(world[x-1][y]==' '&&user.rock>=2&&user.wood>=2){
        user.hungry--;
        user.rock-=2;
        user.wood-=2;
			}
		}
		else if(to=='e'){
			user.e();
		}
		else if(to=='h'){
			if(user.food>=1){
				user.eat();
			}
		}
		else if(to=='m'){
			cout<<"造什么"<<endl;
			cout<<"1.斧头"<<endl;
			cout<<"2.稿子"<<endl;
			cin>>w;
			user.make(w);
		}
		else if(to=='d'){
			user.del();
		}
		if(user.hungry<=0){
			user.blood--;
		}
		if(user.blood==0){
			break;
		}
		system("pause");
		system("cls");
	}
	cout<<"你死了"<<endl;
	freopen("world.in","w",stdout);
	for(int i=1;i<=1000;i+=1){
		for(int j=1;j<=1000;j+=1){
			cout<<world[i][j];
		}
		cout<<endl;
	}
	freopen("CON","w",stdout);
	return 0;
}
