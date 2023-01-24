#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define dt 0.000001

// Hamilonian of the system = p^2/2m +U
typedef struct
{
	double x;
	double y;
} velocity;
typedef struct
{
	double x;
	double y;
} position;
typedef struct
{
	double x;
	double y;
} force;
typedef struct
{
	position p;
	velocity v;
	force f;
} g_particle;

void
evolution(position *p, velocity *v, force *f)
{
#ifndef dt
	#define dt 0.1
#endif
	double x = p->x;
	double y = p->y;

	v->x += f->x*dt;
	v->y += f->y*dt;
	p->x += v->x*dt;
	p->y += v->y*dt;
	double mass = 1.2;
	f->x = -1*mass*(x)/pow(sqrt(x*x + y*y),3);
	f->y = -1*mass*(y)/pow(sqrt(x*x + y*y),3);

}

int
main()
{
	velocity a;
	a.x = 0;
	a.y = 0.5;
	position b;
	b.x = 1;
	b.y = 0;
	double x = 1;
	double y = 0;

	force f;
	f.x = -1.0*(x)/pow(sqrt(x*x + y*y),1);
	f.y = -1.0*(y)/pow(sqrt(x*x + y*y),1);
	f.x = 0;
	f.y = 0;


	for(long i=0; i<10000000;i++){
		if(i%1000 == 0) printf("%f\t%f\t%ld\n",b.x, b.y, i);
		evolution(&b,&a,&f);
	}

	return 0;
}

