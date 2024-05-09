//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Facility.h"      //Facility Page
#include "Bar.h"      //Bar
#include "Cafe.h"      //Cafe
#include "Pool.h"      //Pool
#include "serviceMenu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFacilityy *Facilityy;
//---------------------------------------------------------------------------
__fastcall TFacilityy::TFacilityy(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFacilityy::Button1Click(TObject *Sender)
{
					Help = new THelp(this);
					Help->Show();
					Facilityy->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TFacilityy::Button2Click(TObject *Sender)
{
					 Cafee = new TCafee(this);
					Cafee->Show();
					Facilityy->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TFacilityy::Button3Click(TObject *Sender)
{
	Poool = new TPoool(this);
					Poool->Show();
                    Facilityy->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TFacilityy::Button4Click(TObject *Sender)
{
							  this->Close();
}
//---------------------------------------------------------------------------

