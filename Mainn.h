//---------------------------------------------------------------------------

#ifndef MainnH
#define MainnH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TMainn : public TForm
{
__published:	// IDE-managed Components
	TButton *mainLoginButton;
	TButton *mainRegistrationButton;
	TLabel *welcomeMessage;
	void __fastcall mainLoginButtonClick(TObject *Sender);
	void __fastcall mainRegistrationButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainn(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainn *Mainn;
//---------------------------------------------------------------------------
#endif
