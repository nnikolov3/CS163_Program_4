/* Nikolay Nikolov
   CS163
Instructor:Karla Fant
Program # 4
Purpose of the program: 

The program's utilizes BST to  store, retrieve, delete and display a list of 
games and their peripheral information from external file.
In addition, the user will be able to insert, and update the list with the games. 
The main concept of the assignment is the same as for Program # 3.

This is the .cpp  file for the BST ADT .

*/
#include"bst.h"
#include<fstream>


using namespace std; 

data :: data () // constructor
{
    name = NULL;
    description = NULL;
    type = NULL;
    platform = NULL ;
    rating = 0;
    comment = NULL;
}

data :: ~data () // destructor
{
    if( name)
        delete []name ;

    if(description)
        delete [] description;

    if (type)
        delete [] type ;

    if (platform)
        delete []platform;

    if (comment)
        delete [] comment ;

    name = NULL ;
    description = NULL ;
    type = NULL ;
    platform = NULL ;
    rating  = 0 ;
    comment  = NULL ;
}

int data :: data_display () // the function to display 
{
    cout<<"\t\t|"<<"------------------------------------------------------------------"<< endl ;
    cout<<"\t\t|"<<"The name is          :" << name 	    	      << endl;
    cout << endl;
    cout<<"\t\t|"<<"The desscription is  :" << description        << endl;
    cout << endl;
    cout<<"\t\t|"<<"The type is          :" << type               << endl;
    cout << endl;
    cout<<"\t\t|"<<"The platform is      :" << platform           << endl;
    cout << endl;
    cout<<"\t\t|"<<"The rating is        :" << rating             << endl;
    cout << endl;
    cout<<"\t\t|"<<"The comment is       :" << comment             << endl;	
    cout << endl;
    cout<<"\t\t|" <<"------------------------------------------------------------------"<< endl;

    return 0;

}
//------------------------data struct ends here ---------------------------------
//-------------------------------------------------------------------------------
node :: node() // constructors for the node
{
    left = NULL;
    right = NULL ;

}
node :: ~node () // destructor 
{
    left = NULL;
    right = NULL;

}

//-------------------------------------------------- node struct -- ends here
BST :: BST () //constructor for the BST class
{
    root = NULL;
}

BST :: ~BST() // destructor for the BST class
{
    remove_all(root) ;// remove all function call
}

int BST :: insert_wrapper(char * aname,char * adescription, char * atype, char * aplatform, int arating,char * acomment) //wrapper for the insert function
{
    return insert(root,aname, adescription,atype,aplatform,arating,acomment) ;// calling the insert function
}

int BST :: copy(node * & root,char * aname,char * adescription, char * atype, char * aplatform, int arating,char * acomment)// the function to do the deep copy in the info object in the node
{

    if (root ->info.name) 
        delete [] root ->info.name ;

    if (root ->info.description) 
        delete [] root ->info.description ;

    if (root ->info.type) 
        delete [] root ->info.type ;

    if(root ->info.platform) 
        delete [] root ->info.platform ;

    if (root ->info.comment) 
        delete [] root ->info.comment ;

    root ->info.name = NULL ;
    root ->info.description = NULL ;
    root ->info.type = NULL ;
    root ->info.platform = NULL ;
    root ->info.comment = NULL ;
    root ->info.rating = 0;

    if(aname){
        root -> info.name = new char [strlen(aname)+1];
        strcpy(root ->info.name,aname);
    }
    if(adescription)
    {
        root -> info.description  = new char [strlen(adescription)+1];
        strcpy(root ->info.description,adescription);
    }
    if (atype)
    {
        root -> info.type = new char [strlen(atype)+1];
        strcpy(root ->info.type,atype);
    }
    if (aplatform)
    {
        root -> info.platform = new char [strlen(aplatform)+1];
        strcpy(root ->info.platform,aplatform);
    }
    if(acomment)
    {
        root -> info.comment = new char [strlen(acomment)+1];
        strcpy(root ->info.comment,acomment);
    }

    root -> info.rating = arating ;



    return 1;
} 



int BST :: insert(node * & root,char * aname,char * adescription, char * atype, char * aplatform, int arating,char * acomment) // function to insert in the BST
{		
    if(!root) // if the list is empty 
    {
        root= new node ;
        copy(root,aname,adescription,atype,aplatform,arating,acomment);	 // deep copy 	
        root -> left  = NULL ;
        root -> right = NULL ;

        return true;
    }
    else if  (strcmp (root -> info.name,aname) < 0) // go to the right if the value is larger
    {
        return insert ( root -> left,aname,adescription,atype,aplatform,arating,acomment);
    }
    else if (strcmp (root -> info.name,aname) >= 0) // go to the left if the value is smaller
    {
        return insert ( root -> right ,aname,adescription,atype,aplatform,arating,acomment);
    }

    return 0;

}

int BST :: display_range_wrapper (char * index,  char * index_2)
{
    return display_range(root, index ,index_2 ) ;
}

int BST :: display_range(node * root , char * index, char * index_2)
{ 
    if (!root) // if the list is empty 
        return 0;

    if (root ->info.name[0] < index [0]) // if the first letter is before the one we are looking for  
    {
        return display_range(root->right, index,index_2); // traverse to the right to find the letter

    } else  if((root->info.name[0]  >= index[0]) && ( root ->info.name[0] <= index_2[0])) // if the query is between the first letter and the last letter asked
    {   // pre order traversal 
         root -> info.data_display();      
         display_range(root->left, index,index_2); 
          display_range(root->right, index,index_2);
    }

    return 0;
}


int BST :: display_all_wrapper()
{
    return display_all(root);
}


int BST :: display_all(node * root)
{
    if (!root)
        return 0;

    if(root) // pre -order traversal just for fun 
    {
        root -> info.data_display() ;	
        display_all(root -> left);
        display_all(root -> right);

        return 1 ;
    }

    return 0;
}
// this reads from file 
int BST :: read_file (char * aname,char * adescription, char * atype, char * aplatform, int arating, char * acomment)
{

    const int SIZE =100; 
    ifstream games;

    games.open("CS163_games.txt",ios :: out);
    games.peek() ;

    while(!games.eof())
    {
        games.get(aname,SIZE,':');
        games.ignore(SIZE,':');
        games.clear();


        games.get(adescription,SIZE,':');
        games.ignore(SIZE,':');
        games.clear();

        games.get(atype,SIZE,':');
        games.ignore(SIZE,':');
        games.clear();

        games.get(aplatform,SIZE,':');
        games.ignore(SIZE,':');
        games.clear();

        games >> arating;
        games.ignore(SIZE,':');
        games.clear();

        games.get(acomment,SIZE,'\n');
        games.ignore(SIZE,'\n');
        games.clear();


        insert_wrapper(aname, adescription,atype,aplatform,arating,acomment);
        games.peek();
    }
    games.close();
    games.clear();

    return 1;
}
int BST :: get_height_wrapper()
{
    return   get_height(root);
}
int BST :: get_height( node * root) // the function to get height 
{
    if (! root)
        return 0;

    return max(get_height(root -> right),get_height(root -> left)) +1; // recursive call and add one for each time we reach a max

}

int BST :: count_wrapper()
{
    return count (root);
}

int BST :: count( node * root)
{

    if (! root)
        return 0 ;

    if (root ->info.rating == 5)
    {
        return count(root ->left) + count(root -> right) + 1; // add one if the rating is  5
    }
    else 
        return count(root ->left) + count(root -> right) ; // traverse 

}


int BST :: remove_all_wrapper()
{
    return  remove_all( root) ;

}
int BST :: remove_all(node *& root) // remove all 
{
    if(! root)
        return 0;
    remove_all(root->right);
    remove_all(root->left);

    delete root ;
    root = NULL;

    return 1;

}
int BST :: remove_one_wrapper(char * aname, char * aplatform)
{
    return remove_one( root,aname,aplatform) ;
}

int BST :: remove_one(node * & root, char * aname, char * aplatform) // the longest function 
{
    if (! root)         // no entry 
        return 0;

    if(strcmp( root ->info.name,aname) < 0 ) // if the key is smaller
    {    
        return   remove_one(root -> left,aname,aplatform); //  traverse

    }else if  (strcmp( root ->info.name,aname) > 0 ) // if the key is larger
    {
        return remove_one(root -> right,aname,aplatform); // traverse

    }else if (strcmp( root ->info.name,aname) == 0) // if there is a match
    {
        if(strcmp(root ->info.platform,aplatform) == 0)
        {
            if (root-> left == NULL && root ->left == NULL ) // if a leaf
            {
                delete root ;
                root = NULL ;

                return 1;

            }else if (root ->left == NULL && root -> right != NULL) // if there is one child,left
            {
                node * temp = root; 
                root = root ->right;
                delete temp;
                temp = NULL;
                return 1;

            }else if (root ->left != NULL && root -> right == NULL) // if there is one child ,right
            {
                node * temp = root; 
                root = root ->left ;
                delete temp;
                temp = NULL;
                return 1;

            }else if (root -> left !=NULL && root ->right != NULL) // if there are two children //case 3
            {

                node * temp = minVal(root); // the smallest value in the right sub tree
                root -> info  = temp ->info ;
                delete temp ;
                temp = NULL ;
                remove_one (root -> right,aname,aplatform) ; // traverse to the leftmost in the right sub tree 

                if (root -> left == NULL  && root -> right == NULL) // it a leaf aka case 1 type
                {
                    delete root;
                    root = NULL;

                    return 1 ;

                }else if (root -> left == NULL  && root -> right != NULL) // has one right child aka case 2
                {
                    node * temp = root; 
                    root = root ->right;
                    delete temp;
                    temp = NULL;

                    return 1;
                }
            }

        }
    }

    return 0;

}



node*BST :: minVal(node *& root) // to find the smallest value in the right sub tree
{
    node * current = root;

    while (current-> left == NULL) // good old school traversal 
    {

        current  = current ->left ;
    }

    return  current;

}


int BST :: retrieve_wrapper(char * aname,data & info)
{
    return retrieve (root,aname, info) ;
}

int BST :: retrieve (node *  root,char * aname, data & info)
{
    if(! root)
        return 0;
    if (strcmp (root ->info.name,aname)== 0)
    {
        // copy to the object and pass by reference to the console
        info.name = root->info.name;
        info.description = root ->info.description;
        info.type = root ->info.type;
        info.platform = root ->info.platform;
        info.rating = root->info.rating;
        info.comment = root ->info.comment;

        return 1; 
    }else if (strcmp(root ->info.name,aname) < 0)
    {
        return retrieve(root -> left,aname, info);
    }
    else 
    {
        return retrieve (root -> right,aname ,info) ;
    }

    return 0;

}
// the end 
