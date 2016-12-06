void ImageFusionMMX(CImage &from, CImage &to, CImage &dest, WORD fading) {
    int width = dest.GetWidth(), height = dest.GetWidth();
    DWORD *pFrom = (DWORD*)from.GetPixelAddress(0, height - 1);
    DWORD *pTo = (DWORD*)to.GetPixelAddress(0, height - 1);
    DWORD *pDest = (DWORD*)dest.GetPixelAddress(0, height - 1);
    DWORD *pDestEnd = (DWORD*)dest.GetPixelAddress(width - 1, 0);
    WORD fade1[4], fade2[4];
    fade1[0] = fade1[1] = fade1[2] = fade1[3] = 0x7fff - fading;
    fade2[0] = fade2[1] = fade2[2] = fade2[3] = fading;
    LPWORD fade_ptr1 = fade1, fade_ptr2 = fade2;
    _asm {
        pxor mm7, mm7
        mov ebx, fade_ptr1
        movq mm2, [ebx]
        mov ebx, fade_ptr2
        movq mm3, [ebx]
    }
    while (pDest <= pDestEnd) {
        _asm {
            mov ebx, pFrom
            movd mm0, [ebx]

            mov ebx, pTo
            movd mm1, [ebx]

            punpcklbw mm0, mm7
            punpcklbw mm1, mm7

            pmulhw mm0, mm2
            pmulhw mm1, mm3
            paddw mm0, mm1
            paddw mm0, mm0
            packuswb mm0, mm7

            mov edi, pDest
            movd[edi], mm0
        }
        pFrom++;
        pTo++;
        pDest++;
    }
    _asm EMMS
}
