#include <libming.h>

int main()
{
	FILE *fontfile;
	
	SWFMovie m = newSWFMovieWithVersion(9);
	SWFText text = newSWFText();
	
	SWFFont font = newSWFFont_fromFile(MEDIADIR "/font01.fdb");
	if(font == NULL)
		exit(1);
	
	SWFMovie_assignSymbol(m, (SWFCharacter)text, "mytext");
	SWFText_setFont(text, font);
	SWFText_setColor(text, 0, 0, 0, 0xff);
	SWFText_setHeight(text, 20);
	SWFText_moveTo(text, 100, 100);
	SWFText_addString(text, "The quick brown fox jumps over the lazy dog. 1234567890", NULL);
	
	SWFMovie_add(m, text);
	SWFMovie_nextFrame(m);
	SWFMovie_save(m, "test01.swf");

	return 0;
}
	