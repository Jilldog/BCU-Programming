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

//[Headers] You can add your own extra header files here...
#include "PluginProcessor.h"
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
GainLawsAudioProcessorEditor::GainLawsAudioProcessorEditor (GainLawsAudioProcessor* ownerFilter)
    : AudioProcessorEditor (ownerFilter),
      OnOffButton (0),
      slider (0),
      panMode (0)
{
    addAndMakeVisible (OnOffButton = new TextButton (L"new button"));
    OnOffButton->setButtonText (L"ON/OFF");
    OnOffButton->addListener (this);
    OnOffButton->setColour (TextButton::buttonOnColourId, Colours::red);

    addAndMakeVisible (slider = new Slider (L"new slider"));
    slider->setRange (0, 1, 0.01);
    slider->setSliderStyle (Slider::RotaryHorizontalDrag);
    slider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    slider->addListener (this);

    addAndMakeVisible (panMode = new TextButton (L"Pan Mode"));
    panMode->setButtonText (L"Linear");
    panMode->addListener (this);


    //[UserPreSize]
    addAndMakeVisible (resizer = new ResizableCornerComponent (this, &resizeLimits));
    resizeLimits.setSizeLimits (150, 150, 800, 300);
    //[/UserPreSize]

    setSize (625, 300);


    //[Constructor] You can add your own custom stuff here..
    // set our component's initial size to be the last one that was stored in the filter's settings
    setSize (ownerFilter->lastUIWidth,
             ownerFilter->lastUIHeight);

    startTimer (50);

	OnOffButton->setClickingTogglesState(true);

	int xL = 590;
	int xR = xL+12;
	int y = 100;
	int height = 150;
	int width = 10;

    //[/Constructor]
}

GainLawsAudioProcessorEditor::~GainLawsAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (OnOffButton);
    deleteAndZero (slider);
    deleteAndZero (panMode);


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GainLawsAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    g.setColour (Colour (0xff363736));
    g.fillRoundedRectangle (5.0f, 36.0f, 615.0f, 260.0f, 10.0000f);

    g.setColour (Colours::black);
    g.setFont (Font (26.2000f, Font::plain));
    g.drawText (L"PLUG-IN DEMO",
                197, 3, 200, 30,
                Justification::centred, true);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GainLawsAudioProcessorEditor::resized()
{
    OnOffButton->setBounds (478, 41, 88, 24);
    slider->setBounds (175, 88, 263, 160);
    panMode->setBounds (32, 80, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    resizer->setBounds (getWidth() - 16, getHeight() - 16, 16, 16);

    getProcessor()->lastUIWidth = getWidth();
    getProcessor()->lastUIHeight = getHeight();
    //[/UserResized]
}

void GainLawsAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == OnOffButton)
    {
        //[UserButtonCode_OnOffButton] -- add your button handler code here..
		getProcessor()->pluginONOFF(OnOffButton->getToggleState());
        //[/UserButtonCode_OnOffButton]
    }
    else if (buttonThatWasClicked == panMode)
    {
        //[UserButtonCode_panMode] -- add your button handler code here..
		getProcessor()->changeMode();
        //[/UserButtonCode_panMode]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void GainLawsAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
	GainLawsAudioProcessor* ourProcessor = getProcessor();
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == slider)
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
		getProcessor()->changePan(slider->getValue());
        //[/UserSliderCode_slider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

// This timer periodically checks whether any of the filter's parameters have changed...
void GainLawsAudioProcessorEditor::timerCallback()
{
    GainLawsAudioProcessor* ourProcessor = getProcessor();
	
	int mode = getProcessor()->getMode();
	if (mode == 0)
		panMode->setButtonText(L"Linear");
	else if (mode == 1)
		panMode->setButtonText(L"Square");
	else if (mode == 2)
		panMode->setButtonText(L"Sine");
	else
		panMode->setButtonText(L"ERROR");
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="GainLawsAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="GainLawsAudioProcessor* ownerFilter" variableInitialisers="AudioProcessorEditor (ownerFilter)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="1" initialWidth="625" initialHeight="300">
  <BACKGROUND backgroundColour="ffffffff">
    <ROUNDRECT pos="5 36 615 260" cornerSize="10" fill="solid: ff363736" hasStroke="0"/>
    <TEXT pos="197 3 200 30" fill="solid: ff000000" hasStroke="0" text="PLUG-IN DEMO"
          fontname="Default font" fontsize="26.2" bold="0" italic="0" justification="36"/>
  </BACKGROUND>
  <TEXTBUTTON name="new button" id="fd7d67785124f936" memberName="OnOffButton"
              virtualName="" explicitFocusOrder="0" pos="478 41 88 24" bgColOn="ffff0000"
              buttonText="ON/OFF" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <SLIDER name="new slider" id="aed2938f5375fc4f" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="175 88 263 160" min="0" max="1" int="0.01"
          style="RotaryHorizontalDrag" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="Pan Mode" id="9a588df489263074" memberName="panMode" virtualName=""
              explicitFocusOrder="0" pos="32 80 150 24" buttonText="Linear"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
