#include <bits/stdc++.h>
#include <cctype>
#include <Windows.h>
using namespace std;

//UDF to implement gotoxy() func from TurboC++ IDE
BOOL gotoxy(const WORD x, const WORD y) 
{
    COORD xy;
    xy.X = x;
    xy.Y = y;
    return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

//checks char ch against the supplied characters in
// vector<char> list. Used to check user input
bool checkInput (char ch, vector<char> list)
{
	for (auto it= list.begin(); it!=list.end(); it++)
	{
		if (ch==*it)
			return true;
	}

	return false;
} 

//Checking the re-entered user value
char ReEntry (char ch, int i, vector <char> list, int x=0)
{
	//x==0 for checking from get_symptoms functions
	if (!x)
	{
		gotoxy(5,6+2*i+1);
		cout<<"Re-enter from given options "; //28 characters
		gotoxy(64,6+2*i);
	}

	//x==1 for checking from display_msg function
	else
	{
		gotoxy(31,15);
		cout<<"Re-enter from given options ";
		gotoxy(50,14);
	}

	cin>>ch;
	ch= toupper(ch);

	if (checkInput (ch, list))
	{
		if (!x)
			gotoxy(5,6+2*i+1);
		else
			gotoxy(31,15);
		
		for (int j=0; j<28; j++)		 //Erasing the re-input msg
			cout<<" ";
	}

	return ch;
}

//class to determine diabetic based on symptoms and user input
class diabetes
{
	
	private:
		char name[40];
		int age;
		float wt;
		float ht;
		char sex;
		char s[10];

	public:
		void welcome_screen(void);
		void getvalue(void);
		void diagnosis(void);
		void getlevel1_symptoms(void);
		void getlevel2_symptoms(void);
		void getlevel3_symptoms(void);
		int analyse_symptoms(int);
		char display_message(int,int);
		void disclaimer();		
		
		//un-used in main program. Useful for debugging	
		void getS(int end)
		{
			//obtains the char array s[0:end]

			gotoxy(35,27);
			for (int i=0; i<end; i++)
				cout<<s[i];
			gotoxy(35+end/2,28);
			getchar();
		}

		char bmi_calc()
		{
			float bmi= wt/pow(ht,2);

			if (bmi<19)
				return 'B';
			else if (bmi<25)
				return 'N';
			else if (bmi<30)
				return 'A';
			else
				return 'O';
		}


		char age_calc()
		{
			if (age<35)
				return 'Y';
			else if (age<60)
				return 'M';
			else
				return 'E';
		}

};

int main()
{
	//variable to determine diabetic or not based on user input
	int m;
	//int n;
	
	diabetes dts;
	
	dts.welcome_screen();
	dts.getvalue();
	dts.diagnosis();
	
	dts.getlevel1_symptoms();
	//dts.getS(10);
	m= dts.analyse_symptoms(1);
	
	dts.display_message(m,1);   
	
	dts.getlevel2_symptoms();
	//dts.getS(7);
	m= dts.analyse_symptoms(2);
	
	dts.display_message(m,2);
	

	dts.getlevel3_symptoms();
	//dts.getS(5);
	m= dts.analyse_symptoms(3);
	
	dts.display_message(m,3);			

	return 0;
}

void diabetes::welcome_screen()
{
	system("cls");
	gotoxy(17,7);
	system("color 06");
	printf("*************** W E L C O M E *************** " );
	//gotoxy(25,9);
	//printf(" DPS RUBY PARK " );
	gotoxy(24,9);
	printf(" MEDICAL  DIAGNOSIS  SOFTWARE ");
	system("color 02");
	
	gotoxy(22,14);
	printf("DONE BY : ATRIK RAY ");
	gotoxy(22,16);
	printf("DPS RUBY PARK ");
	gotoxy(43,18);

	gotoxy(17,25);
	printf("******** PRESS ANY KEY TO CONTINUE ***********");
	gotoxy(40,27);
	getchar();
	return;
}


void diabetes::getvalue()
{
	system ("cls");
	system ("color 07");


	gotoxy(20,8);
	printf(" PERSONAL  INFORMATION");
	/*
	printf("NAME :");
	gotoxy(25,i);
	*/

	int i=10;	
	gotoxy(25,i);
	printf("AGE :");
	gotoxy(25,i+2);
	printf("WEIGHT (in kg):");
	gotoxy(25,i+4);
	printf("HEIGHT (in m):");

	/*
	gotoxy(25,i+2);
	printf("SEX (M/F) :");
	system ("color 07");
	gotoxy(42,i);
	gets(name);
	gotoxy(42,i+2);
	cin>>age;
	*/

	gotoxy(50,i);
	cin>>age;
	gotoxy(50,i+2);
	cin>>wt;
	gotoxy(50,i+4);
	cin>>ht;
	/*
	gotoxy(42,18);
	cin>>sex;
	*/
	getchar();
	return;
}

void diabetes::diagnosis(void)
{
	system("cls");
	system("color 06");
	gotoxy(17,7);
	printf("************* DIAGNOSIS WINDOW ************** ");
	gotoxy(22, 14);
	printf(" Let's have a look at symptoms.");
	gotoxy(22, 16);
	printf(" Please enter the form in next page.");
	gotoxy(17,23);
	printf("*************** PRESS ANY KEY *************** ");
	gotoxy(40,27);
	getchar();
}

//Diabetic or not
void diabetes::getlevel1_symptoms()
{
	system("cls");
	
	//valid characters for the given symptoms
	vector<vector<char>> checklist= 
	{
		{'H','L','N'},
		{'P','A'},
		{'I','N'},
		{'D','N'},
	};

	//symptom msgs displayed to the user
	char const *msgs[]=	
	{
	"APPETITE (H(HIGH),/L(LOW),/N(NORMAL))",
	"FREQUENCY OF THIRST(H(HIGH),/L(LOW)/N(NORMAL))",
	"FREQUENCY OF URINATION(H(HIGH),/L(LOW),/N(NORMAL))",
	"VISION (I(IMPAIRMENT),/N(NORMAL))",
	"URINE SUGAR (P(PRESENT)/A(ABSENT))",
	"KETONURIA (P(PRESENT)/A(ABSENT))",
	"FASTING BLOOD SUGAR (H(HIGH)/L(LOW)/N(NORMAL))",
	"R B S (H(HIGH)/L(LOW)/N(NORMAL))",
	"FAMILY HISTORY OF DIABETES (P(PRESENT)/A(ABSENT))",
	"OGTT (D/N)",
	};

	gotoxy(16,3);
	system ("color 07");
	printf( " *** MEDICAL DIAGONOSIS FORM LEVEL 1 SYMPTOMS*** ");

	for (int i=0; i<10; i++)
	{
		gotoxy(3,6+i*2);
		cout<<i+1<<". ";
		cout.write(msgs[i],strlen(msgs[i]));
		gotoxy(64,6+i*2);
		cin>>s[i];
		s[i]= toupper(s[i]);
		//cout<<"\n";

		switch (i)
		{
			//For inputs H,L,N
			case 0:
			case 1:
			case 2:
			case 6:
			case 7:
				while (!(checkInput (s[i], checklist[0])))
				{
					s[i]= ReEntry(s[i], i, checklist[0]);
				}
				break;

			//For inputs P,A
			case 4:
			case 5:
			case 8:
				while (!(checkInput (s[i], checklist[1])))
				{
					s[i]= ReEntry(s[i], i, checklist[1]);
				}
				break;

			//For input I,N
			case 3:
				while (!(checkInput (s[i], checklist[2])))
				{
					s[i]= ReEntry(s[i], i, checklist[2]);
				}
				break;

			//For input D,A
			case 9:
				while (!(checkInput (s[i], checklist[3])))
				{
					s[i]= ReEntry(s[i], i, checklist[3]);
				}	
				break;
		}
		
	}

	
	getchar();
	return;
	
}

//Primary diabetes or secondary
void diabetes::getlevel2_symptoms()
{
	system("cls");

	//valid characters for the given symptoms
	vector<vector<char>> checklist= 
	{
		{'H','L','N'},
		{'P','A'},
	};

	char const *msgs[]= 
	{
		"PANCREATITIS (P/A):",
		"CARCINOMA (P/A):",
		"CIRHHOSIS (P/A):",
		"HCTS (H/L/N):",
		"HEPATITIS (P/A):",
		"HORMONAL DISORDER (P/A):",
		"PANCREATECTOMY (P/A):",
	};

	gotoxy(16,3);
	system ("color 07");
	printf( " *** MEDICAL DIAGONOSIS FORM LEVEL 2 SYMPTOMS*** ");

	for (int j=0; j<7; j++)
	{
		gotoxy(3,6+j*2);
		cout<<j+1<<". ";
		cout.write(msgs[j],strlen(msgs[j]));
		gotoxy(64,6+j*2);
		cin>>s[j];
		s[j]= toupper(s[j]);
		//cout<<"\n";

		switch (j)
		{
			//For inputs H,L,N
			case 0:
			case 1:
			case 2:
			case 4:
			case 5:
			case 6:
				while (!(checkInput (s[j], checklist[1])))
				{
					s[j]= ReEntry(s[j], j, checklist[1]);
				}
				break;

			//For inputs P,A
			case 3:
				while (!(checkInput (s[j], checklist[0])))
				{
					s[j]= ReEntry(s[j], j, checklist[0]);
				}
				break;
		}
	}

	getchar();
	return;
}

//If primary, then insulin dependent or not
void diabetes::getlevel3_symptoms()
{
	int k=0;
	system("cls");

	gotoxy(16,3);
	system ("color 07");
	printf( " *** MEDICAL DIAGONOSIS FORM LEVEL 3 SYMPTOMS*** ");

	gotoxy(3,6);
	cout<<k+1<<". ";
	printf(" AGE (Taken from previous input) ");
	gotoxy(64,6);
	s[k]= age_calc();
	//s[k]= toupper (s[k]);
	cout<<s[k];

	/*
	while (!(checkInput (s[k], {'Y', 'M', 'E'})))
	{
		s[k]= ReEntry(s[k], k, {'Y', 'M', 'E'});
	}
	*/

	++k;
	gotoxy(3,6+k*2);
	cout<<k+1<<". ";
	printf(" BODY WEIGHT (Calculated from your height and weight)");
	gotoxy(64,6+k*2);
	s[k]= bmi_calc();
	//s[k]= toupper(s[k]);
	cout<<s[k];

	/*
	while (!(checkInput (s[k], {'N', 'A', 'B', 'O'})))
	{
		s[k]= ReEntry(s[k], k, {'N', 'A', 'B', 'O'});
	}
	*/
	
	++k;
	gotoxy(3,6+k*2);
	cout<<k+1<<". ";
	printf(" DURATION OF SYMPTOMS (Weeks(W)/Months(M)/Years(Y))");
	gotoxy(64,6+k*2);
	cin>>s[k];
	s[k]= toupper(s[k]);

	while (!(checkInput (s[k], {'W', 'M', 'Y'})))
	{
		s[k]= ReEntry(s[k],k,{'W', 'M', 'Y'});
	}

	++k;
	gotoxy(3,6+k*2);
	cout<<k+1<<". ";
	printf(" KETONURIA (P/A)");
	gotoxy(64,6+k*2);
	cin>>s[k];
	s[k]= toupper(s[k]);

	while (!(checkInput (s[k],  {'P', 'A'})))
	{
		s[k]= ReEntry(s[k],k, {'P', 'A'});
	}

	++k;
	gotoxy(3,6+k*2);
	cout<<k+1<<". ";
	printf("AUTO ANTIBODIES (P/A)");
	gotoxy(64,6+k*2);
	cin>>s[k];
	s[k]= toupper(s[k]);

	while (!(checkInput (s[k], {'P', 'A'})))
	{
		s[k]= ReEntry(s[k],k,{'P', 'A'});
	}
	
	++k;
	getchar();
	return;
}

int diabetes::analyse_symptoms(int n)
{
	int i=0;
	int count=0;
	int result=0;
	
	switch(n)
	{
		case 1: //Analysis of level 1 symptoms
		if(s[9]=='D')
			result=-1;
		else if(s[5]=='P' && s[6]=='H' && s[7]=='H')
			result=-1;
		else
		{
			for(i=0;i<10;i++)
			{
				if(s[i]=='H'||s[i]=='P'||s[i]=='D'||s[i]=='I')
				count++;
			}
			
			if(count>5)
				result=-1;
		}

		break;
		
		case 2: //Analysis of level 2 symptoms
			for (int i=0; i<7; i++)
			{
				if (s[i]=='P' || s[i]=='H')
				{
					return -1;
				}
			}
			
			return 0;
			break;
		
		case 3: //Analysis of level 3 symptoms
			if
			(
				((s[0]=='Y')&&(s[1]=='N')&&(s[2]=='W')&&(s[3]=='P')&&(s[4]=='P'))
				||((s[0]=='Y')&&(s[1]=='B')&&(s[2]=='W')&&(s[3]=='P')&&(s[4]=='P'))
				||((s[0]=='Y')&&(s[1]=='N')&&(s[2]=='M')&&(s[3]=='P')&&(s[4]=='P'))
				||((s[0]=='Y')&&(s[1]=='N')&&(s[2]=='Y')&&(s[3]=='P')&&(s[4]=='P'))
			)
				result=0;
			else
				result=-1;
			break;

		default:
			break;
	}
	return(result);
}

char diabetes::display_message(int m,int n)
{
	char ch;
	system("cls");

	switch(n)
	{
		case 1: //Display msg after level 1 symptoms
			switch(m)
			{
				case 0: 
					gotoxy(30,12);
					system("color 02");
					printf("THE PERSON IS NOT DIABETIC");
					disclaimer();
					printf("PRESS ANY KEY TO QUIT." );
					//system("color 07");
					gotoxy(40,27);
					//cin>>ch;
					//break;
					getchar();
					cout<<"\n";
					exit(0);

				case -1:
					gotoxy(30,12);
					system("color 04");
					printf("THE PERSON IS DIABETIC ");
					gotoxy(30,14);
					printf("Proceed(Y/N)?");
					gotoxy(50,14);
					cin>>ch;
					ch= toupper(ch);
					while (!(checkInput (ch, {'Y', 'N'})))
					{
						ch= ReEntry(ch, 0, {'Y', 'N'}, 1);
					}
					system("color 07");
					break;
			}

			break;

		case 2:	//Display msg after level 2 symptoms
			switch(m)
			{
				case 0: 
					gotoxy(30,12);
					system("color 06");
					printf("IT IS PRIMARY DIABETES.");
					gotoxy(30,14);
					printf("Proceed(Y/N)?");
					gotoxy(50,14);
					cin>>ch;
					ch= toupper(ch);
					while (!(checkInput (ch, {'Y', 'N'})))
					{
						ch= ReEntry(ch, 0, {'Y', 'N'}, 1);
					}
					system("color 07");
					break;
				case -1: 
					gotoxy(30,12);
					system ("color 06");
					printf("IT IS SECONDARY DIABETES");
					disclaimer();
					printf("PRESS ANY KEY TO QUIT.");
					gotoxy(40,27);
					getchar();
					exit(0);
					cout<<"\n";
					break;
			}

			break;
		
		case 3:	//Display msg after level 3 symptoms
			system("color 0D");
			switch(m)
			{
				case 0: 
					gotoxy(28,12);
					printf("IT IS INSULIN DEPENDENT DIABETES");
					disclaimer();
					printf("PRESS ANY KEY TO QUIT.");
					gotoxy(40,27);
					getchar();
					exit(0);
					break;
				case -1: 
					gotoxy(25,12);
					printf("IT IS NON-INSULIN DEPENDENT DIABETES");
					disclaimer();
					printf("PRESS ANY KEY TO QUIT.");
					gotoxy(40,27);
					getchar();
					exit(0);
					break;
			}

			break;
	}

	if (ch=='N')
	{
		disclaimer();
		printf("PRESS ANY KEY TO QUIT." );
		gotoxy(40,27);
		exit(0);
	}

	return (ch);
}

void diabetes::disclaimer()
{
	int i=14;
	gotoxy(9,i++);
	cout<<"The above symptoms and analysis are based on a general view";
	gotoxy(9,i++);
	cout<<"and may not be accurate for every person.";
	gotoxy(9,i++);
	cout<<"In case you require immediate attention, it is best to";
	gotoxy(9,i++);
	cout<<"communicate with a professional medical practitioner.";
	gotoxy(30,i+2);
}
