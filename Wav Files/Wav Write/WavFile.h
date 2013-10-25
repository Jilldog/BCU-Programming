//
//  WavFile.h
//  WavRead
//
//  Created by Nicholas Jillings on 25/10/2013.
//  Copyright (c) 2013 Nicholas Jillings. All rights reserved.
//

#ifndef __WavFile__
#define __WavFile__

#include <iostream>
#include <fstream>
#include <string>
class WavFile{
public:
    char ChunkID[4], Format[4], Subchunk1ID[4], Subchunk2ID[4]; // Header Chunks
    int ChunkSize, Subchunk1Size, SampleRate, ByteRate, Subchunk2Size; // Chunk Size
    short AudioFormat, NumChannels, BlockAlign, BitsPerSample; // Header Info

    float* Data;

    fpos_t start,pos; // File Position Pointers
    FILE* fhandle; // File Handle

    void openFileRead(std::string Filename);
    void openFileWrite(std::string Filename);
    void closeFile();
    void readHeader();
    void generateHeader(int Samples, int Fs);
    void writeHeader();
    void readBlock(int numSamples, float* extData);
    void writeBlock(int numSamples, float* extData);
};

#endif /* defined(__WavRead__WavFile__) */
