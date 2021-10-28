#include "showgen.h"
#include "ui_showgen.h"

showgen::showgen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showgen)
{
    ui->setupUi(this);
}

showgen::~showgen()
{
    delete ui;
}

void showgen::on_pushButton_2_clicked()
{

}

void showgen::on_pushButton_clicked()
{

}

