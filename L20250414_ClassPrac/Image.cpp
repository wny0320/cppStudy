#include "Image.h"

void Image::Terminate(Pixel* _Pixel)
{
	delete[] _Pixel;
	_Pixel = nullptr;
}
