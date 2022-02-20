#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}
void add_fix(char *numb1,char *numb2){
    int char1,char2;
    int i, len1=strlen(numb1),len2=strlen(numb2),sum,carry=0,k=0;
    i=len1-1;
	int j=len2-1;
	char ans[max(len1,len2)+1];
	ans[max(len1,len2)]='0';
    while(i>-1 && j>-1){
        char1=numb1[i]-'0'; 
        char2=numb2[j]-'0'; 
        sum=char1 + char2 + carry;
        carry=0;
        if(sum > 9){ 
            carry = 1;
            sum-=10;
        }
        ans[k] = sum+'0';
        k++;
        i--;j--;
    }   
    	while(j>-1){
    	char1=numb1[j]-'0';
    	sum=char1+carry;
    	carry=0;
    	if(sum>9){
    		carry=1;
    		sum-=10;
		}
    	ans[k]=sum+'0';
    	k++;
    	j--;
		}
		while(i>-1){
    	char1=numb1[i]-'0';
    	sum=char1+carry;
    	carry=0;
    	if(sum>9){
    		carry=1;
    		sum-=10;
		}
    	ans[k]=sum+'0';
    	k++;
    	i--;
		}
    if(carry>0)
	ans[k]='1';
	 
	i=max(len1,len2);
	while(i>0 && ans[i]=='0')
	i--;
	
	while(i>-1){
		printf("%c",ans[i]);
		i--;
	}	
}
void add(char *numb1,char *numb2) {
  int len1=strlen(numb1);
  int len2=strlen(numb2);
  if(len1>len2){
  	add_fix(numb1,numb2);
  }else{
  	add_fix(numb2,numb1);
  }
}
void multiply(char* numb1, char* numb2){
	char s='1';
	int len1=strlen(numb1);
	int len2=strlen(numb2);
	int ans[len1+len2];
	if (len1==0||len2==0)
	s='0';
	else{
	for(int i=0;i<len1+len2;i++){
		ans[i]=0;
	}
	int i_n1 = 0,carry,digit_1,digit_2,sum;
	int i_n2 = 0;
	for (int i=len1-1; i>=0; i--){
		carry=0;
		digit_1= numb1[i]-'0';
		i_n2 = 0;			
		for (int j=len2-1; j>=0; j--){
		digit_2 = numb2[j]-'0';
     	sum = digit_1*digit_2 + ans[i_n1 + i_n2] + carry;
       	carry = sum/10;
    	ans[i_n1 + i_n2] = sum % 10;
		i_n2++;
		}
       if (carry > 0)
			ans[i_n1 + i_n2] += carry;
			
       	i_n1++;
	}
    int i = len1+len2 - 1;
	while (i>=0 && ans[i] == 0)
	i--;
	if (i == -1){
	s= '0';
   }else{
	char text[10];
	while (i >= 0){
		sprintf(text, "%d", ans[i--]);
		printf("%s",text);
	}
}
}
    if(s=='0')
	printf("0");
	 
}
void add_complement(char* numb1,char* numb2){
	int len1=strlen(numb1),len2=strlen(numb2),n=max(len1,len2);
	char arr1[n+1],arr2[n+1];
	printf("%s",numb2);
	arr2[n]='\0';
	arr1[n]='\0';
	int j=0,i;
	if(len1>len2){
		i=len1-len2;
		while(i--){
			arr2[j]='9';
			j++;
		}
		i=len1-len2;
		for(j;j<n;j++){
			arr2[j]=numb2[j-i];
		}
		strcat(arr1,numb1);
	}else{
		i=len2-len1;
		while(i--){
			arr1[j]='0';
			j++;
		}
	strcat(arr2,numb2);
	}
	
	printf("%s\n%s\n",arr1,arr2);
	int char1,char2;
    int sum,carry=0,k=0;
	i=n-1;
	char ans[n];
    while(i>-1){
        char1=arr1[i]-'0'; 
        char2=arr2[i]-'0'; 
        printf("%c %c\n",arr1[i],arr2[i]);
        sum=char1 + char2 + carry;
        carry=0;
        if(sum > 9){ 
            carry = 1;
            sum-=10;
        }
        ans[k] = sum+'0';
        printf("%c \n",ans[k]);
        k++;
        i--;
  }
  printf("%s",ans);
    if(carry>0){
    	i=0;
    while(i<max(len1,len2) && carry!=0){
    	sum=ans[i]-'0'+1;
    	carry=0;
    	if(sum>9){
    		carry=1;
    		sum-=10;
		}
		ans[i]=sum+'0';
    	i++;
	}
	if(carry==1){
		printf("1");
	}
	}else{
 	for(int i=max(len1,len2)-1;i>-1;i--){
		ans[i]='9'-ans[i];
	}
	printf("-");
 }
    i=max(len1,len2)-1;
    while(i>-1){
    	printf("%c",ans[i]);
    	i--;
	}
	
}
void sub(char* numb1,char* numb2){
	int len1=strlen(numb1),len2=strlen(numb2);
	for(int i=0;i<len2;i++){
	      numb2[i]='9'-numb2[i]+'0';
	      printf("%c",numb2[i]);
	}
	printf("\n");
	add_complement(numb1,numb2);
	
}
int main(){
	
	char numb1[310],numb2[310];
	printf("Enter the numbers;\nFirst: ");
	gets(numb1);
	printf("Second: ");
	gets(numb2);
//	multiply(numb1,numb2);
//	add(numb1,numb2);
    sub(numb1,numb2);
	return 0;
}
