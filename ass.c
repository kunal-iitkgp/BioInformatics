#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

int main()
{
FILE *f1;
char line[100], word[5],res_nm[12000][4],atom_nm[12000][4]; 
float pc=0,nc=0,hp=0,neutral=0,total=0;
int i, c1=0;

f1 = fopen("1asy.pdb","r");
while(fgets(line,100,f1)!=NULL)
{
	for(i=0; i<4;i++) word[i] = line[i];
	word[4]='\0';
	if(strcmp(word,"ATOM")==0)
	{       
		// atom name
		for(i=0;i<3;i++)
		{
			atom_nm[c1][i] = line[i+13];
		}
		atom_nm[c1][3] = '\0';
		printf("%s\n",atom_nm[c1]);
		// resi
		for(i=0;i<3;i++)
		{
			res_nm[c1][i] = line[i+17];
		}
		res_nm[c1][3] = '\0';

		c1++;
		
		
	}


}

for(i=0;i<c1;i++)
		{
		if(strcmp(atom_nm[i],"CA ")==0)
		{
			
			printf("%f\n",total);
			if(strcmp(res_nm[i],"ARG")==0||strcmp(res_nm[i],"LYS")==0)
			{
				pc++;
			}
			
			if(strcmp(res_nm[i],"ASP")==0||strcmp(res_nm[i],"GLU")==0)
			{
				nc++;
			}

			if(strcmp(res_nm[i],"SER")==0||strcmp(res_nm[i],"THR")==0||strcmp(res_nm[i],"MET")==0||strcmp(res_nm[i],"HIS")==0||strcmp(res_nm[i],"GYS")==0||strcmp(res_nm[i],"ASN")==0||strcmp(res_nm[i],"GLN")==0||strcmp(res_nm[i],"TYR")==0)
			{
				neutral++;
			}
			
			if(strcmp(res_nm[i],"GLY")==0||strcmp(res_nm[i],"ALA")==0||strcmp(res_nm[i],"LLE")==0||strcmp(res_nm[i],"VAL")==0||strcmp(res_nm[i],"TRP")==0||strcmp(res_nm[i],"PHE")==0||strcmp(res_nm[i],"PRO")==0||strcmp(res_nm[i],"LEU")==0)
			{
				hp++;
			}
		total++;
		}
		}
fclose(f1);
//total = pc + nc + neutral + hp;
pc = pc/total;
nc = nc/total;
neutral = neutral/total;
hp = hp/total;
printf("total=%f positive=%f negative=%f neutral=%f hp=%f",total,pc, nc, neutral,hp);

}

