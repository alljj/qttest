#ifndef WINDOW_H
#define WINDOW_H
#include <windows.h>

HWND findDesktopIconWnd();//找到桌面句柄
void SendMessageToDesktop();//调用主窗口
HWND GetWorkerW();//得到主窗口


#endif // WINDOW_H
