﻿#pragma once
#include "../common/stdinc.h"
#include "font.h"

class CGame
{
public:
    struct
    {
        IDirect3DDevice9** ppD3DDevice;
        void* pTexturePCVirtualTable;
        void* fnGraphics_SetRenderState;
        void* fnDictionary_GetElementByKey;
        void* fnHash_HashStringFromSeediCase;
        int* pGameEpisodeID;

        CFontInfo* pFont_Datas;
        CFontDetails* pFont_Details;
        CFontRenderState* pFont_RenderState;

        float* pFont_BlipWidth;
        float* pFont_ResolutionX;
        float* pFont_ButtonWidths;

        void* fnFont_GetRenderIndex;
        void* fnFont_PrintChar;
        void* fnFont_GetCharacterSizeNormal;
        void* fnFont_GetCharacterSizeDrawing;
        void* fnFont_Render2DPrimitive;
        void* fnFont_AddTokenStringWidth;
        void* fnFont_ParseToken;
        void* fnFont_ProcessToken;
        void* fnFont_ProcessString;

        void* fnMailAppendByteString;
        char* pDLCTruncateBuffer;

    } game_addr;

    void Graphics_SetRenderState(void* texture, int = 1);

    void* Dictionary_grcTexturePC_GetElementByKey(void* dictionary, uint hash);

    uint Hash_HashStringFromSeediCase(const char* str, uint hash = 0);

    uchar Font_GetRenderIndex();
    float Font_GetCharacterSizeNormal(GTAChar chr);
    float Font_GetCharacterSizeDrawing(GTAChar chr, bool use_extra_width);
    void Font_Render2DPrimitive(const CRect* screen_rect, const CRect* texture_rect, uint color, bool buffered);
    void Font_PrintChar(float posx, float posy, GTAChar chr, bool buffered);
    void Font_ProcessString(float posx, float posy, const GTAChar* str, void* a4);

    // ParseToken逻辑
    // 1000+ BLIP
    // 256-300 按键类
    // 全部strcmp都不通过则当成单字符token，返回此字符
    int Font_ParseToken(const GTAChar* text, GTAChar* text_to_show, TokenStruct* token_data);

    const GTAChar* Font_ProcessToken(const GTAChar* text, uint* color, bool get_color, uchar* color_code,
        int* key_number, bool* is_new_line_token, GTAChar* text_to_show,
        TokenStruct* token_data);

    void Font_AddTokenStringWidth(const GTAChar* text, float* width, int render_index);

    void MailAppendByteString(int id, const uchar* str);
};
