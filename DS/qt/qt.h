#ifndef QT_H
#define QT_H

#include <QtWidgets/QMainWindow>
#include "ui_qt.h"

class qt : public QMainWindow
{
	Q_OBJECT

public:
	qt(QWidget *parent = 0);
	~qt();

private:
	Ui::qtClass ui;
};

#endif // QT_H
