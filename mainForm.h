#pragma once
#include <cstddef>
#include "hidapi.h"
#include "brightness.h"


namespace LGUltrafineBrightness {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for mainForm
	/// </summary>
	public ref class mainForm : public System::Windows::Forms::Form
	{
	public:
		mainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			hid_device* handle = handledevice();
			int brightness = get_brightness(handle);
			current_brightness_lbl->Text = (int((float(brightness) / 54000) * 100.0).ToString()) + "%";

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~mainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ current_brightness_lbl;
	protected:


	private: System::Windows::Forms::Label^ adjbrt_lbl;




	private: System::Windows::Forms::Button^ increase_btn;
	private: System::Windows::Forms::Button^ decrease_btn;
	private: System::Windows::Forms::Button^ fine_decrease_btn;
	private: System::Windows::Forms::Button^ fine_increase_btn;
	private: System::Windows::Forms::Label^ finetune_lbl;
	private: System::Windows::Forms::Button^ min_btn;
	private: System::Windows::Forms::Button^ max_btn;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ brightnesslbl;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->current_brightness_lbl = (gcnew System::Windows::Forms::Label());
			this->adjbrt_lbl = (gcnew System::Windows::Forms::Label());
			this->increase_btn = (gcnew System::Windows::Forms::Button());
			this->decrease_btn = (gcnew System::Windows::Forms::Button());
			this->fine_decrease_btn = (gcnew System::Windows::Forms::Button());
			this->fine_increase_btn = (gcnew System::Windows::Forms::Button());
			this->finetune_lbl = (gcnew System::Windows::Forms::Label());
			this->min_btn = (gcnew System::Windows::Forms::Button());
			this->max_btn = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->brightnesslbl = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// current_brightness_lbl
			// 
			this->current_brightness_lbl->AutoSize = true;
			this->current_brightness_lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->current_brightness_lbl->Location = System::Drawing::Point(296, 288);
			this->current_brightness_lbl->Name = L"current_brightness_lbl";
			this->current_brightness_lbl->Size = System::Drawing::Size(44, 31);
			this->current_brightness_lbl->TabIndex = 1;
			this->current_brightness_lbl->Text = L"00";
			// 
			// adjbrt_lbl
			// 
			this->adjbrt_lbl->AutoSize = true;
			this->adjbrt_lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->adjbrt_lbl->Location = System::Drawing::Point(53, 57);
			this->adjbrt_lbl->Name = L"adjbrt_lbl";
			this->adjbrt_lbl->Size = System::Drawing::Size(118, 17);
			this->adjbrt_lbl->TabIndex = 5;
			this->adjbrt_lbl->Text = L"Adjust Brightness";
			// 
			// increase_btn
			// 
			this->increase_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->increase_btn->Location = System::Drawing::Point(56, 102);
			this->increase_btn->Name = L"increase_btn";
			this->increase_btn->Size = System::Drawing::Size(96, 42);
			this->increase_btn->TabIndex = 6;
			this->increase_btn->Text = L"+";
			this->increase_btn->UseVisualStyleBackColor = true;
			this->increase_btn->Click += gcnew System::EventHandler(this, &mainForm::increase_btn_Click);
			// 
			// decrease_btn
			// 
			this->decrease_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->decrease_btn->Location = System::Drawing::Point(56, 159);
			this->decrease_btn->Name = L"decrease_btn";
			this->decrease_btn->Size = System::Drawing::Size(96, 42);
			this->decrease_btn->TabIndex = 7;
			this->decrease_btn->Text = L"-";
			this->decrease_btn->UseVisualStyleBackColor = true;
			this->decrease_btn->Click += gcnew System::EventHandler(this, &mainForm::decrease_btn_Click);
			// 
			// fine_decrease_btn
			// 
			this->fine_decrease_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fine_decrease_btn->Location = System::Drawing::Point(220, 159);
			this->fine_decrease_btn->Name = L"fine_decrease_btn";
			this->fine_decrease_btn->Size = System::Drawing::Size(96, 42);
			this->fine_decrease_btn->TabIndex = 10;
			this->fine_decrease_btn->Text = L"-";
			this->fine_decrease_btn->UseVisualStyleBackColor = true;
			this->fine_decrease_btn->Click += gcnew System::EventHandler(this, &mainForm::fine_decrease_btn_Click);
			// 
			// fine_increase_btn
			// 
			this->fine_increase_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->fine_increase_btn->Location = System::Drawing::Point(220, 102);
			this->fine_increase_btn->Name = L"fine_increase_btn";
			this->fine_increase_btn->Size = System::Drawing::Size(96, 42);
			this->fine_increase_btn->TabIndex = 9;
			this->fine_increase_btn->Text = L"+";
			this->fine_increase_btn->UseVisualStyleBackColor = true;
			this->fine_increase_btn->Click += gcnew System::EventHandler(this, &mainForm::fine_increase_btn_Click);
			// 
			// finetune_lbl
			// 
			this->finetune_lbl->AutoSize = true;
			this->finetune_lbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->finetune_lbl->Location = System::Drawing::Point(235, 57);
			this->finetune_lbl->Name = L"finetune_lbl";
			this->finetune_lbl->Size = System::Drawing::Size(72, 17);
			this->finetune_lbl->TabIndex = 8;
			this->finetune_lbl->Text = L"Fine Tune";
			// 
			// min_btn
			// 
			this->min_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->min_btn->Location = System::Drawing::Point(369, 159);
			this->min_btn->Name = L"min_btn";
			this->min_btn->Size = System::Drawing::Size(96, 42);
			this->min_btn->TabIndex = 13;
			this->min_btn->Text = L"Min";
			this->min_btn->UseVisualStyleBackColor = true;
			this->min_btn->Click += gcnew System::EventHandler(this, &mainForm::min_btn_Click);
			// 
			// max_btn
			// 
			this->max_btn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->max_btn->Location = System::Drawing::Point(369, 102);
			this->max_btn->Name = L"max_btn";
			this->max_btn->Size = System::Drawing::Size(96, 42);
			this->max_btn->TabIndex = 12;
			this->max_btn->Text = L"Max";
			this->max_btn->UseVisualStyleBackColor = true;
			this->max_btn->Click += gcnew System::EventHandler(this, &mainForm::max_btn_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(387, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(67, 17);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Max / Min";
			// 
			// brightnesslbl
			// 
			this->brightnesslbl->AutoSize = true;
			this->brightnesslbl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->brightnesslbl->Location = System::Drawing::Point(129, 288);
			this->brightnesslbl->Name = L"brightnesslbl";
			this->brightnesslbl->Size = System::Drawing::Size(151, 31);
			this->brightnesslbl->TabIndex = 14;
			this->brightnesslbl->Text = L"Brightness:";
			// 
			// mainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(539, 378);
			this->Controls->Add(this->brightnesslbl);
			this->Controls->Add(this->min_btn);
			this->Controls->Add(this->max_btn);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->fine_decrease_btn);
			this->Controls->Add(this->fine_increase_btn);
			this->Controls->Add(this->finetune_lbl);
			this->Controls->Add(this->decrease_btn);
			this->Controls->Add(this->increase_btn);
			this->Controls->Add(this->adjbrt_lbl);
			this->Controls->Add(this->current_brightness_lbl);
			this->Name = L"mainForm";
			this->Text = L"LG UlraFine  Brightness Control";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



private: System::Void increase_btn_Click(System::Object^ sender, System::EventArgs^ e) {

	hid_device* handle = handledevice();
	int brightness = get_brightness(handle);

	brightness = next_step(brightness, big_steps);
	set_brightness(handle, brightness);
	current_brightness_lbl->Text = (int((float(brightness) / 54000) * 100.0).ToString()) + "%";

}

private: System::Void fine_increase_btn_Click(System::Object^ sender, System::EventArgs^ e) {

	hid_device* handle = handledevice();
	int brightness = get_brightness(handle);

	brightness = next_step(brightness, small_steps);
	set_brightness(handle, brightness);
	current_brightness_lbl->Text = (int((float(brightness) / 54000) * 100.0).ToString()) + "%";


}
private: System::Void fine_decrease_btn_Click(System::Object^ sender, System::EventArgs^ e) {

	hid_device* handle = handledevice();
	int brightness = get_brightness(handle);

	brightness = prev_step(brightness, small_steps);
	set_brightness(handle, brightness);
	current_brightness_lbl->Text = (int((float(brightness) / 54000) * 100.0).ToString()) + "%";
}
private: System::Void max_btn_Click(System::Object^ sender, System::EventArgs^ e) {

	hid_device* handle = handledevice();
	int brightness = get_brightness(handle);

	brightness = max_brightness;
	set_brightness(handle, brightness);
	current_brightness_lbl->Text = (int((float(brightness) / 54000) * 100.0).ToString()) + "%";

}
private: System::Void min_btn_Click(System::Object^ sender, System::EventArgs^ e) {

	hid_device* handle = handledevice();
	int brightness = get_brightness(handle);

	brightness = min_brightness;
	set_brightness(handle, brightness);
	current_brightness_lbl->Text = (int((float(brightness) / 54000) * 100.0).ToString()) + "%";

}
private: System::Void decrease_btn_Click(System::Object^ sender, System::EventArgs^ e) {

	hid_device* handle = handledevice();
	int brightness = get_brightness(handle);

	brightness = prev_step(brightness, big_steps);
	set_brightness(handle, brightness);
	current_brightness_lbl->Text = (int((float(brightness) / 54000) * 100.0).ToString())+"%";
	
}

		
};




}


