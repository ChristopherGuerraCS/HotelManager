//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Cafe.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TCafee *Cafee;
double totalCost = 0.0;
//---------------------------------------------------------------------------
__fastcall TCafee::TCafee(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TCafee::Button1Click(TObject *Sender)
{
		totalCost += 10.99; // Price of breakfast item 1
			 UpdateTotalCost();
			 AddToOrderList("Fried Chicken Biscuit Breakfast", 10.99);
}
//---------------------------------------------------------------------------
void __fastcall TCafee::Button2Click(TObject *Sender)
{
		 totalCost += 12.99; // Price of breakfast item 2
			 UpdateTotalCost();
			 AddToOrderList("Steak and Eggs", 12.99);
}
//---------------------------------------------------------------------------
void __fastcall TCafee::Button3Click(TObject *Sender)
{
		  totalCost += 7.99; // Price of breakfeast item 3
			 UpdateTotalCost();
			 AddToOrderList("Sunrise Croissant", 7.99);
}
//---------------------------------------------------------------------------
void __fastcall TCafee::Button4Click(TObject *Sender)
{
		   totalCost += 3.99; // Price of coffee
			 UpdateTotalCost();
			 AddToOrderList("Coffee", 3.99);
}
//---------------------------------------------------------------------------
void __fastcall TCafee::Button5Click(TObject *Sender)
{
			   Label2-> Text = "Subtotal: $" + FloatToStr(totalCost);
               Label7->Text = "Total: $" + FloatToStrF(RoundTo(totalCost + (totalCost * 0.09), -2), ffFixed, 10, 2);
}
//---------------------------------------------------------------------------
void __fastcall TCafee::UpdateTotalCost()
{
	Label1-> Text = "Current Cost: $" + FloatToStr(totalCost);
}
//----------------------------------------------------------------------------
void __fastcall TCafee::AddToOrderList(UnicodeString itemName, double itemCost)
{
	UnicodeString itemDescription = itemName + " - $" + FloatToStr(itemCost);
	ListBox1->Items->Add(itemDescription);
}
void __fastcall TCafee::Button6Click(TObject *Sender)
{
					this->Close();
}
//---------------------------------------------------------------------------



void __fastcall TCafee::deleteButtonClick(TObject *Sender)
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

