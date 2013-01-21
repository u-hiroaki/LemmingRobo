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
//����޳�̊Ǘ��׽�̊��׽
class WinManager
{
public:
	//�ݽ�׸��y���޽�׸�
	WinManager(){};
	virtual ~WinManager(){};
protected:
	//�e�����ޕϐ�
	WNDCLASSEX	m_wcex;//����޳�׽
	HWND    m_hwnd;//����޳�����
	MSG     m_msg;//ү����
	int     m_wWidth;//����޳�̕�
	int     m_wHeight;//����޳�̍���
    int     m_cWidth;//�ײ��ė̈�̕�
    int     m_cHeight;//�ײ��ė̈�̍���
	int     m_WINDOWMODE;//�ٽ�ذ݂�����޳Ӱ�ނ�
    std::map<WPARAM,KeyHookPtr> m_KeyHookTable;
    static void    PostDestroy(HWND hwnd,LPARAM lp){PostMessage(hwnd,WM_DESTROY,0,0);}
public:
	//�e�����ފ֐�
	//������
	HRESULT Init(HINSTANCE hInstance,int nShowCmd,int,int);
	//����ޯ�
	static  LRESULT CALLBACK MyProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam );
	virtual LRESULT AppProc(UINT msg, WPARAM wParam, LPARAM lParam ) = 0;
	//ү����ٰ��
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