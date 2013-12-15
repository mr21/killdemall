#ifndef			MYMATH
# define		MYMATH

# include		<math.h>

# ifndef		M_PI
#  define		M_PI		3.14159265358979323846
# endif

# define		M_PI2		1.57079632679489661923

# define		POW2(X)		((X) * (X))
# define		DEGREES(X)	((X) * (180 / M_PI))
# define		RADIANS(X)	((X) * (M_PI / 180))

# define		MAX(A, B)	((A) > (B) ? (A) : (B))
# define		MIN(A, B)	((A) < (B) ? (A) : (B))

typedef struct {	int	x, y; }		v2i;
typedef struct {	double	x, y; }		v2f;
typedef struct {	double	a, b, c, d; }	m4f;

double			mycos(double rad);
double			mysin(double rad);

v2i*			v2i_(int x, int y);
v2f*			v2f_(double x, double y);
m4f*			m4f_(double a, double b, double c, double d);

void			v2f_multiply_f(v2f*, double);
void			v2f_multiply_m4f(v2f*, m4f const*);

double			pythagore(double a, double b);

#endif
