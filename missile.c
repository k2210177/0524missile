#include <stdio.h>
#include <math.h>
struct robo{
	double x,y,dx,dy;
	double v;
	double w,th;
};
main(){
	double dt,t,d;
	dt=0.01;
	t=dt;
	struct robo pl;
	pl.dx=0.0;
	pl.dy=0.0;
	pl.v=300.0;
	pl.w=M_PI/2.0;
	printf("%lf %lf ",pl.dx,pl.dy);
	struct robo mi;
	mi.dx=1000.0;
	mi.dy=0.0;
	mi.v=400.0;
	mi.w=M_PI/2.0;
	printf("%lf %lf\n",mi.dx,mi.dy);
	while(1){
		pl.th=pl.w*t;
		pl.x=pl.dx+pl.v*dt*cos(pl.th);
		pl.y=pl.dy+pl.v*dt*sin(pl.th);
		pl.dx=pl.x;
		pl.dy=pl.y;
		printf("%lf %lf ",pl.x,pl.y);
		mi.th=atan2((pl.y-mi.dy),(pl.x-mi.dx));
		mi.x=mi.dx+mi.v*dt*cos(mi.th);
		mi.y=mi.dy+mi.v*dt*sin(mi.th);
		mi.dx=mi.x;
		mi.dy=mi.y;
		printf("%lf %lf\n",mi.x,mi.y);
		d=sqrt((pl.x-mi.x)*(pl.x-mi.x)+(pl.y-mi.y)*(pl.y-mi.y));
		if(d<=1.0){
			break;
		}
		t=t+dt;
	}
}
