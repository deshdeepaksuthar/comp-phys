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

void
evol2(position *p1, position *p2, velocity *v1, velocity *v2, force *f1, force *f2)
{
	double x1 = p1->x;
	double y1 = p1->y;
	double x2 = p2->x;
	double y2 = p2->y;

	v1->x += f1->x*dt;
	v1->y += f1->y*dt;
	p1->x += v1->x*dt;
	p1->y += v1->y*dt;

	v2->x += f2->x*dt;
	v2->y += f2->y*dt;
	p2->x += v2->x*dt;
	p2->y += v2->y*dt;

	double mass1 = 1.2;
	double mass2 = 1.2;

	double x = p1->x - p2->x;
	double y = p1->y - p2->y;

	f1->x = -1*mass1*mass2*(x)/pow(sqrt(x*x + y*y),3);
	f1->y = -1*mass1*mass2*(y)/pow(sqrt(x*x + y*y),3);

	/* Newton's law */
	f2->x = -1*f1->x;
	f2->y = -1*f1->y;
}

int
main()
{
	position p1;
	velocity v1;
	force f1;

	p1.x = 1;
	p1.y = 0;
	v1.x = 0;
	v1.y = 1;

	position p2;
	velocity v2;
	force f2;

	p2.x = 0;
	p2.y = 0.5;
	v2.x = 0.0;
	v2.y = -1;



	for(long i=0; i<100000000;i++){
		if(i%1000 == 0) printf("%ld\t%lf\t%lf\t%lf\t%lf\n", i, p1.x, p1.y, p2.x, p2.y);
		evol2(&p1,&p2,&v1,&v2,&f1,&f2);
	}

	return 0;
}

