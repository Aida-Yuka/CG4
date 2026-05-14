#include "object3d.hlsli"

struct Material
{
    float4 color;
    uint enableLighting;
    float4x4 uvTransform;
    float shininess;
};

struct DirectionalLight
{
    float4 color;
    float3 direction;
    float intensity;
};

struct Camera
{
    float3 worldPosition;
};

struct PixelShaderOutput
{
    float4 color : SV_TARGET0;
};

ConstantBuffer<Material> gMaterial : register(b0);
Texture2D<float4> gTexture : register(t0);
SamplerState gSampler : register(s0);
ConstantBuffer<DirectionalLight>gDirectionalLight:register(b1);
ConstantBuffer<Camera> gcamera : register(b2);

PixelShaderOutput main(VertexShaderOutput input)
{
    PixelShaderOutput output;
    float4 textureColor = gTexture.Sample(gSampler, input.texcoord);
    
    //Lightingするか
    if (gMaterial.enableLighting != 0)
    {
        float3 toEye = normalize(gcamera.worldPosition - input.worldPosition);
        float3 reflectLight = reflect(gDirectionalLight.direction,normalize(input.normal));
        float RdotE = dot(reflectLight, toEye);
        float specularPow = pow(saturate(RdotE), gMaterial.shininess);//反射強度
        float NdotL = dot(normalize(input.normal), -gDirectionalLight.direction);
        float cos = pow(NdotL * 0.5f + 0.5f, 2.0f);
        //output.color = gMaterial.color * textureColor * gDirectionalLight.color * cos * gDirectionalLight.intensity;
        
        //拡散反射
        float3 diffuse = gMaterial.color.rgb * textureColor.rgb * gDirectionalLight.color.rgb * cos * gDirectionalLight.intensity;
        //鏡面反射
        float3 specular = gDirectionalLight.color.rgb * gDirectionalLight.intensity * specularPow * float3(1.0f, 1.0f, 1.0f);
        //拡散反射・鏡面反射
        output.color.rgb = diffuse + specular;
        //アルファは今まで通り
        output.color.a = gMaterial.color.a * textureColor.a;
    }
    else //lightingしない場合
    {
        output.color = gMaterial.color * textureColor;
    }
    
    return output;
}