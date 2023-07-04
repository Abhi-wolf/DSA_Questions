#include <stdio.h>
#include <stdlib.h>

//  THE MATRIX WHICH HAS A GRATER NUMBER OF ZERO VALUES IN COMPARISON TO THE NON-ZERO VALUES
//      IS KNOWN AS A SPARSE MATRIX

struct Element 
{
    int i;      // row no of the element
    int j;      // column no of the element
    int x;      // value of the element
};

struct Sparse
{
    int m;      // no of rows of the matrix
    int n;      // no of columns of the matrix
    int num;    // no of elements of the matrix which are non-zero
    struct Element *ele;    //pointer to the element
};



void Create(struct Sparse *s)
{
    int i;
    printf("Enter the dimensions of the Matrix : ");
    scanf("%d%d",&s->m,&s->n);
    printf("Enter number of non-zero elements : ");
    scanf("%d",&s->num);

    s->ele=(struct Element *)malloc((s->num)*sizeof(struct Element));

    printf("Enter non-zero elements\n");
    for(i=0;i<s->num;i++)
    {
        scanf("%d%d%d",&s->ele[i].i,&s->ele[i].j,&s->ele[i].x);
    }
}

void Display (struct Sparse s)
{
    int i,j,k=0;
    printf("\n\tSparse Matrix \n");
    for(i=0;i<s.m;i++)
    {
        for(j=0;j<s.n;j++)
        {
            if(i==s.ele[k].i && j==s.ele[k].j)
                printf("%d ",s.ele[k++].x);
            else    
                printf("0 ");
        }
        printf("\n");
    }
}


struct Sparse * Add(struct Sparse *s1,struct Sparse *s2)
{
    struct Sparse *sum;
    int i,j,k;
    i=j=k=0;
    sum=(struct Sparse *)malloc(sizeof(struct Sparse));

    if(s1->m != s2->m  && s1->n != s2->n)
        return NULL;

        sum->ele=(struct Element *)malloc((s1->num+s2->num)*sizeof(struct Element));
        while(i<s1->num && j<s2->num)
        {
            if(s1->ele[i].i < s2->ele[j].i)
                sum->ele[k++]=s1->ele[i++];
            else if(s1->ele[i].i > s2->ele[j].i)
                sum->ele[k++]=s2->ele[j++];
            else
            {
                if(s1->ele[i].j < s2->ele[j].j)
                    sum->ele[k++]=s1->ele[i++];
                else if(s1->ele[i].j > s2->ele[j].j)
                sum->ele[k++]=s1->ele[j++];
                else
                {
                    sum->ele[k]=s1->ele[i];
                    sum->ele[k++].x=s1->ele[i++].x + s2->ele[j++].x;
                }
            }
        }
        for(;i<s1->num;i++) sum->ele[k++]=s1->ele[i];
        for(;j<s2->num;j++) sum->ele[k++]=s2->ele[j];
        sum->m=s1->m;
        sum->n=s1->n;
        sum->num=k;
        return sum;
    }


int main()
{
    struct Sparse s1,s2,*s3;
    Create(&s1);
    Create(&s2);
    s3=Add(&s1,&s2);
    Display(s1);
    Display(s2);
    Display(*s3);
    return 0;
}