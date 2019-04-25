// NeuralNet.cpp: главный файл проекта.

#include "stdafx.h"

using namespace System;
[STAThreadAttribute]

int main(array<System::String ^> ^args)
{
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	NeuralNet::MainForm nameObjectForm;
	System::Windows::Forms::Application::Run(%nameObjectForm);

	return 0;
}