#include<iostream>
#include "worker.h"
#include "work_manage.h"
#include "employee.h"
#include "Boss.h"
#include "manager.h"
using namespace std;
int main() {
    //ʵ��������Ա����
    work_manage wm;
    //����չʾ�˵���Ա����
    int choice=0;

    while(true)
    {   //����չʾ�˵���Ա����
        wm.show_menu();
        cout<<"����������ѡ��:"<<endl;
        cin>>choice;//�����û�ѡ��

        switch(choice)
        {
            case 0://�˳��������
                wm.exit_system();
                break;
            case 1://����ְ����Ϣ
                wm.Add_Emp();
                break;
            case 2://��ʾְ����Ϣ
                wm.Show_Emp();
                break;
            case 3://ɾ����ְְ��
                wm.Delete_Emp();
                break;
            case 4://�޸�ְ����Ϣ
                wm.Modify_Emp();
                break;
            case 5://����ְ����Ϣ
                wm.Find_Emp();
                break;
            case 6://���ձ������
                wm.Sort_Emp();
                break;
            case 7://��������ĵ�
                wm.clean_File();
                break;
            default:
                break;
        }
    }

    system("pause");
    return 0;
}
