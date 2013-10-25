//
//  WavFile.cpp
//  WavRead
//
//  Created by Nicholas Jillings on 25/10/2013.
//  Copyright (c) 2013 Nicholas Jillings. All rights reserved.
//

#include "WavFile.h"

/*
 Data = new short [Subchunk2Size/(BitsPerSample/8)];
 fread(Data,BitsPerSample/8,Subchunk2Size/(BitsPerSample/8),fhandle);
*/

void WavFile::openFileRead(std::string Filename)
{
    char* file = new char[Filename.size()+1];
    file[Filename.size()] = 0;
    memcpy(file, Filename.c_str(), Filename.size());
    fhandle = fopen(file, "rb");
    fgetpos(fhandle, &start);
    fgetpos(fhandle, &pos);
}

void WavFile::openFileWrite(std::string Filename)
{
    char* file = new char[Filename.size()+1];
    file[Filename.size()] = 0;
    memcpy(file, Filename.c_str(), Filename.size());
    fhandle = fopen(file, "wb");
    fgetpos(fhandle, &start);
    fgetpos(fhandle, &pos);
}

void WavFile::closeFile()
{
    fclose(fhandle);
}

void WavFile::readHeader()
{
    fsetpos(fhandle, &start);
    
    fread(ChunkID,1,4,fhandle);
    fread(&ChunkSize,4,1,fhandle);
    fread(Format,1,4,fhandle);
    fread(Subchunk1ID,1,4,fhandle);
    fread(&Subchunk1Size,4,1,fhandle);
    fread(&AudioFormat,2,1,fhandle);
    fread(&NumChannels,2,1,fhandle);
    fread(&SampleRate,4,1,fhandle);
    fread(&ByteRate,4,1,fhandle);
    fread(&BlockAlign,2,1,fhandle);
    fread(&BitsPerSample,2,1,fhandle);
    fread(&Subchunk2ID,1,4,fhandle);
    fread(&Subchunk2Size,4,1,fhandle);
    
    fgetpos(fhandle, &pos);
}

void WavFile::generateHeader(int Samples, int Fs)
{
    ChunkID[0] = 'R';
    ChunkID[1] = 'I';
    ChunkID[2] = 'F';
    ChunkID[3] = 'F';
    
    Format[0] = 'W';
    Format[1] = 'A';
    Format[2] = 'V';
    Format[3] = 'E';
    
    Subchunk1ID[0] = 'f';
    Subchunk1ID[1] = 'm';
    Subchunk1ID[2] = 't';
    Subchunk1ID[3] = ' ';
    
    Subchunk2ID[0] = 'd';
    Subchunk2ID[1] = 'a';
    Subchunk2ID[2] = 't';
    Subchunk2ID[3] = 'a';
    
    AudioFormat = 3;
    NumChannels = 1;
    SampleRate = Fs;
    BitsPerSample = 32;
    ByteRate = SampleRate * NumChannels * BitsPerSample/8;
    BlockAlign = NumChannels * BitsPerSample/8;
    Subchunk1Size = 16;
    
    Subchunk2Size = Samples * NumChannels * BitsPerSample/8;
    ChunkSize = 36+Subchunk2Size;
    
}

void WavFile::writeHeader()
{
    fsetpos(fhandle, &start);
    
    fwrite(ChunkID,1,4,fhandle);
    fwrite(&ChunkSize,4,1,fhandle);
    fwrite(Format,1,4,fhandle);
    fwrite(Subchunk1ID,1,4,fhandle);
    fwrite(&Subchunk1Size,4,1,fhandle);
    fwrite(&AudioFormat,2,1,fhandle);
    fwrite(&NumChannels,2,1,fhandle);
    fwrite(&SampleRate,4,1,fhandle);
    fwrite(&ByteRate,4,1,fhandle);
    fwrite(&BlockAlign,2,1,fhandle);
    fwrite(&BitsPerSample,2,1,fhandle);
    fwrite(&Subchunk2ID,1,4,fhandle);
    fwrite(&Subchunk2Size,4,1,fhandle);
    
    fgetpos(fhandle, &pos);
}

void WavFile::readBlock(int numSamples, float* extData)
{
    float lsbVal;
    if (BitsPerSample != 32) {
        lsbVal = 1/BitsPerSample;
        int point;
        for (int n = 0; n<numSamples;n++)
        {
            fread(&point, BitsPerSample/8, 1, fhandle);
            fgetpos(fhandle, &pos);
            float fPoint = lsbVal * (float)point;
            extData[n] = fPoint;
        }
    }
    else
    {
        float point;
        for (int n=0; n<numSamples;n++)
        {
            fread(&point,BitsPerSample/8,1,fhandle);
            fgetpos(fhandle, &pos);
            extData[n] = point;
        }
    }
}

void WavFile::writeBlock(int numSamples, float* extData)
{
    for (int n = 0; n<numSamples; n++)
    {
        float point = extData[n];
        fwrite(&point,BitsPerSample/8,1,fhandle);
        fgetpos(fhandle,&pos);
    }
}

