//
//  MidiEffectsScene.hpp
//  firstPractice
//
//  Created by Murawaki on 2017/02/04.
//
//

#ifndef MidiEffectsScene_hpp
#define MidiEffectsScene_hpp

#include "common.h"
#include "ofxMidi.h"

#define MAX_NUM_OF_NOTES 1000

//Structure that stores information for a single note/circle
typedef struct
{
    ofPoint pos;
    int time_counter;
    int note_num;
    int note_vel;
    
} NoteData;

//===========================================================================
//The main openFrameworks class,
//configured to listen for incoming MIDI messages

class MidiEffectsScene:   public baseScene,
public ofxMidiListener
{
    
public:
    
    //Main openFrameworks functions
    void setup();
    void update();
    void draw();
    void exit();
    void keyPressed(int key);
    
    //MIDI input callback function
    void newMidiMessage(ofxMidiMessage& eventArgs);
    
private:
    
    //Array that stores information for each note/circle being displayed
    NoteData noteData[MAX_NUM_OF_NOTES];
    
    //Variable for storing the apps background colour
    int backgroundColour;
    
    //Object that handles the MIDI input
    ofxMidiIn midiIn;
    
    //Flag that sets whether we're currently displaying the apps instructions
    bool showingInstructions;
};

#endif /* MidiEffectsScene_hpp */
