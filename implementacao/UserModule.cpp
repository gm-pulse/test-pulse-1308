#include "UserModule.h"


#include <iostream>
using namespace std;

UserModule::UserModule(void * previous, const QString & name, QWidget * parent)
        : QWidget(parent)
        , mGridLayout(new QGridLayout(this))
        , mLabel(new QLabel(name, this))
{
	Execute();
}

void UserModule::Execute()
{

        cout << "UserModule::Execute" << endl;
	// necessário criar um pedido de estoque do tipo saída, escolhendo
	// a filial, o usuário, o cliente e uma observação para entrega.

        mGridLayout->removeWidget(mLabel);
        delete mLabel;

        QPushButton * newOrderButton       = new QPushButton(this);
        newOrderButton->setText("Novo Pedido");

        QObject::connect(newOrderButton, SIGNAL(clicked()),this, SLOT(newOrder_clickedSlot()));

        newOrderButton->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

        QWidget* centralWidget = new QWidget(this);
        centralWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

        QVBoxLayout* layout = new QVBoxLayout(centralWidget);


	branchLabel = new QLabel("Escolha a filial: ");

	branchs_comboBox = new QComboBox;
	branchs_comboBox->addItem(tr(""));
	branchs_comboBox->addItem(tr("Filial 1"));
	branchs_comboBox->addItem(tr("Filial 2"));
	branchs_comboBox->addItem(tr("Filial 3"));
        branchs_comboBox->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
	connect(branchs_comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(branchChoosedChanged()));

	ClientLabel = new QLabel("Entre com informações do cliente: ");
	obsLabel    = new QLabel("Alguma observação? ");

	txtClientInfos = new QLineEdit(this);
        txtClientInfos->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

	obsClientInfos = new QLineEdit(this);
        obsClientInfos->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

        mGridLayout->addWidget(newOrderButton);
        mGridLayout->addWidget(branchLabel);
        mGridLayout->addWidget(branchs_comboBox);
        mGridLayout->addWidget(ClientLabel);
        mGridLayout->addWidget(txtClientInfos);
        mGridLayout->addWidget(obsLabel);
        mGridLayout->addWidget(obsClientInfos);

        show();

}

void UserModule::branchChoosedChanged()
{
	QString text = branchs_comboBox->currentText();
	cout << "Filial escolhida: " << text.toStdString() << endl;

}

void UserModule::newOrder_clickedSlot()
{
	QString text = txtClientInfos->text();
	cout << "Cliente: " << text.toStdString() << endl;
}
