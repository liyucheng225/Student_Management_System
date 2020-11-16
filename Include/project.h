#ifndef _PROJECT_H_
#define _PROJECT_H_
#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define SIZE_STU 10
#define SIZE_COU 10


//主目录函数定义
void home(void);
void homefile(void);
//学生信息函数定义
void stu_information(void);
//课程信息函数定义
void cou_information(void);
//学生选课函数定义
void stu_choosecou(void);


//学生信息操作函数定义
//1.显示学生信息函数定义
void display_stu(void);
//2.增加学生信息函数定义
void insert_stu(void);
//3.删除学生信息函数定义
void del_stu(char *id);
//4.修改学生信息函数定义
void update_stu_id(char *sid);
void update_stu_name(char *sname);
//5.查询学生信息函数定义
void select_stu(char *id);


//课程信息操作函数定义
//1.显示课程信息函数定义
void display_cou(void);
//2.增加课程信息函数定义
void insert_cou();
//3.删除课程信息函数定义
void del_cou(char *id);
//4.修改课程信息函数定义
void update_cou_id(char *cid);
void update_cou_name(char *name);
//5.查询课程信息函数定义
void select_cou(char *id);


//学生选课信息函数定义
//1.以学号选课
void idchoose_cou(void);
//2.以姓名选课
void nchoose_cou(void);

void display_stu_cou2(int id);
void display_stu_cou(int id);

//修改项目函数定义
void update_cou(int index);
void update_stu(int index);

//写入文件函数定义
void new_stu(void);
void new_cou(void);
void write_stulog(int index ,char ty[]);
void write_coulog(int index ,char ty[]);

//学生信息结构体
struct student_info{
    char stu_ID[10];
    char stu_name[5];
    char *choose_course[10];
    int count;
    int  allcredit;
}stu[SIZE_STU];

struct course_info{
    char course_ID[10];
    char course_name[10];
    char course_nature[10];
    char course_time[2];
    char course_credit[1];
    int  cousel;
    char course_stu_limit[2];
}cou[SIZE_COU];

extern int counum;
extern int stunum;
#endif
