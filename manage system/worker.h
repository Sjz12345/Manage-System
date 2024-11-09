#pragma once
#include <iostream>
using namespace std;
#include <string>

//职工抽象类
class Worker
{
public:
    //显示个人信息
    virtual void show_infor()=0;
    //获取岗位名称
    virtual string getDeptName()=0;
    // 职工编号
    int m_id;
    // 职工姓名
    string m_name;
    // 职工编号
    int m_DepId;
};