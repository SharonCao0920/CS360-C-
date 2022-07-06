#include"Complex.h"

int main()
{
   Complex x;
   Complex y;
   Complex z;

   cout << "Enter first complex number: (real iamginary) ";
   cin >> y;

   cout << "\nEnter second complex number: (real iamginary) ";
   cin >> z;

   x = y + z;
   cout << "\n\nx = y + z:\n" << x << " = " << y << " + " << z;

   x = y - z;
   cout << "\n\nx = y - z:\n" << x << " = " << y << " - " << z;

   x = y * z;
   cout << "\n\nx = y * z:\n" << x << " = " << y << " * " << z;

   x = y / z;
   cout << "\n\nx = y / z:\n" << x << " = " << y << " / " << z << endl << endl;;

   if (y == z)
   {
       cout << y << " and " << z << " same.";
   }

   if (y != z)
   {
       cout << y << " and " << z << " not same.";
   }
   system("pause");
   return 1;
}