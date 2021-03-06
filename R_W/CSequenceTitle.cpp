#include "CSequenceTitle.h"
#include "CDirectXDevice.h"
#include "DXTemplateUtility.h"
const int tmpW=20;
const int tmpH=20;


void CSequenceTitle::Init()
{
    tComPtr<IDirect3DTexture9> bgtex;
    D3DXCreateTextureFromFile(CDirectXDevice::GetDxDevice().GetDevice(),
        L"./Data/Title.png",bgtex.ToCreator());
    m_bg.setScreenSize(800,600);
    m_bg.setActivity(true);
    m_bg.setTexture(bgtex,true);
    m_bg.setUV(0,0,(float)800/1024,(float)600/1024);
    m_bg.setScale((float)800/1024,(float)800/1024);

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
    m_bg.draw();
}