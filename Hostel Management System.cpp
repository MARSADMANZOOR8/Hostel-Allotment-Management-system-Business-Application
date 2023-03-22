// libraries
#include<iostream>
#include <conio.h>
#include <cmath>
#include <fstream>
#include <windows.h>
using namespace std;
// function for the display of logo 
void logo();

// function for the display of header
void header();

// function to clear the screen 
void clear();

// function to view the users
void view_users();

// function for the mainmenu
string mainmenu();

// variable for the count of studdent
const int student = 50;
const int signCount = 100;

// function to read data from the file in which data store
void readdatafromFile();

// function to store the data of the student 
void storeinfilestudentRecord();

// function to read the data from the student record file
void readdatafromfilestudentRecord();

// function 
string getField(string record, int field);

// function to store the data in the file
void storeinfile(string Name,string Password ,string Role);

// function for the validation of the username
bool isvaliduserName(string Name);

// function for the validation of thr password 
bool validation_password(string Password);

// function for the sign_up of the student and admin
void sign_up(string Name,string Password,string Role);

// sign_in function by which admin and student can avail different options
string signin(string user_name, string Password);

// function for interface of admin
void admin_interface();

// function for interface of student
void student_interface();

// function for choice of student
string signin_student();

// function for choice of admin
string signin_admin();

// function for student to view information
void viewinformation();

// function to calulate the aggegerate
void aggegratecalculator();

// function to display the aggegrate of the student
void aggegratecalculatordisplay();

// function to delete the data
void deleteyourdata();

// function to display the room no
void displayroomNO();

// function to take data from the student
void inputdata();

// function to update data enter from student
void updatadata();

// function for the help of student
void help();

// function by which student can see hostel location
void Location();

// function for contact to adminstration
void contactUS();

// function by which student can give the feedback
void givefeedBack();

// function to store the feedback given by the student
void storefeedBack();

// function to confirm the feedbacks
void confirmfeedBack();

// function to display the list of the student
void displaylist();

// function for confirmation
string confirmation();

// function for cancellation
void cancellation();

//function to find out the index
int indexfinding();

//function to view the feedbacks of the students
void viewfeedBacks();

//function for the validation of the intermarks
bool validation_intermarks(string Inter_marks);

// funtion for the validation of student name
bool validation_studentname(string Stud_name);

// Arrays for name 
string name[signCount];

// Arrays for password
string password[signCount];

// Arrays for the role  
string role[signCount];

// Arrays for the student inter_marks
string inter_marks[student];

// Arrays to store the student name 
string stud_name[student];

// Arrays to store the aggegrate of the student
int  aggegrate[student];

// Arrays for feedback
string FeedbackName[student];
string FeedBack[student];

// users count and student count initialized as zero
int users_count = 0;
int studs_count = 0;
int studs_fcount =0;
int user = 0;

// for validation of marks
bool returnIntergerCount(string word);

// feedBacks count initialized as zero
int feedbackCount = 0;

// variables for the feedback
string feedbackName;
string feedBack;
string ignore;
string answer;

// variables for validation of the inter marks
string Inter_marks;
string Stud_name;

main()
{
    system("cls");
    logo();
    clear();
    readdatafromFile();
    readdatafromfilestudentRecord();   
    system("cls");
    header();
    string Name, Password, Role;
    string option;
    string choice;
    string choice1;
    while (option != "0")
    {
        
        system("cls");
        option = mainmenu();
        if (option == "1")
        {
            getline(cin,ignore);
            cout << "Please enter your name : " << endl;
            getline(cin,Name);
            cout << "Please enter your password : " << endl;
            cout <<"e.g 12345 " << endl;
            cin >> Password;
            bool checkPassword = validation_password(Password);
            if(checkPassword == false)
            {
             cout <<" Invalid Password " << endl;
             cout <<"Please try again  " ;
             clear();
             break;
            }
            else if(checkPassword == true) 
            {
                cout << "Enter your role(admin/student) : " << endl;
                cin >> Role;
                bool result = isvaliduserName(Name);
                if (result == true &&( Role== "admin" || Role== "student"))
                {
                 sign_up(Name,Password,Role);
                 storeinfile( Name, Password,Role);
                 cout << "User register successfully " << endl;
                 clear();
                }
                else if(Role != "admin" && Role != "student")
                {
                
                 cout <<  "  Invalid Role entered :: "<< endl;
                 clear();
                }
                else if (!result)
                {

                 cout << "User already registered so do not register again " << endl;
                 clear();

                }
            }
        }
        if (option == "2")
        {
                 
            string signin_name, signin_pass;
            cout << "Please enter your name : " << endl;
            cin >> signin_name;
            cout << "Please enter your password : " << endl;
            cin >> signin_pass;
            string result = signin(signin_name, signin_pass);
            if (result == "student" || result == "admin")
            {
                cout << "Signed in successfully " << endl;
               

                if (result == "student")
                {
                    
                   
                    student_interface();
                   
                }

                if (result == "admin")
                {

                    admin_interface();
                     
                }
                else
                {
                    
                    clear();
                }
            }
        }
        else if (option == "3")
        {
          view_users();
          cout << "Press any key to continue....";
          getch();
        }
      
    }
}
void logo()
{
                                                                                                               
    cout << "HHHHHHHHH     HHHHHHHHH               AAA               MMMMMMMM               MMMMMMMM    SSSSSSSSSSSSSSS   " <<endl;   
    cout << "H:::::::H     H:::::::H              A:::A              M:::::::M             M:::::::M  SS:::::::::::::::S  " <<endl;  
    cout << "H:::::::H     H:::::::H             A:::::A             M::::::::M           M::::::::M S:::::SSSSSS::::::S  " <<endl;  
    cout << "HH::::::H     H::::::HH            A:::::::A            M:::::::::M         M:::::::::M S:::::S     SSSSSSS  " <<endl;  
    cout << "  H:::::H     H:::::H             A:::::::::A           M::::::::::M       M::::::::::M S:::::S              " <<endl;  
    cout << "  H:::::H     H:::::H            A:::::A:::::A          M:::::::::::M     M:::::::::::M S:::::S              " <<endl;  
    cout << "  H::::::HHHHH::::::H           A:::::A A:::::A         M:::::::M::::M   M::::M:::::::M  S::::SSSS           " <<endl;  
    cout << "  H:::::::::::::::::H          A:::::A   A:::::A        M::::::M M::::M M::::M M::::::M   SS::::::SSSSS      " <<endl;  
    cout << "  H:::::::::::::::::H         A:::::A     A:::::A       M::::::M  M::::M::::M  M::::::M     SSS::::::::SS    " <<endl;  
    cout << "  H::::::HHHHH::::::H        A:::::AAAAAAAAA:::::A      M::::::M   M:::::::M   M::::::M        SSSSSS::::S   " <<endl; 
    cout << "  H:::::H     H:::::H       A:::::::::::::::::::::A     M::::::M    M:::::M    M::::::M             S:::::S  " <<endl;  
    cout << "  H:::::H     H:::::H      A:::::AAAAAAAAAAAAA:::::A    M::::::M     MMMMM     M::::::M             S:::::S  " <<endl;  
    cout << "HH::::::H     H::::::HH   A:::::A             A:::::A   M::::::M               M::::::M SSSSSSS     S:::::S  " <<endl;  
    cout << "H:::::::H     H:::::::H  A:::::A               A:::::A  M::::::M               M::::::M S::::::SSSSSS:::::S  " <<endl;   
    cout << "H:::::::H     H:::::::H A:::::A                 A:::::A M::::::M               M::::::M S:::::::::::::::SS   " <<endl;   
    cout << "HHHHHHHHH     HHHHHHHHHAAAAAAA                   AAAAAAAMMMMMMMM               MMMMMMMM  SSSSSSSSSSSSSSS     " <<endl; 
}
void header()
{

    cout << " ******************************************************************************************************************************************************************** " << endl;
    cout << " * #  #   **   ***** ******* ****** #        #      #   *   #     #   *     #*****  ***** #     # #****  #     # *******  ***** *   * *****  ***** #****  #       # * " << endl;
    cout << " * #  # #    #  *  *    #    #      #        # *  * #  * *  # *   #  * *    #       #     # * * # #      # *   #    #      *     * *   *       #   #      # *   * # * " << endl;
    cout << " * #### #    #   *      #    #***** #        #  **  # ##### #  *  # *****   #  **** #**** #  #  # #****  #  *  #    #       *     #     *      #   #****  #   *   # * " << endl;
    cout << " * #  # #    #    *     #    #      #        #      # #   # #   * # #   #   #     * #     #     # #      #   * #    #        *    #      *     #   #      #       # * " << endl;
    cout << " * #  #   **    ****    #    ****** ******   #      # #   # #     # #   #   ******* ***** #     # *****  #     #    #     *****   #   *****    #   *****  #       # * " << endl;
    cout << " ******************************************************************************************************************************************************************** " << endl;

}
void clear()
{

    cout << "Press any key to continue....";
    getch();
    system("cls");

}
string mainmenu()
{
    string result;
    header();
    cout << "         MAIN MENU " << endl;
    cout << "*************************" << endl;
    cout << "LOGIN MANU " << endl;
    cout << "0.               EXIT " << endl;
    cout << "1.               SIGN UP  to create your account " << endl;
    cout << "2.               SIGN IN to login into your account " << endl;
    cout << "3.               viewusers " << endl;
    cout << "Please enter your choice : " << endl;
    cin >> result;
    return result;
}
void storeinfile(string Name,string Password,string Role)
{

    fstream file;
    file.open("data.txt",ios::app);
    file << Name <<","<<Password<<","<<Role<<endl;
    file.close();

}
void view_users()
{

    cout << "--------------------------------------" << endl;
    cout <<    "USERNAMES           PASSWORDS      " << endl;                  
    for(int index = 0;index<users_count; index++)
    {
        cout << name[index] <<"\t"<<"\t"<< password[index] << endl;
                                    
    }

}
void readdatafromFile()
{
    
    string record;
    fstream data;
    data.open("data.txt", ios::in);
    if(data)
    {
        while(!(data.eof()))
        {
         getline(data, record);
         name[users_count] = getField(record , 1);
         password[users_count] = getField(record , 2);
         role[users_count] = getField(record , 3);
         users_count = users_count + 1;

        }
    }
    data.close();
 

}
string getField(string record, int field)
{
    int commaCount = 1;
    string item = "";
    for(int x = 0;x < record.length() ;x++)
    {

        if(record[x] == ',')
        {
            commaCount = commaCount + 1;
        }
        else if(commaCount == field)
        {
            item = item + record[x];
        }

    }
    return item;
}
bool isvaliduserName(string Name)
{

    bool result = true;
    for(int index = 0;index<users_count ;index++)
    {

        if(name[index] == Name)
        {
            result = false;
            break;
        }
      

    }
    return result;

}
bool validation_password(string Password)
{

    bool result = false;
    int count = Password.length();
    if (count == 5)
    {
       result = true;
       return result;
    
    }
    else
    { 
        return result;
    }
}
void sign_up(string Name,string Password,string Role)
{

  name[users_count] = Name;
  password[users_count] = Password;
  role[users_count] = Role;
  users_count++; 

}


void student_interface()
{

    string choice;
    while (choice != "9")
    {
    
        clear();
        choice = signin_student();
        if (choice == "1")
        {
        inputdata();
        }

        else if (choice == "2")
        {
        updatadata();
        }

        else if (choice == "3")
        {
        help();
        }

        else if (choice == "4")
        {
        givefeedBack();
        }

        else if (choice == "5")
        {
        deleteyourdata();
        }

        else if (choice == "6")
        {
        displayroomNO();
        }
        else if (choice == "7")
        {
        Location();
        }
        else if(choice == "8")
        {
        contactUS();
        }
        else if(choice== "9")
        {
            break;
        }
        

    }

}
void admin_interface()
{

    string choice1;
    while (choice1 != "8")
    {
        
        choice1 = signin_admin();
        if (choice1 == "1")
        {
            viewinformation();
            cout << "Press any key to continue....";
            getch();
        }

        else if (choice1 == "2")
        {
            deleteyourdata();
            cout << "Press any key to continue....";
            getch();
        }

        else if (choice1 == "3")
        {
            aggegratecalculator();
            cout << "Press any key to continue....";
            getch();
        }

        else if (choice1 == "4")
        {
            aggegratecalculatordisplay();
            cout << "Press any key to continue....";
            getch();
        }

        else if (choice1 == "5")
        {
            displayroomNO();
            cout << "Press any key to continue....";
            getch();
        }

        else if (choice1 == "6")
        {
            displaylist();
            cout << "Press any key to continue....";
            getch();
        }

        else if (choice1 == "7")
        {
            viewfeedBacks();
            cout << "Press any key to continue....";
            getch();
            
        }
        else if (choice1 == "8")
        {
            break;
        }
      
    }
}

string signin_student()
{

    system("cls");
    header();
    string choice;
    cout << "choice1.         inputdata()" << endl;
    cout << "choice2.         updatadata()" << endl;
    cout << "choice3.         help()" << endl;
    cout << "choice4.         feedback()" << endl;
    cout << "choice5.         deletethedata()" << endl;
    cout << "choice6.         TO check the Room No  " << endl;
    cout << "choice7.         Location " << endl;
    cout << "choice8.         Contact us " << endl;
    cout << "choice9.         Exit " << endl;
    cout << "Enter your choice for student  " << endl;
    cin >> choice;
    return choice;

}
string signin_admin()
{

    system("cls");
    header();
    string option1;

    cout << "choice1.          viewinformation()" << endl;
    cout << "choice2.          deletethedata()" << endl;
    cout << "choice3.          calculateaggegrate()" << endl;
    cout << "choice4.          displayaggegrate()" << endl;
    cout << "choice5.          displayRoomNo()" << endl;
    cout << "choice6.          displayRoomNolist() " << endl;
    cout << "choice7.          Viewfeedbacks " << endl;
    cout << "choice8.          Exit " << endl;

    cout << "enter your option for admin :  " << endl;
    cin >> option1;
    return option1;

}
string signin(string Name, string Password)
{

    for (int i = 0; i < users_count; i++)
    {
        if (name[i] == Name && password[i] == Password)
        {
            return role[i];
        }
    }
    return "undefined";

}

void inputdata()
{
    getline(cin,ignore);
    cout << "Enter student name ";
    getline(cin,Stud_name);
    bool value = validation_studentname(Stud_name);
    if(value == true)
    {
        cout<<"Student already exist! "<<endl;
        clear();
    }

    else
    {
        cout<<"";
        getline(cin,ignore);
        cout << "Enter your inter marks ";
        getline(cin,Inter_marks);
        bool check = returnIntergerCount(Inter_marks);
        
            if (check==true)
            {
                
             bool result = validation_intermarks( Inter_marks);
             if(result == true)
             {
                stud_name[studs_count] = Stud_name;
                inter_marks[studs_count] = Inter_marks;
                studs_count = studs_count + 1; 
                storeinfilestudentRecord();
             }

             else
             {
                cout << "you have enter an invalid marks :" << endl;
                clear();
             }
            }
            else if (check == false)
            {
                cout << "you have enter an invalid marks :" << endl;
                clear();
            }
            
        
    }
}
void updatadata()
{
    int idx = indexfinding();
    getline(cin,ignore);
    cout << "Enter new name " << endl;
    getline(cin,Stud_name);
    bool value = validation_studentname(Stud_name);
    if(value == true)
    {
        cout<<"Student already exist! "<<endl;
        clear();
    }

    else
    {
        cout << "Enter new Fsc marks " << endl;
        cin >> Inter_marks;
        if (Inter_marks > "1100")
        {
          cout << "you have enter an invalid marks :" << endl;
          clear();
        }
        else
        {

          stud_name[idx] = Stud_name;
          inter_marks[idx] = Inter_marks;
          storeinfilestudentRecord();
          aggegrate[idx] = (stof(inter_marks[idx]) * 100) / 1100;

        } 
    } 
}
void cancellation()
{

    cout << "The current operation has been cancellad " << endl;
    clear();

}
void help()
{

    cout << "If you sign in successfully  then please enter  inter marks in correct form . If  " << endl;
    cout << "you want to updata the data then click  on the updata function by  which you can  " << endl;
    cout << "updata your data.if you want to cancel application then click on the cancellation " << endl;
    cout << "by which you can cancel out your application .You can also give the feedback .   " << endl;
  
}
void givefeedBack()
{

    cout << "Please give your feedback here " << endl;
    getline(cin,ignore);
    cout << "Enter your name : " << endl;
    getline(cin,feedbackName);
    cout << "Enter your feedbck here : " << endl;
    getline(cin,feedBack);
    confirmfeedBack();

}
void confirmfeedBack()
{
    answer = confirmation();
    if (answer == "yes")
    {
        storefeedBack();
    }
    else if (answer == "no")
    {
        cancellation();
    }
    else if (answer != "yes" && answer != "no")
    {
        cout << "PLease enter the valid information to proceed " << endl;
        clear();
    }
}
void storefeedBack()
{

    FeedbackName[feedbackCount] = feedbackName;
    FeedBack[feedbackCount] = feedBack;
    feedbackCount++;
    cout << "Thank you for your precious feedback " << endl;
    clear();

}
string confirmation()
{

    cout <<" DO you want to proceed (yes / no )"<< endl;
    cin >> answer;
    return answer;

}

void viewinformation()
{
    
    cout << "Name               Inter Marks" << endl;
    cout <<"_____________________________  " << endl;
    for (int i = 0; i < studs_count; i++)
    {
     cout << stud_name[i] <<"              "<< inter_marks[i] << endl;
    }

}


void aggegratecalculator()
{
    
    for (int i = 0; i < studs_count; i++)
    {
      string Inter = inter_marks[i];
      int value = stoi(Inter);
      aggegrate[i] = ( value * 100) / 1100;  
    
    }
     
    cout << "The aggegrate of all the student is  calculated who apply for hostel " << endl;
    
} 

void aggegratecalculatordisplay()
{
    int j = indexfinding();
     if(j!=-1)
     {
        cout << "The student which  applay for the hostel in the university is  " << stud_name[j] << endl;
        cout << "he got " << inter_marks[j] << " out of 1100 in intermediate. He has the aggegrate " << aggegrate[j]  << endl;
     }
     else
     {
        cout<<"Invalid name entered! "<<endl;
        clear();
     }
    
}

void deleteyourdata()
{

    int j = indexfinding();
    
    if (j != -1)
    {
        stud_name[j] = stud_name[j + 20];
        inter_marks[j] = inter_marks[j + 20];
        cout << "The data is deleted : " << endl;
        studs_count--;
        storeinfilestudentRecord();
        
        
    }

    else
    {
        cout << "Student not found" << endl;
        getch();
    }
}


void displaylist()
{
    string temp;
    string temp1;
    int temp2;
     for(int idx=0;idx<studs_count;idx++)
    {
        for(int j=idx+1;j<studs_count;j++)
        {
            if(inter_marks[idx]<inter_marks[j])
            {
                temp=inter_marks[idx];
                inter_marks[idx]=inter_marks[j];
                inter_marks[j]=temp;
                temp1=stud_name[idx];
                stud_name[idx]=stud_name[j];
                stud_name[j]=temp1;
                temp2=aggegrate[idx];
                aggegrate[idx]=aggegrate[j];
                aggegrate[j]=temp2;
            }
        }
   }
     
     for(int idx=0;idx<studs_count;idx++)
    {

        cout<<"##########################################################"<<endl;
        cout << "Name of the Student ::     " << stud_name[idx]  << endl;
        cout << "Marks of the Student ::    " <<inter_marks[idx] << endl;
        cout << "Aggegrate of the student : " << aggegrate[idx]  << endl;
        cout <<  "ROOM NO IS ::             " << idx + 1         << endl;
        cout << "___________________________________________________________"<<endl;

    }

}
 
void displayroomNO()
{
    
    string name;
    string temp;
    string temp1;
    int temp2;
     for(int idx=0;idx<studs_count;idx++)
    {
        for(int j=idx+1;j<studs_count;j++)
        {
          if(inter_marks[idx]<inter_marks[j])
            {
               temp=inter_marks[idx];
               inter_marks[idx]=inter_marks[j];
               inter_marks[j]=temp;
               temp1=stud_name[idx];
               stud_name[idx]=stud_name[j];
               stud_name[j]=temp1;
               temp2=aggegrate[idx];
               aggegrate[idx]=aggegrate[j];
               aggegrate[j]=temp2;
            }
        }

    }
     int j = indexfinding(); 

         cout<<"##########################################################"<<endl;
         cout << "Name of the Student ::     " << stud_name[j]  << endl;
         cout << "Marks of the Student ::    " <<inter_marks[j] << endl;
         cout <<  "ROOM NO IS ::             " << j + 1         << endl;
         cout << "___________________________________________________________"<<endl;
   
}


int indexfinding()
{
    int j = -1;
    string name;
    getline(cin,ignore);
    cout << "Please enter your name to proceed  " << endl;
    getline(cin,name) ;
    if(name==" ")
    {
        cout << "NO name is prestent " << endl;
    }
    else if(name!=" ")
    {
        for (int i = 0; i < studs_count; i++)
        {
            if (stud_name[i] == name)
            {
                j = i;
                break;
            }
        }
    }
    return j;
}

void viewfeedBacks()
{
    for(int index=0 ; index<=feedbackCount ;index++)
    {
        cout << FeedbackName[index] << endl;
        cout << FeedBack[index] << endl;
    }
}

bool validation_intermarks(string Inter_marks)
{
    int Inter = stoi(Inter_marks);
    if (Inter > 1100 )
    {
        return false;
       
    }
    return true;
}
bool returnIntergerCount(string word)
{
    int value;
    int count = 0;
    int lengthofWord = word.length();
    for(int i=0;i<lengthofWord;i++)
    {
        int value = word[i] - '0';
        if(value>=0 && value<10)
        {
            count = count + 1;
        }
    }
    if(count == lengthofWord)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void storeinfilestudentRecord()
{
    fstream file;
    file.open("StudentRecord.txt",ios::out);
    for(int i = 0;i < studs_count;i++)
    {
        file << stud_name[i] << ",";
        file << inter_marks[i] << endl;
    }
    file.close();
}
void readdatafromfilestudentRecord()
{

    string Name;
    fstream file;
    file.open("StudentRecord.txt",ios::in);
    if(file)
    {

        while(!(file.eof()))
        {
            getline(file,Name);
            if(Name==" ")
            {
              break;
            }
            else
            {
              stud_name[studs_count] = getField(Name,1);
              inter_marks[studs_count] = getField(Name,2);
              studs_count = studs_count + 1 ; 
            }
        }
    }
    file.close();
}
bool validation_studentname(string Stud_name)
{
    for(int i=0;i<studs_count;i++)
    {
        if(Stud_name==stud_name[i])
        {
            return true;
            break;
        }
    }
    return false;
}
void contactUS()
{
cout << " #######################################"<<endl;
cout << " #  Contact us incase of any problem   #"<<endl;
cout << " #  99029452                           #"<<endl;                  
cout << " #  Registrar 042-99029227             #"<<endl;
cout << " #  registrar@ibahostel.edu.pk               #"<<endl;
cout << " #######################################"<<endl;
}
void Location()
{
    cout << "Main GT Road near UNIVERSITY OF PUNJAB ,Lahore    "<<endl;
    cout << "################################################## "<<endl;
    cout << "                     ##                           "<<endl;
    cout << "                     ##      # # # # #            "<<endl;
    cout << "                     ##      #   PU  #            "<<endl;
    cout << "                     ##      #       #            "<<endl;
    cout << "                     #################            "<<endl;
    cout << "       ################                     _____ "<<endl;
    cout << "       ##                                 #Hostel#"<<endl;
    cout << "       ##                                 #      #"<<endl;
    cout << "##################################################"<<endl;
}

