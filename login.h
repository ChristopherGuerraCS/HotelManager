//---------------------------------------------------------------------------

#ifndef loginH
#define loginH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Edit.hpp>
//---------------------------------------------------------------------------
class TloginForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *usernameLabel;
	TLabel *Z;
	TEdit *usernameEdit;
	TEdit *passwordEdit;
	TButton *loginButton;
	TLabel *messageLabel;
	TLabel *Label1;
	void __fastcall loginButtonClick(TObject *Sender);
	void __fastcall passwordEditClick(TObject *Sender);
	void __fastcall usernameEditClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TloginForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TloginForm *loginForm;
//---------------------------------------------------------------------------
#endif
