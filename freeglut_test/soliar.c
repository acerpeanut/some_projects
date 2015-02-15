#include "soliar.h"
#include <string.h>
#include <math.h>

astrophere as_list[NUMALL];

int init_astrophere(){
	memset(as_list,0,sizeof(as_list));
	return 0;
}
int new_astrophere(double x,double y,double m,double vx,double vy){
	int i;
	for(i=0;i<NUMALL;i++){
		if(! as_list[i].enable){
			as_list[i].enable = 1;
			as_list[i].x = x;
			as_list[i].y = y;
			as_list[i].m = m;
			as_list[i].vx = vx;
			as_list[i].vy = vy;
			break;
		}
	}
	return i;
}


int move_astrophere_step(int index){
	if(as_list[index].enable){
		double Fx=0,Fy=0;
		for(int i=0;i<NUMALL;i++){
			if(i!=index && as_list[i].enable){
				double X2 = pow2(as_list[i].x - as_list[index].x);
				double Y2 = pow2(as_list[i].y - as_list[index].y);
				double R2 = X2+Y2;
				double F  = G*as_list[index].m*as_list[i].m/R2;
				double tmpFx = F*X2/R2*(as_list[i].x > as_list[index].x? 1: -1);
				double tmpFy = F*Y2/R2*(as_list[i].y > as_list[index].y? 1: -1);
				Fx += tmpFx;
				Fy += tmpFy;
			}
		}
		double Ax = Fx/as_list[index].m;
		double Ay = Fy/as_list[index].m;
		double theta_x = 1.0/2 * Ax * pow2(thetaT) + as_list[index].vx * thetaT;
		double theta_y = 1.0/2 * Ay * pow2(thetaT) + as_list[index].vy * thetaT;
		double theta_vx = Ax * thetaT;
		double theta_vy = Ay * thetaT;
		as_list[index].vx += theta_vx;
		as_list[index].vy += theta_vy;
		as_list[index].x  += theta_x;
		as_list[index].y  += theta_y;
	}
	return 0;
}

int move_astrophere_all(int count){
	while(count-->0){
		for(int i=0;i<NUMALL;i++){
			if(as_list[i].enable){
				move_astrophere_step(i);
			}
		}
	}
	return 0;
}

int balance_astrophere(double x, double y, int center_index, double *vx, double *vy){
	if(! as_list[center_index].enable){
		return -1;
	}
	double X2 = pow2(x - as_list[center_index].x);
	double Y2 = pow2(y - as_list[center_index].y);
	double R2 = X2+Y2;
	double V2  = G*as_list[center_index].m / sqrt(R2);
	double tmpVx = sqrt(V2*Y2/R2) * (as_list[center_index].y > y? 1: -1);
	double tmpVy = sqrt(V2*X2/R2) * (as_list[center_index].x > x? -1: 1);
	*vx = tmpVx;
	*vy = tmpVy;
	return 0;
}