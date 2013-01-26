#include "CGameStage.h"

void CGameStage::Update()
{
    for(int i=0;i<20;++i)
        for(int j=0;j<20;++j)
        {
           if( m_Blocks[i][j].Update(this->m_StageInfo[i][j],robots))
               m_Blocks[i][j].Render();
        }
}