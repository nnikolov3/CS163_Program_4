/* Nikolay Nikolov
   CS163
Instructor:Karla Fant
Program # 4
Purpose of the program: 

The program's utilizes BST to  store, retrieve,
delete and display a list of games and their peripheral information from external file.
In addition, the user will be able to insert, and update the list with the games. 
The main concept of the assignment is the same as for Program # 3.

This is the header file for the Binary Search Tree ADT.

A computer science student is studying under a tree
and another pulls up on a flashy new bike. 
The first student asks, “Where’d you get that?”
The student on the bike replies,
“While I was studying outside, a beautiful girl pulled up on her bike. 
She took off all her clothes and said, ‘You can have anything you want’.”
The first student responds, “Good choice! Her clothes probably wouldn’t have fit you.”

*/

#include<iostream>
#include<cctype>
#include<cstring>

struct data 
{
    data();
    ~data();
    int data_display();
    char * name ;
    char * description;
    char * type ;
    char * platform;
    int rating ;
    char * comment ;

};

struct node
{
    node();
    data  info;
    node * left ;
    node * right;
    ~node();

};
class BST
{
    public:

        BST() ;
        ~BST () ;
        //insert
        int insert_wrapper(char * aname,char * adescription, char * atype, char * aplatform, int arating,char * acomment) ;//insert wrapper
        //copy
        int copy (node * & root ,char * aname,char * adescription, char * atype, char * aplatform, int arating,char * acomment); //copy
        int get_height_wrapper();
        int count_wrapper();
        int read_file(char * aname, char * adescription,char * atype, char * aplatform, int arating,char * acomment) ;
        //remove functions 
        int remove_all_wrapper();
        int remove_one_wrapper(char * aname, char * aplatform);
        //display functions
        int display_all_wrapper(); 
        int display_range_wrapper(char * index, char * index_2);
        //retrieve 
        int retrieve_wrapper(char * aname,data & info);
        
    private:
        //display functions 
        int display_range ( node * root,char * index, char * index_2) ;
        int display_all(node * root) ;

        node * minVal (node * & root); // find the smallest value of the right  tree
        //remove functions
        int remove_one(node *& root, char * aname, char * aplatform);
        int remove_all(node *& root) ;
        int retrieve( node *  root,char *   aname , data & info) ;
        int get_height(node * root) ;
        int count(node * root) ;
        int insert(node * &  root,char * aname,char * adescription, char * atype, char * aplatform, int arating,char * acomment);
        node * root ;
        
};	 
