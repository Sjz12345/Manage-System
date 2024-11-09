#include "manager.h"

Manager::Manager(int id, string name, int dId) {
     this->m_id=id;
     this->m_name=name;
     this->m_DepId=dId;
}
void Manager::show_infor() {
     cout<<"职工编号： "<<this->m_id;
     cout<<"\t职工姓名： "<<this->m_name;
     cout<<"\t岗位： "<<this->getDeptName();
     cout<<"\t岗位职责： 完成老板交代的任务,并下发任务给员工";
     cout<<endl;
}
string Manager::getDeptName() {
     return string("经理"); //将c语言字符串转化为c++字符串
}
