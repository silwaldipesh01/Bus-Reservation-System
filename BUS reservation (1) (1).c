
/*
project bus reservation system practice
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define MAX 5

void login();//to show the log in page
void username();//check the username and password from the user
void add_bus();//to and new Bus 
void display_bus();// to show bus details 
int display_routes();//to display all the routes with bus details
void dlt_bus();// to delete the bus 
void booking();
void passenger_details();
void add_passenger(char search[]);
void cancel();
void display_revenue();

int count=0;

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
	float total;
}passenger;

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
		printf("\t\t\t[1] Booking\n");
		printf("\t\t\t[2] Cancel Booking\n");
		printf("\t\t\t[3] Display Bus details\n");
		printf("\t\t\t[4] Display Schedule \ Routes\n");
		printf("\t\t\t[5] Display Revenue Report\n");
		printf("\t\t\t[6] Add Bus\n");
		printf("\t\t\t[7] Delete Bus\n");
		printf("\t\t\t[0] Exit\n");
		printf("\t\t\tEnter your choice [0-7]\n");
		printf("\t\t\tYour choice: ");
		
		scanf("%d", &choice);
		
		system("cls");
		
			switch(choice) {
			case 1:
				printf("\t\t\t              Booking\n");
				printf("\t\t\t______________________________________\n");
			//	display_routes();
				if(display_routes())
					booking();
				break;
			case 2:
				printf("\t\t\t           Cancel Booking\n");
				printf("\t\t\t______________________________________\n");
				cancel();
				break;
			case 3:
				printf("\t\t\t         Display Bus Details\n");
				printf("\t\t\t______________________________________\n");
				display_bus();
				break;
			case 4:
				printf("\t\t\t       Display Schedules\ Reports\n");
				printf("\t\t\t______________________________________\n");
				if(display_routes()==0)
					return ;
				break;
			case 5:
				printf("\t\t\t           Dispaly Revenue\n");
				printf("\t\t\t______________________________________\n");
				display_revenue();
				break;
			case 6:
				printf("\t\t\t             Add Bus\n");
				printf("\t\t\t______________________________________\n");
				add_bus();
				break;
			case 7:
				printf("\t\t\t           Delete Bus\n");
				printf("\t\t\t______________________________________\n");										
				dlt_bus();
				break;
			
			case 0:
				 exit (0);
				break;
				
			default:
				printf("Enter valid choice");
				
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
	int i,m,total=0, add_more=1;
	FILE *fp;
	
	fp = fopen("Bus_reservation.txt","a+");
	if(fp== NULL){
		printf("Error opening file");
		exit (1);
	}
	
	while(add_more ==1){
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
		printf("\n\tDeparture: yyyy-mm-dd hr:min\t");
		scanf("%d-%d-%d%d:%d",&bus.lyyyy,&bus.lmm,&bus.ldd,&bus.lhr,&bus.lmin);
		printf("\n\tDuration : hr:min \t");
		scanf("%d:%d",&bus.rhr,&bus.rmin);
		fwrite(&bus,sizeof(bus_details),1,fp);
		printf("\n\tAdd More?? (1 for Yes | 0 for No): ");
		scanf("%d",&add_more);	
	} 
	
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
	
	printf("\n\tS.N\tName\t\t\tNumber\t\tticket price\tno of seats\tavailable seats\n");
	do{	
		fread(&bus,sizeof(bus_details),1,fp);

		printf("\t%d\t%-20s\t%-15s\t%.2f\t\t\t%d\t\t%d\n",
			i,
			bus.name,
			bus.bus_num,
			bus.ticket_price,
			bus.no_of_seats,
			bus.available_seats);
			i++;
	}while(fread(&bus,sizeof(bus_details),1,fp) != 0);
	fclose(fp);
}
int display_routes(){
	bus_details bus;
	int i=1;
	FILE *fp;

	fp=fopen("Bus_reservation.txt","a+");
	if(fp==NULL){
		printf("\tNo data fount\n");
		return 0;
	}
	if(!fread(&bus,sizeof(bus_details),1,fp)){
			printf("\t\t\t Sorry There are no Routes \n");
			return 0;
	}
	printf("\n\tS.N\tName\t\tNumber\t\troute\t\tdestination\tleave on\t\treach on\n");
	do{
		fread(&bus,sizeof(bus_details),1,fp);
		printf("\t%d\t%-10s\t%-10s\t%-15s\t%-15s\t%d-%d-%d %d:%d\t %d:%d\n",
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
	return 1;
}
void dlt_bus(){
	display_bus();
	char search_bus[20];
	bus_details bus;
	int found=0;
	FILE *fp, *temp ;
	fp = fopen("Bus_reservation.txt","r");
	temp=fopen("temp.txt","w");
	if (fp == NULL || temp == NULL) {
        printf("Error opening File");
        exit(0);
    }
	
	printf("\t\tenter the Bus number to dlt");
	
	scanf("%s",&search_bus);
	
	do{
		fread(&bus,sizeof(bus_details),1,fp);
		if ((strcmp(bus.bus_num, search_bus)) == 0){
			found=1;
			continue ;	
		}else{
			fwrite(&bus,sizeof(bus_details),1,temp);
		}
	}while(fread(&bus,sizeof(bus_details),1,fp)!=0);	
	fclose(fp);
	fclose(temp);
	if (found) {
        remove("Bus_reservation.txt");
        rename("temp.txt", "Bus_reservation.txt");
        printf("\t\tBus record deleted successfully.\n");
    } else {
        remove("temp.txt"); // Delete the temporary file if bus not found
        printf("Bus not found in records.\n");
    }
}


void booking() {
    char search[25];
    int found = 0;
    bus_details bus;
    FILE *fp;
    int A = 0;
    int B = 0;
    int row;
    int sideA;
    int sideB;
    
    fp = fopen("Bus_reservation.txt", "r");
    
    if (fp == NULL) {
        printf("No data found\n");
        exit(1);
    }
    
    printf("\nSelect bus no : ");
    scanf("%s", search);
    
    while (fread(&bus, sizeof(bus_details), 1, fp) == 1) {
        if (strcmp(search,bus.bus_num) == 0) {
            found = 1;
            system("cls");
            printf("\t\tBus name: %10s no: %10s\n", bus.name, bus.bus_num);
            printf("\n\t\tSIDE A\t\t\t\tSIDE B\n\n");
            
            for (row = 1; row <= 12; row++) {
                for (sideA = 1; sideA < 4; sideA++) {
                    if ((sideA == 3 && row != 12) || row <= 2) {
                        printf("               ");
                    } else {
                        if (bus.flagA[A] == 1) {
                          // printf("%2d.Booked      ", A + 1);
                          printf("%2d.%-12s", A + 1,bus.p.fname);
                        } else {
                            printf("%2d.Available   ", A + 1);
                        }
                        A++;
                    }
                }
                for (sideB = 1; sideB <= 2; sideB++) {
                    if (bus.flagB[B] == 1) {
                        printf("%2d.%-12s", B + 1,bus.p.fname);
                    } else {
                        printf("%2d.Available   ", B + 1);
                    }
                    B++;
                }
                printf("\n\n");
            }
            
            break;
        }
    }
    
    if (found == 0) {
        printf("\t\tBus not found ");
    }
    
    fclose(fp);
    
    // Move add_passenger call outside the loop
    if (found==1){
        add_passenger(search);
    }
}

void add_passenger(char search[]) {
    bus_details bus;
    char a = 'a';
    char b = 'b';
    int i;
    int booked;
    int found = 0;
    int add_more = 0,d=0;
    FILE *fp, *temp;
    
    fp = fopen("Bus_reservation.txt", "r+");
    temp = fopen("temp.txt","w+");
    
    if (fp == NULL || temp == NULL) {
        printf("Error opening files.\n");
        exit(1);
    }

  do{
  		
        if (strcmp(search, bus.bus_num) == 0) {
            found = 1;
            do{
            	
            	printf("\tEnter passenger details\n");
				printf("\tName: ");
				scanf("%s %s",bus.p.fname,bus.p.lname);
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
				while(bus.p.no_of_seats>5){
					printf("\n\tmaximum booking exceeded enter below 6\n\t");
					scanf("%d",&bus.p.no_of_seats);
				}
				printf("\n\tEnter Side and seat no\n");
				for(i=0;i<bus.p.no_of_seats;i++){
					booked=0;				
					do{
						printf("\t");
						scanf("%c %d",&bus.p.side[i],&bus.p.seats[i]);
						if(*bus.p.side == a)
						{
						
							if(bus.flagA[bus.p.seats[i]-1] == 1 ){
								printf("\tthe seat is already booked\nselect other: \n");
							}else{
								bus.flagA[bus.p.seats[i]-1] = 1;
								printf(" booked \n");
								booked=1;
							}
						}
						if(*bus.p.side == b){
							if(bus.flagB[bus.p.seats[i]-1] == 1 ){
								printf("\tthe seat is already booked\nselect other: \n");
							}else{
								bus.flagB[bus.p.seats[i]-1] = 1;
								printf(" booked\n");
								booked=1;
							}									
						}

					}while(!booked);											
				}
				bus.p.total=bus.p.no_of_seats*bus.ticket_price;
				printf("\n\ttotal amount: %d\n",bus.p.total);
				printf("\tPayment(1 for paid || 0 for pending) ");
				scanf("%d",&bus.p.payment);
				
				fwrite(&bus, sizeof(bus_details), 1, temp);
				printf("\n\tAdd More?? (1 for Yes | 0 for No): ");
				scanf("%d",&add_more);
				
			} while( add_more == 1);
        }
		else{
	        fwrite(&bus, sizeof(bus_details), 1, temp);
	    }

    }while(fread(&bus, sizeof(bus_details), 1, fp) !=0);
    
    if (!found) {
        printf("\tBus not found.\n");
    }
    
    fclose(fp);
    fclose(temp);

    // Replace the original file with the temporary file
    remove("Bus_reservation.txt");
    rename("temp.txt", "Bus_reservation.txt");
}

void cancel(){
    char search_bus[20];
    char side;
    int seat;
    bus_details bus;
    int found = 0;

    FILE *fp, *temp;
    fp = fopen("Bus_reservation.txt", "r");
    temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL) {
        printf("\tError opening File");
        exit(0);
    }

    printf("\tEnter the Bus number: ");
    scanf("%19s", search_bus);
    printf("\n\tEnter side and seat: ");
    scanf(" %c %d", &side, &seat);

    while (fread(&bus, sizeof(bus_details), 1, fp) != 0) {
        if (strcmp(bus.bus_num, search_bus) == 0) {
            if ((side == 'a') && (bus.flagA[seat - 1] == 1) ) {
                bus.flagA[seat - 1] = 0;
                found = 1;
                
                fwrite(&bus, sizeof(bus_details), 1, temp);
            } else if ((side == 'b') && (bus.flagB[seat - 1] ==1)) {
                bus.flagB[seat - 1] = 0;
                found = 1;
                fwrite(&bus, sizeof(bus_details), 1, temp);
            }
        }
        else{
        	fwrite(&bus, sizeof(bus_details), 1, temp);
		}
    }

    fclose(fp);
    fclose(temp);

    if (found) {
        remove("Bus_reservation.txt");
        rename("temp.txt", "Bus_reservation.txt");
        printf("\tBooking canceled successfully\n");
    } else {
        remove("temp.txt"); // Delete the temporary file if bus not found
        printf("\tSeats not found in records or input is invalid.\n");
    }
}
void display_revenue(){
	
	int i,j=1;
	int revenue=0,count=0;
	FILE *fp;
	bus_details bus;
	fp=fopen("Bus_reservation.txt", "r");
	printf("\n\tS.N\tName\t\tNumber\t\trevenue\n");
	do{
		fread(&bus, sizeof(bus_details), 1, fp);
		for(i=0;bus.flagA[i];i++){
			if(bus.flagA[i]==1){
				count++;
			}
		}
		for(i=0;bus.flagB[i];i++){
			if(bus.flagB[i]==1){
				count++;
			}
		}
		printf("%d  ",bus.ticket_price);
		revenue=bus.ticket_price * count;
		printf("\t%d\t%-10s\t%-10s\t%-15d\n",
			j,
			bus.name,
			bus.bus_num,
			revenue
		);
		j++;
	}while (fread(&bus, sizeof(bus_details), 1, fp) != 0);
	fclose(fp);
}
