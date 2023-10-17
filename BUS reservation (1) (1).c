
/*
project bus reservation system practice
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#define MAX 5

void login();
void username();
void display_schedule();
void add_bus();
void display_bus();
void display_routes();
void dlt_bus();
void edit_bus();
void bus_layout();
void booking();
void add_passenger(char search[]);
void staff_details();


typedef struct {
	char fname[50];
	char lname[50];
	float phone_number;
	int no_of_seats; 
	char pickup[50];
	char drop[50];
	int hr,min;
	int payment;
	char side[MAX];
	int seats[MAX];
	
	
}passenger;
	


/*typedef struct {
	char fname[50];
	char lname[50];
	char role[50];
	float contact;
	
	
}staff;*/
//void menu();
typedef struct {
	char name[50];
	char bus_num[50];
	char departure[50];
	char destination[50];
	char route[50];
	int no_of_seats;
	int available_seats;
	float ticket_price;
	int lyyyy,lmm,ldd,lhr,lmin;
	int rhr,rmin;
	int flagA[21];
	int flagB[24];
	passenger p;
}bus_details;
void main()
{

	int choice;
	login();
	
	
	do {
		
		system("cls");
		printf("\t\t\t______________________________________\n");
		printf("\t\t\t              MENU                    \n");
		printf("\t\t\t______________________________________\n");
		printf("\t\t\t[01] Booking\n");
		printf("\t\t\t[02] Display available buses\n");
		printf("\t\t\t[03] Display Schedule\n");
		printf("\t\t\t[04] Display Bus details\n");
		printf("\t\t\t[05] Display Staff details\n");
		printf("\t\t\t[06] Routes\n");
		printf("\t\t\t[07] Reports\n");
		printf("\t\t\t[08] Add Bus\n");
		printf("\t\t\t[09] Delete Bus\n");
		printf("\t\t\t[10] Update\n");
		printf("\t\t\t[0] Exit\n");
		printf("\t\t\tEnter your choice [0-10]\n");
		printf("\t\t\tYour choice: ");
		
		scanf("%d", &choice);
		
		system("cls");
		
		switch(choice) {
			case 1:
				printf("\t\t\t             Booking\n");
				printf("\t\t\t______________________________________\n");
				display_routes();
				booking();
				break;
			case 2:
				printf("\t\t\t        Display Available Buses\n");
				printf("\t\t\t______________________________________\n");
				break;
			case 3:
				printf("\t\t\t        Display Schedules\n");
				printf("\t\t\t______________________________________\n");
		
				break;
			case 4:
				printf("\t\t\t        Display Bus Details\n");
				printf("\t\t\t______________________________________\n");
				display_bus();
				break;
			case 5:
				printf("\t\t\t       Dispaly Staff Display\n");
				printf("\t\t\t______________________________________\n");
			//	staff_details();
				break;
			case 6:
				printf("\t\t\t             Routes\n");
				printf("\t\t\t______________________________________\n");
				display_routes();
				break;
			case 7:
				printf("\t\t\t         Display Reports\n");
				printf("\t\t\t______________________________________\n");
				break;
			case 8:
				printf("\t\t\t              Add Bus\n");
				printf("\t\t\t______________________________________\n");
				add_bus();
				break;
			case 9:
				printf("\t\t\t           Delete Bus\n");
				printf("\t\t\t______________________________________\n");										
				dlt_bus();
				break;
			case 10:
				printf("\t\t\t             Update\n");
				printf("\t\t\t______________________________________\n");
				edit_bus();
			case 0:
				 exit (0);
				break;
				
			default:
				printf("\t\t\tEnter valid choice");
				printf("\t\t\t______________________________________\n");
				break;
		}
		getch();					
	} while(choice !=0 );
}


void login(){
	
	int i;
	printf("\t\t\t______________________________________\n");
	printf("\t\t\t      Bus Reservation system          \n");
	printf("\t\t\t______________________________________\n");
	printf("\n\n\n\n");	
	printf("\t\t\t______________________________________\n");
	printf("\t\t\t            login page                \n");
	printf("\t\t\t______________________________________\n");
	
	username();
	
}

void username(){
	char user[]={"username"};
	char pass[]={"password"};
	char a[20];
	char ch,pwd[20];
	int c,d,i=0;
	printf("\t\t\t     USERNAME: ");
	scanf("%s",&a);
	printf("\n\t\t\t     PASSWORD: ");
	while((ch=getch())!=13){
		pwd[i]=ch;
		if(ch== '\b'){
			printf("\b");
			continue;
		}
		else{
			printf("*");
			i++;
		}
	}
	pwd[i]='\0';
	
	
	c=strcmp(a,user);
	d=strcmp(pwd,pass);
	
	if((c || d)!=0){
		system("cls");
		printf("\n\t\t\tinvalid username or password\n");
		login();		
	}

}

void add_bus(){
	bus_details bus;
	int i,m,total=0, add_more=0;
	FILE *fp;
	
	fp = fopen("Bus_reservation.txt","a+");
	if(fp== NULL){
		printf("Error opening file");
		exit (1);
	}
	
	do{
		printf("\tEnter Bus Details:\n\n");
		printf("\tBus name: ");
		scanf("%s",&bus.name);		
		printf("\n\tBus number: ");
		scanf("%s",&bus.bus_num);		
		printf("\n\tDestination: ");
		scanf("%s",&bus.destination);		
		printf("\n\tRoute: ");
		scanf("%s",&bus.route);
		printf("\n\tNo of seats: ");
		scanf("%d",&bus.no_of_seats);
		printf("\n\tAvailable  seats: ");
		scanf("%d",&bus.available_seats);
		printf("\n\tTicket price: ");
		scanf("%f",&bus.ticket_price);
		printf("\n\tDeparture: yyyy-mm-dd hr:min\n\t");
		scanf("%d-%d-%d%d:%d",&bus.lyyyy,&bus.lmm,&bus.ldd,&bus.lhr,&bus.lmin);
		
		printf("\n\tTravel Durations: hr:min \n\t");
		scanf("%d:%d",&bus.rhr,&bus.rmin);
		
	/*		printf("\nEnter staff details\n");
			printf("staff[1]\n");
			printf("Name: ");
			scanf("%s%s",&bus.s1.fname,&bus.s1.lname);
			printf("\nRole: ");
			scanf("%s",&bus.s1.role);
			printf("\ncontact: ");
			scanf("%f",&bus.s1.contact);
			printf("staff[2]\n");
			printf("Name: ");
			scanf("%s%s",&bus.s2.fname,&bus.s2.lname);
			printf("\nRole: ");
			scanf("%s",&bus.s2.role);
			printf("\ncontact: ");
			scanf("%f",&bus.s2.contact);
			printf("staff[3]\n");
			printf("Name: ");
			scanf("%s%s",&bus.s3.fname,&bus.s3.lname);
			printf("\nRole: ");
			scanf("%s",&bus.s3.role);
			printf("\ncontact: ");
			scanf("%f",&bus.s3.contact);
	*/	
		
		fwrite(&bus,sizeof(bus_details),1,fp);
		
		printf("\n\nAdd More?? (1 for Yes | 0 for No): ");
		scanf("%d",&add_more);
		
	} while(add_more ==1);
	
	fclose(fp);
}
void display_bus(){
	bus_details bus;
	
	FILE *fp;
	int i=1;
	fp = fopen("Bus_reservation.txt","r");
	if(fp== NULL){
		printf("No data fount\n");
		exit (1);
	}
	
	printf("\nS.N\tName\t\t\tNumber\t\tticket price\tno of seats\tavailable seats\n");
	do{	
		fread(&bus,sizeof(bus_details),1,fp);

		printf("%d\t%-20s\t%-15s\t%.2f\t\t\t%d\t\t%d\n",
			i,
			bus.name,
			bus.bus_num,
			bus.ticket_price,
			bus.no_of_seats,
			bus.available_seats);
			i++;
	}while(fread(&bus,sizeof(bus_details),1,fp) != 0);
	fclose(fp);
	getch();
}
void display_routes(){
	bus_details bus;
	int i=1;
	FILE *fp;

	fp=fopen("Bus_reservation.txt","r");
	if(fp==NULL){
		printf("Error opening file\n");
		exit(1);
	}
	
	printf("\nS.N\tName\t\tNumber\t\troute\t\tdestination\tleave on\t\tDuration\n");
	do{	
		fread(&bus,sizeof(bus_details),1,fp);
		printf("%d\t%-10s\t%-10s\t%-15s\t%-15s\t%d-%d-%d %d:%d\t\t%d:%d\n",
			i,
			bus.name,
			bus.bus_num,
			bus.route,
			bus.destination,
			bus.lyyyy,bus.lmm,bus.ldd,bus.lhr,bus.lmin,
			bus.rhr,bus.rmin
			);
			i++;
	}while(fread(&bus,sizeof(bus_details),1,fp) != 0);
	fclose(fp);
	
}

void dlt_bus(){
	display_bus();
	char search_bus[20];
	bus_details bus;
	int found=0;
	FILE *fp, *temp ;
	fp = fopen("Bus_reservation.txt","r");
	fp=fopen("temp.txt","w");
	if(fp==NULL){
		printf("Error opening File");
		exit (0);
	}
	
	printf("enter the Bus number to dlt: ");
	scanf("%s",&search_bus);
	
	do{
		fread(&bus,sizeof(bus_details),1,fp);
		printf("%s",bus.bus_num);
		if ((strcmp(bus.bus_num, search_bus)) == 0){
			
			found=1;
			continue ;	
		}
		else
		{
			fwrite(&bus,sizeof(bus_details),1,temp);
		}	
	}while(fread(&bus,sizeof(bus_details),1,fp)!=0);
	
	if(found==0){
		printf("unsucessful");
	}
	fclose(fp);
	fclose(temp);
	
	remove("Bus_reservation.txt");
	rename("temp.txt","Bus_reservation.txt");
}
void booking(){
	char search[25];
	int found=0;
	bus_details bus;
	FILE *fp;
	int i;
	int A=0;
	int B=0;
	int row;
	int sideA;
	int sideB;
	fp = fopen("Bus_reservation.txt","r");
	if(fp== NULL){
		printf("No data fount\n");
		exit (1);
	}	
	printf("Select bus:\n");
	scanf("%s",&search);
	do{
		fread(&bus,sizeof(bus_details),1,fp);
		if(strcmp(search,bus.bus_num) == 0){
			found=1;
			system("cls");
			printf("Bus name: %10s no: %10s\n",bus.name,bus.bus_num);
			printf("\n\t\tSIDE A\t\t\t\tSIDE B\n\n");
			for(row=1;row<13;row++){
				for(sideA=1;sideA<4;sideA++){
					if((sideA==3 && row!=12)|| row<=2){
							printf("               ");
					}
					else{
						if(bus.flagA[A]==1){
							printf("%2d.Booked      ",A+1);
							A++;
						}
						else{
							printf("%2d.Available   ",A+1);
							A++;
						}
					}
			
				}
				for(sideB=1;sideB<=2;sideB++){
					if(bus.flagB[B]==1){
							printf("%2d.Booked      ",B+1);
							B++;
						}
						else{
							printf("%2d.Available   ",B+1);
							B++;
						}
					
				}
				printf("\n\n");
			}
			break;
		}
			
	}while(fread(&bus,sizeof(bus_details),1,fp)==0);
	if(found==0){
		printf("not runinng good\n");
	}
	add_passenger(search);
	fclose(fp);
 
}
/*
void add_passenger(char search[]){
	bus_details bus;
	char a='a';
	char b='b';
	int add_more=0;
	int i;
	int booked;
	FILE *fp;
	int found=0;
	fp=fopen("Bus_reservation.txt","a+");
	if(fp == NULL){
		printf("No details found\n");
		exit(1);
	}

	do{
		fread(&bus,sizeof(bus_details),1,fp);
		if(strcmp(search,bus.bus_num) == 0){
			found=1;
			
			do{
			
				printf("Enter passenger details\n");
				printf("\tName: ");
				scanf("%s%s",&bus.p.fname,&bus.p.fname);
				printf("\n\tContact: ");
				scanf("%f",&bus.p.phone_number);
				printf("\n\tPick up location: ");
				scanf("%s",&bus.p.pickup);
				printf("\n\tPick up Time: ");
				scanf("%d:%d",&bus.p.hr,&bus.p.min);
				
				printf("\n\tDrop: ");
				scanf("%s",&bus.p.drop);
				printf("\n\tNumber of  seats: ");
				scanf("%d",&bus.p.no_of_seats);
				
				while(bus.p.no_of_seats>=6){
					printf("\n\tmaximum booking exceeded enter below 6\n\t");
					scanf("%d",&bus.p.no_of_seats);
				}
				printf("\n\tEnter Side and seat no\n");
				for(i=0;i<bus.p.no_of_seats;i++){
					booked=0;				
				//	do{
						scanf("%c%d",&bus.p.side[i],&bus.p.seats[i]);
						//if(bus.p.side[i][1]=='a')
						if(strcmp(bus.p.side[i],a)==0)
						{
							if(bus.flagA[bus.p.seats[i]] == 1 ){
								printf("the seat is already booked\nselect other: \n");
							}else{
								bus.flagA[bus.p.seats[i]] = 1;
								booked=1;
							}
						}
						if(strcmp(bus.p.side[i],b)==0){
							if(bus.flagB[bus.p.seats[i]] == 1 ){
								printf("the seat is already booked\nselect other: \n");
							}else{
								bus.flagB[bus.p.seats[i]] = 1;
								booked=1;
							}									
						}

					//}while(booked!=1);											
				}
				printf("\tPayment(1 for paid || 0 for pending)\n\t");
				scanf("%d",&bus.p.payment);
				
			}while(add_more == 1);
			fwrite(&bus,sizeof(bus_details),1,fp);
		}
		
	}while(fread(&bus,sizeof(bus_details),1,fp) != 0);
	fclose(fp);
	if(found==0){
		printf("\nData not found");
	}	
}*/
void add_passenger(char search[]) {
    bus_details bus;
    char a = 'a';
    char b = 'b';
    int i;
    int booked;
    int found = 0;
    int add_more=0;
    FILE *fp, *temp;
    
    fp = fopen("Bus_reservation.txt", "r+");
    temp = fopen("temp.txt", "w+");
    
    if (fp == NULL || temp == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }

    while (fread(&bus,sizeof(bus_details),1,fp) == 1) {
        if (strcmp(search, bus.bus_num) == 0) {
            found = 1;

            // Implement code to add passenger details here.
            do{
            	
				printf("Enter passenger details\n");
				printf("\tName: ");
				scanf("%s%s",&bus.p.fname,&bus.p.fname);
				printf("\n\tContact: ");
				scanf("%f",&bus.p.phone_number);
				printf("\n\tPick up location: ");
				scanf("%s",&bus.p.pickup);
				printf("\n\tPick up Time: ");
				scanf("%d:%d",&bus.p.hr,&bus.p.min);
				
				printf("\n\tDrop: ");
				scanf("%s",&bus.p.drop);
				printf("\n\tNumber of  seats: ");
				scanf("%d",&bus.p.no_of_seats);
				
				while(bus.p.no_of_seats>=6){
					printf("\n\tmaximum booking exceeded enter below 6\n\t");
					scanf("%d",&bus.p.no_of_seats);
				}
				printf("\n\tEnter Side and seat no\n");
				for(i=0;i<bus.p.no_of_seats;i++){
					booked=0;				
					do{
						scanf("%c %d",&bus.p.side[i],&bus.p.seats[i]);
						//if(bus.p.side[i][1]=='a')
						if(strcmp(bus.p.side[i],a)==0)
						{
							if(bus.flagA[bus.p.seats[i]] == 1 ){
								printf("the seat is already booked\nselect other: \n");
							}else{
								bus.flagA[bus.p.seats[i]] = 1;
								booked=1;
							}
						}
						if(strcmp(bus.p.side[i],b)==0){
							if(bus.flagB[bus.p.seats[i]] == 1 ){
								printf("the seat is already booked\nselect other: \n");
							}else{
								bus.flagB[bus.p.seats[i]] = 1;
								booked=1;
							}									
						}

					}while(booked!=1);											
				}
				printf("\tPayment(1 for paid || 0 for pending)\n\t");
				scanf("%d",&bus.p.payment);
            // You can use a loop to read passenger data and book seats.

            fwrite(&bus, sizeof(bus_details), 1, temp);
        } else {
            fwrite(&bus, sizeof(bus_details), 1, temp);
        }
    }

    if (!found) {
        printf("Bus not found.\n");
    }

    fclose(fp);
    fclose(temp);

    // Replace the original file with the temporary file
    remove("Bus_reservation.txt");
    rename("temp.txt", "Bus_reservation.txt");
}
