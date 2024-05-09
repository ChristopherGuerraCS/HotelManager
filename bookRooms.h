//---------------------------------------------------------------------------

#ifndef bookRoomsH
#define bookRoomsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Calendar.hpp>
//---------------------------------------------------------------------------
class TbookRoomsForm : public TForm
{
__published:	// IDE-managed Components
	TText *room1Text;
	TText *room2Text;
	TText *room3Text;
	TButton *room1Button;
	TButton *room2Button;
	TButton *room3Button;
	TCalendar *Calendar1;
	TButton *returnButton;
	void __fastcall room1ButtonClick(TObject *Sender);
	void __fastcall room2ButtonClick(TObject *Sender);
	void __fastcall room3ButtonClick(TObject *Sender);
	void __fastcall returnButtonClick(TObject *Sender);
private:

bool room1Booked = false;
bool room2Booked = false;
bool room3Booked = false;

public:

__fastcall TbookRoomsForm(TComponent* Owner);

void room1Update(bool room1Value);
void room2Update(bool room2Value);
void room3Update(bool room3Value);
};
//---------------------------------------------------------------------------
extern PACKAGE TbookRoomsForm *bookRoomsForm;
//---------------------------------------------------------------------------
#endif
