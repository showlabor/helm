/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "utils.h"
//[/Headers]

#include "xy_pad.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...

#define GRID_CELL_WIDTH 8
#define GRID_CELL_HEIGHT 16

//[/MiscUserDefs]

//==============================================================================
XYPad::XYPad ()
{

    //[UserPreSize]
    mouse_down_ = false;
    x_slider_ = nullptr;
    y_slider_ = nullptr;
    setOpaque(true);
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

XYPad::~XYPad()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void XYPad::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff424242));

    //[UserPaint] Add your own custom painting code here..
    g.setColour(Colour(0xff545454));
    for (int x = 0; x < getWidth(); x += GRID_CELL_WIDTH)
        g.drawLine(x, 0, x, getHeight());
    for (int y = 0; y < getHeight(); y += GRID_CELL_WIDTH)
        g.drawLine(0, y, getWidth(), y);

    g.setColour(Colours::white);
    float x = x_slider_->getValue() * getWidth();
    float y = (1.0f - y_slider_->getValue()) * getHeight();
    g.fillEllipse(x - 1.0f, y - 1.0f, 2.0f, 2.0f);
    g.drawEllipse(x - 5.0f, y - 5.0f, 10.0f, 10.0f, 1.0f);

    if (mouse_down_) {
        g.setColour(Colour(0x11ffffff));
        g.fillEllipse(x - 20.0, y - 20.0, 40.0, 40.0);
    }
    //[/UserPaint]
}

void XYPad::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void XYPad::mouseDown (const MouseEvent& e)
{
    //[UserCode_mouseDown] -- Add your code here...
    setSlidersFromPosition(e.getPosition());
    mouse_down_ = true;
    repaint();
    //[/UserCode_mouseDown]
}

void XYPad::mouseDrag (const MouseEvent& e)
{
    //[UserCode_mouseDrag] -- Add your code here...
    setSlidersFromPosition(e.getPosition());
    //[/UserCode_mouseDrag]
}

void XYPad::mouseUp (const MouseEvent& e)
{
    //[UserCode_mouseUp] -- Add your code here...
    mouse_down_ = false;
    repaint();
    //[/UserCode_mouseUp]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void XYPad::setSlidersFromPosition(Point<int> position) {
    if (x_slider_) {
        double percent = CLAMP((1.0 * position.x) / getWidth(), 0.0, 1.0);
        x_slider_->setValue(percent);
    }
    if (y_slider_) {
        double percent = CLAMP(1.0 - (1.0 * position.y) / getHeight(), 0.0, 1.0);
        y_slider_->setValue(percent);
    }
}

void XYPad::sliderValueChanged(Slider* moved_slider) {
  repaint();
}

void XYPad::setXSlider(Slider* slider) {
  if (x_slider_)
    x_slider_->removeListener(this);

  x_slider_ = slider;
  x_slider_->addListener(this);
  repaint();
}

void XYPad::setYSlider(Slider* slider) {
  if (y_slider_)
    y_slider_->removeListener(this);
  y_slider_ = slider;
  y_slider_->addListener(this);
  repaint();
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="XYPad" componentName="" parentClasses="public Component, SliderListener"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="600"
                 initialHeight="400">
  <METHODS>
    <METHOD name="mouseDown (const MouseEvent&amp; e)"/>
    <METHOD name="mouseDrag (const MouseEvent&amp; e)"/>
    <METHOD name="mouseUp (const MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ff424242"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
