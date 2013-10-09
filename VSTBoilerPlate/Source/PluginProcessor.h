/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#ifndef __PLUGINPROCESSOR_H_76FFF0C1__
#define __PLUGINPROCESSOR_H_76FFF0C1__

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/**
*/
class VstboilerPlateAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    VstboilerPlateAudioProcessor();
    ~VstboilerPlateAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock);
    void releaseResources();

    void processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages);

    //==============================================================================
    AudioProcessorEditor* createEditor();
    bool hasEditor() const;

    //==============================================================================
    const String getName() const;

    int getNumParameters();

    float getParameter (int index);
    void setParameter (int index, float newValue);

    const String getParameterName (int index);
    const String getParameterText (int index);

    const String getInputChannelName (int channelIndex) const;
    const String getOutputChannelName (int channelIndex) const;
    bool isInputChannelStereoPair (int index) const;
    bool isOutputChannelStereoPair (int index) const;

    bool acceptsMidi() const;
    bool producesMidi() const;

    //==============================================================================
    int getNumPrograms();
    int getCurrentProgram();
    void setCurrentProgram (int index);
    const String getProgramName (int index);
    void changeProgramName (int index, const String& newName);

    //==============================================================================
    void getStateInformation (MemoryBlock& destData);
    void setStateInformation (const void* data, int sizeInBytes);

	// These two functions have to be added manually (Unknown reason)
	bool silenceInProducesSilenceOut() const;
	double getTailLengthSeconds() const;

	int numSamples;

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VstboilerPlateAudioProcessor);
};

#endif  // __PLUGINPROCESSOR_H_76FFF0C1__
