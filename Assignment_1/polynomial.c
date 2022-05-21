#include "polynomial.h"

void insert_node(Polyhead *poly, int coef, int exp)
{
    Polynode *new_node = (Polynode *)malloc(sizeof(Polynode));
    if (new_node == NULL)
        return insert_node(poly, coef, exp);
    new_node->coef = coef;
    new_node->exp = exp;
    new_node->link = NULL;

    if (poly->head == NULL)
        poly->head = poly->tail = new_node;
    else
    {
        poly->tail->link = new_node;
        poly->tail = new_node;
    }
    poly->length++;
}

void create_poly(FILE *file, Polyhead *poly1, Polyhead *poly2)
{
    //Need to Fix
    int coef, exp;
    char buf[MAX] = {};

    while (buf[0] != '\n')
    {
        fgets(buf, MAX, file);
        sscanf(buf, "%d %d", coef, exp);
        insert_node(poly1, coef, exp);        
    }
    while (fgets(buf, MAX, file)){
        sscanf(buf, "%d %d", coef, exp);
        insert_node(poly2, coef, exp); 
    }

    return;
}


void print_poly()
{

}

void delete_poly()
{

}