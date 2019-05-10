#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include "widget.h"
#include <QHBoxLayout>

class AddDialog : public QDialog {
    Q_OBJECT

private:
    Widget parent;

public:
    AddDialog(Widget * = nullptr);
    void createChooseType();
    void createButtons();
};

#endif // ADDDIALOG_H
