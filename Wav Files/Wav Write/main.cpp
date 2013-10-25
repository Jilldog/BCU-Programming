//
//  main.cpp
//  WavRead
//
//  Created by Nicholas Jillings on 25/10/2013.
//  Copyright (c) 2013 Nicholas Jillings. All rights reserved.
//

#include <iostream>
#include "WavFile.h"
#include <math.h>

int main(int argc, const char * argv[])
{
    // Generate 1kHz
    
    int numSamples = 44100;
    int Fs = 44100;
    float T = 1.0f/(float)Fs;
    float frequency = 1000;
    
    float* Sig = new float[numSamples];
    
    for (int n = 0; n<numSamples; n++) {
        Sig[n] = sinf(2*M_PI*frequency*((float)n*T));
    }
    
    // The Sine wave is stored in an Array from the Heap called Sig;
    
    WavFile Output; // Construct custom WavFile class;
    std::string Filename; // String to store the filename
    
    //printf("Please Enter File 1 \n");
    //scanf("%s",Filename);
    Filename = "/Users/[enter username]/out.wav\0"; // Output Filename, the \0 is needed at the end
    
    Output.openFileWrite(Filename); // This opens the file for writing
    Output.generateHeader(numSamples, Fs); // The generates the WAVE headers
    Output.writeHeader(); // Write the header file
    Output.writeBlock(numSamples, Sig); // Write Data block
    Output.closeFile(); // Close the file
    return 0;
}

