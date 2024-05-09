//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "bookRooms.h"
#include "Room1.h"
#include "Room2.h"
#include "Room3.h"
#include "serviceMenu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TbookRoomsForm *bookRoomsForm;
//---------------------------------------------------------------------------

__fastcall TbookRoomsForm::TbookRoomsForm(TComponent* Owner)
	: TForm(Owner)
{
}

void __fastcall TbookRoomsForm::room1ButtonClick(TObject *Sender)
{
	room1Form->Show();
	bookRoomsForm->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TbookRoomsForm::room2ButtonClick(TObject *Sender)
{
	room2Form->Show();
	bookRoomsForm->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TbookRoomsForm::room3ButtonClick(TObject *Sender)
{
	room3Form->Show();
	bookRoomsForm->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TbookRoomsForm::returnButtonClick(TObject *Sender)
{
	bookRoomsForm->Hide();
    serviceMenuForm->Show();
}

void TbookRoomsForm::room1Update(bool room1Value)
{
    room1Booked = room1Value;
    if (room1Value == true) {
		room1Text->Text = "Room 1 [Booked]"; // Change the button text to indicate booking status
	} else {
		room1Text->Text = "Room 1 [Available]"; // Change the button text to indicate availability
	}
}

void TbookRoomsForm::room2Update(bool room2Value)
{
	room2Booked = room2Value;
	if (room2Value == true) {
		room2Text->Text = "Room 2 [Booked]"; // Change the button text to indicate booking status
	} else {
		room2Text->Text = "Room 2 [Available]"; // Change the button text to indicate availability
	}
}

void TbookRoomsForm::room3Update(bool room3Value)
{
	room3Booked = room3Value;
	if (room3Value == true) {
		room3Text->Text = "Room 3 [Booked]"; // Change the button text to indicate booking status
	} else {
		room1Text->Text = "Room 3 [Available]"; // Change the button text to indicate availability
	}
}
//---------------------------------------------------------------------------

