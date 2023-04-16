#include<iostream>
#include<fstream>
#include<cstring>
#include<stdlib.h>

using namespace std;
//菜单
void menu(){
	
	cout << "*******************************************"<<endl;
    cout << "**************学生成绩管理系统*************"<<endl;
    cout << "**********输入1添加学生信息****************"<<endl;
    cout << "**********输入2按学号查询学生信息**********"<<endl;
    cout << "**********输入3按性别查询学生信息**********"<<endl;
    cout << "**********输入4按班级查询学生信息**********"<<endl;
    cout << "**********输入5按姓名查询学生信息**********"<<endl;
    cout << "**********输入6按学号修改学生信息**********"<<endl;
    cout << "**********输入7查询某课程的平均分**********"<<endl;
    cout << "**********输入8清空所有数据****************"<<endl;
    cout << "**********输入9重新召唤菜单并清屏**********"<<endl;
    cout << "**********输入10按学号删除学生*************"<<endl;
	cout << "**********输入11按学号查询某学生总分*******"<<endl; 
    cout << "**********输入-1退出系统*******************"<<endl;
    cout << "*******************************************"<<endl;
}
//定义学生类
struct Student{
    //姓名 性别 班级
    char name[20] , sex[20];
    //ch 语文 math 数学 en 英语 pol 政治 his 历史 geo 地理 bio 生物
    double ch , math , en , pol , his , geo , bio ;
    //学号 
    int cno , cl;
};
//向文件中添加学生信息,添加成功返回true，否则返回false
bool add(){
    Student s;
    cout << "请依次输入您要添加的学生姓名 性别 学号 班级,语数外政史地生的各科成绩(各信息用空格或换行隔开)\n";
    cin >> s.name >> s.sex >> s.cno >> s.cl >> s.ch >> s.math >> s.en >> s.pol >> s.his >> s.geo >> s.bio; 
    ofstream fout;
    //用二进制及追加的方式打开文件，用二进制虽然可能不太直观，但是容易处理数据，可以将整个结构体整体写入
    fout.open("student.dat" , ios::app|ios::binary);
    //判断文件是否已打开
    if(!fout.is_open()){
        cout << "文件打开失败,该学生信息录取失败！";
        return false;
    }
    //写入该结构体
    fout.write((char *) &s , sizeof(s));
    //关闭输出流
    fout.close();
    cout << "该学生信息录入成功！\n";
    return true;
}
//输出学生信息
void print(Student s){
	cout << endl;
    cout << "姓名：" << s.name << endl;
    cout << "学号：" << s.cno << endl;
    cout << "性别：" << s.sex << endl;
    cout << "班级：" << s.cl << endl;
    cout << "成绩（按照语数外政史地生顺序输出）:" << s.ch << ' ' << s.math << ' '<< s.en
    << ' ' << s.pol << ' '<< s.his << ' '<< s.geo << ' '<< s.bio << ' '<< endl;
    cout << endl;
}
//因为学生学号是唯一的，所以按学号查找能找到唯一一个学生
bool searchByCno(int cno){
    Student s;
    ifstream fin;
    fin.open("student.dat",ios::in|ios::binary);
    if(!fin.is_open()){
        cout << "文件打开失败" << endl;
        return false;
    }
    //遍历二进制文件中的结构体，若遇到学号与查询的学号相同的学生就输入该学生信息
    while(fin.read((char*) &s,sizeof(s))){
        if(s.cno == cno){
            print(s);
            return true;
        }
    }
    fin.close();
    return false;
}
//按性别查找学生
bool searchBySex(char sex[20]){
    Student s;
    ifstream fin;
    fin.open("student.dat",ios::in|ios::binary);
    if(!fin.is_open()){
        cout << "文件打开失败" << endl;
        return false;
    }
    //遍历二进制文件中的结构体，若遇到性别与查询的性别相同的学生就输入该学生信息
    while(fin.read((char*) &s,sizeof(s))){
        if(!strcmp(sex,s.sex)){
            print(s);
        }
    }
    fin.close();
    return false;
}

//按姓名查找学生
bool searchByName(char name[20]){
    Student s;
    ifstream fin;
    fin.open("student.dat",ios::in|ios::binary);
    //判断文件是否打开成功
    if(!fin.is_open()){
        cout << "文件打开失败" << endl;
        return false;
    }
    //遍历二进制文件中的结构体，若遇到姓名与查询的性别相同的学生就输入该学生信息
    while(fin.read((char*) &s,sizeof(s))){
        if(!strcmp(name,s.name)){
            print(s);
        }
    }
    fin.close();
    return false;
}


//按班级查找学生
bool searchByCL(int cl){
    Student s;
    ifstream fin;
    fin.open("student.dat",ios::in|ios::binary);
    //判断文件是否打开成功
    if(!fin.is_open()){
        cout << "文件打开失败" << endl;
        return false;
    }
    //遍历二进制文件中的结构体，若遇到班级与查询的班级相同的学生就输入该学生信息
    while(fin.read((char*) &s,sizeof(s))){
        if(cl == s.cl){
            print(s);
        }
    }
    fin.close();
    return false;
}

//修改学生信息 
bool revise(int cno){
    Student s;
    ofstream fout;
    ifstream fin;
    fin.open("student.dat",ios::in|ios::binary);
    fout.open("tmp.dat",ios::binary|ios::trunc);
    if(!fin.is_open() || !fout.is_open()){
        cout << "文件打开失败" << endl;
        return false;
    }
    int flag = 0;
    while(fin.read((char*) &s,sizeof(s))){
        if(cno == s.cno){
            flag = 1;
            break;
        }
        fout.write((char *) &s , sizeof(s));
    }
    if(!flag){
        cout << "没有该学号的学生!" << endl;
        return false;
    }
    cout << "该学生信息如下：" << endl;
    print(s);
    int op;
    cout <<"**********************" << endl;
    cout <<"**输入1修改姓名*******" << endl;
    cout <<"**输入2修改性别*******" << endl;
    cout <<"**输入3修改班级*******" << endl;
    cout <<"**输入4修改语文成绩***" << endl;
    cout <<"**输入5修改数学成绩***" << endl;
    cout <<"**输入6修改英语成绩***" << endl;
    cout <<"**输入7修改政治成绩***" << endl;
    cout <<"**输入8修改历史成绩***" << endl;
    cout <<"**输入9修改地理成绩***" << endl;
    cout <<"**输入10修改生物成绩**" << endl;
    cout <<"**********************" << endl;
    cout <<"请选择操作:";
    cin >> op;
    cout << "请输入修改后的值:";
        if(op == 1)cin >> s.name;
        if(op == 2)cin >> s.sex;
        if(op == 3)cin >> s.cl;
        if(op == 4)cin >> s.ch;
        if(op == 5)cin >> s.math;
        if(op == 6)cin >> s.en;
        if(op == 7)cin >> s.pol;
        if(op == 8)cin >> s.his;
        if(op == 9)cin >> s.geo;
        if(op == 10)cin >> s.bio;
        fout.write((char *) &s , sizeof(s));
        cout <<"下面是修改后的信息:" << endl;
        print(s);
        while(fin.read((char*) &s,sizeof(s))){
        fout.write((char *) &s , sizeof(s));
        }
       	//关闭对上面打开的文件的读写，准备开始新的读写 
        fin.close();
        fout.close();
        fin.open("tmp.dat",ios::in|ios::binary);
        fout.open("student.dat",ios::binary|ios::trunc);
        if(!fin.is_open() || !fout.is_open()){
        cout << "文件打开失败" << endl;
        return false;
        }
        while(fin.read((char *) &s , sizeof(s))){
            fout.write((char *) &s , sizeof(s));
        }
        fin.close();
        fout.close();
    cout << "修改完成！"<<endl;
    
    return true;
}
//查询某科平均分 
void searchCourse(){
    int op;
    cout <<"***********************" << endl;
    cout <<"***输入1查询语文成绩***" << endl;
    cout <<"***输入2查询数学成绩***" << endl;
    cout <<"***输入3查询英语成绩***" << endl;
    cout <<"***输入4查询政治成绩***" << endl;
    cout <<"***输入5查询历史成绩***" << endl;
    cout <<"***输入6查询地理成绩***" << endl;
    cout <<"***输入7查询生物成绩***" << endl;
    cout <<"***********************" << endl;
    cout <<"请选择操作:";
    cin >> op;
    double sum = 0;
    int cnt = 0;
    Student s;
    ifstream fin;
    fin.open("student.dat" , ios::binary | ios::in);
    if(!fin.is_open()){
        cout << "文件打开失败" << endl;
        return ;
    }
    while(fin.read((char *) &s , sizeof s)){
        if(op == 1)sum += s.ch;
        if(op == 2)sum += s.math;
        if(op == 3)sum += s.en;
        if(op == 4)sum += s.pol;
        if(op == 5)sum += s.his;
        if(op == 6)sum += s.geo;
        if(op == 7)sum += s.bio;
        cnt++;
    }
    fin.close();
    double x = sum / cnt;
    printf( "全年级该科的平均分为(保留两位小数):%.2f",x);
    cout << endl;
}
//通过学号删除学生信息 
bool deleteByCno(int cno){
    ifstream fin;
    ofstream fout;
    Student s;
    fin.open("student.dat",ios::in | ios::binary);
    fout.open("tmp.dat",ios::binary|ios::trunc);
    if(!fin.is_open() || !fout.is_open()){
    cout << "文件打开失败" << endl;
    return false;
    }
    int flag = 0;
    while(fin.read((char*) &s,sizeof(s))){
        if(s.cno != cno)fout.write((char *) &s , sizeof(s));
        else flag = 1; 
    }

     fin.close();
    fout.close();
    fin.open("tmp.dat",ios::in|ios::binary);
    fout.open("student.dat",ios::binary|ios::trunc);
    if(!fin.is_open() || !fout.is_open()){
    cout << "文件打开失败" << endl;
    return false;
    }
    while(fin.read((char *) &s , sizeof(s))){
        fout.write((char *) &s , sizeof(s));
    }
    fin.close();
    fout.close();
    if(flag)cout << "删除成功！" << endl;
    else cout << "未找到与该学号相同的学生" << endl;
    return true;
}
//输出某个学生的总分
void printSum(int cno){
	ifstream fin;
    ofstream fout;
    Student s;
    fin.open("student.dat",ios::in | ios::binary);
    fout.open("tmp.dat",ios::binary|ios::trunc);
    if(!fin.is_open() || !fout.is_open()){
    cout << "文件打开失败" << endl;
    return;
    }
    int flag = 0;
    while(fin.read((char*) &s,sizeof(s))){
        if(cno == s.cno){
            flag = 1;
            break;
        }
    }
    if(!flag){
        cout << "没有该学号的学生!" << endl;
        return ;
    }
    double sum = 0;
    sum = s.ch + s.math + s.en + s.pol + s.his + s.geo + s.bio;
    printf("该学生的总分为：%.2f",sum);
    cout << endl;
    
	
}
int main(){
    menu();
    
    int op;
    do{
        cout << "请输入您下一步要进行的操作:";
        cin >> op;
        if(op == 1){
            add();
        }else if(op == 2){
            cout << "请输入要查询的学号:";
            int cno;
            cin >> cno;
            bool flag = searchByCno(cno);
            if(flag)cout << "查询完毕！"<<endl;
            else cout << "查询完毕！数据中不存在该学生！"<<endl;
        }else if(op == 3){
            cout << "请输入要查询的性别:";
            char c[20];
            cin >> c;
            bool flag = searchBySex(c);
            if(flag)cout << "查询完毕！"<<endl;
            else cout << "查询完毕！数据中不存在该学生！"<<endl;
        }else if(op == 4){
            cout << "请输入要查询的班级:";
            int cl;
            cin >> cl;
            bool flag = searchByCL(cl);
            if(flag)cout << "查询完毕！"<<endl;
            else cout << "查询完毕！数据中不存在该学生！"<<endl;
        }else if(op == 5){
            cout << "请输入要查询的姓名:";
            char c[20];
            cin >> c;
            bool flag = searchByName(c);
            if(flag)cout << "查询完毕！"<<endl;
            else cout << "查询完毕！数据中不存在该学生！"<<endl;
        }else if(op == 6){
            cout << "请输入要查询的学号:";
            int a;
            cin >> a;
            revise(a);
        }else if(op == 7){
            searchCourse();
        }else if(op == 8){
            ofstream fout;
            fout.open("student.dat" , ios::trunc);
            fout.close();
            cout << "清空完成！"<<endl;
        }else if(op == 9){
            system("cls");
            menu();
        }else if(op == 10){
            cout << "请输入要删除的学生的学号:";
            int a;
            cin >> a;
            deleteByCno(a);
        }else if(op == 11){
        	cout << "请输入要查询学生的学号:";
            int a;
            cin >> a;
            printSum(a);
            
		} else if(op != -1){
            cout << "无效输入，请参考菜单重新输入。。。" << endl;
        }

    }while(op != -1);
	cout << "已退出程序！";
    return 0;

}