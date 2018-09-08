#include "ofMain.h"
#include "ofApp.h"
#include "ofWindow.h"

const int N_WINDOWS = 20;
bool debug = false;

int main( ){
    // main window, where the 3d scene is drawn
    ofGLFWWindowSettings settings;
    settings.setSize(1400, 700);
    settings.setGLVersion(3, 2);

    if(!debug){
        settings.setPosition(ofVec2f(-1400,-700));
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

        int winWidth = 700;
        int winHeight = 400;
//        int winWidth = 300;
//        int winHeight = 200;
        for (int i = 0; i< N_WINDOWS; i++) {
            //settings.setSize(100, 200);
            settings.setSize(ofRandom(winWidth-100,winWidth),
                             ofRandom(winHeight-100,winHeight));

            auto x = ofRandom(0, 1400+winWidth);
            auto y = ofRandom(0, 700);
            auto windowFrame = ofCreateWindow(settings);
            auto windowApp = make_shared<ofWindow>(x,y, mainApp->getTexture(), 2.0);

            ofAddListener(windowFrame->events().keyPressed,mainApp.get(),&ofApp::zoom);

            ofRunApp(windowFrame, windowApp);
        }
        
        ofRunMainLoop();
    }else{
        ofCreateWindow(settings);
        ofRunApp(new ofApp());
    }

}
