#pragma once//Ԥ����ָ����ڷ�ֹ�ļ�����ΰ�����Ҳ��Ϊ���ذ����������ָ�����Ԥ������ֻ���������ָ����ļ�һ�Σ���ʹ�ڶ���ļ��а���������
#include<iostream>
#include "worker.h"
#include "employee.h"
#include "Boss.h"
#include "manager.h"
#include <fstream>
#define FileName "emFile.txt"
using namespace std;

class work_manage {
public:
    work_manage();//���캯��

    void show_menu();//չʾ�˵�

    void exit_system();//�˳�ϵͳ

    int m_EmpNum;//ְ������

    bool FileIsEmpty;//�ж��ļ��Ƿ�Ϊ��

    Worker **m_EmpArray;//ְ������ָ��

    void Add_Emp();//���ְ��

    void save();//�����ļ�

    int get_EmpNum();//ͳ���ļ�������

    void init_EmpArray();//��ʼ��Ա��

    void test();//���Ժ����������Ƿ���ȷ��ȡ�ļ�

    void Show_Emp();//��ʾְ��

    int isExist(int id);//����ְ�����ж�ְ���Ƿ���ڣ������ڷ���ְ���������е�λ�ã������ڷ���-1

    void Delete_Emp();//ɾ��ְ��

    void Modify_Emp();//�޸�ְ����Ϣ

    void Find_Emp();//����ְ��

    void Sort_Emp();//����ְ����Ž�������

    void clean_File();//����ļ�

    ~work_manage();//��������

};