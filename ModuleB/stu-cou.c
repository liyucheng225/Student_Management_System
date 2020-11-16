#include "../Include/project.h"
extern int stunum;
extern int counum;
//学生选课函数实现
void stu_choosecou(void){
        while(1){
        printf("\n-----------------------欢迎进入选课系统---------------------------");
        printf("\n                         1.以学号选课");
        printf("\n                         2.以姓名选课");
        printf("\n                         3.退出!");
        printf("\n                       请输入序号（1-3）：");
        int num=-1;
        scanf("%d",&num);
        char str[5];
        if(num==-1){
            scanf("%s",str);
        }
        switch(num){
            case 1:
                idchoose_cou();
                break;
            case 2:
                nchoose_cou();
                break;
            case 3:
                printf("\n--------------退出-----------------------");
                return;
            default:
                printf("您输入的序号有错误，请重新输入1-6之间的数字:");
                break;
        }
        }

}
//学生选课信息函数定义
//1.以学号选课
void idchoose_cou(void){
    char *sid=(char *)malloc(sizeof(char)*10);
    char *cid=(char *)malloc(sizeof(char)*10);
    while(1){
        printf("\n请输入学生学号：");
        scanf("%s",sid);
        int flag1=0,flag2=0;
        int index1=0,index2=0;//获取输入姓名课程的下标
        int flag3=0,flag4=0;
        for(int i=0;i<stunum;i++){
            if(strcmp(stu[i].stu_ID,sid)==0){
                printf("\n学号存在");
                flag1=1;//学号存在，记flag1为1 
                index1=i;
                break;
            }           
        }
        if(flag1==0){ //学号不存在，进入死循环继续输入
			printf("\n学号不存在，请重新输入！"); 
            continue;
        }
        printf("\n请输入课程号:");
        scanf("%s",cid);
        for(int j=0;j<counum;j++){
            if(strcmp(cou[j].course_ID,cid)==0){
                printf("\n课程存在");
                if(atoi(cou[j].course_stu_limit)<=cou[j].cousel){
                    printf("该课程已满，请重新输入！");
                    flag3=1;//选择的课程选择人数已满，记flag3为1 
                }
            flag2=1;
            index2=j;
            break;
            }
        } 
        if(flag2==0){//课程号不存在,进入死循环继续输入 
        	printf("\n课程不存在，请重新输入！");
            continue;
        }
        
        if(flag3==1){//课程已满进入死循环继续 
            continue;
        }
        for(int k=0;k<stu[index1].count;k++){//遍历学生所选的课程数组 
            if(strcmp(stu[index1].choose_course[k],cou[index2].course_name)==0){//输入的课程号被该学生选过 
                flag4=1;//说明该课程已经被该学生选过，记flag4为1
                } 
        }
        if(flag4==1){//说明该课程已经被该学生选过
            printf("\n%s已经选过这门课了",sid);
            printf("\n选课不成功，按1继续选课，按其他键退出：");
        }
        if(flag4==0){//说明该课程没有被该学生选过，可以进行课程选择
            stu[index1].choose_course[stu[index1].count]=(char *)malloc(sizeof(char)*10);
            stu[index1].choose_course[stu[index1].count]=cou[index2].course_name;//将该课程的名字存入学生的课程数组 
            stu[index1].count++;
            cou[index2].cousel++;//该课程的所选人数加1
            stu[index1].allcredit+=atoi(cou[index2].course_credit);//该学生的总学分就把该课程的学分加上
            printf("\n选课成功，按1继续选课，按其他键退出：");
            new_stu();
            new_cou();
        }
        int key;
        fflush(stdin);
        scanf("%d",&key);
        if(key!=1){
            break;
        }    
    }
}

//2.以姓名选课
void nchoose_cou(void){
    char *sname=(char *)malloc(sizeof(char)*10);
    char *cid=(char *)malloc(sizeof(char)*10);
    while(1){
        printf("\n请输入学生姓名：");
        scanf("%s",sname);
        int flag1=0,flag2=0;
        int index1=0,index2=0;//获取输入姓名课程的下标
        int flag3=0,flag4=0;
        for(int i=0;i<stunum;i++){
            if(strcmp(stu[i].stu_name,sname)==0){
                printf("\n姓名存在");
                flag1=1;//姓名存在，记flag1为1 
                index1=i;
                break;
            }           
        }
        if(flag1==0){ //姓名不存在，进入死循环继续输入
			printf("\n姓名不存在，请重新输入！"); 
            continue;
        }
        printf("\n请输入课程号:");
        scanf("%s",cid);
        for(int j=0;j<counum;j++){
            if(strcmp(cou[j].course_ID,cid)==0){
                printf("\n课程存在");
                if(atoi(cou[j].course_stu_limit)<=cou[j].cousel){
                    printf("该课程已满，请重新输入！");
                    flag3=1;//选择的课程选择人数已满，记flag3为1 
                }
            flag2=1;
            index2=j;
            break;
            }
        } 
        if(flag2==0){//课程号不存在,进入死循环继续输入 
        	printf("\n课程不存在，请重新输入！");
            continue;
        }
        
        if(flag3==1){//课程已满进入死循环继续 
            continue;
        }
        for(int k=0;k<stu[index1].count;k++){//遍历学生所选的课程数组 
            if(strcmp(stu[index1].choose_course[k],cou[index2].course_name)==0){//输入的课程号被该学生选过 
                flag4=1;//说明该课程已经被该学生选过，记flag4为1
                } 
        }
        if(flag4==1){//说明该课程已经被该学生选过
            printf("%s\n已经选过这门课了",sname);
            printf("\n选课不成功，按1继续选课，按其他键退出：");
        }
        if(flag4==0){//说明该课程没有被该学生选过，可以进行课程选择
            stu[index1].choose_course[stu[index1].count]=(char *)malloc(sizeof(char)*10);
            stu[index1].choose_course[stu[index1].count]=cou[index2].course_name;//将该课程的名字存入学生的课程数组 
            stu[index1].count++;
            cou[index2].cousel++;//该课程的所选人数加1
            stu[index1].allcredit+=atoi(cou[index2].course_credit);//该学生的总学分就把该课程的学分加上
            printf("\n选课成功，按1继续选课，按其他键退出：");
            new_stu();
            new_cou();
        }
        int key;
        fflush(stdin);
        scanf("%d",&key);
        if(key!=1){
            break;
        }    
    }
}
