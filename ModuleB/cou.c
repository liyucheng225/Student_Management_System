#include "../Include/project.h"
extern int stunum;
extern int counum;
//课程信息函数实现
void cou_information(void){
        while(1){
        printf("\n-----------------------欢迎进入选课系统---------------------------");
        printf("\n                         1.显示课程信息");
        printf("\n                         2.增加课程信息");
        printf("\n                         3.删除课程信息");
        printf("\n                         4.修改课程信息");
        printf("\n                         5.查询课程信息");
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
                display_cou();
                break;
            case 2:
                insert_cou();
                break;
            case 3:
                while(1){
            		char *cid=(char *)malloc(sizeof(char)*10); 
            		printf("请输入要删除的课程号：");
            		scanf("%s",cid);
               		del_cou(cid); 
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
            		char *cid=(char *)malloc(sizeof(char)*10); 
            		char *cname=(char *)malloc(sizeof(char)*10); 
                    printf("\n请选择1以课程号修改，2以课程名修改：");
                    int num;
                    scanf("%d",&num);
                    if(num==1){
            		    printf("\n请输入要修改的课程号：");
            		    scanf("%s",cid);
               		    update_cou_id(cid);
                    }
                    else if(num==2){
            		    printf("\n请输入要修改的课程名：");
            		    scanf("%s",cname);
               		    update_cou_name(cname);
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
            case 5:
            	while(1){
            		char *cid=(char *)malloc(sizeof(char)*10); 
            		printf("请输入要查询的课程号：");
            		scanf("%s",cid);
               		select_cou(cid);
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
                printf("退出！");
                return;
            default:
                printf("您输入的序号有错误，请重新输入1-6之间的数字！");
                break;
        }
        }

}
//课程信息操作函数定义
//1.显示课程信息函数定义
void display_cou(void){
        printf("\n-----------------------欢迎进入选课系统---------------------------");
        printf("\n课程号\t课程名\t性质\t学时\t学分\t所选人数\t人数限制");
        for(int i=0;i<counum;i++){
          printf("\n%s\t %s\t %s\t %s\t %s\t %d\t\t  %s",cou[i].course_ID,cou[i].course_name,cou[i].course_nature,cou[i].course_time,cou[i].course_credit,cou[i].cousel,cou[i].course_stu_limit); 
        }
}
//2.增加课程信息函数定义
void insert_cou(void){   
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
            printf("\n录入的课程数据为：");
        	printf("\n课程号\t课程名\t性质\t学时\t学分\t人数限制\n");
            while(!feof(fp))
            {
                fgets(buf,sizeof(buf),fp);
                fscanf(fp,"\n%s\t%s\t%s\t%s\t%s\t%s",cou[counum].course_ID,cou[counum].course_name,cou[counum].course_nature,cou[counum].course_time,cou[counum].course_credit,cou[counum].course_stu_limit);
                printf("\n%s\t%s\t%s\t%s\t%s\t%s",cou[counum].course_ID,cou[counum].course_name,cou[counum].course_nature,cou[counum].course_time,cou[counum].course_credit,cou[counum].course_stu_limit);
                counum++;
            }
            counum--;
            for(int i=0;i<counum;i++){
                cou[counum].cousel=0;
            }
            fclose(fp);
            printf("\n录入数据成功，按1继续录入或者任意键返回：\n");
            int flag;
            fflush(stdin);
            scanf("%d",&flag);
            if(flag!=1){
                break;
            }
        }
}
//3.删除课程信息函数定义
void del_cou(char *id){
            int flag=0;
            for(int i=0;i<counum;i++){
            	if(strcmp(id,cou[i].course_ID)==0){
                    write_coulog(i,"删除");
            		for(int j=i;j<counum-1;j++){
            			cou[j]=cou[j+1];
					}
					counum--;
                    flag=1;
                    printf("课程号删除成功");
                    new_cou();
					break;
				}
			}
            if(flag==0){
                printf("课程号不存在");
            }

}
//4.修改课程信息函数定义
void update_cou_id(char *cid){
            int index=0;
            int flag1=0;
            for(int i=0;i<counum;i++){
                if(strcmp(cid,cou[i].course_ID)==0){
            		printf("\n课程号\t课程名\t性质\t学时\t学分\t所选人数\t人数限制");
 					printf("\n%s\t %s\t %s\t %s\t %s\t %d\t\t  %s",cou[i].course_ID,cou[i].course_name,cou[i].course_nature,cou[i].course_time,cou[i].course_credit,cou[i].cousel,cou[i].course_stu_limit);
                    index=i;
                    flag1=1;
                    break;
                }
            }
            if(flag1==0){
            	printf("课程号不存在");
                return;
            }
            update_cou(index);
}
void update_cou_name(char *cname){
            int index=0;
            int flag1=0;
            for(int i=0;i<counum;i++){
                if(strcmp(cname,cou[i].course_name)==0){
            		printf("\n课程号\t课程名\t性质\t学时\t学分\t所选人数\t人数限制");
 					printf("\n%s\t %s\t %s\t %s\t %s\t %d\t\t  %s",cou[i].course_ID,cou[i].course_name,cou[i].course_nature,cou[i].course_time,cou[i].course_credit,cou[i].cousel,cou[i].course_stu_limit); 
                    index=i;
                    flag1=1;
                    break;
                }
            }
            if(flag1==0){
            	printf("课程名不存在");
                return;
            }
            update_cou(index);

}
//5.查询课程信息函数定义
void select_cou(char *id){
            int flag=0;
            for(int i=0;i<counum;i++){
            	if(strcmp(id,cou[i].course_ID)==0){
            			printf("\n课程号\t课程名\t性质\t学时\t学分\t所选人数\t人数限制");
 						printf("\n%s\t %s\t %s\t %s\t %s\t %d\t\t  %s",cou[i].course_ID,cou[i].course_name,cou[i].course_nature,cou[i].course_time,cou[i].course_credit,cou[i].cousel,cou[i].course_stu_limit); 						break;
                        flag=1;
                        break;
				}
			}			
            if(flag==0){
                printf("课程号不存在");
            }
}
void update_cou(int index){
            char *str=(char *)malloc(sizeof(char)*10);
            printf("\n请输入要修改的项目：");
            scanf("%s",str);
            if(strcmp(str,"课程号")==0){
                printf("\n请输入要修改课程号的内容：");
                char *id=(char *)malloc(sizeof(char)*10);
                scanf("%s",id);
                strcpy(cou[index].course_ID,id);
                printf("\n修改成功！");
                new_cou();
                write_coulog(index,"修改");
            }
           else if(strcmp(str,"课程名")==0){
                printf("\n请输入要修改姓名的内容：");
                char *name=(char *)malloc(sizeof(char)*10);
                scanf("%s",name);
                strcpy(cou[index].course_name,name);
                printf("\n修改成功！");
                new_cou();
                write_coulog(index,"修改");
            }
            else if(strcmp(str,"性质")==0){
                printf("\n请输入要修改性质的内容：");
                char *nature=(char *)malloc(sizeof(char)*10);
                scanf("%s",nature);
                strcpy(cou[index].course_nature,nature);
                printf("\n修改成功！");
                new_cou();
                write_coulog(index,"修改");
            }
            else if(strcmp(str,"学时")==0){
                printf("\n请输入要修改学时的内容：");
                char *time1=(char *)malloc(sizeof(char)*10);
                scanf("%s",time1);
                strcpy(cou[index].course_time,time1);
                printf("\n修改成功！");
                new_cou();
                write_coulog(index,"修改");
            }
            else if(strcmp(str,"学分")==0){
                printf("\n请输入要修改的内容：");
                char *credit=(char *)malloc(sizeof(char)*10);
                scanf("%s",credit);
                strcpy(cou[index].course_credit,credit);
                printf("\n修改成功！");
                new_cou();
                write_coulog(index,"修改");
            }
            else if(strcmp(str,"人数限制")==0){
                printf("\n请输入要修改的内容：");
                char *limit=(char *)malloc(sizeof(char)*10);
                scanf("%s",limit);
                strcpy(cou[index].course_stu_limit,limit);
                printf("\n修改成功！");
                new_cou();
                write_coulog(index,"修改");
            }
            else{
                printf("\n没有这个选项或者此项目无法修改，请重新输入：");
            }
}
void new_cou(void){
    FILE *fp;
    fp=fopen("re-course.txt","w+");
    if(fp==NULL){
        printf("没有文件，打开文件失败！");
        fclose(fp);
        return;
    }
    fprintf(fp,"\n课程号\t课程名\t性质\t学时\t学分\t所选人数\t人数限制");
    if(counum==0){
        fclose(fp);
        return;
    }
    for (int i=0;i<counum;i++){
          fprintf(fp,"\n%s\t %s\t %s\t %s\t %s\t %d\t\t  %s",cou[i].course_ID,cou[i].course_name,cou[i].course_nature,cou[i].course_time,cou[i].course_credit,cou[i].cousel,cou[i].course_stu_limit); 
    }
    fclose(fp);
}
void write_coulog(int index ,char ty[]){
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
         fprintf(fp,"\n%d/%d/%d/%d:%d:%d%s课程号是%s的课程",lt->tm_year+1900,lt->tm_mon+1,lt->tm_mday,lt->tm_hour+8,lt->tm_min,lt->tm_sec,ty,cou[index].course_ID);
         fclose(fp);
}         

