#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
//�ϰ���
class Boss :public Worker{
public:
    //���캯��
    Boss(int id, string name,int dId);
    //��ʾ������Ϣ
    virtual void show_infor();
    //��ȡ��λ����
    virtual string getDeptName();

};