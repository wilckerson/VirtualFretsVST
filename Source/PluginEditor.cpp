/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
MyAudioPluginAudioProcessorEditor::MyAudioPluginAudioProcessorEditor (MyAudioPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

	addAndMakeVisible(gainSlider);
	gainSlider.setSliderStyle(juce::Slider::SliderStyle::LinearHorizontal);
	//gainSlider.setRange(0, 1);
	gainSlider.setRange(0.25,4);
	gainSlider.setValue(1);
	gainSlider.addListener(this);

	addAndMakeVisible(gainLabel);
	gainLabel.setText("GainLabel",juce::NotificationType::dontSendNotification);
	//gainLabel.attachToComponent(&gainSlider, true);

	startTimer(1000);
	
}

MyAudioPluginAudioProcessorEditor::~MyAudioPluginAudioProcessorEditor()
{
}

//==============================================================================
void MyAudioPluginAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    /*g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);*/
}

void MyAudioPluginAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
	//gainSlider.setBounds(getLocalBounds());
	gainSlider.setBounds(10, 10, 300, 50);

	gainLabel.setBounds(10, 50, 200, 50);
}

void MyAudioPluginAudioProcessorEditor::sliderValueChanged(juce::Slider *slider)
{
	//if (slider == &gainSlider) {
		
	updateUI();
	//}
}

void MyAudioPluginAudioProcessorEditor::updateUI() {

	double v = gainSlider.getValue();
	double logValue = v;

	//double logValue = v == 0 ? 0 : pow(10, v) / 10;
	processor.gain = logValue;

	/*String txt = "label: ";
	txt << processor.topFreq;
*/
	/*String txt = "Samples: ";
	txt << processor.numSamples;*/

	gainLabel.setText(processor.result, juce::NotificationType::dontSendNotification);
}

void MyAudioPluginAudioProcessorEditor::timerCallback() {

	updateUI();
}
