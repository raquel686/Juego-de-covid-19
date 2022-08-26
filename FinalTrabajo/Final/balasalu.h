#pragma once
class balasalu :public celemento
{
private:

public:
	balasalu(int _x, int _y, int _dx, int _dy);
	~balasalu();
	void dibujar(Graphics^ g);
	void mover(Graphics^ g);
};

