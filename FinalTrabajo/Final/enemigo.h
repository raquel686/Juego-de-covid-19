#pragma once
class enemigo :public celemento
{
private:
	int cambio;
	vector<balaenem*>arrbal;
	direccion direnem;
public:
	enemigo(int _x, int _y);
	~enemigo();
	void dibujar(Graphics^ g);
	void mover(Graphics^ g);
	void setcambio(int _c);
	int getcambio();
	void agregarbala();
	void dibujarbala(Graphics^ g);
	void moverbala(Graphics^ g);
	void eliminarbalaporpos(int pos);
	void eliminarbala(Graphics^ g);
	balaenem* getbala(int i);
	int getcantbal();
	void limpiarbala();
};

