#pragma once
class balaenem :public celemento
{
private:

public:
	balaenem(int _x, int _y, int _dx, int _dy);
	~balaenem();
	void dibujar(Graphics^ g);
	void mover(Graphics^ g);

};
