#pragma once

namespace TextChecker {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Threading;

	ref class Vars
	{
	public:
		static Dictionary<String^, String^>^ langsDict = gcnew Dictionary<String^, String^>();
		static String^ chosenLang;
		static String^ affPath = "";
		static String^ dicPath = "";
		static int mistakes = 0;
		static cli::array<String^>^ signs{"\n", "\t", "!", " ", ".", "&", "^", "#", ",", "/", "&", "?", ":", ";", "(", ")", "*"};
		static bool isWord(String^ word) {
			for each (Char c in word) {
				if (!Char::IsLetter(c)) {
					return false;
				}
			}
			return true;
		}
	};
}


