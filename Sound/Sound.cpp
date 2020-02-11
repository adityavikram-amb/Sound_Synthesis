// x86 ,  "winmm.lib"
#include <iostream>
using namespace std;

#include"Header.h"

atomic<double> freq = 0;


double makeNoise(double dTime)
{
    double amp = 0.2;
    double output =amp * sin(freq * 2 * 3.14159 * dTime);  //sine wave
    
    return output;

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
    wcout << "Hello World!\n";

    vector<wstring> device = olcNoiseMaker<short>::Enumerate();


    for (auto i : device)
    {
        wcout << "found " << i << endl;
    }

        olcNoiseMaker<short> sound(device[0], 44100, 1, 8, 512);

    sound.SetUserFunction(makeNoise);


    double basefreq = 440.0; //a2
    double note = pow(2.0, 1.0 / 12);
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
                freq = basefreq * pow(note, k);
                pressed = 1;
            }
        }
        if (!pressed)
        {
            freq = 0.0;
        }



*/

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
    }
}
