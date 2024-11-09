//普通员工文件
#pragma once
#include <string>
using namespace std;
#include "worker.h"
class Employee:public Worker {
public:
    //初始化
    Employee(int id, string name, int dId);
    //显示个人信息
    virtual void show_infor();
    //获取岗位名称
    virtual string getDeptName();
};