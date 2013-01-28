#ifndef ___CGAME_STAGE_BLOCK___
#define ___CGAME_STAGE_BLOCK___

#include "CGameCharactor.h"
#include "C2DBuffer.h"
class CGameStageBlock
{
    typedef bool (CGameStageBlock::*UpdateFunc)(CGameCharactor&);
public:
    CGameStageBlock();
    ~CGameStageBlock(){}
    void Initialize(const int,const int,const int);
    bool Update(const char,CGameCharactor&);
    void Render();
private:
    UpdateFunc UpdateFuncTable[8];//ä÷êîÉeÅ[ÉuÉã
    bool InnerUpdateNormal(CGameCharactor&){return true;};
    C2DBuffer m_buffer;
};

#endif//___CGAME_STAGE_BLOCK___