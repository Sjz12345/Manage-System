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
        cout<<"文件不存在"<<endl;
        this->m_EmpArray=NULL;//初始化数组指针
        this->m_EmpNum=0;//初始化记录人数
        this->FileIsEmpty=true;//初始化文件是否为空
        ifs.close();
        return;
    }
    //文件存在，并且没有记录
    char ch;
    ifs>>ch;
    if(ifs.eof()){
        //文件为空
        cout<<"文件为空"<<endl;
        this->m_EmpArray=NULL;//初始化数组指针
        this->m_EmpNum=0;//初始化记录人数
        this->FileIsEmpty=true;//初始化文件是否为空
        ifs.close();
        return;
    }
    ifs.close();
    //文件存在并且记录数据
    int num=this->get_EmpNum();
    //cout<<"职工人数为: "<<num<<endl;
    this->m_EmpNum=num;
    //开辟数组空间
    this->m_EmpArray=new Worker*[this->m_EmpNum];
    //将文件数据存到数组中
    this->init_EmpArray();
    //测试函数，使用时注释掉
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
    cout<<"**********欢迎使用职工管理系统**********"<<endl;
    cout<<"********** 0.退出管理程序 **********"<<endl;
    cout<<"********** 1.增加职工信息 **********"<<endl;
    cout<<"********** 2.显示职工信息 **********"<<endl;
    cout<<"********** 3.删除离职职工 **********"<<endl;
    cout<<"********** 4.修改职工信息 **********"<<endl;
    cout<<"********** 5.查找职工信息 **********"<<endl;
    cout<<"********** 6.按照编号排序 **********"<<endl;
    cout<<"********** 7.清空所有文档 **********"<<endl;
    cout<<"**********************************************************"<<endl;
    cout<<endl;
}
void work_manage::exit_system() {
    cout<<"欢迎下次使用"<<endl;
    system("pause");
    exit(0);//退出程序
}
int work_manage::get_EmpNum(){
    ifstream ifs;
    ifs.open(FileName,ios::in);//打开文件

    int id;
    string name;
    int dId;

    int cnt=0;//统计人数

    while(ifs>>id>>name>>dId){
        cnt++;//统计人数
    }
    ifs.close();
    return cnt;
}
void work_manage::save() {
     ofstream ofs;
     ofs.open(FileName,ios::out);//写文件
     //将每个人数据写到文件中
     for(int i=0;i<this->m_EmpNum;i++){
        ofs<<this->m_EmpArray[i]->m_id<<" "
        <<this->m_EmpArray[i]->m_name<<" "
        <<this->m_EmpArray[i]->m_DepId<<endl;
     }
     ofs.close();//关闭文件
}
void work_manage::Add_Emp(){
    cout<<"请输入添加职工的数量: "<<endl;

    int add_num=0;//保存用户输入数量

    cin>>add_num;

    if(add_num>0){
        int newSize=this->m_EmpNum+add_num;//计算添加后新的空间的大小

        Worker ** newspace = new Worker*[newSize];//开辟新的空间

        //将原来空间下的数据，拷贝到新空间下
        if(this->m_EmpArray!=NULL){
            for(int i=0;i<this->m_EmpNum;i++){
                newspace[i]=this->m_EmpArray[i];
            }
        }
            //批量添加新数据
            for(int i=0;i<add_num;i++) {
                int id;//职工编号
                string name;//职工姓名
                int dSelect;//职工部门

                cout<<"请输入第"<<i+1<<"新职工的编号"<<endl;
                cin>>id;
                cout<<"请输入第"<<i+1<<"新职工的姓名"<<endl;
                cin>>name;
                cout<<"请输入第"<<i+1<<"新职工的岗位"<<endl;
                cout<<"1、普通职工"<<endl;
                cout<<"2、经理"<<endl;
                cout<<"3、总裁"<<endl;
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
                //释放原有空间
                delete []this->m_EmpArray;
                //更新新的空间指向
                this->m_EmpArray=newspace;
                //更新新的职工人数
                this->m_EmpNum=newSize;
                //更新职工不为空标志
                this->FileIsEmpty=false;
                //提示添加成功
            cout<<"成功添加"<<add_num<<"名新职工"<<endl;
            this->save();//保存新添加的职工到文件
    }else{
        cout<<"输入数据有误"<<endl;
    }
}
void work_manage::init_EmpArray(){//初始化员工数组
    ifstream ifs;
    ifs.open(FileName,ios::in);

    int id=0;
    string name;
    int dId=0;
    int index=0;
    while(ifs>>id>>name>>dId){
        Worker *temp=NULL;
        if(dId==1){//普通职工
            temp=new Employee(id,name,dId);
        }else if(dId==2){//经理
            temp=new Manager(id,name,dId);
        }else{//总裁
            temp=new Boss(id,name,dId);
        }
        this->m_EmpArray[index++]=temp;
    }
    ifs.close();//关闭文件
}
void work_manage::test(){
    for(int i=0;i<this->m_EmpNum;i++){
        cout<<this->m_EmpArray[i]->m_id<<" "<<this->m_EmpArray[i]->m_name<<" "<<this->m_EmpArray[i]->m_DepId<<endl;
    }
}
void work_manage::Show_Emp(){
     if(this->FileIsEmpty){

        cout<<"文件不存在或记录为空"<<endl;

     }else{
        for(int i=0;i<this->m_EmpNum;i++){
            //利用多态调用接口
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
        cout<<"文件不存在或记录为空"<<endl;
        return;
     }
     //按照职工号进行删除
     cout<<"请输入职工编号: "<<endl;
     int id=0;
     cin>>id;
     int index=this->isExist(id);
     if(index==-1){
        cout<<"删除失败，未找到该员工"<<endl;
     }else{
        //数据前移
        for(int i=index;i<this->m_EmpNum-1;i++){
              this->m_EmpArray[i]=this->m_EmpArray[i+1];
        }
        this->m_EmpNum--;//更新数组中记录职工人数
        this->save();
        cout<<"删除成功"<<endl;
     }
     system("pause");
}
void work_manage::Modify_Emp(){
    if(this->FileIsEmpty){
        cout<<"文件不存在或记录为空"<<endl;
        return;
    }
    cout<<"请输入修改的职工编号: "<<endl;
    int id=0;
    cin>>id;
    int index=this->isExist(id);
    if(index==-1){
        cout<<"职工不存在"<<endl;
    }else{
        cout<<"请输入修改信息的类型: "<<endl;
        cout<<"1、编号"<<endl;
        cout<<"2、姓名"<<endl;
        cout<<"3、岗位"<<endl;
        cin>>id;
        if(id==1){
            cout<<"请输入修改后的编号"<<endl;
            int new_id;
            cin>>new_id;
            this->m_EmpArray[index]->m_id=new_id;
            cout<<"编号修改成功"<<endl;
        }else if(id==2){
            cout<<"请输入修改后的姓名"<<endl;
            string new_name;
            cin>>new_name;
            this->m_EmpArray[index]->m_name=new_name;
            cout<<"姓名修改成功"<<endl;
        }else{
            cout<<"请输入修改后的岗位: "<<endl;
            cout<<"1、普通职工"<<endl;
            cout<<"2、经理"<<endl;
            cout<<"3、总裁"<<endl;
            int new_dId;
            cin>>new_dId;
            this->m_EmpArray[index]->m_DepId=new_dId;
            cout<<"岗位修改成功"<<endl;
        }
    }
    this->save();
    system("pause");
}
void work_manage::Find_Emp(){
    if(this->FileIsEmpty){
        cout<<"文件不存在或记录为空"<<endl;
        return;
    }
    cout<<"请输入查找方式: "<<endl;
    cout<<"1、按编号查找"<<endl;
    cout<<"2、按姓名查找"<<endl;
    int select=0;
    cin>>select;
    if(select==1){
        int id;
        cout<<"请输入查找的职工编号: "<<endl;
        cin>>id;
        int index=this->isExist(id);
        if(index==-1){
            cout<<"查无此人"<<endl;
        }else{
            cout<<"查找成功: "<<endl;
            this->m_EmpArray[index]->show_infor();
        }
    }else if(select==2){
        string name;
        bool flag=true;
        cout<<"请输入查找的职工姓名: "<<endl;
        cin>>name;
        for(int i=0;i<this->m_EmpNum;i++){
            if(name==this->m_EmpArray[i]->m_name){
                cout<<"查找成功: "<<endl;
                this->m_EmpArray[i]->show_infor();
                flag=false;
            }
        }
        if(flag==true){
            cout<<"不存在姓名: "<<name<<"的职工"<<endl;
        }
    }else cout<<"输入选项有误"<<endl;
}
void work_manage::Sort_Emp(){
    if(this->FileIsEmpty){
        cout<<"文件不存在或记录为空"<<endl;
        return;
    }
    cout<<"请输入排序方式"<<endl;
    cout<<"1、升序"<<endl;
    cout<<"2、降序"<<endl;
    int select=0;
    cin>>select;
    if(select==1){
        sort(this->m_EmpArray,this->m_EmpArray+this->m_EmpNum,Sort_up);
        cout<<"升序排序成功"<<endl;
        this->save();
    }else if(select==2){
        cout<<"降序排序成功"<<endl;
        sort(this->m_EmpArray,this->m_EmpArray+this->m_EmpNum,Sort_down);
        this->save();
    }else{
         cout<<"输入选项有误"<<endl;
    }
}
void work_manage::clean_File(){
    cout<<"确认清空 :"<<endl;
    cout<<"1、确认"<<endl;
    cout<<"2、返回"<<endl;
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
        cout<<"清除成功"<<endl;
    }else{
        cout<<"取消成功"<<endl;
    }
}