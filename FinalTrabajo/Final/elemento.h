#pragma once
class celemento
{
protected:
	int x, y;
	int indx, indy;
	int dx, dy;
	int ancho, alto;
public:
	celemento();
	~celemento();
	Rectangle getarea();
	int getx();
	int gety();
	int getancho();
	int getalto();
	int getindx();
	void setdireccion();

};

