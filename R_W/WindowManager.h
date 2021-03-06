#ifndef ___WinManager___
#define ___WinManager___
#include <tchar.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <windows.h>
#include <map>

template <class Key,class Value>
bool insert2map(std::map<Key,Value> &_Table,Key _key,Value _val)
    {
        if(_Table.end() != _Table.find(_key))
            return false;
        else
        {
            _Table.insert(std::map<Key,Value>::value_type(_key,_val));
            return true;}
    }
#ifndef PROP_WINPROC
extern LPCWSTR PROP_WINPROC;
#endif
typedef void (*KeyHookPtr)(HWND,LPARAM);
//ｳｨﾝﾄﾞｳの管理ｸﾗｽの基底ｸﾗｽ
class WinManager
{
public:
	//ｺﾝｽﾄﾗｸﾀ及びﾃﾞｽﾄﾗｸﾀ
	WinManager(){};
	virtual ~WinManager(){};
protected:
	//各種ﾒﾝﾊﾞ変数
	WNDCLASSEX	m_wcex;//ｳｲﾝﾄﾞｳｸﾗｽ
	HWND    m_hwnd;//ｳｲﾝﾄﾞｳﾊﾝﾄﾞﾙ
	MSG     m_msg;//ﾒｯｾｰｼﾞ
	int     m_wWidth;//ｳｲﾝﾄﾞｳの幅
	int     m_wHeight;//ｳｲﾝﾄﾞｳの高さ
    int     m_cWidth;//ｸﾗｲｱﾝﾄ領域の幅
    int     m_cHeight;//ｸﾗｲｱﾝﾄ領域の高さ
	int     m_WINDOWMODE;//ﾌﾙｽｸﾘｰﾝかｳｲﾝﾄﾞｳﾓｰﾄﾞか
    std::map<WPARAM,KeyHookPtr> m_KeyHookTable;
    static void    PostDestroy(HWND hwnd,LPARAM lp){PostMessage(hwnd,WM_DESTROY,0,0);}
public:
	//各種ﾒﾝﾊﾞ関数
	//初期化
	HRESULT Init(HINSTANCE hInstance,int nShowCmd,int,int);
	//ｺｰﾙﾊﾞｯｸ
	static  LRESULT CALLBACK MyProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );
	virtual LRESULT AppProc(UINT msg, WPARAM wParam, LPARAM lParam ) = 0;
	//ﾒｯｾｰｼﾞﾙｰﾌﾟ
	virtual HRESULT MsgLoop() = 0;
	virtual VOID	AppLoop() = 0;
	virtual HRESULT Release() = 0;
    inline  HWND GetWindowHandle()const{return m_hwnd;}
    inline  int GetWindowcHeight()const {return m_cHeight;}
    inline  int GetWindowcWidth()const{return m_cWidth;}
    bool SetKeyHook(UINT msg,KeyHookPtr ptr){return insert2map(m_KeyHookTable,msg,ptr);}
	BOOL SetWindowTitle(const wchar_t* in_title);
};

#endif //___WinManager___