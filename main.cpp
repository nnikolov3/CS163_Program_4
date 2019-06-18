/* Nikolay Nikolov
   CS163
Instructor:Karla Fant
Program # 4
Purpose of the program: 

The program's utilizes BST to  store, retrieve, delete and display a list of 
games and their peripheral information from external file. 
In addition, the user will be able to insert, and update the list with the games. 
The main concept of the assignment is the same as for Program # 3.

This the main client file



A  young Programmer and his Project Manager board a train headed through the mountains on its way to Wichita. 
They can find no place to sit except for two seats right across the aisle from a young woman and her grandmother.
After a while, it is obvious that the young woman,
and the young programmer are interested in each other, 
because they are giving each other looks. 
Soon the train passes into a tunnel and it is pitch black.
There is a sound of a kiss followed by the sound of a slap.
When the train emerges from the tunnel, the four sit there without saying a word. 
The grandmother is thinking to herself,
“It was very brash for that young man to kiss my granddaughter, but I’m glad she slapped him.”
The Project manager is sitting there thinking, “I didn’t know the young tech was brave enough to kiss the girl,
but I sure wish she hadn’t missed him when she slapped me!”
The young woman was sitting and thinking, “I’m glad the guy kissed me, 
but I wish my grandmother had not slapped him!”
The young programmer sat there with a satisfied smile on his face. 
He thought to himself, “Life is good.
How often does a guy have the chance to kiss a beautiful girl ,
and slap his Project manager all at the same time!”
*/

#include"bst.h"
#include<fstream>
#include<iostream> 
#include<cctype>

using namespace std ;

const int SIZE=100;

int main()
{
    BST myBST ;
    int var = 0;
    bool done = false ;
    const int SIZE =500; 

    char aname[SIZE];
    char adescription[SIZE];
    char atype[SIZE] ;
    char aplatform[SIZE];
    int arating = 0;
    char acomment[SIZE] ;
    char index[10];
    char index_2[10];


    data info ; // data object 
    int l = 0;
    int k = 0;// these  are variables to catch some of the returns t
    int j = 0;
    int h = 0;
    int c = 0;
    int z = 0;
    bool success = false ;

    while (!done){ //menu 

        cout<<"\t\t\tHello!"<<endl ;
        cout<<"\t\t\tThese are the commands you can perform : " << endl ;
        cout<<"\t\t\t To insert           --------------------------" << endl;
        cout<< endl;
        cout<<"\t\t\tPress 1 to insert a new game . " << endl ;
        cout<<"\t\t\tPress 2 to insert ALL games from a file. " << endl ;
        cout<< endl;
        cout<<"\t\t\t The Display section  --------------------------" << endl;
        cout<<"\t\t\tPress 3 to display A GAME of YOUR CHOICE . "<< endl;
        cout<<"\t\t\tPress 4 to count  ALL games with 5 STAR rating. " << endl;
        cout<<"\t\t\tPress 5 to DISPLAY games  within a RANGE  ex . A to D . "<< endl ;	
        cout<<"\t\t\tPress 6 to DISPLAY ALL  games. "<< endl ;
        cout<< endl;
        cout<<"\t\t\t The remove section   --------------------------" << endl;
        cout<<"\t\t\tPress 7 to REMOVE a single game . " << endl ;
        cout<<"\t\t\tPress 8 to REMOVE ALL games . " << endl ;
        cout<< endl;
        cout<<"\t\t\t The height           --------------------------" << endl;
        cout<<"\t\t\tPres  9 to get the Height of The Tree . " << endl ;
        cout<<"\t\t\tTo QUIT press 0 . " << endl ;
        cout<<"\t\t\t                      ___________________________" << endl;
        cout<<"\t\t\tNow its your turn to make a choice .Type here --> " ;
        cin >> var ;
        cin.clear () ;cin.ignore(SIZE,'\n') ;


        switch (var){
            case 1 : //  Insert a game 

                cout <<"\t\t\tWelcome ! " << endl ;
                cout<<"\t\t\tI will help you to insert a game!Follow my lead! " << endl;
                cout<< "\033[2J\033[1;1H" << endl; 
                do{

                    cout<< "\033[2J\033[1;1H" << endl; 
                    cout<<"\t\t\tPlease enter the name of the game . Please make sure the first letter is capital-->";
                    cin.get(aname,SIZE);cin.clear() ;cin.ignore(SIZE,'\n') ;
                }while (isupper(aname[0])== 0);
                cout<<endl ;
                cout<<"\t\t\tPlease enter a description for  the game .-->" ;
                cin.get(adescription,SIZE);cin.clear() ;cin.ignore(SIZE,'\n');
                cout<<endl;
                cout<<"\t\t\tPlease enter the type of the game .-->" ;
                cin.get(atype,SIZE);cin.clear() ;cin.ignore(SIZE,'\n');
                cout<<endl;

                do{
                    cout<<"\t\t\tPlease enter the name of the platform for the  game .The first letter is capital.-->" ;
                    cin.get(aplatform,SIZE);cin.clear() ;cin.ignore(SIZE,'\n');
                } while (isupper(aplatform[0]) == 0);

                cout<< endl;
                do{
                    cout<<"\t\t\tPlease enter an INTEGER  BETWEEN the values of 1-5 for the game .-->" ;
                    cin >> arating;
                    cin.clear() ;cin.ignore(SIZE,'\n');
                    cout<< endl; 
                }while (arating >5 ||  arating <0 );

                cout<<"\t\t\tPlease enter a comment for the game .-->" ;
                cin.get(acomment,SIZE);cin.clear() ;cin.ignore(SIZE,'\n');

                myBST.insert_wrapper(aname,adescription,atype,aplatform,arating,acomment); //calling the function to insert


                break ;

            case 2:// Read from file 
                l =  myBST.read_file(aname,adescription,atype,aplatform,arating,acomment); // read from file

                if (l ==1)
                {

                    cout<< "\033[2J\033[1;1H" << endl; 
                    cout<<"\t\t\t " <<"---------------------------------"<<endl ;
                    cout<<"\t\t\t " <<"The games are loaded to the file."<< endl;
                    cout<<"\t\t\t " << "Job done !!" << endl;
                    cout<<"\t\t\t " <<"---------------------------------"<<endl ;
                }else 
                {
                    cout<< "\033[2J\033[1;1H" << endl; 
                    cout << "\t\t\t Something went wrong " << endl; 
                }
                break ;

            case 3:// Display a Game of your choice
                // Displays a Game using the retrieve function 
                // It sends information to the console

                cout<< "\033[2J\033[1;1H" << endl; // this is just to clear the screen
                do{
                    cout<<"\t\t\t " <<"Please enter the name of the game you would like to see. The first letter is capital. ->" ;
                    cin.get(aname,SIZE);cin.clear();cin.ignore(SIZE,'\n') ;
                }while (isupper(aname[0]) == 0) ;
                cout<<endl;
                cout<<endl;

                cout<< "\033[2J\033[1;1H" << endl;  
                k = myBST.retrieve_wrapper(aname,info);
                if (k == 1)
                {

                    cout<< "\033[2J\033[1;1H" << endl; 

                    cout<<"\t\t|"<<"------------------------------------------------------------------"<< endl ;
                    cout<<"\t\t|"<<"The name is          :" << info.name 	    	      << endl;
                    cout << endl;
                    cout<<"\t\t|"<<"The desscription is  :" << info.description        << endl;
                    cout << endl;
                    cout<<"\t\t|"<<"The type is          :" << info.type               << endl;
                    cout << endl;
                    cout<<"\t\t|"<<"The platform is      :" << info.platform           << endl;
                    cout << endl;
                    cout<<"\t\t|"<<"The rating is        :" << info.rating             << endl;
                    cout << endl;
                    cout<<"\t\t|"<<"The comment is       :" << info.comment             << endl;	
                    cout << endl;
                    cout<<"\t\t|" <<"------------------------------------------------------------------"<< endl;
                }
                else
                {
                    cout<< "\033[2J\033[1;1H" << endl; 
                    cout<<"\t\t\t Not a match ! " << endl; 
                }
                break;
            case 4://Count all games with 5 star rating 


                c = myBST.count_wrapper();
                if(c > 0)
                {
                    cout<< "\033[2J\033[1;1H" << endl; 
                    cout<<"\t\t\t "<<"There are :" << endl;
                    cout<<"\t\t\t " <<"---------------------------------"<<endl ;
                    cout<<"\t\t\t " << c << " games with rating 5 "<< endl;
                    cout<<"\t\t\t " <<"---------------------------------"<<endl ;
                }else
                {
                    cout<< "\033[2J\033[1;1H" << endl;
                    cout<< "\t\t\t I am sorry something went wrong  or the list is empty ." << endl ;

                }
                break ;
            case 5://Display within a range 
                cout<< "\033[2J\033[1;1H" << endl;
                
                do {
                cout<<"\t\t\t Make sure you enter letters that are subsequent like A - C , not B -A " << endl;
                do {
                    cout<<"\t\t\t " <<"Please enter the letter to start your query. Type capital letter  ->" ;
                    cin.get(index ,2); cin.clear(); cin.ignore(1,'\n') ;
                } while (isupper(index[0])==0);
                cout<< endl;
                cout<< endl;

                do {
                    cout<<"\t\t\t " <<"Please enter the letter to end your query. Type capital letter  ->" ;
                    cin.get(index_2,2);cin.clear();cin.ignore(1,'\n') ;
                } while (isupper(index_2[0]) == 0);

                } while (index[0] > index_2[0]);

                l= myBST.display_range_wrapper(index, index_2);

                break;
            case 6://Display ALL

                myBST.display_all_wrapper();
                break ;


            case 7: // delete single 
                do{
                    cout<< "\033[2J\033[1;1H" << endl; 
                    cout<<"\t\t\t " <<"Please enter the name of the game you would like to see. The first letter is capital. ->" ;
                    cin.get(aname,SIZE);cin.clear();cin.ignore(SIZE,'\n') ;
                }while (isupper(aname[0] == 0)) ;
                cout<<endl;

                do{
                    cout<< "\033[2J\033[1;1H" << endl; 
                    cout<<"\t\t\t " <<"Please enter the platform you. The first letter is capital. ->" ;
                    cin.get(aplatform,SIZE);cin.clear();cin.ignore(SIZE,'\n') ;
                }while (isupper(aplatform[0] == 0)) ;

                j =myBST.remove_one_wrapper(aname,aplatform);

                if (j==1)
                {

                    cout<< "\033[2J\033[1;1H" << endl; 
                    cout<<"\t\t\t That was successful !" << endl;
                }else 
                {
                    cout<< "\033[2J\033[1;1H" << endl; 
                    cout<<"\t\t\t There was not match or something went wrong!" << endl;
                }   


                break;

            case 8 : // Remove all


                if(  myBST.remove_all_wrapper() == 1)
                {
                    cout<< "\033[2J\033[1;1H" << endl; 
                    cout<<"\t\t\t " <<"---------------------------------"<<endl ;
                    cout<<"\t\t\t " <<"The games were  deleted!            "<< endl;
                    cout<<"\t\t\t " <<"---------------------------------"<<endl ;
                } else
                { 
                    cout<< "\033[2J\033[1;1H" << endl;  
                    cout<<"\t\t\t " <<"---------------------------------"<<endl ;
                    cout<<"\t\t\t " <<"Oppps something went wrong!      "<< endl;
                    cout<<"\t\t\t " <<"---------------------------------"<<endl ;
                }

                break;

            case 9 : // Get the height

                h =  myBST.get_height_wrapper();
                cout<< "\033[2J\033[1;1H" << endl;  
                cout<<" \t\t\t " <<"The height of the tree is " << endl;
                cout<<" \t\t\t" <<"---------------------------------"<<endl ;
                cout<<" \t\t\t " << h << endl;
                cout<< " \t\t\t " <<"---------------------------------"<<endl ;

                break;

            case 0://Quit 
                cout<< "\033[2J\033[1;1H" << endl;    
                cout <<"\t\t\t Live long and prosper. " << endl ;
                done = true ;
                break ;

            default :

                break ;
        }
    }
    return 0 ;

}
