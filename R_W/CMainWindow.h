#ifndef ___CMAINWINDOW_2011_11_26___
#define ___CMAINWINDOW_2011_11_26___
#include "WindowManager.h"
#include "CSequenceTitle.h"
#include "CSequenceDummy.h"
#include "FPSCounter.h"
///���C���E�B���h�E�Ȃ̂ŃV���O���g��


class CMainWindow : public WinManager
{
public:
static	CMainWindow& GetMainWindow()
	{
		static CMainWindow Instance;
		return Instance;
	}
	LRESULT AppProc(UINT msg,WPARAM wParam,LPARAM lParam);
	HRESULT MsgLoop();
	VOID AppLoop();
	HRESULT Release();
private:
	CMainWindow()
		:m_fpsc(100)
    {ZeroMemory(&m_rect,sizeof(m_rect));};
    ~CMainWindow(){};
	CMainWindow(CMainWindow& obj){};
	void operator=(CMainWindow& obj){};
    CSequenceTitle m_sequence;
	CFPSCounter m_fpsc;
protected:
    void HookKey(WPARAM,LPARAM);
    void ChangeScr2Window();
    void ChangeScr2Full();

	RECT     m_rect;
};

#endif //___CMAINWINDOW_2011_11_26___