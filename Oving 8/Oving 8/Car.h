#pragma once
class Car
{
	unsigned int freeSeats;
public:
	Car(unsigned int freeSeats);

	bool hasFreeSeats() const;
	void reserveFreeSeat();

	virtual ~Car() {};
};

