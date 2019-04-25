#pragma once
#include "Ann.h"
namespace NeuralNet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для DataLook
	/// </summary>
	public ref class DataLook : public System::Windows::Forms::Form
	{
	public:
		Ann *ann;
		Bitmap ^ bmp;
		Graphics ^g;
		int BegImage;
		int NimagesX, NimagesY;
		DataLook(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			ann = new Ann();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~DataLook()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(33, 24);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 50);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(44, 108);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 23);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(206, 45);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(206, 124);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Показать";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// DataLook
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(545, 255);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"DataLook";
			this->Text = L"DataLook";
			this->Load += gcnew System::EventHandler(this, &DataLook::DataLook_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void DataLook_Load(System::Object^  sender, System::EventArgs^  e)
	{
		int h, w;
		int wp, hp, hl;
		System::Drawing::Rectangle workingRectangle = Screen::PrimaryScreen->WorkingArea;
		this->Size = System::Drawing::Size(workingRectangle.Width - 10, workingRectangle.Height - 10);
		this->Left = 0;
		this->Top = 0;
		h = workingRectangle.Height - 10;
		w = workingRectangle.Width - 10;
		wp = w - 20;
		hp = h - 80;
		hl = 20;
		// pictureBox1
		pictureBox1->Top = 10;
		pictureBox1->Left = 0;
		pictureBox1->Width = wp;
		pictureBox1->Height = hp;
		bmp = gcnew Bitmap(wp, hp);
		pictureBox1->Image = bmp;
		System::Drawing::SolidBrush^ br =
			gcnew System::Drawing::SolidBrush(System::Drawing::Color::White);
		g = Graphics::FromImage(bmp);
		g->FillRectangle(br, 0, 0, wp, hp);
		BegImage = 0;
		NimagesX = wp / ann->NinputX - 3;
		NimagesY = hp / (ann->NinputY + hl);
		// button
		button1->Top = hp + 5;
		button1->Left = 10;
		label1->Top = button1->Top;
		label1->Left = button1->Left + button1->Width + 10;
		textBox1->Top = button1->Top;
		textBox1->Left = label1->Left + label1->Width + 10;
		DrawImages();
	}
			 void DrawImages()
			 {
				 int i, j, m, z;
				 int x, y, hx, hy;
				 int p, q;
				 Color col;
				 unsigned char cc;
				 cc = 0;
				 int hl = 20;
				 hx = ann->NinputX;
				 hy = ann->NinputY;

				 System::Drawing::SolidBrush^ br =
					 gcnew System::Drawing::SolidBrush(System::Drawing::Color::White);
				 g = Graphics::FromImage(bmp);
				 g->FillRectangle(br, 0, 0, NimagesX*hx, NimagesY*(hy + hl));
				 m = BegImage;
				 x = 0;
				 y = 0;
				 for (j = 0; j < NimagesY; j++)
				 {
					 for (i = 0; i < NimagesX; i++)
					 {
						 x = 0;
						 y = 0;
						 if (m < ann->Number)
						 {
							 for (q = 0; q < ann->NinputY; q++)
							 {
								 for (p = 0; p < ann->NinputX; p++)
								 {
									 z = q*ann->NinputX + p;
									 z = z + m*ann->NinputX*ann->NinputY;
									 cc = ann->Data[z];
									 if (ann->Type == 0)
									 {
										 if (cc == 0)
											 cc = 255;
										 else
											 cc = 0;
										 col = Color::FromArgb(cc, cc, cc);
										 bmp->SetPixel(x + i*ann->NinputX, y + j*(ann->NinputY + hl), col);
									 }
									 if (ann->Type == 1)
									 {
										 col = Color::FromArgb(cc, cc, cc);
										 bmp->SetPixel(x + i*ann->NinputX, y + j*(ann->NinputY + hl), col);
									 }

									 x++;
								 }
								 x = 0;
								 y++;
							 }
						 }
						 m++;
					 }
				 }
				 pictureBox1->Image = bmp;
			 }

	};
}
