#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


typedef struct LIST
{
	int value;
	struct LIST *next;
} list;

list *head = NULL;
int n = 0;

void add(int value, int index);
void del(int index);
void show(int index);
void error(char type);
void printing(int value, int index);
void message(char select);
void clear(void);


int main(void)
{
	char opr[8];
	int value, index;
	message('h');
	while (1)
	{
		fflush(stdin);
		scanf("%s", opr);
		if (0 == strcmp(opr, "help"))
		{
			message('h');
		}
		else if (0 == strcmp(opr, "add"))
		{
			if (0)
			{
				error('a');
				continue;
			}
			else
			{
				scanf("%d", &value);
				if (0)
				{
					error('a');
					continue;
				}
				else
				{
					scanf("%d", &index);
					if (0)
					{
						error('a');
						continue;
					}
					else
					{
						add(value, index);
					}
				}
			}
		}
		else if (0 == strcmp(opr, "del"))
		{
			if (0)
			{
				error('a');
				continue;
			}
			else
			{
				scanf("%d", &index);
				if (0)
				{
					error('a');
					continue;
				}
				else
				{
					del(index);
					continue;
				}
			}
		}

		else if (0 == strcmp(opr, "show"))
		{
			if (0)
			{
				error('a');
				continue;
			}
			else
			{
				scanf("%d", &index);
				if (0)
				{
					error('a');
					continue;
				}
				else
				{
					show(index);
					continue;
				}
			}
		}
		else if (0 == strcmp(opr, "end"))
		{
			clear();
			return 0;
		}
		else
		{
			error('o');
			continue;
		}

	}
	return 0;
}


void add(int value, int index)
{

	if (index < 1)
	{
		if (index == 0)
		{
			if (head == NULL)
			{
				head = (list *)malloc(sizeof(list));
				head->value = value;
				head->next = NULL;
			}
			else
			{
				list *tmp = head;
				head = (list *)malloc(sizeof(list));
				head->next = tmp;
				head->value = value;
			}
		}
		else
		{
			if (head != NULL){
				list *current;
				for (current = head; current->next != NULL;
					current = current->next);
					current->next = (list *)malloc(sizeof(list));
				current = current->next;
				current->value = value;
				current->next = NULL;
			}
			else
			{
				head = (list*)malloc(sizeof(list));
				head->next = NULL;
				head->value = value;
			}
		}
	}
	else
	{
		if (index > n)
		{
			error('l');
			return;
		}

		else
		{
			int i;
			list *current, *tmp;
			current = head;
			for (i = 1; i < index; current = current->next, i++);
			tmp = current->next;
			current->next = (list *)malloc(sizeof(list));
			current = current->next;
			current->value = value;
			current->next = tmp;
		}
	}
	n++;
	return;
}

void del(int index)
{
	if (n == 0)
	{
		error('x');
		return;
	}

	else if (index > n)
	{
		error('l');
		return;
	}
	else if (index < 1)
	{
		clear();
		return;
	}

	else if (index > n)
	{
		error('l');
		return;
	}

	else if (n == 1)
	{
		free(head);
		head = NULL;
	}
	else
	{
		int i;
		list *current, *tmp;
		current = head;

		for (i = 2; i < index; i++, current = current->next);
		tmp = current->next->next;
		free(current->next);
		current->next = tmp;
	}
	n--;
	return;
}

void show(int index)
{
	if (n == 0)
	{
		error('x');
		return;
	}

	if (index == 0)
	{
		list *current;
		int i;
	

		for (current = head, i = 1; current != NULL; current = current->next, i++)
		{
			printing(current->value, i);
		}
	}
	else if (index < 0)
	{
		error('a');
		return;
	}
	else if (index > n)
	{
		error('l');
		return;
	}
	else
	{
		list *current;
		int i;
		for (i = 1, current = head; i < index; i++, current = current->next);
		printing(current->value, i);
	}
	return;
}

void error(char type)
{
	printf("\nError! ");
	switch (type)
	{
	case 'a':
		printf("Wrong Algument. Please check 'help'\n\n");
		break;
	case 'o':
		printf("Wrong Operation. Please check 'help'\n\n");
		break;
	case 'l':
		printf("List is shorter than you entered.\n\n");
		break;
	case 'x':
		printf("There is no list.\n\n");
		break;
	default:
		error('a');
		break;
	}
}

void printing(int value, int index)
{
	if (index == 1)
	{
		printf(" 1st value is %d\n", value);
	}
	else if (index == 2)
	{
		printf(" 2nd value is %d\n", value);
	}
	else if (index == 3)
	{
		printf(" 3rd value is %d\n", value);
	}
	else
	{
		printf("%2dth value is %d\n", index, value);
	}
}

void message(char select)
{
	switch (select)
	{
	case 'h':
		printf(
			"add value k : add value after kth of list. ex) \"add 3 5\" make list \"1 2 3 4\" to \"1 2 3 5 4\"\n"
			"	Option\n"
			"	if k is 0, value is added before head\n"
			"		ex) \"add 3 0\" command add value 3 to head of list\n"
			"	if k is smaller than 0, value is added to end of the list\n\n"
			"del k : delete kth list\n"
			"	Option\n"
			"	if k is 0, clear all list\n"
			"	if k is smaller than 0, delete end of list\n\n"
			"show k : show kth list\n"
			"	Option\n"
			"	if k is 0, show all\n"
			"	if k is smaller than 0, show end of list\n\n"
			"end : end program\n\n"
			"help : show this help message\n\n"
			);
		break;
	}
	return;
}

void clear(void)
{
	list *current, *next;
	current = head;
	next = NULL;
	if (current != NULL){
		do
		{
			next = current->next;
			free(current);
			current = next;
		} while (current != NULL);
		head = NULL;
		n = 0;
	}
	return;
}
