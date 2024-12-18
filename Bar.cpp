//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Bar.h"
#include <System.Math.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
THelp *Help;
double bartotalCost = 0.0;

//---------------------------------------------------------------------------
__fastcall THelp::THelp(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall THelp::Button1Click(TObject *Sender)
{
	bartotalCost += 15.00; // Price of drink 1
	UpdateTotalCost();
	AddToOrderList("Blue Hawaiian Cocktail", 15.00);
}
//---------------------------------------------------------------------------
void __fastcall THelp::Button2Click(TObject *Sender)
{
	bartotalCost += 11.50; //Price of Drink2
	UpdateTotalCost();
	AddToOrderList("Classic Mojito Cocktail", 11.50);
}
//---------------------------------------------------------------------------
void __fastcall THelp::Button3Click(TObject *Sender)
{
	bartotalCost += 10.75; //Price of Drink3
	UpdateTotalCost();
	AddToOrderList("Watermelon Cherry Daiquri", 10.75);
}
//---------------------------------------------------------------------------
void __fastcall THelp::Button4Click(TObject *Sender)
{
	bartotalCost += 9.50; //Price of Drink4
	UpdateTotalCost();
	AddToOrderList("Rum Sunset Cocktail", 9.50);
}
//---------------------------------------------------------------------------
		void __fastcall THelp::UpdateTotalCost()
{
	Label2-> Text = "Current Cost: $" + FloatToStr(bartotalCost);
}
//---------------------------------------------------------------------------
void __fastcall THelp::Button5Click(TObject *Sender)
{
	 Label1-> Text = "Subtotal: $" + FloatToStr(bartotalCost);
	 Label7->Text = "Total: $" + FloatToStrF(RoundTo(bartotalCost + (bartotalCost * 0.09), -2), ffFixed, 10, 2);
}
//---------------------------------------------------------------------------

void __fastcall THelp::AddToOrderList(UnicodeString itemName, double itemCost)
{
	UnicodeString itemDescription = itemName + " - $" + FloatToStr(itemCost);
	ListBox1->Items->Add(itemDescription);
}
void __fastcall THelp::Button6Click(TObject *Sender)
{
				this->Close();
}
//---------------------------------------------------------------------------

void __fastcall THelp::deleteButtonClick(TObject *Sender)
{

    // Check if there are items in the list
	if (ListBox1->Items->Count > 0)
	{
		// Remove the last item from the list
		ListBox1->Items->Delete(ListBox1->Items->Count - 1);

		// Update the total cost by subtracting the cost of the deleted item
		// Assuming the cost is stored in an array or list, adjust the total accordingly
		// For demonstration purposes, I'll just subtract a fixed value
		bartotalCost -= 10.0; // Assuming each item costs $10.0, adjust this according to your actual implementation

		// Update the UI to reflect the changes
		UpdateTotalCost();
	}

}
//---------------------------------------------------------------------------

