/*
  ==============================================================================
                            Notes about code and process
 
 1. I like to create an image folder in my source code folder for my images and then drag and drop images into juce.
 2. I like to make sure in the source folder to check off Binary and xcode resources. (Xcode resources is just so that the xcode isn't cluttered with images. Moves images to Resources folder)
 3. Functions used only rotate a single image. Does not use a film strip.
 4. Function in look and feel is the drawRotarySlider function but only the angle was used. Might be able to do it another way. 
 5. After dragging images and checking the setting in the source folder you should be able see the binary info in the Juce Library Code BinaryData.cpp and .h but .h has what we need. 
 6. Most important! When drawing knob images and backgrounds set bounds to their width and height. Unlike vectors I haven't been able to resize images.
 
 
 Sources for those that want to create better looking images:
 
 You can use to create film strips or maybe just one knob.
 Knobman : https://www.g200kg.com/jp/software/knobman.html
 Main knobman program is windows only. There is a web page.
 I like to use Vectr and Photoshop Elements.
 
 This was linked on Martin Finke blog on creating audio plugins.
 Cool photoshop tutorial: https://design.tutsplus.com/tutorials/creating-a-cool-brushed-metal-surface-in-photoshop--psd-117
 
  ==============================================================================
*/

#include "MainComponent.h"


//==============================================================================
MainContentComponent::MainContentComponent()
{
    //Create Background image.
    backgroundImg = ImageCache::getFromMemory(BinaryData::background_png, BinaryData::background_pngSize);
    
    //Create knob image in MainComponent.cpp only for setting bounds.
    knobMaster = ImageCache::getFromMemory(BinaryData::knobMaster_png, BinaryData::knobMaster_pngSize);
    
    imageSlider.setTextBoxStyle(Slider::TextBoxBelow, false, 0, 0);
    imageSlider.setSliderStyle(Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    imageSlider.setRange(0.01f, 99.99f);
    imageSlider.setValue(0.01f);
    imageSlider.setLookAndFeel(&sliderLookAndFeel);
    imageSlider.addListener(this);
    
    addAndMakeVisible(imageSlider);
    
    //Set background size to the size of the background image.
    setSize (backgroundImg.getWidth(), backgroundImg.getHeight());
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
    //Draw Background image.
    g.drawImageAt(backgroundImg, 0, 0);
    
}

void MainContentComponent::resized()
{
    float halfWidth = backgroundImg.getWidth() /2;
    float halfHeight = backgroundImg.getHeight() /2;
    
    
    //The image is drawn from the top left corner.
    //The width and height (100, 100) are from the width and height of the image.
    imageSlider.setBounds(halfWidth - (knobMaster.getWidth() /2), halfHeight - (knobMaster.getHeight() /2), 100, 100);

}

void MainContentComponent::sliderValueChanged(Slider *slider)
{
    if (slider == &imageSlider)
    {
        sliderValue = imageSlider.getValue();

    }
}






