//---------------------------------------------------------------------------

#include <fmx.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#pragma hdrstop

#include "login.h"
#include "Mainn.h"
#include "serviceMenu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TloginForm *loginForm;
//---------------------------------------------------------------------------
__fastcall TloginForm::TloginForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
std::vector<std::string> parseCommaDelimitedString(std::string line) {
	std::vector<std::string> result;
	std::stringstream s_stream(line);

	while(s_stream.good()) {
		std::string substr;
		getline(s_stream,substr,',');
		result.push_back(substr);
	}
	return result;
}
//---------------------------------------------------------------------------
void __fastcall TloginForm::loginButtonClick(TObject *Sender)
{
	   fstream myFile;
	   myFile.open("registeredUsers.txt",ios::in);

	   if (myFile.is_open()) {
		  std::string line;

		  while(getline(myFile,line)) {
			   std::vector<std::string> parsedLine = parseCommaDelimitedString(line);
			   const char* username = parsedLine.at(2).c_str();

			   AnsiString editUsername = usernameEdit->Text;
			   const char* usernameString = editUsername.c_str();

			   if(std::strcmp(username,usernameString)==0) {
				   const char* password = parsedLine.at(3).c_str();

					AnsiString editPassword = passwordEdit->Text;
					const char* passwordString = editPassword.c_str();

					if(std::strcmp(password,passwordString)==0)  {
						messageLabel->Text = "Success";
					serviceMenuForm = new TserviceMenuForm(this);
					serviceMenuForm->Show();
					}
					else
						 messageLabel-> Text = "Wrong username or password";
               }
		  }
	   }
}
//---------------------------------------------------------------------------
void __fastcall TloginForm::passwordEditClick(TObject *Sender)
{
	passwordEdit->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TloginForm::usernameEditClick(TObject *Sender)
{
    usernameEdit->Text = "";
}
//---------------------------------------------------------------------------

