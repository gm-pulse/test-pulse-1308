#ifndef USERMODULE_H
#define USERMODULE_H
#include <QPushButton>
#include <QMessageBox>
#include <QMainWindow>
#include <QVBoxLayout>

#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QString>
#include <QLineEdit>

class UserModule: public QWidget
{
	Q_OBJECT

public:
	explicit UserModule  (void * previous, const QString & name, QWidget * parent = 0);
	~ UserModule(){}

	void Execute();

public slots:
	void newOrder_clickedSlot();
	void branchChoosedChanged();


private:
	QGridLayout *   mGridLayout;
	QLabel      *   mLabel;
	QLabel      *   branchLabel;
	QLabel      *   ClientLabel;
	QLabel      *   obsLabel;
	QComboBox   *   comboBox;
	QLineEdit   *   txtClientInfos;
	QLineEdit   *   obsClientInfos;

};
#endif
