#pragma once
class ambulancia :public celemento
{
private:
public:
	ambulancia(int _x, int _y);
	~ambulancia();
	void dibujar(Graphics^ g);
	void mover(Graphics^ g);
};

