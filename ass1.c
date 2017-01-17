#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

int main()
{
FILE *f1, *f2;
char line[100], word[5], sl_no[7], atom_nm[10000][4], res_nm[10000][4], chain_id[10000][2], res_no[5], x_no[9], y_no[9], z_no[9]; 
int store_atm_no[10000], store_res_no[10000];
float x[10000], y[10000], z[10000];
int i, c1=0;

f1 = fopen("12as.pdb","r");
f2 = fopen("a.pdb","w");
while(fgets(line,100,f1)!=NULL)
{
	for(i=0; i<4;i++) word[i] = line[i];
	word[4]='\0';
	if(strcmp(word,"ATOM")==0)
	{       
		//serial
		for(i=0;i<6;i++)
		{
			sl_no[i] = line[i+5];	
		}
		sl_no[6] = '\0'; 
		store_atm_no[c1] = atoi(sl_no);
		printf("%d\t",store_atm_no[c1]);		
		
		// atom name
		for(i=0;i<3;i++)
		{
			atom_nm[c1][i] = line[i+13];
		}
		atom_nm[c1][3] = '\0';
		printf("%s\t",atom_nm[c1]);
		
		// residual number
		for(i=0;i<3;i++)
		{
			res_nm[c1][i] = line[i+17];
		}
		res_nm[c1][3] = '\0';
		printf("%s\t",res_nm[c1]);
		
		// chain id
		for(i=0;i<1;i++)
		{
			chain_id[c1][i] = line[i+21];
		}
		chain_id[c1][1] = '\0';
		printf("%s\t",chain_id[c1]);
		
		//res_nm
		for(i=0;i<4;i++)
		{
			res_no[i] = line[i+22];	
		}
		res_no[4] = '\0'; 
		store_res_no[c1] = atoi(res_no);
		printf("%d\t",store_res_no[c1]);

		//x 
		for(i=0;i<8;i++)
		{
			x_no[i] = line[i+30];	
		}
		x_no[8] = '\0'; 
		x[c1] = atof(x_no);
		printf("%f\t", x[c1]);

		//y
		for(i=0;i<8;i++)
		{
			y_no[i] = line[i+38];	
		}
		y_no[8] = '\0'; 
		y[c1] = atof(y_no);
		printf("%f\t",y[c1]);

		//z
		for(i=0;i<8;i++)
		{
			z_no[i] = line[i+46];	
		}
		z_no[8] = '\0'; 
		z[c1] = atof(z_no);
		printf("%f\n",z[c1]);

		c1++;
		
		
	}


}

for(i=0;i<c1;i++)
		{
			fprintf(f2,"ATOM  %5d %s %s %s%4d    %8.3f%8.3f%8.3f\n",store_atm_no[i],atom_nm[i],res_nm[i],chain_id[i],store_res_no[i],x[i],y[i],z[i]);
		}
fclose(f2);
fclose(f1);

}

