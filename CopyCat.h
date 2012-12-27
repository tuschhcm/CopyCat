#ifndef CopyCat_h
#define CopyCat_h

#include <Arduino.h>

class CopyCat{
public:
	CopyCat();
	void playPattern(int i);
	void recievePattern(int r, int g, int b, int i);
	bool compare(int i);

private:
	int gamePattern[10];
	int playerPattern[10];
};

#endif