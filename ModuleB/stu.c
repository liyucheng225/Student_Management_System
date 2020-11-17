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
//1.显示学生信息函数定义
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

//2.增加学生信息函数定义
void insert_stu(void){  
        while(1){
             FILE *fp;
            char buf[1024];
            char *file1=(char *)malloc(sizeof(char)*30);
            printf("\n请输入要录入的文件名：");
            scanf("%s",file1);
            if((fp=fopen(file1,"r"))==0)
            {
                printf("\n无文件!\n");
                fclose(fp);
                continue ;
            }
            printf("\n录入的学生数据为：");
            printf("\n学号\t姓名\n");    
            while(!feof(fp))
            {
                fgets(buf,sizeof(buf),fp);
                fscanf(fp,"%s%s",stu[stunum].stu_ID,stu[stunum].stu_name);
                printf("%s\t%s\n",stu[stunum].stu_ID,stu[stunum].stu_name);
                stunum++;
            }
            fclose(fp);
            stunum-=1;
            for(int i=0;i<stunum;i++){
                stu[i].count=0;
                stu[i].allcredit=0;
            }
            printf("\n录入学生记录成功，按1继续录入，按其他键返回:");
            int flag;
            fflush(stdin);
            scanf("%d",&flag);
            if(flag!=1){
                break;
            }
        
    }
}
//3.删除学生信息函数定义
extern void write_stulog(int index,char ty[]);
void del_stu(char *id){
            int flag=0;
            for(int i=0;i<stunum;i++){
            	if(strcmp(id,stu[i].stu_ID)==0){
                    write_stulog(i,"删除");
            		for(int j=i;j<stunum-1;j++){
            			stu[j]=stu[j+1];
					}
					stunum--;
                    flag=1;
                    printf("删除成功");
                    new_stu();
					break;
				}
			} 
            if(flag==0){
                printf("学号不存在");
            }
}
//4.修改学生信息函数定义
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
//5.查询学生信息函数定义
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
void update_stu(int index){
            char *str=(char *)malloc(sizeof(char)*10);
            printf("\n请输入要修改的项目：");
            scanf("%s",str);
            if(strcmp(str,"学号")==0){
                printf("\n请输入要修改学号的内容：");
                char *id=(char *)malloc(sizeof(char)*10);
                scanf("%s",id);
                strcpy(stu[index].stu_ID,id);
                printf("\n修改成功！");
                write_stulog(index,"修改");
                new_stu();
            }
           else if(strcmp(str,"姓名")==0){
                printf("\n请输入要修改姓名的内容：");
                char *name=(char *)malloc(sizeof(char)*10);
                scanf("%s",name);
                strcpy(stu[index].stu_name,name);
                printf("\n修改成功！");
                write_stulog(index,"修改");
                new_stu();
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
                        write_stulog(index,"修改");
                        new_stu();
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
void new_stu(void){
    FILE *fp;
    fp=fopen("re-student.txt","w+");
    if(fp==NULL){
        printf("没有文件，打开文件失败！");
        fclose(fp);
        return;
    }
    fprintf(fp,"学号\t姓名\t\t所选课程\t\t总计学分");
    if(stunum==0){
        fclose(fp);
        return;
    }
    for (int i=0;i<stunum;i++){
        fprintf(fp,"\n%-10s%-9s\t",stu[i].stu_ID,stu[i].stu_name);
        fclose(fp);
        display_stu_cou(i);
        fp=fopen("re-student.txt","a+");
        fprintf(fp,"\t\t%-10d",stu[i].allcredit);
    }
    fclose(fp);
}
void display_stu_cou(int index){ 
            FILE *fp;
             fp=fopen("re-student.txt","a+");
                 if(fp==NULL){
                 printf("没有文件，打开文件失败！");
                 fclose(fp);
                 return;
                 }
             for(int i=0;i<stu[index].count;i++){
                fprintf(fp,"%s",stu[index].choose_course[i]);
             }
             fclose(fp);
}
void write_stulog(int index ,char ty[]){
         time_t t;
         struct tm *lt;
         time (&t);
         lt=gmtime(&t);
         FILE *fp;
         fp=fopen("log.log","a+");
         if(fp==NULL){
             printf("没有文件");
             fclose(fp);
             return;
         }
         fprintf(fp,"\n%d/%d/%d/%d:%d:%d%s学号是%s的学生",lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday,lt->tm_hour+8,lt->tm_min,lt->tm_sec,ty,stu[index].stu_ID);
         fclose(fp);
}         

