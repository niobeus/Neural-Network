#pragma once
#include "Ann.h"
#include <time.h>
#using <System.Windows.Forms.DataVisualization.dll>

namespace NeuralNet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для NetTrain
	/// </summary>
	public ref class NetTrain : public System::Windows::Forms::Form
	{
	public:
		Ann *ann;
		int Step;
		float MaxErr;
		float Er, Erg;
		float Ero;
		time_t start;
		time_t end;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  checkBox2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	public:
		NetTrain(void)
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
		~NetTrain()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	protected:
	private: System::Windows::Forms::Label^  label2;

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(21, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(195, 23);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Размерность входа       0";
			// 
			// label2
			// 
			this->label2->Location = System::Drawing::Point(25, 46);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(191, 23);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Размерность выхода    0";
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(28, 73);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(176, 23);
			this->label3->TabIndex = 2;
			this->label3->Text = L"векторов       1";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(221, 23);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(39, 17);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Эпох";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(277, 23);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(63, 22);
			this->textBox1->TabIndex = 4;
			this->textBox1->Text = L"10000";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(223, 50);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(41, 17);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Delta";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(277, 50);
			this->textBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(63, 22);
			this->textBox2->TabIndex = 6;
			this->textBox2->Text = L"0,1";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(223, 78);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(37, 17);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Beta";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(277, 80);
			this->textBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(63, 22);
			this->textBox3->TabIndex = 8;
			this->textBox3->Text = L"1";
			// 
			// label7
			// 
			this->label7->Location = System::Drawing::Point(347, 23);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(123, 23);
			this->label7->TabIndex = 9;
			this->label7->Text = L"Макс. err";
			// 
			// label8
			// 
			this->label8->Location = System::Drawing::Point(349, 50);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(120, 23);
			this->label8->TabIndex = 10;
			this->label8->Text = L"Шаг вывода";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(353, 80);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(107, 17);
			this->label9->TabIndex = 11;
			this->label9->Text = L"Размер группы";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(475, 23);
			this->textBox4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(57, 22);
			this->textBox4->TabIndex = 12;
			this->textBox4->Text = L"0,01";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(477, 50);
			this->textBox5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(56, 22);
			this->textBox5->TabIndex = 13;
			this->textBox5->Text = L"1";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(477, 80);
			this->textBox6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(56, 22);
			this->textBox6->TabIndex = 14;
			this->textBox6->Text = L"1";
			// 
			// label10
			// 
			this->label10->Location = System::Drawing::Point(549, 23);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(89, 23);
			this->label10->TabIndex = 15;
			this->label10->Text = L"Слоев";
			// 
			// label11
			// 
			this->label11->Location = System::Drawing::Point(549, 54);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(89, 23);
			this->label11->TabIndex = 16;
			this->label11->Text = L"Тек. слой";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(656, 20);
			this->textBox7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(48, 22);
			this->textBox7->TabIndex = 17;
			this->textBox7->Text = L"1";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(656, 50);
			this->textBox8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(48, 22);
			this->textBox8->TabIndex = 18;
			this->textBox8->Text = L"15";
			this->textBox8->Leave += gcnew System::EventHandler(this, &NetTrain::textBox8_Leave);
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"15", L"0", L"0", L"0", L"0" });
			this->listBox1->Location = System::Drawing::Point(737, 20);
			this->listBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(48, 84);
			this->listBox1->TabIndex = 19;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &NetTrain::listBox1_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(869, 20);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 20;
			this->button1->Text = L"Старт";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &NetTrain::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(869, 54);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(99, 23);
			this->button2->TabIndex = 21;
			this->button2->Text = L"Продолжить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &NetTrain::button2_Click);
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(25, 138);
			this->chart1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(760, 300);
			this->chart1->TabIndex = 22;
			this->chart1->Text = L"chart1";
			// 
			// label12
			// 
			this->label12->Location = System::Drawing::Point(28, 455);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(765, 23);
			this->label12->TabIndex = 23;
			this->label12->Text = L"Результат: ";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(815, 138);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(56, 21);
			this->checkBox1->TabIndex = 24;
			this->checkBox1->Text = L"bias";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->Location = System::Drawing::Point(815, 177);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(146, 24);
			this->checkBox2->TabIndex = 25;
			this->checkBox2->Text = L"Stochastic grad";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Location = System::Drawing::Point(815, 227);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(153, 121);
			this->groupBox1->TabIndex = 26;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Activate";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(7, 22);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(79, 21);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Sigmoid";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(7, 50);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(62, 21);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Tanh";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(7, 85);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(65, 21);
			this->radioButton3->TabIndex = 2;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"ReLU";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// NetTrain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(981, 485);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"NetTrain";
			this->Text = L"NetTrain";
			this->Load += gcnew System::EventHandler(this, &NetTrain::NetTrain_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		double td, ero;
		if (button1->Text == "Старт")
		{
			start = time(NULL);
			chart1->Series[0]->Points->Clear();
			GetParams();
			button1->Text = "Стоп";
			button2->Enabled = false;
			ann->CalcInterrupt = false;
			ann->Init();
			if (checkBox1->Checked)
			{
				ann->IsBias = 1;
			}
			else
			{
				ann->IsBias = 0;
			}
			TrainNet();
			return;
		}
		else
		{
			end = time(NULL);
			button1->Text = "Старт";
			ann->CalcInterrupt = true;
			button2->Enabled = true;
			OutResult();

		}
	}

			 void OutResult()
			 {
				 double td, ero;
				 String ^s, ^s1;
				 end = time(NULL);
				 s = "Execution Time: ";
				 td = (double)(end - start);
				 s1 = System::Convert::ToString(td);
				 s = s + s1;
				 s = s + "  second ";
				 s1 = System::Convert::ToString(Ero);
				 s = s + " Current error: ";
				 s = s + s1;
				 label12->Text = "Result: " + s;
			 }

			 void GetParams()
			 {
				 int i, k;
				 float x;
				 String ^ s = gcnew String("");
				 s = textBox7->Text;
				 k = System::Convert::ToInt32(s);
				 ann->NumberLayers = k;
				 s = textBox1->Text;
				 k = System::Convert::ToInt32(s);
				 ann->Epoch = k;
				 s = textBox5->Text;
				 k = System::Convert::ToInt32(s);
				 Step = k;
				 s = textBox4->Text;
				 x = System::Convert::ToDouble(s);
				 MaxErr = x;
				 s = textBox2->Text;
				 x = System::Convert::ToDouble(s);
				 ann->Delta = x;
				 s = textBox3->Text;
				 x = System::Convert::ToDouble(s);
				 ann->Beta = x;
				 k = ann->NumberLayers;
				 ann->neurons[0] = ann->NinputX*ann->NinputY;
				 for (i = 1; i <= k; i++)
				 {
					 s = listBox1->Items[i - 1]->ToString();
					 ann->neurons[i] = System::Convert::ToInt32(s);
				 }
				 ann->neurons[k + 1] = ann->Noutput;
				 s = textBox6->Text;
				 k = System::Convert::ToInt32(s);
				 ann->SizeGroup = k;
				 if (radioButton1->Checked)
				 {
					 ann->TypeActivate = 1;
				 }
				 if (radioButton2->Checked)
				 {
					 ann->TypeActivate = 2;
				 }
				 if (radioButton3->Checked)
				 {
					 ann->TypeActivate = 3;
				 }

			 }
	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		int k;
		k = listBox1->SelectedIndex;
		if (k >= 0)
		{
			textBox8->Text = listBox1->Items[k]->ToString();
		}
	}
	private: System::Void textBox8_Leave(System::Object^  sender, System::EventArgs^  e)
	{
		int k;
		String ^ s = gcnew String("");
		s = textBox8->Text;
		k = listBox1->SelectedIndex;
		listBox1->Items[k] = s;
	}

			 void TrainNet()
			 {
				 int i, j, k, m, z, n, Ind, p;
				 i = 0;
				 do
				 {
					 Application::DoEvents();
					 if (ann->CalcInterrupt)
						 return;
					 // subgrups
					 if (checkBox2->Checked)
					 {
						 ann->DistrInputs();
						 n = ann->SizeGroup;
						 Ind = 0;
					 }
					 Er = 0.0;
					 if (checkBox2->Checked)
					 {
						 for (j = 0; j<ann->NumberGroups; j++)
						 {
							 ann->ClearDiff();
							 z = 0;
							 Erg = 0;
							 while (z<n)
							 {
								 k = ann->GroupNumbers[Ind];
								 p = k*ann->Ninput;
								 for (m = 0; m<ann->Ninput; m++)
								 {
									 ann->Y[0][m] = ann->Data[p];
									 p++;
								 }
								 Application::DoEvents();
								 if (ann->CalcInterrupt)
									 return;
								 ann->Forward();
								 ann->CalcErr(k);
								 Er += ann->Eri / ann->Number;
								 Erg += ann->Eri / ann->SizeGroup;
								 ann->Backward(k);
								 ann->SumGrad();
								 z++;
								 Ind++;
							 }
							 ann->CopySum();
							 Ind++;
							 ann->CorrectWeights(k);
						 }
					 }
					 else
					 {
						 for (j = 0; j<ann->Number; j++)
						 {
							 k = j*ann->Ninput;
							 for (m = 0; m<ann->Ninput; m++)
							 {
								 //					 ann->Y[0][m]=ann->Data[k]*1.0/(255.0*9900);
								 ann->Y[0][m] = ann->Data[k];
								 k++;
							 }
							 Application::DoEvents();
							 if (ann->CalcInterrupt)
								 return;
							 ann->Forward();
							 ann->CalcErr(j);
							 Er += ann->Eri / ann->Number;
							 ann->Backward(j);
							 ann->CorrectWeights(j);
						 }
					 }
					 // out
					 if (i % Step == 0)
					 {
						 // out error
						 OutResult();
						 chart1->Series[0]->Points->AddXY(i, Er);
						 chart1->Refresh();
					 }
					 i++;
					 Ero = Er;
				 } while (i<ann->Epoch && Er>MaxErr);
			 }

	private: System::Void NetTrain_Load(System::Object^  sender, System::EventArgs^  e)
	{
		String ^ s = gcnew String("");
		if (ann->Type == 0 || ann->Type == 1)
		{
			s = (ann->NinputX*ann->NinputY).ToString();
			s = "Размерность входа: " + s;
			label1->Text = s;
			s = (ann->Noutput).ToString();
			s = "Размерность выхода: " + s;
			label2->Text = s;
			s = (ann->Number).ToString();
			s = "Векторов: " + s;
			label3->Text = s;
		}


	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		// continue
	}
	};
}
