#include <Windows.h>
#include <iostream>

HHOOK mice;

LRESULT CALLBACK Track(int proton, WPARAM electron, LPARAM nutron)
{
	switch (proton)
	{
	case(HC_ACTION):
	{
		switch (electron)
		{
		case(WM_MOUSEMOVE):
		{
			auto& root = *(const MOUSEHOOKSTRUCT*)nutron;
			std::cout << "x::" << root.pt.x <<" "<< "y::" << root.pt.y << std::endl;
		};
		default:
		{
			nullptr;
		};
		};
	};
	default:
	{
		CallNextHookEx(mice, proton, electron, nutron);
	};
	};
	return CallNextHookEx(mice, proton, electron, nutron);
};

int main()
{
	mice = SetWindowsHookEx(WH_MOUSE_LL, Track, nullptr, 0);
	MSG Stand_In_The_queue;
	while (GetMessage(&Stand_In_The_queue, nullptr, 0, 0)!=0) {};
	return 0;
}