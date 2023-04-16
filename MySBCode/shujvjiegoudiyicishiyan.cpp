#include<iostream>
#include<fstream>
#include<cstring>
#include<stdlib.h>

using namespace std;
//�˵�
void menu(){
	
	cout << "*******************************************"<<endl;
    cout << "**************ѧ���ɼ�����ϵͳ*************"<<endl;
    cout << "**********����1���ѧ����Ϣ****************"<<endl;
    cout << "**********����2��ѧ�Ų�ѯѧ����Ϣ**********"<<endl;
    cout << "**********����3���Ա��ѯѧ����Ϣ**********"<<endl;
    cout << "**********����4���༶��ѯѧ����Ϣ**********"<<endl;
    cout << "**********����5��������ѯѧ����Ϣ**********"<<endl;
    cout << "**********����6��ѧ���޸�ѧ����Ϣ**********"<<endl;
    cout << "**********����7��ѯĳ�γ̵�ƽ����**********"<<endl;
    cout << "**********����8�����������****************"<<endl;
    cout << "**********����9�����ٻ��˵�������**********"<<endl;
    cout << "**********����10��ѧ��ɾ��ѧ��*************"<<endl;
	cout << "**********����11��ѧ�Ų�ѯĳѧ���ܷ�*******"<<endl; 
    cout << "**********����-1�˳�ϵͳ*******************"<<endl;
    cout << "*******************************************"<<endl;
}
//����ѧ����
struct Student{
    //���� �Ա� �༶
    char name[20] , sex[20];
    //ch ���� math ��ѧ en Ӣ�� pol ���� his ��ʷ geo ���� bio ����
    double ch , math , en , pol , his , geo , bio ;
    //ѧ�� 
    int cno , cl;
};
//���ļ������ѧ����Ϣ,��ӳɹ�����true�����򷵻�false
bool add(){
    Student s;
    cout << "������������Ҫ��ӵ�ѧ������ �Ա� ѧ�� �༶,��������ʷ�����ĸ��Ƴɼ�(����Ϣ�ÿո���и���)\n";
    cin >> s.name >> s.sex >> s.cno >> s.cl >> s.ch >> s.math >> s.en >> s.pol >> s.his >> s.geo >> s.bio; 
    ofstream fout;
    //�ö����Ƽ�׷�ӵķ�ʽ���ļ����ö�������Ȼ���ܲ�ֱ̫�ۣ��������״������ݣ����Խ������ṹ������д��
    fout.open("student.dat" , ios::app|ios::binary);
    //�ж��ļ��Ƿ��Ѵ�
    if(!fout.is_open()){
        cout << "�ļ���ʧ��,��ѧ����Ϣ¼ȡʧ�ܣ�";
        return false;
    }
    //д��ýṹ��
    fout.write((char *) &s , sizeof(s));
    //�ر������
    fout.close();
    cout << "��ѧ����Ϣ¼��ɹ���\n";
    return true;
}
//���ѧ����Ϣ
void print(Student s){
	cout << endl;
    cout << "������" << s.name << endl;
    cout << "ѧ�ţ�" << s.cno << endl;
    cout << "�Ա�" << s.sex << endl;
    cout << "�༶��" << s.cl << endl;
    cout << "�ɼ���������������ʷ����˳�������:" << s.ch << ' ' << s.math << ' '<< s.en
    << ' ' << s.pol << ' '<< s.his << ' '<< s.geo << ' '<< s.bio << ' '<< endl;
    cout << endl;
}
//��Ϊѧ��ѧ����Ψһ�ģ����԰�ѧ�Ų������ҵ�Ψһһ��ѧ��
bool searchByCno(int cno){
    Student s;
    ifstream fin;
    fin.open("student.dat",ios::in|ios::binary);
    if(!fin.is_open()){
        cout << "�ļ���ʧ��" << endl;
        return false;
    }
    //�����������ļ��еĽṹ�壬������ѧ�����ѯ��ѧ����ͬ��ѧ���������ѧ����Ϣ
    while(fin.read((char*) &s,sizeof(s))){
        if(s.cno == cno){
            print(s);
            return true;
        }
    }
    fin.close();
    return false;
}
//���Ա����ѧ��
bool searchBySex(char sex[20]){
    Student s;
    ifstream fin;
    fin.open("student.dat",ios::in|ios::binary);
    if(!fin.is_open()){
        cout << "�ļ���ʧ��" << endl;
        return false;
    }
    //�����������ļ��еĽṹ�壬�������Ա����ѯ���Ա���ͬ��ѧ���������ѧ����Ϣ
    while(fin.read((char*) &s,sizeof(s))){
        if(!strcmp(sex,s.sex)){
            print(s);
        }
    }
    fin.close();
    return false;
}

//����������ѧ��
bool searchByName(char name[20]){
    Student s;
    ifstream fin;
    fin.open("student.dat",ios::in|ios::binary);
    //�ж��ļ��Ƿ�򿪳ɹ�
    if(!fin.is_open()){
        cout << "�ļ���ʧ��" << endl;
        return false;
    }
    //�����������ļ��еĽṹ�壬�������������ѯ���Ա���ͬ��ѧ���������ѧ����Ϣ
    while(fin.read((char*) &s,sizeof(s))){
        if(!strcmp(name,s.name)){
            print(s);
        }
    }
    fin.close();
    return false;
}


//���༶����ѧ��
bool searchByCL(int cl){
    Student s;
    ifstream fin;
    fin.open("student.dat",ios::in|ios::binary);
    //�ж��ļ��Ƿ�򿪳ɹ�
    if(!fin.is_open()){
        cout << "�ļ���ʧ��" << endl;
        return false;
    }
    //�����������ļ��еĽṹ�壬�������༶���ѯ�İ༶��ͬ��ѧ���������ѧ����Ϣ
    while(fin.read((char*) &s,sizeof(s))){
        if(cl == s.cl){
            print(s);
        }
    }
    fin.close();
    return false;
}

//�޸�ѧ����Ϣ 
bool revise(int cno){
    Student s;
    ofstream fout;
    ifstream fin;
    fin.open("student.dat",ios::in|ios::binary);
    fout.open("tmp.dat",ios::binary|ios::trunc);
    if(!fin.is_open() || !fout.is_open()){
        cout << "�ļ���ʧ��" << endl;
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
        cout << "û�и�ѧ�ŵ�ѧ��!" << endl;
        return false;
    }
    cout << "��ѧ����Ϣ���£�" << endl;
    print(s);
    int op;
    cout <<"**********************" << endl;
    cout <<"**����1�޸�����*******" << endl;
    cout <<"**����2�޸��Ա�*******" << endl;
    cout <<"**����3�޸İ༶*******" << endl;
    cout <<"**����4�޸����ĳɼ�***" << endl;
    cout <<"**����5�޸���ѧ�ɼ�***" << endl;
    cout <<"**����6�޸�Ӣ��ɼ�***" << endl;
    cout <<"**����7�޸����γɼ�***" << endl;
    cout <<"**����8�޸���ʷ�ɼ�***" << endl;
    cout <<"**����9�޸ĵ���ɼ�***" << endl;
    cout <<"**����10�޸�����ɼ�**" << endl;
    cout <<"**********************" << endl;
    cout <<"��ѡ�����:";
    cin >> op;
    cout << "�������޸ĺ��ֵ:";
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
        cout <<"�������޸ĺ����Ϣ:" << endl;
        print(s);
        while(fin.read((char*) &s,sizeof(s))){
        fout.write((char *) &s , sizeof(s));
        }
       	//�رն�����򿪵��ļ��Ķ�д��׼����ʼ�µĶ�д 
        fin.close();
        fout.close();
        fin.open("tmp.dat",ios::in|ios::binary);
        fout.open("student.dat",ios::binary|ios::trunc);
        if(!fin.is_open() || !fout.is_open()){
        cout << "�ļ���ʧ��" << endl;
        return false;
        }
        while(fin.read((char *) &s , sizeof(s))){
            fout.write((char *) &s , sizeof(s));
        }
        fin.close();
        fout.close();
    cout << "�޸���ɣ�"<<endl;
    
    return true;
}
//��ѯĳ��ƽ���� 
void searchCourse(){
    int op;
    cout <<"***********************" << endl;
    cout <<"***����1��ѯ���ĳɼ�***" << endl;
    cout <<"***����2��ѯ��ѧ�ɼ�***" << endl;
    cout <<"***����3��ѯӢ��ɼ�***" << endl;
    cout <<"***����4��ѯ���γɼ�***" << endl;
    cout <<"***����5��ѯ��ʷ�ɼ�***" << endl;
    cout <<"***����6��ѯ����ɼ�***" << endl;
    cout <<"***����7��ѯ����ɼ�***" << endl;
    cout <<"***********************" << endl;
    cout <<"��ѡ�����:";
    cin >> op;
    double sum = 0;
    int cnt = 0;
    Student s;
    ifstream fin;
    fin.open("student.dat" , ios::binary | ios::in);
    if(!fin.is_open()){
        cout << "�ļ���ʧ��" << endl;
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
    printf( "ȫ�꼶�ÿƵ�ƽ����Ϊ(������λС��):%.2f",x);
    cout << endl;
}
//ͨ��ѧ��ɾ��ѧ����Ϣ 
bool deleteByCno(int cno){
    ifstream fin;
    ofstream fout;
    Student s;
    fin.open("student.dat",ios::in | ios::binary);
    fout.open("tmp.dat",ios::binary|ios::trunc);
    if(!fin.is_open() || !fout.is_open()){
    cout << "�ļ���ʧ��" << endl;
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
    cout << "�ļ���ʧ��" << endl;
    return false;
    }
    while(fin.read((char *) &s , sizeof(s))){
        fout.write((char *) &s , sizeof(s));
    }
    fin.close();
    fout.close();
    if(flag)cout << "ɾ���ɹ���" << endl;
    else cout << "δ�ҵ����ѧ����ͬ��ѧ��" << endl;
    return true;
}
//���ĳ��ѧ�����ܷ�
void printSum(int cno){
	ifstream fin;
    ofstream fout;
    Student s;
    fin.open("student.dat",ios::in | ios::binary);
    fout.open("tmp.dat",ios::binary|ios::trunc);
    if(!fin.is_open() || !fout.is_open()){
    cout << "�ļ���ʧ��" << endl;
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
        cout << "û�и�ѧ�ŵ�ѧ��!" << endl;
        return ;
    }
    double sum = 0;
    sum = s.ch + s.math + s.en + s.pol + s.his + s.geo + s.bio;
    printf("��ѧ�����ܷ�Ϊ��%.2f",sum);
    cout << endl;
    
	
}
int main(){
    menu();
    
    int op;
    do{
        cout << "����������һ��Ҫ���еĲ���:";
        cin >> op;
        if(op == 1){
            add();
        }else if(op == 2){
            cout << "������Ҫ��ѯ��ѧ��:";
            int cno;
            cin >> cno;
            bool flag = searchByCno(cno);
            if(flag)cout << "��ѯ��ϣ�"<<endl;
            else cout << "��ѯ��ϣ������в����ڸ�ѧ����"<<endl;
        }else if(op == 3){
            cout << "������Ҫ��ѯ���Ա�:";
            char c[20];
            cin >> c;
            bool flag = searchBySex(c);
            if(flag)cout << "��ѯ��ϣ�"<<endl;
            else cout << "��ѯ��ϣ������в����ڸ�ѧ����"<<endl;
        }else if(op == 4){
            cout << "������Ҫ��ѯ�İ༶:";
            int cl;
            cin >> cl;
            bool flag = searchByCL(cl);
            if(flag)cout << "��ѯ��ϣ�"<<endl;
            else cout << "��ѯ��ϣ������в����ڸ�ѧ����"<<endl;
        }else if(op == 5){
            cout << "������Ҫ��ѯ������:";
            char c[20];
            cin >> c;
            bool flag = searchByName(c);
            if(flag)cout << "��ѯ��ϣ�"<<endl;
            else cout << "��ѯ��ϣ������в����ڸ�ѧ����"<<endl;
        }else if(op == 6){
            cout << "������Ҫ��ѯ��ѧ��:";
            int a;
            cin >> a;
            revise(a);
        }else if(op == 7){
            searchCourse();
        }else if(op == 8){
            ofstream fout;
            fout.open("student.dat" , ios::trunc);
            fout.close();
            cout << "�����ɣ�"<<endl;
        }else if(op == 9){
            system("cls");
            menu();
        }else if(op == 10){
            cout << "������Ҫɾ����ѧ����ѧ��:";
            int a;
            cin >> a;
            deleteByCno(a);
        }else if(op == 11){
        	cout << "������Ҫ��ѯѧ����ѧ��:";
            int a;
            cin >> a;
            printSum(a);
            
		} else if(op != -1){
            cout << "��Ч���룬��ο��˵��������롣����" << endl;
        }

    }while(op != -1);
	cout << "���˳�����";
    return 0;

}