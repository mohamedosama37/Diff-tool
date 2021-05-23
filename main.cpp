/***************************************************************************************************************************************************/
/*AUTHOR   : MOHAMED OSAMA                                                                                                                        */
/*DATE     : 8 jan 2021                                                                                                                          */
/*VERSION  : V02                                                                                                                                */
/***********************************************************************************************************************************************/
/* DESCRIPTION                                                                                                                                */
/*------------                                                                                                                               */
/* this program is used to compare between 2 text files ( size , number of matching & mismatching words                                     */
/*                                                        matching and mismatching lines ,percentage of identical                          */
/******************************************************************************************************************************************/

// add libraries
#include <stdio.h>
#include <stdlib.h>
#include  <fstream>
#include<windows.h>
#include <iostream>
#include <conio.h>
#include <string.h>

//define macros
#define EOF_SUCESS 2
#define FILE_FAIL  1
#define ERROR     -1
#define STATUS_SUCCESS 0
#define MENU_OPTION 4
#define TRUE        1
#define FALSE       0
#define INITAL      0
#define null -32
#define ESC   27
#define Enter 13
#define Tab   9
#define F3    72
#define F17   80
using namespace std;

// define new data type for comparing the files //
// class compares files has 4 function to compares files//
//by size , words , line , percentage //
// and private  variable to store the files properties ex ( size ,file name or location)//
//and set & get fn to access these privates variables//

class compare_files
{
    // flag to check if file 1 is bigger than 2//
    char    file1_is_bigger;
 // to count words numbers in the files //
    double  lines_number;
  // to count words numbers in the files //
    double  words_number;
 // to count words matched between the files //
    double  word_match;
// to count words mismatched between the files //
    double  word_missmatch ;
// to store first file size //
    double  input_file1_size;
// to store second file size //
    double  input_file2_size;
// to store similarity percentage between the two files //
    double  precentage_identical;
// to count number of lines similar between the files //
    double  identical_line_count;
// to  count number of words similar between the files //
    double  identical_words_count ;
// to  count number of words not similar between the files //
    double  notidentical_words_count ;
// to  count number of lines not similar between the files //
    double  notidentical_line_count;
 // to hold the address or name of file1 //
    string  input_first_buffer ;
// to hold the address or name of file2 //
    string  input_second_buffer;

   public:


// constructor to set the initial variable//

   compare_files()
   {
     lines_number             =INITAL ;
     words_number             =INITAL ;
     word_match               =INITAL ;
     word_missmatch           =INITAL ;
     input_file1_size         =INITAL ;
     input_file2_size         =INITAL ;
     precentage_identical     =INITAL ;
     identical_line_count     =INITAL ;
     identical_words_count    =INITAL ;
     notidentical_line_count  =INITAL ;
     notidentical_words_count =INITAL ;
     file1_is_bigger          =INITAL;
     input_first_buffer       ="";
     input_second_buffer      ="";
   }

   //bool fn to check if all words in the 2 files are similar //
   // and to count number of matching or mismatching words //
   // and print the mismatching words with their locations//
   bool word_compare ( void );
   // bool fn to check if the 2 files have the same lines//
   // or not and to get number of different lines//
   bool file_sentence_compare (void);
   // function to check the percentage of the similarity//
   // of file 1 to file 2 //
   void check_file1_identical_precentage(void);
    // function to check the percentage of the similarity//
   // of file 2 to file 1 //
   void check_file2_identical_precentage(void);
   // function to check if the 2 files have the same //
   // size or not and get their size                //
   bool size_compare ( void );
   // function used  to count words of lines in the bigger  file//
    void get_file_words_count(void);
   // function used  to count lines of lines in the the bigger file//
    void get_file_lines_count(void);
   //function to set and get the private variables//
   void set_word_match (double) ;
   double get_word_match (void);
   void set_word_missmatch (double) ;
   double get_word_missmatch (void);
   void set_precentage_identical(double);
   double get_precentage_identical(void);
   void set_notidentical_line_count(double);
   double get_notidentical_line_count(void);
   void set_identical_line_count(double);
   double get_identical_line_count(void);
   void set_identical_words_count(double);
   double get_identical_words_count(void);
   void set_notidentical_words_count(double);
   double get_notidentical_words_count(void);
   void set_file1_is_bigger (char);
   char get_file1_is_bigger (void);
   void set_input_file1_size(double);
   double get_input_file1_size(void);
   void set_input_file2_size(double);
   double get_input_file2_size(void);
   void set_words_number( double);
   double get_words_number(void);
   void set_lines_number(double);
   double get_lines_number(void);
   void set_input_first_buffer(string);
   string get_input_first_buffer(void);
   void set_input_second_buffer(string);
   string get_input_second_buffer (void);


};



//creating object from the class//
compare_files compare;


 // textattr function to clour the menu and highlighted choice //

 void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

}

// implementation of set  function  to access the private variable //
  void  compare_files :: set_lines_number( double input)
   {
    lines_number =input ;
   }
  // implementation of get  function  to get the private variable //
   double compare_files :: get_lines_number(void)
   {
    return lines_number ;
   }


// implementation of set  function  to access the private variable //
  void  compare_files :: set_file1_is_bigger( char input)
   {
    file1_is_bigger =input ;
   }
  // implementation of get  function  to get the private variable //
   char compare_files :: get_file1_is_bigger(void)
   {
    return file1_is_bigger ;
   }



// implementation of set  function  to access the private variable //
  void  compare_files :: set_words_number( double input)
   {
    words_number =input ;
   }
  // implementation of get  function  to get the private variable //
   double compare_files :: get_words_number(void)
   {
    return words_number;
   }

// implementation of set  function  to access the private variable //
  void  compare_files :: set_input_first_buffer(string input)
   {
    input_first_buffer =input ;
   }
  // implementation of get  function  to get the private variable //
   string compare_files :: get_input_first_buffer(void)
   {
    return input_first_buffer;
   }
   // implementation of set  function  to access the private variable //
   void compare_files :: set_input_second_buffer(string input)
   {
    input_second_buffer =input;
   }
// implementation of get  function  to get the private variable //
   string compare_files :: get_input_second_buffer (void)
   {
    return input_second_buffer;
   }
// implementation of set  function  to access the private variable //
  void compare_files :: set_input_file1_size(double input)
  {
    input_file1_size = input ;
  }
// implementation of get  function  to get the private variable //
  double compare_files :: get_input_file1_size(void)
   {
     return input_file1_size;
   }
// implementation of set  function  to access the private variable //
   void compare_files :: set_input_file2_size(double input)
   {
   input_file2_size = input ;
   }
 // implementation of get  function  to get the private variable //
   double compare_files :: get_input_file2_size(void)
   {
     return input_file2_size ;
   }

// implementation of set  function  to access the private variable //
void compare_files :: set_identical_words_count(double input)
{
  identical_words_count = input;
}
// implementation of get  function  to get the private variable //
double compare_files :: get_identical_words_count(void)
{
  return identical_words_count ;
}
// implementation of set  function  to access the private variable //
void compare_files :: set_notidentical_words_count(double input )
{
  notidentical_words_count = input;
}
// implementation of get  function  to get the private variable //
double compare_files :: get_notidentical_words_count(void)
{
  return notidentical_words_count ;
}
// implementation of set  function  to access the private variable //
void compare_files :: set_identical_line_count (double input)
{
   identical_line_count = input ;
}
// implementation of get  function  to get the private variable //
double compare_files :: get_identical_line_count(void)
{
    return identical_line_count;
}

// implementation of set  function  to access the private variable //
void compare_files :: set_notidentical_line_count (double input)
{
   notidentical_line_count = input ;
}
// implementation of get  function  to get the private variable //
double compare_files :: get_notidentical_line_count(void)
{
    return notidentical_line_count;
}
// implementation of set  function  to access the private variable //
void compare_files :: set_precentage_identical (double input)
{
   precentage_identical = input ;
}
// implementation of get  function  to get the private variable //
double compare_files :: get_precentage_identical(void)
{
    return precentage_identical;
}
// implementation of set  function  to access the private variable //
void compare_files :: set_word_match (double input)
{
   word_match = input ;
}
// implementation of get  function  to get the private variable //
double compare_files :: get_word_match (void)
{
    return word_match;
}
// implementation of set  function  to access the private variable //
void compare_files :: set_word_missmatch (double input)
{
   word_missmatch = input ;
}
// implementation of get  function  to get the private variable //
double compare_files :: get_word_missmatch (void)
{
    return word_missmatch;
}

// this function to return number of  lines in the bigger //
//size file to use in calculating number of mismatching lines //

 void compare_files :: get_file_lines_count(void)
 {
    ifstream input_file1 , input_file2 ;
    string line;
    input_file1.open(compare.get_input_first_buffer(),ios :: in | ios :: binary);
    input_file2.open(compare.get_input_second_buffer(),ios :: in | ios :: binary);
          // we check if the 2 files are open successfully without no issue//
    // we read from files flag if zero it success//
    // if not  we cout the issue and clear the flag to be able to read from it again later//
       if (input_file1.rdstate() != STATUS_SUCCESS || input_file2.rdstate() != STATUS_SUCCESS  )

        {
                           cout<< " There is issue in reading files"<<endl;
                           input_file1.clear();
                           input_file2.clear();

        }


                //now we will check if file1_isbigger flag to know which file is bigger//
        //to get its words count//
        if (compare.get_file1_is_bigger()== TRUE)
        {

          // now we will loop until we finish the file //
          // and we will increment the lines_number counters in this loop//


                     while(!input_file1 .eof())
                     {
                      getline(input_file1, line);
                     compare.set_lines_number(compare.get_lines_number()+1);
                     }

             // we will check eofbit flag to check if  whole file 1 was read or not//

              if (input_file1.eofbit != EOF_SUCESS)
                    {
                             cout<<"not all the file was read" <<endl;
                             input_file1.clear();
                    }


        }else
        {

            // now we will loop until we finish file 2 //
          // and we will increment the lines_number counters in this loop//


                     while(!input_file2 .eof())
                     {
                      getline(input_file2, line);
                     compare.set_lines_number(compare.get_lines_number()+1);
                     }


              // we will check eofbit flag to check if  whole file 2 was read or not//
                         if (input_file2.eofbit != EOF_SUCESS)
                    {
                             cout<<"not all the file was read" <<endl;
                             input_file2.clear();
                    }

        }

        //we close the files//
    input_file1.close();
    input_file2.close();

 }
// this function to return  number of words in the bigger//
//size file to use in calculating the number of mismatching words//

void compare_files :: get_file_words_count(void)
{


    // temp object from ifstram to be able to open the files and use getline function to read the files line by line //
    ifstream input_file1 , input_file2 ;
    string word;
    input_file1.open(compare.get_input_first_buffer(),ios :: in | ios :: binary);
    input_file2.open(compare.get_input_second_buffer(),ios :: in | ios :: binary);

      // we check if the 2 files are open successfully without no issue//
    // we read from files flag if zero it success//
    // if not  we cout the issue and clear the flag to be able to read from it again later//
       if (input_file1.rdstate() != STATUS_SUCCESS || input_file2.rdstate() != STATUS_SUCCESS  )

        {
                           cout<< " There is issue in reading files"<<endl;
                           input_file1.clear();
                           input_file2.clear();

        }

        //now we will check if file1_isbigger flag to know which file is bigger//
        //to get its words count//
        if (compare.get_file1_is_bigger()== TRUE)
        {

          // now we will loop until we finish the file //
          // and we will increment the words_number counters in this loop//


                     while(!input_file1 .eof())
                     {
                input_file2>>word;
               compare.set_words_number(compare.get_words_number()+1);
                     }

             // we will check eofbit flag to check if  whole file 1 was read or not//

              if (input_file1.eofbit != EOF_SUCESS)
                    {
                             cout<<"not all the file was read" <<endl;
                             input_file1.clear();
                    }


        }else
        {

            // now we will loop until we finish file 2 //
          // and we will increment the words_number counters in this loop//


           while (!input_file2.eof())
           {

                input_file2>>word;
               compare.set_words_number(compare.get_words_number()+1);
           }

              // we will check eofbit flag to check if  whole file 2 was read or not//
                         if (input_file2.eofbit != EOF_SUCESS)
                    {
                             cout<<"not all the file was read" <<endl;
                             input_file2.clear();
                    }

        }

        //we close the files//
    input_file1.close();
    input_file2.close();
}





   //bool fn to check if all words in the 2 files are similar //
   // and to count number of matching or mismatching words //
   // and print the mismatching words with their locations//
   // param : void //
   // return : bool ( true or false)//


bool compare_files::word_compare (void)
{


// local buffer to read the words from files//
    string input_file1_buffer ;
    string input_file2_buffer ;

        // temp object from ifstram to be able to open the files and use getline function to read the files line by line //
    ifstream input_file1 , input_file2 ;
    input_file1.open(compare.get_input_first_buffer(),ios :: in | ios :: binary);
    input_file2.open(compare.get_input_second_buffer(),ios :: in | ios :: binary);

      // we check if the 2 files are open successfully without no issue//
    // we read from files flag if zero it success//
    // if not  we cout the issue and clear the flag to be able to read from it again later//
       if (input_file1.rdstate() != STATUS_SUCCESS || input_file2.rdstate() != STATUS_SUCCESS  )

        {
                           cout<< " There is issue in reading files"<<endl;
                           input_file1.clear();
                           input_file2.clear();

        }


        // do while loop until finish reading all words from first files//
// we read word from file1 and from file 2//
// and then we compare the 2 words//
// if they are similar increment the identical word counter//
// if not  similar increment the not identical word counter//
// and print the 2 mismatched words to the user with their location//



      // but first we need to check if file 1 is bigger so will read from file 2 as it will finish before file 1
      // as we donot want to read to file 1 and continue reading after file 2 is done //
        if (compare.get_file1_is_bigger()== TRUE)
        {
                               while(!input_file2 .eof())
                              {
                                      // read word from file 1 in first buffer//
                                    input_file1 >> input_file1_buffer ;
                                    // read word from file 2 in second buffer//
                                    input_file2 >> input_file2_buffer;
                                      //compare the 2 words//
                                    if (input_file1_buffer == input_file2_buffer)
                                    {
                                      // increment the identical counter in case true//
                                     compare.set_identical_words_count((compare.get_identical_words_count()+1));
                                    }
                                    else
                                    {
                                       // increment the notidentical counter in case False//
                                       // cout the 2 words//
                                       textattr( 15);
                                       cout<<"word  from file 1 : ";
                                      cout <<input_file1_buffer<<endl;
                                      cout <<"is mismatch with "<<endl;

                                      textattr( 1);
                                      cout<<"word  from file 2 : ";
                                       cout <<input_file2_buffer<<endl;
                                     // tellg() function return the postion of the words//
                                    cout << "they are mismatch at locations "<<input_file2.tellg()<< endl;

                                    compare.set_notidentical_words_count( (compare.get_notidentical_words_count()+1));
                                  }


                             }
                                              // check if we real all the file or not//
                                             // if flag of eof return 2  it is success//
                                           //else we notice the user that not all the file was read//
                                          // clear the flag to read from it again later//

                                    if (input_file2.eofbit != EOF_SUCESS)

                                   {
                                       cout<<"not all the file was read" <<endl;
                                       input_file2.clear();
                                    }
            } else

                {


                            while(!input_file1 .eof())
                             {
                              // read word from file 1 in first buffer//
                              input_file1 >> input_file1_buffer ;
                              // read word from file 2 in second buffer//
                              input_file2 >> input_file2_buffer;
                               //compare the 2 words//
                             if (input_file1_buffer == input_file2_buffer)
                                 {
                                   // increment the identical counter in case true//
                                  compare.set_identical_words_count((compare.get_identical_words_count()+1));
                                }else
                                {
                                    // increment the notidentical counter in case False//
                                    // cout the 2 words//
                                    textattr( 15);
                                   cout<<"word  from file 1 : ";
                                    cout <<input_file1_buffer<<endl;
                                    cout <<"is  mismatch with "<<endl;

                                   textattr( 1);
                                  cout<<"word  from file 2 : ";
                                  cout <<input_file2_buffer<<endl;
                                 // tellg() function return the postion of the words//
                                  cout << "they are mismatch at location "<<input_file1.tellg()<< endl;

                                compare.set_notidentical_words_count( (compare.get_notidentical_words_count()+1));
                               }


                          }

                                // check if we real all the file or not//
                                // if flag of eof return 2  it is success//
                               //else we notice the user that not all the file was read//
                              // clear the flag to read from it again later//
                               if (input_file1.eofbit != EOF_SUCESS)

                               {
                                 cout<<"not all the file was read" <<endl;
                                 input_file1.clear();

                                }

                }


    input_file1.close();
    input_file2.close();

    // check if the not identical counter  more than 1 so the files//
    //  have mismatched words between them and return false//
    //else  return true //
    if ( compare.get_notidentical_words_count() >= 1)
    {
        return FALSE;
    }
   return TRUE;
}





   //bool fn to check if all lines in the 2 files are similar //
   // and to count number of matching or mismatching lines //
   // and print the mismatching lines with their locations//
   // param : void//
   // return : bool ( true or false)//
bool compare_files ::file_sentence_compare (void)
{

// local buffer to read the liness from files//
    string input_file1_buffer ;
    string input_file2_buffer ;
    // temp object from ifstram to be able to open the files and use getline function to read the files line by line //
    ifstream input1 , input2 ;
    input1.open(compare.get_input_first_buffer(),ios :: in | ios :: binary);
    input2.open(compare.get_input_second_buffer(),ios :: in | ios :: binary);

    // we check if the 2 files are open successfully without no issue//
    // we read from files flag if zero it success//
    // if not  we cout the issue and clear the flag to be able to read from it again later//
       if (input1.rdstate() != STATUS_SUCCESS || input2.rdstate() != STATUS_SUCCESS  )

        {
                           cout<< " There is issue in reading files"<<endl;
                           input1.clear();
                           input2.clear();

        }

// do while loop until finish reading all lines from first files//
// we read wline from file1 and from file 2//
// and then we compare the 2 lines//
// if they are similar increment the identical line counter//
// if not  similar increment the not identical line counter//
// and print the 2 mismatched line to the user with their location//


    // but first we need to check if file 1 is bigger so will read from file 2 as it will finish before file 1
    // as we donot want to read to file 1 and continue reading after file 2 is done //
    if (compare.get_file1_is_bigger()== TRUE)
        {

            while(!input2 .eof())
           {
               // read lines from file 1 in first buffer//
               getline(input1 ,input_file1_buffer );
                // read lines from file 1 in first buffer//
               getline(input2 ,input_file2_buffer );
                //compare the 2 lines//
               if (input_file1_buffer == input_file2_buffer)
             {

                // increment the identical counter in case true//
                compare.set_identical_line_count((compare.get_identical_line_count()+1));
             }else
             {

                              textattr( 15);
                               cout<<"line  from file 1 : ";
                               cout <<input_file1_buffer<<endl;
                               cout <<"is  mismatch with "<<endl;

                               textattr( 1);
                               cout<<"line  from file 2 : ";
                               cout <<input_file2_buffer<<endl;


               // increment the notidentical counter in case False//
                compare.set_notidentical_line_count( (compare.get_notidentical_line_count()+1) );
               }

             }

              // check if we real all the file or not//
              // if flag of eof return 2  it is success//
              //else we notice the user that not all the file was read//
              // clear the flag to read from it again later//

          if (input2.eofbit != EOF_SUCESS)

           {
                 cout<<"not all the file was read" <<endl;
                  input1.clear();

            }

        }

        else
        {



         while(!input1 .eof()) {
               // read lines from file 1 in first buffer//
               getline(input1 ,input_file1_buffer );
                // read lines from file 1 in first buffer//
               getline(input2 ,input_file2_buffer );
                //compare the 2 lines//
               if (input_file1_buffer == input_file2_buffer)
             {

                // increment the identical counter in case true//
                compare.set_identical_line_count((compare.get_identical_line_count()+1));
             }else
             {


                              textattr( 15);
                               cout<<"line  from file 1 : ";
                               cout <<input_file1_buffer<<endl;
                               cout <<"is  mismatch with "<<endl;

                               textattr( 1);
                               cout<<"line  from file 2 : ";
                               cout <<input_file2_buffer<<endl;

               // increment the notidentical counter in case False//
                compare.set_notidentical_line_count( (compare.get_notidentical_line_count()+1) );
               }

             }

              // check if we real all the file or not//
              // if flag of eof return 2  it is success//
              //else we notice the user that not all the file was read//
              // clear the flag to read from it again later//

          if (input1.eofbit != EOF_SUCESS)

           {
                 cout<<"not all the file was read" <<endl;
                  input1.clear();

            }


         }

    //close the temp fstream object after reading the lines//
     input1.close();
     input2.close();

    // check if the not identical counter  more than 1 so the files//
    //  have mismatched lines between them and return false//
    //else  return true //
    if (  compare.get_notidentical_line_count()  >= 1)
    {
        return FALSE;
    }
   return TRUE;

}



   //bool fn to check if sizes 2 files are similar //
   // and to get sizes of the 2 files //
   // param : void//
   // return : bool ( true or false)//

bool compare_files :: size_compare ( void)
{


          // temp object from ifstram to be able to open the files and use getline function to read the files line by line //
    ifstream input_file1 , input_file2 ;
    input_file1.open(compare.get_input_first_buffer(),ios :: in | ios :: binary);
    input_file2.open(compare.get_input_second_buffer(),ios :: in | ios :: binary);

      // we check if the 2 files are open successfully without no issue//
    // we read from files flag if zero it success//
    // if not  we cout the issue and clear the flag to be able to read from it again later//
       if (input_file1.rdstate() != STATUS_SUCCESS || input_file2.rdstate() != STATUS_SUCCESS  )

        {
                           cout<< " There is issue in reading files"<<endl;
                           input_file1.clear();
                           input_file2.clear();

        }
 // we point the pointer the last file1 word to get the size of the files//
    input_file1.seekg(0,ios :: end);
   //use the tellg to know where the pointer stop and get the location //
    compare.set_input_file1_size(input_file1.tellg()) ;
    // return the pointer back to its initial location //
    input_file1.seekg(0,ios :: beg);
 // we point the pointer the last file1 word to get the size of the files//
    input_file2.seekg(0,ios :: end);
 //use the tellg to know where the pointer stop and get the location //
    compare.set_input_file2_size(input_file2.tellg()) ;
    // return the pointer back to its initial location //
    input_file2.seekg(0,ios :: beg);


    input_file1.close();
    input_file2.close();

    // check if the 2 files have the same size or not//
    //  if not same return false//
    //else  return true //

     if ((compare.get_input_file1_size() == compare.get_input_file2_size()))
     {
         return TRUE ;
     }else
     {
         return FALSE ;
     }

}

// we check the percentage of how file 1 is similar to file 2 //
// by check how many words in file 1 are found in file 2 from all file 1 words//
// the difference between this function  and compare by word as word compare word to correspond word//
//while this check if the word is found in any location at the other file//
// param :: void//
//return :: void//

 void compare_files :: check_file1_identical_precentage(void)
 {
     // temp fstream objects  to open the files and read word by word //
     fstream file1 ;
     fstream file2 ;
     // temp string to hold the word to check if its found in file 2 lines //
     string word;
     // temp string to hold the line we get from file 2 //
     string line;
      // temp size_t to check if word is found or not in the other file//
     size_t pos;
     // temp flag id check the word is found or not //
     short flag_word_isfound =0 ;

    file1.open(compare.get_input_first_buffer(), ios :: binary | ios :: in);
    file2.open(compare.get_input_second_buffer(), ios :: binary | ios :: in);

    // we check if the 2 files are open successfully without no issue//
    // we read from files flag if zero it success//
    // if not  we cout the issue and clear the flag to be able to read from it again later//

    if (file1.rdstate() != STATUS_SUCCESS || file2.rdstate() != STATUS_SUCCESS  )

        {
                           cout<< " There is issue in reading files"<<endl;
                           file1.clear();
                           file2.clear();

        }


        // do wile loop to get word from file 1 and loop line by line in the second file//
        // if we found the word is found in the second file we raise the flag and we increment//
        // the word match counter if the flag is zero   we increment the mismatch counter//
    while(!file1.eof()){

              file1 >> word ;
              file2.seekg(0,ios :: beg);
              while(!file2.eof())
                 {

                   getline(file2 ,line);
                   pos =line.find(word);
                   if(pos != string::npos)
                 {
                   flag_word_isfound =1 ;
                 }

                 }

              if (flag_word_isfound ==1 )
             {
                 compare.set_word_match(( compare.get_word_match()+1 ));
                flag_word_isfound = 0;
             }else
             {
               compare.set_word_missmatch((compare.get_word_missmatch()+1)) ;
             }

             // we calculate number of words in file 1 //
             compare.set_words_number((compare.get_words_number()+1 ));

    }


            // check if we real all the file or not//
        // if flag of eof return 2  it is success//
        //else we notice the user that not all the file was read//
        // clear the flag to read from it again later//
       if (file1.eofbit != EOF_SUCESS)

    {
             cout<<"not all  file 1 was read" <<endl;
             file1.clear();

    }

           if (file2.eofbit != EOF_SUCESS)

    {
             cout<<"not all  file  2 was read" <<endl;
             file2.clear();

    }


  //close the temp file//
     file1.close();
    file2.close();

 }

// we check the percentage of how file 1 is similar to file 2 //
// by check how many words in file 1 are found in file 2 from all file 1 words//
// the difference between this function  and compare by word as word compare word to correspond word//
//while this check if the word is found in any location at the other file//
// param :: void//
//return :: void//

 void compare_files :: check_file2_identical_precentage(void)
 {
     // temp fstream objects  to open the files and read word by word //
     fstream file1 ;
     fstream file2 ;
     // temp string to hold the word to check if its found in file 2 lines //
     string word;
     // temp string to hold the line we get from file 2 //
     string line;
      // temp size_t to check if word is found or not in the other file//
     size_t pos;
     // temp flag id check the word is found or not //
     short flag_word_isfound =0 ;

    file1.open(compare.get_input_first_buffer(), ios :: binary | ios :: in);
    file2.open(compare.get_input_second_buffer(), ios :: binary | ios :: in);

    // we check if the 2 files are open successfully without no issue//
    // we read from files flag if zero it success//
    // if not  we cout the issue and clear the flag to be able to read from it again later//

    if (file1.rdstate() != STATUS_SUCCESS || file2.rdstate() != STATUS_SUCCESS  )

        {
                           cout<< " There is issue in reading files"<<endl;
                           file1.clear();
                           file2.clear();

        }


        // do wile loop to get word from file 2 and loop line by line in the first file//
        // if we found the word is found in the first file we raise the flag and we increment//
        // the word match counter if the flag is zero   we increment the mismatch counter//
    while(!file2.eof()){

              file2 >> word ;
              file1.seekg(0,ios :: beg);

             while(!file1.eof())
                {

                   getline(file1 ,line);
                   pos =line.find(word);
                   if(pos != string::npos)
                 {
                   flag_word_isfound =1 ;
                 }

                 }

              if (flag_word_isfound ==1 )
             {
                 compare.set_word_match(( compare.get_word_match()+1 ));
                flag_word_isfound = 0;
             }else
             {
               compare.set_word_missmatch((compare.get_word_missmatch()+1)) ;
             }

             // we calculate number of words in file 2 //
             compare.set_words_number((compare.get_words_number()+1 ));

    }


            // check if we real all the file or not//
        // if flag of eof return 2  it is success//
        //else we notice the user that not all the file was read//
        // clear the flag to read from it again later//
       if (file2.eofbit != EOF_SUCESS)

    {
             cout<<"not all  file 1 was read" <<endl;
             file1.clear();

    }

           if (file2.eofbit != EOF_SUCESS)

    {
             cout<<"not all  file  2 was read" <<endl;
             file2.clear();

    }

  //close the temp file//
     file1.close();
    file2.close();

 }


// gotoxy function to change the positions//

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
using namespace std;


int main()
{

// fstream object to open the files and read from them //
 fstream myfilehandler1 , myfilehandler2 ;
 // temp char to hold the buttom pressed from the user//
 char pressed_button ;
 // index to know where the user stand on the menu //
 int index;
 //flag to check if file is open successfully or not //
 short open_file_flag=0;
 // temp string to hold address or file name from  user (getline fn)
 string file_name_buffer ="";

 // while as the user while not enter the menu until he success enter the file name//
 while ( open_file_flag == FALSE)

 {
      cout << "enter the first txt file  name or address" << endl;
      getline (cin, file_name_buffer);
      // set the name or address in buffer to send it to file open function //
      compare.set_input_first_buffer(file_name_buffer);
      myfilehandler1.open(compare.get_input_first_buffer(),ios :: in | ios :: binary);
      // if file is sucess open we will the user to enter the second file name if not the user will stay in the loop asking him to enter the file1 name  xD//
      if (myfilehandler1.rdstate() == STATUS_SUCCESS)
      {

          system("CLS");

          while (open_file_flag == FALSE){

                  cout << "enter the second txt file  name or address" << endl;
                  getline (cin,file_name_buffer);
                  compare.set_input_second_buffer(file_name_buffer);
                  myfilehandler2.open(compare.get_input_second_buffer(),ios :: in | ios :: binary);

                    // now if the user entered the second file succes we will raise open file flag to one to break the while loop and go the menu //
                         if (myfilehandler2.rdstate() == STATUS_SUCCESS)

                         {
                             open_file_flag =TRUE;

                         }else
                         {
                                       // now if the user enter file 1 wrong he will get msg //
                                      // that he entered the name wrong & to retry again//
                                      system("CLS");
                                    cout<< "the address or the name you entered is wrong"<<endl;
                                    cout<< "kindly retry again , press any key to retry "<<endl;
                                    getchar();
                                    system("CLS");
                         }

        };
      }else
      {
          // now if the user enter file 1 wrong he will get msg //
          // that he entered the name wrong & to retry again//
         system("CLS");
         cout<< "the address or the name you entered is wrong"<<endl;
         cout<< "kindly retry again , press any key to retry "<<endl;
         getchar();
         system("CLS");
      }


 }

// char array to hold the menu choices names //

char arr[MENU_OPTION][30]={"compare files by size ","compare files by words ","compare files by lines " , "compare files by percentage "};
int i;
system("cls");
     cout << "\t\t\      main menu    \n" << endl;
     cout <<"\t\t\      ------------" << endl;


// loop true to continue print the menu //
 while(TRUE)
   {

   // loop to show the choices //
      for( int loop_counter=0;loop_counter< MENU_OPTION ;loop_counter++)
      {
      gotoxy(20,loop_counter+5);
      textattr( 15);
      cout << arr[loop_counter] <<endl;
      }
      gotoxy(20,index+5);
      textattr( 1);
      cout << arr[index] << endl;
      pressed_button=getch();

      // now we open thread to detect what the user pressed and depend on what he choiced we we call function //

          if( pressed_button == ESC)break;
     // we try to detect the arrow  up or down  to highlight  choice the user want//
          if( pressed_button== Tab )
           {
                gotoxy(20,index+5);
                textattr( 15);
                cout <<arr[index] <<endl;
                if(index==3)
                {
                    index=0;
                    gotoxy(20,index+5);
                    textattr( 1);
                     cout << arr[index] << endl;
                }
                else
               {
                    index = index+1;
                    gotoxy(20,index+5);
                    textattr( 1);
                    cout << arr[index] << endl;
              }
           }
          if( pressed_button == null )
           {
                   pressed_button=getch();
                   if(pressed_button==F17)
                   {
                     gotoxy(20,index+5);
                     textattr( 15);
                     cout << arr[index] << endl;
                     if(index==3)
                      {
                          index=0;
                          gotoxy(20,index+5);
                          textattr( 1);
                          cout << arr[index] << endl;
                      }
                     else
                      {
                         index=index+1;
                         gotoxy(20,index+5);
                         textattr( 1);
                         cout << arr[index] << endl;
                       }
                    }
                   else if (pressed_button== F3)
                   {
                   gotoxy(20,index+5);
                   textattr( 15);
                   cout << arr[index] << endl;
                   if(index==0)
                    {
                         index=3;
                         gotoxy(20,index+5);
                         textattr( 1);
                         cout << arr[index] << endl;
                     }
                   else{
                          index=index-1;
                          gotoxy(20,index+5);
                         textattr( 1);
                          cout << arr[index] << endl;
                      }
                    }
                 else if (pressed_button== ESC)
                    {
                    break;
                    }


            }

            // now if the user pressed enter on any option  we will call the compare function the user want//
            else if ( pressed_button==Enter)
            {
                 if (index ==INITAL)
                {
                      system("cls");
                      textattr( 15);

                      // if user selected first option  we will call compare by size function //
                      // if the bool function return true the files are identical and false with size of each one if not//
                      if (compare.size_compare ( ))
                        {
                             cout<<"the two files are equal  with size "<<compare.get_input_file1_size()<<endl;

                        }else
                        {
                            textattr( 15);
                            cout<< "the two files are different  sizes" <<endl;
                            cout << "size of first file is "<<compare.get_input_file1_size()<<endl;
                            textattr( 1);
                            cout << "the size of the second file is "<<compare.get_input_file2_size()<<endl;
                        }

                     getch();
                     system("cls");
                     textattr( 15);
                     cout << "\t\t\      main menu    \n" << endl;
                     cout <<"\t\t\      ------------" << endl;
                  }
                   else if(index==(INITAL+1))
                  {

                    system("cls");
                    compare.size_compare ( );

                   // we first compare which file is bigger  to set file 1 flag or not  for mismatch word calculation //
                    if ( compare.get_input_file1_size() > compare.get_input_file2_size())
                    {
                       compare.set_file1_is_bigger(TRUE);
                    }else

                    {
                        compare.set_file1_is_bigger(FALSE);
                    }


                        // if user selected second option  we will call compare by word function //
                      // if the bool function return true the files are identical and false with number of mismatched words if not//
                    if ( compare.word_compare())
                      {
                         cout<<" the two files are identical  "<<endl;

                      }else
                      {
                          textattr( 15);
                          // now we want to count number of mismatch words for file 1 & 2 but the issue if word_compare reutn mismatch//
                          //for one file ( the smaller one as our loop will stop at ending the small one//
                          // we need to use getwords number function to get number of words to the big file//
                          //and then we will add the mismatch for both + remaining  words we didnot read when when finished the loop//
                          // remaining = (total - match & mismatch )  words//
                            compare.get_file_words_count();

                         if (compare.get_file1_is_bigger()== TRUE)
                          {
                        cout << " file 1  is  mismatch with    "<< ( compare.get_words_number()-compare.get_identical_words_count() ) <<" words"<<endl;
                        cout << "file  2  is mismatch with    "<<   compare.get_notidentical_words_count()<<" words"<<endl;
                          }else
                          {
                        cout << "file  1  is mismatch with    "<<   compare.get_notidentical_words_count()<<" words"<<endl;
                        cout << " file 2  is  mismatch with    "<< ( compare.get_words_number()-compare.get_identical_words_count() ) <<" words"<<endl;

                          }



                      }

                      //we cleat identical or notidentical counter and words count as they are global counter in case we called the function//
                      // we begin increment from zero //
                        compare.set_identical_words_count(INITAL);
                        compare.set_notidentical_words_count(INITAL);
                        compare.set_words_number(INITAL);
                    getchar();
                    system("cls");
                    textattr( 15);
                     cout << "\t\t\      main menu    \n" << endl;
                     cout <<"\t\t\      ------------" << endl;
                 }
                 else if (index==(INITAL+2))
                 {




                    system("cls");

                    // we first compare which file is bigger  to set file 1 flag or not  for mismatch word calculation //
                    compare.size_compare ( );

                    if ( compare.get_input_file1_size() > compare.get_input_file2_size())
                    {
                       compare.set_file1_is_bigger(TRUE);
                    }else

                    {
                        compare.set_file1_is_bigger(FALSE);
                    }


                        // if user selected third option  we will call compare by lines function //
                      // if the  function return true the files are identical and false with number of mismatched lines if not//
                    if ( compare.file_sentence_compare())
                    {
                    cout<<"  the two files are identical  "<<endl;
                    }else
                    {
                    textattr( 15);

                            // now we want to count number of mismatch lines for file 1 & 2 but the issue if line_compare reutn mismatch//
                          //for one file ( the smaller one as our loop will stop at ending the small one//
                          // we need to use getlines number function to get number of lines to the big file//
                          //and then we will add the mismatch for both + remaining  lines we didnot read when when finished the loop//
                          // remaining = (total - match & mismatch ) lines//
                     compare.get_file_lines_count();

                      if (compare.get_file1_is_bigger()== TRUE)
                          {
                        cout << " file 1  is  mismatch with    "<< ( compare.get_lines_number()- compare.get_identical_line_count() ) <<" lines"<<endl;
                        cout << "file  2  is mismatch with    "<<   compare.get_notidentical_line_count()<<" lines"<<endl;
                          }else
                          {
                        cout << "file  1  is mismatch with    "<<   compare.get_notidentical_line_count()<<" lines"<<endl;
                        cout << " file 2  is  mismatch with    "<< ( compare.get_lines_number()-compare.get_identical_line_count()) <<" lines"<<endl;

                          }



                    }

                      //we cleat identical or notidentical counter in case we called the function//
                      // we begin increment from zero //
                      compare.set_identical_line_count(INITAL);
                      compare.set_notidentical_line_count(INITAL);


                    getchar();
                    system("cls");
                    textattr( 15);
                     cout << "\t\t\      main menu    \n" << endl;
                     cout <<"\t\t\      ------------" << endl;
                 }
                 else if (index == (INITAL+3))
                 {


                        // if user selected fourth option  we will call compare by percentage function //
                       // to know number of matched words  and compare it to total number of words in each file//
                       // so we can know by percentage how file is match to the other//
                    system("cls");
                    compare.check_file1_identical_precentage();
                    compare.set_precentage_identical( ((compare.get_word_match()/ compare.get_words_number())*100)   );
                    cout << " the percentage of similarity of file 1 with  file 2 =  " <<compare.get_precentage_identical()<<" %" <<endl;
                    //we rest words_number counter //
                    compare.set_words_number(INITAL );
                    //we rest words_matched counter //
                    compare.set_word_match(INITAL );
                     //we rest words_mismatched counter //
                    compare.set_word_missmatch(INITAL );
                    compare.check_file2_identical_precentage();
                    compare.set_precentage_identical( ((compare.get_word_match()/ compare.get_words_number())*100)   );
                    textattr( 1);
                    cout << " the percentage of similarity of the file 2 with file 1 =  " <<compare.get_precentage_identical()<<" %"<<endl;
                    //we rest words_number counter //
                    compare.set_words_number(INITAL );
                    //we rest words_matched counter //
                    compare.set_word_match(INITAL );
                     //we rest words_mismatched counter //
                    compare.set_word_missmatch(INITAL );
                    textattr( 15);
                    getchar();
                    system("cls");
                    textattr( 15);
                     cout << "\t\t\      main menu    \n" << endl;
                     cout <<"\t\t\      ------------" << endl;


                 }

           }

   }


}
