//---------------------------------------------------------------------------

#ifndef CafeH
#define CafeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
//---------------------------------------------------------------------------
class TCafee : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TButton *Button5;
	TListBox *ListBox1;
	TButton *Button6;
	TLabel *Label7;
	TButton *deleteButton;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall deleteButtonClick(TObject *Sender);

private:
	double totalCost;
	void __fastcall UpdateTotalCost();// User declarations
    void __fastcall AddToOrderList(UnicodeString itemName, double itemCost);
public:		// User declarations
	__fastcall TCafee(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCafee *Cafee;
//---------------------------------------------------------------------------
#endif
