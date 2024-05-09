//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Mainn.h"
#include "login.h"
#include "registration.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TMainn *Mainn;
//---------------------------------------------------------------------------
__fastcall TMainn::TMainn(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainn::mainLoginButtonClick(TObject *Sender)
{
	loginForm = new TloginForm(this);
	loginForm->Show();
}
//---------------------------------------------------------------------------
void __fastcall TMainn::mainRegistrationButtonClick(TObject *Sender)
{
	registrationForm = new TregistrationForm(this);
	registrationForm ->Show();
}
//---------------------------------------------------------------------------
