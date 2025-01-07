#include "MainWindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent) {
	// Create a central widget to hold all your controls
	QWidget *central = new QWidget(this);

	// Create a vertical layout
	QVBoxLayout *layout = new QVBoxLayout(central);

	// Create a button as an example
	myButton = new QPushButton("Click Me", central);

	// Add it to the layout
	layout->addWidget(myButton);

	// Set the layout on the central widget
	central->setLayout(layout);

	// Set the central widget of the MainWindow
	setCentralWidget(central);

	// Optionally: connect signals/slots here (e.g., connect the button to something)
	connect(myButton, &QPushButton::clicked, this, &MainWindow::onButtonClicked);
}

void MainWindow::onButtonClicked() {
	qDebug() << "Button was clicked!";
}
