#define Max 500

typedef struct 
{
    int exp;
    int coef;
}term;

static term poly_array[Max];
static int free;

struct polynomial_1
{
    int *p;
    int degree;

};


typedef struct polynomial_2
{
    int start,end;
};
