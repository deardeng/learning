#include "qt.h"
#include <QtWidgets/QApplication>
#include <QPushButton>
int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QPushButton* pb = new QPushButton("°´Å¥");
	QObject::connect(pb, SIGNAL(clicked()), &app, SLOT(quit()));
	pb->show();
	return app.exec();
}
