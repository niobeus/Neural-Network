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
	/// Сводка для NetTest
	/// </summary>
	public ref class NetTest : public System::Windows::Forms::Form
	{
	public:
		Ann *ann;
		Bitmap^ bmp;
		Graphics^ g;
		NetTest(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~NetTest()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::ListBox^  listBox1;
	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(23, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(189, 23);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Размерность входа:         0";
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(26, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(186, 23);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Размерность выхода:      0";
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(23, 90);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(223, 19);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Количество векторов:     0";
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(29, 126);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(87, 23);
			this->label4->TabIndex = 3;
			this->label4->Text = L"N вектора       1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(122, 127);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(87, 22);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L"1";
			// 
			// label5
			// 
			this->label5->Location = System::Drawing::Point(32, 172);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(84, 23);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Масштаб: ";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(123, 172);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(86, 22);
			this->textBox2->TabIndex = 6;
			this->textBox2->Text = L"2";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(32, 216);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(109, 23);
			this->button1->TabIndex = 7;
			this->button1->Text = L"распознать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &NetTest::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(35, 267);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(128, 23);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Распознать все";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &NetTest::button2_Click);
			// 
			// label6
			// 
			this->label6->Location = System::Drawing::Point(32, 324);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(214, 23);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Результат";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(276, 30);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(334, 324);
			this->pictureBox1->TabIndex = 10;
			this->pictureBox1->TabStop = false;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Location = System::Drawing::Point(637, 30);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(138, 324);
			this->listBox1->TabIndex = 11;
			// 
			// NetTest
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(858, 405);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"NetTest";
			this->Text = L"NetTest";
			this->Load += gcnew System::EventHandler(this, &NetTest::NetTest_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		int k, w, h;
		int i, j, x, y, m, z, p, q;
		int Sc;
		String ^s;
		Color col;
		float r, f;
		unsigned char cc;
		SolidBrush ^br;
		s = textBox2->Text;
		k = System::Convert::ToInt32(s);
		Sc = k;
		w = ann->NinputX*k;
		h = ann->NinputY*k;
		pictureBox1->Width = w;
		pictureBox1->Height = h;
		bmp = gcnew Bitmap(w, h);
		pictureBox1->Image = bmp;
		g = Graphics::FromImage(bmp);
		Color c1;
		c1 = System::Drawing::Color::FromArgb(255, 255, 255);
		br = gcnew SolidBrush(c1);
		g->FillRectangle(br, 0, 0, w, h);
		s = textBox1->Text;
		m = System::Convert::ToInt32(s);
		x = 0;
		y = 0;
		for (q = 0; q<ann->NinputY; q++)
		{
			for (p = 0; p<ann->NinputX; p++)
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
					for (i = 0; i<Sc; i++)
					{
						for (j = 0; j<Sc; j++)
						{
							bmp->SetPixel(x + i, y + j, col);
						}
					}
				}
				if (ann->Type == 1)
				{
					col = Color::FromArgb(cc, cc, cc);
					for (i = 0; i<Sc; i++)
					{
						for (j = 0; j<Sc; j++)
						{
							bmp->SetPixel(x + i, y + j, col);
						}
					}
				}
				x += Sc;
			}
			x = 0;
			y += Sc;
		}

		if (ann->Type<2)
		{
			k = m*ann->Ninput;
			for (m = 0; m<ann->Ninput; m++)
			{
				ann->Y[0][m] = ann->Data[k];
				k++;
			}
		}
		ann->Forward();

		listBox1->Items->Clear();
		for (i = 0; i<ann->Noutput; i++)
		{
			k = ann->NumberLayers + 1;
			s = ann->Y[k][i].ToString();
			listBox1->Items->Add(s);
		}
		r = 0;
		k = 0;
		m = listBox1->Items->Count;
		for (i = 0; i<m; i++)
		{
			s = listBox1->Items[i]->ToString();
			f = System::Convert::ToDouble(s);
			if (f>r)
			{
				r = f;
				k = i;
			}
		}
		s = System::Convert::ToString(k + 1);
		s = "Класс: " + s;
		label6->Text = s;

	}

	private: System::Void NetTest_Load(System::Object^  sender, System::EventArgs^  e)
	{
		String ^s;
		if (ann->Type == 0 || ann->Type == 1)
		{
			s = (ann->NinputX*ann->NinputY).ToString();
			s = "Размерность входа: " + s;
			label1->Text = s;
			s = (ann->Noutput).ToString();
			s = "Размерность выхода: " + s;
			label2->Text = s;
			s = (ann->Number).ToString();
			s = "Количество векторов: " + s;
			label3->Text = s;
		}

	}
			 int Recognize(int m)
			 {
				 int k, p, q, z, i, n;
				 unsigned char cc;
				 float f, r;
				 if (ann->Type<2)
				 {
					 k = 0;
					 for (q = 0; q<ann->NinputY; q++)
					 {
						 for (p = 0; p<ann->NinputX; p++)
						 {
							 z = q*ann->NinputX + p;
							 z = z + m*ann->NinputX*ann->NinputY;
							 cc = ann->Data[z];
							 ann->Y[0][k] = (double)cc;
							 k++;
						 }
					 }
					 ann->Forward();
					 r = 0;
					 k = 0;
					 n = ann->Noutput;
					 z = ann->NumberLayers + 1;
					 for (i = 0; i<n; i++)
					 {
						 f = ann->Y[z][i];
						 if (f>r)
						 {
							 r = f;
							 k = i;
						 }
					 }
					 return k;
				 }
				 return 0;
			 }

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		int i, k, m, n;
		double pr;
		String ^s;
		m = 0;
		for (i = 0; i<ann->Number; i++)
		{
			k = Recognize(i);
			if (k == ann->Classes[i] - 1)
				m++;
		}
		pr = m*100.0 / ann->Number;
		n = (int)pr;
		s = System::Convert::ToString(n);
		s = "Распознано: " + s + " %";
		label6->Text = s;
	}
	};
}
