#ifndef ___C_STATE_2011_01_30___
#define ___C_STATE_2011_01_30___

//状態遷移クラス
class CState
{
public:
    CState(){}
    virtual CState(){}
protected:
    virtual void Run() = 0;
    virtual void LoadData() = 0;
    virtual 
};

class CStTitle
{

};
#endif