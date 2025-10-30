#include<iostream>
#include<string>
using namespace std;
#include"STrt.hpp"

int Number_of_Lines(string filename);
int ReadMediaFile(string filename,struct MediaST *ptr);
int ReadRadioFile(string filename,struct RadioST *ptr);