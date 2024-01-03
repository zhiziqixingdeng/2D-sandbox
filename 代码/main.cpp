#include <iostream>
#include "var.h"
#include <iomanip>
using namespace std;
char world[1000][1000];
int x=500;
int y=500;
void draw(){
	for(int i=x-5;i<=x+5;i+=1){
		for(int j=x-5;j<=x+5;j+=1){
			cout<<world[i][j];
		}
		cout<<endl;
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
	while(true){

	}
	return 0;
}
