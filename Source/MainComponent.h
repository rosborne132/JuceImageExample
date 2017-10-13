/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//Include BinaryData.h so we can use ImageCache.
#include "../JuceLibraryCode/BinaryData.h"



//Set Look and Feel for all dials.
class SliderLookAndFeel : public LookAndFeel_V4
{
public:
    
    void drawRotarySlider (Graphics &g, int x, int y, int width, int height, float sliderPos,
                           float rotaryStartAngle, float rotaryEndAngle, Slider &slider) override
    {
        
        //Create Varible for entire Knob.
        knobMaster = ImageCache::getFromMemory(BinaryData::knobMaster_png ,BinaryData::knobMaster_pngSize);
        
        float angle = rotaryStartAngle + (sliderPos * (rotaryEndAngle - rotaryStartAngle));

        //Draw Knob.
        //knobMaster.getWidth() /2, knobMaster.getHeight() /2 Changes the point of rotation.
        g.drawImageTransformed(knobMaster, AffineTransform::identity.rotated(angle, knobMaster.getWidth() /2, knobMaster.getHeight() /2));
        
    }
private:
    
    //Image of entire knob.
    Image knobMaster;
};



class MainContentComponent   : public Component,
                               public Slider::Listener
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();

    void paint (Graphics&) override;
    void resized() override;
    
    void sliderValueChanged(Slider *slider) override;

private:
    //Create Background image.
    Image backgroundImg;
    
    //Image of entire knob.
    Image knobMaster;

    //Create Slider.
    Slider imageSlider;
    
    //Create value.
    float sliderValue;
    
    //Create LookAndFeel
    SliderLookAndFeel sliderLookAndFeel;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};
