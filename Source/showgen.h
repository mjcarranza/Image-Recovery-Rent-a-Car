#ifndef SHOWGEN_H
#define SHOWGEN_H

#include <QWidget>

namespace Ui {
class showgen;
}

class showgen : public QWidget
{
    Q_OBJECT

public:
    explicit showgen(QWidget *parent = nullptr);
    ~showgen();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::showgen *ui;
};

#endif // SHOWGEN_H
