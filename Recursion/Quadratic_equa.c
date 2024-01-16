#include <stdio.h>
#include <math.h>
int main()
{
  float a, b, c, r1, r2, img1, img2, d;

  int choice;
  printf("Enter the coefficients: ");
  scanf("%f%f%f\n", &a, &b, &c);
  if (a == 0.0)
  {
    if (b == 0.0)
      printf("\nEquation is degenrate \n");
    else
    {
      printf("\n Linear equation has single root\n");
      r1 = -c / b;
      printf("Root is %.2f\n", r1);
    }
  }
  else
  {
    d = b * b - 4 * a * c;
    if (d > 0)
      choice = 1;
    else
    {
      if (d == 0.0)
        choice = 2;
      else
        choice = 3;
    }

    switch (choice)
    {
    case 1:
      printf("Real and distinct roots are\n");
      r1 = (-b + sqrt(d)) / (2 * a);
      r2 = (-b - sqrt(d)) / (2 * a);
      printf("r1= %8.2f\n", r1);
      printf("r2= %8.2f", r2);
      break;
    case 2:
      printf("Real and equal roots are\n");
      r1 = r2 = -b / (2 * a);
      // r1=(-b-sqrt(d))/(2*a);
      printf("r1= %8.2f\n", r1);
      printf("r2=%8.2f", r2);
      break;
    case 3:
      printf("Imaginary roots are\n");
      r1 = r2 = -b / (2 * a);
      img1 = (sqrt(-d) / (2 * a));
      img2 = -img2;
      // r1=(-b-sqrt(d))/(2*a);
      printf("r1= %8.2f img1=%8.2f\n", r1, img1);
      printf("r2=%8.2f  img2=%8.2f\n", r2, img2);
      break;
    }
  }
  return 0;
}