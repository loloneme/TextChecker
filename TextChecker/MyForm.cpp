#include "MyForm.h"
#include <map>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	TextChecker::MyForm form;
	Application::Run(% form);

}