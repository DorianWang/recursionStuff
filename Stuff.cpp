
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

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

int f2_I(int n)
{
   int before1 = 3;
   int before2 = 5;
   int before3 = 0;
   int tempOutput = 0;
   if (n<4){
      if (n==1){
         return before3;   
      }
      else if (n == 2){
         return before2;     
      }
      else if (n == 1){
         return before1;     
      }
      else{  
         return -1;
      }   
   }
   
   for (int i=4; i<=n; i++){
      tempOutput = 7*before1 - 4*before2 - 9*before3;
      before3 = before2; before2 = before1; before1 = tempOutput;
   }
    
   return tempOutput;
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

   return (7*f2_R(n-1) - 4*f2_R(n-2) - 9*f2_R(n-3));

}

//Note, baseCase array must be listed from front to back. (z, y, x, w)
int f3_I(int n, int baseCase[4], int coefficients[5])
{
   int tempOutput = 0;
   int b1 = baseCase[0];
   int b2 = baseCase[1];
   int b3 = baseCase[2];
   int b4 = baseCase[3];
   int constant = coefficients[4];
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
   
   for (int i=5; i<=n; i++){
      tempOutput = coefficients[0]*b1 - coefficients[1]*b2 + coefficients[2]*b3 - coefficients[3]*b4;
      b4 = b3; b3 = b2; b2 = b1; b1 = tempOutput;
   }

}

int f3_R(int n, int baseCase[], int coefficients[])
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
   
   return coefficients[0]*f3_R(n-1, baseCase, coefficients) - coefficients[1]*f3_R(n-2, baseCase, coefficients) + coefficients[2]*f3_R(n-3, baseCase, coefficients) - coefficients[3]*f3_R(n-4, baseCase, coefficients);
}

int f4_I(int n, int m)
{
   if (m>n){
      return -1;//:(   
   }    
   
   return (7*(n-m+1)*(n+m))/2;
}

int f4_R(int n, int m)
{
   if (n<m){
      return 0;   
   }

return 7*m + f4_R(n, m+1);    
}


int f5_I(int A[], int a, int b, int m)
{
int count = 0;
   for (int i = a; i<=b; i++){
      if (A[i]%m == 0){
         count++;   
      }    
   }
   return count;
}

int f5_R(int A[], int a, int b, int m)
{
    
   for (int i = a; i<=b; i++){
      if (A[i]%m == 0){
         return 1 + f5_R(A, a+1, b, m);
      }    
   }

return 0;
}
    
    
int f6_I(int A[], int m)
{
   int count = 0;
   int i=0;
   while (A[i]>=0){
      if (A[i]%m ==0){
         count = count + A[i];   
      }      
   }
   return count;
}
    
int f6_R(int A[], int m)
{
   int i = 0;
   while(A[i]>=0){
      if (A[i]%m == 0){
         return A[i] + f6_R(&A[i], m);   
      }    
   } 
   return 0;
}
    
int f7_I(char str[])
{
//Temporary constants, will be changed later
int letterVal = 10;
int numVal = 5;
int spaceVal = 20;
int additionVal = 0;
int otherVal = 1;
   
int stringLength = strlen(str);
if (stringLength == 0){
   return 0;   
}

int returnValue = 0;
   
   for (int i=0; i<stringLength - 1; i++){
      if (str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z'){
         returnValue += letterVal;
         continue;
      }
      
      if (str[i]>='0'&&str[i]<='9'){
         returnValue += numVal;
         continue;
      }
      
      if (str[i]>=' '){
         returnValue += spaceVal;
         continue;
      }
      
      if (str[i]>='+'){
         returnValue += additionVal;
         continue;
      }
      returnValue++;
   }
   
   return returnValue;
}
    
int f7_R(char str[])
{
//Temporary constants, will be changed later
int letterVal = 10;
int numVal = 5;
int spaceVal = 20;
int additionVal = 0;
int otherVal = 1;

int returnValue = 0;

int stringLength = strlen(str);
if (stringLength == 0||str[0]==0){
   return 0;   
}

   if (str[0]>='a'&&str[0]<='z'||str[0]>='A'&&str[0]<='Z'){
      returnValue = letterVal;
   }
   
   if (str[0]>='0'&&str[0]<='9'){
      returnValue = numVal;
   }
   
   if (str[0]>=' '){
      returnValue = spaceVal;
   }
   
   if (str[0]>='+'){
      returnValue = additionVal;
   }
   returnValue++;
   return (returnValue + f7_R(str+1));
}

    
int f8_I(char str[])
{
   
int stringLength = strlen(str);
int mid = min(stringLength/2+1, stringLength);

   for (int i=0; i<mid; i++){
      if (str[i]!=str[stringLength-i-1]){
         return 0;   
      }    
   }
   return 1;
}
   
   
int f8_R(char str[], int stringLength)
{
   if (stringLength<2){
      return 1;
   }
   
   if (str[0]==(str[stringLength]-1)){
      return f8_R(str+1, stringLength - 2);   
   }
return 0;
}
   
int f9_I(char c, char str[])
{
   int count = 0; int stringLength = strlen(str);
   
   
   for (int i=0; i< stringLength - 1; i++){
      if (str[i]==c){
         count++;   
      }    
   }
   return count;
}
   
int f9_R(char c, char str[])
{
   if (str[0]==0){
      return 0;   
   }
   
   if (str[0]==c){
      return 1 + f9_R(c, str+1);
   }
   return f9_R(c, str+1);
}
   
int f10_I(char c, char str[])
{
   int i=0; int stringLength = strlen(str);
   
   if (str[0]==0){
      return 0;   
   }
   
   while (str[i]!=c&&str[i]!=0){
      i++;
   }
   
   if (str[i]==0){
      return 0;   
   }
   
   for (int j = i; j<stringLength; j++){
      str[j] = str[j+1];    
   }
   return 1;
}
   
int f10_R(char c, char str[])
{
   if (str[0]==0){
      return 0;   
   }
   
   if (str[0]==c){
      int stringLength = strlen(str);
      for (int j = 0; j<stringLength; j++){
         str[j] = str[j+1];    
      }
      return 1;
   }
   f10_R(c, str+1);
}
   
int f11_I(char c, char str[])
{
   int i=0; int stringLength = strlen(str);
   
   if (str[0]==0){
      return 0;   
   }
   
   while (str[i]!=0){
      if (str[i]==c){
         for (int j = i; j<stringLength; j++){
            str[j] = str[j+1];    
         }
      }
      if (str[i]==0){
         break;   
      }
      i++;
   }

return 1;
}
   
int f11_R(char c, char str[])
{
   if (str[0]==0){
      return 1;   
   }
   
   if (str[0]==c){
      int stringLength = strlen(str);
      for (int j = 0; j<stringLength; j++){
         str[j] = str[j+1];    
      }
      if (str[0]!=0){
         return f10_R(c, str+1);;
      }
      return 1;
   }

}

//The size of the array must be more than the arrayLength, or else there will be undefined behavior
//in the calling routine.
int f12_I(int n, int A[], int arrayLength)
{
   int i=0;
   while(n>=A[i]){i++;}


   
   for (int j=arrayLength; j>i; j++){
      A[j] = A[j-1];
   }
   A[i] = n;

return 1;
}
   
int f12_R(int n, int A[], int arrayLength)
{
   if (arrayLength == 0){return 1;}
   if (A[arrayLength]!=n){
      A[arrayLength] = n;
      return f12_R(n, A, arrayLength);
   }
   
   int temp;
   if (A[arrayLength-1]>n){
      temp = A[arrayLength-1]; A[arrayLength-1] = n, A[arrayLength] = temp;
      f12_R(n, A, arrayLength - 1);
   }

   return 1;
}   
   
   
//1+1/2 (-1+x)-1/8 (-1+x)^2+1/16 (-1+x)^3-5/128 (-1+x)^4+7/256 (-1+x)^5
//Wolfram alpha, taylor series
double f13_I(double input)
{
double x = input;

double smallValue = x - x/2;

double output = smallValue + 1/2 * (smallValue) - 1/8 * (smallValue)*(smallValue) + 1/16 * (smallValue)*(smallValue)*(smallValue)
- 5/256 * (smallValue)*(smallValue)*(smallValue)*(smallValue) + 7/256 * (smallValue)*(smallValue)*(smallValue)*(smallValue)*(smallValue);
//More magic may be added if required...
       
int test = (int)(output + 0.5000);


return output;
}
   
double f13_R()
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   

   
   


