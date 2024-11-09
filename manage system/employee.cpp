#include "employee.h"
//构造函数
Employee::Employee(int id, string name, int dId) {
    this->m_id = id;
    this->m_name = name;
    this->m_DepId = dId;
}
//显示个人信息
void Employee::show_infor() {
    cout<<"职工编号： "<<this->m_id;
    cout<<"\t职工姓名： "<<this->m_name;
    cout<<"\t岗位： "<<this->getDeptName();
    cout<<"\t岗位职责： 完成经理交代的任务";
    cout<<endl;
}
//获取岗位名称
string Employee::getDeptName() {
    return  string("员工");
}