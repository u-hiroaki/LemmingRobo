#include "CSequenceTitle.h"
#include "CDirectXDevice.h"
#include "DXTemplateUtility.h"
const int tmpW=20;
const int tmpH=20;

const int sample[20][20] =
{
    {},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
    {},
    {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
    {},
    {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
    {},
    {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
    {},
    {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
    {},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

void CSequenceTitle::Init()
{
    tComPtr<IDirect3DTexture9> bgtex;/*
    D3DXCreateTextureFromFile(CDirectXDevice::GetDxDevice().GetDevice(),
        L"./Data/Title.png",bgtex.ToCreator());
    m_bg.setScreenSize(800,600);
    m_bg.setActivity(true);
    m_bg.setTexture(bgtex,false);
    m_bg.setSize(800,600);
    m_bg.setUV(0,0,(float)800/1024,(float)600/1024);*/
    D3DXCreateTextureFromFile(CDirectXDevice::GetDxDevice().GetDevice(),
        L"./Data/block.png",bgtex.ToCreator());
    for(int i=0;i<tmpH;++i)
        for(int j=0;j<tmpW;++j)
        {
            tile[i][j].setScreenSize(800,600);
            tile[i][j].setTexture(bgtex,true);
            tile[i][j].setUV(0.0f,0.0f,30.0f/128.0f,30.0f/128.0f);
            tile[i][j].setPos(j*30,i*30);
            tile[i][j].setScale(30.0f/128.0f,30.0f/128.0f);
            if(sample[i][j])
                tile[i][j].setActivity(true);
            else if(j==0||j==tmpW-1)
                tile[i][j].setActivity(true);
            else tile[i][j].setActivity(false);
        }

}

void CSequenceTitle::Render(IDirect3DDevice9* dev)
{
    CDirectXDevice::GetDxDevice().Begin();
    C2DSprite::drawAll(CDirectXDevice::GetDxDevice().GetDevice());
    C2DSprite::clearDrawList();
    CDirectXDevice::GetDxDevice().End();
}

void CSequenceTitle::Update()
{
//    m_bg.draw();
    for(int i=0;i<tmpH;++i)
        for(int j=0;j<tmpW;++j)
            tile[i][j].draw();
}