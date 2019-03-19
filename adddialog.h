#ifndef ADDDIALOG_H
#define ADDDIALOG_H
#include <QDialog>


class AddDialog : public QDialog{
    Q_OBJECT

private:
    QWidget parent;

public:
    AddDialog(QWidget * = nullptr);
    void createChooseType();
    void createButtons();
};

#endif // ADDDIALOG_H
