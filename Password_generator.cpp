#include<bits/stdc++.h >
using namespace std;

string lower(string s)
{
    for(int i=0; i<s.size(); i++)
    {
        s[i]=tolower(s[i]);
        //
    }
    return s;
}



string generatePassword(int password_length,string is_number_required,string is_special_char_required)
{
    string numeric=lower(is_number_required);

    bool use_numbers=false;
    if(numeric=="yes") use_numbers=true;
    else use_numbers=false;


    string special = lower(is_special_char_required);


    bool use_special_chars=false;
    if(special=="yes") use_special_chars=true;
    else use_special_chars=false;



    string english_letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numbers="0123456789";
    string specialCharacters="!@#$%^&*()-+=";
    string password="";



    srand(time(0));
    //main password
    int english_letters_index;
    for(int i=0; i<password_length-2; i++)
    {
        english_letters_index=rand()%english_letters.size();
        password+=english_letters[english_letters_index];

    }

    //cout<<"Password = "<<password<<"\n";



    //add numbers or not(just add a charcater)
    if(use_numbers==true)
    {
        int numbers_index=rand()%numbers.size();
        password+=numbers[numbers_index];
    }
    else
    {
        english_letters_index=rand()%english_letters.size();
        password+=english_letters[english_letters_index];

    }
    //cout<<"password = "<<password<<"\n";



    //add special character or not (just add a letter)
    if(use_special_chars==true)
    {
        int special_character_index=rand()%specialCharacters.size();
        password+=specialCharacters[special_character_index];

    }
    else
    {
        english_letters_index=rand()%english_letters.size();
        password+=english_letters[english_letters_index];
    }

   // cout<<"password = "<<password<<"\n";

   return password;




}



int main()
{
    cout<<"Password Length: ";
    int password_length;
    cin>>password_length;

    cout<<"Are numeric characters / numbers required in the password?(YES or No ): ";
    string is_number_required;
    cin>>is_number_required;
    // string numeric=lower(is_number_required);


//    bool use_numbers=false;
    //  if(numeric=="yes") use_numbers=true;
    //else use_numbers=false;


    cout<<"Are special characters required in the password?(YES or No ): ";
    string is_special_char_required;
    cin>>is_special_char_required;
    // string special = lower(is_special_char_required);



    string password=generatePassword(password_length,is_number_required,is_special_char_required);
    cout<<"\n\n\nPassword : "<<password<<"\n\n\n";

}
