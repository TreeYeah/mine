#include <bits/stdc++.h>//C++���ܿ� 
#include <windows.h> 
#include <conio.h>//����̨������� 
using namespace std;

#define getrand(a,b) (rand()%b+a)//��ȡ����� 
#define akey (key=='z'||key=='Z')
#define bkey (key=='x'||key=='X')
#define dakaifangshi 2 //�򿪷�ʽ  1Ϊ������� 2Ϊ������� 

int chang=9,kuan=9,lei=10;
int space=0;
int flag[302][302];
int boom[302][302];
int flaged=0;

void go(int x,int y) //����ƶ�������x��ʾ�����꣬y��ʾ�����ꡣ
{
    COORD coord;         //ʹ��ͷ�ļ��Դ�������ṹ
    coord.X=x*2+2;            //���ｫint����ֵ����short,�����������漰������ֵ�����ᳬ��short��Χ
    coord.Y=y+1;
    HANDLE a=GetStdHandle(STD_OUTPUT_HANDLE);  //��ñ�׼������
    SetConsoleCursorPosition(a,coord);         //�Ա�׼����ľ��Ϊ�������ÿ���̨�������
}
void color(int a)//�趨��ɫ�ĺ��� 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
}//�� ���� ���� ǳ��  ��  ����  ���� ǳ�� ��� ���� ����  ����� �Һ� ǳ��  �׻�  ��
bool out(int x,int y)
{
	if(x>kuan||y>chang||x<1||y<1) return 1;
	return 0;
}
void mxy(int x,int y)
{
	go(x,y);
	if(flag[x][y]==1)
	{
		color(65);//+1
		printf("��");
	}
	if(flag[x][y]==0)
	{
		color(73);//+9
		printf("��");
	}
	if(flag[x][y]==-1)
	{
		color(64);
		if(boom[x][y]==0) printf("  ");
		else if(boom[x][y]>0) cout<<" "<<boom[x][y];
		else color(247),cout<<"��";		
	}
}
void pxy(int x,int y)
{
	go(x,y);
	if(flag[x][y]==1)
	{
		color(49);
		printf("��");
	}
	if(flag[x][y]==0)
	{
		color(249);
		printf("��");
	}
	if(flag[x][y]==-1)
	{
		color(240);
		if(boom[x][y]==0) printf("  ");
		else if(boom[x][y]>0) cout<<" "<<boom[x][y];
		else color(247),cout<<"��";		
	}
}
int find0(int x,int y) 
{
	if(dakaifangshi==1)
	{
		if(out(x,y)||flag[x][y]!=0) return 0;
		flag[x][y]=-1;
		pxy(x,y);
		if(boom[x][y]==0)
		{
			if(chang*kuan<=100) Sleep(20);
			else if(chang*kuan<=200) Sleep(16);
			else if(chang*kuan<=250) Sleep(15);
			else if(chang*kuan<=300) Sleep(12);
			else if(chang*kuan<=400) Sleep(10);
			else if(chang*kuan<=500) Sleep(7);
			else if(chang*kuan<=600) Sleep(5);
			else Sleep(2);
			return (1+find0(x+1,y)+find0(x-1,y)+find0(x,y+1)+find0(x,y-1)+find0(x+1,y+1)+find0(x+1,y-1)+find0(x-1,y+1)+find0(x-1,y-1));
		}
		return 1;
	} 
	else
	{
		if(out(x,y)||flag[x][y]==-1)
			return 0;
		
		flag[x][y]=-1;
		mxy(x,y);
		
		int fx[8][2]=
		{	
			{ 1, 0},
			{-1, 0},
			{ 0, 1},
			{ 0,-1},
			
			{ 1, 1},
			{ 1,-1},
			{-1, 1},
			{-1,-1},
		};
		int head=0,tail=1;
		int open=1;
		int sv[1024][2];
		sv[1][0]=x;
		sv[1][1]=y;
		
		do
		{
			head++;
			for(int i=0;i<8;i++)
			{
				int xx=sv[head][0]+fx[i][0];
				int yy=sv[head][1]+fx[i][1];
				if(!out(xx,yy)&&flag[xx][yy]==0&&boom[sv[head][0]][sv[head][1]]==0)
				{
					tail++;
					sv[tail][0]=sv[head][0]+fx[i][0];
					sv[tail][1]=sv[head][1]+fx[i][1];
					flag[sv[tail][0]][sv[tail][1]]=-1;
					pxy(sv[tail][0],sv[tail][1]);
					open++;	
					
					if(chang*kuan<=100) Sleep(16);
					else if(chang*kuan<=200) Sleep(14);
					else if(chang*kuan<=250) Sleep(12);
					else if(chang*kuan<=300) Sleep(10);
					else if(chang*kuan<=400) Sleep(7);
					else if(chang*kuan<=500) Sleep(5);
					else if(chang*kuan<=600) Sleep(3);
					else Sleep(2);
				}
			}
			
		}while(head<tail);
		return open;
	}
	
}

int gaming()
{
	unsigned long long t;
	bool pspac=0;
	flaged=0;
	memset(flag,0,sizeof(flag));
	memset(boom,0,sizeof(boom));
	color(15);
	go(0,chang+2);printf("                        \n                         \n                           \n                                 ");
	int key=0;
	int p=0;
	int nx=kuan/2,ny=chang/2;
	for(int i=1;i<=kuan;i++)
	{
		for(int j=1;j<=chang;j++)
		{
			pxy(i,j);
			if(i==kuan) color(15),printf("      ");
		}
	}
	color(15);
	go(3,0);printf("ʣ��������%d    ",lei-flaged);
	mxy(nx,ny);
	while(1)
	{
		key=getch();
		if(key==224)
		{
			key=getch();
			pxy(nx,ny);
			if(key==72)
			{
				if(ny-1>=1)
				{
					ny--;
				}
			}
			if(key==80)
			{
				if(ny+1<=chang)
				{
					ny++;
				}
			}
			if(key==75)
			{
				if(nx-1>=1)
				{
					nx--;
				}
			}
			if(key==77)
			{
				if(nx+1<=kuan)
				{
					nx++;
				}
			}
			mxy(nx,ny);
		}
		if(key==13||bkey)
		{
			if(flag[nx][ny]!=-1)
			{
				flag[nx][ny]=1-flag[nx][ny];
				if(flag[nx][ny]) flaged++;
				else flaged--;
				mxy(nx,ny);
				color(15);
				go(3,0);printf("ʣ��������%d    ",lei-flaged);
			}
		}
		if(key==32||akey)
		{
			if(flag[nx][ny]!=-1)
			{
				if(p==0)
				{
					unsigned seed;
	   				seed = time(0);
	  				srand(seed);
	  				
	  				int kx=getrand(1,kuan);int ky=getrand(1,chang);
	  				for(int i=1;i<=lei;i++)
	  				{
	  					while(boom[kx][ky]==-1||kx==nx&&ky==ny||(kx==nx-1&&ky==ny||kx==nx&&ky==ny-1||kx==nx+1&&ky==ny||kx==nx&&ky==ny+1||kx==nx-1&&ky==ny-1||kx==nx+1&&ky==ny+1||kx==nx+1&&ky==ny-1||kx==nx-1&&ky==ny+1)&&space==1)
	  					{
	  						kx=getrand(1,kuan);ky=getrand(1,chang);
						}
						boom[kx][ky]=-1;
						if(boom[kx+1][ky]!=-1) boom[kx+1][ky]++;
						if(boom[kx][ky+1]!=-1) boom[kx][ky+1]++;
						if(boom[kx-1][ky]!=-1) boom[kx-1][ky]++;
						if(boom[kx][ky-1]!=-1) boom[kx][ky-1]++;
						if(boom[kx+1][ky+1]!=-1) boom[kx+1][ky+1]++;
						if(boom[kx-1][ky-1]!=-1) boom[kx-1][ky-1]++;
						if(boom[kx+1][ky-1]!=-1) boom[kx+1][ky-1]++;
						if(boom[kx-1][ky+1]!=-1) boom[kx-1][ky+1]++;
					}
					t=time(0); 
				}
				p+=find0(nx,ny);
				color(15);go(8,0);printf("%d    ",lei-flaged);
				mxy(nx,ny);
				if(boom[nx][ny]==-1)
				{
				
					t=time(0)-t; 
					color(143);
					printf("Boom!");
					go(0,chang+2);
					color(15); 
					printf("�����ˣ���ʱ%d�롣",t);
					go(0,chang+3);
					cout<<">>  ����������";
					go(2,chang+4);
					cout<<"������һ��";
					go(2,chang+5);
					cout<<"������������";
					int a=0;
					key=0;
					while(key!=13)
					{
						key=getch();
						if(key==224)
						{
							key=getch();
							go(0,chang+3+a);cout<<"  ";
							if(key==72)
							{
								if(a>0) a--;
							}
							else if(key==80)
							{
								if(a<2) a++;
							}
							go(0,chang+3+a);cout<<">>";
						}
					} 
					return a;	
				}

			}
			else
			{
				if(pspac)
				{
					pspac=0;
					int s=0;
					for(int i=-1;i<=1;i++)
						for(int j=-1;j<=1;j++)
							if(flag[nx+i][ny+j]==1) s++;
					if(s==boom[nx][ny])
					{
						s=0;
						for(int i=-1;i<=1;i++)
							for(int j=-1;j<=1;j++)
								if(flag[nx+i][ny+j]!=1&&!out(nx+i,ny+j))
								{
									p+=find0(nx+i,ny+j);
									color(15);go(8,0);printf("%d    ",lei-flaged);
									flag[nx+i][ny+j]=-1;
									if(boom[nx+i][ny+j]==-1) s=1,pxy(nx+i,ny+j); 
								}
						mxy(nx,ny);
						if(s)
						{
							t=time(0)-t; 
							color(143);
							printf("Boom!");
							
							color(15); 
							go(8,0);printf("%d    ",lei-flaged);
							go(0,chang+2);
							printf("�����ˣ���ʱ%d�롣",t);
							go(0,chang+3);
							cout<<">>  ����������";
							go(2,chang+4);
							cout<<"������һ��";
							go(2,chang+5);
							cout<<"������������";
							int a=0;
							key=0;
							while(key!=13)
							{
								key=getch();
								if(key==224)
								{
									key=getch();
									go(0,chang+3+a);cout<<"  ";
									if(key==72)
									{
										if(a>0) a--;
									}
									else if(key==80)
									{
										if(a<2) a++;
									}
									go(0,chang+3+a);cout<<">>";
								}
							} 
							return a;
						} 
					} 
				} 
				else pspac=1;
			} 
				
		}
		else pspac=0;
		if((key=='z'&&GetKeyState('X')<0||key=='Z'&&GetKeyState('X')<0||key=='x'&&GetKeyState('Z')<0||key=='X'&&GetKeyState('Z')<0)&&flag[nx][ny]==-1)
		{
			int s=0;
			for(int i=-1;i<=1;i++)
				for(int j=-1;j<=1;j++)
					if(flag[nx+i][ny+j]==1) s++;
			if(s==boom[nx][ny])
			{
				s=0;
				for(int i=-1;i<=1;i++)
					for(int j=-1;j<=1;j++)
						if(flag[nx+i][ny+j]!=1&&!out(nx+i,ny+j))
						{
							p+=find0(nx+i,ny+j);
							pxy(nx+i,ny+j);
							color(15);go(8,0);printf("%d    ",lei-flaged);
							flag[nx+i][ny+j]=-1;
							if(boom[nx+i][ny+j]==-1) s=1,pxy(nx+i,ny+j); 
						}
				mxy(nx,ny);
				if(s)
				{
					t=time(0)-t; 
					color(143);
					printf("Boom!");
					color(15); 
					go(8,0);printf("%d    ",lei-flaged);
					go(0,chang+2);
					printf("�����ˣ���ʱ%d�롣",t);
					go(0,chang+3);
					cout<<">>  ����������";
					go(2,chang+4);
					cout<<"������һ��";
					go(2,chang+5);
					cout<<"������������";
					int a=0;
					key=0;
					while(key!=13)
					{
						key=getch();
						if(key==224)
						{
							key=getch();
							go(0,chang+3+a);cout<<"  ";
							if(key==72)
							{
								if(a>0) a--;
							}
							else if(key==80)
							{
								if(a<2) a++;
							}
							go(0,chang+3+a);cout<<">>";
						}
					} 
					return a;
				} 
			} 
		}
		if(p==chang*kuan-lei)
		{
			color(15); 
			
			t=time(0)-t; 
			go(8,0);printf("%d    ",lei-flaged);
			go(0,chang+2);
			printf("��Ӯ�ˣ���ʱ%d�롣",t);
			for(int j=1;j<=chang;j++)
			{
				for(int i=1;i<=kuan;i++)
				{
					if(boom[i][j]==-1) 
					{
						flag[i][j]=-1;
						pxy(i,j); 
						if(lei<=16) Sleep(200);
						else if(lei<=32) Sleep(150);
						else if(lei<=64) Sleep(120);
						else if(lei<=128) Sleep(75);
						else if(lei<=256) Sleep(40);
						else Sleep(20);
					}
				}
			} color(15); 
			go(0,chang+3);
			cout<<">>  ����������";
			go(2,chang+4);
			cout<<"������һ��";
			go(2,chang+5);
			cout<<"������������";
			int a=0;
			key=0;
			while(key!=13)
			{
				key=getch();
				if(key==224)
				{
					key=getch();
					go(0,chang+3+a);cout<<"  ";
					if(key==72)
					{
						if(a>0) a--;
					}
					else if(key==80)
					{
						if(a<2) a++;
					}
					go(0,chang+3+a);cout<<">>";
				}
			} 
			return a;
		}
	}
	
}
int main()
{
	SetConsoleTitle("ɨ��");
	CONSOLE_CURSOR_INFO cursor_info={1,0};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);//���ع�� 
	color(15);
	go(0,3);printf(">>  ���ͼ���9*9��10�ף���֤��һ�������ף�");
	go(2,4);printf("���м���12*12��18�ף���֤��һ�������ף�");
	go(2,5);printf("���߼���16*16��32�ף���֤��һ�������ף�");
	go(2,6);printf("���Զ���");
go(0,9);printf("����������");
	go(2,10);printf("��������ƹ���ƶ�;");
	go(2,11);printf("Enter/X��ǡ�");
	go(2,12);printf("Space/Z�򿪹��ѡ�д�;");
	go(2,13);printf("���������οո��/ͬʱ����Z��X");
	go(2,14);printf("    ��������Χ����״�����������Χ�ѱ����������ѡ�з����ϵ�������ȣ�; ");
	
go(0,16);printf("ʤ���ж���");	
	go(2,17);printf("ʤ��:���׷���������з��񱻴�;");
	go(2,18);printf("ʧ��:�����׷��񱻴򿪡�");
	
	int a=0,key=0;
	while(key!=13)
	{
		key=getch();
		if(key==224)
		{
			key=getch();
			go(0,3+a);printf("  ");
			if(key==72)
			{
				if(a>0)
				{
					a--;
				}
			}
			if(key==80)
			{
				if(a<3)
				{
					a++;
				}
			}
			go(0,3+a);printf(">>");
		}
	}
	if(a==0)
	{
		chang=9;
		kuan=9;
		lei=10;
		space=0;		
	}
	if(a==1)
	{
		chang=12;
		kuan=12;
		lei=18;
		space=0;
	}
	if(a==2)
	{
		chang=16;
		kuan=16;
		lei=32;
		space=0;
	}
	else if(a==3)
	{
		system("cls");
		chang=0;
		kuan=0;
		lei=0;
		space=0;
		while(chang<=2||chang>128) {
		go(2,2);printf("����������(3-128)��");cin>>chang;}
		while(kuan<=2||kuan>256) {
		go(2,3);printf("����������(3-256)��");cin>>kuan;}
		while(lei<1||lei>chang*kuan-1){
		go(2,4);printf("����������(%d-%d)��",1,chang*kuan-1); cin>>lei;}
		while(space!=1&&space!=2||space==2&&lei>chang*kuan-9){
		go(2,5);printf("��ѡ��֤�ȼ����ȼ�1����֤��һ�������ף��ȼ�2����֤��һ���ȵ��ĸ���Ϊ0����"); cin>>space;}space--;
	}
	system("cls");
	int gr=gaming();
	while(gr)
	{
		if(gr==2)
		{
			system("cls");
			main();
			return 0;
		}
		else gr=gaming();
	}
	return 0;
}
