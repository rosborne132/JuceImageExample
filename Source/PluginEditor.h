/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//Include the location of BinaryData.h [1].
//Check the Binary Resource box within the settings of the source.
//The .cpp and .h are located in the Juce Library Code folder.
#include "../JuceLibraryCode/BinaryData.h"


//==============================================================================
/**
*/
class ImageExampleAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    ImageExampleAudioProcessorEditor (ImageExampleAudioProcessor&);
    ~ImageExampleAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    
    //Add member for image [2]
    Image MyBackground;
    
    ImageExampleAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ImageExampleAudioProcessorEditor)
};
