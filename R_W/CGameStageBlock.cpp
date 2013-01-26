#include "CGameStageBlock.h"

CGameStageBlock::CGameStageBlock()
{
    this->UpdateFuncTable[0] = &CGameStageBlock::InnerUpdateNormal;
}

bool CGameStageBlock::Update(const char idx,CGameCharactor& obj)
{
    return (this->*UpdateFuncTable[idx])(obj);
}

void CGameStageBlock::Render()
{
    m_buffer.draw();
}

void CGameStageBlock::Initialize(const int in_x,const int in_y,)
{
    m_buffer.setActivity(true);
    m_buffer.setPos(in_x,in_y);
    m_buffer.setUV();
}
