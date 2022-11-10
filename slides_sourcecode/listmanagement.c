/* File: listmanagement.c */
#include <stdio.h>
#include <stdlib.h>

typedef struct listnode *Listptr;

struct listnode {
  int value;
  Listptr next;
};

int empty(Listptr);
int in(Listptr, int);
int n_th(Listptr, int, int *);
void insert_at_start(Listptr *, int);
void insert_at_end(Listptr *, int);
int delete(Listptr *, int);
void print(Listptr);

int main(void)
{ Listptr alist;
  int v;
  alist = NULL;                                     /* List is NULL */
                                          /* Check if list is empty */
  printf("List is%s empty\n", empty(alist) ? "" : " not");
  insert_at_start(&alist, 44);                /* List is 44--> NULL */
  printf("List is "); print(alist);
  insert_at_end(&alist, 55);            /* List is 44--> 55--> NULL */
  printf("List is "); print(alist);
  insert_at_start(&alist, 33);     /* List is 33--> 44-> 55--> NULL */
  printf("List is "); print(alist);
  insert_at_end(&alist, 66); /* List is 33--> 44-> 55--> 66--> NULL */
  printf("List is "); print(alist);
                                          /* Check if list is empty */
  printf("List is%s empty\n", empty(alist) ? "" : " not");
                                                /* Check membership */
  printf("55 is%s in list\n", in(alist, 55) ? "" : " not");
  printf("77 is%s in list\n", in(alist, 77) ? "" : " not");
  if (n_th(alist, 2, &v))                     /* Return 2nd element */
    printf("Item no 2 is %d\n", v);
  else
    printf("Item no 2 does not exist\n");
  if (n_th(alist, 6, &v))                     /* Return 6th element */
    printf("Item no 6 is %d\n", v);
  else
    printf("Item no 6 does not exist\n");
  printf("Deleting 55. %s\n", delete(&alist, 55) ? "OK!" : "Failed!");
                                  /* List is 33--> 44--> 66--> NULL */
  printf("List is "); print(alist); 
  printf("Deleting 22. %s\n", delete(&alist, 22) ? "OK!" : "Failed!");
                                  /* List is 33--> 44--> 66--> NULL */
  printf("List is "); print(alist);
  printf("Deleting 33. %s\n", delete(&alist, 33) ? "OK!" : "Failed!");
                                        /* List is 44--> 66--> NULL */
  printf("List is "); print(alist);
  return 0;
}

int empty(Listptr list)                   /* Check if list is empty */
{ if (list == NULL)                          /* Is it really empty? */
    return 1;                                         /* Yes, it is */
  else
    return 0;                                       /* No, it isn't */
}

int in(Listptr list, int v)         /* Check if v is member of list */
{ while (list != NULL)         /* Visit list elements up to the end */
    if (list->value == v)   /* Did we find what we are looking for? */    
      return 1;                                      /* Yes, we did */
    else
      list = list->next;                  /* No, go to next element */
  return 0;                            /* Finally, v is not in list */
}

int n_th(Listptr list, int n, int *vaddr)
           /* Return n-th element of list, if it exists, into vaddr */
{ while (list != NULL)    /* Maybe search up to the end of the list */
    if (n-- == 1) {              /* Did we reach the right element? */
      *vaddr = list->value;                       /* Yes, return it */
      return 1;                                      /* We found it */
    }
    else
      list = list->next;                  /* No, go to next element */
  return 0;                             /* Sorry, list is too short */
}

void insert_at_start(Listptr *ptraddr, int v)
                      /* Insert v as first element of list *ptraddr */
{ Listptr templist;
  templist = *ptraddr;                /* Save current start of list */
  *ptraddr = malloc(sizeof(struct listnode)); /* Space for new node */
  (*ptraddr)->value = v;                               /* Put value */
  (*ptraddr)->next = templist;      /* Next element is former first */
}

void insert_at_end(Listptr *ptraddr, int v)
                       /* Insert v as last element of list *ptraddr */
{ while (*ptraddr != NULL)                     /* Go to end of list */
    ptraddr = &((*ptraddr)->next);/* Prepare what we need to change */
  *ptraddr = malloc(sizeof(struct listnode)); /* Space for new node */
  (*ptraddr)->value = v;                               /* Put value */ 
  (*ptraddr)->next = NULL;              /* There is no next element */
}

int delete(Listptr *ptraddr, int v)
               /* Delete element v from list *ptraddr, if it exists */
{ Listptr templist;
  while ((*ptraddr) != NULL)   /* Visit list elements up to the end */
    if ((*ptraddr)->value == v) {    /* Did we find what to delete? */
      templist = *ptraddr;         /* Yes, save address of its node */
      *ptraddr = (*ptraddr)->next;        /* Bypass deleted element */
      free(templist);     /* Free memory for the corresponding node */
      return 1;                           /* We deleted the element */
    }
    else
      ptraddr = &((*ptraddr)->next);/* Prepare what we might change */
  return 0;        /* We did't find the element we were looking for */
}

void print(Listptr list)                  /* Print elements of list */
{ while (list != NULL) {       /* Visit list elements up to the end */
    printf("%d--> ", list->value);         /* Print current element */
    list = list->next;                        /* Go to next element */
  }
  printf("NULL\n");                            /* Print end of list */
}
