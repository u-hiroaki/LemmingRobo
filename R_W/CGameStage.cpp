#include "CGameStage.h"

void CGameStage::Initilize()
{
    for(int i=0;i<MAX_STAGE_HEIGHT;++i)
        for(int j=0;j<MAX_STAGE_WIDTH;++j)
            m_Blocks[i][j].Initialize(i,j,0);
}

void CGameStage::Update()
{
    for(int i=0;i<MAX_STAGE_HEIGHT;++i)
        for(int j=0;j<MAX_STAGE_WIDTH;++j)
        {
               m_Blocks[i][j].Render();
        }
}