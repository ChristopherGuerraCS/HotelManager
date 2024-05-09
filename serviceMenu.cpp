//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "serviceMenu.h"
#include "bookRooms.h"
#include "Facility.h"
#include "login.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TserviceMenuForm *serviceMenuForm;
//---------------------------------------------------------------------------
__fastcall TserviceMenuForm::TserviceMenuForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TserviceMenuForm::bookRoomsPortalClick(TObject *Sender)
{
	bookRoomsForm->Show();
	serviceMenuForm->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TserviceMenuForm::facilitiesPortalClick(TObject *Sender)
{
	Facilityy = new TFacilityy(this);
	  Facilityy->Show();
      serviceMenuForm->Hide();

}
//---------------------------------------------------------------------------

