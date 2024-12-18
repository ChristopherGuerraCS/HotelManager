//---------------------------------------------------------------------------

#ifndef PoolH
#define PoolH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TPoool : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TListBox *ListBox1;
	TLabel *Label1;
	TLabel *Label2;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TButton *Button5;
	TLabel *Label6;
	TButton *deleteButton;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall deleteButtonClick(TObject *Sender);
private:
	double totalCost;
	void __fastcall UpdateTotalCost();
	void __fastcall AddToOrderList(UnicodeString itemName, double itemCost);	// User declarations
public:		// User declarations
	__fastcall TPoool(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPoool *Poool;
//---------------------------------------------------------------------------
#endif
