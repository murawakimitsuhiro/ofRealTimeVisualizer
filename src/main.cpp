#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
    /*
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	ofRunApp(new ofApp());*/
    
    ofGLFWWindowSettings settings;
    settings.width = 600;
    settings.height = 600;
    settings.setPosition(ofVec2f(300,0));
    settings.resizable = true;
    shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
    
    settings.width = 200;
    settings.height = 200;
    settings.setPosition(ofVec2f(0,0));
    settings.resizable = false;
    shared_ptr<ofAppBaseWindow> guiWindow = ofCreateWindow(settings);
    guiWindow->setVerticalSync(false);
    
    shared_ptr<ofApp> mainApp(new ofApp);
    mainApp->setupInspector();
    ofAddListener(guiWindow->events().draw,mainApp.get(),&ofApp::drawInspector);
    
    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();
}
