#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int wro=0,rig=0,flag=0;
int main()
{
	void fraction();
	int max(int a,int b);  //���Լ����������
	int min(int a,int b);  //��С��������������
    int sum,language,i,swit,num[4],j;
	srand((unsigned int)time(NULL)); //������������� 
	printf("��ӭʹ������������ϰ����\n");
	printf("Welcome to the program of operation practice!\n");
	printf("******************************************************************************\n\n");
	printf("��ѡ������ʹ�õ�����/Please choose the language your use:\n1.����/Chinese     2.Ӣ��/English\n");
	scanf("%d",&language);  //�����л�
	if(language==1)
		printf("������������Ҫ����Ŀ����");
	else
		printf("Please input the number you need:");
	scanf("%d",&sum);
	for(i=1;i<=sum;)
	{
		for(j=1;j<=4;j++)
		{
			num[j]=rand()%10+1;
		}
		swit=1;
		switch(swit)
		{
		   case 1:fraction();break;   //�������������ʽ��
		}
		if(flag==0)
			i++;
		flag=0;   //��flag����Ƿ��������Ŀ
	}
	if(language==1)
	{
		printf("������ȷ����Ϊ��%4d\n",rig);
		printf("���Ĵ�������Ϊ��%4d\n",wro);
		printf("��ӭ�ٴ�ʹ�ã�\n");
	}
	else
	{
		printf("The number of questions you did right is:%4d\n",rig);
		printf("The number of questions you did wrong is:%4d\n",wro);
		printf("Welcome to use again!\n");
	}
	return 0;
}



//��������������� 
void fraction()  
{
	srand((unsigned int)time(NULL)); //������������� 
	int max(int a,int b);  //���Լ����������
	int min(int a,int b);  //��С��������������
	int mu1,zi1,mu2,zi2,com,sign,mu3,zi3,yue,input1,input2;
	for(;;)
	{
		mu1=rand()%10+1;		
		zi1=rand()%10+1;		
		if(mu1<=zi1)
		    continue;
		else
		{
			com=max(mu1,zi1);
			mu1=mu1/com;
			zi1=zi1/com;
		    break;
		}
    }                        //�ó���һ����������
	for(;;)
	{
		mu2=rand()%10+1;		
		zi2=rand()%10+1;		
		if(mu2<=zi2)
		    continue;
		else
		{
			com=max(mu2,zi2);
			mu2=mu2/com;
			zi2=zi2/com;
		    break;
		}
    }                       //�ó��ڶ�����������
	sign=rand()%4+1;        //�������
	if(sign==1)                                         //�ӷ�
	{	
		printf("%d/%d+%d/%d=",zi1,mu1,zi2,mu2);
		yue=min(mu1,mu2);
		zi1=zi1*(yue/mu1);
		zi2=zi2*(yue/mu2);
		mu3=yue;
		zi3=zi1+zi2;
		com=max(mu3,zi3);
		mu3=mu3/com;
		zi3=zi3/com;          //Լ�ּ���
		if(zi3%mu3==0)
		{
			scanf("%d",&input1);
			if(input1==(zi3/mu3))
				rig++;
			else
				wro++;
		}
		else
		{
			scanf("%d/%d",&input1,&input2);
			if(input1==zi3&&input2==mu3)
				rig++;
			else
				wro++;
		}
		printf("%d/%d\n",zi3,mu3);
	}
	if(sign==2)                                   //����
	{	

		yue=min(mu1,mu2);
		zi1=zi1*(yue/mu1);
		zi2=zi2*(yue/mu2);
		mu3=yue;
		zi3=zi1-zi2;
		if(zi3<=0)        //������ָ����⣬���ǵ���ͬ�����������ûʲô̫�����壬һ��ɾȥ��
			flag=1;
		else
		{
			com=max(mu3,zi3);
			mu3=mu3/com;
			zi3=zi3/com;
			printf("%d/%d-%d/%d=",zi1/(yue/mu1),mu1,zi2/(yue/mu2),mu2);
			if(zi3%mu3==0)
			{
			scanf("%d",&input1);
			if(input1==(zi3/mu3))
				rig++;
			else
				wro++;
			}
		   else
		   {
			scanf("%d/%d",&input1,&input2);
			if(input1==zi3&&input2==mu3)
				rig++;
			else
				wro++;
		   }
			printf("%d/%d\n",zi3,mu3);
		}
	}
	if(sign==3)                                //�˷�
	{
		printf("(%d/%d)*(%d/%d)=",zi1,mu1,zi2,mu2);
		mu3=mu1*mu2;
		zi3=zi1*zi2;
		com=max(mu3,zi3);
		mu3=mu3/com;
		zi3=zi3/com;
		if(zi3%mu3==0)
		{
			scanf("%d",&input1);
			if(input1==(zi3/mu3))
				rig++;
			else
				wro++;
		}
		else
		{
			scanf("%d/%d",&input1,&input2);
		if(input1==zi3&&input2==mu3)
				rig++;
		else
				wro++;
		}
		printf("%d/%d\n",zi3,mu3);
	}
	if(sign==4)                             //����
	{
		printf("(%d/%d)/(%d/%d)=",zi1,mu1,zi2,mu2);
		mu3=mu1*zi2;
		zi3=zi1*mu2;
		com=max(mu3,zi3);
		mu3=mu3/com;
		zi3=zi3/com;
		if(zi3%mu3==0)
		{
			scanf("%d",&input1);
			if(input1==(zi3/mu3))
				rig++;
			else
				wro++;
		}
		else
		{
			scanf("%d/%d",&input1,&input2);
		if(input1==zi3&&input2==mu3)
				rig++;
		else
				wro++;
		}
		printf("%d/%d\n",zi3,mu3);
	}
}

int max(int a,int b)   //�����Լ������
{
	int i,temp;
	if(a<b)
	{
		temp=a;
		a=b;
		b=temp;
	}
	for(i=b;i>=1;i--)
	{
		if(a%b==0)
		{
			return(b);
			break;
		}
		if(a%i==0&&b%i==0)
		{
			return(i);
			break;
		}
	}
}


int min(int a,int b)   //����С����������
{
	int i,temp;
	if(a<b)
	{
		temp=a;
		a=b;
		b=temp;
	}
	for(i=a;;i++)
	{
		if(a%b==0)
		{
			return(a);
			break;
		}
		if(i%a==0&&i%b==0)
		{
			return(i);
			break;
		}
	}
}
