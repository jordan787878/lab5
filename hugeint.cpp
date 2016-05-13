#include "hugeint.h"
#include <cstring>

HugeInt::HugeInt() {
 for(int i=0; i<300 ;i++)
 { hugenumber[i] = 0; }
 sitnumber = 0;
   
}

HugeInt::HugeInt(int num) {
 sitnumber = 1; 
 int temp = num;
 int temp_2 = 0;

 for(int i=0;i<300;i++)
 { 
   hugenumber[i] = 0;
   temp =(int)temp/10;
   if(temp >=1 ) { sitnumber++; }         
 } 
  
 temp = num;

 for(int i=0;i<sitnumber;i++)
 {
   temp_2 = temp%10;
   hugenumber[i] = temp_2; 
   temp = (int)temp/10;   
 } 

}

HugeInt::HugeInt(string word) {

 for(int i=0;i<300;i++)
 { hugenumber[i] = 0; }

 sitnumber = word.size();
 char temp[sitnumber];
 strcpy(temp,word.c_str());
 
 for(int i=0;i<sitnumber;i++)
 {
   hugenumber[sitnumber-i-1] = temp[i]-'0';
 }
  
}

void HugeInt::operator=(const HugeInt & right) {
 sitnumber = right.sitnumber;
 for(int i =0;i<sitnumber;i++)
 { hugenumber[i] = right.hugenumber[i]; }

}


HugeInt HugeInt::operator+(const HugeInt & right) {

int tempsit = 0;
if(sitnumber >= right.sitnumber )
{ tempsit = sitnumber; }
else
{ tempsit = right.sitnumber; }

HugeInt add;
add.sitnumber = tempsit+1;

 for(int i=0;i<tempsit+1;i++)
 {
   add.hugenumber[i]=hugenumber[i]+right.hugenumber[i];
 }
 
 for(int i=0;i<tempsit+1;i++)
 {  
   if(add.hugenumber[i] >= 10)
   { add.hugenumber[i] = add.hugenumber[i]-10;
     add.hugenumber[i+1] = add.hugenumber[i+1] + 1;
   }
 }
 

 return add;
 
}

HugeInt HugeInt::operator- (const HugeInt & right) {

int tempsit = 0;
 if( sitnumber >= right.sitnumber)
 { tempsit = sitnumber; }
 else
 { tempsit = right.sitnumber; }

HugeInt minus;
minus.sitnumber = tempsit;

for(int i=0;i<tempsit;i++)
{
  minus.hugenumber[i]=hugenumber[i]-right.hugenumber[i];
}

for(int i=0;i<tempsit;i++)
{
  if(minus.hugenumber[i] < 0 )
  { minus.hugenumber[i] = minus.hugenumber[i] + 10;
    minus.hugenumber[i+1] = minus.hugenumber[i+1]-1;
  }
}

return minus;

}


ostream & operator<< (ostream & out ,const HugeInt & hugenum) {
 
 int realsit = hugenum.sitnumber;
 for(int i=0;i<hugenum.sitnumber;i++)
 {
   if(hugenum.hugenumber[hugenum.sitnumber-i-1] != 0 )
   {

     for(int i =0; i< realsit; i++)
     { 
      out << hugenum.hugenumber[realsit-i-1]; 
     }
     return out;
   }
  
   realsit--;
 }

}
void operator >> (istream & in,HugeInt & hugenum) {

string temp;
in >> temp;
hugenum.sitnumber = temp.size();
char store[hugenum.sitnumber];
strcpy(store,temp.c_str());
for(int i=0;i<hugenum.sitnumber;i++)
{
  hugenum.hugenumber[hugenum.sitnumber-i-1] = store[i]-'0';
}
    
}

