#ifndef __PTL_MACRO_HPP__
#define __PTL_MACRO_HPP__
#include <windows.h>


namespace ptl {
	class Macro {
	public:

		// Simple function for waiting the program for specific amount of time
		// Extremely useful and essential since keystrokes without delay between them
		// does not work quite as expected
		void delay(const DWORD pDuration) {
			Sleep(pDuration);
		}

		// First parameter is virtual code and second is scan code.
		// Normally scan codes can be easily mapped from virtual code with function MapVirtualKey
		// But it has been reported that MapVirtualKey function rarely does not work properly.
		// Therefore I left second argument optional.
		void keyDown(const BYTE pVirtualCode, BYTE pScanCode = 0){
			if (pScanCode == 0) {
				pScanCode = MapVirtualKey(pVirtualCode, MAPVK_VK_TO_VSC);
			}
			keybd_event(pVirtualCode, pScanCode, 0, 0);
		}

		// First parameter is virtual code and second is scan code.
		// Normally scan codes can be easily mapped from virtual code with function MapVirtualKey
		// But it has been reported that MapVirtualKey function rarely does not work properly.
		// Therefore I left second argument optional.
		void keyUp(const BYTE pVirtualCode, BYTE pScanCode = 0){
			if (pScanCode == 0) {
				pScanCode = MapVirtualKey(pVirtualCode, MAPVK_VK_TO_VSC);
			}
			keybd_event(pVirtualCode, pScanCode, KEYEVENTF_KEYUP, 0);
		}

		// Move mouse cursor
		// Relative means change its position relative to its previous position
		void mouseMove(const DWORD x, const DWORD y, const bool isRelative = false) {
			if (isRelative) {
				mouse_event(MOUSEEVENTF_MOVE, x, y, 0, 0);
			}
			else {
				mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE, x, y, 0, 0);
			}
		}

		// Mouse wheel positive values means scrooling up and negative values means scrooling down
		void mouseWheel(const DWORD pAmount) {
			mouse_event(MOUSEEVENTF_WHEEL, 0, 0, pAmount, 0);
		}

		// Mouse left button down, relative means change cursor position relative to its previous position
		// x and y coordinates vary between 0 and 65536 and (0, 0) is top left corner
		void leftButtonDown(const DWORD x, const DWORD y, const bool isRelative = false) {
			if (isRelative) {
				mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
			}
			else {
				mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE | MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
			}
		}

		// Mouse left button up, relative means change cursor position relative to its previous position
		// x and y coordinates vary between 0 and 65536 and (0, 0) is top left corner
		void leftButtonUp(const DWORD x, const DWORD y, const bool isRelative = false) {
			if (isRelative) {
				mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_LEFTUP, x, y, 0, 0);
			}
			else {
				mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE | MOUSEEVENTF_LEFTUP, x, y, 0, 0);
			}
		}

		// Mouse middle button down, relative means change cursor position relative to its previous position
		// x and y coordinates vary between 0 and 65536 and (0, 0) is top left corner
		void middleButtonDown(const DWORD x, const DWORD y, const bool isRelative = false) {
			if (isRelative) {
				mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_MIDDLEDOWN, x, y, 0, 0);
			}
			else {
				mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE | MOUSEEVENTF_MIDDLEDOWN, x, y, 0, 0);
			}
		}

		// Mouse middle button up, relative means change cursor position relative to its previous position
		// x and y coordinates vary between 0 and 65536 and (0, 0) is top left corner
		void middleButtonUp(const DWORD x, const DWORD y, const bool isRelative = false) {
			if (isRelative) {
				mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_MIDDLEUP, x, y, 0, 0);
			}
			else {
				mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE | MOUSEEVENTF_MIDDLEUP, x, y, 0, 0);
			}
		}

		// Mouse right button down, relative means change cursor position relative to its previous position
		// x and y coordinates vary between 0 and 65536 and (0, 0) is top left corner
		void rightButtonDown(const DWORD x, const DWORD y, const bool isRelative = false) {
			if (isRelative) {
				mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_RIGHTDOWN, x, y, 0, 0);
			}
			else {
				mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE | MOUSEEVENTF_RIGHTDOWN, x, y, 0, 0);
			}
		}

		// Mouse right button up, relative means change cursor position relative to its previous position
		// x and y coordinates vary between 0 and 65536 and (0, 0) is top left corner
		void rightButtonUp(const DWORD x, const DWORD y, const bool isRelative = false) {
			if (isRelative) {
				mouse_event(MOUSEEVENTF_MOVE | MOUSEEVENTF_RIGHTUP, x, y, 0, 0);
			}
			else {
				mouse_event(MOUSEEVENTF_ABSOLUTE | MOUSEEVENTF_MOVE | MOUSEEVENTF_RIGHTUP, x, y, 0, 0);
			}
		}
	};
}


#endif /* __PTL_MACRO_HPP__ */

