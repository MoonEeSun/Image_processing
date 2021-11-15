#include "main.h"

#define CLIP(x) (x < minVal) ? minVal : x > maxVal ? maxVal : x // ������ ȭ�Ұ��� ������ �Ѿ���� �˷��ִ� clipping
#define CLIPPIC_HOR(x) (x < 0) ? 0 : x >= WIDTH  ? WIDTH  - 1 : x // ȭ�Ұ� ���� �ۿ� �ִ��� �˷��ִ� clipping
#define CLIPPIC_VER(x) (x < 0) ? 0 : x >= HEIGHT ? HEIGHT - 1 : x // ȭ�Ұ� ���� �ۿ� �ִ��� �˷��ִ� clipping

#define MAX(x, y) x > y ? x : y
#define SWAP(x, y) {int tmp; tmp = x; x = y; y = tmp;}

// �������
typedef struct _Image_Buffer
{
	UChar* padding; // �е� ���� ���� ����

	UChar* Embossing;
	UChar* Sharpening;
	UChar* DoG;
	UChar* LoG; // LoG - operator ���� �����
	UChar* Median;
	UChar* Sobel;
	UChar* Blur;
	UChar* homogeneity;

}Img_Buf;

void ImageFiltering(UChar* Data, Img_Buf* img);
void ImageFilteringBlur(UChar* Data, Img_Buf* img);
void ImagePadding(Img_Buf* img, UChar* Buf, int width, int height, int maskSize);
void ImageOutput(UChar* Data, Int wid, Int hei, Char String[]);

void OutputBlock(Img_Buf* img, UChar *paddingBlock, int maskSize, int i, int j, int PStride);