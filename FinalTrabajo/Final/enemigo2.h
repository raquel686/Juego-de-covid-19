#pragma once
class enemigo2 :public celemento
{
private:
	int cambio;
	direccion diresalu;
	vector<balasalu*>arrbal;
public:

	enemigo2(int px, int py);
	~enemigo2();
	void dibujar(Graphics^ g);
	void mover(Graphics^ g);
	void setcambio(int _c);
	int getcambio();
	void agregarbala();
	void dibujarbala(Graphics^ g);
	void moverbala(Graphics^ g);
	void eliminarbalaporpos(int pos);
	void eliminarbala(Graphics^ g);
	balasalu* getbala(int i);
	int getcantbal();
	void limpiarbala();
};
