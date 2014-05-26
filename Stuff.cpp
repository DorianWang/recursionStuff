
int f1_I(int n)
{
   if (n<1){
      return 0; // :(   
   }
   return 17 + (n-1)*9;
}

int f1_R(int n)
{
   if (n < 1){
      return 0;
   }
   
   if (n==1){
      return 17;   
   }
    
   return f1_R(n-1) + 9;
}

int f2_I()
{
    
    
    
}

int f2_R(int n)
{

   if (n < 4){
      if (n == 1){
         return 0;
      }
      if (n == 2){
         return 5;   
      }
      if (n == 3){
         return 3;   
      }
      
      return -1;//Not a valid input number;
   }

   return (7*f2_R(n-1) - 4*f2_R(n-2) - 9*f2_R(n-3);

}

int f3_I()



int f3_R(int n, int* baseCase, int* coefficients)
{
   if (n < 5){
      if (n == 1){
         return baseCase[0];
      }
      if (n == 2){
         return baseCase[1];   
      }
      if (n == 3){
         return baseCase[2];   
      }
      if (n ==4){
         return baseCase[3];   
      }
      return -1;//:(
   }
   
   return coefficients[0]*f3_R(n-1) - coefficients[1]*f3_R(n-2) + coefficients[2]*f3_R(n-3) - coefficients[3]*f3_R(n-4);
}















