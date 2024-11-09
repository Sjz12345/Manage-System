#include<iostream>
#include "worker.h"
#include "work_manage.h"
#include "employee.h"
#include "Boss.h"
#include "manager.h"
using namespace std;
int main() {
    //实例化管理员对象
    work_manage wm;
    //调用展示菜单成员函数
    int choice=0;

    while(true)
    {   //调用展示菜单成员函数
        wm.show_menu();
        cout<<"请输入您的选择:"<<endl;
        cin>>choice;//接受用户选项

        switch(choice)
        {
            case 0://退出管理程序
                wm.exit_system();
                break;
            case 1://增加职工信息
                wm.Add_Emp();
                break;
            case 2://显示职工信息
                wm.Show_Emp();
                break;
            case 3://删除离职职工
                wm.Delete_Emp();
                break;
            case 4://修改职工信息
                wm.Modify_Emp();
                break;
            case 5://查找职工信息
                wm.Find_Emp();
                break;
            case 6://按照编号排序
                wm.Sort_Emp();
                break;
            case 7://清空所有文档
                wm.clean_File();
                break;
            default:
                break;
        }
    }

    system("pause");
    return 0;
}
