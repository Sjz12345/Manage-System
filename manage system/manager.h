#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
//������
class Manager :public Worker{
    public:
    //���캯��
    Manager(int id, string name,int dId);
    //��ʾ������Ϣ
    virtual void show_infor();
    //��ȡ��λ����
    virtual string getDeptName();


};