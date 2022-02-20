#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}
int isSmaller(char* str1, char* str2){
	int n1 = strlen(str1),n2 = strlen(str2),i;
	if (n1 < n2)
		return 1;
		
	if (n2 < n1)
		return 0;
		
	for ( i = 0 ; i < n1 ; i++){
		if(str1[i] < str2[i])
			return 1;
		else if (str1[i] > str2[i])
			return 0;
    }
	return 0;
}
void findDiff(char* str1, char* str2,int sign){
	int n1 = strlen(str1), n2 = strlen(str2), sub;
	char *ans,*neww;
	neww=ans = (char*)malloc((n1+1) * sizeof(char));
	ans[n1] = '\0';
	strrev(str1);
	strrev(str2);
	int carry = 0, i;
	for( i = 0 ; i < n2 ; i++){
		 sub = ((str1[i]-'0')-(str2[i]-'0')-carry);
		 
		if( sub < 0 ) {
			sub = sub+10;
			carry = 1;
		}
		else
			carry = 0;
			
		ans[i] = sub + '0';
	}
	for( i ;i < n1 ;i++){
		 sub = ((str1[i] - '0') - carry);
		if (sub < 0) {
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;

	    ans[i] = sub + '0';
	}
	strrev(ans);
	i = 0;
	while( ans[i] == '0' && i < n1-1 ){
		i++;
	}
	ans = (ans + i);
	if(sign)
	printf("-");
	
	printf("%s",ans);
	free(neww);
}
void add_fix(char *numb1,char *numb2,int sign ){
    int len1 = strlen(numb1), len2 = strlen(numb2);
    
	int char1, char2, i , sum , carry , k , j , temp;
    
	i = len1-1;
	j = len2-1;
    k = 0;
	carry = 0;
	temp = max(len1,len2);
	char ans[temp+1];
	ans[temp] = '0';
    while( i > -1 && j > -1 ){
    	
        char1 = numb1[i]-'0'; 
        char2 = numb2[j]-'0'; 
        sum = char1 + char2 + carry;
        carry = 0;
        if(sum > 9){ 
            carry = 1;
            sum -= 10;
        }
        ans[k] = sum+'0';
        k++;
        i--;j--;
    }   
    while( j > -1 ){
        char1 = numb1[j] - '0';
    	sum = char1 + carry;
    	carry = 0;
    if( sum > 9 ){
    	   carry = 1;
    	   sum -= 10;
		}
    	ans[k] = sum + '0';
    	k++;
    	j--;
		}
	while( i > -1 ){
		char1 = numb1[i] -'0' ;
    	sum = char1 + carry;
    	carry = 0;
    if( sum > 9 ){
    		carry = 1;
    		sum -=10 ;
		}
    	ans[k] = sum + '0';
    	k++;
    	i--;
		}
    if( carry > 0 )
	ans[k]='1';
	 
	i = temp;
	while( i > 0 && ans[i] == '0')
	i--;
	
	if(sign==1){
		printf("-");
	}
	while( i > -1 ){
		printf("%c",ans[i]);
		i--;
	}	
}
void add(char *numb1,char *numb2,int sign) {
  int len1 = strlen(numb1);
  
  int len2 = strlen(numb2);
  
  if( len1 > len2 ){
  	add_fix( numb1 , numb2 ,sign);
  }else{
  	add_fix( numb2 , numb1 ,sign);
  }
}
void multiply(char* numb1, char* numb2,int sign){
	char s = '1';
	
	int len1 = strlen(numb1),i;
	
	int len2 = strlen(numb2);
	
	int ans[len1+len2];
	
	if ( len1 == 0 || len2 == 0 )
	s='0';
	else{
	for( i = 0; i < len1+len2; i++){
		ans[i] = 0;
	}
	int k = 0, carry,digit_1,digit_2,sum,j;
	int l = 0;
	for ( i = len1-1; i >= 0; i--){
		
		carry=0;
		digit_1= numb1[i]-'0';
		l = 0;			
		for ( j = len2-1; j >= 0; j--){
			
		digit_2 = numb2[j] - '0';
     	sum = digit_1 * digit_2 + ans[ k + l ] + carry;
       	carry = sum/10;
    	ans[ k + l ] = sum % 10;
		l++;
		}
       if (carry > 0)
			ans[ k + l ] += carry;
			
       k++;
	}
    i = len1+len2 - 1;
	while (i>=0 && ans[i] == 0)
	i--;
	if (i == -1){
	s= '0';
   }else{
   	if(sign==1){
   		printf("-");
	   }
	char text[10];
	while ( i >= 0 ){
		sprintf(text, "%d", ans[i--]);
		printf("%s",text);
	}
}
}
    if(s == '0')
	printf("0");
	 
}

void sub(char* numb1,char* numb2){
	int len1 = strlen(numb1), len2 = strlen(numb2);
	
	if(isSmaller(numb1, numb2))
		findDiff(numb2, numb1,1);
	else
		findDiff(numb1,numb2,0);
}

int main(){
	int sign1=0,sign2=0;
	char *numb1, *numb2, *no1, *no2;
	
	no1=numb1=(char *)malloc(310*sizeof(char));
	
	no2=numb2=(char *)malloc(310*sizeof(char));
	
	printf("Enter the numbers\nFirst: ");
	gets(numb1);
	
	printf("Second: ");
	gets(numb2);
	
	if(  numb1[0]=='-'){
		sign1=1;
		numb1=numb1+1;
	}
	
	if(numb2[0] == '-'){
		numb2=numb2+1;
	    sign2=1;	
	}
	
	printf("Press 0 for addition 1 for substraction and 2 for multiplication: \n");
	
	int n;
	scanf("%d",&n);
	
	if(n==0){
    printf("Addition of this two number:\n");
	if(sign1==sign2){
	add(numb1,numb2,sign1);
	}else{
		if(sign1==1){
			sub(numb2,numb1);
		}else{
			sub(numb1,numb2);
		}
	}
     printf("\n");
	
	}else if(n==1){
     printf("Substraction of this two number\n");
     if(sign1==1 &&sign2==1){
     	sub(numb2,numb1);
	 }else if(sign1==0 && sign2==0){
        sub(numb1,numb2);
	 }else if(sign1==0 && sign2==1){
	 	add(numb1,numb2,0);
	 }else{
	 	add(numb1,numb2,1);
	 }
    
	}else{
		if(sign1!=sign2){
			sign1=1;
		}else{
			sign1=0;
		} 
	 printf("Multliplication of this two number:\n");
	multiply(numb1,numb2,sign1);
    printf("\n");
	}
	
	free(no1);
	free(no2);
	return 0;
}
