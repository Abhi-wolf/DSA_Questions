#include <iostream>
using namespace std;

int valid_string(char arr[])
{
    int j;
    for(j=0;arr[j]!='\0';j++)
    {
        if(!(arr[j]>=65 && arr[j]<=90) && !(arr[j]>=97 && arr[j]<=122) && !(arr[j]>=48 && arr[j]<=57))
            return 0;
    }
    return 1;
}





int main()
{
    char ch1[]={"WelCoMe ABHiJeeT"};        // space is also counted 
    int count1=0;
    for(int i=0;ch1[i]!='\0';i++)
        count1++;
    
    cout<<"Length of string1 is "<<count1<<endl;

    char ch2[]={"welcome"};
    int count2=0;
    for(int i=0;ch2[i]!='\0';i++)
        count2++;
    
    cout<<"Length of string2 is "<<count2<<endl;

    // lower to upper case
    for(int i=0;i<count2;i++)
        ch2[i]-=32;             // to convert upper to lower add 32   ,  lower to upper subtract 32
    
    cout<<"String2 in capital -> "<<ch2<<endl;



    // lower to upper and upper to lower
    for(int i=0;ch1[i]!='\0';i++)       // OR  for(int i=0;ch1[i]!='\0';i++)
    {
        if(ch1[i]>=65 && ch1[i]<=90)
            ch1[i]+=32;
        else if(ch1[i]>=97 && ch1[i]<=122)
            ch1[i]-=32;
    }

    cout<<"String1 in small -> "<<ch1<<endl;


    // counting vowels and consonants
    int vow=0,con=0;
    for(int j=0;ch1[j]!='\0';j++)
    {
        if(ch1[j]=='a' || ch1[j]=='A' || ch1[j]=='e' || ch1[j]=='E' || ch1[j]=='i' || ch1[j]=='I' || ch1[j]=='o' || ch1[j]=='O' || ch1[j]=='u' || ch1[j]=='U')
            vow++;
        else{
            if((ch1[j]>=65 && ch1[j]<=90) || (ch1[j]>=97 && ch1[j]<=122))
                con++;
        }

    }
    cout<<"\nVowels -> "<<vow<<"\nConsonants -> "<<con<<endl;

    //      count number of words in a sentence
    int count3=0;
    for(int j=0;ch1[j]!='\0';j++)
    {
        if(ch1[j]==32 && ch1[j-1]!=32)
            count3++;
    }
    cout<<"Number to words are "<<count3+1<<endl;



    // validating a string (like passwords should contain only letters and words not any extra)
    char arr[]={"Rocky123456"};
    if(valid_string(arr))
        cout<<"\nValid string\n";
    else
        cout<<"\nNot a valid string\n";
    
    

    //  reversing a string      (1st method)
    int i,j;
    for(i=0;arr[i]!='\0';i++);          // finding the size of string 
    
    char ar[i-1];
    i=i-1;
    for( j=0;i>=0;j++,i--)
    {
        ar[j] = arr[i];
    }
    ar[j]='\0';

    cout<<"Reverse string is  "<<ar<<endl;

    //   (2nd method)
    i=0,j=0;
    for(j=0;arr[j]!='\0';j++);
    j=j-1;
    for(i=0;i<j;i++,j--)
    {
        char temp=arr[i];
        arr[i]=arr[j];;
        arr[j]=temp;
    }
    cout<<"Reverse string using 2nd method : "<<arr<<endl;



    //      compairing two strings
    char ch3[]={"painting"};
    char ch4[]={"Painting"};            // ascii of smaller p is greater than capital P
    for(i=0,j=0;ch3[i]!='\0'&&ch4[j]!='\0';i++,j++)
    {
        if(ch3[i]!=ch4[j])
            break;
    }

    if(ch3[i]==ch4[j])
        cout<<"Equal\n";
    else if(ch3[i]<ch4[j])
        cout<<"Smaller\n";
    else
        cout<<"Larger\n";



    //      palindrome -> string remains when reversed  eg. madam,nitin etc
    //  first reverse string and store it in another string and then compare them both
    char ch6[]={"madam"};
    for(i=0;ch6[i]!='\0';i++);
    i=i-1;
    char ch5[i];
    
    for(j=0;i>=0;i--,j++)
        ch5[j]=ch6[i];
    ch5[j]='\0';
    
    cout<<endl<<ch5<<endl;

    for(i=0,j=0;ch6[i]!='\0' && ch5[j]!='\0';i++,j++)
    {
        if(ch6[i]!=ch5[j])
            break;
    }

    if(ch6[i]==ch5[j])
        cout<<"Yes its a palindrome\n";
    else
        cout<<"No its not a palindrome\n";



    //  finding duplicates
    // cretaes a hash table of size 26 and initialized with 0
    //  as the elements are traversed 1 to assigned to its box  
    int h[26]={0};
    for(i=0;ch6[i]!='\0';i++)
    {
        if(ch6[i]>=97 && ch6[i]<=122)               //  for lower case character
            h[ch6[i]-97]+=1;
        else if(ch6[i]>=65 && ch6[i]<=90)           //  for upper case character
            h[ch6[i]-65]+=1;
    }
    cout<<endl;
    for(j=0;j<26;j++)
    {
        if(h[j]>1)
        {
            cout<<(j+97)<<" is repeated "<<h[j]<<" times"<<endl;
        } 
    }
    cout<<"\n";



    /* using bits operation 
      <<   -> shifts all bits to the left based on the given value
      &    -> returns false if any one is false
      |    -> returns true if any one is true         */ 
    
    long int t=0,l=0;
    char A[]={"finding"};
    for(i=0;A[i]!='\0';i++)
    {
        l=1;
        l=l<<(A[i]-97);

        if((l&t)>0)
            cout<<A[i]<<" is duplicate\n";
        else
            t=l|t;
    }


    /* checking if two strings are anagram
        anagram -> if letters of a word are rearranged and their sizes are equal
     here we have assumed that size are equal */

    char ch7[]={"verbose"};
    char ch8[]={"observe"};

    int num1[26]={0};

    for(i=0;ch7[i]!='\0';i++)
        num1[ch7[i]-97]+=1;
    
    for(i=0;ch8[i]!='\0';i++)
    {
        num1[ch8[i]-97]-=1;
        if(num1[i]<0)
        {
            cout<<ch7<<" and "<<ch8<<" are not anagram\n";
            break;
        }
    }
    if(ch8[i]=='\0')
        cout<<ch7<<" and "<<ch8<<" are anagram\n";



        

    return 0;
}