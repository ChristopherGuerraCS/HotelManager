//---------------------------------------------------------------------------

#ifndef Room3H
#define Room3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <fmx.h>
#include <System.IOUtils.hpp>
//---------------------------------------------------------------------------
class Troom3Form : public TForm
{
__published:	// IDE-managed Components
	TButton *confirmButton;
	TButton *room3ReturnButton;
	TText *Text1;
	TButton *room3UnbookButton;
	void __fastcall confirmButtonClick(TObject *Sender);
	void __fastcall room3UnbookButtonClick(TObject *Sender);
	void __fastcall room3ReturnButtonClick(TObject *Sender);
private:	// User declarations


public:		// User declarations
	__fastcall Troom3Form(TComponent* Owner);
    bool IsRoomBooked();
	void SaveBookedStatus(bool booked);
	void LoadBookedStatus(); // Declaration of LoadBookedStatus function
    void UpdateButtonVisibility(bool booked);


};
//---------------------------------------------------------------------------
extern PACKAGE Troom3Form *room3Form;
//---------------------------------------------------------------------------
#endif
