#pragma once
class policia :public celemento
{
private:
public:
	policia(int _x, int _y);
	~policia();
	void dibujar(Graphics^ g);
	void mover(Graphics^ g);
};


