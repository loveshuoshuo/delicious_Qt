
/****************************************
        first Qt homework
        written 15/9/2018
        Author  Joseph_Zhou
 ****************************************/



#include <QCoreApplication>
#include <QDebug>
#include<cstdio>
#include<climits>
#include<windef.h>
#include<QList>
using namespace std;

#define  MAX(x, y)  ( ((x) > (y)) ? (x) : (y) )
#define  MIN(x, y)  ( ((x) < (y)) ? (x) : (y) )                             //比较大小

#define  QuadraWORD_LLO(xxx)  ((quint8) ((quint32)(xxx)     ))
#define  QuadraWORD_HLO(xxx)  ((quint8) ((quint32)(xxx) >> 8))
#define  QuadraWORD_LHI(xxx)  ((quint8) ((quint32)(xxx) >>16))
#define  QuadraWORD_HHI(xxx)  ((quint8) ((quint32)(xxx) >>24))              //取4字节数字的各个字节


//#define  W_PTR( var )  ( (word *) ((void *) &(var)) )

//typedef  unsigned long int  uint32;      /* Unsigned 32 bit value */
//typedef  unsigned short     uint16;      /* Unsigned 16 bit value */
//typedef  unsigned char      uint8;       /* Unsigned 8  bit value */      //宏定义无符号数

int main(int argc,char *argv[])
{
    quint32 u=0x12345678;                                                   //原始数据
    quint8 hhi,lhi,hlo,llo;                                                 //各四位
    llo=QuadraWORD_LLO(u);
    hlo=QuadraWORD_HLO(u);
    lhi=QuadraWORD_LHI(u);
    hhi=QuadraWORD_HHI(u);
    QList<quint8> values;
    values.append({hhi,lhi,hlo,llo});                                       //将四位数append到一起

    //for (int x : values )

    //输出原始数和各字节数
    qDebug().nospace()<<"原始值:"<<"0x"<<hex<<u<<"=="<<dec<<u;               //function nospace() ensure that no space between characters
    qDebug().nospace()<<"0x"<<hex<<hhi<<"=="<<dec<<hhi<<" 0x"<<hex<<lhi<<"=="<<dec<<lhi<<" 0\
x"<<hex<<hlo<<"=="<<dec<<hlo<<" 0x"<<hex<<llo<<"=="<<dec<<llo;

//    qDebug().nospace()<<"0x"<<hex<<lhi<<"=="<<dec<<lhi;
//    qDebug().nospace()<<"0x"<<hex<<hlo<<"=="<<dec<<hlo;
//    qDebug().nospace()<<"0x"<<hex<<llo<<"=="<<dec<<llo;

    //输出上下两字节的最大最小值
    qDebug().nospace()<<"最高和次高8位最大值:"<<"0x"<<hex<<MAX(hhi, lhi)<<'<'<<dec<<MAX(hhi, lhi)<<'>';
    qDebug().nospace()<<"最低和次低8位最小值:"<<"0x"<<hex<<MIN(hlo, llo)<<'<'<<dec<<MIN(hlo, llo)<<'>';

    //输出组合后的数字
    quint32 transf=(hlo<<24)+(llo<<8)+(hhi<<16)+(lhi);
    qDebug().nospace()<<"重新组合后数值:"<<"0x"<<hex<<transf<<'<'<<dec<<transf<<'>';

    //输出排序后的list
    qDebug()<<values;
    std::sort(values.begin(),values.end(),std::greater<qint8>());       //Sort函数使用模板:   Sort(start,end,排序方法)
    qDebug()<<values;

    //int ui=sizeof(values);            //可以返回values的大小
    //qDebug()<<ui;
    //qDebug()<<"0x"<<hex<<hhi<<lhi<<hlo<<llo;
    //qDebug()<<W_PTR(values);
    //qDebug()<<hex<<values[3];
}


