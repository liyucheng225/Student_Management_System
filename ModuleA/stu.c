#include "../Include/project.h"
extern int stunum;
extern int counum;
//学生信息函数实现
void stu_information(void){
        while(1){
        printf("\n-----------------------欢迎进入选课系统---------------------------");
        printf("\n                         1.显示学生信息");
        printf("\n                         2.增加学生信息");
        printf("\n                         3.删除学生信息");
        printf("\n                         4.修改学生信息");
        printf("\n                         5.查询学生信息");
        printf("\n                         6.退出!");
        printf("\n                       请输入序号（1-6）：");
        int num=-1;
        scanf("%d",&num);
        char str[5];
        if(num==-1){
            scanf("%s",str);
        }
        switch(num){
            case 1:
                display_stu();
                break;
            case 2:
                insert_stu();
                break;
            case 3:
                while(1){
            		char *cid=(char *)malloc(sizeof(char)*10); 
            		printf("请输入要删除的学号：");
            		scanf("%s",cid);
               		del_stu(cid); 
               		printf("\n按1继续删除，按其他键返回！");
                	int flag;
            		fflush(stdin);
            		scanf("%d",&flag);
            		if(flag!=1){
                		break;
            		}
            	}
                break;
            case 4:
            	while(1){
            		char *id=(char *)malloc(sizeof(char)*10); 
            		char *name=(char *)malloc(sizeof(char)*10); 
                    printf("\n请选择1以学号修改2以姓名修改：");
                    int num;
                    scanf("%d",&num);
                    if(num==1){
            		    printf("\n请输入要修改的学号：");
            		    scanf("%s",id);
               		    update_stu_id(id);
                    }
                    else if(num==2){
            		    printf("\n请输入要修改的姓名：");
            		    scanf("%s",name);
               		    update_stu_name(name);
                    }
                    else{
                    	printf("输入错误");
                        break;
                    }
               	    printf("\n按1继续修改，按其他键返回：");
                	int flag;
            		fflush(stdin);
            		scanf("%d",&flag);
            		if(flag!=1){
                		break;
            		}
            	}
                break;
                break;
            case 5:
                while(1){
            		char *sid=(char *)malloc(sizeof(char)*10); 
            		printf("请输入要查询的学号：");
            		scanf("%s",sid);
               		select_stu(sid);
               		printf("\n按1继续查询，按其他键返回:");
                	int flag;
            		fflush(stdin);
            		scanf("%d",&flag);
            		if(flag!=1){
                		break;
            		}
            	}
                break;
            case 6:
                printf("\n--------------退出-----------------------");
                return;
            default:
                printf("您输入的序号有错误，请重新输入1-6之间的数字！");
                break;
        }
        }
}
//1.显示学生信息函数实现
void display_stu(void){
        printf("\n-----------------------欢迎进入选课系统---------------------------");
        printf("\n学号\t姓名\t\t所选课程\t\t总计学分");
        for(int i=0;i<stunum;i++){
            if(stu[i].count>0){
            printf("\n%-10s%-9s\t",stu[i].stu_ID,stu[i].stu_name);
            display_stu_cou2(i);
            printf("\t\t%-10d",stu[i].allcredit);
            }
            else{
            printf("\n%s\t%s",stu[i].stu_ID,stu[i].stu_name); 
            }
        }
    }

//2.增加学生信息函数实现
void insert_stu(void){  
    while(1){
    	 printf("\n学号\t姓名\n");    
        scanf("%s%s",stu[stunum].stu_ID,stu[stunum].stu_name);
        int i;
        int j=-1;//用来继续判断是否重复
        for(int i=0;i<stunum;i++){
            if(stunum==0){
                break;
            }
            if(!strcmp(stu[i].stu_ID,stu[stunum].stu_ID)){
                printf("\n您已经添加过此条记录，请重新添加:");
                j=1;
                break;
            }
        }
        if(j==1){
            continue;
        }
            printf("\n录入学生记录成功，按1继续录入，按其他键返回:");
             stunum++;
            stu[stunum].count=0;
            int flag;
            fflush(stdin);
            scanf("%d",&flag);
            if(flag!=1){
                break;
            }
        
    }
}
//3.删除学生信息函数实现
void del_stu(char *id){
            int flag=0;
            for(int i=0;i<stunum;i++){
            	if(strcmp(id,stu[i].stu_ID)==0){
            		for(int j=i;j<stunum-1;j++){
            			stu[j]=stu[j+1];
					}
					stunum--;
                    flag=1;
                    printf("删除成功");
					break;
				}
			} 
            if(flag==0){
                printf("课程号不存在");
            }
}
//4.修改学生信息函数实现-学号
void update_stu_id(char *sid){
            int index=0;
            int flag=0;
            for(int i=0;i<stunum;i++){
                if(strcmp(sid,stu[i].stu_ID)==0){
                    printf("\n学号\t姓名\t\t所选课程\t\t总计学分");
                    if(stu[i].count>0){
                    printf("\n%-10s%-9s\t",stu[i].stu_ID,stu[i].stu_name);
                    display_stu_cou2(i);
                    printf("\t\t%-10d",stu[i].allcredit);
                    }
                    else{
                    printf("\n%s\t%s",stu[i].stu_ID,stu[i].stu_name); 
                    }
                    index=i;
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                printf("学号不存在");
                return;
            }
            update_stu(index);
}
//修改学生信息实现-性名
void update_stu_name(char *name){
            int index=0;
            int flag=0;
            for(int i=0;i<stunum;i++){
                if(strcmp(name,stu[i].stu_name)==0){
                    printf("\n学号\t姓名\t\t所选课程\t\t总计学分");
                    if(stu[i].count>0){
                    printf("\n%-10s%-9s\t",stu[i].stu_ID,stu[i].stu_name);
                    display_stu_cou2(i);
                    printf("\t\t%-10d",stu[i].allcredit);
                    }
                    else{
                    printf("\n%s\t%s",stu[i].stu_ID,stu[i].stu_name); 
                    }
                    index=i;
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                printf("学号不存在");
                return;
            }
            update_stu(index);

}
//5.查询学生信息函数实现
void select_stu(char *id){
                int flag=0;
                for(int i=0;i<stunum;i++){
                	if(strcmp(id,stu[i].stu_ID)==0){
                         printf("\n学号\t姓名\t\t所选课程\t\t总计学分");
                         if(stu[i].count>0){
                             printf("\n%-10s%-9s\t",stu[i].stu_ID,stu[i].stu_name);
                             display_stu_cou2(i);
                             printf("\t\t%-10d",stu[i].allcredit);
                         }
                         else{
                             printf("\n%s\t%s",stu[i].stu_ID,stu[i].stu_name); 
                         }
                        flag=1;
                		 break;
					}
				}
                if(flag==0){
                    printf("学号不存在");
                }
}
void display_stu_cou2(int index){//根据学生数组序号展示学生所选课程的名字 
             for(int i=0;i<stu[index].count;i++){
                printf("%s",stu[index].choose_course[i]);
                if(i!=stu[index].count-1){
                    printf("\\");
                }
             }
}
void update_stu(int index){//修改学生的属性函数实现
            char *str=(char *)malloc(sizeof(char)*10);
            printf("\n请输入要修改的项目：");
            scanf("%s",str);
            if(strcmp(str,"学号")==0){
                printf("\n请输入要修改学号的内容：");
                char *id=(char *)malloc(sizeof(char)*10);
                scanf("%s",id);
                strcpy(stu[index].stu_ID,id);
                printf("\n修改成功！");
            }
           else if(strcmp(str,"姓名")==0){
                printf("\n请输入要修改姓名的内容：");
                char *name=(char *)malloc(sizeof(char)*10);
                scanf("%s",name);
                strcpy(stu[index].stu_name,name);
                printf("\n修改成功！");
            }
            else if(strcmp(str,"所选课程")==0){
                int flag=0;
                printf("\n所选课程为：");
                display_stu_cou2(index);
                printf("\n请输入要删除的课程名：");
                char *dcou=(char *)malloc(sizeof(char)*10);
                scanf("%s",dcou);
                for(int i=0;i<stu[index].count;i++){
                    if(strcmp(dcou,stu[index].choose_course[i])==0){
                        stu[index].choose_course[i]=stu[index].choose_course[i+1];
                        stu[index].count--;
                        flag=1;
                        printf("删除成功");
                    }
                }
                if(flag==0){
                    printf("课程名不存在");
                }
            }
            else{
                printf("\n没有这个选项或者此项目无法修改，请重新输入：");
            }
}
