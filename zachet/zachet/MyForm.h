#pragma once

namespace zachet {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::Windows::Forms::Button^ button1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(42, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(22, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"x1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(95, 35);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 1;
			this->textBox1->Text = L"-2";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(95, 78);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 22);
			this->textBox2->TabIndex = 3;
			this->textBox2->Text = L"5";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(42, 78);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(22, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"x2";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(95, 178);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(100, 22);
			this->textBox3->TabIndex = 7;
			this->textBox3->Text = L"3";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(42, 178);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(23, 17);
			this->label3->TabIndex = 6;
			this->label3->Text = L"y2";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(95, 135);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 22);
			this->textBox4->TabIndex = 5;
			this->textBox4->Text = L"-4";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(42, 135);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(23, 17);
			this->label4->TabIndex = 4;
			this->label4->Text = L"y1";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(271, 35);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(770, 417);
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(67, 252);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(128, 48);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Нарисовать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1329, 513);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public: int unit = 50; //шаг в пискелах
	public: delegate double DelegatePtr(double); //тип функции для рисования
	private:  double f(double x) { //конкретная функция, которую рисуем
		double y = Math::Cos(Math::Sqrt(x));
		return Double::IsNaN(y) ? 0 : y;
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int pW = pictureBox1->Width, pH = pictureBox1->Height;
		Bitmap^ img = gcnew Bitmap(pW, pH);
		//создаем поверхность для рисования (изображение) с размером элемента управления PictureBox
		Graphics^ g = Graphics::FromImage(img); //создаем устройство для рисования на поверхности
		
		//находим середину и рисуем линии осей:
		int mX = int(pW / 2 - pW / 2 % unit);
		int mY = int(pH / 2 - pH / 2 % unit);
		g->DrawLine(Pens::Red, mX, 0, mX, pH);
		g->DrawLine(Pens::Red, 0, mY, pW, mY);
		g->ScaleTransform(1, -1); //переворачиваем ось Y для удобства восприятия
		g->TranslateTransform((float)mX, -(float)mY); //смещаем нулевую координату на пересечение осей
		//рисуем график:
		DelegatePtr^ f = gcnew DelegatePtr(this, &MyForm::f);
		double x1 = -1., x2 = 10., s = 0.25; //границы рисования
		double x = x1;
		double y;
		System::Collections::Generic::List<PointF>^ Points =
			gcnew System::Collections::Generic::List<PointF>(); //коллекция точек графика
		while (x < x2) {
			y = f(x);
			Points->Add(PointF(x * unit, y * unit));
			//добавляем точку в коллекцию. Полученные координаты сразу переводим в экранные единицы
			x += s;
		}
		g->DrawLines(Pens::Green, Points->ToArray()); //рисование линий графика
		delete g; //освобождение ресурсов устройства рисования
		this->pictureBox1->Image = img; //присвоение и отображение изображения в PictureBox
	}
};
}
