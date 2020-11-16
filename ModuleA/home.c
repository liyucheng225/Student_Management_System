#include "../Include/project.h"
extern int stunum;
extern int counum;
//-------------------------------主目录
//home函数实现
void home(void){
    while(1){
        printf("\n-----------------------欢迎进入选课系统---------------------------");
        printf("\n                   请选择你要进行的操作：");
        printf("\n                       1.学生信息");
        printf("\n                       2.课程信息");
        printf("\n                       3.学生选课");
        printf("\n                       4.退出系统");
        printf("\n                   请输入序号（1-4）：");
        int num=-1;
        scanf("%d",&num);
        char str[5];
        if(num==-1){
            scanf("%s",str);
        }

        switch(num){
             case 1:
                //1.学生信息
                stu_information();
                break;
            case 2:
                //2.课程信息
                cou_information();
                break;
            case 3:
                stu_choosecou();
                //3.学生选课
                break;
            case 4:
                printf("退出");
                return;
            default:
                printf("您输入的序号错误，请输入1-5之间的数字！");
                break;
                
        }
    
    }
}
