#ifndef ____CSEQUENCE_TITLE_H_2013_01_17___
#define ____CSEQUENCE_TITLE_H_2013_01_17___
#include "CSequence.h"
#include "C2DSprite.h"

class CSequenceTitle:public CSequence
{
public:
    CSequenceTitle(){}
    ~CSequenceTitle(){}
    void Init();
    void Render(IDirect3DDevice9 *dev);
    void  Update();
private:
    C2DSprite m_bg;
    C2DSprite tile[20][20];
    bool InnerInit();
};

#endif//____CSEQUENCE_TITLE_H_2013_01_17___