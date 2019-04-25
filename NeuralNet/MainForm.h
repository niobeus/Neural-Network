#pragma once
#include "Ann.h"
#include <string.h>
#include "DataLook.h"
#include "NetTrain.h"
#include "NetTest.h"
namespace NeuralNet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Runtime::InteropServices;
	/// <summary>
	/// —водка дл€ MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		Ann *ann;
		DataLook ^DL;
		NetTrain ^NT;
		NetTest ^NE;
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			ann = new Ann();
			DL = gcnew DataLook();
			NT = gcnew NetTrain();
			NE = gcnew NetTest();
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openDataToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  loadNetToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveNetToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  viewToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  trainToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  testToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadNetToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveNetToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->viewToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->testToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->fileToolStripMenuItem,
					this->viewToolStripMenuItem, this->trainToolStripMenuItem, this->testToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(651, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->openDataToolStripMenuItem,
					this->loadNetToolStripMenuItem, this->saveNetToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(44, 24);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openDataToolStripMenuItem
			// 
			this->openDataToolStripMenuItem->Name = L"openDataToolStripMenuItem";
			this->openDataToolStripMenuItem->Size = System::Drawing::Size(148, 24);
			this->openDataToolStripMenuItem->Text = L"Open data";
			this->openDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::openDataToolStripMenuItem_Click);
			// 
			// loadNetToolStripMenuItem
			// 
			this->loadNetToolStripMenuItem->Name = L"loadNetToolStripMenuItem";
			this->loadNetToolStripMenuItem->Size = System::Drawing::Size(148, 24);
			this->loadNetToolStripMenuItem->Text = L"Load net";
			// 
			// saveNetToolStripMenuItem
			// 
			this->saveNetToolStripMenuItem->Name = L"saveNetToolStripMenuItem";
			this->saveNetToolStripMenuItem->Size = System::Drawing::Size(148, 24);
			this->saveNetToolStripMenuItem->Text = L"Save net";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(148, 24);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::exitToolStripMenuItem_Click);
			// 
			// viewToolStripMenuItem
			// 
			this->viewToolStripMenuItem->Name = L"viewToolStripMenuItem";
			this->viewToolStripMenuItem->Size = System::Drawing::Size(53, 24);
			this->viewToolStripMenuItem->Text = L"View";
			this->viewToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::viewToolStripMenuItem_Click);
			// 
			// trainToolStripMenuItem
			// 
			this->trainToolStripMenuItem->Name = L"trainToolStripMenuItem";
			this->trainToolStripMenuItem->Size = System::Drawing::Size(54, 24);
			this->trainToolStripMenuItem->Text = L"Train";
			this->trainToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::trainToolStripMenuItem_Click);
			// 
			// testToolStripMenuItem
			// 
			this->testToolStripMenuItem->Name = L"testToolStripMenuItem";
			this->testToolStripMenuItem->Size = System::Drawing::Size(48, 24);
			this->testToolStripMenuItem->Text = L"Test";
			this->testToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::testToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"text(*.txt)|*.txt|all files(*.*)|*.*";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(651, 208);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"Neural Nets";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Close();
	}
	private: System::Void openDataToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			String ^ s = gcnew String("");
			s = openFileDialog1->FileName;
			char* chars =
				(char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			strcpy(ann->fName, chars);
			Marshal::FreeHGlobal(IntPtr((void*)chars));
			ann->Load();
		}
	}
	private: System::Void viewToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (ann->Number == 0)
			return;
		DL->ann = ann;
		DL->ShowDialog();
	}
	private: System::Void trainToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (ann->Number == 0)
			return;
		NT->ann = ann;
		NT->ShowDialog();
	}
	private: System::Void testToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		NE->ann = NT->ann;
		NE->ShowDialog();
	}
	};
}

