#pragma once
#include <d3d9.h>
#include <list>
#include <vector>
#include <d3dx9.h>
#include "DXTemplateUtility.h"

/*********************************************************
��ʂɕ`�悵�������p�N���X
�e���Ƃ�
�G�l�~�[�Ղ�Ƃ�
����Ȋ���

�e�N�X�`���ւ̃|�C���^�ƗD��x��pair�ɂ���multimap�̃L�[�ɂ���?
�ŁA���̂����Ƃ��ŊǗ�?
�ʁ[�񥥥
*********************************************************/

class C2DBuffer
{
    static IDirect3DVertexBuffer9* vBuff;
    static IDirect3DVertexBuffer9* streamBuff;
    static std::list<C2DBuffer*> drawObjectList;		// �`��Ώۃ��X�g
    static std::vector<float>      drawBuffer;
    static IDirect3DVertexDeclaration9 *decl;	// ���ʒ��_�錾
    static ID3DXEffect *effect;					// ���ʃG�t�F�N�g
    static int scW, scH;			// �X�N���[���T�C�Y
    static tComPtr< IDirect3DTexture9> tex;		// �e�N�X�`��
    
    IDirect3DVertexBuffer9*         g_pVBBox;
    IDirect3DIndexBuffer9*          g_pIBBox;

    int polyW, polyH;		// �|���S���T�C�Y
    float pivotX, pivotY;	// �s�{�b�g���W
    float posX, posY, posZ;	// �ʒu
    float rad;				// ��]�p�x�i���W�A���j
    float scaleX, scaleY;	// �X�P�[��
    float uvLeft, uvTop;	// UV������W
    float uvW, uvH;			// UV����
    float alpha;			// ���ߓx
    bool bActivity;			// �A�N�e�B�u

    // �R�s�[
    void copy( const C2DBuffer &r );

public:
    C2DBuffer();
    C2DBuffer( const C2DBuffer &r );
    ~C2DBuffer();

    C2DBuffer &operator =( const C2DBuffer &r ) { copy(r); return *this; }

    //effect���쐬
    static void begin_first( IDirect3DDevice9* dev );

    // ��Еt��
    static void end_last();

    // �|���T�C�Y�w��
    void setSize( int w, int h );

    // �X�N���[���T�C�Y�w��
    static void setScreenSize( int w, int h );

    // �s�{�b�g�w��
    void setPivot( float x, float y );
    void setPivotCenter();
    void getPivot( float *x, float *y );

    // �p���w��
    void setPos( float x, float y );
    void getPos( float *x, float *y );
    void setRotate( float deg );
    float getRotate();
    void setScale( float sx, float sy );
    void getScale( float *sx, float *sy );

    // �e�N�X�`���ݒ�
    static void setTexture( tComPtr<IDirect3DTexture9> tex, bool isResize );

    // UV�؂���w��
    void setUV( float l, float t, float w, float h );
    void getUV_LT( float *l, float *t );
    void getUV_WH( float *w, float *h );

    // ���ݒ�
    void setAlpha( float a );
    float getAlpha();

    // �v���C�I���e�B�ݒ�
    void setPriority( float z );
    float getPriority();

    // �A�N�e�B�r�e�B�ݒ�
    void setActivity( bool isActive );
    bool getActivity();

    // �`�惊�X�g�ɐς�
    void draw();

    // �`�惊�X�g����C�ɕ`��
    static void drawAll( IDirect3DDevice9 *dev );

    // �`�惊�X�g�N���A
    static void clearDrawList();
};
