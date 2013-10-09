/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  9 Oct 2013 12:03:20pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_DEMOPLUGINAUDIOPROCESSOREDITOR_PLUGINEDITOR_54C3FE1F__
#define __JUCER_HEADER_DEMOPLUGINAUDIOPROCESSOREDITOR_PLUGINEDITOR_54C3FE1F__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "VUmeter.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class GainLawsAudioProcessorEditor  : public AudioProcessorEditor,
                                        public Timer,
                                        public ButtonListener,
                                        public SliderListener
{
public:
    //==============================================================================
    GainLawsAudioProcessorEditor (GainLawsAudioProcessor* ownerFilter);
    ~GainLawsAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback();
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);
    void sliderValueChanged (Slider* sliderThatWasMoved);



    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    VUmeter *VUmeterL,*VUmeterR;
	ScopedPointer<ResizableCornerComponent> resizer;
    ComponentBoundsConstrainer resizeLimits;

    AudioPlayHead::CurrentPositionInfo lastDisplayedPosition;

    GainLawsAudioProcessor* getProcessor() const
    {
        return static_cast <GainLawsAudioProcessor*> (getAudioProcessor());
    }

    void displayPositionInfo (const AudioPlayHead::CurrentPositionInfo& pos);
    //[/UserVariables]

    //==============================================================================
    TextButton* OnOffButton;
    Slider* slider;
    TextButton* panMode;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    GainLawsAudioProcessorEditor (const GainLawsAudioProcessorEditor&);
    const GainLawsAudioProcessorEditor& operator= (const GainLawsAudioProcessorEditor&);
};


#endif   // __JUCER_HEADER_DEMOPLUGINAUDIOPROCESSOREDITOR_PLUGINEDITOR_54C3FE1F__
