#include<stdio.h>

typedef struct
{
    int real;
    int img;
} complex;

void read_complex(complex *c);
void display_complex(complex c);
complex add_complex(complex c1, complex c2);        //function for adding two complex number
complex sub_complex(complex c1, complex c2);        //function for substracting two complex number

int main()
{
    complex c1, c2, sum, sub;

    read_complex(&c1);      //passed as pointer
    read_complex(&c2);
    display_complex(c1);        //entire structure passed
    display_complex(c2);
    sum = add_complex(c1, c2);
    printf("After Addition: ");
    display_complex(sum);
    sub = sub_complex(c1, c2);
    printf("After Substraction: ");
    display_complex(sub);

    return 0;
}

void read_complex(complex *c)
{
    printf("Enter Real Value: ");
    scanf("%d",&(*c).real);
    printf("Enter Imaginary Value: ");
    scanf("%d",&c->img);        //(*c).real is equivalent to c->real
}

void display_complex(complex c)
{
    printf("Comlex Number is: %d + i%d\n", c.real, c.img);
}

complex add_complex(complex c1, complex c2)
{
    complex c;
    c.real = c1.real + c2.real;
    c.img = c1.img + c2.img;
    return c;
}

complex sub_complex(complex c1, complex c2)
{
    complex c;
    c.real = c1.real - c2.real;
    c.img = c1.real - c2.real;
    return c;
}