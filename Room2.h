//---------------------------------------------------------------------------

#ifndef Room2H
#define Room2H
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
class Troom2Form : public TForm
{
__published:	// IDE-managed Components
	TButton *confirmButton;
	TText *Text1;
	TButton *room2UnbookButton;
	void __fastcall confirmButtonClick(TObject *Sender);
	void __fastcall returnButtonClick(TObject *Sender);
	void __fastcall room2UnbookButtonClick(TObject *Sender);
private:	// User declarations


public:		// User declarations
	__fastcall Troom2Form(TComponent* Owner);
    bool IsRoomBooked();
	void SaveBookedStatus(bool booked);
	void LoadBookedStatus(); // Declaration of LoadBookedStatus function
    void UpdateButtonVisibility(bool booked);


};
//---------------------------------------------------------------------------
extern PACKAGE Troom2Form *room2Form;
//---------------------------------------------------------------------------
#endif
