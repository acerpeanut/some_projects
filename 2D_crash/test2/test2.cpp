

#include "stdafx.h"

#include <math.h>

typedef struct pos{
int x,y;
}pos;
typedef int vect[2];
typedef pos line[2];
typedef pos quad[4];

#define pow2(x) ((x)*(x))
void pos_to_line(pos a,pos b,line c){
	c[0]=a;
	c[1]=b;
}
void line_to_vec(line a,vect b){
	b[0]=a[1].x-a[0].x;
	b[1]=a[1].y-a[0].y;
}
void pos_to_vec(pos a,pos b,vect c){
	c[0]=b.x-a.x;
	c[1]=b.y-a.y;
}
void vec_plus(vect a,vect b,vect c){
	c[0]=a[0]+b[0];
	c[1]=a[1]+b[1];
}
void vec_sub(vect a,vect b,vect c){
	c[0]=a[0]-b[0];
	c[1]=a[1]-b[1];
}
int vec_mo(vect a){
	return sqrtl(pow2(a[0])+pow2(a[1]));
}
int vec_ji1(vect a,vect b){                   // |a||b|cos
	return a[0]*b[0]+a[1]*b[1];
}
float vec_touying(vect a,vect b){          // |b|cos
	return (float)vec_ji1(a,b)/vec_mo(a);
}
float vec_cos(vect a,vect b){               // cos
	return (float)vec_ji1(a,b)/(vec_mo(a)*vec_mo(b));
}
int vec_ji2(vect a,vect b){                   // |a||b|sin
	return a[0]*b[1]-a[1]*b[0];
}
float vec_chuiliang(vect a,vect b){        // |b|sin
	return (float)vec_ji2(a,b)/vec_mo(a);
}
float vec_sin(vect a,vect b){                  // sin
	return (float)vec_ji2(a,b)/(vec_mo(a)*vec_mo(b));
}
float pos_dist(pos a,pos b){
	vect c;
	pos_to_vec(a,b,c);
	return vec_mo(c);
}
float pos_line_dist(pos a,line b){
	vect c,d;
	c[0]=a.x-b[0].x;
	c[1]=a.y-b[0].y;
	d[0]=b[1].x-b[0].x;
	d[1]=b[1].y-b[1].y;
	return abs(vec_chuiliang(c,d));
}
int pos_isIn_circle(pos a,pos b,float r){
	return pos_dist(a,b)<r;
}
int line_isIn_circle(line a,pos b,float r){
	vect c,d,e;
	if(pos_line_dist(b,a)<r){
		if(pos_isIn_circle(a[0],b,r)||pos_isIn_circle(a[1],b,r)){
			return 1;
		}
		else{
			pos_to_vec(a[0],b,c);
			pos_to_vec(a[1],b,d);
			line_to_vec(a,e);
			if(vec_ji2(c,e)*vec_ji2(d,e)<0){
				return 1;
			}
		}
	}
	return 0;
}
int pos_isIn_quad(quad a,pos b){
	vect c,d;
	float p;
	int i;
	pos_to_vec(a[0],a[1],c);
	pos_to_vec(a[0],b,d);
	p=vec_ji2(c,d);
	for(i=1;i<4;i++){
		pos_to_vec(a[i],a[(i+1)%4],c);
		pos_to_vec(a[i],b,d);
		if(p*vec_ji2(c,d) < 0)
			return 0;
	}
	return 1;
}
int quad_isIn_circle(quad a,pos b,float r){
	line l[4];
	vect c,d;
	float p;
	int i;
	for(i=0;i<4;i++){
		pos_to_line(a[i],a[(i+1)%4],l[i]);
		if(line_isIn_circle(l[i],b,r))
			return 1;
	}
	return pos_isIn_quad( a, b);
}
int main(){
	pos a={0,-5};
	pos b={0,5};
	vect c={a.x,a.y};
	vect d={b.x,b.y};
	line e={a,b};
	pos f={0,9};
	cout<<line_isIn_circle(e,a,4)<<endl;
	cin>>a.x;
	return 0;
}