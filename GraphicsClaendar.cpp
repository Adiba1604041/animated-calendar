#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<bits/stdc++.h>
#define TRUE    1
#define FALSE   0
using namespace std;

int year, days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    char *months[]=
    {
	" ",
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"};


   int inputyear(void)
{
	int year;

	printf("\t\tPlease enter a year (example: 1999) : ");
	scanf("%d", &year);
	return year;
}

    //checking leap year
    int determineleapyear(int year)
{
	if(year% 4 == FALSE && year%100 != FALSE || year%400 == FALSE)
	{
		days_in_month[2] = 29;
		return TRUE;
	}
	else
	{
		days_in_month[2] = 28;
		return FALSE;
	}
}

   //daycode
   int determinedaycode(int year)
{
	int daycode;
	int d1, d2, d3;

	d1 = (year - 1.)/ 4.0;
	d2 = (year - 1.)/ 100.;
	d3 = (year - 1.)/ 400.;
	daycode = (year + d1 - d2 + d3) %7;
	return daycode;
}



void calendar(int year, int daycode)
{
    int k=0,l=0,v=0;
	int month, day;
	for ( month = 1; month <= 12; month++ )
	{
	    char a[100];
        settextstyle(10,HORIZ_DIR,6);
        outtextxy(335,20,"Calendar");
        settextstyle(10,HORIZ_DIR,6);
        sprintf(a,"%d",year);
        outtextxy(630,20,a);
        bar(20,0,40,700);
        bar(60,0,80,600);
        bar(100,0,120,500);
        bar(140,0,160,400);
        bar(180,0,200,300);
        bar(220,0,240,200);
        bar(400,580,1000,600);
        bar(300,620,1000,640);
        bar(200,660,1000,680);

	v=0;

        settextstyle(10,HORIZ_DIR,3);
		outtextxy(500,94,months[month]);
		 settextstyle(10,HORIZ_DIR,2);
		outtextxy(380,118,"Sun Mon Tue Wed Thu Fri Sat" );

		// Correct the position for the first date
		for ( day = 1; day <= daycode; day++ )
        {
            outtextxy(400+l,155,"      ");
            l=l+100;

        }
		settextstyle(10,HORIZ_DIR,2);
		// Print all the dates for one month
		for ( day = 1; day <= days_in_month[month]; day++ )
		{
		    char arr[100];
			sprintf(arr,"%2d",day);
		    outtextxy(400+k,155+v,arr);

			// Is day before Sat? Else start next line Sun.
           if ( ( day + daycode ) % 7 > 0 )
			outtextxy(400+k,155," ");

			else
            {
            outtextxy(400+k,155+v,arr);
           v=v+50;
            k=-44;
            }
			k=k+44;

		}
		v=v+70;
			// Set position for next month
			daycode = ( daycode + days_in_month[month] ) % 7;

            if(month==1)
        {
            setcolor(WHITE);
            outtextxy(350,440,"Press any key to start the calendar.");

            getch();
        }
         delay(3000);
        if(kbhit())
            {
                getch();
                while(1)
                {
                    if(kbhit())
                        {
                            getch();
                            break;
                        }
                }
            }

        cleardevice();

}


	}

int main()
{
    int gd=DETECT;
    int gm;
    initwindow(1000,700,"",20,20);

    system ("color f9") ;
	int year, daycode, leapyear;

	year = inputyear();
	daycode = determinedaycode(year);
	determineleapyear(year);
	calendar(year, daycode);
	printf("\n");
    getch();
    closegraph();
}
