#ifndef __HS_ADAPT_H__
#define __HS_ADAPT_H__


extern int Win_Width, Win_Height;


#define HS_LEFT (-1.0)
#define HS_RIGHT (1.0)
#define HS_BUTTOM (-1.0)
#define HS_TOP (-1.0)

#define HS_DISTAN_X 2
#define HS_DISTAN_X 2

#define HS_INT_FLT_X(x) ( (x)/(Win_Width*0.5) - 1 )
#define HS_INT_FLT_Y(y) ( (y)/(Win_Height*0.5) - 1 )

#define HS_FLT_INT_X(x) ( ((y)+1) * (Win_Width >>1))
#define HS_FLT_INT_Y(y) ( ((y)+1) * (Win_Height>>1))



#endif