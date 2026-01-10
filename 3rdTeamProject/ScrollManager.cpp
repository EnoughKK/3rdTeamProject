#include "pch.h"
#include "ScrollManager.h"

void ScrollManager::Scroll_Lock() {

	if (WINCX - 2880 > ScrollX)
		ScrollX = WINCX - 2880;

	if (WINCY - 1080 > ScrollY)
		ScrollY = WINCY - 1080;
}
