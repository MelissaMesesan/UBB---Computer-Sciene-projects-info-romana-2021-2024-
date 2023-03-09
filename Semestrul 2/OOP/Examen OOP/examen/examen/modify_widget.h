#pragma once

#include <QWidget>
#include <QPainter>
#include <memory>

class Modify_widget : public QWidget
{
	Q_OBJECT
private:
	int nr;

	/*
		se deseneaza elipsa
	*/
	virtual void paintEvent(QPaintEvent* event) override
	{
		qDebug("ma redesenes");
		QPainter pnt{ this };
		for (int i = 1; i <= nr; i++)
		{
			pnt.drawEllipse(QPoint(3, 0), 3 * i, i);
		}
	}
public:

	/*
		constructor
	*/
	Modify_widget(int nr) : nr{ nr } {
	};

	/*
		se tot modifica in functie de cate sunt
	*/
	void paint_songs(int nr)
	{
		this->nr = nr;
		this->repaint();
	}

	~Modify_widget() = default;
};
