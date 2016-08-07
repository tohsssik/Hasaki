//
//  ConfigInfo.h
//  HasakiCocos
//
//  Created by 罗忆 on 16/4/17.
//
//

#ifndef ConfigInfo_h
#define ConfigInfo_h
#include "Headers.h"

//if the device is ios,change the file path to direct path
//ifndef ,then device is mac,change the file path to full path

//#define RUN_IN_IOS
#ifdef RUN_IN_IOS
static string GET_FILE(string _fileName)
{
    return _fileName;
}
#else
static string GET_FILE(string _fileName)
{
    string path1 = "/Users/luoyi/workspace/Hasaki/HasakiCocos/Resources/";
    return path1+_fileName;
}
#endif

 


#endif /* ConfigInfo_h */
