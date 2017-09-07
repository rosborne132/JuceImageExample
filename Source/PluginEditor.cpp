/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
ImageExampleAudioProcessorEditor::ImageExampleAudioProcessorEditor (ImageExampleAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    
    //Load image from the BinaryData from BinaryData.h in the Juce Library Code [3].
    MyBackground = ImageCache::getFromMemory(BinaryData::Background_png, BinaryData::Background_pngSize);
    
    //Set size for plugin so that th window is as big as the photo.
    setSize(MyBackground.getWidth(), MyBackground.getHeight());
    
}

ImageExampleAudioProcessorEditor::~ImageExampleAudioProcessorEditor()       {}

//==============================================================================
void ImageExampleAudioProcessorEditor::paint (Graphics& g)
{
    g.drawImageAt(MyBackground, 0, 0);
}

void ImageExampleAudioProcessorEditor::resized()                            {}
