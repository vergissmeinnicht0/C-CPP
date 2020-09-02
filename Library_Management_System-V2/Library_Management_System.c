/**********源程序代码**********/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LONG sizeof(struct Book)
struct Book
{
	char title[100];
	char author[50];
	char press[100];
	char year[5];
	char claim_number[30];
	int collection;
	int can_borrow;
	char unit_price[10];
	char student_name[50];
	char sex[5];
	char student_id[20];
	long long int number;
};

/**********函数声明**********/
void main_meun();//【主界面函数】
void manager_menu();//【管理员功能界面函数】
void student_meun();//【学生功能界面函数】
int book_add(int back);//【新书信息录入函数】
int search_2(int back);//【图书信息查询（学生版）】
int search_1(int back);//【图书信息查询函数（管理员版）】
int search_number(int back);//【按编号查询函数（管理员版）】
int search_title(int back);//【按书名查询函数（管理员版）】
void search_menu();//【图书查询函数界面（管理员版）】
int book_delete(int back);//【图书信息删除函数】
int borrow(int back);//【办理借书手续函数】
int return_book(int back);//【办理还书手续函数】

/**********主函数**********/
int main()
{
	int a,b,c,z;
	int back=0,back2=0,back3=0;
	A:system("cls");//A为一个标志位，用于从子函数返回主界面
	back=0;back2=0;back3=0;
	main_meun();//【主界面函数】
	while(1)//主程序循环运行
	{
		scanf("%d",&a);
		switch(a)
		{
		case 1://进入管理员界面
			{
				printf("登陆密码【123】：");
				scanf("%d",&z);
				if(z!=123)goto A;
				B:system("cls");//B为一个标志位，用于从子函数返回管理员功能界面
				back=0;back2=0;back3=0;
				manager_menu();//【管理员功能界面函数】
				while(1)
				{
					scanf("%d",&b);
					switch(b)
					{
					case 1:{back2=book_add(back2);if(back2==1)goto B;}//进入新书信息录入
					case 2:{back2=search_1(back2);if(back2==1)goto B;}//进入图书信息查询
					case_3:{back2=book_delete(back2);if(back2==1)goto B;}//进入图书信息删除
					case 4:goto A;//返回主菜单
					case 0://退出系统
						{
							system("cls");
							printf(" ------------------------------------------------------------\n");
							printf("                   -=  感谢使用，再见！ =-                   \n");
							printf(" ------------------------------------------------------------\n");
							exit(0);
						}
					}
				}
			}break;
		case 2://进入学生界面
			{
				C:system("cls");//C为一个标志位，用于从子函数返回学生功能界面
				
				student_meun();//【学生功能界面函数】
				while(1)
				{
					scanf("%d",&c);
					switch(c)
					{
					case 1:{ back3=search_2(back3);if(back3==1)goto C; }//进入图书信息查询
					case 2:{ back3=borrow(back3);if(back3==1)goto C; }//办理借书手续
					case 3:{ back3=return_book(back3);if(back3==1)goto C; }//办理还书手续
					case 4:goto A;//返回主菜单
					case 0://退出系统
						{
							system("cls");
							printf(" ------------------------------------------------------------\n");
							printf("                   -=  感谢使用，再见！ =-                   \n");
							printf(" ------------------------------------------------------------\n");
							exit(0);
						}
					}
				}
			}break;
		case 0://退出系统
			{
				system("cls");
				printf(" ------------------------------------------------------------\n");
				printf("                   -=  感谢使用，再见！ =-                   \n");
				printf(" ------------------------------------------------------------\n");
				exit(0);
			}
		}
	}
}

/**********其他函数**********/

void main_meun()//【主界面函数】
{
	printf(" ============================================================\n");
	printf(" |                                                          |\n");
	printf(" |                   欢迎使用图书管理系统                   |\n");
	printf(" |                                                          |\n");
	printf(" |                                                          |\n");
	printf(" |     [1].管理员登陆    [2].学生登陆    [0].退出系统       |\n");
	printf(" |                                                          |\n");
	printf(" ============================================================\n");
	printf("请选择：");
}

void manager_menu()//【管理员功能界面函数】
{
	printf(" ============================================================\n");
	printf(" |                                                          |\n");
	printf(" |                    [1].新书信息录入                      |\n");
	printf(" |                                                          |\n");
	printf(" |                    [2].图书信息查询                      |\n");
	printf(" |                                                          |\n");
	printf(" |                    [3].图书信息删除                      |\n");
	printf(" |                                                          |\n");
	printf(" |                    [4].返回主菜单                        |\n");
	printf(" |                                                          |\n");
	printf(" |                    [0].退出系统                          |\n");
	printf(" |                                                          |\n");
	printf(" ============================================================\n");
	printf("请选择：");
}

void student_meun()//【学生功能界面函数】
{
    printf(" ============================================================\n");
	printf(" |                                                          |\n");
	printf(" |                    [1].图书信息查询                      |\n");
	printf(" |                                                          |\n");
	printf(" |                    [2].办理借书手续                      |\n");
	printf(" |                                                          |\n");
	printf(" |                    [3].办理还书手续                      |\n");
	printf(" |                                                          |\n");
	printf(" |                    [4].返回主菜单                        |\n");
	printf(" |                                                          |\n");
	printf(" |                    [0].退出系统                          |\n");
	printf(" |                                                          |\n");
	printf(" ============================================================\n");
	printf("请选择：");
}

int book_add(int back)//【新书信息录入函数】
{
	 FILE *fp;
	 struct Book *p1;
	 long long int a,b;
	 int n;
	 fp=fopen("Books_SQL.txt","a+");
	 if(fp==NULL){printf("数据库打开错误！请检查...\n");exit(0);}
	 while(1)
	 {
		A:system("cls");//A为一个标志位，用于返回本函数首界面
		p1=(struct Book*)malloc(LONG);
		fseek(fp,-11,SEEK_END);
		fscanf(fp,"%lld",&a);
		if(a<0)a=20011001;
		fseek(fp,0,SEEK_END);
		printf("上一本图书编号：%lld\n",a);
		printf("请输入新图书信息：\n");
		printf("===============================================================================\n");
		printf("书名                        作者    出版社              年份 索取号   单价 数量\n");	
		printf("-------------------------------------------------------------------------------\n");
		p1->number=a+1;
		strcpy(p1->student_id,"未知");
		strcpy(p1->student_name,"未知");
		strcpy(p1->sex,"未知");
		scanf("%s %s %s %s %s %s %d",p1->title,p1->author,p1->press,p1->year,p1->claim_number,p1->unit_price,&p1->collection);
		p1->can_borrow=p1->collection;
		fprintf(fp,"%s %s %s %s %s %s %d %d %s %s %s %lld\n",p1->title,p1->author,p1->press,p1->year,p1->claim_number,p1->unit_price,p1->collection,p1->can_borrow,p1->student_name,p1->sex,p1->student_id,p1->number);
		fflush(fp);
		if(1<p1->collection)
		{
			for(b=2;b<=p1->collection;b++)
			{
				p1->number=a+b;
				fprintf(fp,"%s %s %s %s %s %s %d %d %s %s %s %lld\n",p1->title,p1->author,p1->press,p1->year,p1->claim_number,p1->unit_price,p1->collection,p1->can_borrow,p1->student_name,p1->sex,p1->student_id,p1->number);
				fflush(fp);
			}
		}
		printf("\a");
		printf(" -------------------------------------------------------\n");
		printf("            [1].继续录入    [2].结束录入                \n");
		printf(" -------------------------------------------------------\n");
		printf("请选择：");
		scanf("%d",&n);
		switch(n)
		{
		case 1:goto A;
		case 2:{fclose(fp);back=1;return(back);}
		}
	 }
}

int search_2(int back)//【进入图书信息查询（学生版）】
{
	FILE *fp;
	char title[100];
	struct Book *p;
	int a1=0,b1;
	A:system("cls");//A为一个标志位，用于返回本函数首界面
	back=0;
	printf("请输入书名：");
	scanf("%s",title);
	fp=fopen("图书信息数据库.txt","r");
	if(fp==NULL){printf("数据库打开错误！请检查...\n");exit(0);}
	p=(struct Book*)malloc(LONG);
	while(!feof(fp))
		{
			fscanf(fp,"%s %s %s %s %s %s %d %d %s %s %s %lld\n",p->title,p->author,p->press,p->year,p->claim_number,p->unit_price,&p->collection,&p->can_borrow,p->student_name,p->sex,p->student_id,&p->number);
			if(strcmp(title,p->title)==0)
				{
					a1=1;			
					printf("===============================================================================\n");
					printf("书名                        作者    出版社             年份  索取号   馆藏 可借\n");			
					printf("-------------------------------------------------------------------------------\n");			
					printf("%-28s%-8s%-19s%-6s%-11s%-5d%d\n",p->title,p->author,p->press,p->year,p->claim_number,p->collection,p->can_borrow);
					break;
				}
		}
	if(a1==1)
	{
		fclose(fp);
		printf("\n");
		printf(" -------------------------------------------------------\n");
		printf("   [1].继续搜索   [2].返回学生功能菜单   [0].退出系统   \n");
		printf(" -------------------------------------------------------\n");
		printf("请选择：");
		scanf("%d",&b1);
		while(1)
		{
			switch(b1)
			{
			case 1:goto A;break;
			case 2:return(back=1);
			case 0:
				{
					system("cls");
					printf(" ------------------------------------------------------------\n");
					printf("                   -=  感谢使用，再见！ =-                   \n");
					printf(" ------------------------------------------------------------\n");
					exit(0);
				}
			}
		}
	}
	if(a1==0)
	{
		fclose(fp);
		printf("\a \n 未找到与条件相符的图书！\n\n");
		printf(" -------------------------------------------------------\n");
		printf("   [1].继续搜索   [2].返回学生功能菜单   [0].退出系统   \n");
		printf(" -------------------------------------------------------\n");
		printf("请选择：");
		scanf("%d",&b1);
		while(1)
		{
			switch(b1)
			{
			case 1:goto A;break;
			case 2:return(back=1);
			case 0:
				{
					system("cls");
					printf(" ------------------------------------------------------------\n");
					printf("                   -=  感谢使用，再见！ =-                   \n");
					printf(" ------------------------------------------------------------\n");
					exit(0);
				}
			}
		}
	}
}

int search_1(int back)//【进入图书信息查询函数（管理员版）】
{
	int a,back3;
    A:system("cls");//A为一个标志位，用于返回本函数首界面
	back=0;back3=0;
	search_menu();
	scanf("%d",&a);
	while(1)
	{
		switch(a)
		{
		case 1:{back3=search_number(back3);if(back3==1)goto A;}//进入编号查询
		case 2:{back3=search_title(back3);if(back3==1)goto A;}//进入书名查询
		case 3:return(back=1);
		}
	}
}
int search_number(int back)//【按编号查询函数（管理员版）】
{

	FILE *fp;
	long long int number;
	struct Book *p;
	int b1;
	A:system("cls");//A为一个标志位，用于返回本函数首界面
	back=0;
	printf("请输入图书编号（数字）：");
	scanf("%lld",&number);
	fp=fopen("图书信息数据库.txt","r");
	if(fp==NULL){printf("数据库打开错误！请检查...\n");exit(0);}
	p=(struct Book*)malloc(LONG);
	while(1)
		{
			if(feof(fp))
			{
				fclose(fp);
				printf("\a\n  未找到与条件相符的图书！\n\n");
				printf(" -------------------------------------------------------\n");
				printf("    [1].继续搜索   [2].返回上一级菜单   [0].退出系统    \n");
				printf(" -------------------------------------------------------\n");
				printf("请选择：");
				scanf("%d",&b1);
				while(1)
					{
						switch(b1)
						{
						case 1:goto A;break;
						case 2:return(back=1);
						case 0:
							{
								system("cls");
								printf(" ------------------------------------------------------------\n");
								printf("                   -=  感谢使用，再见！ =-                   \n");
								printf(" ------------------------------------------------------------\n");
								exit(0);
							}
						}
					}
			}
			fscanf(fp,"%s %s %s %s %s %s %d %d %s %s %s %lld\n",p->title,p->author,p->press,p->year,p->claim_number,p->unit_price,&p->collection,&p->can_borrow,p->student_name,p->sex,p->student_id,&p->number);
			if(number==p->number)
			{ 
				fclose(fp);		
				printf("===============================================================================\n\n");
				printf(" %-6s%-12lld%-8s%-12s%-6s%-8s%s%s\n\n","编号：",p->number,"索取号：",p->claim_number,"年份：",p->year,"单价：",p->unit_price);
				printf(" 书名：%s\n\n",p->title);
				printf(" %-6s%-12s%s%s\n\n","作者：",p->author,"出版社：",p->press);
				printf(" %-6s%-12d%s%d\n\n","馆藏：",p->collection,"可借：",p->can_borrow);
				printf(" 借书人信息||      %-6s%-10s%-6s%-7s%-7s%s\n\n","姓名：",p->student_name,"性别：",p->sex,"学号：",p->student_id);			
				printf("===============================================================================\n");
				printf(" -------------------------------------------------------\n");
				printf("    [1].继续搜索   [2].返回上一级菜单   [0].退出系统    \n");
				printf(" -------------------------------------------------------\n");
				printf("请选择：");
				scanf("%d",&b1);
					while(1)
						{
							switch(b1)
							{
							case 1:goto A;break;
							case 2:return(back=1);
							case 0:
								{
									system("cls");
									printf(" ------------------------------------------------------------\n");
									printf("                   -=  感谢使用，再见！ =-                   \n");
									printf(" ------------------------------------------------------------\n");
									exit(0);
								}
							}
						}
			}
		}
}

int search_title(int back)//【按书名查询函数（管理员版）】
{
	FILE *fp;
	char title[100];
	struct Book *p;
	int a1,b1;
	A:system("cls");//A为一个标志位，用于返回本函数首界面
	back=0;
	a1=0;
	printf("请输入书名：");
	scanf("%s",title);
	fp=fopen("图书信息数据库.txt","r");
	if(fp==NULL){printf("数据库打开错误！请检查...\n");exit(0);}
	p=(struct Book*)malloc(LONG);
	while(!feof(fp))
		{
			fscanf(fp,"%s %s %s %s %s %s %d %d %s %s %s %lld\n",p->title,p->author,p->press,p->year,p->claim_number,p->unit_price,&p->collection,&p->can_borrow,p->student_name,p->sex,p->student_id,&p->number);
			if(strcmp(title,p->title)==0)
				{
					a1=1;				
					printf("===============================================================================\n\n");
					printf(" %-6s%-12lld%-8s%-12s%-6s%-8s%s%s\n\n","编号：",p->number,"索取号：",p->claim_number,"年份：",p->year,"单价：",p->unit_price);
					printf(" 书名：%s\n",p->title);
					printf(" %-6s%-12s%s%s\n\n","作者：",p->author,"出版社：",p->press);
					printf(" %-6s%-12d%s%d\n","馆藏：",p->collection,"可借：",p->can_borrow);
					printf(" 借书人信息||      %-6s%-10s%-6s%-7s%-7s%s\n\n","姓名：",p->student_name,"性别：",p->sex,"学号：",p->student_id);				
					printf("===============================================================================\n");
				}
		}
	if(a1==1)
	{
		fclose(fp);
		printf(" -------------------------------------------------------\n");
		printf("    [1].继续搜索   [2].返回上一级菜单   [0].退出系统    \n");
		printf(" -------------------------------------------------------\n");
		printf("请选择：");
		scanf("%d",&b1);
		while(1)
		{
			switch(b1)
			{
			case 1:goto A;break;
			case 2:return(back=1);
			case 0:
				{
					system("cls");
					printf(" ------------------------------------------------------------\n");
					printf("                   -=  感谢使用，再见！ =-                   \n");
					printf(" ------------------------------------------------------------\n");
					exit(0);
				}
			}
		}
	}
	if(a1==0)
	{
		fclose(fp);
		printf("\a \n未找到与书名相符的图书！\n\n");
		printf(" -------------------------------------------------------\n");
		printf("    [1].继续搜索   [2].返回上一级菜单   [0].退出系统    \n");
		printf(" -------------------------------------------------------\n");
		printf("请选择：");
		scanf("%d",&b1);
		while(1)
		{
			switch(b1)
			{
			case 1:goto A;break;
			case 2:return(back=1);
			case 0:
				{
					system("cls");
					printf(" ------------------------------------------------------------\n");
					printf("                   -=  感谢使用，再见！ =-                   \n");
					printf(" ------------------------------------------------------------\n");
					exit(0);
				}
			}
		}
	}
}

void search_menu()//【图书查询函数界面（管理员版）】
{
    printf(" ============================================================\n");
	printf(" |                                                          |\n");
	printf(" |                    [1].按图书编号查询                    |\n");
	printf(" |                                                          |\n");
	printf(" |                    [2].按图书名称查询                    |\n");
	printf(" |                                                          |\n");
	printf(" |                    [3].返回上一级菜单                    |\n");
	printf(" |                                                          |\n");
	printf(" ============================================================\n");
	printf("请选择：");
}

int book_delete(int back)//【图书信息删除函数】
{
	FILE *fp;
	char title[100],d[100];
	struct Book n[1000];
	int i,j;
	struct Book *p;
	int a,b,c,e,f;
	A:system("cls");//A为一个标志位，用于返回本函数首界面
	back=0,i=0,j=0,b=0,a=0;
	printf("请输入书名：");
	scanf("%s",title);
	fp=fopen("图书信息数据库.txt","r");
	if(fp==NULL){printf("数据库打开错误！请检查...\n");exit(0);}
	p=(struct Book*)malloc(LONG);
	while(!feof(fp))
		{
			fscanf(fp,"%s %s %s %s %s %s %d %d %s %s %s %lld\n",p->title,p->author,p->press,p->year,p->claim_number,p->unit_price,&p->collection,&p->can_borrow,p->student_name,p->sex,p->student_id,&p->number);
			if(strcmp(title,p->title)==0)
				{
					a=1;
					if(strcmp(p->student_name,"未知")!=0)b=1;				
					printf("===============================================================================\n\n");
					printf(" %-6s%-12lld%-8s%-12s%-6s%-8s%s%s\n\n","编号：",p->number,"索取号：",p->claim_number,"年份：",p->year,"单价：",p->unit_price);
					printf(" 书名：%s\n",p->title);
					printf(" %-6s%-12s%s%s\n\n","作者：",p->author,"出版社：",p->press);
					printf(" %-6s%-12d%s%d\n","馆藏：",p->collection,"可借：",p->can_borrow);
					printf(" 借书人信息||      %-6s%-10s%-6s%-7s%-7s%s\n\n","姓名：",p->student_name,"性别：",p->sex,"学号：",p->student_id);				
					printf("===============================================================================\n");
				}
		}
	fclose(fp);
	if(b==1)
	{
		fclose(fp);
		printf("\a \n\n此书正在出借，无法删除信息！\n\n");
		printf(" -------------------------------------------------------\n");
		printf("   [1].重新搜索  [2].返回管理员功能菜单  [0].退出系统   \n");
		printf(" -------------------------------------------------------\n");
		printf("请选择：");
		scanf("%d",&b);
		while(1)
		{
			switch(b)
			{
			case 1:goto A;break;
			case 2:return(back=1);
			case 0:
				{
					system("cls");
					printf(" ------------------------------------------------------------\n");
					printf("                   -=  感谢使用，再见！ =-                   \n");
					printf(" ------------------------------------------------------------\n");
					exit(0);
				}
			}
		}
	}
	if(a==1&&b!=1)
	{
		printf("\a\n\n  确认删除？\n");
		printf(" -------------------------------------------------------\n");
		printf("                 [1].是      [2].否                     \n");
		printf(" -------------------------------------------------------\n");
		scanf("%d",&c);
		while(1)
		{
			switch(c)
			{
			case 1:
				{
					fp=fopen("图书信息数据库.txt","r");
					if(fp==NULL){printf("数据库打开错误！请检查...\n");exit(0);}
					while(!feof(fp))
					{
						fscanf(fp,"%s %s %s %s %s %s %d %d %s %s %s %lld\n",&n[i].title,&n[i].author,&n[i].press,&n[i].year,&n[i].claim_number,&n[i].unit_price,&n[i].collection,&n[i].can_borrow,&n[i].student_name,&n[i].sex,&n[i].student_id,&n[i].number);
						if(strcmp(title,n[i].title)==0)
							{						   strcpy(d,n[i].press);strcpy(n[i].press,n[i].title);strcpy(n[i].title,d);
								e=n[i].number/10000;n[i].collection=e;
								f=n[i].number%10000;n[i].can_borrow=f;
								n[i].number=1234567890;
							}
						i+=1;
					}
					j=i;
					fclose(fp);
					fp=fopen("图书信息数据库.txt","w");
					if(fp==NULL){printf("数据库打开错误！请检查...\n");exit(0);}
					i=0;
					while(j!=0)
					{
						fprintf(fp,"%s %s %s %s %s %s %d %d %s %s %s %lld\n",n[i].title,n[i].author,n[i].press,n[i].year,n[i].claim_number,n[i].unit_price,n[i].collection,n[i].can_borrow,n[i].student_name,n[i].sex,n[i].student_id,n[i].number);
						fflush(fp);
						i+=1;
						j-=1;
					}			
					fclose(fp);
					system("cls");
					printf("  \n 删除成功！\n\n");
					printf(" -------------------------------------------------------\n");
					printf("   [1].继续删除  [2].返回管理员功能菜单  [0].退出系统   \n");
					printf(" -------------------------------------------------------\n");
					printf("请选择：");
					scanf("%d",&b);
					while(1)
					{
						switch(b)
							{
							case 1:goto A;break;
							case 2:return(back=1);
							case 0:
								{
									system("cls");
									printf(" ------------------------------------------------------------\n");
									printf("                   -=  感谢使用，再见！ =-                   \n");
									printf(" ------------------------------------------------------------\n");
									exit(0);
								}
							}
					}
				}
			case 2:return(back=1);
			}
		}
	}
	if(a!=1)
	{
		fclose(fp);
		printf("\a \n 未找到与书名相符的图书！\n\n");
		printf(" -------------------------------------------------------\n");
		printf("   [1].重新搜索  [2].返回管理员功能菜单  [0].退出系统   \n");
		printf(" -------------------------------------------------------\n");
		printf("请选择：");
		scanf("%d",&b);
		while(1)
		{
			switch(b)
			{
			case 1:goto A;break;
			case 2:return(back=1);
			case 0:
				{
					system("cls");
					printf(" ------------------------------------------------------------\n");
					printf("                   -=  感谢使用，再见！ =-                   \n");
					printf(" ------------------------------------------------------------\n");
					exit(0);
				}
			}
		}
	}
}

int borrow(int back)//【办理借书手续函数】
{
	FILE *fp;
	char title[100];
	char student_name[50],sex[5],student_id[20];
	struct Book *p,n[1000];
	int a,b,c,d,i,j;
	A:system("cls");//A为一个标志位，用于返回本函数首界面
	back=0;a=0;b=0;i=0;j=0;d=0;
	printf("请输入书名：");
	scanf("%s",title);
	fp=fopen("图书信息数据库.txt","r");
	if(fp==NULL){printf("数据库打开错误！请检查...\n");exit(0);}
	p=(struct Book*)malloc(LONG);
	while(!feof(fp))
		{
			fscanf(fp,"%s %s %s %s %s %s %d %d %s %s %s %lld\n",p->title,p->author,p->press,p->year,p->claim_number,p->unit_price,&p->collection,&p->can_borrow,p->student_name,p->sex,p->student_id,&p->number);
			if(strcmp(title,p->title)==0)
				{
					a=1;
					if(p->can_borrow!=0)b=1;			printf("===============================================================================\n");
	printf("书名                        作者    出版社             年份  索取号   馆藏 可借\n");
					printf("-------------------------------------------------------------------------------\n");				printf("%-28s%-8s%-19s%-6s%-11s%-5d%d\n",p->title,p->author,p->press,p->year,p->claim_number,p->collection,p->can_borrow);
					break;
				}
		}
	if(a!=1)
	{
		fclose(fp);
		printf("\a \n 无该书信息！\n\n");
		printf(" -------------------------------------------------------\n");
		printf("   [1].继续搜索   [2].返回学生功能菜单   [0].退出系统   \n");
		printf(" -------------------------------------------------------\n");
		printf("请选择：");
		scanf("%d",&c);
		while(1)
		{
			switch(c)
			{
			case 1:goto A;
			case 2:return(back=1);
			case 0:
				{
					system("cls");
					printf(" ------------------------------------------------------------\n");
					printf("                   -=  感谢使用，再见！ =-                   \n");
					printf(" ------------------------------------------------------------\n");
					exit(0);
				}
			}
		}
	}
	if(b!=1)
	{
		fclose(fp);
		printf("\a \n 无法办理该书借阅手续！\n\n");
		printf(" -------------------------------------------------------\n");
		printf("   [1].继续搜索   [2].返回学生功能菜单   [0].退出系统   \n");
		printf(" -------------------------------------------------------\n");
		printf("请选择：");
		scanf("%d",&c);
		while(1)
		{
			switch(c)
			{
			case 1:goto A;
			case 2:return(back=1);
			case 0:
				{
					system("cls");
					printf(" ------------------------------------------------------------\n");
					printf("                   -=  感谢使用，再见！ =-                   \n");
					printf(" ------------------------------------------------------------\n");
					exit(0);
				}
			}
		}
	}
	if(b==1)
	{
		printf("\a\n\n 是否办理该书借书手续？\n");
		printf(" -------------------------------------------------------\n");
		printf("                   [1].是      [2].否                   \n");
		printf(" -------------------------------------------------------\n");
		scanf("%d",&c);
		while(1)
		{
			switch(c)
			{
			case 1:
				{
					system("cls");
					printf("请输入你的个人信息：\n");
					printf(" =======================================================\n");
					printf(" 姓名       性别   学号                                 \n");
					printf(" -------------------------------------------------------\n");
					scanf("%s %s %s",student_name,sex,student_id);
					fp=fopen("图书信息数据库.txt","r");
					if(fp==NULL){printf("数据库打开错误！请检查...\n");exit(0);}
					while(!feof(fp))
					{
						fscanf(fp,"%s %s %s %s %s %s %d %d %s %s %s %lld\n",&n[i].title,&n[i].author,&n[i].press,&n[i].year,&n[i].claim_number,&n[i].unit_price,&n[i].collection,&n[i].can_borrow,&n[i].student_name,&n[i].sex,&n[i].student_id,&n[i].number);
						if(strcmp(title,n[i].title)==0)
						{
							if(d!=1&&strcmp(n[i].student_name,"未知")==0)
							{
								strcpy(n[i].student_name,student_name);
								strcpy(n[i].sex,sex);
								strcpy(n[i].student_id,student_id);
								d=1;
							}
							n[i].can_borrow-=1;
						}
						i+=1;
					}
					fclose(fp);
					j=i;
					fp=fopen("图书信息数据库.txt","w");
					if(fp==NULL){printf("数据库打开错误！请检查...\n");exit(0);}
					i=0;
					while(j!=0)
					{
						fprintf(fp,"%s %s %s %s %s %s %d %d %s %s %s %lld\n",n[i].title,n[i].author,n[i].press,n[i].year,n[i].claim_number,n[i].unit_price,n[i].collection,n[i].can_borrow,n[i].student_name,n[i].sex,n[i].student_id,n[i].number);
						fflush(fp);
						i+=1;j-=1;
					}			
					fclose(fp);
					system("cls");
					printf("  \n 借书办理成功！\n\n");
					printf(" -------------------------------------------------------\n");
					printf("    [1].继续借书  [2].返回学生功能菜单  [0].退出系统    \n");
					printf(" -------------------------------------------------------\n");
					printf("请选择：");
					scanf("%d",&c);
					while(1)
					{
						switch(c)
							{
							case 1:goto A;break;
							case 2:return(back=1);
							case 0:
								{
									system("cls");
									printf(" ------------------------------------------------------------\n");
									printf("                   -=  感谢使用，再见！ =-                   \n");
									printf(" ------------------------------------------------------------\n");
									exit(0);
								}
							}
					}
				}
			case 2:return(back=1);
			}
		}
	}
}

int return_book(int back)//【办理还书手续函数】
{
	FILE *fp;
	char title[100];
	char student_name[50];
	struct Book *p,n[1000];
	int a,b,c,d,i,j;
	A:system("cls");//A为一个标志位，用于返回本函数首界面
	back=0;a=0;b=0;i=0;j=0;d=0;
	printf("请输入你的姓名：");
	scanf("%s",student_name);
	fp=fopen("图书信息数据库.txt","r");
	if(fp==NULL){printf("数据库打开错误！请检查...\n");exit(0);}
	p=(struct Book*)malloc(LONG);
    printf("你目前的借书情况：\n");
	printf("===============================================================================\n");
	printf("书名                        作者    出版社             年份  索取号   馆藏 可借\n");
	printf("-------------------------------------------------------------------------------\n");
	while(!feof(fp))
		{
			fscanf(fp,"%s %s %s %s %s %s %d %d %s %s %s %lld\n",p->title,p->author,p->press,p->year,p->claim_number,p->unit_price,&p->collection,&p->can_borrow,p->student_name,p->sex,p->student_id,&p->number);
			if(strcmp(student_name,p->student_name)==0)
				{
					a=1;
	printf("%-28s%-8s%-19s%-6s%-11s%-5d%d\n",p->title,p->author,p->press,p->year,p->claim_number,p->collection,p->can_borrow);
					printf("-------------------------------------------------------------------------------\n");
				}
		}
	fclose(fp);
	if(a!=1)
	{
		printf("你目前没有借书记录！\n");
		printf(" -------------------------------------------------------\n");
		printf("          [1].返回学生功能菜单   [0].退出系统           \n");
		printf(" -------------------------------------------------------\n");
		printf("请选择：");
		scanf("%d",&c);
		while(1)
		{
			switch(c)
			{
			case 1:return(back=1);
			case 0:
				{
					system("cls");
					printf(" ------------------------------------------------------------\n");
					printf("                   -=  感谢使用，再见！ =-                   \n");
					printf(" ------------------------------------------------------------\n");
					exit(0);
				}
			}
		}
	}
	if(a==1)
	{
		printf("\n请输入所还图书书名（每次一种）：");
		scanf("%s",title);
		printf("\a\n\n 是否确认办理该书还书手续？\n");
		printf(" -------------------------------------------------------\n");
		printf("                   [1].是      [2].否                   \n");
		printf(" -------------------------------------------------------\n");
		printf("请输入：");
		scanf("%d",&c);
		while(1)
		{
			switch(c)
			{
			case 1:
				{
					system("cls");
					fp=fopen("图书信息数据库.txt","r");
					if(fp==NULL){printf("数据库打开错误！请检查...\n");exit(0);}
					while(!feof(fp))
					{
						fscanf(fp,"%s %s %s %s %s %s %d %d %s %s %s %lld\n",&n[i].title,&n[i].author,&n[i].press,&n[i].year,&n[i].claim_number,&n[i].unit_price,&n[i].collection,&n[i].can_borrow,&n[i].student_name,&n[i].sex,&n[i].student_id,&n[i].number);
						if(strcmp(title,n[i].title)==0)
						{
						if(strcmp(n[i].student_name,student_name)==0)
							{
								strcpy(n[i].student_name,"未知");
								strcpy(n[i].sex,"未知");
								strcpy(n[i].student_id,"未知");
							}
							n[i].can_borrow+=1;
						}
						i+=1;
					}
					fclose(fp);
					j=i;
					fp=fopen("图书信息数据库.txt","w");
					if(fp==NULL){printf("数据库打开错误！请检查...\n");exit(0);}
					i=0;
					while(j!=0)
					{
						fprintf(fp,"%s %s %s %s %s %s %d %d %s %s %s %lld\n",n[i].title,n[i].author,n[i].press,n[i].year,n[i].claim_number,n[i].unit_price,n[i].collection,n[i].can_borrow,n[i].student_name,n[i].sex,n[i].student_id,n[i].number);
						fflush(fp);
						i+=1;j-=1;
					}			
					fclose(fp);
					system("cls");
					printf("  \n 还书办理成功！\n\n");
					printf(" -------------------------------------------------------\n");
					printf("    [1].继续还书  [2].返回学生功能菜单  [0].退出系统    \n");
					printf(" -------------------------------------------------------\n");
					printf("请选择：");
					scanf("%d",&c);
					while(1)
					{
						switch(c)
							{
							case 1:goto A;break;
							case 2:return(back=1);
							case 0:
								{
									system("cls");
									printf(" ------------------------------------------------------------\n");
									printf("                   -=  感谢使用，再见！ =-                   \n");
									printf(" ------------------------------------------------------------\n");
									exit(0);
								}
							}
					}
				}
			case 2:return(back=1);
			}
		}
	}
}

