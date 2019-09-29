#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pnode    {
	struct pnode *prev;
	char *name;
	float balance;
	struct pnode *next;
				};

struct pnode *root = NULL,
			 *lptr,
			 *sptr;

void menu(void);
void process (char *customer);
void add(char *customer);
void close (char *customer);
void neighbor (char *customer);
void printlist(void);

int main(void)
{
	char choice;
	char customer[25];

	menu();
	scanf("%c",&choice);

	while (1)
	{
		switch (choice)
		{
		case '1':
			printf("\nPlease enter a customer name (last,first,middle):  ");
			scanf("%s",customer);
			process(customer);
			break;
		case '2':
			printf("\nPlease enter a customer name (last,first,middle):  ");
			scanf("%s",customer);
			add(customer);
			break;
		case '3':
			printf("\nPlease enter a customer name (last,first,middle):  ");
			scanf("%s",customer);
			close(customer);
			break;
		case '4':
			printlist();
			break;
		case '5':
			printf("\nPlease enter a customer name (last,first,middle):  ");
			scanf("%s",customer);
			neighbor(customer);
			break;
		case '6':
			goto out;
			break;
		default:
			printf("\nPlease enter a 1,2,3,4,5, or 6 only!\n");
			break;
		}

	menu();
	scanf("%c",&choice);
	while (choice == '\n')
	{scanf("%c",&choice);}

	}

out: printf("\n");
return 0;
}


void menu(void)
{
	printf("\n\n");
	printf("Doubly Linked List Maintenance Menu\n\n");
	printf("1.    Process a Transaction\n");
	printf("2.    Add a New Customer\n");
	printf("3.    Close an Account\n");
	printf("4.    Print a List of All Customers\n");
	printf("5.    Get the Neighbors of a Customer\n");
	printf("6.    Exit the Program\n\n");
	printf("What is Your Choice?  ");
	
	return;
}

void process(char *customer)
{
	int i;
	float amount;
	lptr = root;

	while (lptr != NULL)
	{
		i = strcmp(lptr->name, customer);

		if (i < 0)
			{lptr = lptr->next;}
		else if (i == 0)
		{
			printf("Please enter a withdrawal amount (ex. 20.00):  ");
			scanf("%f",&amount);
			lptr->balance = lptr->balance - amount;
			printf("Customer %s new balance is $%6.2f.\n",customer, lptr->balance);
			return;
		}
		else
		{break;}
	}

	printf("Customer %s does not exist in the list \n", customer);
	return;
}

void add(char *customer)
{
	int i; 
	int j = 1;
	float amount;
	lptr = root;
	

	while (1)
	{
		if (lptr != NULL)
		{i = strcmp(lptr->name, customer);}

		if (root == NULL)
		{
		printf("Please enter a beginning balance (ex. 20.00):  ");
		scanf("%f",&amount);
		sptr = (struct pnode *) malloc(sizeof(struct pnode));
		sptr->name = (char *) malloc(strlen(customer) + 1);
		strcpy(sptr->name, customer);
		sptr->balance = amount;
		root = sptr;
		sptr->next = NULL;
		sptr->prev = NULL;
		return;
		}
		else if (i > 0 && j == 1)
		{
		printf("Please enter a beginning balance (ex. 20.00):  ");
		scanf("%f",&amount);
		sptr = (struct pnode *) malloc(sizeof(struct pnode));
		sptr->name = (char *) malloc(strlen(customer) + 1);
		strcpy(sptr->name, customer);
		sptr->balance = amount;
		root = sptr;
		sptr->next = lptr;
		sptr->prev = NULL;
		(sptr->next)->prev = sptr;
		return;
		}
		else if (i > 0 && j > 1)
		{
		printf("Please enter a beginning balance (ex. 20.00):  ");
		scanf("%f",&amount);
		sptr = (struct pnode *) malloc(sizeof(struct pnode));
		sptr->name = (char *) malloc(strlen(customer) + 1);
		strcpy(sptr->name, customer);
		sptr->balance = amount;
		sptr->prev = lptr->prev;
		sptr->next = (sptr->prev)->next;
		(sptr->prev)->next = sptr;
		(sptr->next)->prev = sptr;
		return;
		}
		else if ((i < 0) && (lptr->next == NULL))
		{
		printf("Please enter a beginning balance (ex. 20.00):  ");
		scanf("%f",&amount);
		sptr = (struct pnode *) malloc(sizeof(struct pnode));
		sptr->name = (char *) malloc(strlen(customer) + 1);
		strcpy(sptr->name, customer);
		sptr->balance = amount;
		sptr->next = NULL;
		sptr->prev = lptr;
		(sptr->prev)->next = sptr;
		return;
		}
		else if (i == 0)
		{
		printf("Customer %s already exists in list!\n", customer);
		return;
		}
		else
		{lptr = lptr->next;
		j = j + 1;}
	}
	
}

void close (char *customer)
{
	int i;
	int j = 1;

	lptr = root;
	while (lptr != NULL)
	{
		i = strcmp (lptr->name, customer);
		if (lptr->next != NULL)
		{
			if (i < 0)
				{lptr = lptr->next;
				j = j + 1;}
			else if (i == 0 && j == 1)
				{printf("Closing Balance is $%6.2f. Thank You!", lptr->balance);
				root = lptr->next;
				(lptr->next) -> prev = NULL;
				free (lptr);
				return;}
			else if (i == 0 && j > 1)
				{printf("Closing Balance is $%6.2f. Thank You!", lptr->balance);
				(lptr->prev)->next = lptr->next;
				(lptr->next)->prev = lptr->prev;
				free (lptr);
				return;}
			else
				{break;}
		}
		else if (lptr->next == NULL)
		{
			if (i < 0)
				{break;}
			else if (i == 0 && j == 1)
				{printf("Closing Balance is $%6.2f. Thank You!", lptr->balance);
				root = NULL;
				free (lptr);
				return;}
			else if (i == 0 && j > 1)
				{printf("Closing Balance is $%6.2f. Thank You!", lptr->balance);
				(lptr->prev)->next = NULL;
				free (lptr);
				return;}
			else 
				{break;}
		}
	}
	printf("Customer %s does not exist in list \n", customer);
	return;
}

void neighbor(char *customer)
{
	int i;
	int j = 1;
	char noword[] = {"Neighbor Does Not Exist"};

	lptr = root;
	while (lptr != NULL)
	{
		i = strcmp(lptr->name,customer);
		if(i < 0)
			{lptr = lptr->next;
			j = j + 1;}
		else if (i == 0 && j == 1 && lptr->next == NULL)
			{printf("Preceding %s \n",noword);
			printf("Customer              = %s \n", customer);
			printf("Following %s \n",noword);
			return;}
		else if (i == 0 && j == 1 && lptr->next != NULL)
			{printf("Preceding %s \n",noword);
			printf("Customer              = %s \n", customer);
			printf("Following Neighbor    = %s \n",(lptr->next)->name);
			return;}
		else if (i == 0 && j > 1 && lptr->next != NULL)
			{printf("Preceding Neighbor    = %s \n",(lptr->prev)->name);
			printf("Customer              = %s \n", customer);
			printf("Following Neighbor    = %s \n",(lptr->next)->name);
			return;}
		else if (i == 0 && j > 1 && lptr->next == NULL)
			{printf("Preceding Neighbor   = %s \n", (lptr->prev)->name);
			printf("Customer              = %s \n", customer);
			printf("Following %s \n",noword);
			return;}
		else
			{break;}
	}
	printf("Customer = %s does not exist in the list \n",customer);
	return;
}

void printlist(void)
{
	lptr = root;

	printf("The Current Customers in the list are:  \n");
	printf("Name                             Balance\n");
	printf("----                             -------\n\n");

	if (lptr != NULL)
	{
		while (lptr != NULL)
		{
			printf("%-25s        $  %6.2f\n", lptr->name, lptr->balance);
			lptr = lptr->next;
		}
		return;
	}
	else
	{
		printf("No Customers to Print, Please Add or Exit!\n");
		return;
	}
	
}

