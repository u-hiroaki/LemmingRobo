#ifndef ___CGAME_STAGE_H_2013_01_20___
#define ___CGAME_STAGE_H_2013_01_20___
#include <cstring>
#include "DXTemplateUtility.h"

//�X�e�[�W���̊Ǘ��N���X
//�X�e�[�W�T�C�Y��20x20(30x30�h�b�g)
class CGameStage{
public:
    CGameStage()
    {std::memset(m_StageInfo,0,sizeof(char)*20*20 );}
    ~CGameStage(){}
    void Render(){}
    void Update();
protected:
    char m_StageInfo[20][20];
    tComPtr<IDirect3DTexture9> blocktex[16];
};
#endif//___CGAME_STAGE_H_2013_01_20___