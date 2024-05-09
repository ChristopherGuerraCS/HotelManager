//---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
//---------------------------------------------------------------------------
USEFORM("registration.cpp", registrationForm);
USEFORM("Pool.cpp", Poool);
USEFORM("Mainn.cpp", Mainn);
USEFORM("Room1.cpp", room1Form);
USEFORM("serviceMenu.cpp", serviceMenuForm);
USEFORM("Room3.cpp", room3Form);
USEFORM("Room2.cpp", room2Form);
USEFORM("Cafe.cpp", Cafee);
USEFORM("bookRooms.cpp", bookRoomsForm);
USEFORM("Bar.cpp", Help);
USEFORM("Facility.cpp", Facilityy);
USEFORM("login.cpp", loginForm);
//---------------------------------------------------------------------------
extern "C" int FMXmain()
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TMainn), &Mainn);
		Application->CreateForm(__classid(Troom1Form), &room1Form);
		Application->CreateForm(__classid(Troom2Form), &room2Form);
		Application->CreateForm(__classid(Troom3Form), &room3Form);
		Application->CreateForm(__classid(TbookRoomsForm), &bookRoomsForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
