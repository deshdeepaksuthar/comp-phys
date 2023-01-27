#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define dt 0.001

// Hamilonian of the system = p^2/2m +U
typedef struct
{
	double x;
	double y;
	double z;
} velocity;
typedef struct
{
	double x;
	double y;
	double z;
} position;
typedef struct
{
	double x;
	double y;
	double z;
} force;
typedef struct
{
	position p;
	velocity v;
	force f;
} g_particle;

void
evol3d(
		position *p1, position *p2, position *p3,
		velocity *v1, velocity *v2, velocity *v3,
		force *f1, force *f2, force *f3)
{
	double x1 = p1->x;
	double y1 = p1->y;
	double z1 = p1->z;

	double x2 = p2->x;
	double y2 = p2->y;
	double z2 = p2->z;

	double x3 = p3->x;
	double y3 = p3->y;
	double z3 = p3->z;


	double mass1 = 1;
	double mass2 = 1;
	double mass3 = 1;

	double x;
	double y;
	double z;
	double mass;

	f1->x = 0;
	f1->y = 0;
	f1->z = 0;

	f2->x = 0;
	f2->y = 0;
	f2->z = 0;

	f3->x = 0;
	f3->y = 0;
	f3->z = 0;

/* Force on particle one */
	/* due to two */
	x = x1 - x2;
	y = y1 - y2;
	z = z1 - z2;
	mass = mass1;

	f1->x += -1*mass*mass2*(x)/pow((x*x + y*y + z*z),1.5);
	f1->y += -1*mass*mass2*(y)/pow((x*x + y*y + z*z),1.5);
	f1->z += -1*mass*mass2*(z)/pow((x*x + y*y + z*z),1.5);

	/* due to three */
	x = p1->x - p3->x;
	y = p1->y - p3->y;
	z = p1->z - p3->z;

	f1->x += -1*mass*mass3*(x)/pow((x*x + y*y + z*z),1.5);
	f1->y += -1*mass*mass3*(y)/pow((x*x + y*y + z*z),1.5);
	f1->z += -1*mass*mass3*(z)/pow((x*x + y*y + z*z),1.5);

/* Force on particle two */
	/* due to one */
	x = p2->x - p1->x;
	y = p2->y - p1->y;
	z = p2->z - p1->z;
	mass = mass2;

	f2->x += -1*mass*mass1*(x)/pow((x*x + y*y + z*z),1.5);
	f2->y += -1*mass*mass1*(y)/pow((x*x + y*y + z+z),1.5);
	f2->z += -1*mass*mass1*(z)/pow((x*x + y*y + z+z),1.5);

	/* due to three */
	x = p2->x - p3->x;
	y = p2->y - p3->y;
	z = p2->z - p3->z;

	f2->x += -1*mass*mass3*(x)/pow((x*x + y*y + z*z),1.5);
	f2->y += -1*mass*mass3*(y)/pow((x*x + y*y + z*z),1.5);
	f2->z += -1*mass*mass3*(z)/pow((x*x + y*y + z*z),1.5);

/* Force on particle three */
	/* due to one */
	x = p3->x - p1->x;
	y = p3->y - p1->y;
	z = p3->z - p1->z;
	mass = mass3;

	f3->x += -1*mass*mass1*(x)/pow((x*x + y*y + z*z),1.5);
	f3->y += -1*mass*mass1*(y)/pow((x*x + y*y + z*z),1.5);
	f3->z += -1*mass*mass1*(z)/pow((x*x + y*y + z*z),1.5);

	/* due to two */
	x = p3->x - p2->x;
	y = p3->y - p2->y;
	z = p3->z - p2->z;

	f3->x += -1*mass*mass2*(x)/pow((x*x + y*y + z*z),1.5);
	f3->y += -1*mass*mass2*(y)/pow((x*x + y*y + z*z),1.5);
	f3->z += -1*mass*mass2*(z)/pow((x*x + y*y + z*z),1.5);

/* ALL FORCE CALCULATIONS DONE */
/* Finding new velocities and positions */

	v1->x += f1->x*dt;
	v1->y += f1->y*dt;
	v1->z += f1->z*dt;
	p1->x += v1->x*dt;
	p1->y += v1->y*dt;
	p1->z += v1->z*dt;

	v2->x += f2->x*dt;
	v2->y += f2->y*dt;
	v2->z += f2->z*dt;
	p2->x += v2->x*dt;
	p2->y += v2->y*dt;
	p2->z += v2->z*dt;

	v3->x += f3->x*dt;
	v3->y += f3->y*dt;
	v3->z += f3->z*dt;
	p3->x += v3->x*dt;
	p3->y += v3->y*dt;
	p3->z += v3->z*dt;
}


int
main()
{
	position p1;
	velocity v1;
	force f1;

	p1.x = 0;
	p1.y = 2;
	p1.z = 0;
	v1.x = 0;
	v1.y = 0;
	v1.z = 0;

	position p2;
	velocity v2;
	force f2;

	p2.x = 0;
	p2.y = 0;
	p2.z = 0;
	v2.x = 0;
	v2.y = 0;
	v2.z = 0;

	position p3;
	velocity v3;
	force f3;

	p3.x = 2;
	p3.y = 0;
	p3.z = 0;
	v3.x = 0;
	v3.y = 0;
	v3.z = 0;


	for(long i=0; i<3;i++){
		if(i%1 == 0) printf("%ld\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", i,
				p1.x, p1.y, p1.z,
				p2.x, p2.y, p2.z,
				p3.x, p3.y, p3.z);
		if(i%1 == 0) printf("%ld\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", i,
				v1.x, v1.y, v1.z,
				v2.x, v2.y, v2.z,
				v3.x, v3.y, v3.z);
		if(i%1 == 0) printf("%ld\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n", i,
				f1.x, f1.y, f1.z,
				f2.x, f2.y, f2.z,
				f3.x, f3.y, f3.z);
		evol3d(&p1,&p2, &p3,&v1,&v2, &v3,&f1,&f2, &f3);
	}

	return 0;
}

