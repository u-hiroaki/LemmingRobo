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

//初期化
//位置情報とどのタイプのブロックかを指定
void CGameStageBlock::Initialize(const int in_x,const int in_y,const int blockType)
{
    float tmp_u=0.0f,tmp_v=0.0f;
    m_buffer.setActivity(true);
    m_buffer.setPos(in_x,in_y);
    m_buffer.setUV(tmp_u,tmp_v,30.0f/128.0f,30.0f/128.0f);
}
