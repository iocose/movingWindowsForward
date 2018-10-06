#include "ofMain.h"
#include "ofApp.h"
#include "ofWindow.h"

const int N_WINDOWS = 30;
int mainWidth = 2100;
int mainHeight = 1000;
int winWidth = 550;
int winHeight = 400;
bool debug = false;

int main( ){
    // main window, where the 3d scene is drawn
    ofGLFWWindowSettings settings;
    settings.setSize(mainWidth, mainHeight);
    settings.setGLVersion(3, 2);

    if(!debug){
        settings.setPosition(ofVec2f(-mainWidth,-mainHeight));
        settings.visible = false; // hide the main window
        settings.resizable = false;
        shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(settings);
        shared_ptr<ofApp> mainApp(new ofApp);
        ofRunApp(mainWindow, mainApp);

        // https://forum.openframeworks.cc/t/sharing-offbo-between-multiple-windows-how-shared-ptr-solved/22008
        // share the context of the main app with the windows app
        settings.shareContextWith = mainWindow;
        settings.resizable = false;
        settings.visible = true;

        for (int i = 0; i< N_WINDOWS; i++) {
            settings.setSize(ofRandom(winWidth-200,winWidth),
                             ofRandom(winHeight-200,winHeight));

            auto x = ofRandom(0, mainWidth+winWidth);
            auto y = ofRandom(0, mainHeight);
            auto windowFrame = ofCreateWindow(settings);
            auto windowApp = make_shared<ofWindow>(x,y, mainApp->getTexture(), 2.0);

            ofAddListener(windowFrame->events().keyPressed,mainApp.get(),&ofApp::evt);

            ofRunApp(windowFrame, windowApp);
        }
        
        ofRunMainLoop();
    }else{
        ofCreateWindow(settings);
        ofRunApp(new ofApp());
    }

}
