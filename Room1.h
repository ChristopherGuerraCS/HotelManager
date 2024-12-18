//---------------------------------------------------------------------------

#ifndef Room1H
#define Room1H
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
class Troom1Form : public TForm
{
__published:	// IDE-managed Components
	TButton *confirmButton;
	TButton *returnButton;
	TText *Text1;
	TButton *unbookButton;
	void __fastcall confirmButtonClick(TObject *Sender);
	void __fastcall returnButtonClick(TObject *Sender);
	void __fastcall unbookButtonClick(TObject *Sender);
private:	// User declarations


public:		// User declarations
	__fastcall Troom1Form(TComponent* Owner);
    bool IsRoomBooked();
	void SaveBookedStatus(bool booked);
	void LoadBookedStatus(); // Declaration of LoadBookedStatus function
    void UpdateButtonVisibility(bool booked);


};
//---------------------------------------------------------------------------
extern PACKAGE Troom1Form *room1Form;
//---------------------------------------------------------------------------
#endif
