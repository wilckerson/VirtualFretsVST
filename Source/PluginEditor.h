/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class MyAudioPluginAudioProcessorEditor  : public AudioProcessorEditor, public juce::Slider::Listener, private juce::Timer
{
public:
    MyAudioPluginAudioProcessorEditor (MyAudioPluginAudioProcessor&);
    ~MyAudioPluginAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
	
	void sliderValueChanged(juce::Slider *slider) override;
	
private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    MyAudioPluginAudioProcessor& processor;

	juce::Slider gainSlider;
	juce::Label gainLabel;

	void timerCallback() override;
	void updateUI();

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MyAudioPluginAudioProcessorEditor)
};
