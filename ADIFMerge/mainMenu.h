/* TODO:

VS Runtimes / installer. - DONE
Redo file output. - DONE
Add counter for records. - DONE
Add log file. - DONE
Check for output file in input files.
Add a progress bar - DONE

*/

#pragma once
#include <string>
#include <vector>
#include <msclr\marshal_cppstd.h>
#include <iostream>
#include <fstream>
#include <algorithm>

#define VERSION "1.4"

namespace ADIFMerge {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for mainMenu
	/// </summary>
	public ref class mainMenu : public System::Windows::Forms::Form
	{
	public:
		mainMenu(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~mainMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button_Browse;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::Windows::Forms::Label^  labelHeader;
	private: System::Windows::Forms::ListBox^  fileList;
	private: System::Windows::Forms::Button^  button_Delete;
	private: System::Windows::Forms::Button^  button_Merge;
	private: System::Windows::Forms::TextBox^  textBox_Output;

	private: System::Windows::Forms::Label^  label_Output;
	private: System::Windows::Forms::Button^  button_Output;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker_Process;
	private: System::Windows::Forms::Button^  button_Clear;

	private: System::Windows::Forms::RadioButton^  radioButton_MultiLine;
	private: System::Windows::Forms::RadioButton^  radioButton_SingleLine;
	private: System::Windows::Forms::ProgressBar^  progressBar_Process;
	private: System::Windows::Forms::CheckBox^  checkBox_Diag;
	private: System::Windows::Forms::Button^  button_LogBrowse;
	private: System::Windows::Forms::TextBox^  textBox_Log;









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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(mainMenu::typeid));
			this->button_Browse = (gcnew System::Windows::Forms::Button());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->labelHeader = (gcnew System::Windows::Forms::Label());
			this->fileList = (gcnew System::Windows::Forms::ListBox());
			this->button_Delete = (gcnew System::Windows::Forms::Button());
			this->button_Merge = (gcnew System::Windows::Forms::Button());
			this->textBox_Output = (gcnew System::Windows::Forms::TextBox());
			this->label_Output = (gcnew System::Windows::Forms::Label());
			this->button_Output = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker_Process = (gcnew System::ComponentModel::BackgroundWorker());
			this->button_Clear = (gcnew System::Windows::Forms::Button());
			this->radioButton_MultiLine = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_SingleLine = (gcnew System::Windows::Forms::RadioButton());
			this->progressBar_Process = (gcnew System::Windows::Forms::ProgressBar());
			this->checkBox_Diag = (gcnew System::Windows::Forms::CheckBox());
			this->button_LogBrowse = (gcnew System::Windows::Forms::Button());
			this->textBox_Log = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button_Browse
			// 
			this->button_Browse->Location = System::Drawing::Point(9, 25);
			this->button_Browse->Name = L"button_Browse";
			this->button_Browse->Size = System::Drawing::Size(75, 23);
			this->button_Browse->TabIndex = 0;
			this->button_Browse->Text = L"Add";
			this->button_Browse->UseVisualStyleBackColor = true;
			this->button_Browse->Click += gcnew System::EventHandler(this, &mainMenu::button_Browse_Click);
			// 
			// openFileDialog
			// 
			this->openFileDialog->CheckFileExists = false;
			this->openFileDialog->CheckPathExists = false;
			this->openFileDialog->DefaultExt = L"adi";
			this->openFileDialog->FileName = L".txt";
			this->openFileDialog->Multiselect = true;
			// 
			// labelHeader
			// 
			this->labelHeader->AutoSize = true;
			this->labelHeader->Location = System::Drawing::Point(12, 9);
			this->labelHeader->Name = L"labelHeader";
			this->labelHeader->Size = System::Drawing::Size(72, 13);
			this->labelHeader->TabIndex = 1;
			this->labelHeader->Text = L"Files to merge";
			// 
			// fileList
			// 
			this->fileList->FormattingEnabled = true;
			this->fileList->Location = System::Drawing::Point(90, 9);
			this->fileList->Name = L"fileList";
			this->fileList->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
			this->fileList->Size = System::Drawing::Size(587, 95);
			this->fileList->TabIndex = 2;
			// 
			// button_Delete
			// 
			this->button_Delete->Location = System::Drawing::Point(9, 54);
			this->button_Delete->Name = L"button_Delete";
			this->button_Delete->Size = System::Drawing::Size(75, 23);
			this->button_Delete->TabIndex = 3;
			this->button_Delete->Text = L"Delete";
			this->button_Delete->UseVisualStyleBackColor = true;
			this->button_Delete->Click += gcnew System::EventHandler(this, &mainMenu::button_Delete_Click);
			// 
			// button_Merge
			// 
			this->button_Merge->Location = System::Drawing::Point(306, 221);
			this->button_Merge->Name = L"button_Merge";
			this->button_Merge->Size = System::Drawing::Size(75, 23);
			this->button_Merge->TabIndex = 4;
			this->button_Merge->Text = L"Merge";
			this->button_Merge->UseVisualStyleBackColor = true;
			this->button_Merge->Click += gcnew System::EventHandler(this, &mainMenu::button_Merge_Click);
			// 
			// textBox_Output
			// 
			this->textBox_Output->Location = System::Drawing::Point(90, 171);
			this->textBox_Output->Name = L"textBox_Output";
			this->textBox_Output->ReadOnly = true;
			this->textBox_Output->Size = System::Drawing::Size(587, 20);
			this->textBox_Output->TabIndex = 5;
			// 
			// label_Output
			// 
			this->label_Output->AutoSize = true;
			this->label_Output->Location = System::Drawing::Point(12, 154);
			this->label_Output->Name = L"label_Output";
			this->label_Output->Size = System::Drawing::Size(58, 13);
			this->label_Output->TabIndex = 6;
			this->label_Output->Text = L"Output File";
			// 
			// button_Output
			// 
			this->button_Output->Location = System::Drawing::Point(9, 170);
			this->button_Output->Name = L"button_Output";
			this->button_Output->Size = System::Drawing::Size(75, 23);
			this->button_Output->TabIndex = 7;
			this->button_Output->Text = L"Browse";
			this->button_Output->UseVisualStyleBackColor = true;
			this->button_Output->Click += gcnew System::EventHandler(this, &mainMenu::button_Output_Click);
			// 
			// backgroundWorker_Process
			// 
			this->backgroundWorker_Process->WorkerReportsProgress = true;
			this->backgroundWorker_Process->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &mainMenu::backgroundWorker_Process_DoWork);
			this->backgroundWorker_Process->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &mainMenu::backgroundWorker_Process_ProgressChanged);
			this->backgroundWorker_Process->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &mainMenu::backgroundWorker_Process_RunWorkerCompleted);
			// 
			// button_Clear
			// 
			this->button_Clear->Location = System::Drawing::Point(9, 83);
			this->button_Clear->Name = L"button_Clear";
			this->button_Clear->Size = System::Drawing::Size(75, 23);
			this->button_Clear->TabIndex = 8;
			this->button_Clear->Text = L"Clear All";
			this->button_Clear->UseVisualStyleBackColor = true;
			this->button_Clear->Click += gcnew System::EventHandler(this, &mainMenu::button_Clear_Click);
			// 
			// radioButton_MultiLine
			// 
			this->radioButton_MultiLine->AutoSize = true;
			this->radioButton_MultiLine->Checked = true;
			this->radioButton_MultiLine->Location = System::Drawing::Point(9, 199);
			this->radioButton_MultiLine->Name = L"radioButton_MultiLine";
			this->radioButton_MultiLine->Size = System::Drawing::Size(106, 17);
			this->radioButton_MultiLine->TabIndex = 10;
			this->radioButton_MultiLine->TabStop = true;
			this->radioButton_MultiLine->Text = L"Multiline Records";
			this->radioButton_MultiLine->UseVisualStyleBackColor = true;
			// 
			// radioButton_SingleLine
			// 
			this->radioButton_SingleLine->AutoSize = true;
			this->radioButton_SingleLine->Location = System::Drawing::Point(9, 221);
			this->radioButton_SingleLine->Name = L"radioButton_SingleLine";
			this->radioButton_SingleLine->Size = System::Drawing::Size(120, 17);
			this->radioButton_SingleLine->TabIndex = 11;
			this->radioButton_SingleLine->Text = L"Single Line Records";
			this->radioButton_SingleLine->UseVisualStyleBackColor = true;
			// 
			// progressBar_Process
			// 
			this->progressBar_Process->Location = System::Drawing::Point(387, 221);
			this->progressBar_Process->Name = L"progressBar_Process";
			this->progressBar_Process->Size = System::Drawing::Size(290, 23);
			this->progressBar_Process->TabIndex = 12;
			// 
			// checkBox_Diag
			// 
			this->checkBox_Diag->AutoSize = true;
			this->checkBox_Diag->Location = System::Drawing::Point(306, 197);
			this->checkBox_Diag->Name = L"checkBox_Diag";
			this->checkBox_Diag->Size = System::Drawing::Size(118, 17);
			this->checkBox_Diag->TabIndex = 13;
			this->checkBox_Diag->Text = L"Log Diagnostic Info";
			this->checkBox_Diag->UseVisualStyleBackColor = true;
			this->checkBox_Diag->CheckedChanged += gcnew System::EventHandler(this, &mainMenu::checkBox_Diag_CheckedChanged);
			// 
			// button_LogBrowse
			// 
			this->button_LogBrowse->Enabled = false;
			this->button_LogBrowse->Location = System::Drawing::Point(425, 195);
			this->button_LogBrowse->Name = L"button_LogBrowse";
			this->button_LogBrowse->Size = System::Drawing::Size(75, 23);
			this->button_LogBrowse->TabIndex = 14;
			this->button_LogBrowse->Text = L"Browse";
			this->button_LogBrowse->UseVisualStyleBackColor = true;
			this->button_LogBrowse->Visible = false;
			this->button_LogBrowse->Click += gcnew System::EventHandler(this, &mainMenu::button_LogBrowse_Click);
			// 
			// textBox_Log
			// 
			this->textBox_Log->Enabled = false;
			this->textBox_Log->Location = System::Drawing::Point(506, 196);
			this->textBox_Log->Name = L"textBox_Log";
			this->textBox_Log->ReadOnly = true;
			this->textBox_Log->Size = System::Drawing::Size(171, 20);
			this->textBox_Log->TabIndex = 15;
			this->textBox_Log->Visible = false;
			// 
			// mainMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(692, 258);
			this->Controls->Add(this->textBox_Log);
			this->Controls->Add(this->button_LogBrowse);
			this->Controls->Add(this->checkBox_Diag);
			this->Controls->Add(this->progressBar_Process);
			this->Controls->Add(this->radioButton_SingleLine);
			this->Controls->Add(this->radioButton_MultiLine);
			this->Controls->Add(this->button_Clear);
			this->Controls->Add(this->button_Output);
			this->Controls->Add(this->label_Output);
			this->Controls->Add(this->textBox_Output);
			this->Controls->Add(this->button_Merge);
			this->Controls->Add(this->button_Delete);
			this->Controls->Add(this->fileList);
			this->Controls->Add(this->labelHeader);
			this->Controls->Add(this->button_Browse);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"mainMenu";
			this->Text = L"ADIFMerge";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//Button to open a prompt, and add the returned filepath to a list.
	private: System::Void button_Browse_Click(System::Object^  sender, System::EventArgs^  e) {
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			for each (String^ file in openFileDialog->FileNames)
			{
				fileList->Items->Add(file);
			}
		}
	}

			 // Button to remove files from the file browser list.
	private: System::Void button_Delete_Click(System::Object^  sender, System::EventArgs^  e) {
		for (int i = fileList->SelectedIndices->Count - 1; i >= 0; i--)
		{
			fileList->Items->RemoveAt(fileList->SelectedIndices[i]);
		}
	}

			 // Button to clear all files from the file browser list.
	private: System::Void button_Clear_Click(System::Object^  sender, System::EventArgs^  e) {
		fileList->Items->Clear();
	}

			 // Button to locate and select an output file.
	private: System::Void button_Output_Click(System::Object^  sender, System::EventArgs^  e) {
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			textBox_Output->Text = openFileDialog->FileName;
		}
	}

			 // Button to initiate merge.
	private: System::Void button_Merge_Click(System::Object^  sender, System::EventArgs^  e) {
		// Check for output file in input file list.
		if(fileList->Items->Contains(textBox_Output->Text)) {
			MessageBox::Show("Output file cannot be included in the input file list");
		}
		else {
			button_Merge->Enabled = false;
			// Creates a new background worker thread.
			backgroundWorker_Process->RunWorkerAsync(1);
		}
	}

			 // Process files in a separate thread from the rest of the program.
	private: System::Void backgroundWorker_Process_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
		const int fileCount = fileList->Items->Count;

		array<String^>^ outputArray = gcnew array<String^>(fileCount);

		String^ managedOutput;

		for (int i = 0; i < fileList->Items->Count; i++) {
			managedOutput = fileList->Items[i]->ToString();
			outputArray[i] = managedOutput;
		}

		processFiles(outputArray);

		delete[] outputArray;
	}

			 // Reset merge button after process finishes.
	private: System::Void backgroundWorker_Process_RunWorkerCompleted(System::Object^  sender, System::ComponentModel::RunWorkerCompletedEventArgs^  e) {
		button_Merge->Enabled = true;
	}

			 // Update progress of thread.
	private: System::Void backgroundWorker_Process_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
		progressBar_Process->Value = (e->ProgressPercentage);
	}

			 // Function to process the data. Accepts an array of filenames (String^ ) and writes an output file.
			 void processFiles(array<String^>^ files) {

				 // Initialize counters.
				 int totalFiles = files->Length;
				 int processedFiles = 0;
				 int recordCount = 0;

				 // Initialize datetimes for logging.
				 System::DateTime timeBefore = System::DateTime::Now;
				 System::DateTime timeAfter;

				 // Initialize filestreams.
				 std::ifstream inputStream;
				 std::ofstream outputStream;
				 std::ofstream logStream;

				 // Initialize strings.
				 String^ managedOutputFilePath = textBox_Output->Text;
				 std::string unmanagedOutputFilePath = msclr::interop::marshal_as<std::string>(managedOutputFilePath);
				 String^ message = "";

				 if (checkBox_Diag->Checked == true) {

					 // Set log filename.
					 String^ managedLogFilePath = textBox_Log->Text;
					 std::string unmanagedLogFilePath = msclr::interop::marshal_as<std::string>(managedLogFilePath);

					 // Open file.
					 logStream.open(unmanagedLogFilePath);
				 }

				 // Prepare header.
				 message = (message + "Created with ADIFMerge\nVersion " + VERSION + "\nCopyright Levi Cherry-Allen 2016\n<EOH>\n\n");

				 // Open output stream.
				 outputStream.open(unmanagedOutputFilePath);

				 if (outputStream.is_open()) {
					 // Write header.
					 outputStream << msclr::interop::marshal_as<std::string>(message);
					 message = "";
				 }

				 for (int i = 0; i < files->GetLength(0); i++) {
					 // Load file, then convert it to from System::String to std::string.
					 String^ managedInputFilePath = files[i];
					 std::string unmanagedInputFilePath = msclr::interop::marshal_as<std::string>(managedInputFilePath);

					 // Initialize storage string.
					 std::string line;

					 // Open input file.
					 inputStream.open(unmanagedInputFilePath);

					 // Set flag for whether header has been read.
					 bool readHeader = false;

					 if (inputStream.is_open()) {
						 // Get a line of data, using < as the delimiter.
						 while (getline(inputStream, line, '<')) {

							 // Remove linebreaks.
							 line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());

							 // Convert the line from std::string to System::String.
							 String^ output = gcnew String(line.c_str());

							 // Run if header has not been read, and is a header.
							 if (readHeader == false && (output->Contains("EOH") || output->Contains("eoh"))) {
								 // Set header to read.
								 readHeader = true;
							 }

							 // Run if header has already been run, and is an end of record.
							 else if (readHeader == true && (output->Contains("EOR") || output->Contains("eor"))) {
								 // Prepare EOR to be written.
								 if (radioButton_MultiLine->Checked == true) {
									 message = (message + "<EOR>\n\n")->ToUpper();
									 recordCount++;
								 }
								 // Prepare EOR to be written.
								 else {
									 message = (message + "<EOR>\n")->ToUpper();
									 recordCount++;
								 }
								 // Write EOR.
								 if (outputStream.is_open()) {
									 outputStream << msclr::interop::marshal_as<std::string>(message);
									 message = "";
								 }
							 }

							 // Run if header has already been read, and is not an end of record.
							 else if (readHeader == true) {
								 // Prepare record to be written.
								 if (radioButton_MultiLine->Checked == true) {
									 message = (message + "<" + output->Trim() + "\n")->ToUpper();
								 }
								 // Prepare record to be written.
								 else {
									 message = (message + "<" + output->Trim())->ToUpper();
								 }
								 // Write record.
								 if (outputStream.is_open())
								 {
									 outputStream << msclr::interop::marshal_as<std::string>(message);
									 message = "";
								 }
							 }

							 // Run after each file.
						 }
						 processedFiles++;
						 if (totalFiles != 0 && processedFiles != 0) {
							 // Report progress of thread.
							 backgroundWorker_Process->ReportProgress(((float)processedFiles / (float)totalFiles) * 100);
						 }
						 inputStream.close();
					 }
				 }
				 timeAfter = System::DateTime::Now;
				 // Show report of file and record count.
				 MessageBox::Show(recordCount + " Records merged from " + files->GetLength(0) + " files!");

				 // Close output stream.
				 outputStream.close();

				 // Prep and write log.
				 if (checkBox_Diag->Checked == true && logStream.is_open() == true) {

					 String^ log = "";
					 log = (log + "Log file from ADIFMerge created at: " + System::DateTime::Now + "\n");
					 log = (log + "Processed files: " + processedFiles + "\n");
					 log = (log + "Processed records: " + recordCount + "\n");
					 log = (log + "Processing time: " + (timeAfter - timeBefore) + "\n");

					 logStream << msclr::interop::marshal_as<std::string>(log);

					 logStream.close();
				 }
			 }
	private: System::Void checkBox_Diag_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (checkBox_Diag->Checked == true) {
			button_LogBrowse->Enabled = true;
			button_LogBrowse->Visible = true;
			textBox_Log->Enabled = true;
			textBox_Log->Visible = true;
		}
		else {
			button_LogBrowse->Enabled = false;
			button_LogBrowse->Visible = false;
			textBox_Log->Enabled = false;
			textBox_Log->Visible = false;
		}
	}
private: System::Void button_LogBrowse_Click(System::Object^  sender, System::EventArgs^  e) {
	if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		textBox_Log->Text = openFileDialog->FileName;
	}
}
};
}