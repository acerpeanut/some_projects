#ifndef __SOLIAR_H__
#define __SOLIAR_H__

typedef struct{
	int enable;
	double x,y;
	double m;
	double vx,vy;
}astrophere;

#define NUMALL 100
#define G      25.0
#define pow2(x) ((x)*(x))
#define thetaT 1

extern astrophere as_list[NUMALL];

int init_astrophere();
int new_astrophere(double x,double y,double m,double vx,double vy);
int move_astrophere_step(int index);
int move_astrophere_all(int count);
int balance_astrophere(double x, double y, int center_index, double *vx, double *vy);



#endif