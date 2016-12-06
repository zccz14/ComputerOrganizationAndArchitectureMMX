void ImageFusionCPUBenchmark(CImage src1, CImage src2, WORD fading) {
    CImage temp1, temp2;
    int width = min(src1.GetWidth(), src2.GetWidth());
    int height = min(src1.GetHeight(), src2.GetHeight());
    temp1.Create(width, height, 24);
    temp2.Create(width, height, 24);
    while (1) {
        ImageFusion(src1, src2, image3, 0);
        ImageFusionMMX(src1, src2, image4, 0);
    }
}