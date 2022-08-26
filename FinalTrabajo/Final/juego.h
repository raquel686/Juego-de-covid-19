#pragma once
class juego
{
private:
	vector<enemigo*>arren;
	cjugador* objjug;
	vector<enemigo2*>arrsalu;
	vector<policia*>objpol;
	vector<ambulancia*>objenfer;
	vector<basura*>arrbas;
	int vidajugador;
	int puntaje;
	int tiempo;
	int nivel;
	int numbasura;
public:
	juego();
	~juego();
	void generarenem();
	void generasalu();
	void generarjugador();
	void generarpolicia();
	void generarenfermera();
	void generabasura();
	void dibujarenem(Graphics^ g);
	void moverenem(Graphics^ g);
	void dibujarjugador(Graphics^ g);
	void moverjug(Graphics^ g, Keys key);
	void disparo();
	void disparoasin();
	void disparosalu();
	void colision();
	void eliminarmen(Graphics^ g);
	int getcantasin();
	int getcantsalu();
	int getvidajugador();
	void setvidajugador(int v);
	int getpuntaje();
	void setpuntaje(int p);
	int gettiempo();
	void settiempo(int t);
	int getnivel();
	int getbolsasreco();
	void pasarnivel(Timer^ t,Timer^t2,Timer^t3,Timer^t4, int time,int cantotal);
};


