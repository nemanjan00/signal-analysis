#pragma once

#include <QMainWindow>

class QPushButton;

class MainWindow : public QMainWindow {
	Q_OBJECT  // Needed for Qt signals/slots

	public:
		explicit MainWindow(QWidget *parent = nullptr);

	private:
		// Example widget
		QPushButton *myButton;
	private slots:
		// This must match exactly how you call it in connect()
		void onButtonClicked();
};
