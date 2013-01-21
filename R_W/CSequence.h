#ifndef  ___CSequence_H_2013_01_17___
#define ___CSequence_H_2013_01_17___
#include <d3d9.h>

class CSequence{
public:
    CSequence(){};
    virtual ~CSequence(){}
    virtual void Init()=0;
    virtual void Update()=0;
    virtual void Render(IDirect3DDevice9 *dev)=0;
};
#endif//___CSequence_H_01_17___