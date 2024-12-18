// Room1.cpp

#include <fmx.h>
#include "Room1.h"
#include "bookRooms.h"
#include <System.IOUtils.hpp>

#pragma hdrstop
#pragma package(smart_init)
#pragma resource "*.fmx"

Troom1Form *room1Form;
const UnicodeString BookedStatusFilePath = "Room1BookedStatus.txt";

__fastcall Troom1Form::Troom1Form(TComponent* Owner)
    : TForm(Owner)
{
	LoadBookedStatus(); // Load room booking status when the form is initialized
	UpdateButtonVisibility(!IsRoomBooked());
}

bool Troom1Form::IsRoomBooked()
{
    if (TFile::Exists(BookedStatusFilePath))
    {
        TFileStream *fileStream = new TFileStream(BookedStatusFilePath, fmOpenRead);
        TStreamReader *reader = new TStreamReader(fileStream);

        try
        {
            UnicodeString text = reader->ReadLine();
            bool booked = text.Trim().LowerCase() == "true";
            return booked;
        }
        __finally
        {
            delete reader;
            delete fileStream;
        }
    }
    else
    {
        // If the file doesn't exist or can't be read, assume the room is not booked
        return false;
    }
}

void __fastcall Troom1Form::confirmButtonClick(TObject *Sender)
{
    bool booked = IsRoomBooked();
    if (!booked)
    {
        // If the room is not booked, book it
        SaveBookedStatus(true);
        if (bookRoomsForm != nullptr)
        {
            bookRoomsForm->room1Update(true);
        }
    }

    // Update button visibility based on current room booking status
    UpdateButtonVisibility(IsRoomBooked());
}


void __fastcall Troom1Form::returnButtonClick(TObject *Sender)
{
    bookRoomsForm->Show();
    room1Form->Hide();
}

void Troom1Form::UpdateButtonVisibility(bool booked)
{
    // If the room is booked, show the unbook button and hide the book button
    confirmButton->Visible = !booked;
    unbookButton->Visible = booked;
}

void Troom1Form::SaveBookedStatus(bool booked)
{
    TFileStream *fileStream = new TFileStream(BookedStatusFilePath, fmCreate);
    TStreamWriter *writer = new TStreamWriter(fileStream);

    try
    {
        writer->Write(booked ? "true" : "false");
    }
    __finally
    {
        delete writer;
        delete fileStream;
    }
}


void Troom1Form::LoadBookedStatus()
{
    if (TFile::Exists(BookedStatusFilePath))
    {
        TFileStream *fileStream = new TFileStream(BookedStatusFilePath, fmOpenRead);
        TStreamReader *reader = new TStreamReader(fileStream);

        try
        {
            UnicodeString text = reader->ReadLine();
            bool booked = text.Trim().LowerCase() == "true";
            UpdateButtonVisibility(booked);
        }
        __finally
        {
            delete reader;
            delete fileStream;
        }
    }
}

void __fastcall Troom1Form::unbookButtonClick(TObject *Sender)
{
    // Determine if the room is booked
    bool booked = IsRoomBooked();

    // Show the bookRoomsForm and hide the current room1Form
    bookRoomsForm->Show();
    room1Form->Hide();

    if (booked)
    {
        // If the room is booked, delete the file
        TFile::Delete(BookedStatusFilePath);

        // Update the room booking status and notify bookRoomsForm
        if (bookRoomsForm != nullptr)
        {
            bookRoomsForm->room1Update(false);
        }
    }

    // Update button visibility based on room booking status
    UpdateButtonVisibility(false); // After unbooking, the room should not be booked
}

//---------------------------------------------------------------------------

