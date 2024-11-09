#pragma once//预处理指令，用于防止文件被多次包含（也称为多重包含）。这个指令告诉预处理器只处理包含该指令的文件一次，即使在多个文件中包含了它。
#include<iostream>
#include "worker.h"
#include "employee.h"
#include "Boss.h"
#include "manager.h"
#include <fstream>
#define FileName "emFile.txt"
using namespace std;

class work_manage {
public:
    work_manage();//构造函数

    void show_menu();//展示菜单

    void exit_system();//退出系统

    int m_EmpNum;//职工人数

    bool FileIsEmpty;//判断文件是否为空

    Worker **m_EmpArray;//职工数组指针

    void Add_Emp();//添加职工

    void save();//保存文件

    int get_EmpNum();//统计文件中人数

    void init_EmpArray();//初始化员工

    void test();//测试函数，测试是否正确读取文件

    void Show_Emp();//显示职工

    int isExist(int id);//根据职工号判断职工是否存在，若存在返回职工在数组中的位置，不存在返回-1

    void Delete_Emp();//删除职工

    void Modify_Emp();//修改职工信息

    void Find_Emp();//查找职工

    void Sort_Emp();//按照职工编号进行排序

    void clean_File();//清空文件

    ~work_manage();//析构函数

};