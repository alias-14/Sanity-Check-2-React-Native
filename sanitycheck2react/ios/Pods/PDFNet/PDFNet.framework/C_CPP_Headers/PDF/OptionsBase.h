// This file is autogenerated: please see the codegen template "Options"
#ifndef PDFTRON_H_CPPPDFOptionsBase
#define PDFTRON_H_CPPPDFOptionsBase

#include <SDF/ObjSet.h>
#include <PDF/ColorSpace.h>

namespace pdftron{ namespace PDF{ 

class OptionsBase
{
public:
	static double ColorPtToNumber(const ColorPt& cp) 
	{
		int num_comp = 3;
		int red = 0;
		int green = 0;
		int blue = 0;
		int alpha = 255;
		if(num_comp == 1) {
			red = (int)(255*cp.Get(0));
			green = red;
			blue = red;
		}
		else if(num_comp == 3 || num_comp == 4) {
			red = (int)(255*cp.Get(0));
			green = (int)(255*cp.Get(1));
			blue = (int)(255*cp.Get(2));
		}
		if(num_comp == 4) {
			alpha = (int)(255*cp.Get(3));
		}
		UInt32 num = ((0xFF&alpha) << 24)
				| ((0xFF&red) << 16)
				| ((0xFF&green) << 8)
				| ((0xFF&blue) << 0);
		return (double)num;
	}
	static ColorPt ColorPtFromNumber(double dnum) 
	{
		UInt32 num = (UInt32)dnum;
		return ColorPt(((num >> 16) & 0xFF)/255.0,
			((num >> 8) & 0xFF)/255.0,
			((num >> 0) & 0xFF)/255.0,
			((num >> 24)&0xFF)/255.0);
	}
};

}
}

#endif // PDFTRON_H_CPPPDFOptionsBase
