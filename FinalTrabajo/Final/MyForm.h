#pragma once
#include "pch.h"
#include "MyForm2.h"
namespace Final {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			objman = new juego();
			objman->generarjugador();
			
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::Windows::Forms::Timer^ timer2;
	private: System::Windows::Forms::Timer^ timer3;
	private: System::Windows::Forms::Timer^ timer4;
	private: System::Windows::Forms::Timer^ timer5;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ labelvidas;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ labeltiempo;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ labelpuntaje;
	private: System::Windows::Forms::Timer^ timer6;
	private: System::Windows::Forms::Timer^ timer7;
	private: System::Windows::Forms::Timer^ timer8;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ labelbolsas;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer4 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer5 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->labelvidas = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->labeltiempo = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->labelpuntaje = (gcnew System::Windows::Forms::Label());
			this->timer6 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer7 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer8 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->labelbolsas = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Interval = 1850;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// timer3
			// 
			this->timer3->Interval = 2000;
			this->timer3->Tick += gcnew System::EventHandler(this, &MyForm::timer3_Tick);
			// 
			// timer4
			// 
			this->timer4->Interval = 4000;
			this->timer4->Tick += gcnew System::EventHandler(this, &MyForm::timer4_Tick);
			// 
			// timer5
			// 
			this->timer5->Interval = 5000;
			this->timer5->Tick += gcnew System::EventHandler(this, &MyForm::timer5_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(20, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(36, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Vidas:";
			// 
			// labelvidas
			// 
			this->labelvidas->AutoSize = true;
			this->labelvidas->Location = System::Drawing::Point(62, 21);
			this->labelvidas->Name = L"labelvidas";
			this->labelvidas->Size = System::Drawing::Size(35, 13);
			this->labelvidas->TabIndex = 1;
			this->labelvidas->Text = L"label2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(166, 21);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(45, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Tiempo:";
			// 
			// labeltiempo
			// 
			this->labeltiempo->AutoSize = true;
			this->labeltiempo->Location = System::Drawing::Point(217, 21);
			this->labeltiempo->Name = L"labeltiempo";
			this->labeltiempo->Size = System::Drawing::Size(35, 13);
			this->labeltiempo->TabIndex = 3;
			this->labeltiempo->Text = L"label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(331, 21);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(46, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Puntaje:";
			// 
			// labelpuntaje
			// 
			this->labelpuntaje->AutoSize = true;
			this->labelpuntaje->Location = System::Drawing::Point(383, 21);
			this->labelpuntaje->Name = L"labelpuntaje";
			this->labelpuntaje->Size = System::Drawing::Size(35, 13);
			this->labelpuntaje->TabIndex = 5;
			this->labelpuntaje->Text = L"label6";
			// 
			// timer6
			// 
			this->timer6->Interval = 1000;
			this->timer6->Tick += gcnew System::EventHandler(this, &MyForm::timer6_Tick);
			// 
			// timer7
			// 
			this->timer7->Interval = 3000;
			this->timer7->Tick += gcnew System::EventHandler(this, &MyForm::timer7_Tick);
			// 
			// timer8
			// 
			this->timer8->Interval = 30000;
			this->timer8->Tick += gcnew System::EventHandler(this, &MyForm::timer8_Tick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(507, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(90, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Bolsas recogidas:";
			// 
			// labelbolsas
			// 
			this->labelbolsas->AutoSize = true;
			this->labelbolsas->Location = System::Drawing::Point(604, 21);
			this->labelbolsas->Name = L"labelbolsas";
			this->labelbolsas->Size = System::Drawing::Size(35, 13);
			this->labelbolsas->TabIndex = 7;
			this->labelbolsas->Text = L"label4";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(714, 362);
			this->Controls->Add(this->labelbolsas);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->labelpuntaje);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->labeltiempo);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->labelvidas);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: juego* objman; Random b;
		   int a = b.Next(5, 11);
		   MyForm2^ config = gcnew MyForm2();
		 
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		if (config->getStart() == false) {
			config->ShowDialog();
			labelvidas->Text = config->vidas();
			objman->setvidajugador(Convert::ToInt32(config->vidas()));
			objman->settiempo(Convert::ToInt32(config->tiempo())*60);
		}
		if (config->getStart() == true) {
			timer1->Enabled = true;
			timer6->Enabled = true;
			timer2->Enabled = true;
			timer3->Enabled = true;
			timer7->Enabled = true;
			timer4->Enabled = true;
			timer5->Enabled = true;
			timer8->Enabled = true;

		}

	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g;
		g = this->CreateGraphics();
		BufferedGraphicsContext^ espacioBuffer = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacioBuffer->Allocate(g, this->ClientRectangle);
		Bitmap^ imagen;
		if (objman->getnivel() == 1)
			imagen = gcnew Bitmap("escenario1.png");
		if (objman->getnivel() == 2)
			imagen = gcnew Bitmap("escenario2.png");
		int ancho = g->VisibleClipBounds.Width;
		int alto = g->VisibleClipBounds.Height;
		buffer->Graphics->DrawImage(imagen, 0, 0, ancho, alto);
		objman->dibujarenem(buffer->Graphics);
		objman->dibujarjugador(buffer->Graphics);
		objman->moverenem(buffer->Graphics);
		objman->colision();
		objman->eliminarmen(buffer->Graphics);
		objman->pasarnivel(timer2,timer3,timer4,timer5, Convert::ToInt32(config->tiempo())*60,a);
		if (objman->getnivel() > 2) {
			timer1->Enabled = false;
			timer6->Enabled = false;
			MessageBox::Show("¡Ganaste el juego!", "Felicitaciones", MessageBoxButtons::OK);
			exit(0);
		}
		if (objman->getvidajugador() < 0) {
			timer1->Enabled = false;
			timer6->Enabled = false;
			MessageBox::Show("Game Over", "Perdiste", MessageBoxButtons::OK);
			exit(0);
		}
		buffer->Render(g);
		labelpuntaje->Text = (objman->getpuntaje()).ToString();
		labelvidas->Text = (objman->getvidajugador()).ToString();
		labeltiempo->Text = (objman->gettiempo()).ToString();
		labelbolsas->Text = (objman->getbolsasreco()).ToString();
		delete buffer;
		delete espacioBuffer;
		delete g;
		delete imagen;
	}
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		objman->generarenem();
		if (objman->getcantasin() == a / 2)
			timer2->Enabled = false;
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		Graphics^ g;
		g = this->CreateGraphics();
		if (e->KeyCode == Keys::Space)
			objman->disparo();
		objman->moverjug(g, e->KeyCode);
		delete g;
	}
	private: System::Void timer3_Tick(System::Object^ sender, System::EventArgs^ e) {
		objman->generasalu();
		if (objman->getcantsalu() ==  a / 2)
			timer3->Enabled = false;
	}
private: System::Void timer4_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (objman->gettiempo() < b.Next(30, (Convert::ToInt32(config->tiempo()) * 60) - 15)) {
		objman->generarpolicia();
		timer4->Enabled = false;
	}
}
private: System::Void timer5_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (objman->gettiempo() < b.Next(30, (Convert::ToInt32(config->tiempo()) * 60) - 15)) {
		objman->generarenfermera();
		timer5->Enabled = false;
	}
}
private: System::Void timer6_Tick(System::Object^ sender, System::EventArgs^ e) {
	 objman->settiempo(objman->gettiempo() - 1);
	if (objman->gettiempo() < 0) {
		timer1->Enabled = false;
		timer6->Enabled = false;
		MessageBox::Show("Game Over", "Perdiste", MessageBoxButtons::OK);
		exit(0);
	}
}
private: System::Void timer7_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (config->dificultad() == "Principiante") {
		timer7->Enabled = false;
	}
	else {
		objman->disparoasin();
		objman->disparosalu();
	}
}
private: System::Void timer8_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (objman->gettiempo() < Convert::ToInt32(config->tiempo()) * 60 - 5) {
		objman->generabasura();
	}
}
};
}
