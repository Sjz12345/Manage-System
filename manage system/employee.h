//��ͨԱ���ļ�
#pragma once
#include <string>
using namespace std;
#include "worker.h"
class Employee:public Worker {
public:
    //��ʼ��
    Employee(int id, string name, int dId);
    //��ʾ������Ϣ
    virtual void show_infor();
    //��ȡ��λ����
    virtual string getDeptName();
};