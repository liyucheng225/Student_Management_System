#!/bin/bash
cp ../../log.log ~/
file=~/log.log
upstu=`grep  "修改" ${file} |grep "学生"| wc -l` 
upcou=`grep "修改" ${file}|grep "课程"|wc -l`
echo "修改学生信息的次数是：${upstu}次"
echo "修改课程信息的次数是：${upcou}次"
read -p "请输入要查找的学号：" stu
serstu=`grep "修改" ${file}|grep "学生"|grep "是${stu}"|wc -l`
if [ $serstu -gt 0 ]
then
    echo "存在对学号为${stu}的学生的修改记录"
else
    echo "不存在对学号为${stu}的学生的修改记录"
fi
read -p "请输入要查找的课程号：" cou
sercou=`grep "修改" ${file}|grep "课程"|grep "是${cou}"|wc -l`
if [ $sercou -gt 0 ]
then
    echo "存在对课程号为${cou}的课程的修改记录"
else
    echo "不存在对课程号为${cou}的课程的修改记录"
fi
