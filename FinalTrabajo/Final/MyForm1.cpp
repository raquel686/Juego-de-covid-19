#include "MyForm1.h"
using namespace System;
using namespace System::Windows::Forms; [STAThread]
void main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);  Application::Run(gcnew
        Final::MyForm1()); //Project 1 es el nombre del proyecto
}

