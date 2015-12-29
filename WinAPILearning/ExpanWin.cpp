/*

This code is public domain.  Do with it as you please.
//Download by http://www.NewXing.com
If you need any help understand the basic window creation process you I've got an
example that explains it all up on http://www.planet-source-code.com just search
the c++ section for kyle laduke and find my code entitled Win32 Window (Pure API)
that code is highly commented and explains how to make a normal window.

The code used in the example is pretty much the same as used in this one but this
one isn't commented except only on the sections that have to do with the creation
of controls to be put on the window.  Its also commented in some places on how to
deal with them.  The point of this code is only for an example of how to create and
use some of these window types for yourself.  You should review MSDN documentation
on them still.

*/

#define WIN32_LEAN_AND_MEAN

#include <malloc.h>
#include <stdlib.h>
#include <windows.h>

/*
The following things I am about to define here (ID_*) are control id's.  The control
ID's are used to determin what control the message handler procedure is getting
information about if there happens to be more than one control of the same type.
For most of my code here we only have one control of the same type but this is just
to show you how it would be done so I defined them and used them. ..them being control
id's.  A control id can be any number you want to give it but don't give the same
number to more than one control or it defeates the purpose of them.
*/

#define IDB_REMOVE 1000
#define IDB_ADD 1001

#define IDE_ITEMTEXT 2000

#define IDL_LISTBOX 3000

//Download by http://www.NewXing.com
TCHAR szClassName[] = L"Windows App w/controls";
char text[] = "rbh";

HINSTANCE hApplicationInstance = NULL;
//Download by http://www.NewXing.com
HWND hListbox = NULL; // This will hold the handle of the listbox
HWND hMainWindow = NULL;
HWND hRemove = NULL;
HWND hEdit = NULL;
HWND hAdd = NULL;

LRESULT AddItem(HWND hwnd, LPCTSTR lpstr); // This procedure adds an item to a listbox
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreviousInstance, LPSTR lpCommandLine, int nShowCommand)  {
	MSG messages;
	WNDCLASSEX wcex;

	hApplicationInstance = hInstance;

	wcex.cbClsExtra = 0;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.cbWndExtra = 0;
	wcex.hbrBackground = (HBRUSH)(COLOR_3DFACE + 1);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hInstance = hInstance;
	wcex.lpfnWndProc = WindowProcedure;
	wcex.lpszClassName = szClassName;
	wcex.lpszMenuName = NULL;
	wcex.style = CS_HREDRAW | CS_VREDRAW;

	if (!RegisterClassEx(&wcex))
		return 0;

	hMainWindow = CreateWindowEx(0, szClassName, 
		L"Win32 Controls",
		WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 
		225, 140, 
		HWND_DESKTOP, NULL, hInstance, NULL);

	ShowWindow(hMainWindow, nShowCommand);

	/*
	Below, in our message pump, I have added the following after two lines of code.
	"// <-- Added"
	What these two lines do is enable tabbing between control items.

	See, the if statement on the top commented line just says if IsDialogMessage(...)
	returns false then execute the code in the if statement.  The second added line is
	just the closing line for the if statement

	See, IsDialogMessage passes our message structure and out handle of the main window
	to see if the message is some sort of dialog message.  If it is then the procedure
	handles it and returns true.  If it was handled then we dont need to handle it so
	skip the translatemessage and dispatchmessage.  Well, dialog messages are things like
	tab and shift tab.  For that reason I set it up so tabbing between items will work.
	Most examples I see don't have this feature and it pisses me off frankly.  Most people
	want to be able to tab between items on their windows!  So if we are gonna help them
	make the controls we should help them do it how they will want it and use it.
	*/
	//Download by http://www.NewXing.com
	while (GetMessage(&messages, NULL, 0, 0))  {
		if (!IsDialogMessage(hMainWindow, &messages))  { // <-- Added
			TranslateMessage(&messages);
			DispatchMessage(&messages);
		} // <-- Added
	}

	return (int)messages.wParam;
}


LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)  {
	HGDIOBJ hDefaultFont = NULL;

	switch (uMsg)  {
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_CREATE:  {
						 hListbox = CreateWindowEx(WS_EX_CLIENTEDGE, // Give the list box a sunken border
							 L"Listbox",        // The class name of our lisbox; leave this alone!
							 L"",
							 WS_CHILD | WS_VISIBLE | LBS_NOTIFY | WS_TABSTOP | WS_VSCROLL, /* WS_CHILD - this is a child window

																						   WS_VISIBLE - we want it visible

																						   LBS_NOTIFY - notify the parent window when the user selects an item

																						   WS_TABSTOP - when the user tabs through items let the focus land on this control

																						   WS_VSCROLL - give us a vertical scrollbar
																						   */
																						   //??
																						   5, 5, 100, 100, // Size and position
																						   hwnd, /* We use the hwnd parameter instead of the hMainWindow because
																								 this procedure with this message is invoked before CreateWindowEx
																								 returns.  Thus the hMainWindow variable isn't set to the handle
																								 yet.  So we just use hwnd for the handle because its the correct
																								 window.
																								 */
																								 (HMENU)IDL_LISTBOX, /* Assign the control id for this window.  It's got to
																													 be converted to HMENU because thats what this parameter
																													 requires.
																													 */
																													 //??
																													 hApplicationInstance,
																													 NULL);

						 hDefaultFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT); // Gets the default font object

						 SendMessage(hListbox, WM_SETFONT, (WPARAM)hDefaultFont, MAKELPARAM(FALSE, 0)); /* See for some reason create
							//																			window just insists on making
							//																			our windows look all ugly by
							//																			giving them a stupid font to
							//																			start with.  So what we do here
							//																			is change the font that the
							//																			control uses to the default one
							//																			by windows. */

						 AddItem(hListbox, L"Item 1");    // \'
						 AddItem(hListbox, L"Item 2");    //  \'
						 AddItem(hListbox, L"Item 3");    //   \'
						 AddItem(hListbox, L"Item 4");    //    \'
						 AddItem(hListbox, L"Item 5");    //     \'
						 AddItem(hListbox, L"Item 6");    //      \'
						 AddItem(hListbox, L"Item 7");    //       \'
						 AddItem(hListbox, L"Item 8");    //        > Add some items to the list box
						 AddItem(hListbox, L"Item 9");    //       /'
						 AddItem(hListbox, L"Item 10");   //      /'
						 AddItem(hListbox, L"Item 11");   //     /'
						 AddItem(hListbox, L"Item 12");   //    /'
						 AddItem(hListbox, L"Item 13");   //   /'
						 AddItem(hListbox, L"Item 14");   //  /'
						 AddItem(hListbox, L"Item 15");   // /'

						 /*
						 To create the next window I just used CreateWindow instead of CreateWindowEx.  I did this because
						 for our button we don't really need any extended style so we don't need the ability for that.  All
						 we need is normal ol' createwindow so thats what I used.
						 */

						 hRemove = CreateWindow(L"Button",  // Class name of our button; leave this alone.. what we want is button
							 L"&Remove", /* Caption of our button; the and means the next character gets an
										underscore.  That allows the user to hit alternate and the underscored
										letter to use it.  In this case alt+r would be the same as clicking our
										button. */
										BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE | WS_TABSTOP, /* BS_PUSHBUTTON - create a push button and have it post wm_command to the window proc when clicked
																							WS_CHILD - this window is a child window
																							WS_VISIBLE - we would like this window to be visible
																							WS_TABSTOP - we want tab to enable the user to stop on this item
																							*/
																							110, 5, 100, 25, // Size and position of the button
																							hwnd, // Check the listbox for info on this
																							(HMENU)IDB_REMOVE, // Set our control ID for this control
																							hApplicationInstance,
																							NULL);

						 SendMessage(hRemove, WM_SETFONT, (WPARAM)hDefaultFont, MAKELPARAM(FALSE, 0)); // Use the default font for our button

						 hEdit = CreateWindowEx(WS_EX_CLIENTEDGE, // Put a border on the control
							 L"Edit",
							 L"",
							 WS_CHILD | WS_VISIBLE | WS_TABSTOP | ES_AUTOHSCROLL, /* The only non-standard thin here is
																				  ES_AUTOHSCROLL.  This is used here so
																				  that when the user types pasted the
																				  length of the text box the text box
																				  scrolls.
																				  */
																				  110, 35, 100, 20,
																				  hwnd,
																				  (HMENU)IDE_ITEMTEXT,
																				  hApplicationInstance,
																				  NULL);

						 SendMessage(hEdit, WM_SETFONT, (WPARAM)hDefaultFont, MAKELPARAM(FALSE, 0)); // USe the default font for the edit control

						 hAdd = CreateWindow(L"Button",                                           // \'
							 L"&Add Item",                                        //  \'
							 BS_PUSHBUTTON | WS_CHILD | WS_VISIBLE | WS_TABSTOP, //   \'
							 110, 60, 100, 25,                                   //    \' This is almost the same as the button above,
							 hwnd,                                               //    /' everything except the control id & position
							 (HMENU)IDB_ADD,                                     //   /'
							 hApplicationInstance,                               //  /'
							 NULL);                                              // /'

						 SendMessage(hAdd, WM_SETFONT, (WPARAM)hDefaultFont, MAKELPARAM(FALSE, 0)); // Use the default font for the button


	}

	case WM_COMMAND:  {
						  // See, the loword of the wparam holds the control id's, so do a switch between them to handle them correct

						  switch (LOWORD(wParam))  {
						  case IDB_REMOVE:  { // if the control id was what was given for the remove button
												if (HIWORD(wParam) == BN_CLICKED)  { // If the remove button was clicked then
													int iCurSel = (int)SendMessage(hListbox, LB_GETCURSEL, 0, 0); // Get the current selected item; see msdn->LB_GETCURSEL

													if (iCurSel == -1) // If there wasnt anything selected then exit the switch statement
														break;

													SendMessage(hListbox, LB_DELETESTRING, (WPARAM)iCurSel, 0); // Remove the currently selected item; see msdn->LB_DELETESTRING for more info
												}
						  }break;

						  case IDL_LISTBOX:  { // If the control id was what we gave for the listbox
												 if (HIWORD(wParam) == LBN_SELCHANGE)  { // if the hi word is lbn_selchange
													 LPCTSTR Item; // pointer for our item info
													 int iCurSel = (int)SendMessage(hListbox, LB_GETCURSEL, 0, 0); /* get the currently selected item
																												   check msdn documentation on lb_getcurcel for info */
													 int nItemLen = (int)SendMessage(hListbox, LB_GETTEXTLEN, iCurSel, 0); /* Get the length of the item */

													 if (nItemLen > 0)  { // If the item's length is longer that 0 then
														 Item = (LPCTSTR)malloc(nItemLen); // allocate the place for our item

														 SendMessage(hListbox, LB_GETTEXT, iCurSel, (LPARAM)Item); // Get the item text and store it into Item

														 SetWindowText(hMainWindow, Item); // Set the caption of the window to Item's data
													 }
												 }
						  }break;

						  case IDB_ADD:  { // If the control id is what we gave to the add button then
											 if (HIWORD(wParam) == BN_CLICKED)  { // If the button was clicked then
												 TCHAR *NewItem; // Pointer to the new item's text

												 int nTextLen = (int)SendMessage(hEdit, WM_GETTEXTLENGTH, 0, 0); // Get the length of the edit box

												 if (nTextLen > 0)  { // If the text lenght is greater than 0 then

													 NewItem = (TCHAR*)malloc(nTextLen); // allocate the new space for the text

													 SendMessage(hEdit, WM_GETTEXT, (nTextLen + 1), (LPARAM)NewItem); // save the text to the NewItem memory space

													 AddItem(hListbox, NewItem); // Add the item to the listbox
												 }
											 }
						  }break;
						  }
	}

		/*if (LOWORD(wParam) == 1 &&
		HIWORD(wParam) == BN_CLICKED &&
		(HWND) lParam == hwndButton)ss
		}*/

	default: return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

	return 0;
}

/*
This is a quick and easy function to add items to a listbox for you
*/
LRESULT AddItem(HWND hwnd, LPCTSTR lpstr)  {
	return SendMessage(hwnd, LB_ADDSTRING, 0, (LPARAM)lpstr); /* This just sends a message to the lb for you
															  Check MSDN for a complete list of commands
															  you may send to listboxes to get information */
}
