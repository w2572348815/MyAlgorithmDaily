#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<cstring>
using namespace std;
 struct student
{

	char name[11];
	char id[11];
	char it_class[11];
	double score_English;
	double score_math;
    double score_chinese;
	double score_computer;
	struct student *next;		
};
int main()
{	
	cout<<"                                             欢迎登录学生成绩管理系统"<<endl; 
	cout<<"                              输入指定按键管理查询"<<endl;
		student *head,*p;
   	       		int n1=0;
   	       	p=head=(student*)malloc(sizeof(student));
   	       	head->next=p;
		while(1){
	cout<<"                                              1，添加学生信息"<<endl;
	cout<<"                                              2，删除学生信息"<<endl;
   	cout<<"                                              3，修改学生信息"<<endl;  
   	cout<<"                                              4，查询学生信息"<<endl;
   	cout<<"                                              5，班级分数信息"<<endl;
   	cout<<"                                                0，退出系统"<<endl;
   	
   	      int n=0;  
   	       	cin>>n;
   	       	if(n==1)
   	       	{
   	       		cout<<"你正在进入添加学生信息系统......"<<endl; 
   	       		while(1)
   	       		{
   	       			      cout<<"             请选择接下来你的操作"<<endl;
						  cout<<"             1,添加学生信息"<<endl;
						  cout<<"             0,退出添加系统"<<endl; 
						  cin>>n1;
						  if(n1==1)
						  {
						  	cout<<"输入该学生的名字，学号，班级，英语数学语文和计算机成绩"<<endl;
						  	cout<<"姓名:"<<endl; cin>>p->name;
							cout<<"学号:"<<endl; cin>>p->id;
							cout<<"班级:"<<endl; cin>>p->it_class;
							cout<<"英语成绩:"<<endl; cin>>p->score_English;
							cout<<"数学成绩:"<<endl; cin>>p->score_math;
							cout<<"语文成绩:"<<endl; cin>>p->score_chinese;
							cout<<"计算机成绩:"<<endl; cin>>p->score_computer;
							student *q;
					     	q=(student*)malloc(sizeof(student)); 
					        p->next=q;
					        p=q;  
						  }
						  else if(n1==0)break;
						    p->next=NULL;
   	       		}
   	       	}
   	       	else if(n==2)
		    {
		    	
   	       	}
   	       	else if(n==3)
   	       	{
   	       	}
   	       	else if(n==4)
   	       	{
   	       		cout<<"你正在进入查询学生信息系统......" <<endl;
   	       		while(1)
   	       	{
   	       		int n4=0;
   	       		         cout<<"             请选择你要查询的方式"<<endl;
   	       		         cout<<"             1，根据姓名查询"<<endl;
   	       		         cout<<"             2，根据班级查询"<<endl;
   	       		         cout<<"             3，根据学号查询"<<endl;
   	       		         cout<<"             0，退出信息查询系统"<<endl;
					cin>>n4;
					if(n4==1)
					{
						cout<<"请输入要查询的名字"<<endl;
						char name4[10];
						cin>>name4; 
						student *q4;
						q4=(student*)malloc(sizeof(student));
						q4=head;
						while(q4!=NULL)
						{
							// cout << "dasdsadsa";
							if(!strcmp(name4,q4->name))
							{
								cout<<"姓名："<<q4->name<<"学号："<<q4->id<<"班级："<<q4->it_class<<"数学成绩："<<q4->score_math<<"英语成绩："<<q4->score_English<<"语文成绩"<<q4->score_chinese<<"计算机成绩："<<q4->score_computer<<endl; 
							}
							q4=q4->next;
						}
					}
					else if(n4==2)
					{
					}
					else if(n4==3)
					{
					}
					else if(n4==0)
					{
						break;
					} 
		}
   	       	}
   	       	else if(n==5)
   	       	{
   	       	}
   	       	else if(n==0)break;
   	       	else cout<<"警告警告，你输入了什么奇怪的东东ヾ(。￣—□—￣)ツ"<<endl;
   	       
  }
}