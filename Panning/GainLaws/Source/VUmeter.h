/*
  ==============================================================================

    VUmeter.h
    Created: 17 Sep 2012 5:01:15pm
    Author:  Stuart Mansbridge

  ==============================================================================
*/

#ifndef __VUMETER_H_4320541B__
#define __VUMETER_H_4320541B__

#include "../JuceLibraryCode/JuceHeader.h"

// A basic VUmeter component 
class JUCE_API VUmeter  : public Component
{
public:
	VUmeter ()	: level (0) {}

    ~VUmeter()	{}

    void setValue(float newLevel)
    {
        if (newLevel != level) //if (fabs (level - newLevel) > 0.005f)
        {
            level = newLevel;
            repaint();
        }
    }

    void paint (Graphics& g)
    {
		int width	= getWidth();
		int height	= getHeight();
		float tweak = 0.0f;	//0.07;
	
		level += tweak;
		level = exp (log (level) / 3.0f);

		// total blocks
		const int totalBlocks = 60;
		// number of blocks to light up
		const int numBlocks = roundToInt ((totalBlocks) * level);
		// height of a block
		const float h = (height - totalBlocks) / (float) totalBlocks;

		for (int i = 0; i < totalBlocks; ++i)
		{
			if (i >= numBlocks)
				g.setColour (Colour (0x5F000000));
			else
			{
				if (i < totalBlocks - 24)
					g.setColour (Colour (0xFF4DB92E));
				else if (i < totalBlocks - 14)
					g.setColour (Colours::yellow);
				else if (i < totalBlocks - 4)
					g.setColour (Colours::orange);
				else 
					g.setColour (Colours::red);
			}
			g.fillRect (0.0f, (height) - (i * h) - (i*1.0f), width * 0.8f, h );//- 3.0f);
		}
	}

private:
    float level;

    JUCE_DECLARE_NON_COPYABLE (VUmeter);
	JUCE_LEAK_DETECTOR (VUmeter);
};

#endif  // __VUMETER_H_4320541B__
