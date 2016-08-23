#pragma once

#include <d3d11.h>
#include <directxmath.h>

#include "textureclass.h"

class BitmapClass
{
private:
    struct VertexType
    {
        DirectX::XMFLOAT3 position;
        DirectX::XMFLOAT2 texture;
    };

public:
    BitmapClass();
    BitmapClass(const BitmapClass&);
    ~BitmapClass();

    bool Initialize(ID3D11Device*, ID3D11DeviceContext*, int, int, char*, int, int);
    void Shutdown();
    bool Render(ID3D11DeviceContext*, int, int);

    int GetIndexCount();
    ID3D11ShaderResourceView* GetTexture();

private:
    bool InitializeBuffers(ID3D11Device*);
    void ShutdownBuffers();
    bool UpdateBuffers(ID3D11DeviceContext*, int, int);
    void RenderBuffers(ID3D11DeviceContext*);

    bool LoadTexture(ID3D11Device*, ID3D11DeviceContext*, char*);
    void ReleaseTexture();

private:
    ID3D11Buffer *m_vertexBuffer, *m_indexBuffer;
    int m_vertexCount, m_indexCount;
    TextureClass* m_Texture;
    int m_screenWidth, m_screenHeight;
    int m_bitmapWidth, m_bitmapHeight;
    int m_previousPosX, m_previousPosY;
};