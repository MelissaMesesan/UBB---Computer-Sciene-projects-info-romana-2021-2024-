#pragma once

#include <QWidget>
#include "Service.h"
#include "Observer.h"

class DrawTrucks : public QWidget, public Observer
{
private:
	Service& service;
	void setup();
public:
	DrawTrucks(Service& service) : service{ service }
	{
		setup();
	};
	void update_me() override;

	void paintEvent(QPaintEvent* event) override;

	~DrawTrucks();
};

