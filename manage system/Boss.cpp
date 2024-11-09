#include "Boss.h"

Boss::Boss(int id, string name, int dId) {
    this->m_id=id;
    this->m_name=name;
    this->m_DepId=dId;
}
void Boss::show_infor() {
    cout<<"职工编号： "<<this->m_id;
    cout<<"\t职工姓名： "<<this->m_name;
    cout<<"\t岗位： "<<this->getDeptName();
    cout<<"\t岗位职责： 管理公司所有事物";
    cout<<endl;
}
string Boss::getDeptName() {
    return string("总裁"); //将c语言字符串转化为c++字符串
}