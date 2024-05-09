//---------------------------------------------------------------------------

#ifndef registrationH
#define registrationH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TregistrationForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *nameLabel;
	TEdit *nameEdit;
	TLabel *ageLabel;
	TEdit *ageEdit;
	TLabel *usernameLabel;
	TEdit *usernameEdit;
	TLabel *passwordLabel;
	TEdit *passwordEdit;
	TButton *saveButton;
	void __fastcall saveButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TregistrationForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TregistrationForm *registrationForm;
//---------------------------------------------------------------------------
#endif
