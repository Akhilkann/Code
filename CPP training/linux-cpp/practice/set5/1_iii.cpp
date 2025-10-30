#include<iostream>
#include<sstream>
//#define test

using namespace std;

struct St
{
    char **Array;
    int number_of_words;
};
#ifdef test 
#else
St Sentence_to_words(char *buffer);
#endif

int main()
{
    #ifndef test 
    St Ret={0,0};
    char chSentence[100]={0};
    cout<<"Enter the sentence"<<endl;
    cin.getline(chSentence,100);
    Ret=Sentence_to_words(chSentence);
    cout<<"number of words="<<Ret.number_of_words<<endl;
    cout<<"Words in the sentence are..."<<endl;
    for(int i=0;i<Ret.number_of_words;i++)
    {
        cout<<Ret.Array[i]<<endl;
    }
    delete(Ret.Array);
    return 0;
    
    
    
    #else
    #endif

    return 0;
}

St Sentence_to_words(char *buffer)
{
    int i=0 ,cnt =0;
    St temp={0,0};
    int number_of_words =0;
    for(int i=0;buffer[i]!='\0';i++)
    {
        if(buffer[i]==' ')
        {
            number_of_words++;
        }
    }
    cout<<number_of_words<<endl;
    char **ptr1=new char*[number_of_words+1];
    for (int j = 0; j < number_of_words+1; j++)
    {
        ptr1[j]=new char[10];
        int u=0;
        static int i = 0;
        for (i;buffer[i] != ' '&&buffer[i] != '\0'; i++,u++)
        {

            ptr1[j][u]=buffer[i];

        }
        ptr1[j][u]='\0';
        i++;

    }
    temp.Array=ptr1;
    temp.number_of_words=number_of_words+1;

    return temp;
}