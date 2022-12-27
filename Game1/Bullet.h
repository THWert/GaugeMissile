#pragma once
class Bullet
{
public:
	ObLine missile;
	ObCircle missilePet;

public:
	Bullet();
	void Update(ObRect player);
	void Render();

	bool Shoot(ObRect player, ObRect gaugebar);

private:
	float gaugespeed;
};

