/* File: treemanagement.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tnode *Treeptr;

typedef struct tnode {
  char *word;
  Treeptr left;
  Treeptr right;
} Treenode;

Treeptr addtree(Treeptr, char *);
void treeprint(Treeptr, int);
void nodesprint(Treeptr);
int treedepth(Treeptr);
int treesearch(Treeptr, char *);

int main(int argc, char *argv[])
{ Treeptr p;
  char buf[80];
  p = NULL;                              /* Initialize binary tree */
  while (scanf("%s", buf) != EOF)         /* Read words from input */
    p = addtree(p, buf);          /* and insert them into the tree */
  printf("Tree is:\n"),
  treeprint(p, 0);                 /* Kind of tree pretty printing */
  printf("\nNodes are:\n");
  nodesprint(p);         /* Print tree nodes in alphabetical order */
  printf("\n\nTree depth is %d\n", treedepth(p));
                                /* Compute and print depth of tree */
  printf("\n");
  while (--argc) {                            /* For each argument */
    argv++;       /* check whether it coincides with any tree node */
    printf("%s found %s\n",
           (treesearch(p, *argv)) ? "   " : "not", *argv);
  }
}

Treeptr addtree(Treeptr p, char *w)   /* Insert word w into tree p */
{ int cond;
  if (p == NULL) {                             /* If tree is empty */
    p = malloc(sizeof(Treenode));   /* Allocate space for new node */
                                    /* Allocate space to copy word */
    p->word = malloc((strlen(w)+1) * sizeof(char));
    strcpy(p->word, w);                /* Copy word w to tree node */
    p->left = NULL;           /* Left subtree of new node is empty */
    p->right = NULL;         /* Right subtree of new node is empty */
  }
  else if ((cond = strcmp(w, p->word)) < 0)
                      /* Does word w precede word of current node? */
    p->left = addtree(p->left, w);
                            /* If yes, insert it into left subtree */
  else if (cond > 0)       /* Does it follow word of current node? */
    p->right = addtree(p->right, w);
                           /* If yes, insert it into right subtree */
  /* If it is the same with word of current node, do not insert it */
  return p;                                         /* Return tree */
}

void treeprint(Treeptr p, int indent)         /* Pretty print tree */
{ int i;
  if (p != NULL) {                         /* If tree is not empty */
    treeprint(p->right, indent+4);
                /* Print right subtree 4 places right of root node */
    for (i=0 ; i < indent ; i++)
      printf(" ");                    /* Take care for indentation */
    printf("%s\n", p->word);                    /* Print root node */
    treeprint(p->left, indent+4);
                 /* Print left subtree 4 places right of root node */
  }
}

void nodesprint(Treeptr p)                     /* Print tree nodes */
{ if (p != NULL) {                         /* If tree is not empty */
    nodesprint(p->left);                     /* Print left subtree */
    printf("%s ", p->word);                     /* Print root node */
    nodesprint(p->right);                   /* Print right subtree */
  }
}

int treedepth(Treeptr p)                /* Compute depth of tree p */
{ int n1, n2;
  if (p == NULL)                       /* Depth of empty tree is 0 */
    return 0;
  n1 = treedepth(p->left);        /* Compute depth of left subtree */
  n2 = treedepth(p->right);      /* Compute depth of right subtree */
  return (n1 > n2) ? n1+1 : n2+1;
     /* Return maximun of depths of left and right subtrees plus 1 */
}

int treesearch(Treeptr p, char *w)
                              /* Check whether word w is in tree p */
{ int cond;
  if (p == NULL)                               /* If tree is empty */
    return 0;                               /* We didn't find word */
  if ((cond = strcmp(w, p->word)) == 0)
                   /* Word w is the same with word of current node */
    return 1;
  else if (cond < 0)         /* If w precedes word of current node */
    return treesearch(p->left, w);          /* Search left suftree */
  else                                                /* Otherwise */
    return treesearch(p->right, w);        /* search right subtree */
}
