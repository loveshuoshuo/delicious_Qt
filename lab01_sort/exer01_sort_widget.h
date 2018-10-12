#ifndef EXER01_SORT_WIDGET_H
#define EXER01_SORT_WIDGET_H

#include <QWidget>
#include <qdebug.h>

namespace Ui {
class exer01_sort_Widget;
}

class exer01_sort_Widget : public QWidget
{
    Q_OBJECT

public:
    explicit exer01_sort_Widget(QWidget *parent = 0);

    void sortbyname(QVector<QVector<QString>> &table0);
    void sortbylesson1(QVector<QVector<QString>> &table0);
    void sortbylesson2(QVector<QVector<QString>> &table0);

    ~exer01_sort_Widget();
private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


private:
    Ui::exer01_sort_Widget *ui;
};
//class student
//{
//public:
//    student(QString &number,QString &name,QString &lesson1,QString &lesson2)
//    {
//        this->name=name;
//        this->number=number;
//        this->lesson1=lesson1;
//        this->lesson2=lesson2;

//    }
//private:
//    QString number;
//    QString name;
//    QString lesson1;
//    QString lesson2;
//};

#endif // EXER01_SORT_WIDGET_H