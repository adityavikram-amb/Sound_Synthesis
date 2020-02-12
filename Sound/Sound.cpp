// x86 ,  "winmm.lib"
#include <iostream>
using namespace std;

#include"Header.h"

atomic<double> freq = 0;


double makeNoise(double dTime)
{
    double amp = 0.2;
    double output = amp * sin(freq * 2 * 3.14159 * dTime);  //sine wave
    
   // return output;

    // square wave 
    if (output > 0)
    {
        return amp;
    }
    else
    {
        return -amp;
    }
    // square wae

}

int main()
{
    ifstream fin;
    double basefreq[5] = { 55.0,110.0,220.0,440.0,880.0 }; //a4
    double note [5][12];
    string table = "AABCCDDEFFGG";
    string Happy_Birthday = "4C 4C 4D 4C 4F 4E ";
    string Sweet_Child = "4C#5C#4G#4F#5F#4G#5F 4G#";
    string song = Happy_Birthday;
    fin.open("music.txt");
    getline(fin,song);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            note[i][j] = basefreq[i] * (pow(2.0, (double)j / 12.0));

            cout << note[i][j] << " ";
        }
        cout << endl;
    }

    cout << table.length()<<endl;
    for (int i =0;i< table.length();i+=2)
    {
        cout << table[ i]<< endl;
    }



    vector<wstring> device = olcNoiseMaker<short>::Enumerate();


    for (auto i : device)
    {
        wcout << "found " << i << endl;
    }

        olcNoiseMaker<short> sound(device[0], 44100, 1, 8, 512);

    sound.SetUserFunction(makeNoise);



 
    bool pressed = 0;
    double timex = 250; // seconds delay in ms
    unsigned char nid_note[16] = "ZSXCFVGBNJMK\xbcL\xbe";
    while (1)
    {
        //manual_piano
     /*
        pressed = 0;
        for (int k = 0; k < 15; k++)
        {
            if (GetAsyncKeyState(nid_note[k]) & 0x8000)
            {
                freq = 440 * pow(2, k/12.0);
                pressed = 1;
            }
        }
        if (!pressed)
        {
            freq = 0.0;
        }

*/
        

        /*
            freq = 277;
            Sleep(timex);
            freq = 550;
            Sleep(timex);
            freq = 416;
            Sleep(timex);
            freq = 370;
            Sleep(timex);
            freq = 735;
            Sleep(timex);
            freq = 418;
            Sleep(timex);
            freq = 690;
            Sleep(timex);
            freq = 418;
            Sleep(timex);
            */
        for (int i = 0; i < song.length()-2; i+=3)
        {
            if (song[i + 2] == ' ')
            {
                freq = note[song[i] - '0'-1][table.find(song[i+1])];
                cout << song[i]<<" " << song[i + 1]<<"  "<<freq << endl;
                Sleep(timex);
                freq = 0;
                
            }
            if (song[i + 2] == '#')
            {
                freq = note[song[i] - '0' - 1][table.find(song[i + 1])+1];
                cout << song[i] << " " << song[i + 1] << "# " << freq << endl;
                Sleep(timex);
                freq = 0;
                
            }
            Sleep(20);
        }



    }
}
