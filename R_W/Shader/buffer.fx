float4x4 proj;
texture tex;
float alpha;

sampler smp = sampler_state {
    texture = <tex>;
};


struct VS_IN {
    float3 pos : POSITION;
    float2 uv  : TEXCOORD0;
};

struct VS_OUT {
    float4 pos : POSITION;
    float2 uv  : TEXCOORD0;
};


// ���_�V�F�[�_
VS_OUT vs_main( VS_IN In ) {
   VS_OUT Out = (VS_OUT)0;
   
   Out.pos = mul( float4(In.pos, 1.0f), proj );
   Out.uv  = In.uv;
   return Out;
}


// �s�N�Z���V�F�[�_
float4 ps_main(VS_OUT In) : COLOR0 {
    float4 color = tex2D( smp, In.uv );
    
	if(In.uv.x > 0.2 && In.uv.x < 0.8)
	 if(In.uv.y > 0.2 && In.uv.y < 0.8)
	color= float4(1,0,0,1);
	color.a *= alpha;
    return color;
}


technique Tech {
    pass p0 {
        VertexShader = compile vs_3_0 vs_main();
        PixelShader  = compile ps_3_0 ps_main();
        AlphaBlendEnable = true;
        SrcBlend = SRCALPHA;
        DestBlend = INVSRCALPHA;
    }
}
