#include<fstream>
#include<sstream>
#include"FileRead.hpp"


int Number_of_Lines(string filename)
{
    string line;
    int linecount=0;
    if(filename == "Media.txt")
    {
        ifstream file("Media.txt");
        if(file.is_open())
        {
            while (std::getline(file, line)) {
                linecount++;
            }
        }
        file.close();
    }
    else if(filename == "Radio.txt")
    {
        ifstream file("Radio.txt");
        if(file.is_open())
        {
            while (std::getline(file, line)) {
                linecount++;
            }
        }
        file.close();
    }
    return linecount;
}

int ReadMediaFile(string filename,struct MediaST *ptr)
{
    int returnStatusfailed = false;
    int no_of_Medialines = Number_of_Lines(filename);
    ifstream file(filename);
    string s;
    if(file.is_open())
    {   
        for(int i=0;i<no_of_Medialines;i++)
        {
            getline(file, s);
            stringstream ss(s);
            getline(ss, ptr[i].Song_name,',');
            getline(ss, ptr[i].Artist_name, ',');
            getline(ss, ptr[i].Album_name, ',');
            getline(ss, ptr[i].Duration,',');
        }
        file.close();
    }
    else
    {
        cout<<"Mediafile read failed"<<endl;
        returnStatusfailed = true;
    }
    return returnStatusfailed;
}

int ReadRadioFile(string filename,struct RadioST *ptr)
{
    int returnStatusfailed = false;

    int no_of_Radiolines = Number_of_Lines(filename);
    ifstream file(filename);
    string s;
    if(file.is_open())
    {
        for(int i=0;i<no_of_Radiolines;i++)
        {
            getline(file, s);
            stringstream ss(s);
            getline(ss, ptr[i].Type,',');
            getline(ss, ptr[i].Frequency, ',');
        }
        file.close();
    }
    else
    {
        cout<<"Radiofile read failed"<<endl;
        returnStatusfailed = true;
    }

    return returnStatusfailed;
}
