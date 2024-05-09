//---------------------------------------------------------------------------

#ifndef serviceMenuH
#define serviceMenuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TserviceMenuForm : public TForm
{
__published:	// IDE-managed Components
	TButton *bookRoomsPortal;
	TButton *facilitiesPortal;
	TText *Text1;
	void __fastcall bookRoomsPortalClick(TObject *Sender);
	void __fastcall facilitiesPortalClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TserviceMenuForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TserviceMenuForm *serviceMenuForm;
//---------------------------------------------------------------------------
#endif
