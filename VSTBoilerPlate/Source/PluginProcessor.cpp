/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic startup code for a Juce application.

	This is the basic boiler-plate code for a blank plugin auto-created by
	JUCE. It it better to build a blank plugin in JUCE and build up than copy
	this one. It is just an example.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
VstboilerPlateAudioProcessor::VstboilerPlateAudioProcessor()
{
}

VstboilerPlateAudioProcessor::~VstboilerPlateAudioProcessor()
{
}

//==============================================================================
const String VstboilerPlateAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int VstboilerPlateAudioProcessor::getNumParameters()
{
    return 0;
}

float VstboilerPlateAudioProcessor::getParameter (int index)
{
    return 0.0f;
}

void VstboilerPlateAudioProcessor::setParameter (int index, float newValue)
{
}

const String VstboilerPlateAudioProcessor::getParameterName (int index)
{
    return String::empty;
}

const String VstboilerPlateAudioProcessor::getParameterText (int index)
{
    return String::empty;
}

const String VstboilerPlateAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String VstboilerPlateAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool VstboilerPlateAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool VstboilerPlateAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool VstboilerPlateAudioProcessor::acceptsMidi() const
{
#if JucePlugin_WantsMidiInput
    return true;
#else
    return false;
#endif
}

bool VstboilerPlateAudioProcessor::producesMidi() const
{
#if JucePlugin_ProducesMidiOutput
    return true;
#else
    return false;
#endif
}

int VstboilerPlateAudioProcessor::getNumPrograms()
{
    return 0;
}

int VstboilerPlateAudioProcessor::getCurrentProgram()
{
    return 0;
}

void VstboilerPlateAudioProcessor::setCurrentProgram (int index)
{
}

const String VstboilerPlateAudioProcessor::getProgramName (int index)
{
    return String::empty;
}

void VstboilerPlateAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void VstboilerPlateAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..

	numSamples = samplesPerBlock;
}

void VstboilerPlateAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void VstboilerPlateAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...

	// This creates a local memory store for the sample data
	float* data = new float[numSamples];

	// This for loop allows you to run through all the incoming channels, thereby
	// allowing a plugin to process any number of channels it is given.
    for (int channel = 0; channel < getNumInputChannels(); ++channel)
    {
		// This allows you access the sample by sample info
        float* channelData = buffer.getSampleData (channel);

		// This for loop coppies the samples to the local store data so you can work on them
		for (int sample = 0; sample < numSamples; sample++)
			data[sample] = channelData[sample];

		// PERFORM SUPER-COOL DAFX STUFF!!!!!!!!!!!!!!!!!

		// We are going to do a mega-awesome gain of 0.5
		for (int sample = 0; sample < numSamples; sample++)
			data[sample] = data[sample] * 0.5;
		// Short hand version
		//	data[sample] *= 0.5;

        // Copy your processed data back
		for (int sample = 0; sample < numSamples; sample++)
			channelData[sample] = data[sample];
    }

}

bool VstboilerPlateAudioProcessor::silenceInProducesSilenceOut() const
{
	return false;
}

double VstboilerPlateAudioProcessor::getTailLengthSeconds() const
{
	return 0.0;
}

//==============================================================================
bool VstboilerPlateAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* VstboilerPlateAudioProcessor::createEditor()
{
    return new VstboilerPlateAudioProcessorEditor (this);
}

//==============================================================================
void VstboilerPlateAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void VstboilerPlateAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new VstboilerPlateAudioProcessor();
}
