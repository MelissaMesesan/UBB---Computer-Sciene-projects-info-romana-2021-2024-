#include "DrawTrucks.h"

#include <QPainter>

void DrawTrucks::setup()
{
	this->setWindowTitle("Drawing trucks");
}

void DrawTrucks::update_me()
{
	this->repaint();
}

void DrawTrucks::paintEvent(QPaintEvent* event)
{
	QPainter pnt{ this };

	for (int i = 0; i < service.get_all().size(); i++)
	{
		pnt.drawEllipse(QPoint(this->width() / 2, this->height() / 2), 10 * i, 10 * i);
	}
}

DrawTrucks::~DrawTrucks()
{
}