//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Pool.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TPoool *Poool;
double pooltotalCost = 0.0;
//---------------------------------------------------------------------------
__fastcall TPoool::TPoool(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPoool::Button1Click(TObject *Sender)
{
	pooltotalCost += 15.00; // Price Pool Towels
	UpdateTotalCost();
	AddToOrderList("Pool Towel", 15.00);
}
//---------------------------------------------------------------------------
void __fastcall TPoool::Button2Click(TObject *Sender)
{
	pooltotalCost += 20.00; // Price of Sunbathing Chair
	UpdateTotalCost();
	AddToOrderList("Subathing Chair", 20.00);
}
//---------------------------------------------------------------------------
void __fastcall TPoool::Button3Click(TObject *Sender)
{
	pooltotalCost += 8.00; // Pool Toys
	UpdateTotalCost();
	AddToOrderList("Pool Toys", 8.00);
}
//---------------------------------------------------------------------------
void __fastcall TPoool::Button4Click(TObject *Sender)
{
	Label1-> Text = "Subtotal: $" + FloatToStr(pooltotalCost);
    Label6->Text = "Total: $" + FloatToStrF(RoundTo(pooltotalCost + (pooltotalCost * 0.09), -2), ffFixed, 10, 2);
}
//---------------------------------------------------------------------------
void __fastcall TPoool::UpdateTotalCost()
{
	Label2-> Text = "Current Cost: $" + FloatToStr(pooltotalCost);
}
//---------------------------------------------------------------------------
void __fastcall TPoool::AddToOrderList(UnicodeString itemName, double itemCost)
{
	UnicodeString itemDescription = itemName + " - $" + FloatToStr(itemCost);
	ListBox1->Items->Add(itemDescription);
}

void __fastcall TPoool::Button5Click(TObject *Sender)
{
                    this->Close();
}
//---------------------------------------------------------------------------


void __fastcall TPoool::deleteButtonClick(TObject *Sender)
{
    // Check if there are items in the list
	if (ListBox1->Items->Count > 0)
	{
		// Remove the last item from the list
		ListBox1->Items->Delete(ListBox1->Items->Count - 1);

		// Update the total cost by subtracting the cost of the deleted item
		// Assuming the cost is stored in an array or list, adjust the total accordingly
		// For demonstration purposes, I'll just subtract a fixed value
		totalCost -= 10.0; // Assuming each item costs $10.0, adjust this according to your actual implementation

		// Update the UI to reflect the changes
		UpdateTotalCost();
	}
}
//---------------------------------------------------------------------------

