#include "Boss.h"

Boss::Boss(int id, string name, int dId) {
    this->m_id=id;
    this->m_name=name;
    this->m_DepId=dId;
}
void Boss::show_infor() {
    cout<<"ְ����ţ� "<<this->m_id;
    cout<<"\tְ�������� "<<this->m_name;
    cout<<"\t��λ�� "<<this->getDeptName();
    cout<<"\t��λְ�� ����˾��������";
    cout<<endl;
}
string Boss::getDeptName() {
    return string("�ܲ�"); //��c�����ַ���ת��Ϊc++�ַ���
}