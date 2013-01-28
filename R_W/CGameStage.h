#ifndef ___CGAME_STAGE_H_2013_01_20___
#define ___CGAME_STAGE_H_2013_01_20___
#include <cstring>
#include "DXTemplateUtility.h"
#include "CGameStageBlock.h"

#define MAX_STAGE_WIDTH 20
#define MAX_STAGE_HEIGHT 20
#define MAX_BLOCK_NUM MAX_STAGE_HEIGHT*MAX_STAGE_WIDTH

//�X�e�[�W���̊Ǘ��N���X
//�X�e�[�W�T�C�Y��20x20(30x30�h�b�g)
class CGameStage{
public:
    CGameStage(){}
    ~CGameStage(){}
    void Render(){}
    void Update();
    void Initilize();
protected:
    CGameStageBlock m_Blocks[MAX_STAGE_HEIGHT][MAX_STAGE_WIDTH];
    tComPtr<IDirect3DTexture9> blocktex[16];
    CGameCharactor robots;
};
#endif//___CGAME_STAGE_H_2013_01_20___