#include "manager.h"

Manager::Manager(int id, string name, int dId) {
     this->m_id=id;
     this->m_name=name;
     this->m_DepId=dId;
}
void Manager::show_infor() {
     cout<<"ְ����ţ� "<<this->m_id;
     cout<<"\tְ�������� "<<this->m_name;
     cout<<"\t��λ�� "<<this->getDeptName();
     cout<<"\t��λְ�� ����ϰ彻��������,���·������Ա��";
     cout<<endl;
}
string Manager::getDeptName() {
     return string("����"); //��c�����ַ���ת��Ϊc++�ַ���
}
