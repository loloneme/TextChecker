#pragma once
#include "MyForm1.h"
#include "Vars.h"




namespace TextChecker {

	using namespace NHunspell;
	using namespace System;
	using namespace System::Text::RegularExpressions;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Threading;
	using namespace Runtime::InteropServices;
	using namespace std;

	

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{

			InitializeComponent();
			Vars::langsDict = getLangsDict();
			List<String^>^ availableLangs = getLangs(Vars::langsDict);

			for each (String ^ s in availableLangs) {
				this->langChoose->Items->Add(s);
			}


			String^ info = "Добро пожаловать в приложение TextChecker, которое поможет Вам проверить правильность написанного Вами текста. Чтобы начать, откройте Ваш .txt файл, либо введите текст в поле";
			MessageBox::Show(this, info, "Приветствие", MessageBoxButtons::OK, MessageBoxIcon::Information);

		}



	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ openButton;
	protected:


	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::RichTextBox^ textField;

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ToolStripMenuItem;
	private: System::Windows::Forms::ComboBox^ langChoose;


	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Button^ checkButton;



	private: System::Windows::Forms::ListBox^ suggestList;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ saveButton;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;





	private: System::ComponentModel::IContainer^ components;











	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->openButton = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->textField = (gcnew System::Windows::Forms::RichTextBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->langChoose = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkButton = (gcnew System::Windows::Forms::Button());
			this->suggestList = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// openButton
			// 
			this->openButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->openButton->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->openButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->openButton->Location = System::Drawing::Point(13, 42);
			this->openButton->Margin = System::Windows::Forms::Padding(4);
			this->openButton->Name = L"openButton";
			this->openButton->Size = System::Drawing::Size(225, 56);
			this->openButton->TabIndex = 1;
			this->openButton->Text = L"Выбрать файл";
			this->openButton->UseVisualStyleBackColor = true;
			this->openButton->Click += gcnew System::EventHandler(this, &MyForm::fileButton_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"txt files (*.txt)|*.txt";
			// 
			// textField
			// 
			this->textField->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textField->Location = System::Drawing::Point(13, 121);
			this->textField->Margin = System::Windows::Forms::Padding(4);
			this->textField->Name = L"textField";
			this->textField->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->textField->Size = System::Drawing::Size(795, 561);
			this->textField->TabIndex = 2;
			this->textField->Text = L"";
			this->textField->SelectionChanged += gcnew System::EventHandler(this, &MyForm::textField_SelectionChanged);
			this->textField->TextChanged += gcnew System::EventHandler(this, &MyForm::textField_TextChanged);
			this->textField->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::textField_MouseDown);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1034, 28);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ToolStripMenuItem
			// 
			this->ToolStripMenuItem->Name = L"ToolStripMenuItem";
			this->ToolStripMenuItem->Size = System::Drawing::Size(81, 24);
			this->ToolStripMenuItem->Text = L"Справка";
			this->ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::Info_Click);
			// 
			// langChoose
			// 
			this->langChoose->BackColor = System::Drawing::SystemColors::Window;
			this->langChoose->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->langChoose->FormattingEnabled = true;
			this->langChoose->Location = System::Drawing::Point(281, 70);
			this->langChoose->Name = L"langChoose";
			this->langChoose->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->langChoose->Size = System::Drawing::Size(207, 28);
			this->langChoose->TabIndex = 4;
			this->langChoose->SelectionChangeCommitted += gcnew System::EventHandler(this, &MyForm::Lang_Selected);
			this->langChoose->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::langChoose_MouseDown);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(276, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(248, 25);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Выбрать язык для проверки:";
			// 
			// checkButton
			// 
			this->checkButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->checkButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->checkButton->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->checkButton->FlatAppearance->BorderSize = 0;
			this->checkButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->checkButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkButton->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->checkButton->Location = System::Drawing::Point(578, 42);
			this->checkButton->Name = L"checkButton";
			this->checkButton->Size = System::Drawing::Size(230, 56);
			this->checkButton->TabIndex = 6;
			this->checkButton->Text = L"Проверить текст";
			this->checkButton->UseVisualStyleBackColor = false;
			this->checkButton->Visible = false;
			this->checkButton->Click += gcnew System::EventHandler(this, &MyForm::checkButton_Click);
			// 
			// suggestList
			// 
			this->suggestList->FormattingEnabled = true;
			this->suggestList->ItemHeight = 20;
			this->suggestList->Location = System::Drawing::Point(831, 324);
			this->suggestList->Name = L"suggestList";
			this->suggestList->Size = System::Drawing::Size(178, 164);
			this->suggestList->TabIndex = 7;
			this->suggestList->Visible = false;
			this->suggestList->VisibleChanged += gcnew System::EventHandler(this, &MyForm::suggestList_VisibleChanged);
			this->suggestList->DoubleClick += gcnew System::EventHandler(this, &MyForm::suggestList_DoubleClick);
			// 
			// label2
			// 
			this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(815, 121);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(208, 200);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Выберите из списка подходящий орфографически правильный вариант слова с помощью д"
				L"войного щелчка:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label2->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(826, 528);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(208, 28);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Количество ошибок: ";
			this->label3->Visible = false;
			// 
			// saveButton
			// 
			this->saveButton->Location = System::Drawing::Point(12, 706);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(796, 28);
			this->saveButton->TabIndex = 10;
			this->saveButton->Text = L"Сохранить файл";
			this->saveButton->UseVisualStyleBackColor = true;
			this->saveButton->Click += gcnew System::EventHandler(this, &MyForm::saveButton_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::RosyBrown;
			this->ClientSize = System::Drawing::Size(1034, 746);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->suggestList);
			this->Controls->Add(this->checkButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->langChoose);
			this->Controls->Add(this->textField);
			this->Controls->Add(this->openButton);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"TextChecker";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		//Функция, считывающая файл с кодами ISO, возвращает словарь,
		//где ключ - код, а значение - название языка на русском
		Dictionary<String^, String^>^ getLangsDict() {
			Dictionary<String^, String^>^ d = gcnew Dictionary<String^, String^>();
			try {
				StreamReader^ isoFile = gcnew StreamReader("../files/isocodes.txt");
				while (!isoFile->EndOfStream) {
					String^ s = isoFile->ReadLine();
					cli::array<String^>^ words = s->Split('\t');
					String^ code = words[0];
					String^ name = words[1];
					d->Add(code, name);
				}
			}
			catch (Exception^ e) {
				MessageBox::Show(this, "Ошибка при открытии файла с ISO кодами языков", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			return d;
		}

		List<String^>^ getLangs(Dictionary<String^, String^>^ codeDict) {
			List<String^>^ res = gcnew List<String^>();
			for each (KeyValuePair<String^, String^> kvp in codeDict)
			{
				String^ dicFilePath = "../files/dics/" + kvp.Key + ".dic";
				String^ affFilePath = "../files/dics/" + kvp.Key + ".aff";
				if ((File::Exists(dicFilePath)) && (File::Exists(affFilePath))) {
					res->Add(kvp.Value);
				}
			}
			return res;
		}

		void check() {
			Vars::mistakes = 0;
			Hunspell^ hunspell = gcnew Hunspell(Vars::affPath, Vars::dicPath);
			int last = 0;
			String^ alltext = textField->Text;
			try {
				for each (String ^ word in alltext->Split(Vars::signs, StringSplitOptions::RemoveEmptyEntries)) {
					if (Vars::isWord(word)) {
						int index = alltext->IndexOf(word);
						textField->Select(last + index, word->Length);

						if (!hunspell->Spell(word)) {
							textField->SelectionColor = Color::Red;
							Vars::mistakes += 1;
						}
						else if (textField->SelectionColor == Color::Red) {
							textField->SelectionColor = Color::Black;
						}

						last += index + word->Length;
						alltext = alltext->Substring(index + word->Length);
						textField->SelectionStart = textField->TextLength;
						textField->SelectionColor = Color::Black;
					}
				}
				label3->Visible = true;
				label3->Text = "Количество ошибок: " + Vars::mistakes.ToString();
				int len = textField->Text->Split(Vars::signs, StringSplitOptions::RemoveEmptyEntries)->Length;
				if (Vars::mistakes >= len * 0.7 && len >= 100) {
					MessageBox::Show(this, "Вы уверены, что выбрали нужный язык?", "Слишком много ошибок в тексте!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
			catch (Exception^ e) {
				MessageBox::Show(this, "Неизвестная ошибка", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

#pragma endregion
private: System::Void fileButton_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ FileName = "";
		openFileDialog1->FileName = "";


		if (openFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK) 
		{
			FileName = openFileDialog1->FileName;
		}

		try {
			StreamReader^ file = File::OpenText(FileName);
			textField->Text = file->ReadToEnd();
			if (Vars::affPath != "") {
				check();
			}

		}
		catch (Exception^ e) {
			MessageBox::Show(this, "Файл не был открыт", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
}


private: System::Void Info_Click(System::Object^ sender, System::EventArgs^ e) {
	MyForm1^ f1 = gcnew MyForm1();
	f1->Show();
}

private: System::Void Lang_Selected(System::Object^ sender, System::EventArgs^ e) {
	Vars::chosenLang = langChoose->GetItemText(langChoose->SelectedItem);
	for each (String^ k in Vars::langsDict->Keys)
	{
		if (Vars::langsDict[k] == Vars::chosenLang) {
			Vars::affPath = "../files/dics/" + k + ".aff";
			Vars::dicPath = "../files/dics/" + k + ".dic";
			break;
		}
	}
	if (textField->Text != "") {
		checkButton->Visible = true;
	}
}

private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}


private: System::Void textField_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (textField->SelectedText != "") {
		Hunspell^ hunspell = gcnew Hunspell(Vars::affPath, Vars::dicPath);


		if (textField->SelectedText->Split(Vars::signs, StringSplitOptions::RemoveEmptyEntries)->Length == 1) {
			List<String^>^ suggs = hunspell->Suggest(textField->SelectedText->Split(Vars::signs, StringSplitOptions::RemoveEmptyEntries)[0]);

			if (e->Button == System::Windows::Forms::MouseButtons::Right)
			{
				suggestList->Visible = true;
				for each (String ^ suggestion in suggs) {
					suggestList->Items->Add(suggestion);
				}

			}
		}

	}
}
private: System::Void checkButton_Click(System::Object^ sender, System::EventArgs^ e) {
	check();
}
private: System::Void langChoose_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (textField->Text == "") {
		MessageBox::Show(this, "Сначала введите текст!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
private: System::Void textField_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (textField->Text == "") {
		checkButton->Visible = false;
		label3->Visible = false;
	}
}
private: System::Void textField_SelectionChanged(System::Object^ sender, System::EventArgs^ e) {
	suggestList->Items->Clear();
	suggestList->Visible = false;
}

private: System::Void suggestList_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
	if (suggestList->SelectedItem) {
		String^ newWord = suggestList->SelectedItem->ToString();

		if (textField->SelectedText[textField->SelectedText->Length - 1] == ' ') {
			newWord += " ";
		}
		textField->SelectionColor = Color::Black;
		textField->SelectedText = textField->SelectedText->Replace(textField->SelectedText, newWord);
		Vars::mistakes -= 1;
		label3->Text = "Количество ошибок: " + Vars::mistakes.ToString();

	}
}

private: System::Void suggestList_VisibleChanged(System::Object^ sender, System::EventArgs^ e) {
	if (suggestList->Visible) {
		label2->Visible = true;
	}
	else {
		label2->Visible = false;
	}
}

private: System::Void saveButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textField->Text != "") {
		saveFileDialog1->CreatePrompt = true;
		saveFileDialog1->OverwritePrompt = true;

		saveFileDialog1->FileName = "myText";
		saveFileDialog1->DefaultExt = "txt";
		saveFileDialog1->Filter ="Text files (*.txt)|*.txt";
		saveFileDialog1->InitialDirectory = Environment::GetFolderPath(Environment::SpecialFolder::MyDocuments);

		if (saveFileDialog1->ShowDialog() == Windows::Forms::DialogResult::OK && saveFileDialog1->FileName->Length > 0)
		{ 
			textField->SaveFile(saveFileDialog1->FileName, RichTextBoxStreamType::PlainText);
		}
	}
	else {
		MessageBox::Show(this, "Невозможно сохранить пустой файл", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

}

};
}
