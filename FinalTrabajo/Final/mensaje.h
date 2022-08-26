#pragma once
class mensaje :public celemento
{
private:

public:
	mensaje(int _x, int _y, int _dx, int _dy);
	~mensaje();
	void dibujar(Graphics^ g);
	void mover(Graphics^ g);
	/*void setdireccion(int _dx, int _dy);*/

};


