#include <iostream>
#include <algorithm>
#include "worker.h"
#include "work_manage.h"
#include "employee.h"
#include "Boss.h"
#include "manager.h"
#define FileName "emFile.txt"
using namespace std;
bool Sort_up(Worker *w1,Worker *w2){
    return w1->m_id<w2->m_id;
}
bool Sort_down(Worker *w1,Worker *w2){
    return w1->m_id>w2->m_id;
}
work_manage::work_manage() {
    ifstream ifs(FileName,ios::in);
    this->FileIsEmpty=false;
    if(!ifs.is_open()) {
        cout<<"�ļ�������"<<endl;
        this->m_EmpArray=NULL;//��ʼ������ָ��
        this->m_EmpNum=0;//��ʼ����¼����
        this->FileIsEmpty=true;//��ʼ���ļ��Ƿ�Ϊ��
        ifs.close();
        return;
    }
    //�ļ����ڣ�����û�м�¼
    char ch;
    ifs>>ch;
    if(ifs.eof()){
        //�ļ�Ϊ��
        cout<<"�ļ�Ϊ��"<<endl;
        this->m_EmpArray=NULL;//��ʼ������ָ��
        this->m_EmpNum=0;//��ʼ����¼����
        this->FileIsEmpty=true;//��ʼ���ļ��Ƿ�Ϊ��
        ifs.close();
        return;
    }
    ifs.close();
    //�ļ����ڲ��Ҽ�¼����
    int num=this->get_EmpNum();
    //cout<<"ְ������Ϊ: "<<num<<endl;
    this->m_EmpNum=num;
    //��������ռ�
    this->m_EmpArray=new Worker*[this->m_EmpNum];
    //���ļ����ݴ浽������
    this->init_EmpArray();
    //���Ժ�����ʹ��ʱע�͵�
    //this->test();

}
work_manage::~work_manage() {
    if(this->m_EmpArray!=NULL){
        delete[] this->m_EmpArray;
        this->m_EmpArray=NULL;
    }
}
void work_manage::show_menu() {
    cout<<"**********************************************************"<<endl;
    cout<<"**********��ӭʹ��ְ������ϵͳ**********"<<endl;
    cout<<"********** 0.�˳�������� **********"<<endl;
    cout<<"********** 1.����ְ����Ϣ **********"<<endl;
    cout<<"********** 2.��ʾְ����Ϣ **********"<<endl;
    cout<<"********** 3.ɾ����ְְ�� **********"<<endl;
    cout<<"********** 4.�޸�ְ����Ϣ **********"<<endl;
    cout<<"********** 5.����ְ����Ϣ **********"<<endl;
    cout<<"********** 6.���ձ������ **********"<<endl;
    cout<<"********** 7.��������ĵ� **********"<<endl;
    cout<<"**********************************************************"<<endl;
    cout<<endl;
}
void work_manage::exit_system() {
    cout<<"��ӭ�´�ʹ��"<<endl;
    system("pause");
    exit(0);//�˳�����
}
int work_manage::get_EmpNum(){
    ifstream ifs;
    ifs.open(FileName,ios::in);//���ļ�

    int id;
    string name;
    int dId;

    int cnt=0;//ͳ������

    while(ifs>>id>>name>>dId){
        cnt++;//ͳ������
    }
    ifs.close();
    return cnt;
}
void work_manage::save() {
     ofstream ofs;
     ofs.open(FileName,ios::out);//д�ļ�
     //��ÿ��������д���ļ���
     for(int i=0;i<this->m_EmpNum;i++){
        ofs<<this->m_EmpArray[i]->m_id<<" "
        <<this->m_EmpArray[i]->m_name<<" "
        <<this->m_EmpArray[i]->m_DepId<<endl;
     }
     ofs.close();//�ر��ļ�
}
void work_manage::Add_Emp(){
    cout<<"���������ְ��������: "<<endl;

    int add_num=0;//�����û���������

    cin>>add_num;

    if(add_num>0){
        int newSize=this->m_EmpNum+add_num;//������Ӻ��µĿռ�Ĵ�С

        Worker ** newspace = new Worker*[newSize];//�����µĿռ�

        //��ԭ���ռ��µ����ݣ��������¿ռ���
        if(this->m_EmpArray!=NULL){
            for(int i=0;i<this->m_EmpNum;i++){
                newspace[i]=this->m_EmpArray[i];
            }
        }
            //�������������
            for(int i=0;i<add_num;i++) {
                int id;//ְ�����
                string name;//ְ������
                int dSelect;//ְ������

                cout<<"�������"<<i+1<<"��ְ���ı��"<<endl;
                cin>>id;
                cout<<"�������"<<i+1<<"��ְ��������"<<endl;
                cin>>name;
                cout<<"�������"<<i+1<<"��ְ���ĸ�λ"<<endl;
                cout<<"1����ְͨ��"<<endl;
                cout<<"2������"<<endl;
                cout<<"3���ܲ�"<<endl;
                cin>>dSelect;

                Worker *temp=NULL;
                switch(dSelect){
                    case 1:
                        temp=new Employee(id,name,dSelect);
                    break;
                    case 2:
                        temp=new Manager(id,name,dSelect);
                    break;
                    case 3:
                        temp=new Boss(id,name,dSelect);
                    break;
                    default:
                        break;
                }
                newspace[this->m_EmpNum+i]=temp;
            }
                //�ͷ�ԭ�пռ�
                delete []this->m_EmpArray;
                //�����µĿռ�ָ��
                this->m_EmpArray=newspace;
                //�����µ�ְ������
                this->m_EmpNum=newSize;
                //����ְ����Ϊ�ձ�־
                this->FileIsEmpty=false;
                //��ʾ��ӳɹ�
            cout<<"�ɹ����"<<add_num<<"����ְ��"<<endl;
            this->save();//��������ӵ�ְ�����ļ�
    }else{
        cout<<"������������"<<endl;
    }
}
void work_manage::init_EmpArray(){//��ʼ��Ա������
    ifstream ifs;
    ifs.open(FileName,ios::in);

    int id=0;
    string name;
    int dId=0;
    int index=0;
    while(ifs>>id>>name>>dId){
        Worker *temp=NULL;
        if(dId==1){//��ְͨ��
            temp=new Employee(id,name,dId);
        }else if(dId==2){//����
            temp=new Manager(id,name,dId);
        }else{//�ܲ�
            temp=new Boss(id,name,dId);
        }
        this->m_EmpArray[index++]=temp;
    }
    ifs.close();//�ر��ļ�
}
void work_manage::test(){
    for(int i=0;i<this->m_EmpNum;i++){
        cout<<this->m_EmpArray[i]->m_id<<" "<<this->m_EmpArray[i]->m_name<<" "<<this->m_EmpArray[i]->m_DepId<<endl;
    }
}
void work_manage::Show_Emp(){
     if(this->FileIsEmpty){

        cout<<"�ļ������ڻ��¼Ϊ��"<<endl;

     }else{
        for(int i=0;i<this->m_EmpNum;i++){
            //���ö�̬���ýӿ�
            this->m_EmpArray[i]->show_infor();
        }
     }
     system("pause");
}
int work_manage::isExist(int id){
    int index=-1;
    for(int i=0;i<this->m_EmpNum;i++){
        if(id==this->m_EmpArray[i]->m_id){
            index=i;
            break;
        }
    }
    return index;
}
void work_manage::Delete_Emp(){
     if(this->FileIsEmpty){
        cout<<"�ļ������ڻ��¼Ϊ��"<<endl;
        return;
     }
     //����ְ���Ž���ɾ��
     cout<<"������ְ�����: "<<endl;
     int id=0;
     cin>>id;
     int index=this->isExist(id);
     if(index==-1){
        cout<<"ɾ��ʧ�ܣ�δ�ҵ���Ա��"<<endl;
     }else{
        //����ǰ��
        for(int i=index;i<this->m_EmpNum-1;i++){
              this->m_EmpArray[i]=this->m_EmpArray[i+1];
        }
        this->m_EmpNum--;//���������м�¼ְ������
        this->save();
        cout<<"ɾ���ɹ�"<<endl;
     }
     system("pause");
}
void work_manage::Modify_Emp(){
    if(this->FileIsEmpty){
        cout<<"�ļ������ڻ��¼Ϊ��"<<endl;
        return;
    }
    cout<<"�������޸ĵ�ְ�����: "<<endl;
    int id=0;
    cin>>id;
    int index=this->isExist(id);
    if(index==-1){
        cout<<"ְ��������"<<endl;
    }else{
        cout<<"�������޸���Ϣ������: "<<endl;
        cout<<"1�����"<<endl;
        cout<<"2������"<<endl;
        cout<<"3����λ"<<endl;
        cin>>id;
        if(id==1){
            cout<<"�������޸ĺ�ı��"<<endl;
            int new_id;
            cin>>new_id;
            this->m_EmpArray[index]->m_id=new_id;
            cout<<"����޸ĳɹ�"<<endl;
        }else if(id==2){
            cout<<"�������޸ĺ������"<<endl;
            string new_name;
            cin>>new_name;
            this->m_EmpArray[index]->m_name=new_name;
            cout<<"�����޸ĳɹ�"<<endl;
        }else{
            cout<<"�������޸ĺ�ĸ�λ: "<<endl;
            cout<<"1����ְͨ��"<<endl;
            cout<<"2������"<<endl;
            cout<<"3���ܲ�"<<endl;
            int new_dId;
            cin>>new_dId;
            this->m_EmpArray[index]->m_DepId=new_dId;
            cout<<"��λ�޸ĳɹ�"<<endl;
        }
    }
    this->save();
    system("pause");
}
void work_manage::Find_Emp(){
    if(this->FileIsEmpty){
        cout<<"�ļ������ڻ��¼Ϊ��"<<endl;
        return;
    }
    cout<<"��������ҷ�ʽ: "<<endl;
    cout<<"1������Ų���"<<endl;
    cout<<"2������������"<<endl;
    int select=0;
    cin>>select;
    if(select==1){
        int id;
        cout<<"��������ҵ�ְ�����: "<<endl;
        cin>>id;
        int index=this->isExist(id);
        if(index==-1){
            cout<<"���޴���"<<endl;
        }else{
            cout<<"���ҳɹ�: "<<endl;
            this->m_EmpArray[index]->show_infor();
        }
    }else if(select==2){
        string name;
        bool flag=true;
        cout<<"��������ҵ�ְ������: "<<endl;
        cin>>name;
        for(int i=0;i<this->m_EmpNum;i++){
            if(name==this->m_EmpArray[i]->m_name){
                cout<<"���ҳɹ�: "<<endl;
                this->m_EmpArray[i]->show_infor();
                flag=false;
            }
        }
        if(flag==true){
            cout<<"����������: "<<name<<"��ְ��"<<endl;
        }
    }else cout<<"����ѡ������"<<endl;
}
void work_manage::Sort_Emp(){
    if(this->FileIsEmpty){
        cout<<"�ļ������ڻ��¼Ϊ��"<<endl;
        return;
    }
    cout<<"����������ʽ"<<endl;
    cout<<"1������"<<endl;
    cout<<"2������"<<endl;
    int select=0;
    cin>>select;
    if(select==1){
        sort(this->m_EmpArray,this->m_EmpArray+this->m_EmpNum,Sort_up);
        cout<<"��������ɹ�"<<endl;
        this->save();
    }else if(select==2){
        cout<<"��������ɹ�"<<endl;
        sort(this->m_EmpArray,this->m_EmpArray+this->m_EmpNum,Sort_down);
        this->save();
    }else{
         cout<<"����ѡ������"<<endl;
    }
}
void work_manage::clean_File(){
    cout<<"ȷ����� :"<<endl;
    cout<<"1��ȷ��"<<endl;
    cout<<"2������"<<endl;
    int select=0;
    cin>>select;
    if(select==1){
        ofstream ofs(FileName,ios::trunc);
        ofs.close();

        if(this->m_EmpArray!=NULL){
            for(int i=0;i<this->m_EmpNum;i++){

                if(this->m_EmpArray[i]!=NULL){
                    delete this->m_EmpArray[i];
                }
            }
            this->m_EmpNum=0;
            delete []this->m_EmpArray;
            this->m_EmpArray=NULL;
            this->FileIsEmpty=true;
        }
        cout<<"����ɹ�"<<endl;
    }else{
        cout<<"ȡ���ɹ�"<<endl;
    }
}