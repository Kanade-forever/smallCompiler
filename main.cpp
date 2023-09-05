#include "widget.h"
#include <QApplication>


/*
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();



    return a.exec();
}*/

//using namespace std;
int sysnum; //当前四元式个数
int wrong;  //出错 1-出错 0-未出错
char temp;  //
Token Next; //
FILE *fp;   //文件指针
int row;    //当前扫描行数

Symbol *Sym;      //变量列表首指针
Symbol *cp_Sym;   //变量列表动态指针

int var_count;    //四元式中临时变量当前个数
char *op1;
char *op2;
char *op3;
char *op4;
Four FourList;     //四元式列表首指针
Four *cp_FourList; //四元式列表动态指针
Link *Ture;        //真出口
Link *False;       //假出口
Link *cp_Ture;        //真出口
Link *cp_False;       //假出口
int grade;
LinkStack Sign;    //变量栈
LinkStack Var;     //符号栈

void initial() {   //初始化
    op1 = (char *)malloc(10);
    op2 = (char *)malloc(10);
    op3 = (char *)malloc(10);
    op4 = (char *)malloc(10);


    sysnum = 0;
    var_count = 0;
    row = 1;

    Sym = (Symbol *)malloc(sizeof(Symbol));
    cp_Sym = Sym;
    Sym->Next = nullptr;

    cp_FourList = &FourList;
    cp_FourList->Next = nullptr;

    Ture = (Link *)malloc(sizeof(Link));    //真出口
    Ture->Next = nullptr;
    False = (Link *)malloc(sizeof(Link));   //假出口
    False->Next = nullptr;
    cp_Ture = Ture;
    cp_False = False;
    grade = 0;

    InitStack(&Sign);
    InitStack(&Var);

}

int main(int argc,char *argv[]) {
    initial();
    qDebug() << "Compiling..." << endl;
    fp = fopen("pro.txt", "r");
    if (fp == nullptr) {
        printf("文件错误！");
        exit(0);
    }
    temp = fgetc(fp);
    Next = getNextToken();
    program();
    if (wrong == 0 && temp == EOF) {
        qDebug() << "Compiled!" << endl;
    }
    //PrintSignForm();
    PrintFour();

    QApplication a(argc,argv);
    Widget w;
    w.show();
    return a.exec();
}
