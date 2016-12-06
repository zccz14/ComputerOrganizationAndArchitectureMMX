void ImageFusion(CImage &from, CImage &to, CImage &dest, WORD fading) {
    int width = dest.GetWidth(), height = dest.GetWidth();
    BYTE *pFrom = (BYTE*)from.GetPixelAddress(0, height - 1);
    BYTE *pTo = (BYTE*)to.GetPixelAddress(0, height - 1);
    BYTE *pDest = (BYTE*)dest.GetPixelAddress(0, height - 1);
    int t = 3 * height * width;
    while (t--) {
        *pDest = (*pFrom * (0x8000 - fading) + *pTo * fading) / 0x8000;
        pTo++;
        pFrom++;
        pDest++;
    }
}
