#pragma once
#include "SwndFrame.h"
#include "SCaptureButton.h"
class CWindowHelperHander
{
	friend class CMainDlg;
public:
	CWindowHelperHander();
	~CWindowHelperHander();
	void OnInit(SOUI::SWindow *pPageRoot); 
protected:
	EVENT_MAP_BEGIN()
		EVENT_NAME_HANDLER(L"img_capture_host", EventCapture::EventID, OnEventCaptureHost)
		EVENT_NAME_HANDLER(L"img_capture_host", EventCaptureFinish::EventID, OnEventCaptureHostFinish)
	EVENT_MAP_BREAK()

protected:
	void OnEventCaptureHost(EventArgs *pEvt);
	void OnEventCaptureHostFinish(EventArgs *pEvt);
	void UpdataWindowInf(HWND hWnd);
private:
	SwndFrame       m_wndFrame;
	HWND m_hHostWnd,m_hLastHwnd;
	SWindow	*m_HostRoot;
};