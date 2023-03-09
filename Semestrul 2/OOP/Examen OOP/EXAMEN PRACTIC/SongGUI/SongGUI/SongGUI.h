#pragma once

#include <QtWidgets/QWidget>
#include "ui_SongGUI.h"
#include "Service.h"
#include <QLabel>
#include <QTableView>
#include "MyModel.h"
#include <QPushButton>
#include <QLineEdit>
#include <QSlider>
#include <QDebug>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QPainter>

class SongGUI : public QWidget
{
	Q_OBJECT

public:
	SongGUI(Service& service, MyModel& model) : service{ service }, model{model}
	{
		setup();
	};


private:
	int current_id = -1;
	Service& service;
	void setup();

	QTableView* table;
	MyModel& model;
	QPushButton* update_button, * delete_button;
	QSlider* rank_slider;
	QLineEdit* title_le;
	QWidget* draw_widget;
	QLabel* lrank;

	QVBoxLayout* main_layout;
	/*
	For table clicj
	i - QModelIndex - where the clicked happened
	*/
	void click_event(const QModelIndex& i);
	/*
	when slider is changed, set value for label
	val - int - the new value
	*/
	void slider_event(const int& val);
	/*
	when update is clickec
	*/
	void update_event();
	/*
	when delete is clicked
	*/
	void delete_event();
	/*
	update the widget
	*/
	void update_me();

	void paintEvent(QPaintEvent* event) override;

};