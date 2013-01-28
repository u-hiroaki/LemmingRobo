#ifndef ___CSEQUENCE_GAME_H_2013_01_20___
#define ___CSEQUENCE_GAME_H_2013_01_20___

#include "CSequence.h"
#include "CGameStage.h"

class CSequenceGame:public CSequence{
public:
    CSequenceGame(){}
    ~CSequenceGame(){}
    void Init();
    void Update(){}
    void Render(IDirect3DDevice9* dev){}
private:
    void InnerInitialize();
	CGameStage m_gameStage;
};

#endif//___CSEQUENCE_GAME_H_2013_01_20___