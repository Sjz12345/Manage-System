#include "employee.h"
//���캯��
Employee::Employee(int id, string name, int dId) {
    this->m_id = id;
    this->m_name = name;
    this->m_DepId = dId;
}
//��ʾ������Ϣ
void Employee::show_infor() {
    cout<<"ְ����ţ� "<<this->m_id;
    cout<<"\tְ�������� "<<this->m_name;
    cout<<"\t��λ�� "<<this->getDeptName();
    cout<<"\t��λְ�� ��ɾ�����������";
    cout<<endl;
}
//��ȡ��λ����
string Employee::getDeptName() {
    return  string("Ա��");
}