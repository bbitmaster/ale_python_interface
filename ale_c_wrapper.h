#ifndef __ALE_C_WRAPPER_H__
#define __ALE_C_WRAPPER_H__

#include <ale_interface.hpp>
#include <python2.7/Python.h>
//We should look into fixing this warning later, disable for now
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <numpy/arrayobject.h>

extern "C" {
    //declares int rgb_palette[256]
    #include "atari_ntsc_rgb_palette.h"
    ALEInterface *ALE_new(){
    return new ALEInterface();}

    void ALE_del(ALEInterface *ale){delete ale;}

    const char *getString(ALEInterface *ale,const char *key){return ale->getString(key).c_str();}
    int getInt(ALEInterface *ale,const char *key){return ale->getInt(key);}
    bool getBool(ALEInterface *ale,const char *key){return ale->getBool(key);}
    float getFloat(ALEInterface *ale,const char *key){return ale->getFloat(key);}

    void setString(ALEInterface *ale,const char *key,const char *value){ale->set(key,value);}
    void setInt(ALEInterface *ale,const char *key,int value){ale->set(key,value);}
    void setBool(ALEInterface *ale,const char *key,bool value){ale->set(key,value);}
    void setFloat(ALEInterface *ale,const char *key,float value){ale->set(key,value);}

    void loadROM(ALEInterface *ale,const char *rom_file){ale->loadROM(rom_file);}
    int  getLegalActionSize(ALEInterface *ale){return ale->getLegalActionSet().size();}

    void getLegalActionSet(ALEInterface *ale,int *actions){
        ActionVect action_vect = ale->getLegalActionSet();
        const int sz = (int)ale->getLegalActionSet().size();
        for(int i = 0;i < ale->getLegalActionSet().size();i++){
            actions[i] = action_vect[i];
        }
    }

    int getMinimalActionSize(ALEInterface *ale){return ale->getMinimalActionSet().size();}

    void getMinimalActionSet(ALEInterface *ale,int *actions){
        ActionVect action_vect = ale->getMinimalActionSet();
        const int sz = (int)ale->getMinimalActionSet().size();
        for(int i = 0;i < ale->getMinimalActionSet().size();i++){
            actions[i] = action_vect[i];
        }
    }

    int getFrameNumber(ALEInterface *ale){return ale->getFrameNumber();}
    int getEpisodeFrameNumber(ALEInterface *ale){return ale->getEpisodeFrameNumber();}

    int getScreenWidth(ALEInterface *ale){return ale->getScreen().width();}
    int getScreenHeight(ALEInterface *ale){return ale->getScreen().height();}

    int getScreen(ALEInterface *ale,unsigned char *screen_data){
        int w = ale->getScreen().width(); 
        int h = ale->getScreen().height(); 
        pixel_t *ale_screen_data = (pixel_t *)ale->getScreen().getArray();
        memcpy(screen_data,ale_screen_data,w*h*sizeof(pixel_t));
    }

    int getScreenRGB(ALEInterface *ale,int *screen_data){
        int w = ale->getScreen().width(); 
        int h = ale->getScreen().height(); 
        pixel_t *ale_screen_data = (pixel_t *)ale->getScreen().getArray();
        for(int i = 0;i < w*h;i++){
            screen_data[i] = rgb_palette[ale_screen_data[i]];
        }
    }

    int getRAMSize(ALEInterface *ale){return ale->getRAM().size();}

    void getRAM(ALEInterface *ale,unsigned char *ram){
        unsigned char *ale_ram = ale->getRAM().array();
        int size = ale->getRAM().size();
        memcpy(ram,ale_ram,size*sizeof(unsigned char));
    }

    int act(ALEInterface *ale,int action){return ale->act((Action)action);}
    bool game_over(ALEInterface *ale){return ale->game_over();}
    void reset_game(ALEInterface *ale){ale->reset_game();}

    void set(ALEInterface *ale,const char *key,const char*value){ale->set(key,value);}
}

#endif
