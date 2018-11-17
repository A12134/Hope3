#ifndef FLIP_BOOK_H
#define FLIP_BOOK_H
class Flipbook
{
private:
	float mSizeX, mSizeY;

public:

	// @param x: the size of the flipbook single sprite width
	// @param y: the size of the flipbook signle sprite height
	Flipbook(float x, float y);
	~Flipbook();
};
#endif


